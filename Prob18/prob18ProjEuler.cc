#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

void readData(FILE *inFile, std::vector<std::vector<int> > &data); 
void printData(std::vector<std::vector<int> > &data); 
void getMaxSumData(std::vector<std::vector<int> > &data,
  std::vector<std::vector<int> > &maxSum);
void printMaxSum(std::vector<std::vector<int> > &maxSum);

int main()
{
  char inFileName[] = "data";
  FILE *inFile = fopen(inFileName,"r");

  if (inFile == NULL) {
    fprintf(stderr, "Can't open input file %s!\n", inFileName);
    exit(1);
  }

  std::vector<std::vector<int> > data, maxSum;
  
  readData(inFile, data); 
  printData(data);
  getMaxSumData(data, maxSum);
  printData(maxSum);
  printMaxSum(maxSum); 
   
  fclose(inFile);
  return 0;
}
    
    

void readData(FILE *inFile, std::vector<std::vector<int> > &data)
{
  std::vector<int> newRow; 
  data.push_back(newRow); 
  
  int row = 0;
  int i;  
  char delim; 
  while (fscanf(inFile,"%d%c",&i,&delim) == 2) {
    data[row].push_back(i); 
    
    if (delim == '\n') {
      data.push_back(newRow);
      ++row;
    }
  }
}
  
  
void printData(std::vector<std::vector<int> > &data)
{
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < data[i].size(); ++j) {
      printf("%i ", data[i][j]); 
    }
    printf("\n"); 
  }   
}


void getMaxSumData(std::vector<std::vector<int> > &data,
  std::vector<std::vector<int> > &maxSum)
{
  // Dynamic Programming with memoization
  for (int row = 0; row < data.size(); ++row) {
    std::vector<int> newRow; 
    maxSum.push_back(newRow);
    int maxSumSoFar; 
    
    if (row == 0) {
      maxSum[row].push_back(data[0][0]);
    } else {
      for (int col = 0; col < data[row].size(); ++col) {
        if (col == 0) {
          maxSumSoFar = data[row][col] + maxSum[row-1][col]; 
        } else if (col == data[row].size()-1) {
          maxSumSoFar = data[row][col] + maxSum[row-1][col-1];
        } else {
          maxSumSoFar = data[row][col] + 
            std::max(maxSum[row-1][col], maxSum[row-1][col-1]);
        }
        
        maxSum[row].push_back(maxSumSoFar); 
      }      
    }
  }
}

void printMaxSum(std::vector<std::vector<int> > &maxSum)
{
  int lastRow = maxSum.size()-1; 
  int totMaxSum = 0; 
  for (int col = 0; col < maxSum[lastRow].size(); ++col) {
    if (maxSum[lastRow][col] > totMaxSum) 
      totMaxSum = maxSum[lastRow][col];
  }
  
  printf("Max sum: %d\n", totMaxSum); 
}

    

  

