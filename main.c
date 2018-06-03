#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int color_vector[20];
int  chromatic_number(int **adjacency_matrix, int iterator)
{
    int row;
    int col;


    for(row = 0; row < iterator; row++)
    {

        color_vector[iterator] = 3;
        if(adjacency_matrix[row][iterator] == 1 && color_vector[iterator] != color_vector[row])
        {
            color_vector[iterator] = color_vector[row]+1;

        }
     }

     return color_vector[iterator];
}

int main()
{
    int **adjacency_matrix;
    int number_of_vertices = 6;
    int row;
    int color;
    int col;



    adjacency_matrix = malloc(number_of_vertices * sizeof(int*));
    for (row = 0; row < number_of_vertices; row++){
        adjacency_matrix[row] = malloc(number_of_vertices * sizeof(int));
    }

    adjacency_matrix = adjacency_matrix_generator(number_of_vertices);

   for (row = 0; row < number_of_vertices; row++){
            printf("\n");
        for (col = 0; col < number_of_vertices; col++){
            printf("%d ",  adjacency_matrix[row][col]);
        }
    }


    color = chromatic_number(adjacency_matrix, number_of_vertices);
    printf("\n");
    printf("\nThe minimum number of colors needed is %d. \n", color);


    for(row = 0; row < number_of_vertices; row++)
        {
        chromatic_number(adjacency_matrix, row);
        }

    for(row = 0; row < number_of_vertices; row++)
    {
    printf("Vertex[%d] = %d \n", row+1, color);
    }

    for (row = 0; row < number_of_vertices; row++)
    {
        free(adjacency_matrix[row]);
    }
    free(adjacency_matrix);

    return 0;
}
