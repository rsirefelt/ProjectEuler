function [ isPalindrom ] = isPalindrom( number )
%Returns true or false depending if "number" is a palindromic number
%or not.
%Ex palindromic number: 9009, 1111, 1001, 1221

numberAsString = num2str(number);
numberAsString2 = numberAsString; 

for i = 1:length(numberAsString)
    numberAsString2(i) = numberAsString(end-(i-1));
end

isPalindrom = strcmp(numberAsString,numberAsString2);

end

