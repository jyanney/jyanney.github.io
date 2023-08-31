
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>  //preprocessors and definitions to set max element limits on arrays
#include <string.h>
#define MAX_FLIGHTS 5
#define MAX_LOCATIONS 6
#define MAX_PLANES 5
#define MAX_PILOTS 6


typedef struct {  //typedef of struct FLIGHT and struc within struc plane
    int flightNumber;
    char pilotName[20];
    char startLocation[4];
    char endLocation[4];
    struct plane {
        int planeNumber;
        int seats[4][30];    
    } plane;
} FLIGHT;



void printFlights(FLIGHT *flight, int x);  //function declarations
void printSeats(FLIGHT *flights, int rows, int col, int planes[]);
void bookSeat(FLIGHT *flights);
void cancelSeat(FLIGHT *flight);
void modifySeat(FLIGHT *flights);
void addRemoveRoute(FLIGHT *flights, char locations[][6], int planes[]);
void addRemovePlane(int *planes);
void addRemoveLocations(char locations[][6]);
void addRemovePilot(FLIGHT *flights, char pilots[][20]);
void searchPlane(FLIGHT *flights);

int main()
{
    int menuSelect = 0;  //variable and array declarations
    int customerSelect = 0;
    int managerSelect = 0;
    
    char locations[MAX_LOCATIONS][6] = {"\0"};  //declaring and intiliazing empty int and char arrays
    char pilots[MAX_PILOTS][20] = {"\0"};
    int planes[MAX_PLANES] = {0};
    
    
    
  

    
    FLIGHT flights[MAX_FLIGHTS];  //array of flight structs
    

    
     for (int i = 0; i < MAX_FLIGHTS; i++)  //loops to initialize all values to 0 
    {
        
        flights[i].flightNumber = 0;
        strcpy(flights[i].pilotName, "\0");
        strcpy(flights[i].startLocation, "\0");
        strcpy(flights[i].endLocation, "\0");
        flights[i].plane.planeNumber = planes[i];
        
    }
    
    for (int i = 0; i < MAX_FLIGHTS;i++)
    {
        for (int j = 0;j<4;j++)
        {
            for (int k = 0; k < 30; k++)
            {
                flights[i].plane.seats[j][k] = 0;
            }
        }
    }
    
      for (int i = 0; i < MAX_FLIGHTS; i++)
    {
        
        flights[i].flightNumber = i;
        
    }


    strcpy(locations[0], "ATX");   //hardcoding 2 locations, 1 pilot, 1 plane to make one flight for user to play with
    strcpy(locations[1], "SAT");   //can be removed through functions
    planes[0] = 111;
    strcpy(pilots[0], "CptJack");
    strcpy(flights[0].startLocation, locations[0]);
    strcpy(flights[0].endLocation, locations[1]);
    flights[0].plane.planeNumber = planes[0];
    


    
    
    
    
    printf("Welcome to NeverLand Air's Computerized Managment System.\n");  //main menu
    
    do
    {
       printf("Press 1 to access the customer menu.  Press 2 to access the manager menu. Press 3 to quit.\n");
       scanf("%d", &menuSelect);
    
    
    
    if (menuSelect == 1)  //customer menu
    {
        printf("\nWelcome Customer!\n");
         do 
         {
            printf("Press 1 to book a flight. Press 2 to cancel a flight reservation.");  
            printf(" Press 3 to modify a flight reservation.\n");
            printf("Press 4 to quit back to the main menu.\n");
            scanf("%d", &customerSelect);
            
            switch(customerSelect)  //customer functions switch
            {
            
               case(1):
               bookSeat(&(*flights));
               break;
               
            
               case(2):
               cancelSeat(&(*flights));
               break;
            
               case(3):
               modifySeat(&(*flights));
               break;
               
            
               case(4):
               printf("Back to Main Menu.\n");
               break;
            
               default:
               printf("Please enter a valid input\n");
               break;
            
                
            }
        
            } while (customerSelect != 4); 
    }
   
    else if (menuSelect == 2)  //mananger menu
    {
       printf("\nWelcome Boss!\n");
       do
       {
          printf("Press 1 to view airline flight information.  Press 2 to view flights occupancy.\n");
          printf("Press 3 to add/remove routes and assign/remove planes to flights. Press 4 to visit hanger to add/remove planes.\n");
          printf("Press 5 to add/remove locations.");
          printf(" Press 6 to manage the pilot roster.\nPress 7 to search for a plane.\nPress 8 to quit back to the main menu.\n");
          scanf("%d", &managerSelect);
          
          switch(managerSelect) //manager functions switch
          {
            case(1):
            printFlights(&(*flights), 5);
            break;
            
            case(2):
            printSeats(&(*flights), 4, 30, planes);
            break;
            
            case(3):
            addRemoveRoute(&(*flights), locations, planes);
            break;
            
            case(4):
            addRemovePlane(planes);
            break;
            
            case(5):
            addRemoveLocations(locations);
            break;
            
            case(6):
            addRemovePilot(&(*flights), pilots);
            break;
            
            case(7):
            searchPlane(flights);
            break;
            
            case(8):
            printf("Back to Main Menu\n");
            break;
            
            default:
            printf("Please enter a valid input\n");
            break;
           }
        
        } while (managerSelect != 8);
    }
    else if (menuSelect == 3)
    {
        printf("Goodbye.\n");
    }
    
    else
    {
        printf("Please enter a valid input.\n");
    }
    
    } while (menuSelect !=3);

    return 0;
}


