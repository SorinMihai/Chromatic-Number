#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file.h"


int color_vector[20]; //vector used to store the colors, represeted by numbers

int main()
{
    int **adjacency_matrix;
    int number_of_vertices;
    int row; //number of rows
    int color;
    int col; //number of columns
    char answer;

    printf("Would you like to manually enter the number of vertices? Y/N \n");
    scanf("%c", &answer);
    if(answer == 'Y' || answer == 'y')
    {
        printf("Enter the number of vertices : ");
        scanf("%d", &number_of_vertices);
    }

    else {

            srand(time(NULL));
            int r;
            r=rand()%500;
            number_of_vertices = r;

         }
    //allocating space in the memory for the adjacency matrix of the graph
    adjacency_matrix = malloc(number_of_vertices * sizeof(int*));
    for (row = 0; row < number_of_vertices; row++)
    {
        adjacency_matrix[row] = malloc(number_of_vertices * sizeof(int));
    }
    //assigning the adjacency matrix the random generated matrix
    adjacency_matrix = adjacency_matrix_generator(number_of_vertices);

    //printing the adjacency matrix
    print_matrix(adjacency_matrix, number_of_vertices);

    printf("\n");

    for(row = 0; row < number_of_vertices; row++)
        chromatic_number(adjacency_matrix,row);

    printf("\n");

    for(row = 0; row < number_of_vertices; row++)
        printf("Vertex[%d] = %d\n", row+1, color_vector[row]);


    printf("\n");
   //computing the minimum number of colors and assiging it to the color variable
    color = color_vector[0];
    for(row = 0; row < number_of_vertices; row++)
        if(color_vector[row] > color)
            color = color_vector[row];


    printf("\nThe minimum number of colors needed is %d. \n", color);

    //free the allocated memory to avoid performance problems
    for (row = 0; row < number_of_vertices; row++)
    {
        free(adjacency_matrix[row]);
    }
    free(adjacency_matrix);

    return 0;
}
