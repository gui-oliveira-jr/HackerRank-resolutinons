#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;
typedef struct HashT HashT;

HashT *criarHt(unsigned int tam);
int inserir(int key, HashT *t);
void imprimir(HashT *t);
int liberar(HashT *t);
struct HashT
{
    unsigned int tam;
    int *buckets;
} ;
struct Cell
{
    int item;
    Cell *next;
};
struct ListaE
{
    Cell *head;
};
struct Spa_Mat
{
    int n_lin;
    ListaE **lin;
};

Spa_Mat *criarMs(int l)
{
    Spa_Mat *mat = (Spa_Mat *)malloc(sizeof(Spa_Mat));
    int i;

    mat->n_lin = l;
    mat->lin = (ListaE **)malloc(sizeof(ListaE *) * l);

    for (i = 0; i < l; i++)
    {
        mat->lin[i] = (ListaE *)malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    return mat;
}

Cell *criar_celula(int item)
{
    Cell *nova = (Cell *)malloc(sizeof(Cell));
    nova->item = item;
    nova->next = NULL;

    return nova;
}

void insertInLine(int item, ListaE *l)
{
    Cell *auxA, *auxP, *novo;

    if (l->head == NULL)
    {
        novo = criar_celula(item);
        novo->next = l->head;
        l->head = novo;
    }
    else
    {
        auxA = l->head;
        auxP = auxA;

        while (auxP != NULL)
        {
            auxA = auxP;
            auxP = auxP->next;
        }

        if (auxP != NULL)
            auxP->item = item;
        else
        {
            novo = criar_celula(item);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}

HashT *criarHt(unsigned int tam)
{
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

int hashingF(int k, int B)
{
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa)
{
    return (hashC + tentativa) % B;
}

int inserir(int key, HashT *t)
{
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0))
    {
        x = hashingF(key, t->tam);

        if (t->buckets[x] <= 0)
        {
            t->buckets[x] = key;

            return 1;
        }
        else
        {
            i = 1;
            rh = x;

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0))
            {
                rh = overflow_prog(x, t->tam, i);

                i++;
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0))
            {
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}

void imprimir(HashT *t)
{
    int i;
    if (t != NULL)
    {
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
    }
}
void imprimirOpenHash(Spa_Mat *mat)
{
    int i;
    Cell *aux;

    for (i = 0; i < mat->n_lin; i++)
    {
        aux = mat->lin[i]->head;
        printf("%d: ", i);
        while (aux != NULL)
        {

            printf("-> %d ", aux->item);

            aux = aux->next;
        }
        printf("\n");
    }
}

int liberar(HashT *t)
{
    if (t != NULL)
    {
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}
Spa_Mat *convertOpenHash(HashT *t, int l)
{
    Spa_Mat *mat = criarMs(l);

    int indice;

    int i;
    if (t != NULL)
    {
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
            {
                indice = hashingF(t->buckets[i], t->tam);
                insertInLine(t->buckets[i], mat->lin[indice]);
            }
    }

    return mat;
}

int main(void)
{
    int n, nkey, key;

    scanf("%d", &n);
    scanf("%d", &nkey);

    HashT *t = criarHt(n);
    Spa_Mat *mat = criarMs(n);

    for (int i = 0; i < nkey; i++)
    {
        scanf("%d", &key);

        inserir(key, t);
    }

    mat = convertOpenHash(t, n);

    imprimirOpenHash(mat);
}