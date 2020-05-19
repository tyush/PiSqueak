const int buttonAPin = 2;
const int buttonBPin = 3;
const int buttonCPin = 4;

const int joy1XPin = A1;
const int joy1YPin = A0;

const int ledPin = 13;

int buttonAState = 0;
int buttonBState = 0;
int buttonCState = 0;

int remButtonAState = 0;
int remButtonBState = 0;
int remButtonCState = 0;

int joy1X = 500;
int joy1Y = 500;

int remJoy1X = 500;
int remJoy1Y = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  pinMode(buttonCPin, INPUT);
  pinMode(joy1XPin, INPUT);
  pinMode(joy1YPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  buttonCState = digitalRead(buttonCPin);
  joy1X = analogRead(joy1XPin);
  joy1Y = analogRead(joy1YPin);

  if(buttonAState != remButtonAState) {
    if(buttonAState == 1) {
      Serial.println("button A+");
    } else {
      Serial.println("button A-");
    }
    remButtonAState = buttonAState;
  }
  if(buttonBState != remButtonBState) {
    if(buttonBState == 1) {
      Serial.println("button B+");
    } else {
      Serial.println("button B-");
    }
    remButtonBState = buttonBState;
  }
  if(buttonCState != remButtonCState) {
    if(buttonCState == 1) {
      Serial.println("button C+");
    } else {
      Serial.println("button C-");
    }
    remButtonCState = buttonCState;
  }

  if(joy1X != remJoy1X) {
    Serial.print("joy1X: ");
    Serial.println(joy1X);
    remJoy1X = joy1X;  
  }
  if(joy1Y != remJoy1Y) {
    Serial.print("joy1Y: ");
    Serial.println(joy1Y);
    remJoy1Y = joy1Y;
  }
  
  if(buttonAState == 1 && buttonBState == 1 && buttonCState == 1) {
    Serial.println("shutoff");  
  }

//  Serial.print("buttons: ");
//  Serial.print(button1State);
//  Serial.print(" ");
//  Serial.print(button2State);
//  Serial.print(" ");
//  Serial.print(button3State);
//  Serial.println();
  
  delay(10);
}