void printFlights(FLIGHT *flights, int x)  //prints current flights
{
    
    printf("CURRENT FLIGHT INFORMATION:\n\n");
    
    for (int i = 0; i < x; i++)
    {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
    }
}


void printSeats(FLIGHT *flights, int rows, int col, int planes[])  //print seats in flights
{
      printf("SEATS:\n\n");
      printf("0 means seat is open. 1 means seat is filled.\n\n");
      
      

      
      for (int k = 0; k < MAX_FLIGHTS; k++){  

               for (int i = 0; i < 4; i++)  

               { 

               for (int j = 0; j < 30; j++)  

               {  

                   printf("%d ",flights[k].plane.seats[i][j]); 

               } 

                    printf("\n"); 

               } 
               printf("\n");

               }     
    
}

void bookSeat(FLIGHT *flights)  //books first available seat in a flight
{
    int flightSelect = 0;
    
    printf("CURRENT FLIGHT INFORMATION:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
    }
    
    do{
    printf("For the flight you want to book, enter its flight number as an integer.\n");
    scanf("%d", &flightSelect);
    }while (flightSelect < 0 || flightSelect > MAX_FLIGHTS);
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 30;j++)
        {
            if (flights[flightSelect].plane.seats[i][j] == 0)
            {
                flights[flightSelect].plane.seats[i][j] = 1;
                printf("Reservation successful.\n\n");
                return;
            }
            
        }
    }
    
}

void cancelSeat(FLIGHT *flights)  //cancels a reserved seat in a flight
{
    int flightSelect = 0;
    
    printf("CURRENT FLIGHT INFORMATION:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
    }
    
    do{
    printf("To cancel a seat reservation, enter the flight number as an integer.\n");
    scanf("%d", &flightSelect);
    }while (flightSelect < 0 || flightSelect > MAX_FLIGHTS);
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 30;j++)
        {
            if (flights[flightSelect].plane.seats[i][j] == 1)
            {
                flights[flightSelect].plane.seats[i][j] = 0;
                printf("Cancellation successful.\n\n");
                return;
            }
            
        }
    }
    
}

