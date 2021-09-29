// C++ code
//fixed led==red/green/blue (led)
//variable led == Xred/Xgreen/Xblue  (Xled)
const int red=9;
const int green=10;
const int blue=11;

const int Xred=3;
const int Xgreen=5;
const int Xblue=4;

int redButton=2;
int greenButton=7;
int blueButton=12;

int redMode=0;
int greenMode=0;
int blueMode=0;

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
  
  pinMode(redButton,INPUT_PULLUP);
  pinMode(greenButton,INPUT_PULLUP);
  pinMode(blueButton,INPUT_PULLUP);
  
  
  

}

void loop()
{
  
  for(int x=0;x<1;x++){
  	randomSeed(analogRead(A0));
  	int defRed= random(0,easyLvl+1);
  	analogWrite(red, defRed*255/easyLvl);
  	Serial.print("red = ");
  	Serial.println(defRed);
 
  } 
  if(digitalRead(redButton)==LOW)
  {
    Serial.print("The Red button is been pressed the following times:");
    Serial.print(" ");
    redMode=redMode+1;
    Serial.println(redMode);
    delay(5);
    
  }
  
  if(digitalRead(greenButton)==LOW){
  	greenMode=greenMode+1;
  }
  if(digitalRead(blueButton)==LOW){
  	blueMode=blueMode+1;
  }
  if(redMode<easyLvl){
    int redValue=redMode*(max/easyLvl);
    analogWrite(Xred,redValue);
    Serial.println("Red Value is");
    Serial.println(redValue);
    delay(1000);
    
  }
  
 /* if(redMode==defRed){
    for(int i=0;i<=5;i++){
       analogWrite(Xred,min);
       delay(500);
       analogWrite(Xred,max);
       delay(500);
    
    }  
    analogWrite(Xred, defRed*255/easyLvl)
  }
 */
   
}