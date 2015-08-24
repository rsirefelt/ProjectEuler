%Generating fibbonacci

x = [1, 2];

c = 0;
summation = 2;
while c <= 4e6
    c = sum(x);
    x = [x(2), c];
    if mod(c,2) == 0 && c <= 4e6
        summation = summation + c;
    end
end

summation

