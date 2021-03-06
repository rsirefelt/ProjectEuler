#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *gridFile;
    gridFile = fopen("grid.txt", "r");

    //read file into matrix
    int nrOfCols = 20;
    int nrOfRows = 20;
    int **matrix;
    matrix = malloc(nrOfRows * sizeof(int*));
    for (int i=0; i < nrOfRows; i++)
    {
      matrix[i] = (int*)malloc(nrOfCols * sizeof(int));
    }
    
    int i;

    for(int i = 0; i < nrOfRows; i++) 
    {
      for(int j = 0; j < nrOfCols; j++)
      {
        fscanf(gridFile, "%d", &matrix[i][j]);
      }
    }

    for(int i = 0; i < nrOfRows; i++) 
    {
      for(int j = 0; j < nrOfCols; j++)
      {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
    
    int maxProd = 0;
    int firstMaxProdRow; 
    int firstMaxProdCol;
    int prodRow;
    int prodCol;
    int prodDiagRight;
    int prodDiagLeft;
    char type;
    
    
    // Start value
    for(int i = 0; i < nrOfRows; i++) 
    {
      for(int j = 0; j < nrOfCols; j++)
      {
        //Row
        if (j < nrOfCols - 3)
        {
          prodRow = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
          if (prodRow > maxProd) 
          {
            firstMaxProdRow = i; 
            firstMaxProdCol = j;
            maxProd = prodRow;
            type = 'r';
          }
        }
        
        //Col
        if (i < nrOfRows - 3)
        {
          prodCol = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
          if (prodCol > maxProd) 
          {
            firstMaxProdRow = i; 
            firstMaxProdCol = j;
            maxProd = prodCol;
            type = 'c';
          }
        }
        
        //Diag Right
        if (i < nrOfRows - 3 && j < nrOfCols - 3)
        {
          prodDiagRight = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
          if (prodDiagRight > maxProd) 
          {
            firstMaxProdRow = i; 
            firstMaxProdCol = j;
            maxProd = prodDiagRight;
            type = 'h';
          }
        }
        
        //Diag left
        if (i < nrOfRows - 3 && j >= 3)
        {
          prodDiagLeft = matrix[i][j] * matrix[i+1][j-1] * matrix[i+2][j-2] * matrix[i+3][j-3];
          if (prodDiagLeft > maxProd) 
          {
            firstMaxProdRow = i; 
            firstMaxProdCol = j;
            maxProd = prodDiagLeft;
            type = 'v';
          }
        }
        
      }
    }
    
    printf("%d %d %d", maxProd, firstMaxProdRow, firstMaxProdCol);
    
    
    
    for (int i=0; i < nrOfRows; i++)
    {
      free(matrix[i]);
    }
    free(matrix[i]);
    
    return 0;
}
