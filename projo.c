#include <stdio.h>
// leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Function to calculate the day of the week for the 1st day of a given month and year
int getStartDay(int year, int month) {
    int day = 1;
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Function to display the calendar for a given month and year
void displayCalendar(int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth = getDaysInMonth(month, year);
    int startDay = getStartDay(year, month);

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Su Mo Tu We Th Fr Sa\n");