void modifySeat(FLIGHT *flights)  //allows user to cancel reservervation and make a new one in same function (modify)
{
    int currentFlight;
    int newFlight;
    
    printf("CURRENT FLIGHT INFORMATION:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
    }
    
    do{
    printf("Enter the flight number of your current seat reservation as an integer.\n");
    scanf("%d", &currentFlight);
    }while(currentFlight < 0 || currentFlight > MAX_FLIGHTS);
    
    do{
    printf("Enter the flight number of your desired flight as an integer.\n");
    scanf("%d", &newFlight);
    }while(newFlight < 0 || newFlight > MAX_FLIGHTS);
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 30;j++)
        {
            if (flights[currentFlight].plane.seats[i][j] == 1)
            {
                flights[currentFlight].plane.seats[i][j] = 0;
                printf("Your seat reservation on flight number %d is cancelled.\n", flights[currentFlight].flightNumber);
                break;
            }
            
        }
    }
    
     for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 30;j++)
        {
            if (flights[newFlight].plane.seats[i][j] == 0)
            {
                flights[newFlight].plane.seats[i][j] = 1;
                printf("Your seat reservation on flight number %d is confirmed.\n\n", flights[newFlight].flightNumber);
                return;
            }
            
        }
    }
}

void addRemoveRoute(FLIGHT *flights, char locations[][6], int planes[])  //allows manager to add/remove routes and pilots from flights structs
{
   int menuSelect = 0;
   int removeFlight = 0;
   int addRoute = 0;
   int planeSelect = 0;
   int flightSelect = 0;
   int planeMenuSelect = 0;
   int pilotMenuSelect = 0;
   char pilotAdd[20] = {"\0"};
   
   do{
   printf("Press 1 to remove route locations from a flight. Press 2 to add route locations to a flight.\nPress 3 to assign a plane to a route.\n\n");
   scanf("%d", &menuSelect);
   }while (menuSelect < 1 || menuSelect > 3);
   
   if (menuSelect == 1)
   {
       printf("CURRENT FLIGHT LIST:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
    }
    
    printf("Enter flight number to remove current route.\n");
    scanf("%d", &removeFlight);
    
    strcpy(flights[removeFlight].startLocation, "\0");
    strcpy(flights[removeFlight].endLocation, "\0");
    
    printf("Route locations removed from flight number %d.\n\n", flights[removeFlight].flightNumber);
    
    
   }
   
   else if (menuSelect == 2)
   {
       printf("CURRENT FLIGHT LIST:\n\n");
       for (int i = 0; i < 5; i++)
        {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Pilot's Name: %s\n", flights[i].pilotName);
        printf("Departure Location: %s\n", flights[i].startLocation);
        printf("Arrival Location: %s\n", flights[i].endLocation);
        printf("Plane Number: %d\n", flights[i].plane.planeNumber);
        printf("\n\n");
        }
        printf("CURRENT LOCATIONS:");
        for (int i = 0; i < MAX_LOCATIONS;i++)
        {
            printf("%s ", locations[i]);
        }
        printf("\n\n");
        
        do{
        printf("What flight number do you want to add a route for?\n");
        scanf("%d", &addRoute);
        }while(addRoute < 0 || addRoute > MAX_FLIGHTS);
        printf("Enter 3 Letter Airport Code for starting location.\n");
        scanf("%s", flights[addRoute].startLocation);
        printf("Enter 3 Letter Airport Code for ending location.\n");
        scanf("%s", flights[addRoute].endLocation);
        printf("Route locations added for flight number %d.\n\n", flights[addRoute].flightNumber);
   }
   else if (menuSelect == 3)
   {
       printf("Current Plane Hanger\n");
    
       for (int i = 0; i < MAX_PLANES;i++)
        {
        printf("Hanger Spot %d = %d\n", i, planes[i]);
        }
    
    do{
    printf("Press 1 to assign a plane to route.  Press 2 to remove a plane from a route.\n");
    scanf("%d", &planeMenuSelect);
    }while (planeMenuSelect < 1 || planeMenuSelect > 2);
    
    if (planeMenuSelect == 1)
    {
       
       do{
       printf("What flight do you wish to assign a plane to?\n");
       scanf("%d", &flightSelect);
       }while (flightSelect < 0 || flightSelect > MAX_FLIGHTS);
       
    
       printf("Which plane do you wish to assign to the route?  Enter the plane number.\n");
       scanf("%d", &planeSelect);
      
       
       flights[flightSelect].plane.planeNumber = planeSelect;
       printf("Plane %d is now assigned to flight number %d.\n\n", flights[flightSelect].plane.planeNumber, flights[flightSelect].flightNumber);
    }
    else if (planeMenuSelect == 2)
    {
        
        do{
        printf("Which flight do you wish to remove a plane from?\n");
        scanf("%d", &flightSelect);
        }while (flightSelect < 0 || flightSelect > MAX_FLIGHTS);
       
        flights[flightSelect].plane.planeNumber = 0;
        printf("Plane %d is now removed from flight number %d.\n\n", flights[flightSelect].plane.planeNumber, flights[flightSelect].flightNumber);
        
    }
   }
   
 
}

 

