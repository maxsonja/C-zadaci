/*
u sublimeu postavi build system na c++
stisni ctrl+b
i u folderu di se nalazi spremljen ovaj file ces imat .exe istog imena kojeg pokrenes
*/

#include <stdio.h>		
#include <math.h>		//sadržava funkciju za eksponent
#include <unistd.h>		//dodatne funkcije za unos (nije napisano u zadatku ali
						// cist da se ljepse vidi rezultat kad pokrenes program)

float element[18];			//array maksimalne dužine unosa
float broj;					//broj unesenih elemenata koliko se želi
float donja_granica=7;		//donja granica intervala
float gornja_granica=19;	//gornja granica intervala

float srednjaV;				//varijabla za srednju vrijednost

int i;						//int za petlje
char tmp=0;					//varijabla korištena za prestanak rada programa, *nije obavezno za sami zadatak


//funkcija za izracunavanje srednje vrijednosti
float srednjaVrijednost(float niz[],int duzina){
	float zbroj =0;
	for(i=0; i<duzina; i++){
		zbroj += niz[i];
	}
	return zbroj/duzina;
}

//funkcija za ispis elemenata *nije zadano u zadatku
void ispisiElemente(float niz[],int broj){
	for(i=0; i<broj; i++){
		printf("%f\t", niz[i]);
	}
	printf("\n");
}

int main(){

	printf("unesi broj elemenata (vise od 7 i manje od 19): ");
	while(1){												//glavnja petlja za upis brojeva
		scanf("%f", &broj);									//čeka upis broja elemenata
		if(broj>donja_granica && broj<gornja_granica){		//provjerava jeli je broj unutar intervala	
			for(i =0; i<broj; i++){							//ako da, traži upis vrijednosti u ta polja
				printf("upisite broj u element %i: " , i);
				scanf("%f", &element[i]);
			}
			srednjaV = srednjaVrijednost(element, broj);	//izracun srednje vrijednosti elemenata

			for(i=0; i<broj; i++){							//provjera svih elemenata
				if(element[i]<srednjaV){					//dali su manji od srednje vrijednosti
					element[i]=powf(element[i], 3);			//ako da element^3
				}
			}

			//ovo nije zadano u zadatku, pregledat ispis rezultata
			printf("\nSrednja Vrijednost: %f\nVrjednosti elemenata:\n", srednjaV);
			ispisiElemente(element, broj);

			//kraj programa kad se stisne enter
			sleep(1);
			fflush ( stdin );
			printf("\n--<stisni enter za kraj>--");
			
			while(tmp != '\n'){
				scanf("%c", &tmp);
			}

			break;	//kraj programa
		}
		else {	//ako uneseni broj elemenata nije u intervalu
			printf("broj %f nepripada potrebnom intervalu, pokusajte opet: ", broj);
		}

	}
}

