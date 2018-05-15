#include<stdio.h>
#include<stdlib.h>

int Adj[100][100] ,color[100];  //Adj:adjacency matrix, x:colors

void color_function (int k)
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

int main()
{
  int vtc;
  int edges;
  int i;
  int j;
  int k;
  int l;

  printf("Enter the number of vertices : ");
  scanf("%d",&vtc);  //total vertices

  printf("Enter the number of edges : ");
  scanf("%d",&edges);  //total edges

  for(i=0;i<vtc;i++)
    for(j=0;j<vtc;j++)
      Adj[i][j] = 0;  //assign 0 to all indexes of the adjacency matrix

  printf("Enter indexes where value is 1-->\n");
  for(i=0;i<edges;i++)
    {
    scanf("%d %d",&k,&l);
    Adj[k][l] = 1;
    Adj[l][k] = 1;
    }

  for(i=0;i<vtc;i++)
    color_function(i);  //coloring each vertex

  printf("Colors of vertices -->\n");
  for(i=0;i<vtc;i++)  //displaying color of each vertex
    printf("Vertex[%d] : %d\n",i+1,color[i]);

  return 0;
}
