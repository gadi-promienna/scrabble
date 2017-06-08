#include <stdio.h>

#include "gra2.h"


int main(){
char reguly[2];
printf("\n\n");
printf("    __\n");
printf("   /  \\\n");
printf("   |\n");
printf("    \\    __   __    __   __   __       __\n");
printf("     \\  /  \\ |  \\  /  \\ |  \\ |  \\ |   |\n");
printf("      \\ |    |__|  |__| |__| |__| |   |__\n");
printf("   |  | |    |  \\  |  | |  | |  | |   |\n");
printf("   \\__/ \\__/ |   \\ |  | |__/ |__/ |__ |__\n");

printf("\n\n\n");

printf("   Zapraszamy do gry! :)\n\n   Oto plansza:\n\n");

printf("       1 2 3 4 5 6 7 8 9\n");
printf("    1 | | | | | | | | | |\n");
printf("    2 | | | | | | | | | |\n");
printf("    3 | | | | | | | | | |\n");
printf("    4 | | | | | | | | | |\n");
printf("    5 | | | | |*| | | | |\n");
printf("    6 | | | | | | | | | |\n");
printf("    7 | | | | | | | | | |\n");
printf("    8 | | | | | | | | | |\n");
printf("    9 | | | | | | | | | |\n\n\n");

printf("  Wyswietlic reguly gry? (t-tak, n-nie)\n  ");
scanf("%c",reguly);
if(reguly[0] == 't')
 printf("\n\n  ZASADY:\n\nNasza gra jest modyfikacja popularnej gry slownej scrabbe. Przeznaczona dla dwoch osob. Polega na losowaniu liter i tworzeniu z nich slow. Slowa ukladane sa w sposob przypominajacy krzyzowke. Gra rozpoczyna sie w polu * - srodek planszy. Warunkiem uznania slowa jest akceptacja tego slowa przez przeciwnika. Zbior liter nie obejmuje polskich znakow diakrytycznych. Każda litera ma wartosc 1. Wynik ruchu to suma wartosci wszystkich liter slowa, a wynik ostateczny to suma wszystkich ruchow.\nKoniec gry nastepuje w dwoch przypadkach:\n - wykorzystanie puli wszystkich liter przez jednego z graczy,\n - calkowita rezygnacja z gry przez jednego z graczy.\nWygrywa osoba, ktora ma najwiecej punktow; jesli obydwaj gracze maja taka sama liczbe punktow, wowczas wygrywa ten, ktory wykorzystal wiecej liter.\n\n");

printf("\n----------------------------------------------------\n\n");
clear();
OBIEKT gracz gracze[2];
OBIEKT podstawka podstawki[2];
OBIEKT worek worek1;
OBIEKT pole plansza[10][10];
OBIEKT pole plansza_robocza[10][10];
gracze[0].wynik = 0;
gracze[1].wynik =0;
int roboczy_wynik;
printf("  Gre rozpoczyna gracz A.\n\n  GRACZ A - podaj imie: \n  ");
scanf("%s", gracze[0].imie);
printf("  Witaj, %s!\n",gracze[0].imie);
printf("\n  GRACZ B - podaj imie: \n  ");
scanf("%s", gracze[1].imie);
printf("  Ahoj, %s!\n\n", gracze[1].imie);
printf("\n----------------------------------------------------\n\n");

tworz_plansze(plansza);
kopiuj_plansze(plansza, plansza_robocza);
//rysuj_plansze(plansza);
worek1.ostatnia_wyjeta=0;

wypelnij_worek(worek1.litery);
printf("  Oto PODSTAWKI,\n  czyli litery, ktore wylosowal dla Was program :)\n\n\n");
printf("  Podstawka GRACZA %s :\n  ", gracze[0].imie);
wypelnij_podstawke (podstawki[0].litery, worek1.litery, &worek1.ostatnia_wyjeta);

printf("\n\n\n  Podstawka GRACZA %s :\n  ", gracze[1].imie);
wypelnij_podstawke (podstawki[1].litery, worek1.litery, &worek1.ostatnia_wyjeta);

printf("\n\n----------------------------------------------------\n");	
printf("\n\n         Pora rozpoczac nasza gre!\n\n");
printf("\n\n\n");
printf("                   .^^^^^^^^^^.\n");
printf("                 /              \\\n"); 
printf("     ____      |                 |\n"); 
printf("    |    |    |    ___     ___    |\n");
printf("     \\   |   |    |_o_|   |_o_|    |\n");
printf("      |  |   |                     |\n");
printf("     _|__|___           ()         |\n"); 
printf("    |        |                    |\n");
printf("   |  _______ |    (          )  |\n");
printf("  |    _______ |     ~ ~ ~ ~    /\n"); 
printf("  |   ________|  .      '    . /\n"); 
printf("   \\________/       |,,,,,,|  \n");
printf("\n\n\n");
printf("                POWODZENIA :)\n\n\n");

char menu='d';
int runda = 1;
int i;
int powrot=0;
int wynik_roboczy;
while(menu!='k'&& worek1.ostatnia_wyjeta!=100) // nastepna runda dopoki nie skonczy sie gra
{
printf("\n\n\n =================>  RUNDA nr %d <=================\n\n ", runda);
      
for(i=0; i<2; i++) // ruch kolejnego gracza
{	powrot=0;
rysuj_plansze(plansza);

          if(menu=='k') break;
printf("\n\n\n  Ruch GRACZA %s! \n", gracze[i].imie);
printf("  Twoja podstawka: ");
rysuj_podstawke(podstawki[i].litery);
printf ("\n\n  Co zamierzasz?\n\n  d - dodawanie wyrazu\n  w - wymiana litery\n  s - stanie kolejki\n  k - koniec \n  (badz cierpliwy, zdarza sie, ze litere trzeba wpisac dwa razy) \n");
clear ();
scanf("%c", &menu);



  

switch(menu)
{
case 'd': 
wynik_roboczy = gracze[i].wynik;
dodaj_wyraz(plansza,  podstawki[i].litery,  podstawki[i].robocza, &gracze[i].wynik, &runda, i);
doluz_litery(podstawki[i].litery, worek1.litery, &worek1.ostatnia_wyjeta);
rysuj_plansze(plansza);
if(sprawdz_wyraz()==1) 
{ 
kopiuj_podstawke(podstawki[i].litery, podstawki[i].robocza);
kopiuj_plansze(plansza, plansza_robocza);
}
else 
{
kopiuj_podstawke(podstawki[i].robocza, podstawki[i].litery);
kopiuj_plansze(plansza_robocza, plansza);
gracze[i].wynik = wynik_roboczy;
powrot = 1;
};

break;
case 'w': 
wymien_litery(podstawki[i].litery, worek1.litery, &worek1.ostatnia_wyjeta);
break;
case 's': 
stoj_kolejke();

break;
case 'k': 
break;
default:
printf("\n Ta litera nic dla mnie nie znaczy. Podaj inna \n");

break;
};
if(powrot==1)
{
if(i==0) i=1;
else i=0;
runda--;

};
if(powrot==0) printf("\n____________________________________\n  %s, Twoj wynik to: %d pkt!\n____________________________________\n", gracze[i].imie, gracze[i].wynik);

}

runda++;

}





if(gracze[0].wynik > gracze[1].wynik) 
{
printf("\n\n\n\n\n");
printf("     | /\n");
printf("     |/   __          _  __    __   _\n");
printf("     |\\  |  | |\\ | | |_ |     | _  |_| \\/\n");
printf("     | \\ |__| | \\| | |_ |__   |__| |\\  |\n");
printf("\n\n");
printf("\n\n   ===>  Wygral GRACZ o imieniu %s!  <===\n\n               Zdobyl %d pkt.\n               GRATULACJE :)\n\n", gracze[0].imie, gracze[0].wynik); 
printf("\n    GRACZ %s tym razem niestety przegral.\n    Mial %d pkt.\n\n\n", gracze[1].imie, gracze[1].wynik);
};
if(gracze[0].wynik < gracze[1].wynik) 
{
printf("\n\n   ===>  Wygral GRACZ o imieniu %s!  <===\n\n               Zdobyl %d pkt.\n        GRATULACJE!\n\n", gracze[1].imie, gracze[1].wynik); 
printf("\n    GRACZ %s tym razem niestety przegral.\n    Mial %d pkt.\n\n\n", gracze[0].imie, gracze[0].wynik);
}
if(gracze[0].wynik == gracze[1].wynik) printf("\n Ups... Jest remis! :)");
return 0;
}
