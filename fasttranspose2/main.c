#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} terms;

const int MAX_COL = 100;
void fasttranspose(terms a[], terms b[]);

int main()
{

    int size;
    printf("Enter the number of non zero elements: ");
    scanf("%d", &size);

    terms m[size + 1], tm[size + 1];
    m[0].value = size;

   // printf("Enter the number of rows and columns of the matrix: ");
    // scanf("%d %d", &m[0].row, &m[0].col);

    printf("Enter the sparse terms representation: ");
    for (int i = 0; i <= size; i++)
        scanf("%d %d %d", &m[i].row, &m[i].col, &m[i].value);

    printf("Sparse terms before transpose\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);

    fasttranspose(m, tm);

    printf("Sparse matrix after transpose\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", tm[i].row, tm[i].col, tm[i].value);
}

void fasttranspose(terms a[], terms b[]) {/* the transpose of a is placed in b */

int rowTerms [MAX_COL], startingPos [MAX_COL];
int i, j;
int numCols = a[0].col; // to switch col and row value
int numTerms = a[0].value; //to have the limit to iterate through rows in the sparse
b[0].row = numCols; // first row of t
b[0].col = a[0].row; // first row of t
b[0].value = numTerms; // first row of t

 if (numTerms > 0) {
        /* nonzero matrix */

    for (i = 0; i < numCols; i++)
        rowTerms [i] = 0;

    for (i = 1; i <= numTerms; i++)
        rowTerms [a[i].col]++;

    startingPos [0] = 1;

    for (i = 1; i < numCols; i++)

    startingPos[i] = startingPos [i-1]+rowTerms [i-1];

    for (i = 1; i <= numTerms; i++) {

        j = startingPos [a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
 }
}
