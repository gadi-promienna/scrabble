#define OBIEKT struct


struct litera
{
char znak;
int wartosc;
};


struct podstawka
{
struct litera litery[8];
struct litera robocza[8];
};

struct worek
{
struct litera litery[100];
int ostatnia_wyjeta;

};

struct gracz
{ 
char imie[20];
int wynik;
};

struct pole
{
int nr;
OBIEKT litera litera_pola;
int wartosc;
};

void clear (void)
{ 
while ( getchar() != '\n' );
}

void wypelnij_worek(OBIEKT litera *litery)
{
struct litera alfabet[29];

//samogloski (a, o, i, u, y, e) oraz m, n, b, c, z,\n- 2 pkt: s, d, f, g, h, j, k, l,\n- 3 pkt: w, r, t, p
char samogloski[6] = {'a', 'o', 'i', 'u', 'y', 'e'};
char grupa2[5] =  {'m', 'n', 'b', 'c', 'z'};
char grupa3[8] = { 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
char grupa4[4] = {'w', 'r', 't', 'p' };

int i;
int j;
for(i=0; i<6; i++) // stworzenie puli liter, z ktorej beda losowane litery do worka
{
alfabet[i].znak = samogloski[i];
alfabet[i].wartosc = 1;
}

j=i;

for(i=0; i<5; i++) 
{
alfabet[j+i].znak = grupa2[i];
alfabet[j+i].wartosc = 1;
}

j=j+i;
for(i=0; i<8; i++) 
{
alfabet[j+i].znak = grupa3[i];
alfabet[j+i].wartosc = 2;
}

j=j+i;

for(i=0; i<6; i++) 
{
alfabet[j+i].znak = samogloski[i];
alfabet[j+i].wartosc = 1;
}

j=j+i;

for(i=0; i<4; i++) 
{
alfabet[j+i].znak = grupa4[i];
alfabet[j+i].wartosc = 3;
}


//for(i=0; i<29; i++) printf(" \n l: %c ", alfabet[i].znak);

//printf("\n ");

srand(time(0));
int los;
for(i=0; i<100; i++) 
{
los = rand()%29;
litery[i] = alfabet[los];
//printf(" \n l: %c ", litery[i].znak);
}
};

void wypelnij_podstawke (OBIEKT litera *litery_podstawki, OBIEKT litera *litery_worka, int *ostatnia_wyjeta)
{
 int i;
 for(i=0; i<8; i++) litery_podstawki[i] = litery_worka[i + (*ostatnia_wyjeta)];
 *ostatnia_wyjeta=*ostatnia_wyjeta+8;
 for(i=0; i<8; i++)  printf(" %c |", litery_podstawki[i].znak);

};


void kopiuj_podstawke (OBIEKT litera *podstawka_wklejana, OBIEKT litera *podstawka_zmieniana)
{
int i;
for(i=0; i<8; i++) podstawka_zmieniana[i] = podstawka_wklejana[i];
}




void rysuj_podstawke (OBIEKT litera *litery_podstawki)
{
 int i;
 for(i=0; i<8; i++)  printf(" %c |", litery_podstawki[i].znak);

};

void tworz_plansze(OBIEKT pole (*plansza)[10])
{
int i, j;

plansza[0][0].litera_pola.znak = ' ';
for(i=1; i<10; i++) plansza[i][0].litera_pola.znak = (i + '0');
for(i=1; i<10; i++) plansza[0][i].litera_pola.znak = (i + '0');

for(i=1; i<10; i++) 
{ 
for(j=1; j<10; j++)  {
plansza[i][j].litera_pola.znak = '|';
plansza[i][j].wartosc = 1; //dajemy jakies pola premiowane? ;)
}



}
printf ("\n");

};

void rysuj_plansze(OBIEKT pole (*plansza)[10])
{
int i, j;
printf ("\n    PLANSZA: \n \n");
for(i=0; i<10; i++) 
{ 
for(j=0; j<10; j++) printf ("%2c", plansza[j][i].litera_pola.znak);

printf ("\n");
}


};

void kopiuj_plansze (OBIEKT pole (*plansza_wklejana)[10], OBIEKT pole (*plansza_zmieniana)[10])
{
int i;
int j;
for(i=0; i<10; i++) 
{ 
for(j=0; j<10; j++) plansza_zmieniana[i][j] = plansza_wklejana[i][j];
}
}	

void dodaj_wyraz(OBIEKT pole (*plansza)[10], OBIEKT litera *litery_podstawki,  OBIEKT litera *litery_robocze, int *wynik, int *runda, int gracz) 
{
int i;
int x=4;
int y=4;
int kier=0;
char znak='1';
int punkty;
for(i=0; i<8; i++) litery_robocze[i]=litery_podstawki[i];
if(*runda!=1||gracz==1){	 //pierwszy gracz zaczyna od srodka
printf("\n\n  Od ktorego pola chcesz dodawac litery? \n wspolrzedna pozioma: \n");
scanf ("%d", &x);
printf("\n wspolrzedna pionowa: \n");
scanf ("%d", &y); 
printf ("x: %d ", x); 
printf ("y: %d ", y);
}
printf("\n  Chcesz wpisywac litery w pionie, czy w poziomie (1 - pionowo, 2 - poziomo)?\n  Wybierz cyfrę, kliknij enter. Nastepnie wpisz slowo i rowniez zatwierdz je enterem.\n  (!!! PAMIETAJ : jesli wykorzystasz litery, ktorych nie masz na podstawce, rezulatem Twojego ruchu bedzie... brak ruchu!)\n");
scanf("%d", &kier);


clear();
if(kier==1) // obsluga pionowo wpisywanych liter

while((znak=getchar())!='\n'&&y<10)
{	
punkty = 0;

if(plansza[x][y].litera_pola.znak == znak&&znak!='|')
{
punkty = plansza[x][y].litera_pola.wartosc * plansza[x][y].wartosc ;
*wynik=*wynik+punkty;
y++;
printf("\n Literka %c na tym polu warta jest %d punktow \n", znak, punkty);
}	

if((punkty=dobra_litera(litery_podstawki, &znak))!=0&&(plansza[x][y].litera_pola.znak=='|'||plansza[x][y].litera_pola.znak==znak))
{ plansza[x][y].litera_pola.znak = znak;
plansza[x][y].litera_pola.wartosc = punkty ;
punkty = punkty * plansza[x][y].wartosc;
*wynik=*wynik+punkty;
//printf(" %d wynik2", *wynik);
y++;
printf("  Za literke '%c' masz %d pkt \n", znak, punkty);	

}

}

if(kier==2)  // obsluga poziomo wpisywanych liter
while((znak=getchar())!='\n'&&x<10)
{	
punkty = 0;

if(plansza[x][y].litera_pola.znak == znak&&znak!='|')
{
punkty = plansza[x][y].litera_pola.wartosc;
punkty = punkty * plansza[x][y].wartosc;
*wynik=*wynik+punkty;
x++;
printf("\n Dostajesz za literke %c %d punktow \n", znak, punkty);
}


//printf(" %d wynik1", *wynik);
if((punkty=dobra_litera(litery_podstawki, &znak))!=0&&(plansza[x][y].litera_pola.znak=='|'))
{ 
plansza[x][y].litera_pola.znak = znak;
plansza[x][y].litera_pola.wartosc = punkty ;
punkty = punkty * plansza[x][y].wartosc;
*wynik=*wynik+punkty;
//printf(" %d wynik2", *wynik);
x++;
printf("\n Dostajesz za literke %c %d punktow \n", znak, punkty);
}

}
clear();

};
int sprawdz_wyraz()
{	
int wyrok;
printf("\n Czy przeciwnik zgadza sie na taki wyraz? :P \n 1-tak, 0-nie \n");
scanf("%d", &wyrok);
if(wyrok==0) {
printf ("\n Jaka szkoda... Mnie sie ten wyraz bardzo podobal :) \n ");
return 0; }
else return 1;
};
void doluz_litery(OBIEKT litera *litery_podstawki, OBIEKT litera *litery_worka, int *ostatnia_wyjeta)
{

int i;
for(i=0; i<8; i++)
if(litery_podstawki[i].znak == '0')	
{litery_podstawki[i] = litery_worka[i + (*ostatnia_wyjeta)];
*ostatnia_wyjeta=*ostatnia_wyjeta+1; }
 



};


void wymien_litery(OBIEKT litera *litery_podstawki, OBIEKT litera *litery_worka, int *ostatnia_wyjeta)
{	
int i;
int kolejna=1;
OBIEKT litera robocza;
int los;
srand(time(0));
while(kolejna==1)
{
printf("\n Ktora litere chcesz wymienic? \n Wpisz numer od 0-7 \n");	
scanf("%d", &i); //numer litery, ktora gracz chce wymienic
//litery_podstawki[i] = litery_worka[i + (*ostatnia_wyjeta)];
//*ostatnia_wyjeta=*ostatnia_wyjeta+1; 
robocza=litery_podstawki[i];
los =rand()%(100- *ostatnia_wyjeta) + *ostatnia_wyjeta; // losowanie litery, na ktora zamieniam
litery_podstawki[i]=litery_worka[los];
litery_worka[los]=robocza;
rysuj_podstawke(litery_podstawki);
printf("\n Wymieniasz nastepna litere? 1-tak 0-nie\n");
scanf("%d", &kolejna);}





};


int dobra_litera (OBIEKT litera *litery_podstawki, char *znak) 
{
int waga;
int i;

int powt=0; // żeby przyjmowało powtórzone litery
for(i=0; i<8; i++) if(litery_podstawki[i].znak==*znak&&powt==0)
{
waga = litery_podstawki[i].wartosc;
litery_podstawki[i].znak='0';
litery_podstawki[i].wartosc=0; 
//printf(" waga %d", waga);

return waga;

};
return 0;


};
void stoj_kolejke(){};
