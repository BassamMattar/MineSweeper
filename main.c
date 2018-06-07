#include <stdio.h>
#include <stdlib.h>
#include "mine.h"
#include <time.h>
#include <windows.h>
#define max 99
int openScreen();
int choosingLevel(int*,int*,int*);
void initializingAllArrays(int a1[][max],int a2[][max],int a3[][max],int a4[][max],char a5[][max],char a6[][max],int,int);
void puttingBombs(int a1[][max],char a2[][max],int,int,int);
void indication(int a1[][max],int a2[][max],int,int);
void userInput(char *,int *,int *,int,int);
void emptyCell(int a1[][max],int a2[][max],char a3[][max],int rows,int columns,int USIi,int USIj);
int main()
{
    int choice,digitalArray[max][max],indicateArray[max][max],visitArray0[max][max],visitArray1[max][max];
    char displayArray[max][max],loseArray[max][max],option;
    int rows , columns,noOfbombs,Ui,Uj,i,j;
    srand(time(0));
    choice = openScreen();
    if(choice == 1){
        choosingLevel(&rows,&columns,&noOfbombs);
        initializingAllArrays(digitalArray,indicateArray,visitArray0,visitArray1,displayArray,loseArray,rows,columns);
        puttingBombs(digitalArray,loseArray,rows,columns,noOfbombs);
        indication(digitalArray,indicateArray,rows,columns);
        userInput(&option,&Ui,&Uj,rows,columns);
        emptyCell(indicateArray,visitArray0,displayArray,rows,columns,Ui,Uj);
    }else if(choice == 2){
    }else{
    }

    return 0;
}
