import java.util.Scanner;

public class DogShelter{
public static Scanner gIn = new Scanner(System.in); //inputs a global scanner



   public static void changeDog(double[] dogsList){  //allows user to swap elements
   System.out.print("Enter the position from (0 to " + dogsList.length + ") : ");
   int fromDogIndex = gIn.nextInt();
      while (fromDogIndex > dogsList.length || fromDogIndex < 0){
      System.out.println("Value out of range, please try again");
      System.out.print("Enter the position from (0 to " + dogsList.length + ") : ");
      fromDogIndex = gIn.nextInt();
      }
   System.out.print("Enter the position to change to (0 to " + dogsList.length + ")"); 
   System.out.print("that is not " + fromDogIndex + " : ");
   int toDogIndex = gIn.nextInt();
      while(toDogIndex > dogsList.length || toDogIndex < 0 || toDogIndex == fromDogIndex){
      System.out.println("Value out of range, please try again");
      System.out.print("Enter the position to change to (0 to " + dogsList.length + ")"); 
      System.out.print("that is not " + fromDogIndex + " : ");
      toDogIndex= gIn.nextInt();
      }
   double temp;
   temp = dogsList[fromDogIndex];
   dogsList[fromDogIndex] = dogsList[toDogIndex];
   dogsList[toDogIndex] = temp;  //uses a temp variable to allow for swapping of elements
   
   
   }


   public static void modifyDog(double[] dogsList){ //allows user to modify an element
      
      System.out.print("Enter the index (0 to " + dogsList.length +")");
      int userIndex = gIn.nextInt();
         while(userIndex > dogsList.length || userIndex < 0){
         System.out.println("Value out of range, please try again");
         System.out.print("Enter the index (0 to " + dogsList.length +")");
         userIndex = gIn.nextInt();
         }
      System.out.println("The current weight of the dog at " + userIndex + " is : " + dogsList[userIndex]);
      System.out.println("Enter the weight of the new dog (0.00 - 100.00) : ");
      dogsList[userIndex] = gIn.nextDouble();
         while (dogsList[userIndex] > 100.0 || dogsList[userIndex] <= 0.0){
         System.out.println("Value out of range, please try again");
         System.out.print("Enter the weight of the new dog (0.00 - 100.00) : ");
         dogsList[userIndex] = gIn.nextDouble();
         }
      }  //uses loops to validate data and allows user to modify elements
   

   public static void listDog(double[] dogsList){  //iterates to show the elements in the array
   System.out.println("LIST OF DOGS' WEIGHT");
   
      for (int i = 0; i < dogsList.length; i++){
      
        System.out.println("Dog[" + i +  "] : " + dogsList[i]);
     
      }
  
   }
   
   public static void closeShelter(double[] dogsList){  //iterates through array and sets all values to 0.0
      for (int i = 0; i < dogsList.length; i++){
      dogsList[i] = 0;
      }
   }
   
   public static void reportDog(double[] dogsList){  //sorts dogs as members of weight categories
   System.out.println("DOGS' REPORT");
   int xL = 0;
   int L = 0;
   int M = 0;
   int S = 0;
   int xS = 0;   //declaring and intitializing variables and values
   
      for (int i = 0; i < dogsList.length; i++){  //running a loop to sort the array into categories
         if (dogsList[i] >= 90 && dogsList[i] <= 100){
         xL++;
         }
            if (dogsList[i] >= 50 && dogsList[i] < 90){
            L++;
            }
               if (dogsList[i] >= 30 & dogsList[i] < 50){
               M++;
               }
                  if (dogsList[i] >= 20 && dogsList[i] < 30){
                  S++;
                  }
                     if (dogsList[i] > 0 && dogsList[i] < 20){
                     xS++;
                     }
                        
      }
   
      
      System.out.println("xL : " + xL);
      System.out.println("L : " + L);
      System.out.println("M : " + M);
      System.out.println("S : " + S);
      System.out.println("xS : " + xS);  //printing the count of elements in each category
      
     
   }
  
  public static void main(String[] args){ //main method. drives other methods.
  System.out.print("UTSA - Spring 2022 - CS1083 - Section 001 -"); 
  System.out.println(" Project 2 - TexasShelter - written by Jim Yanney");  //printing into info
  System.out.println("");
  final int gMAX_DOGS = 100;
  int count = 0;
  

  System.out.print("Please, enter the number of dogs in the shelter (Max 100): ");
  int gShelterSize = gIn.nextInt();
     while(gShelterSize > gMAX_DOGS || gShelterSize <= 0){
     System.out.println("Value out of range, please try again");
     System.out.print("Please, enter the number of dogs in the shelter (Max 100): ");
     
     gShelterSize = gIn.nextInt();
     }
     double[] gWeight = new double[gShelterSize];  //gets input from user, validates it
                                                   //uses it to set length of array
     
     
  
 
    
      
  
  int menuChoice = 100;
  
     while(menuChoice != 0) {    //main menu that validates input and repeats until 0 is input
     System.out.println("MAIN MENU");
     System.out.print("0 - Exit, 1 - Report, 2 Assign/Modify dogs, 3 - (Ex)Change Dog");
     System.out.println(" 4 - Close shelter, 5 - List");
     System.out.print("Select an option : ");
     menuChoice = gIn.nextInt();
     
        if (menuChoice == 1){
        reportDog(gWeight);
        }
           if (menuChoice == 2){
           modifyDog(gWeight);
           }
              if (menuChoice == 3){
              changeDog(gWeight);
              }
                 if(menuChoice == 4){
                 closeShelter(gWeight);
                 }
                    if (menuChoice == 5){
                    listDog(gWeight);
                    }
     
                       if (menuChoice == 0){
                       System.out.println("Thank you for looking at the Dog Shelter info! Bye!");
                       }
                       
                          if (menuChoice < 0 || menuChoice > 5){
                          System.out.println("Value out of range, please, try again");
                          }
                       
                      
                       
                          
    
    
     }
  
  }
}