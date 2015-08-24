#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main()
{

  std::ifstream inputFile("numbers.txt");
  
  if (!inputFile.is_open())
  {
    std::cerr << "Error opening file." << std::endl;
    inputFile.close();
  }
  
  std::vector<std::string> numbers;
  
  std::string line; 
  while(getline(inputFile, line))
  {
    numbers.push_back(line);
  } 
  
  int sum;
  int rest = 0;
  std::vector<int> totalSum; 
  
  for (int pos = numbers[0].length()-1; pos >= 0; pos--)
  {
    sum = 0;
    for (int i = 0; i < numbers.size(); i++) 
    {
      sum = sum + (int)numbers[i].at(pos) - '0';
    }
    sum = sum + rest;
    rest = sum/10;
    
    if(pos != 0) 
    {
      totalSum.push_back(sum%10);
    }
    else
    {
      while(sum != 0)
      {
        totalSum.push_back(sum%10);
        sum = sum/10;
      }
    }
  }
  
  std::vector<int>::iterator iter;
  iter = totalSum.end();
  for (int i = 0; i < 10; i++)
  {
    iter--;
    std::cout << *iter; 
  }
  
  std::cout << std::endl;
  
  inputFile.close();

  return 0;
}
