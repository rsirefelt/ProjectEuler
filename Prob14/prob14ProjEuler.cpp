#include <iostream>
#include <stdio.h>

unsigned long CalcCollatzChain(unsigned long* chain, unsigned long number); 
unsigned long NewCollatzNumber(unsigned long number);

int main()
{
  int size = 1000000;
  unsigned long chain[size];
  chain[0] = 0;
  chain[1] = 1; // We know this
  
  for (int i = 2; i < size; ++i) {
    chain[i] = -1;
  }
  
  unsigned long maxChainLength = 0;
  unsigned long chainLength;
  int maxNumber;
  
  for (int i = 2; i < size; ++i) {
    chainLength = CalcCollatzChain(chain, i);
    chain[i] = chainLength;
    
    if (chainLength > maxChainLength) {
      maxChainLength = chainLength;
      maxNumber = i;
    }
  }
  
  printf("Max chain length: %lu \n", maxChainLength);
  printf("Max number: %i \n", maxNumber);
 
  return 0;
}

unsigned long CalcCollatzChain(unsigned long* chain, unsigned long number)
{
  unsigned long count = 1; // For the term itself
  int size = 1000000;
  number = NewCollatzNumber(number);
  
  while (number > 0)
  {
    if (number < size && chain[number] != -1) {
      count = count + chain[number];
      return count;
    } else {
      ++count;
    } 
    number = NewCollatzNumber(number);
  }

  return count;
}


unsigned long NewCollatzNumber(unsigned long number)
{
  if (number%2 == 0) {
    number = number/2;
  } else {
    number = 3*number + 1; 
  }
  return number;
}










