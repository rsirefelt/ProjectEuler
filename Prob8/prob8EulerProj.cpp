#include <iostream>
#include <fstream>
#include <string>

int main()
{
  //Reading a long digit to the string digit
  std::string line;
  std::string digit;
  std::ifstream myfile("prob8EulerProjDigit.txt");
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      digit = digit + line;
    }
    myfile.close();
  }
  else
  {
    std::cout << "The file couldn't be opened";
  }

  std::cout << digit << std::endl << std::endl << digit.length() << std::endl << std::endl;
  
  //From string to int array
  int digitInt[digit.length()];
  for (int j = 0; j < digit.length(); j++)
  {
    //Takes negative 48 to go from ASCII char to single digit
    digitInt[j] = digit[j] - 48;
    std::cout << digitInt[j];
  }
  
  std::cout << std::endl << std::endl;

  int maxProduct = 0;
  int product;
  for (int i = 0; i <= digit.length()-5; i++)
  {
    product = 1;
    for (int j = 0; j < 5; j++)
    {
      product *= digitInt[i+j];
    }

    if (product == 0)
    {
      i = i + 4;
    }
    else if (product > maxProduct)
    {
      maxProduct = product;
    }
    else{}
  }
  
  std::cout << maxProduct << std::endl;
 
  return 0;
}
      
 
