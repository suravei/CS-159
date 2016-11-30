
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. login1@purdue.edu
*	 2. login2@purdue.edu
*	 3. login3@purdue.edu (delete line if no third partner)
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section:
*
*  Program Description:
*
***************************************************************************/


#include <stdio.h>

#define MAX_CLASS 30

int getExiting(int []);
int getReturning(int []);

void checkAttendance(int [], int [], int, int);
int find(int [], int [], int, int, int []);

void printList(int [], int);
void insertionSort(int [], int);

int main()
{

  int exiting [MAX_CLASS] = {0};
  int returning [MAX_CLASS] = {0};

  int exitingLength = getExiting(exiting);
  int returningLength = getReturning(returning);

  checkAttendance(exiting, returning, exitingLength, returningLength);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.
*       2.
*       3.
*
*     Function Description:
*
***************************************************************************/

int getExiting(int array [])
{

  int i = -1; // Iterator
  printf("\nEnter set of exiting students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  return(i);
}

int getReturning(int array [])
{

  int i = -1; // Iterator
  printf("Enter set of returning students: ");
  
  do {
    i++;
    scanf("%d", &array[i]);
  } while(array[i] != -1 && (i + 1) < MAX_CLASS);

  return(i);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.
*       2.
*       3.
*
*     Function Description:
*
***************************************************************************/

void checkAttendance(int exiting [], int returning [], int exitLen, int returnLen)
{

  int valuesExit [MAX_CLASS + 1] = {};
  int valuesReturn [MAX_CLASS + 1] = {};
  int countExit = find(exiting, returning, exitLen, returnLen, valuesExit);
  int countReturn = find(returning, exiting, returnLen, exitLen, valuesReturn);

  if(countExit == 0 && countReturn == 0)
  {
    printf("\nAll exiting students returned.\n\n");
  }
  else
  {
    if(countExit != 0)
    {
      printf("\nStudents returning but not exiting:");
      printList(valuesExit, countExit);
      printf("\n\n");
    }

    if(countReturn != 0)
    {
      if(countExit == 0) 
      {
	printf("\n");
      }

      printf("Students exiting but not returning:");
      printList(valuesReturn, countReturn);
      printf("\n\n");
    }

    
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.
*       2.
*       3.
*
*     Function Description:
*
***************************************************************************/

int find(int exiting [], int returning [], int exitLen, int returnLen, int values [])
{

  int i;
  int j;
  int cnt = 0;
  
  for(i = 0; i < exitLen; i++)
  {
    for(j = 0; j < returnLen; j++)
    {
      if(exiting[i] == returning[j])
      {
	j = 99;
      }
    }

    if(j != 100)
    {
      values[cnt] = exiting[i];
      cnt++;
    }
  }

  values[cnt] = -1;
  return(cnt);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.
*       2.
*       3.
*
*     Function Description:
*
***************************************************************************/

void printList(int array [], int len)
{
  int i; // For-loop iterator
  insertionSort(array, len);

  for(i = 0; i < len; i++)
  {
    printf(" %d", array[i]);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.
*       2.
*       3.
*
*     Function Description:
*
***************************************************************************/

void insertionSort(int array [], int len) 
{

  int min; // Index of minimum value
  int temp; // Temp value used for value swap

  int i; // For-loop iterator
  int j; // For-loop iterator

  for(i = 0; i < len - 1; i++)
  {
    min = i;
    for(j = i; j < len; j++)
    {
      if(array[min] > array[j])
      {
	min = j;
      }	
    }

    temp = array[i];
    array[i] = array[min];
    array[min] = temp;
  }
}

