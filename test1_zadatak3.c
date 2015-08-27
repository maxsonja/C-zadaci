//zadatak 3
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