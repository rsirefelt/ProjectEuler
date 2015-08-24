#include <iostream>

int main()
{
  int numberOfPrimes = 1;
  int primes[10001];
  int number = 3;
  primes[0] = 2;
  
  while (numberOfPrimes <= 10001) {
    
    bool isPrime = true;
    for (int j = 1; j < numberOfPrimes; j++) {
      if (number % primes[j] == 0) {
	isPrime = false;
      }
    }
    
    if (isPrime) {
      primes[numberOfPrimes] = number;
      numberOfPrimes++;
    }
    number = number + 2;
  }

  std::cout << primes[10000] << std::endl;
  return 0;
}
