#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int charcmp(char c1, char c2)
{
    if (c1 > c2) 
        return 1;
    else
        return 0;
}

int cmpstr(char str1[], char str2[])
{
    int i;
    for (i = 0; (str1[i] == str2[i]) && (str1[i] != '\0') && (str1[i] != '\0'); i++);

    return charcmp(str1[i], str2[i]);
}

void selectSort(char **strv, int tam)
{
    char *strAux;

    for (int i = 0; i < tam; i++){
        int min = i;
        for (int j = tam - 1; j > i; j--){
            if (cmpstr(strv[min], strv[j]) == 1)
            {
                min = j;
            }
        }

        if (min != i){
            strAux = strv[i];
            strv[i] = strv[min];
            strv[min] = strAux;
        }
    }
}

int main(void)
{
    int tam;

    scanf("%d", &tam);

    char **strv = (char **)malloc(sizeof(char *) * tam);
    for (int i = 0; i < tam; i++){
        strv[i] = (char *)malloc(sizeof(char) * 30);
    }

    for (int j = 0; j < tam; j++){
        scanf(" %s", strv[j]);
    }

    selectSort(strv, tam);
    for (int i = 0; i < tam; i++){
        printf("%s\n", strv[i]);
    }
}
