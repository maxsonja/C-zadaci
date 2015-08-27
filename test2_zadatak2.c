#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a,b,i,j,x; 
float max[6][7];
float sr;
float max_sr=0xffff;

//funkcija koja vraca slucajni broj u zadanom intervalu
float random(float min, float max){  
    return ((float)rand() / ( (float)RAND_MAX)) * (max-min) + min;
}

int main(){
    time_t t;
    srand((unsigned)time(&t)) ;        //naredbe kako bi se dobila razlicita vrijednost

    printf("ucitaj mi red i stupac ");
    while(1){                                    //while petlja koja očitava i provjerava brojeve 
        scanf("%d %d", &a , &b);
        if(2<=a && a<7 && 4<=b && b<8){
            break;

        }
        else{
            printf("upisane su krive vrijednosti, pokusajte opet ");
        }


    }
    //petlja popunjava matricu random brojevima
    for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            max[i][j]=random(20,50);
        }
    }
    //petlja koja provjerava koji stupac ima najmanju vrijednost
    for(j=0; j<b; j++){
        for(i=0; i<a; i++){
            sr+=max[i][j];
        }
        sr=sr/a;
        if(sr<max_sr){
            max_sr=sr;
            x=j;
        } 
    }
    //petlja koja ispisuje stupac sa najmanjom vrjednoscu
    for(i=0; i<a; i++){
        printf("%f\n", max[x][i]);
    }
    printf("\n");
    return 0;        //kraj programa
}


/*
primjer ispisa pokrenutog programa:

ucitaj mi red i stupac 6 7
28.745874
28.221813
40.657604
46.225258
36.580044
31.926462

/*

