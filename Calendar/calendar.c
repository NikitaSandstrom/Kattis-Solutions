#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>




/*
    Filename: cal.c
    Purpose: Recreates the calendar function from default command line (with limitations)
             As well this is the first project from the MCS-284 class.
    Designer: Nikita Sandstrom
    E-mail: nsandst2@gustavus.edu
    Last Edit: Sept 30, 2020

*/





//Starting Variables
int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //Days in a month for each month (non leap-year)
char *monthsInYear[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"}; 
char userInp[];
int yearPicked; //Used for current Year 
int monthPicked; //Used for current Month or month chosen if by char
int startDay = 1; //when does the first of the month start on.


int main(int argc, char *argv[]) {
    if (argc == 1) { //Print Calendar of Current Month and Year
        currentDate();
        header(monthPicked);
        startofMonth(monthPicked, yearPicked);
        formatStart();
        printCalendar(monthPicked);
    } else if (argc == 2) {
        if (atoi(argv[1]) > 1753) { //Prints a 12 Month Calendar of the specified year
            for (int i = 1; i <= 12; i++) {
                header(i);
                startofMonth(i, atoi(argv[1]));
                formatStart();
                printCalendar(i);
                printf("\n");
            }
        } else {
            printf("Please choose a year above 1753 to work with the Gregorian Calendar\n");
        }
    } else if (argc == 3) {

        for (int i = 0; i < 3; i++) { //Checks the userInput to see if it is a valid month
            userInp[i] = toupper(argv[2][i]);
        }
        for (int i = 0; i < 12; i++) {
            if (strncmp(userInp, (monthsInYear[i]), 3) == 0) {
                monthPicked = i+1;
            }
        }

        if (strcmp((argv[1]), "-m") == 0 && atoi(argv[2]) > 0 && atoi(argv[2]) < 13) { //Prints out a calendar of the month chosen of the current year
            currentDate();
            header(atoi(argv[2]));
            startofMonth(atoi(argv[2]), yearPicked);
            formatStart();
            printCalendar(atoi(argv[2]));
        } else if (strcmp((argv[1]), "-m") == 0 && monthPicked > 0) { //The Version of Code except it uses the character format.
            header(monthPicked);
            startofMonth(monthPicked, yearPicked);
            formatStart();
            printCalendar(monthPicked);
        } else if (atoi(argv[1]) > 0 && atoi(argv[1]) < 13 && atoi(argv[2]) > 1753) { //Prints out a calendar of the chosen month and year
            header(atoi(argv[1]));
            startofMonth(atoi(argv[1]), atoi(argv[2]));
            formatStart();
            printCalendar(atoi(argv[1]));
        }
    } else if (argc == 4) {

        for (int i = 0; i < 3; i++) { //Checks the userInput to see if it is a valid month
            userInp[i] = toupper(argv[2][i]);
        }
        for (int i = 0; i < 12; i++) {
            if (strncmp(userInp, (monthsInYear[i]), 3) == 0) {
                monthPicked = i+1;
            }
        }

        if (strcmp((argv[1]), "-m") == 0 && atoi(argv[2]) > 0  && atoi(argv[2]) < 13 && atoi(argv[3]) > 1753) { //Prints out a calendar of the chosen month and year
            header(atoi(argv[2]));
            startofMonth(atoi(argv[2]), atoi(argv[3]));
            formatStart();
            printCalendar(atoi(argv[2]));
        } if (strcmp((argv[1]), "-m") == 0 && monthPicked > 0 && atoi(argv[3]) > 1753) { //Prints out a calendar of the chosen month and year
            header(monthPicked);
            startofMonth(monthPicked, atoi(argv[3]));
            formatStart();
            printCalendar(monthPicked);
        }
    } else { //Prints out an error message and gives a series of commands to have the program work.
        printf("Please enter less than 5 arguments for this to work\n");
        printf("Just the file itself will print the calendar of the current month and year.\n");
        printf("Filename and a number above 1753 will print a 12 month calendar of the current year.\n");
        printf("Filename -m (num btwn 1-12) will print out a calendar of the chosen month and current year. \n");
        printf("Filename (num btwn 1-12) (num above 1753) will print out the calendar of the chosen month and year.\n");
        printf("Filename -m (num btwn 1-12) (num above 1753) will print out the calendar of the chosen month and year.\n");
    }

    return 0;
} 



//////////////////////////
//Helper Functions Below//
//////////////////////////

int header(int month) { //Creates the top of the Calendar, formatting for the certain month
    if (month == 1) {
        printf("       January\n");
    } else if (month == 2) {
        printf("       Febrary\n");
    } else if (month == 3) {
        printf("       March\n");
    } else if (month == 4) {
        printf("       April\n");
    } else if (month == 5) {
        printf("       May\n");
    } else if (month == 6) {
        printf("       June\n");
    } else if (month == 7) {
        printf("       July\n");
    } else if (month == 8) {
        printf("       August\n");
    } else if (month == 9) {
        printf("       September\n");
    } else if (month == 10) {
        printf("       October\n");
    } else if (month == 11) {
        printf("       November\n");
    } else if (month == 12) {
        printf("       December\n");
    }

    printf("Su Mo Tu We Th Fr Sa\n"); //20 char total (Formatting)
    return 0;
}


//FUNCTIONS FOR GETTING VALUES FOR VARIABLES//

int isLeapYear(int year) { //Determines if the year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

int startofMonth(int month, int year) { //Determines when the start of the month happens (0 is Monday and 6 is Sunday)
    if (isLeapYear(year) == 1) {
        daysInMonth[1] = 29;
    }

    for(int i = 1753; i < year; i++) { //adds up all the days before the year selected
        if (isLeapYear(i) == 1) {
            startDay += 366;
        } else {
            startDay += 365;
        }
    }

    for (int i = 0; i < month-1; i++) { //adds up all the days of month-1
        startDay += daysInMonth[i];
    }

    startDay %= 7; //7 days a week, Mon = 0, Sun = 6
    return 0;
}

int currentDate() { //Gets the current month and year of the user
    time_t timeNow;
    struct tm *current;
    time(&timeNow);

    current = localtime(&timeNow);

    yearPicked = current->tm_year+1900;
    monthPicked = current->tm_mon+1;

    return 0;
}




//FUNCTIONS FOR FORMATTING THE MAIN CALENDAR//

int formatStart() { //Adds Whitespace for the first week depending on when the first day of the month is
    for (int i = 0; i < startDay; i++ ) {
        printf("   ");
    }
    return 0;
}

int printCalendar(int month) { //Prints out the days of the month of the calendar
    int counter = startDay; //Keeping a separate counter to create the line breaks
    for (int i = 1; i <= daysInMonth[month-1]; i++) {
        printf("%2d", i);
        printf(" ");
        counter++;
        if (counter % 7 == 0) { //Checking to see if the counter has reached Sunday to break a new line
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}










































