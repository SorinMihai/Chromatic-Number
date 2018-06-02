/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int  chromatic_number(int **adjacency_matrix, int iterator)
{
    int row;
    int col;

    for(row = 0; row < iterator; row++)
    {


        if(adjacency_matrix[row][iterator] != 0 && color_vector[iterator]!= color_vector[row])
        {
            color_vector[iterator] = color_vector[row]+1;

        }
     }

     return color_vector[iterator];
}
*/
