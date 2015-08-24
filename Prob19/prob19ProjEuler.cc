#include <stdio.h>

int main() 
{

  int totNrOfDays = 0; 
  int startYear = 1901;
  int endYear = 2001; 
  int daysAYear = 365; 
  int daysAWeek = 7;
  
  int jan = 31, mar = 31, may = 31, jul = 31, aug = 31, okt = 31, dec = 31;
  int feb = 28, apr = 30, jun = 30, sep = 30, nov = 30;
  
  for (int year = startYear; year < 2001; ++year) {
    if (year%4 == 0 || year%400 == 0) {
      totNrOfDays = totNrOfDays + daysAYear + 1; // leap year
    } else {
      totNrOfDays = totNrOfDays + daysAYear;
    }
  }
  
  int nrOfSundays = totNrOfDays/daysAWeek; 
  
  
  
  return 0;
  
 
  
  
  

}
