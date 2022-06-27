#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int tam;
    float c;
    int *buckets;
}HashT;

HashT *criar(unsigned int tam, float c){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->c = c;
    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

int hash(const float c, int k, int tam)
{
   return (int)(((k*c) - (int)(k*c)) * tam);
}

int h2(int k, int tam)
{
   return  1 + k % (tam - 1);
}

int rehash(int key, int tam, int i, int h1){
    return ((int)(h1 + i * h2(key, tam))) % tam;
}

int buscar(int key, HashT *t){
    int i,x = hash(t->c, key, t->tam); 
    if (t->buckets[x] == key) 
        return x;
    else if (t->buckets[x] >= 0){ 
        i = 1;
        int aux = x;
        while ((i < t->tam) && (t->buckets[x] != key) && (t->buckets[x] >= 0)){
            x = rehash(key, t->tam, i, aux);

            i++;
        }

        if ((i < t->tam) && (t->buckets[x] <= key))
            return x;

    }
    return -1;

}

int inserir(int key, HashT *t){
    int x;
    int i;
    if ((t != NULL) && (key > 0)){
        x = hash(t->c, key, t->tam); 
        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{
            i = 1;
            int aux=x;
            while ((i < t->tam) && (t->buckets[x] != key) && (t->buckets[x] >= 0)){
                x = rehash(key, t->tam, i, aux);

                i++;}

             if ((i < t->tam) && (t->buckets[x] <= 0)){
                t->buckets[x] = key;

                return 1;
            }
        }
    }

    return 0;
}

void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++){
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
        }
    }
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}

int main()
{
    int aux, tam;
    float c;
    scanf("%f %d", &c, &tam);
    HashT *t = criar(tam,c);
    scanf("%d",&tam);
    for(int i = 0; i<tam; i++){
        scanf("%d", &aux);
        inserir(aux, t);
        printf("%d\n",buscar(aux, t));
    }
    liberar(t);
}