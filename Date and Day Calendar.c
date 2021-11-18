//day from the given date
#include <stdio.h>
int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Function for determining the day of a given date.

int determine_day(int date,int month,int year){
//calculating odd days FOR YEARS.
int rem,left,oddDays1,left2,rem2,oddDays2,oddDaysY;
// Minus 1 because calculating for previous years

//There are 0 odd days in every 400 years so obtaining the remaining years.
rem = (year - 1) % 400;
left = (rem / 100) * 100; // stores the century years not divisible by 400

//oddDays1 stores the no. of odd days for century years<400.
switch (left)
{
case 0:
oddDays1 = 0; break;
case 100:
oddDays1 = 5; break;
case 200:
oddDays1 = 3; break;
case 300:
oddDays1 = 1; break;
}

//oddDays2 stores no. of odd days for years<100.

left2 = rem-left;		//left2 stores no. of years <100. rem2= left2/4;	//rem2 stores no. of leap years.
 


left2 = left2-rem2 ;	//left2 now stores the no. of non leap years.

oddDays2= left2+(rem2*2); //leap year has 2 odd days,normal has one odd day (adding both).

if (oddDays2 > 6)
{
oddDays2 %= 7;
}

//Total odd Days in the previous years are stored in oddDaysY.
oddDaysY = oddDays1 + oddDays2; if (oddDaysY > 6)
{
oddDaysY %= 7;
}


//Calculating odd days FOR MONTHS of the current year.
int oddDays3=0,oddDays4,oddDaysM;

// oddDays3 stores no. of odd days for months before given month
for(int i=1; i< month; i++){ oddDays3=oddDays3+(days_in_month[i]%7);
}

oddDays4= date; //oddDays4stores no. of odd days of the given month.

oddDaysM= oddDays3+oddDays4; //Total odd days of current year are stored in oddDaysM.

if (oddDaysM > 6)
{
oddDaysM %= 7;
}

//Calculation of total odd days altogether
int oddDaysT=oddDaysY+oddDaysM; //for both of months and years if (oddDaysT > 6)
{
oddDaysT %= 7;
}
 



return oddDaysT;
}


//FOR PRINTING CALENDAR

void calender(int year){
{
int weekDay=1,startingDay;


char *months[]= {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

startingDay=determine_day(1,1,year); //To set the position of the starting day of the month.

for(int month=1;month<=12;month++){

printf("\n\n---------------%s	\n",months[month]);
printf("\nMon\tTue\tWed\tThurs\tFri\tSat\tSun\n");

for(weekDay=1;weekDay<startingDay;weekDay++) printf(" \t");

for(int date=1;date<=days_in_month[month];date++){ printf("%d \t",date);

if(++weekDay>7){ printf("\n"); weekDay=1;
}
startingDay=weekDay;
}

}
}}

int main ()
{
 


int date, month, year, choice; char proceed;

S:
printf ("\nEnter the date,month and year::"); scanf ("%d", &date);
scanf ("%d", &month);
scanf ("%d", &year);
printf ("\n Given date is::%d // %d // %d", date, month, year);

//determine leap year or not
if (year % 4 ==0 && year % 100 != 0 || year % 400 ==0)
{
days_in_month[2] = 29;

}
else{
days_in_month[2] = 28;

}

printf("\nEnter your choice::");
printf("\nFor Checking day of the entered date press 1::"); printf("\nFor printing calendar of the entered year press 2::\n"); scanf("%d",&choice);


if (choice==1) //for determining day of given date
{
int m = determine_day(date,month,year); switch(m)
{
case 0: printf("The day is Sunday"); break;
case 1: printf("The day is Monday"); break;
case 2: printf("The day is Tuesday"); break;
case 3: printf("The day is Wednesday"); break;
 


case 4: printf("The day is Thursday"); break;
case 5: printf("The day is Friday"); break;
case 6: printf("The day is Saturday");

}
}
else if(choice==2){ //for printing calendar
calender(year);
}
else{
printf("\nenter valid choice!!");
}
printf("\nDo you want to continue? (y/n)::");

scanf("%s",&proceed); if(proceed=='y'||proceed == 'Y'){
goto S;
}
else if(proceed=='n'|| proceed == 'N'){ printf("Thankyou for using this program, Bye!");
}

return 0;
}
