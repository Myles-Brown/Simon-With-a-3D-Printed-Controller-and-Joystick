// ---------------- PIN DECLARATIONS ----------------

// lights
int red = 2;
int green = 5;
int blue = 4;
int yellow = 3;

// misc
int speaker = 7;
int button = 6;

// joystick
int xVal = A0;
int yVal = A1;
int zVal = A2;

// ---------------- GAME VARIABLES ----------------


bool lose = false;
bool checkFlag = false;
bool gameOn = false;

int ledState = LOW;
unsigned long previousMillis = 0;

int pattern[32];
int solution[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int guessPosition = 1;
int solutionPosition = 0;

bool pressTrue = false;
bool redTrue = false;
bool greenTrue = false;
bool yellowTrue = false;
bool blueTrue = false;

bool Patternflag = true;
int guess = 0;


// ---------------- SETUP ----------------

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);

  pinMode(speaker, OUTPUT);
  pinMode(button, INPUT);
  pinMode(zVal, INPUT);

    randomSeed(analogRead(A3));

  for (int i = 0; i <= 32; i++){
    pattern[i] = random(1,6);
    if (i > 1 && pattern[i] == pattern[i-1] && pattern[i] == pattern[i-2])
    i--;
  }
  lose = false;
  gameOn = false;
}

// ---------------- HELPER FUNCTIONS ----------------

void lightsOff() {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
}

void playTone(int freq, int duration){
  tone(speaker, freq);
  delay(duration);
}

void playPattern(int pattern[], int guessPosition){
  delay(350);
  for (int i = 0; i < guessPosition; i++){
    lightsOff();
    noTone(speaker);
    delay(150);
    if (pattern[i] == 1){
      digitalWrite(red, HIGH);
      playTone(165, 100);
    }
    else if (pattern[i] == 2){
    digitalWrite(blue, HIGH);
    playTone(880, 100);
    }
    else if (pattern[i] == 3){
    digitalWrite(green, HIGH);
    playTone(659, 100);
    }
    else if (pattern[i] == 4){
    digitalWrite(yellow, HIGH);
    playTone(554.18, 100);
    }
    else if (pattern[i] == 5){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    playTone(988, 100);
    }
  }
}

 void startJingle() {
  digitalWrite(green, HIGH);
  playTone(659, 120);
  digitalWrite(green, LOW); 
  delay(40);
  digitalWrite(red, HIGH);
  playTone(784, 120); 
  digitalWrite(red, LOW); 
  delay(40);
  digitalWrite(yellow, HIGH);
  playTone(659, 120);
  digitalWrite(yellow, LOW);
  delay(40);
  digitalWrite(blue, HIGH);
  playTone(988, 220);
  delay(80);
  digitalWrite(blue, LOW);
}

