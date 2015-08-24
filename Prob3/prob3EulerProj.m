%What is the largest prime factor of the number 600851475143 ?
t = cputime();

n = 600851475143;

listOfPrimes = primes(10000);

flag = true;
i = 0;
while flag;
    i = int32(i + 1);
    if mod(n,listOfPrimes(i)) == 0
        n = n/listOfPrimes(i);
    end
    if n == 1
        flag = false;
    end    
end

listOfPrimes(i)

timeElapsedInSeconds = cputime() - t