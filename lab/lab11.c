/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*       1. Atif Niyaz aniyaz@purdue.edu
*       2. Ittichot Suwanmungkool isuwanmu@purdue.edu
*       3. Canyu Yang yang1083@purdue.edu
*
*  Lab #: 11
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Wednesday, 11:30 A.M. - 1:20 P.M., SC 189
*
*  Program Description: This program decrypts a list of numbers based on a 
*                       key that is validated from standard input
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

#define NUM_INTS 20

void getKey(int*);
void getData(int[]);
void insecure(int[], int);
void decrypt(int, int);

int main()
{
  int data [NUM_INTS] = {}; // Dataset Array to Analyze (Initialize all Values)
  int key; // Key for the program
  
  getKey(&key);
  getData(data);
  insecure(data, key);

  return(0);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getKey
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwanmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int key; // Specific Key to get
*
*     Function Description: Takes in a <int*> and validates the input to
*                           determine the key.
*
***************************************************************************/

void getKey(int* key)
{
  do
  {
    printf("\nEnter key value: ");
    scanf("%d", key);

    if(*key < 0 || *key >= 10)
    {
      printf("\nError! Key must be a single digit!\n");
    }
  } while(*key < 0 || *key >= 10);
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getData
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwanmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int data []; // The data array to populate
*
*     Function Description: Takes in NUM_INTS integers into an array from
*                           standard IO.
*
***************************************************************************/

void getData(int data [])
{
  int i; // For-loop Iterator
  
  printf("Enter %d data values now: ", NUM_INTS);
  
  for(i = 0; i < NUM_INTS; i++)
  {
    scanf("%d", &data[i]);
  }
}

/***************************************************************************
*
*     Function Information
*
*     Name of Function: insecure
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwanmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int data []; // The data to analyze
*       2. int key; // The key to use to decrypt
*
*     Function Description: Takes in NUM_INTS ints and decrypts them.
*
***************************************************************************/

void insecure(int data [], int key)
{
  int i; // For-loop iterator

  printf("\n Original  Decrypted\n---------- ----------\n");

  for(i = 0; i < NUM_INTS; i++)
  {
    decrypt(data[i], key);
  }

  printf("\n");
} 

/***************************************************************************
*
*     Function Information
*
*     Name of Function: decrypt
*
*     Programmer's Name: Atif Niyaz, Ittichot Suwanmungkool, Canyu Yang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int number; // Number to decrypt
*       2. int key;    // Key to use to decrypt
*
*     Function Description: Decrypts an individual number based on a key 
*
***************************************************************************/

void decrypt(int number, int key)
{

  int powVal = 0; // Power determinator
  int encrypted = 0; // Encrypted number
  
  printf("%10d", number);

  while(number != 0)
  {
    encrypted += ((number % 10 - key + 10) % 10) * (int) (pow(10, powVal));
    powVal++;
    number /= 10;
  }
  
  printf("%*c%0*d\n", 12 - powVal, 0, powVal, encrypted);
}

