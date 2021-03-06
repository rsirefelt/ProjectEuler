#include <iostream>

bool isPrime(int num)
{
  bool flag = true;
  for (int i = 3; i < num/2; i = i + 2)
  {
    if (num % i == 0)
    {
      flag = false;
      break;
    }
  }
  return flag;
}

int main()
{
  unsigned long sumPrimes = 2;
  
  std::cout << "Sum Primes:" << std::endl;
  //std::cout << 2 << std::endl;
  
  for (int i = 3; i < 2000000; i = i + 2)
  { 
    if (isPrime(i))
    {
      //std::cout << i << std::endl;
      sumPrimes += i;
    }
  }

  std::cout << sumPrimes << std::endl;
  return 0;
}

  
