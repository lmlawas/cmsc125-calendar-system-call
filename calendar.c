/*
    reference: https://www.codingunit.com/how-to-make-a-calendar-in-c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OF_MONTHS 12
#define TRUE 1
#define FALSE 0

int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[] = {
    " ",
    "\nJanuary",
    "\nFebruary",
    "\nMarch",
    "\nApril",
    "\nMay",
    "\nJune",
    "\nJuly",
    "\nAugust",
    "\nSeptember",
    "\nOctober",
    "\nNovember",
    "\nDecember"
};

int isValidMonth(char month[]){
/*******************************************************************************
    This function checks if the argument month is a valid month or not.
    It returns the numerical value of the month if true, else return 0.
*******************************************************************************/
    char *months1[] = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    char *months2[] = {
        "",
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sept",
        "Oct",
        "Nov",
        "Dec",
    };
    int i;

    for( i = 1; i <= NUMBER_OF_MONTHS; i++ ){
        if( atoi(month) != 0 ){
            if( atoi(month) == i ) return i;
        }
        else{
            if( strcmp(month, months1[i]) == 0 ) return i;
            if( strcmp(month, months2[i]) == 0 ) return i;
        }
    }
    return FALSE;
}// end of isValidMonth

int getDaycode(int year){
/*******************************************************************************
    This function computes the daycode to determine when the day will start
    in a given month/year.
*******************************************************************************/
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1)/ 4;
    d2 = (year - 1)/ 100.;
    d3 = (year - 1)/ 400.;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}// end of getDaycode

void isLeapYear(int year){
/*******************************************************************************
    This function checks if it is a leapyear or not.
*******************************************************************************/
    if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE){
        daysInMonth[2] = 29;        
    }    
    else{
        daysInMonth[2] = 28;
    }    
}// end of isLeapYear

void displayCalendar(int year, int month, int daycode){
/*******************************************************************************
    This function displays the calendar
*******************************************************************************/
    int m, day;

    if( month == 0 ){
        for ( m = 1; m <= 12; m++ ){
            
            printf("%s %d", months[m], year);
            printf("\nSu  Mo  Tu  We  Th  Fr  Sa\n" );            

            // Correct the position for the first date
            for ( day = 1; day <= 1 + daycode * 5; day++ ){
                printf(" ");
            }

            // Print all the dates for one month
            for ( day = 1; day <= daysInMonth[m]; day++ ){
                if(day > 9) printf("%d ", day );
                else printf(" %d ", day );

                // Is day before Sat? Else start next line Sun.
                if ( ( day + daycode ) % 7 > 0 ){                
                    printf(" ");
                }
                else{
                    printf("\n");
                }
            }
                
            // Set position for next month
            daycode = ( daycode + daysInMonth[m] ) % 7;
        }    
    }
    else{
        for ( m = 1; m <= 12; m++ ){
            
            if(m == month) printf("%s %d", months[m], year);
            if(m == month) printf("\nSu  Mo  Tu  We  Th  Fr  Sa\n" );            

            // Correct the position for the first date
            for ( day = 1; day <= 1 + daycode * 5; day++ ){
                if(m == month) printf(" ");
            }

            // Print all the dates for one month
            for ( day = 1; day <= daysInMonth[m]; day++ ){
                if(m == month){
                    if(day > 9) printf("%d ", day );
                    else printf(" %d ", day );
                }

                // Is day before Sat? Else start next line Sun.
                if ( ( day + daycode ) % 7 > 0 ){                
                     if(m == month)printf(" ");
                }
                else{
                    if(m == month) printf("\n");
                }
            }
                
            // Set position for next month
            daycode = ( daycode + daysInMonth[m] ) % 7;
            if(m == month) break;
        }
    }
    printf("\n");
}

int main( int argc, char *argv[] ){
/*******************************************************************************
    main function
*******************************************************************************/
    int month, year, daycode;
    int time_systimeyear = 2016, time_systimemonth = 5;
    
    if( argc == 1 ){        
        month = time_systimemonth;
        year = time_systimeyear;
        // printf("Compute the current month...\n");
        daycode = getDaycode(year);
        isLeapYear(year);
        displayCalendar(year, month, daycode);
        /*
            insert code for computing the current month
        */
    }
    else if( argc == 2 ){
        if( strcmp(argv[1], "-m") == 0 ){
            printf("cal missing argument for option -m.\n");
        }
        else if( strcmp(argv[1], "-y") == 0 ){
            month = 0;
            year = time_systimeyear;            
            // printf("Compute the current year...\n");
            daycode = getDaycode(year);
            isLeapYear(year);
            displayCalendar(year, month, daycode);
            /* 
                insert code for computing the current year
            */
        }
        else{
            printf("cal: Invalid argument '%s'\n", argv[1]);
        }
    }
    else if( argc == 3 ){
        if( strcmp(argv[1], "-m") == 0 ){            
            month = isValidMonth(argv[2]);
            if( month ){
                year = time_systimeyear;
                daycode = getDaycode(year);
                isLeapYear(year);
                displayCalendar(year, month, daycode);
                // printf("Compute the month of current year...\n");
                /* 
                    insert code for computing month of current year
                */
            }
            else{
                printf("cal: invalid argument '%s'\n", argv[2]);
            }
        }
        else if( strcmp(argv[1], "-y") == 0 ){
            year = atoi(argv[2]);
            if( year == 0 ) printf("cal: invalid argument '%s'\n", argv[2]);
            else if( year > 9999 || year < 1) printf("cal: year `%d' not in range 1..9999\n", year);            
            else if( year >= 1 && year <= 9999 ){
                month = 0;
                daycode = getDaycode(year);
                isLeapYear(year);
                displayCalendar(year, month, daycode);
                // printf("Compute the year...\n");
                /* 
                    insert code for computing the year
                */
            }
            else{
                printf("cal: invalid argument '%s'\n", argv[2]);
            }
        }
        else{
            printf("cal: invalid argument '%s'\n", argv[1]);
        }
    }
    else{
        printf("cal: invalid number of arguments\n");
    }
}// end of main
