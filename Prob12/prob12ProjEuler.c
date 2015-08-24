#include "stdio.h"

int main()
{
  
  int nrOfDiv = 1;
  unsigned long triNum = 1; 
  unsigned long num = 1;
  
  while (nrOfDiv <= 500) 
  {
    nrOfDiv = 2; //1 and the number self is always a divisor
    num++;
    triNum = triNum + num; 
    
    int testDiv = 2; 
    
    while (testDiv*testDiv <= triNum)
    {
      if (triNum%testDiv == 0) 
      {
        nrOfDiv = nrOfDiv + 2; // divisors come in pairs
      }
      testDiv++;
    }
    
    printf("Nr of divisors: %i, for triNum: %lu\n", nrOfDiv, triNum);
  }
  
  printf("500 divisors for triNum: %lu \n", triNum);  
  
  return 0;

}
