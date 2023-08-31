#include <stdio.h>
#include <stdbool.h>
//preprocessor directives

void printArray(int qArr[][30], int kArr[][30], int rows);
void editArray(int (*arr)[30], int rows, int stayLength);
void roomCost(int numberNights, int numberGuests);
void discountRoomCost(int numberNights, int numberGuests);
//function declarations for printing schedule, making reservations, calculating regular and discount room costs


int main() {
  int queenArr[2][30] = {0};
  int kingArr[2][30] = {0};
  int userInput = 0;
  int numberGuests = 0;
  int numberNights = 0;
  int olderGuests = 0;
  //declaration and initialization of variables including 2d arrays.  One 2d array for the 2 queen rooms for 30 days.
  //One 2d array for King room for 30 days.
  
   printf("Welcome to Hotel Piedra del Agua (The Water Stone Hotel).\nHow many total guests will be staying in the room?\n");
   do
   {
      printf("The minimum guest per room is 1 and the minimum is 4.\n");
      scanf ("%d", &numberGuests);
   } while (numberGuests <= 0 || numberGuests >= 5);
   
   printf("How many nights will you be staying?\n");
   do
   {
      printf("The minimum number of nights is 1 and the maximum is 30.\n");
      scanf("%d", &numberNights);
   } while (numberNights <= 0 || numberNights >= 30);
   
   
   printf("How many of your guests are over the age of 65 years?\n");
   do
   {
       printf("Enter 0 for none.\n");
       scanf("%d", &olderGuests);  
   } while (olderGuests < 0 || olderGuests > numberGuests);
   
   //Gets basic reservation information from user input.  Used to determine length of stay, room type, discount.  
   //Validates inputs with do-while loops.

  printf("Thank you for your information.\n\nPress 1 to view schedule. "); 
  printf("1's indicate the room is occupied.  0's indicate it is vacant.\nPress 2 to book a room. Press 3 to calculate reservation cost.  Press 4 to quit.\n");
  scanf("%d", &userInput);
  
do
{
  
  switch(userInput)
  {
      
      case(1):   //user selected to view schedule.  Will send the 2d arrays to printArray function
  
      printArray(queenArr, kingArr, 2);
      printf("Press 1 to view schedule. "); 
      printf("Press 2 to book a room. Press 3 to calculate reservation cost. Press 4 to quit.\n");
      scanf("%d", &userInput);
      break;
      
      case(2):  //user selected make reservation function
      
      if (numberGuests <= 2 && numberGuests > 0)  
      {
         printf("\nParties of 1 or 2 are assigned one of our Queen Rooms.\n");
         editArray(queenArr, 2, numberNights);  //sends Queen array, length, and number of nights to function 
      }
      else if (numberGuests >= 3 && numberGuests <= 4)  //determines room type based on number of guests in party
      {
          printf("\nParties of 1 or 2 are assigned one of our King Rooms.\n"); 
          editArray(kingArr, 2, numberNights);  //sends King array, length, and number of nights to function
         
      }
      printf("Press 1 to view schedule."); 
      printf("Press 2 to book a room. Press 3 to calculate reservation cost. Press 4 to quit. \n");
      scanf("%d", &userInput);
      break;
      
    
      
      case(3):
      
      if(olderGuests == 0)  //calls regular room cost calculation if no discount
      {
        roomCost(numberNights, numberGuests);  
      }
      else  //calls discount room calculation if there is a guest over 65
      {
        discountRoomCost(numberNights, numberGuests);
      }
      printf("Press 1 to view schedule."); 
      printf("Press 2 to book a room. Press 3 to calculate reservation cost. Press 4 to quit. \n");
      scanf("%d", &userInput);
      break;
      
      
      default:
      break;
    }  


}while (userInput != 4);
  
  printf("Thank you for using our reservation system.\n\n");
  return 0;
}

void printArray(int qArr[][30], int kArr[][30], int rows) {  //accepts a 2d array by value and prints using two for loops)
  printf("Day:\t     ");
  for (int i = 1; i < 31; i++){
      printf("%3d", i);
  }
  printf("\n");
  for(int i = 0; i < rows; i++) {
      printf("Queen Room %1d", i);
    for(int j = 0; j < 31; j++) {
      
      printf("%d  ", qArr[i][j]);
    }
    printf("\n");
    }  
    
    for(int i = 0; i < rows; i++) {
      printf("King Room  %1d", i);
         for(int j = 0; j < 31; j++) {
      
            printf("%d  ", kArr[i][j]);
         }
            printf("\n");
    }
  }


void editArray(int (*arr)[30], int rows, int stayLength) {  //accepts a 2d array by pointer, rows, and length of stay

   bool occupied1 = 0;
   bool occupied2 = 0;
   int userStartDate = 0;
   int userEndDate = 0;
   //variables for editing the array to make reservation
   
   printf("Enter your reservation start day.\n");  
   
   do
   {
   printf("Enter 0 for the first day of the month.  Enter 30 for the last day.\n");
   scanf("%d", &userStartDate);
   } while (userStartDate  < 0 || userStartDate > 30);
   userEndDate = userStartDate + stayLength;  //user enters start date and end date is calculated by length of stay
   
   
   for(int i = 0; i < 1; i++) {  //iterates through 2d array row 1 to check if room 1 of the type is occupied
         for(int j = userStartDate; j < userEndDate; j++) 
         {
            if (arr[i][j] == 1)
            {
                occupied1 = true;  //true if room 1 of the type is occupied on any date desired
            }
         }
   }
   
   for(int i = 1; i <= 1; i++) {  //iterates through 2d array row 2 to check if room 2 of the type is occupied
         for(int j = userStartDate; j < userEndDate; j++) 
         {
            if (arr[i][j] == 1)
            {
                occupied2 = true;  //true if room2 of the type is occupied
            }
         }
   }
   
    if(occupied1 == false )  //room 1 is available
      for(int i = 0; i < 1; i++) {
         for(int j = userStartDate; j < userEndDate; j++) 
         {
            arr[i][j] = 1;  //place 1's to make reservation
         }
         printf("Reservation successful.\n\n");
      }
    else if(occupied1 == true && occupied2 == false)  //room 1 is occupied and room 2 is empty
    {
        for(int i = 1; i <= 1; i++) {
         for(int j = userStartDate; j < userEndDate; j++) 
         {
            arr[i][j] = 1;  //place 1's to make reservation
         }
         printf("Reservation successful.\n\n");
      }
    }
    
    else  //room 1 and room 2 of the type are occupied on any of the desired days
    {
        printf("Unfortunately, those dates are not available.\nPlease check the schedule and try an alternate reservation start date.\n\n");
    }
  
}

void roomCost(int nights, int guests)  //calculates regular room cost based on room type and length of stay
{
       
            
    if (guests <= 2)
    {
        printf("Queen rooms are $100 a night.\nThe total cost of the reservation is: $%0.2lf USD.\n", (double) nights * 100);
    }
    else
    {
        printf("King rooms are $150 a night.\nThe total cost of the reservation is: $%0.2lf USD.\n", (double) nights * 150 );  
    }
}

void discountRoomCost(int nights, int guests) //calculates discounted room cost based on room type and length of stay
{
     
    if (guests <= 2)
    {
        printf("Queen rooms are normally $100 a night.\nHowever, your 10%% guest-over-65 discount makes the reservation total: $%0.2lf USD.\n", (nights * 100) * .9);
    }   
    else
    {
        printf("King rooms are normally $150 a night.\nHowever, your 10%% guest-over-65 discount makes the reservation total: $%0.2lf USD.\n", (nights * 150) * .9);
    }
}     