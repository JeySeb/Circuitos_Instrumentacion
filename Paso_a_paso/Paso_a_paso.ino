
// Puertos y Variables para Motor paso a paso
#define StepPin 4
#define ms1 5
#define ms2 6
#define ms3 7
//#define DirPin 3 // Este pin se pondra en GND ahora
unsigned int t = 1000; // Rango: 980 - 9800 que corresponde a 150 - 15 RPMs aprox.

// Puertos y Variables para Encoder
#define Encoder_pin 2      // The pin the encoder is connected 
#define PulsosRotacion 20  // Value of pluses per rotation

int Encoder = 0;           // Value of the Output of the encoder 
int Estado = 1;            // Current state of the encoder to recognize the pulse changes
int Pulsos = 0;            // Counter of pulses
unsigned long InitialTime = 0;
unsigned long FinalTime; 
float RPMs;


void setup() {

Serial.begin(9600);

  pinMode( ms1 , OUTPUT);
  pinMode( ms2 , OUTPUT);
  pinMode( ms3 , OUTPUT);
//  pinMode( DirPin , OUTPUT);
  pinMode( StepPin , OUTPUT);
  pinMode( Encoder_pin , INPUT);

  ////// Motor paso a paso //////
  
  FullPaso();
  //MedioPaso();
  //QuarterPaso();
  //EighthPaso();
  //SixteenthPaso();
}
void loop() {
  
 
  ////// Motor paso a paso //////
  
  digitalWrite(StepPin, HIGH); 
  delayMicroseconds(t);           
  digitalWrite(StepPin, LOW);  
  delayMicroseconds(t);

  /*
   
  
  ////// Encoder //////
  Encoder = digitalRead(Encoder_pin);  

  if(Encoder == LOW && Estado == 1)
  {
     Estado = 0;             
  }

  if(Encoder == HIGH && Estado == 0)
  {
     Pulsos++; 
     Estado = 1;     
  }
  Serial.print("Encoder = ");
    Serial.println(Encoder); 
  if(Pulsos == PulsosRotacion)
  {
    FinalTime = millis();
    RPMs = 60000/(FinalTime - InitialTime);
    Pulsos = 0; 
    InitialTime = FinalTime;
    Serial.print("RPM = ");
    Serial.println(RPMs); 
  
}
*/
}
//Función para Controlar el Motor Paso a Paso: Permite controlar el motor y los pasos de este
void FullPaso(void)
{
  
  Serial.println("Motor Control");

  digitalWrite(ms1, LOW);
  digitalWrite(ms2, LOW);
  digitalWrite(ms3, LOW);
//  digitalWrite(DirPin, LOW);
}

void MedioPaso(void)
{
  
  Serial.println("Motor Control");

  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, LOW);
  digitalWrite(ms3, LOW);
//  digitalWrite(DirPin, LOW);
}
void QuarterPaso(void)
{
  
  Serial.println("Motor Control");

  digitalWrite(ms1, LOW);
  digitalWrite(ms2, HIGH);
  digitalWrite(ms3, LOW);
//  digitalWrite(DirPin, LOW);
}
void EighthPaso(void)
{
  
  Serial.println("Motor Control");

  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, HIGH);
  digitalWrite(ms3, LOW);
//  digitalWrite(DirPin, LOW);
}
void SixteenthPaso(void)
{
  
  Serial.println("Motor Control");

  digitalWrite(ms1, HIGH);
  digitalWrite(ms2, HIGH);
  digitalWrite(ms3, HIGH);
//  digitalWrite(DirPin, LOW);
}
