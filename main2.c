#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int ColorVector[20];
void  chromatic_number(int k)
{
    int **adjacency_matrix;
    int line;
    int col;
    int color=1;

   // color_vect[k]=malloc(sizeof(int));
    color_vect[k]=1;
    for(row = 0; row < k; row++)
    {
        if(adjacency_matrix[row][k]==1 && color_vect[k]!= adjacency_matrix[row])
        {
          //  color_vect[k]=malloc(sizeof(int));
            color_vect[k]=adjacency_matrix[line]+1;
        }
     }

int main()
{
    int number_of_vertices = 6;
    int **adjacency_matrix;
    int color;
    int row;
    int col;

    adjacency_matrix = malloc(number_of_vertices * sizeof(int*));
    for (row = 0; row < number_of_vertices; row++){
        adjacency_matrix[row] = malloc(number_of_vertices * sizeof(int));
    }

    adjacency_matrix = generator_matrix(number_of_vertices);

   for (row = 0; row < number_of_vertices; row++){
            printf("\n");
        for (col = 0; col < number_of_vertices; col++){
            printf("%d ",  adjacency_matrix[row][col]);
        }
    }


   /* color=chromatic_number(adjacency_matrix, no_vertices);
    printf("\n");
    printf("\nThe minimum number of colors needed is %d.", color);
    */

    for(row = 0; row < number_of_vertices; row++){
        chromatic_number(row);
   }

   for(row = 0; row < number_of_vertices; row++){
    printf("Vertex[%d] = %d", row+1, color_vect[row]);
   }


    for (row = 0; row < number_of_vertices; row++){
        free(adjacency_matrix[row]);
    }
    free(adjacency_matrix);

    return 0;
}
