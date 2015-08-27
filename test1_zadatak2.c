#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrica[70][70];

int d;
int min=24;
int max=70;
int srednjaV=0;

int randMin=-29;
int randMax=57;

int i=0;
int j=0;

int random(int minimum, int maximum){
	return ( rand() % (maximum-minimum) ) + minimum;
}

void popuni2dMatricu(int polje[70][70],int velicina){
	for(i=0; i<velicina; i++){
		for(j=0; j<velicina; j++){
			polje[i][j]=random(randMin, randMax);
		}
	}
}

int srednjaVrijednost(int polje[70][70], int velicina){
	int zbroj=0;
	int kolicina=0;
	for(i=0; i<velicina; i++){
		if( polje[i][i] % 2 != 0 ){
			zbroj+=polje[i][i];
			kolicina++;
		}
	}
	if(zbroj!=0){
		return (zbroj/kolicina);
	}
	return 0;
}

int main(){
	time_t t;
	srand((unsigned)time(&t)) ;
	printf("upisite velicinu 2d matrice: ");
		while(1){
			scanf("%d", &d);
			if(d>min && d<=max){
				popuni2dMatricu(matrica, d);
				printf("Srednja vrijednost neparnih brojeva na glavnoj diagonali je: %d \n",
						srednjaVrijednost(matrica, d));
				break;
			}
		}
}