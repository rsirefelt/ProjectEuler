// Using sieve algorithm
#include <iostream>

int main()
{
	int limit = 2000000;
	unsigned long sumPrime = 0;
	short numbers[limit-1];
	int prime;
	int ind;
	
  for(int i = 0; i < limit-1; i++)
  {
  	numbers[i] = 1;
  }
	
	for (int i = 0; i < limit-1; i++)
	{
		if(numbers[i])
		{
			prime = i+2;
			sumPrime += prime;
			
			ind = i+prime;
			while (ind < limit-1)
			{
				numbers[ind] = false;
				ind = ind + prime;
			}
		}
	}
	
	std::cout << "Sum Primes: " << sumPrime << std::endl;
	return 0;
}
