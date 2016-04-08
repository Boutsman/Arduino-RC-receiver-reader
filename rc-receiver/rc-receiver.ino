#define CH1 2
#define CH2 3
#define CH3 7

int lastVal1 = 0;
int lastVal2 = 0;
int lastVal3 = 0;

int valCH1 = 0;
int valCH2 = 0;
int valCH3 = 0;

void setup() {
  pinMode(CH1, INPUT_PULLUP);
  pinMode(CH2, INPUT_PULLUP);
  pinMode(CH3, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(CH2), geefTijd, FALLING);
  attachInterrupt(digitalPinToInterrupt(CH1), resetTimer1, RISING);
  attachInterrupt(digitalPinToInterrupt(CH2), resetTimer2, RISING);
  attachInterrupt(digitalPinToInterrupt(CH3), resetTimer3, RISING);
  Serial.begin(115200);
}

void loop() {
  Serial.print(valCH1);
  Serial.print("\t");

  Serial.print(valCH2);
  Serial.print("\t");

  Serial.print(valCH3);
  Serial.print("\t");

  Serial.println("");
}

void geefCH1() {
  int val = micros();
  valCH1 = val - lastVal1;
  //Serial.println(valCH1);
  attachInterrupt(digitalPinToInterrupt(CH1), resetTimer1, RISING);
}

void geefCH2() {
  int val = micros();
  valCH2 = val - lastVal2;
  //Serial.println(valCH2);
  attachInterrupt(digitalPinToInterrupt(CH2), resetTimer2, RISING);
}

void geefCH3() {
  int val = micros();
  valCH3 = val - lastVal3;
  //Serial.println(valCH3);
  attachInterrupt(digitalPinToInterrupt(CH3), resetTimer3, RISING);
}

void resetTimer1() {
  lastVal1 = micros();
  //Serial.println("resetTimer1");
  attachInterrupt(digitalPinToInterrupt(CH1), geefCH1, FALLING);
}

void resetTimer2() {
  lastVal2 = micros();
  //Serial.println("resetTimer2");
  attachInterrupt(digitalPinToInterrupt(CH2), geefCH2, FALLING);
}

void resetTimer3() {
  lastVal3 = micros();
  //Serial.println("resetTimer3");
  attachInterrupt(digitalPinToInterrupt(CH3), geefCH3, FALLING);
}
