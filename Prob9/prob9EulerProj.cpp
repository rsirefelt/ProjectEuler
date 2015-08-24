#include <iostream>
#include <math.h>

int main()
{
  int a;
  int b;
  int c;
  int cSquare;

  std::cout << sqrt(100) << std::endl;
  
  for(int i = 1; i < 1000; i++)
  {
    for(int j = i; j < 1000; j++)
    {
      cSquare = pow(i,2) + pow(j,2);
      
      if(sqrt(cSquare) + i + j == 1000)
      {
	a = i;
	b = j;
	c = sqrt(cSquare);
	break;
      }
    }
  }
  
  int product = a * b * c;
  std::cout << "a = " << a  << " b = " << b << " c =  " << c << std::endl;
  std::cout << "a * b * c = " << product << std::endl;
  return 0;
}
