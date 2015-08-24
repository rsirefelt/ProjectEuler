#include <stdio.h>

int main()
{
  int nrOfNumbers = 1000;
  int wordLength[nrOfNumbers];
  int hundredWord = 7;
  int andWord = 3;
  
  wordLength[0] = 3; //one
  wordLength[1] = 3; //two
  wordLength[2] = 5; //three
  wordLength[3] = 4; //four
  wordLength[4] = 4; //five
  wordLength[5] = 3; //six
  wordLength[6] = 5; //seven
  wordLength[7] = 5; //eight
  wordLength[8] = 4; //nine
  
  wordLength[9] = 3; //ten
  wordLength[10] = 6; //eleven
  wordLength[11] = 6; //twelve
  wordLength[12] = 8; //thirteen
  wordLength[13] = 8; //fourteen
  wordLength[14] = 7; //fifteen
  wordLength[15] = 7; //sixteen
  wordLength[16] = 9; //seventeen
  wordLength[17] = 8; //eighteen
  wordLength[18] = 8; //nineteen
  
  wordLength[19] = 6; //twenty
  wordLength[29] = 6; //thirty
  wordLength[39] = 5; //forty
  wordLength[49] = 5; //fifty
  wordLength[59] = 5; //sixty
  wordLength[69] = 7; //seventy
  wordLength[79] = 6; //eighty
  wordLength[89] = 6; //ninety 
  
  wordLength[999] = 11; //one thousand
  
  int firstDigitInd, secondDigitInd, thirdDigitInd;
  int firstDigit, secondDigit, thirdDigit;
  int number;
  
  for (int i = 20; i < nrOfNumbers-1; ++i) {
    number = i+1; 
    
    firstDigitInd = i%10;
    if (firstDigitInd != 9) { //ten
      firstDigit = wordLength[firstDigitInd];
    } else {
      firstDigit = 0;
    }    
    
    if ( (number%100)/10 == 0) {
      secondDigit = 0; 
    } else if ((number%100)/10 == 1) {
      secondDigitInd = i%100;
      secondDigit = wordLength[secondDigitInd];
      firstDigit = 0;
    } else if (firstDigitInd != 9) {
      secondDigitInd = i%100 - (firstDigitInd+1);
      secondDigit = wordLength[secondDigitInd];
    } else {
      secondDigitInd = i%100; 
      secondDigit = wordLength[secondDigitInd];
    }
    
    
    if (i > 98) {
      thirdDigitInd = (i+1)/100 - 1;
      if (number%100 != 0) {
        thirdDigit = wordLength[thirdDigitInd] + hundredWord + andWord; 
      } else {
        thirdDigit = wordLength[thirdDigitInd] + hundredWord; 
      }
    } else {
      thirdDigit = 0;
    }
  
    wordLength[i] = firstDigit + secondDigit + thirdDigit;
    
  }
  
  int totalLength = 0;
  for (int i = 0; i < nrOfNumbers; ++i) {
    totalLength = totalLength + wordLength[i];
  }
  
  printf("Total length: %i\n", totalLength);
  
  return 0;
}
