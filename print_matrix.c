#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file.h"

///function to print the adjacency matrix
void print_matrix(int **adjacency_matrix, int number_of_vertices)
{
int row;
int col;

for (row = 0; row < number_of_vertices; row++)
    {
            printf("\n");

        for (col = 0; col < number_of_vertices; col++)
        {
            printf("%d ", adjacency_matrix[row][col]);
        }
    }

    printf("\n");
}
