// C++ code
//fixed led==red/green/blue (led)
//variable led == Xred/Xgreen/Xblue  (Xled)
const int red=9;
const int green=10;
const int blue=11;

const int Xred=3;
const int Xgreen=5;
const int Xblue=6;

int redButton=2;
int greenButton=7;
int blueButton=8;
int resetButton=13;

int redMode=0;
int greenMode=0;
int blueMode=0;


//value of defined LED
int defRed=0;
int defGreen=0;
int defBlue=0;

int min=0;
int max=255;
int easyLvl=10;

void setup() 
{
  //general setup
  Serial.begin(9600);
  
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(Xred,OUTPUT);
  pinMode(Xgreen,OUTPUT);
  pinMode(Xblue,OUTPUT);
  //buttons are inputting data!
  pinMode(redButton,INPUT_PULLUP);
  pinMode(greenButton,INPUT_PULLUP);
  pinMode(blueButton,INPUT_PULLUP);
  pinMode(resetButton,INPUT_PULLUP);
  
  
  

}

/*creates a random color for the defined RGB
such that when the reset button is pressed, the color changes! */

void randomColor(){
 randomSeed(analogRead(A0));
 defRed= random(0,easyLvl+1);
 randomSeed(analogRead(A1));
 defGreen= random(0,easyLvl+1);  
 randomSeed(analogRead(A2));
 defBlue= random(0,easyLvl+1);  
 RGB_color(defRed, defGreen, defBlue);
}

//function that sets the defined RGB's color to the given parameters

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red, red_light_value);
  analogWrite(green, green_light_value);
  analogWrite(blue, blue_light_value);
  Serial.print("The RGB value is ");
  Serial.print("(");
  Serial.print(defRed); 
  Serial.print(", ");
  Serial.print(defGreen);
  Serial.print(", ");
  Serial.print(defBlue);
  Serial.print(")");
  
 
}

//what actually happens

void loop()
{ 
  
  if(digitalRead(resetButton)==LOW){
  randomColor();
  }
  
  if(digitalRead(redButton)==LOW)
  {
    redMode=redMode+1;
    Serial.println(redMode);
    delay(5);
    
  }
  
  if(digitalRead(greenButton)==LOW)
  {
    greenMode=greenMode+1;
    Serial.println(greenMode);
    delay(5);
    
  }
  
   if(digitalRead(blueButton)==LOW)
  {
    blueMode=blueMode+1;
    Serial.println(blueMode);
    delay(5);
    
  }
  //add value to color 
  
  if(redMode<easyLvl){
    int redValue=redMode*(max/easyLvl);
    analogWrite(Xred,redValue);
    //Serial.println("Red Value is");
    //Serial.println(redValue);
    delay(500);
    
  }
  
  
   if(greenMode<easyLvl){
    int greenValue=greenMode*(max/easyLvl);
    analogWrite(Xgreen,greenValue);
    //Serial.println("Green Value is");
    //Serial.println(greenValue);
    delay(500);
    
  }
  if(blueMode<easyLvl){
    int blueValue=blueMode*(max/easyLvl);
    analogWrite(Xblue,blueValue);
    delay(500);
    
  }
  
                                          
   
}
