#include<stdio.h>
#include<stdlib.h>
int daygen(int day,int month,int year)                                                            //Function from the previous assignment//
{
	int tot;
	tot=(year-1)*365;                                                     
	int leap=(year-1)/4;                                                  
	tot+=leap;                                                                 
	if(month==1)
	tot+=day;
	else if(month==2)
	tot+=30+day;
	else if(month==3)
	tot+=58+day;
	else if(month==4)
	tot+=89+day;
	else if(month==5)
	tot+=119+day;
	else if(month==6)
	tot+=150+day;
	else if(month==7)
	tot+=180+day;
	else if(month==8)
	tot+=211+day;
	else if(month==9)
	tot+=242+day;
	else if(month==10)
	tot+=272+day;
	else if(month==11)
	tot+=303+day;
	else if(month==12)
	tot+=333+day;
	if((year%4)==0&&month>2)                                                 
	tot+=1;
	int dayname=tot%7;          
	return dayname;                                                             //daynames are integers where 0 is sunday 1 is monday... 6 is saturday//
}
int endDate(int month,int year)                                                 //Computing last day of the month//
{
	int end;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	end=31;
	else if(month==2&&(year%4)==0)
	end=29;
	else if(month==2&&(year%4)!=0)
	end=28;
	else
	end=30;
	return end;
}
void monthName(int month)                                                        //prints names from numbers//
{
	switch(month)
	{
		case 1: printf("\tJanuary");
		break;
		case 2: printf("\tFebraury");
		break;
		case 3: printf("\tMarch");
		break;
		case 4: printf("\tApril");
		break;
		case 5: printf("\tMay");
		break;
		case 6: printf("\tJune");
		break;
		case 7: printf("\tJuly");
		break;
		case 8: printf("\tAugust");
		break;
		case 9: printf("\tSeptember");
		break;
		case 10: printf("\tOctober");
		break;
		case 11: printf("\tNovember");
		break;
		case 12: printf("\tDecember");
		break;
		default: printf("\tPlease Enter a correct Month");
	}
}
void printMonth(int month,int year)                                                                 //Prints calendar of a month//
{
	int day=1,end=endDate(month,year);                                                             
	printf("\t%d\n",year);                                                                          //Although year is not printed in the assignment sample runs in the document i am doing it show that the move right and left are perfectly working//
	monthName(month);
	printf("\nSu Mo Tu We Th Fr Sa\n");
	int i=0;
	while(i<daygen(1,month,year))                                                                  //This loop prints the appropriate spaces in the first week//
	{
		printf("   ");
		i++;
	}                                                                                            
	while(i<7)                                                                                       //Printing dates in first week following spaces//
	{
		printf(" %d ",day);
		day++;
		i++;
	}
	int k=0;
    while(k<5)                                                                                       //Printing rest of the dates within 5 rows//
    {
    	printf("\n");
    	int j=0;
		while(j<7)
		{
			if(day<=end)
			{
				if((day/10)==0)
				printf(" %d ",day);
				else
				printf("%d ",day);
		    }
		    j++; 
		    day++;
		}
		k++;
   }
}
void printCalendarRow(int month,int year)                                                              //Prints a row in the year calendar, consists of 3 months//
{
	int day1=1,day2=1,day3=1;                                                                          //Logic is the same as in printMonth but for simultaneous printing 3 variables for each parameter each month are declared//
	int i=0;
	int end1=endDate(month,year);
	int end2=endDate((month+1),year);
	int end3=endDate((month+2),year);
	monthName(month);
	printf("\t\t");
	monthName((month+1));
	printf("\t");
	monthName((month+2));
	printf("\nSu Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa\n");
	while(i<=daygen(1,month,year))                                                          //The entire below code prints each row under 3 months and repeats until end of the months//
	{
		printf("   ");
		i++;
	}
	i--;
	printf("\b\b\b");                                                                      //Spacing adjustments//
	while(i<7)
	{
		printf(" %d ",day1);
		day1++;
		i++;
	}
	printf("\b");                                                                          //spacing adjustments//
	int a=0;
	while(a<=daygen(1,(month+1),year))
	{
	    printf("   ");
		a++;
	}
	a--;
	while(a<7)
	{
		printf(" %d ",day2);
		day2++;
		a++;
	}
	printf("\b");                                                                          //spacing adjustments//
	int c=0;
	while(c<=daygen(1,(month+2),year))
	{
	    printf("   ");
		c++;
	}
	c--;
	while(c<7)
	{
		printf(" %d ",day3);
		day3++;
		c++;
	}
	int k;
    while(k<5)
    {
    	printf("\n");
    	int j=0;
		while(j<7)
		{
			if(day1<=end1)
			{
				if((day1/10)==0)
				printf(" %d ",day1);
				else
				printf("%d ",day1);
		    }
		    else
		    printf("   ");
		    j++; 
		    day1++;
		}
		printf("  ");
		int l=0;
		while(l<7)
		{	
			if(day2<=end2)
			{
				if((day2/10)==0)
				printf(" %d ",day2);
				else
				printf("%d ",day2);
		    }
		    else
		    printf("   ");
		    l++;
		    day2++;
		}
		printf("  ");
		int m=0;
		while(m<7)
		{	
			if(day3<=end3)
			{
				if((day3/10)==0)
				printf(" %d ",day3);
				else
				printf("%d ",day3);
		    }
		    m++;
		    day3++;
		}
		k++;
   }
}
void printYear(int year)
{
	printf("\t\t\t\t%d\n",year);
	printCalendarRow(1,year);
	printf("\n");
	printCalendarRow(4,year);
	printf("\n");
	printCalendarRow(7,year);
	printf("\n");
	printCalendarRow(10,year);
}
void main()
{
	int year,month;
	int i=1;                                                                                                               //Intiating infinite loop//
	while(i>0)
	{
		printf("\nCalendar menu :\n1:Display year\n2:Display month\n3:Move right\n4:Move left\n5:Exit\n");
		int choice;
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the year\n");
	        scanf("%d",&year);
	        printYear(year);
	        int move,j;
	        while(j>=0)                                                                                                            //Another infinite loop for moving calendar//
	        {
	        	 printf("\nCalendar menu :\n1:Display year\n2:Display month\n3:Move right\n4:Move left\n5:Exit\n");
	             scanf("%d",&move);
	             if(move==3)
	             printYear((++year));
	             else if(move==4)
	             printYear((--year));
	             else if(move==5)
	             exit(0);
	             else
	             printf("Please select Exit and restart again to select another option");
	             j++;
	        }
		}
		if(choice==2)
		{
			printf("Enter the month\n");
        	scanf("%d",&month);	
			printf("Enter the year\n");
	        scanf("%d",&year);
	        printMonth(month,year);
	        int move,j;
	        while(j>=0)                                                                                                           //Another infinite loop for moving calendar//
	        {
	        	 printf("\nCalendar menu :\n1:Display year\n2:Display month\n3:Move right\n4:Move left\n5:Exit\n");
	             scanf("%d",&move);
	             if(move==3)
	             {
	             	if(month==12)
	             	{
	             	month=1;
	             	printMonth(month,(++year));
	                }
	             	else
	             	printMonth(++month,year);
				 }
	             else if(move==4)
	             {
	             	if(month==1)
	             	{
	             	month=12;
	             	printMonth(12,(--year));
	                }
	             	else
	             	printMonth(--month,year);
				 }
	             else if(move==5)
	             exit(0);
	             else
	             printf("Please select Exit and restart again to select another option");
	             j++;
	        }
		}
		else if(choice==5)
		exit(0);
		else
		printf("Please select a display");
	}
}
























