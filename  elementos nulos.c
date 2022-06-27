#include <stdio.h>
#include <stdlib.h>
typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;

struct Cell
{
    int item;
    int col;
    Cell *next;
};

struct ListaE
{
    Cell *head;
};

struct Spa_Mat
{
    int n_lin;
    int n_col;
    ListaE **lin;
};

Spa_Mat *criar(int l, int c)
{
    Spa_Mat *mat = (Spa_Mat *)malloc(sizeof(Spa_Mat));
    int i;

    mat->n_col = c;
    mat->n_lin = l;
    mat->lin = (ListaE **)malloc(sizeof(ListaE *) * l);

    for (i = 0; i < l; i++)
    {
        mat->lin[i] = (ListaE *)malloc(sizeof(ListaE));
        mat->lin[i]->head = NULL;
    }

    return mat;
}

Cell *criar_celula(int item, int col)
{
    Cell *nova = (Cell *)malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}

void insertInLine(int item, int col, ListaE *l)
{
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col))
    {
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    }
    else if (col == l->head->col)
    {
        l->head->item = item;
    }
    else
    {
        auxA = l->head;
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col))
        {
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        else
        {
            novo = criar_celula(item, col);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}

Spa_Mat* convertBiMat(int **bi, int l, int c)
{
    Spa_Mat *mat = criar(l, c);

    int elNull = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (bi[i][j] == 0)
            {
                elNull++;
            }
            else
            {
                insertInLine(bi[i][j], j, mat->lin[i]);
            }
        }
    }
    printf("%d", elNull);

    return mat;
}

int **gerarBiMat(int l, int c)
{
    int **mat = (int **)malloc(sizeof(int *) * l);
    for (int i = 0; i < l; i++)
    {
        mat[i] = (int *)malloc(sizeof(int) * c);
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
   
    return mat;
}


int main(void)
{
    int l, c;

    scanf(" %d %d", &l, &c);

    int **biMat = gerarBiMat(l, c);

    convertBiMat(biMat, l, c);
}
