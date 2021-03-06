#include <stdio.h>
#include <stdlib.h>

unsigned long** InitializeGrid(int dim);
void ReleaseGrid(unsigned long** grid, int dim);
void PrintGrid(unsigned long** grid, int dim);
void CalculateNrOfPaths(unsigned long** grid, int dim, int row, int col);

int main()
{
  int dim = 21;
  unsigned long** grid = InitializeGrid(dim);
  
  for (int row = dim-2; row >= 0; --row) {
    for (int col = dim-2; col >= 0; --col) {
      grid[row][col] = grid[row+1][col] + grid[row][col+1];
    }
  }
  
  PrintGrid(grid, dim);
  
  ReleaseGrid(grid, dim);
  
  return 0;
}

void CalculateNrOfPaths(int** grid, int dim, int row, int col)
{
  

}


unsigned long** InitializeGrid(int dim)
{
  unsigned long** grid = new unsigned long*[dim];
  
  for (int row = 0; row < dim; ++row) {
    grid[row] = new unsigned long[dim];
  }
  
  for (int row = 0; row < dim; ++row) {
    for (int col = 0; col < dim; ++col) {
      if (row == 20 || col == 20) {
        grid[row][col] = 1; 
      } else {
        grid[row][col] = 0;
      }
    }
  }
  
  return grid;
}

void ReleaseGrid(unsigned long** grid, int dim)
{
  for (int row = 0; row < dim; ++row) {
    delete[] grid[dim];
  }
}

void PrintGrid(unsigned long** grid, int dim) 
{
  for (int row = 0; row < dim; ++row) {
    for (int col = 0; col < dim; ++col) {
      printf("%lu ", grid[row][col]);
    }
    printf("\n");
  }
}











