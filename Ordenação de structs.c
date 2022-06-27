#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[30];
    char curso[30];
    float coef;
}Aluno;

int charcmp(char c1, char c2)
{   
    if(c1 > c2){
        return 1;
    }
    if(c1 == c2){
        return 0;
    }else{
        return -1;
    }
}

int cmpstr(char str1[], char str2[])
{
    int i;
    for(i = 0; (str1[i] == str2[i]) && (str1[i] != '\0') && (str1[i] != '\0'); i++);
    return charcmp(str1[i], str2[i]);
}

int cmpmat(int mat1, int mat2){
    if(mat1 > mat2){
        return 1;
    }
    if(mat1 == mat2){
        return 0;
    }else{
        return -1;
    }
}

void selectSort(Aluno **strv, int tam)
{
    Aluno *strAux;

    for (int i = 0; i < tam; i++){
        int min = i;
        for (int j = tam - 1; j > i; j--){
            if(cmpstr(strv[min]->nome, strv[j]->nome) == 1){
                min = j;
            }
            if(cmpstr(strv[min]->nome, strv[j]->nome) == 0){
                if(cmpmat(strv[min]->matricula,strv[j]->matricula) == 1){
                    min = j;
                }
                    
            }
 
        }

        if (min != i){
            strAux = strv[i];
            strv[i] = strv[min];
            strv[min] = strAux;
        }
    }
}

int main() {

    int tam;
    char name[30], curso[30];
    scanf("%d", &tam);

    Aluno **stdv = (Aluno**) malloc(sizeof(Aluno*) * tam);
    for (int i = 0; i < tam; i++)
    {
        stdv[i] = (Aluno*) malloc(sizeof(Aluno));
    }

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &stdv[i]->matricula);
        scanf(" %s", name);
        scanf(" %s", curso);
        scanf("%f", &stdv[i]->coef);
        strcpy(stdv[i]-> nome, name);
        strcpy(stdv[i]-> curso, curso);

    }

    selectSort(stdv, tam);

    for (int i = 0; i < tam; i++)
    {
        printf("%s %d %s %.2f\n",stdv[i]->nome,stdv[i]->matricula, stdv[i]->curso,stdv[i]->coef);
    }
    
    return 0;
}
