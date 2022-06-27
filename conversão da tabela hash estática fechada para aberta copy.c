#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

int inserir(int key, Spa_Mat *t);
void imprimir(Spa_Mat *mat);

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

int hashingF(int k, int B)
{
    return k % B;
}

void imprimir(Spa_Mat *mat)
{
    int i;
    Cell *aux;
    printf("\n");
    for (i = 0; i < mat->n_lin; i++)
    {
        aux = mat->lin[i]->head;
        printf("%d: ->", i);
        while (aux != NULL)
        {

            printf(" %d ", aux->item);

            aux = aux->next;
            if (aux != NULL)
            {
                printf("->");
            }
        }
        printf("\n");
    }
}

int liberarMs(Spa_Mat *m)
{
    if (m != NULL)
    {
        free(m->lin);

        free(m);

        return 1;
    }

    return 0;
}

void insertHash(Spa_Mat *mat, int key)
{
    insertInLine(key, mat->lin[hashingF(key, mat->n_lin)]);
    printf("%d\n", hashingF(key, mat->n_lin));

}

int main(void)
{
    int n, nkey, key;

    scanf("%d", &n);
    scanf("%d", &nkey);
    Spa_Mat *mat = criarMs(n);

    for (int i = 0; i < nkey; i++)
    {
        scanf("%d", &key);

        insertHash(mat, key);
    }

    imprimir(mat);

    liberarMs(mat);
}