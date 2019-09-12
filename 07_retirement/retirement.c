#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;
  
double calculate(double initial, retire_info information){
  double interest_earned = initial * information.rate_of_return;
  double current_balance = interest_earned + initial;
  current_balance = current_balance + information.contribution;
  return current_balance;
}



void retirement (int startAge, double initial, retire_info working, retire_info retired) 
{
  double current_balance = initial;
  double total_balance;

  for (int i = startAge; i <= startAge + working.months; i++) {
    int ageYear = i/12;
    int ageMonths = i%12;
    total_balance = initial;
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonths, current_balance);
    current_balance = calculate(initial, working);
    initial = current_balance;
  }

  for (int j = startAge + working.months + 1; j <= startAge + working.months + retired.months - 1; j++) {
    int ageYear = j/12;
    int ageMonths = j%12;
    current_balance = calculate(total_balance, retired);
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonths, current_balance);
    total_balance = current_balance;
  }
}

int main () {
  retire_info working;
  retire_info retired;
    
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
    
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
    
  int startAge = 327;
  double initial = 21345;
    
  retirement(startAge, initial, working, retired);
        
  return EXIT_SUCCESS;
}
