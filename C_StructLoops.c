/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

typedef struct{  //create struct with one int, one float, array of ints
   int x;
   float y;
   int myArray[5];
}DATA;

void editElement(DATA *mystruct, int structArrayIndex);  //function declaration

int main()
{
    DATA structs[10];   //create array of ten structs
    int structArrayIndex = 0;  //int variable to track index
    
    for (int k = 0; k < 10; k++)  //initializing elements of structs in the array 
    {
        structs[k].x = k + 1; 
        structs[k].y = k * 1.5;
    }
    
    for (int k = 0; k < 10;k++)  //loop to initiliaze array element
    {
        for (int i =0; i < 5;i++)
        {
            structs[k].myArray[i] = 4;
        }
    }
    
   do{  //get user input for what struct the user wishes to modify
   printf("What struct in the array do you want to change?\n");
   printf("The allowed indexes range from 0-9\n");
   printf("Enter the number of the struct in the array as an integer.\n");
   scanf("%d", &structArrayIndex);
   if (structArrayIndex >= 0 && structArrayIndex <= 9)
   {
       printf("You choose to edit structs[%d].\n\n", structArrayIndex);  
   }
   else
   {
       printf("Please enter a valid index.\n\n");
   }
   } while (structArrayIndex > 9 || structArrayIndex < 0);

   printf("BEFORE\n");  //before function call
   printf("structs[%d].x = %d\n", structArrayIndex, structs[structArrayIndex].x);
   printf("structs[%d].y = %lf\n",structArrayIndex,  structs[structArrayIndex].y);
   for (int i = 0; i < 5;i++)
   {
       printf("structs[%d].myArray[%d] = %d\n", structArrayIndex, i, structs[structArrayIndex].myArray[i]);
   }
   printf("\n\n");
    
    editElement(&structs[structArrayIndex], structArrayIndex);  //function call
    
    
   printf("AFTER\n");  //after function call
   printf("structs[%d].x = %d\n", structArrayIndex, structs[structArrayIndex].x);
   printf("structs[%d].y = %lf\n",structArrayIndex,  structs[structArrayIndex].y);
   for (int i = 0; i < 5;i++)
   {
       printf("structs[%d].myArray[%d] = %d\n", structArrayIndex, i, structs[structArrayIndex].myArray[i]);
   }
   printf("\n\n");

    return 0;

}

void editElement(DATA *mystruct, int structArrayIndex)  //function to accept specified element as pointer and modify values
{
   

   
   mystruct->x = 100;
   mystruct->y = 99.0;
   for (int i = 0; i < 5; i++)
   {
       mystruct->myArray[i] = i + i;
   }
   
   
   
}
    
    
    
    
    
    