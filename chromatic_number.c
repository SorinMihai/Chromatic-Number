#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header_file.h"


int color_vector[20];
int  chromatic_number(int **adjacency_matrix, int iterator)
{
    int row;
    int col;

    ///initializing the first color with 1
    color_vector[iterator] = 1;
    for(row = 0; row < iterator; row++)
    {   ///if two neighbours have the same color, assign higher color
        if(adjacency_matrix[row][iterator] == 1 && color_vector[iterator] == color_vector[row])
        {
            color_vector[iterator] = color_vector[row]+1;

        }
     }


}

