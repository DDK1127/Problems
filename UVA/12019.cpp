#include<iostream>
using namespace std;

int main(){
    int time, month, day, total, today;
    scanf("%d", &time);
    for(int i = 0; i < time; i++){
        total = 0;
        scanf("%d%d", &month ,&day);
        switch (month)
        {
        case 1: // January 31
            total += day;
            break;
        case 2: // Fevruary 28
            total = 31+day; 
            break;
        case 3: // March 31
            total = 59+day; 
            break;
        case 4: // April 30
            total = 90+day; 
            break;
        case 5: // May 31
            total = 120+day;
            break;
        case 6: // June 30
            total = 151+day;
            break;
        case 7: // July 31
            total = 181+day;
            break;
        case 8: // Auguest 31
            total = 212+day;
            break;
        case 9: // September 30
            total = 243+day;
            break;
        case 10: // October 31
            total = 273+day;
            break;
        case 11: // November 30
            total = 304+day;
            break;
        case 12: // December 31
            total = 334+day;
            break;
        default:
            printf("Error month number");
            break;
        }
        today = (total+5)%7;
        switch (today)
        {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        default:
            printf("Error calcluate number\n");
            break;
        }
    }
    return 0;
}