void addRemovePlane(int *planes)  //allows mananger to add/remove planes from the hanger array
{
    
    int menuSelect = 0;
    int removePlane = 0;
    int newPlaneNumber = 0;
    
    
    printf("NEVERLAND AIRLINES PLANE HANGER:\n");
    
    for (int i = 0; i < MAX_PLANES;i++)
    {
        printf("Hanger Spot %d = %d\n", i, planes[i]);
    }
    
    do{
    printf("Press 1 to remove a plane for a hanger spot.  Press 2 to add a plane to the hanger.\n");
    scanf("%d", &menuSelect);
    }while (menuSelect < 0 || menuSelect > 2 );
    
    if (menuSelect == 1)
    {
    
    do{
    printf("What hanger spot do you want to remove the plane from?\n");
    scanf("%d", &removePlane);
    }while (removePlane < 0 || removePlane > MAX_PLANES);
    
    planes[removePlane] = 0;
    printf("Plane has been removed from the hanger spot specified.\n\n");

    }
    
    else if (menuSelect == 2)
    {
    
    printf("Input a plane number for the plane as a 3 digit integer.\n");
    scanf("%d", &newPlaneNumber);
    
       for (int i = 0; i < MAX_PLANES; i++)
       {
           if( planes[i] == 0)
           {
               planes[i] = newPlaneNumber;
               printf("Plane number %d has been added to the hanger.\n\n", newPlaneNumber);
               break;
           }
           
       }
    
    }
  
    
  
    
}


void addRemoveLocations(char locations[][6]) //allows the manger to add/remove destinations/locations from the array
{
    char airportCode[4];
    char removeCode[4];
    int menuSelect = 0;
    
    
    printf("CURRENT LOCATIONS:\n");
        for (int i = 0; i < MAX_LOCATIONS;i++)
        {
            printf("%s ", locations[i]);
        }
    
    printf("\n\n");    
    do{
    printf("Press 1 to remove location. Press 2 to add a location.\n");
    scanf("%d", &menuSelect);
    }while (menuSelect < 1 || menuSelect > 2);
    
    if (menuSelect == 1)
    {
        printf("Enter airport code you wish to remove.\n");
        scanf("%s", removeCode);
        
        for (int i = 0; i < MAX_LOCATIONS; i++)
        {
            if (strcmp(removeCode, locations[i]) == 0)
            {
                strcpy(locations[i], "\0");
                printf("%s removed from locations.\n\n", locations[i]);
            }
            else
            {
                
            }
        }
    }
    else if (menuSelect == 2)
    {
    printf("Enter your new location as a three letter airport code.\n");
    scanf("%s", airportCode);
    for (int i = 0; i < MAX_LOCATIONS;i++)
    {
       if (strcmp(locations[i], "\0") == 0)
       {
       strcpy(locations[i], airportCode);
       printf("%s added to locations.\n\n", airportCode);
       break;
       }
    
    }
    }
    
    printf("CURRENT LOCATIONS:\n");
        for (int i = 0; i < MAX_LOCATIONS;i++)
        {
            printf("%s ", locations[i]);
        }
        
    printf("\n\n");
}


