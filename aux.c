#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;

HashT *criar(unsigned int tam);

int inserir(int key, HashT *t);

void imprimir(HashT *t);

int liberar(HashT *t);

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hashingF(int k, int B){
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}

int inserir(int key, HashT *t){
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam);

        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{ 
            i = 1; 
            rh = x; 

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = overflow_prog(x, t->tam, i); 

                i++; 
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
        
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

int main(void){
    int n, nkey, key;

    scanf("%d", &n);
    scanf("%d", &nkey);

    HashT *t = criar(n);

    for (int i = 0; i < nkey; i++)
    {
        scanf("%d", &key);

        inserir(key, t);

    }

    imprimir(t);
    
}