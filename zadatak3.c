/*
Zadatak3(10 bodova):
Napisati funkciju koja određuje i vraća najmanju znamenku predanog joj cijeloga broja.
U main() funkciji omogućiti korisniku unos jednoga cijelog broja.
Pozvati funkciju s unesenom vrjednosti kao argumentom i ispisati na ekran povratnu vrijednost.
*/

#include <stdio.h>
#include <math.h>

int broj, znamenka;

int findZnamenka(int numb){
	int minZnamenka = 10;

	numb = abs(numb);
	do {								//za svaku znamenku
		znamenka = numb % 10;			//izdvoji zadnju znamenku
		numb = numb / 10;				//obrisi zadnju znamenku
		if(znamenka < minZnamenka){		//ako je nova manja od prosle	
			minZnamenka = znamenka;		//postavi novu najmanju znamenku
		}
	} while(numb>0);					//ponavljaj to dok ima znamenki

	return minZnamenka;					//vrati rjesenje
}

int main(){
	printf("unesi neki broj: ");
	scanf("%d", &broj);
	printf( "najmanja znamenka je: %d" , findZnamenka(broj) );

	return 0;
}