// ---------------- LOOP ----------------
void loop() {
  if (gameOn == false){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 750) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      playTone(2225,0);
    } else {
      ledState = LOW;
      noTone(speaker);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(red, ledState);
    digitalWrite(blue, ledState);
    digitalWrite(green, ledState);
    digitalWrite(yellow, ledState);
  }
  int start = digitalRead(button);
  if (start == 1){
  gameOn = true;
  lightsOff();
  noTone(speaker);
  delay(250);
  startJingle();
  }
}
else if (lose == false && gameOn == true){
  if (Patternflag == true){
  playPattern(pattern, guessPosition);
  Patternflag = false;
  delay(75);
  }
  int xPos = analogRead(xVal);
  int yPos = analogRead(yVal);
  int press = digitalRead(zVal);

  //figure out user input
  if (press == 0){
     redTrue = false;
     greenTrue = false;
     yellowTrue = false;
     blueTrue = false;
   if (pressTrue == false){
    lightsOff();
    noTone(speaker);
    checkFlag = true;
  }
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    playTone(988, 5);
    pressTrue = true;
    
  }
  else if (yPos > 650 && xPos < 580 && xPos > 120){
    
     pressTrue = false;
     redTrue = false;
     greenTrue = false;
     yellowTrue = false;
   
   if (blueTrue == false){
    lightsOff();
    noTone(speaker);
   }
    digitalWrite(blue, HIGH);
    playTone(880, 5);
    blueTrue = true;
    delay(50);
    if (yPos > 650 && xPos < 580 && xPos > 120){
       checkFlag = true;
    }
  }
  else if (yPos < 50 && xPos < 580 && xPos > 120){
    
     pressTrue = false;
     blueTrue = false;
     greenTrue = false;
     yellowTrue = false;
    if (redTrue == false){
    lightsOff();
    noTone(speaker);
    checkFlag = true;
    }
    digitalWrite(red, HIGH);
    playTone(165, 5);
    redTrue = true;
    delay(50);
    if (yPos < 50 && xPos < 580 && xPos > 120){
      checkFlag = true;
    }
  }
  else if (xPos > 650 && yPos < 580 && yPos > 120){

     pressTrue = false;
     redTrue = false;
     blueTrue = false;
     greenTrue = false;
    if (yellowTrue == false){
    lightsOff();
    noTone(speaker);
    }
    digitalWrite(yellow, HIGH);
   playTone(554.18, 5);
    yellowTrue = true;
    delay(50);
    if (xPos > 650 && yPos < 580 && yPos > 120){
      checkFlag = true;
    }
    
  }
  else if (xPos < 50 && yPos < 580 && yPos > 120){
    
     pressTrue = false;
     redTrue = false;
     yellowTrue = false;
     blueTrue = false;
    if (greenTrue == false){
    lightsOff();
    noTone(speaker);
    checkFlag = true;
    }
    digitalWrite(green, HIGH);
     playTone(659, 5);
    greenTrue = true;
    
    delay(50);
    if (xPos < 50 && yPos < 580 && yPos > 120){
      checkFlag = true;
    }
    
  }
  else{
    if(checkFlag == true){
      if (yellowTrue == true)
        solution[solutionPosition] = 4;
      else if (redTrue == true)
        solution[solutionPosition] = 1;
      else if (greenTrue == true)
        solution[solutionPosition] = 3;
      else if (blueTrue == true)
        solution[solutionPosition] = 2;
      else if (pressTrue == true)
        solution[solutionPosition] = 5;
      checkFlag = false;
      for (int i = 0; i <= solutionPosition; i++){
      if (solution[i] != pattern[i])
        lose = true;
      }
        solutionPosition++;
       
    }
    pressTrue = false;
    redTrue = false;
    greenTrue = false;
    yellowTrue = false;
    blueTrue = false;
    lightsOff();
    noTone(speaker);
    delay(5);
  }
  if ( (redTrue || blueTrue || greenTrue || yellowTrue) && press == 1){
     lightsOff();
  }
  
  if (solutionPosition >=  guessPosition){
    guessPosition++;
    Patternflag = true;
    solutionPosition = 0;
  }
 }
 else if (lose == true){
 digitalWrite(red, ledState);
  digitalWrite(blue, ledState);
  digitalWrite(green, ledState);
  digitalWrite(yellow, ledState);
    unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      playTone(300,0);
    } else {
      ledState = LOW;
      noTone(speaker);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(red, ledState);
    digitalWrite(blue, ledState);
    digitalWrite(green, ledState);
    digitalWrite(yellow, ledState);
  }
  int restart = digitalRead(button);
  if (restart == 1){
    randomSeed(analogRead(A3));
  for (int i = 0; i <= 32; i++){
    pattern[i] = random(1,6);
    if (i > 1 && pattern[i] == pattern[i-1] && pattern[i] == pattern[i-2])
    i--;
  }
  lose = false;
  guessPosition = 1;
  solutionPosition = 0;
  Patternflag = true;
  noTone(speaker);
  lightsOff();
  delay(500);
  startJingle();
  delay(100);
  }
 }
}