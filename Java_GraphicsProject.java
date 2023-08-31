import java.awt.*;  //importing necessary classes
import java.util.*;



public class project3draft2{

static Scanner scnr = new Scanner(System.in);  //global variables and arrays
static int numberOfShapes;
static int numberOfTimes;
static String shapeType[] = new String[20];
static int[] shapeSize = new int[20];
static String[] shapeColor = new String[20];
static int[] shapeDirection = new int[20];
static int[] shapeSpeed = new int[20];
static int[] Xposition = new int[20];
static int[] Yposition= new int[20];
  
   
   public static void changePositions(){  //method that translates user input into defined movement by pixels in a specified direction
   int i;
   
      for (i = 0; i < numberOfShapes; i++){
        if(shapeDirection[i] == 0){
        Xposition[i] = Xposition[i] - shapeSpeed[i];
        }
           else if(shapeDirection[i] == 4){
           Xposition[i] = Xposition[i] + shapeSpeed[i];  
           }
              else if(shapeDirection[i] == 2){
              Yposition[i] = Yposition[i] + shapeSpeed[i];               
              }
                 else if(shapeDirection[i] == 6){
                 Yposition[i] = Yposition[i] - shapeSpeed[i];
                 }
                     else if(shapeDirection[i] == 7){
                     Yposition[i] = Yposition[i] + shapeSpeed[i];
                     Xposition[i] = Xposition[i] - shapeSpeed[i];
                     }
                        else if(shapeDirection[i] == 5){
                        Yposition[i] = Yposition[i] + shapeSpeed[i];
                        Xposition[i] = Xposition[i] + shapeSpeed[i];
                        }
                            else if(shapeDirection[i] == 1){
                            Yposition[i] = Yposition[i] - shapeSpeed[i];
                            Xposition[i] = Xposition[i] - shapeSpeed[i];
                            }
                               else if(shapeDirection[i] == 3){
                               Yposition[i] = Yposition[i] - shapeSpeed[i];
                               Xposition[i] = Xposition[i] + shapeSpeed[i];
                               }
                    
     
      }
 
   }

   public static void showShapesMoving(DrawingPanel p){  //method that calls drawing methods to emulate motion
   int i;
      for (i = 0; i < numberOfTimes; i++){
      showShapes(p, false);
      changePositions();
      showShapes(p, true);
      p.sleep(100);
      }
   }

   public static void showCircle(DrawingPanel p, int i, boolean isColor){  //method which draws circles
   Graphics g = p.getGraphics();
   g.fillOval(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      if (isColor == true){
      g.setColor(Color.BLACK);
      g.drawOval(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      }
       if (isColor != true){
      g.setColor(Color.WHITE);
      g.drawOval(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      }
   }

   public static void showSquare(DrawingPanel p, int i, boolean isColor){  //method which draws squares
   Graphics g = p.getGraphics();
   g.fillRect(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      if (isColor == true){
      g.setColor(Color.BLACK);
      g.drawRect(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      }
      if (isColor != true){
      g.setColor(Color.WHITE);
      g.drawRect(Xposition[i], Yposition[i], shapeSize[i],shapeSize[i]);
      }
   }
   
   public static void graphicsSetColor(DrawingPanel p, int i){  //method which translates the user's string color into a color for the panel
   Graphics g = p.getGraphics();
   if (shapeColor[i].equals("Red")){
   g.setColor(Color.RED);
   }
   else if (shapeColor[i].equals("Blue")){
   g.setColor(Color.BLUE);
   }
   else if (shapeColor[i].equals("Pink")){
   g.setColor(Color.PINK);
   }
   else if (shapeColor[i].equals("Yellow")){
   g.setColor(Color.YELLOW);
   }
   else if (shapeColor[i].equals("Green")){
   g.setColor(Color.GREEN);
   }
   else if (shapeColor[i].equals("Magenta")){
   g.setColor(Color.MAGENTA);
   }
   else if (shapeColor[i].equals("Cyan")){
   g.setColor(Color.CYAN);
   }
   else if (shapeColor[i].equals("Orange")){
   g.setColor(Color.ORANGE);
   }
   else if (shapeColor[i].equals("Dark_gray")){
   g.setColor(Color.DARK_GRAY);
   }
   else if (shapeColor[i].equals("Light_gray")){
   g.setColor(Color.LIGHT_GRAY);
   }
   else if (shapeColor[i].equals("Gray")){
   g.setColor(Color.GRAY);
   }
   else {
   g.setColor(Color.BLACK);
   }
   }
   
   public static void setNoColor(DrawingPanel p){  //method which draws shape the same color of background ie white
   Graphics g = p.getGraphics();
   g.setColor(Color.white);
   }

   public static void showShapes(DrawingPanel p, boolean isColor){  //method which calls methods to set color and draw shapes
   int i;
   
      for (i = 0; i < numberOfShapes; i++){
        if (isColor == true){
        graphicsSetColor(p,i);  
        }
        else{
        setNoColor(p);  
        }
        if (shapeType[i].equals("Square")){
        showSquare(p, i, isColor);  
        }
            else if (shapeType[i].equals("Circle")){
            showCircle(p,i,isColor);  
            }
      }
   }



  public static void initialPosition(DrawingPanel p){  //populates x pos and y pos arrays to begin at center of panel
   int i;
   
   
      for (i = 0; i < numberOfShapes; i++){
      Xposition[i] = (p.getWidth() / 2);
      Yposition[i] = (p.getHeight() / 2);
      }
   showShapes(p, true);
   p.sleep(100);
   }

   public static void getShapeInformation(){    //populates arrays using loop and user input
     for (int i = 0; i < numberOfShapes; i++){
       shapeType[i] = scnr.next();
       shapeSize[i] = scnr.nextInt();
       shapeColor[i] = scnr.next();
       shapeDirection[i] = scnr.nextInt();
       shapeSpeed[i] = scnr.nextInt();
     }     
     
   }
   
   public static void main(String[] args){
   System.out.println("UTSA - Spring 2022 - CS 1083 - Project 3 - written by JIM YANNEY");
   System.out.println("");
   System.out.print("Please input width, height of the panel, # of shapes, # of times to move followed by the shape, ");
   System.out.print("size, color, direction, and speed of every shape: "); //Displays request to user to input required information
     
  int panelWidth = scnr.nextInt();
  int panelHeight = scnr.nextInt();  //sets panel width and height in pixels
  numberOfShapes = scnr.nextInt();
  numberOfTimes = scnr.nextInt();   //gives value to global variables defining number of shapes and number of moves
  
  
  getShapeInformation();  //calls method to populate the global arrays
 
  DrawingPanel p = new DrawingPanel(panelWidth, panelHeight);  //initialises the drawingpanel with the width and height
    
  initialPosition(p); //calls method which initially sets shapes on the panel
  
  showShapesMoving(p); //calls methods which emulate motion on the panel
     
   }
  
}