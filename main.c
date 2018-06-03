#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file.h"


int color_vector[20]; //vector used to store the colors, represeted by numbers

int main()
{
    int **adjacency_matrix;
    int number_of_vertices =rand();
    int row; //number of rows
    int color;
    int col; //number of columns


    //allocating space in the memory for the adjacency matrix of the graph
    adjacency_matrix = malloc(number_of_vertices * sizeof(int*));
    for (row = 0; row < number_of_vertices; row++){
        adjacency_matrix[row] = malloc(number_of_vertices * sizeof(int));
    }
    //assigning the adjacency matrix the random generated matrix
    adjacency_matrix = adjacency_matrix_generator(number_of_vertices);

   for (row = 0; row < number_of_vertices; row++){
            printf("\n");
        for (col = 0; col < number_of_vertices; col++){
            printf("%d ",  adjacency_matrix[row][col]);
        }
    }

    printf("\n");

    for(row = 0; row < number_of_vertices; row++)
        chromatic_number(adjacency_matrix,row);

    for(row = 0; row < number_of_vertices; row++)
        printf("Vertex[%d] = %d\n", row+1, color_vector[row]);



   //computing the minimum number of colors and assiging it to the color variable
    color = color_vector[0];
    for(row = 0; row < number_of_vertices; row++)
        if(color_vector[row] > color)
            color = color_vector[row];

    printf("\n");

    printf("\nThe minimum number of colors needed is %d. \n", color);

    //free the allocated memory to avoid performance problems
    for (row = 0; row < number_of_vertices; row++)
    {
        free(adjacency_matrix[row]);
    }
    free(adjacency_matrix);

    return 0;
}
