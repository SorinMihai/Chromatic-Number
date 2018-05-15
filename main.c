#include<stdio.h>
#include<stdlib.h>

int Adj[50][50] ,color[50];  //Adj:adjacency matrix, x:colors

void next_color (int k)
{
   int i;
   int j;
   color[k] = 1;  //coloring vertex with color 1

   for(i=0;i<k;i++) //checking all k-1 vertices-backtracking
    {
     if(Adj[i][k] != 0 && color[k] == color[i])  //if they have the same color
       color[k] = color[i]+1;  //assign higher color than color[i]
   }
}

int main(){

  return 0;
}
