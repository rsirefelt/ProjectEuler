#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> number;
  std::vector<int> doubleNumber;
  int rest, sum;
  long unsigned bigSum = 0;
  
  number.push_back(1); // 2^0;
  
  printf("%lu\n", number.size());
  
  for (int i = 1; i < 1001; ++i) {
    rest = 0;
    sum = 0; 
    for (int j = 0; j < number.size()-1; ++j) {
      sum = number[j] + number[j] + rest;
      rest = sum/10;
      doubleNumber.push_back(sum%10);
    }
    
    sum = number[number.size()-1] + number[number.size()-1] + rest;
    
    while(sum != 0) {
      doubleNumber.push_back(sum%10);
      sum = sum/10;
    }
    
    number.swap(doubleNumber);
    doubleNumber.clear();
  }
  
  for (int i = 0; i < number.size(); ++i) {
    bigSum = bigSum + number[i];
  }
  
  printf("Answer: %lu \n", bigSum);
  
  return 0;
}
