#define max 99
int counter =0 ;
int openScreen(){
printf("****************************************************************************\n");
printf("*                                                                          *\n");
printf("*                                                                          *\n");
printf("*                                                                          *\n");
printf("*                        *     *  ***  **      *  ******                   *\n");
printf("*                        * * * *   *   * *     *  *                        *\n");
printf("*                        *  *  *   *   *   *   *  ******                   *\n");
printf("*                        *     *   *   *     * *  *                        *\n");
printf("*                        *     *  ***  *       *  ******                   *\n");
printf("*                                                                          *\n");
printf("*                                                                          *\n");
printf("*          ******    *     *  ******  ******  *****   ******   *****       *\n");
printf("*         *          *     *  *       *       *    *  *        *    *      *\n");
printf("*          ******    *  *  *  ******  ******  *****   ******   *****       *\n");
printf("*                *   * * * *  *       *       *       *        *    *      *\n");
printf("*          ******    *     *  ******  ******  *       ******   *     *     *\n");
printf("*                                                                          *\n");
printf("*                                  1 New Game                              *\n");
printf("*                                                                          *\n");
printf("*                                  2 Custom Game                           *\n");
printf("*                                                                          *\n");
printf("*                                  3 Load Game                             *\n");
printf("*                                                                          *\n");
printf("*                                 >> ");
int choice;
scanf("%d",&choice);
printf("*                                                                          *\n");
printf("****************************************************************************\n");

while(1){
    if(choice==1||choice==2||choice==3){
        system("Cls");
        return choice;
    }else{
        printf("Invalid input!!\nPlease enter 1 for (New Game) or 2 for (Custom Game) or 3 for (Load Game)\n >> ");
    scanf("%d",&choice);
    }
}
}
int choosingLevel(int *rows,int *columns,int* noOfbombs){
    int choice;
printf("****************************************************************************\n");
printf("*                                                                          *\n");
printf("*                                                                          *\n");
printf("*                  PLEASE CHOOSE THE DIFFICULTY YOU WANT :                 *\n");
printf("*                                                                          *\n");
printf("*                   1 EASY                                                 *\n");
printf("*                                                                          *\n");
printf("*                   2 MEDIUM                                               *\n");
printf("*                                                                          *\n");
printf("*                   3 HARD                                                 *\n");
printf("*                                                                          *\n");
printf("*                 >>                                                       *\n");
printf("*                                                                          *\n");
printf("****************************************************************************\n");
scanf("%d",&choice);
while(1){
    if(choice!=1&&choice!=2&&choice!=3){
    printf("Invalid input!!\nPlease enter 1 for (EASY) or 2 for (MEDIUM) or 3 for (HARD)\n >> ");
    scanf("%d",&choice);
    }else{
        break;
    }
}
if(choice==1){
    *rows = 9;
    *columns= 9;
    *noOfbombs= 10;
}else if(choice==2){
    *rows = 16;
    *columns= 16;
    *noOfbombs= 40;
}else{
    *rows = 16;
    *columns= 30;
    *noOfbombs= 99;
}
system("Cls");
}
void initializingAllArrays(int a1[][max],int a2[][max],int a3[][max],int a4[][max],char a5[][max],char a6[][max],int rows,int columns){
    int i , j ;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            a1[i][j]=0;
            a2[i][j]=0;
            a3[i][j]=0;
            a4[i][j]=0;
            a5[i][j]=178;
            a6[i][j]=169;
        }
    }
}
void puttingBombs(int a1[][max],char a2[][max],int rows,int columns,int noOfbombs){
    int i , j ;
    i = rand()%rows;
    j= rand()%columns;
    if(counter < noOfbombs){
        if(a1[i][j]==0 && (i != 0 || j != 0)){
            counter++;
            a1[i][j]=1;
            a2[i][j]=144;
            puttingBombs(a1,a2,rows,columns,noOfbombs);
        }else{
            puttingBombs(a1,a2,rows,columns,noOfbombs);
        }
    }
}
void indication(int a1[][max],int a2[][max],int rows,int columns){
    int i , j, ii , jj , surroundingBombs =0 ;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            for(ii=i-1;ii<=i+1;ii++){
                for(jj=j-1;jj<=j+1;jj++){
                    if(ii>=0 && jj >= 0 && a1[i][j] != 1 && ii < rows && j < columns){
                        surroundingBombs+=a1[ii][jj];
                    }
                }
            }
            if(a1[i][j]!=1){
            a2[i][j]=surroundingBombs;
            surroundingBombs=0;
            }else{
            a2[i][j]=9;
            }
        }
    }
}
void userInput(char *x,int *y,int *z,int rows,int columns){
    char a;int b , c;
    fflush(stdin);
    printf("Please enter (p) to open or (f) to put flag or (q) to query or (e) to erase flag .");
    scanf("%c",&a);
    while(1){
        if(a=='p'||a=='f'||a=='e'||a=='q'){
            *x=a;
            break;
        }else{
            printf("\nInvalid input please make sure that you enter (p) or (f) or (e).\nNote: this input is sensitive case.\n");
            scanf("%c",&a);
        }
    }
    scanf("%d",&b);
    b--;
    while(1){
        if(b<=rows&&b>=0){
            *y=b;
            break;
        }else{
            printf("Invalid input please make sure that the coordinates of the box are in the range\n");
            scanf("%d",&b);
            b--;
        }
    }
    scanf("%d",&c);
    c--;
    while(1){
        if(c<=columns&&c>=0){
            *z=c;
            break;
        }else{
            printf("Invalid input please make sure that the coordinates of the box are in the range\n");
            scanf("%d",&c);
            c--;
        }
    }
    system("Cls");
}
void emptyCell(int a1[][max],int a2[][max],char a3[][max],int rows,int columns,int Ui,int Uj){
    int i , j ;
    a3[Ui][Uj]=' ';
    a2[Ui][Uj]=1;
    counter++;
    for(i=Ui-1;i<=Ui+1;i++){
        for(j=Uj-1;j<=Uj+1;j++){
            if(a1[i][j]==0 && a2[i][j]==0&&i>=0&&j>=0&&i<rows&&j<columns){
                emptyCell(a1,a2,a3,rows,columns,i,j);
            }else{
                a3[i][j]=48+a1[i][j];
            }
        }
    }
}
void recurtion(int Ui ,int Uj){
    int i=Ui,j=Uj;
    if(i<9 && j<9){
        i++;
        j++;
        printf("%d %d\n",i,j);
        recurtion(i,j);
    }

}
