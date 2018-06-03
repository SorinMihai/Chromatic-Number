#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file.h"
int ** adjacency_matrix_generator(int number_of_vertices){
    int **adjacency_matrix;
    int row;
    int col;
    //allocating space in the memory for the matrix
    adjacency_matrix = malloc(number_of_vertices * sizeof(int*));
    for (row = 0; row < number_of_vertices; row++){
        adjacency_matrix[row] = malloc(number_of_vertices * sizeof(int));
    }
    srand(time(0));
    for (row = 0; row < number_of_vertices; row++){
        for (col = row; col < number_of_vertices; col++){
            if (row == col){
               //filling the main diagonal with 0
               adjacency_matrix[row][col] = 0;
            }else{
                //assigning the values to the matrix
                adjacency_matrix[row][col] = rand() % 2;
                adjacency_matrix[col][row] = adjacency_matrix[row][col];
            }
            adjacency_matrix[row][col] = adjacency_matrix[col][row];
        }
    }

    return adjacency_matrix;

}
