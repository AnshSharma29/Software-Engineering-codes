/* Program to generate the previous date given a date, assumes data
given as dd mm yyyy separated by space and performs error checks on the
validity of the current date entered. */

#include <stdio.h>
#include <conio.h>

int main()
{
    int day, month, year, validDate = 0;
    /*Date Entry*/
    printf("Enter the day value: ");
    scanf("%d", &day);
    printf("Enter the month value: ");
    scanf("%d", &month);
    printf("Enter the year value: ");
    scanf("%d", &year);

    /*Check Date Validity */
    if (year >= 1900 && year <= 2025) {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            if (day >= 1 && day <= 31) {
                validDate = 1;
            }
            else {
                validDate = 0;
            }
        }
        else if (month == 2) {
            int rVal=0;
            if (year%4 == 0) {
                rVal=1;
                if ((year%100)==0 && (year % 400) !=0) {
                    rVal=0;
                }
            }
            if (rVal ==1 && (day >=1 && day <=29) ) {
                validDate = 1;
            }
            else if (day >=1 && day <= 28 ) {
                validDate = 1;
            }
            else {
                validDate = 0;
            }
        }
        else if ( (month >= 1 && month <= 12) && (day >= 1 && day <= 30)) {
            validDate = 1;
        }
        else {
            validDate = 0;
        }
    }

    /*Prev Date Calculation*/
    if (validDate) {
        if (day == 1) {
            if (month == 1) {
                year--;
                day=31;
                month=12;
            }
            else if (month == 3) {
                int rVal=0;
                if (year%4 == 0) {
                    rVal=1;
                    if ((year%100)==0 && (year % 400) !=0) {
                        rVal=0;
                    }
                }
                if (rVal ==1) {
                    day=29;
                    month--;
                }
                else {
                    day=28;
                    month--;
                }
            }
            else if (month == 2 || month == 4 || month == 6 || month == 9 ||
            month == 11) {
                day = 31;
                month--;
            }
            else {
                day=30;
                month--;
            }
        }
        else {
            day--;
        }
        printf("The next date is: %d-%d-%d",day,month,year);
    }
    else {
        printf("The entered date ( %d-%d-%d ) is invalid",day,month,year);
    }
    getche ();
    return 1;
}