void addRemovePilot(FLIGHT *flights, char pilots[][20]) //allows manager to add/remove pilots from the roster array and flight structs
{
    int menuSelect = 0;
    int pilotMenuSelect = 0;
    int flightSelect = 0;
    char removeName[20] = {"\0"};
    char addName[20] = {"\0"};
    
    
    
    printf("CURRENT NEVERLAND AIRLINES PILOT ROSTER\n\n");
    for (int i = 0; i < MAX_PILOTS;i++)
    {
        printf("pilots[%d] = %s\n", i , pilots[i]);
    }
    
    do{
    printf("Press 1 to remove a pilot from roster. Press 2 to add a pilot to roster.\n");
    printf("Press 3 to assign/remove pilots from flights.\n");
    scanf("%d", &menuSelect);
    } while (menuSelect < 1 || menuSelect > 3);
    
    if (menuSelect == 1)
    {
        printf("Enter the pilot's name you wish to remove.\n");
        scanf("%s", removeName);
        
        for (int i = 0; i < MAX_PILOTS; i++)
        {
            if (strcmp(pilots[i], removeName) == 0)
            {
                strcpy(pilots[i], "\0");
                printf("%s removed from the roster.\n", removeName);
            }
            else
            {
                
            }
        }
    }
    else if (menuSelect == 2)
    {
    printf("Enter the name of your new pilot.  The name must not contain spaces and must be less than 20 characters in length.\n");
    scanf("%s", addName);
    for (int i = 0; i < MAX_PILOTS;i++)
    {
       if (strcmp(pilots[i], "\0") == 0)
       {
       strcpy(pilots[i], addName);
       printf("%s added to the roster.\n", addName);
       break;
       }
    
    }
    
    }
    
    else if(menuSelect == 3)
    {
        do{
        printf("Press 1 to assign a pilot to a flight.");
        printf("Press 2 to remove a pilot from a flight.\n");
        scanf("%d", &pilotMenuSelect);
        }while (pilotMenuSelect < 1 || pilotMenuSelect > 2);
        
        if (pilotMenuSelect == 1)
        {
            printf("Enter the pilot's name you wish to assign.\n");
            scanf("%s", addName);
            printf("Enter the flight number you wish to assign the pilot to.\n");
            scanf("%d", &flightSelect);
            
            strcpy(flights[flightSelect].pilotName, addName);
            printf("%s is now the pilot of flight number %d.\n\n", addName, flights[flightSelect].flightNumber);
            
        }
        
        else if (pilotMenuSelect == 2)
        {
            printf("Enter the flight number you wish to remove the current pilot from.\n");
            scanf("%d", &flightSelect);
            
            for (int i; i <MAX_FLIGHTS;i++)
            {
                if (i == flightSelect)
                {
                    strcpy(flights[flightSelect].pilotName, "\0");
                    printf("The pilot of flight number %d has been removed.\n", flights[flightSelect].flightNumber);
                }
            }
            
            
        }
        
    }
    
    
}


void searchPlane(FLIGHT *flights) //allows manager to search for what flights a plane is currently assigned to
{
    
  int count = 0;
  int key = 0;
  
  printf("To see what flights a plane is asigned to, enter the plane number.\n");
  
  scanf("%d", &key);

  
  for (int i  = 0; i < MAX_FLIGHTS; i++) {
    if (flights[i].plane.planeNumber == key) {
      printf("Plane found assigned to flight number %d\n", i);
      count++; 
    }
  }

  if (count == 0) 
    printf("Plane not found assigned to any flight.\n");
  else
    printf("Plane is assigned to %d flights.\n", count);
    
  
    
    
}