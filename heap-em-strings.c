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

void refazer(char **v, int esq, int dir){
	int j = (esq + 1) * 2 - 1; 
	char *x = v[esq]; 

	while (j <= dir){

		if ((j < dir) && (cmpstr(v[j + 1], v[j]) == 1))
			j++;

		if (cmpstr(x,v[j]) == 1)
			break;

		v[esq] = v[j];
		esq = j; 
		j = (esq + 1) * 2 - 1; 
	}

	v[esq] = x;
}

void gerarHeap(char **v, int n){
	int esq = n / 2;

	while (esq >= 0){
		refazer(v, esq, n - 1);
		esq--;
	}
}

void heapsort(char **v, int n){
	char *x;
	int dir = n - 1;

	gerarHeap(v, n); 

	while (dir > 0){
		x = v[0];
		v[0] = v[dir];
		v[dir] = x;
		dir--;

		refazer(v, 0, dir);
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

    heapsort(strv, tam);
    for (int i = 0; i < tam; i++){
        printf("%s\n", strv[i]);
    }
}
