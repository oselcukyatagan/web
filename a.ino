#include <Arduino.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <DS3231.h>
#include <string.h>


DS3231 rtc(A4, A5);
String instruction = "Write: ";
String input;

const int letterArraySize = 50;
char letters[letterArraySize];

SoftwareSerial bt_comm(11, 10);
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
int lcd_setup_time = 200;
int lcd_loop_time = 300;

int led = 3;
int buttonPin = 13;

int buzzer = 2;
int buzzFreq = 550;

int dotWait = 100;
int dashWait = 300;

int signBreak = 100;
int letterBreak = 300;
int wordBreak = 300;

void dotSound() {

  delay(dotWait);
}

void dashSound() {

  delay(dashWait);
  noTone(buzzer);
}


void dot(int i) {
  digitalWrite(led, HIGH);
  tone(buzzer, buzzFreq);
  lcd.setCursor(i, 1);
  lcd.print(".");
  delay(dotWait);
  digitalWrite(led, LOW);
  noTone(buzzer);
}

void dash(int i) {

  digitalWrite(led, HIGH);
  tone(buzzer, buzzFreq);
  lcd.setCursor(i, 1);
  lcd.print("-");
  delay(dashWait);
  digitalWrite(led, LOW);
  noTone(buzzer);
}

void clear() {
  for (int j = 16; j >= 0; j--) {
    lcd.setCursor(j, 1);
    lcd.print(" ");
  }
}

// Morse code implementation for letters
void A() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  clear();
}

void B() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  clear();
}

void C() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void D() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void E() {
  int i = 0;
  dot(i);
  i++;
  clear();
}

void Fr() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void G() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void H() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void I() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void J() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void K() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void L() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  clear();
}

void M() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void N() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void O() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void P() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void Q() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void R() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void S() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void T() {
  int i = 0;
  dash(i);
  clear();
}

void U() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void V() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void W() {
  int i = 0;
  dot(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  clear();
}

void X() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  delay(signBreak);
  clear();
}

void Y() {
  int i = 0;
  dash(i);
  delay(signBreak);
  dot(i);
  delay(signBreak);
  dash(i);
  delay(signBreak);
  dash(i);
  clear();
}

void Z() {
  int i = 0;
  dash(i);
  i++;
  delay(signBreak);
  dash(i);
  i++;
  delay(signBreak);
  dot(i);
  i++;
  delay(signBreak);
  dot(i);
  clear();
}

void setup() {

  //rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(13, 15, 00);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(17, 06, 2023);

  bt_comm.begin(9600);
  Serial.begin(9600);
  rtc.begin();

  lcd.begin(16, 2);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  delay(80);
  
  lcd.setCursor(0,0);
  lcd.print(rtc.getDateStr());

  String rtc_time = String(rtc.getTimeStr()).substring(0, 5);

  lcd.setCursor(11,0);
  lcd.print(rtc_time);

  delay(lcd_setup_time);

  int buttonState = digitalRead(buttonPin);

  if(buttonState == LOW){
    S();
    delay(letterBreak);
    O();
    delay(letterBreak);
    S();
  }

  Serial.println(instruction);
  bt_comm.println(instruction);

  if (bt_comm.available() ) {

    input = bt_comm.readString();

    int inputLen = input.length();
    inputLen = min(inputLen, letterArraySize);  // clear unnecessary memory

    for (int i = 0; i < inputLen; i++) {
      letters[i] = toupper(input.charAt(i));  // Store the letters in the array
    }

    for (int i = 0; i < inputLen; i++) {  //print the letters with a space between
      bt_comm.print(letters[i]);
    }

    bt_comm.println("");


    for (int i = 0; i < inputLen; i++) {
      switch (letters[i]) {
        case 'A':
          A();
          delay(letterBreak);
          bt_comm.println("A");
          Serial.println("A");
          break;
        case 'B':
          B();
          delay(letterBreak);
          bt_comm.println("B");
          Serial.println("B");
          break;
        case 'C':
          C();
          delay(letterBreak);
          bt_comm.println("C");
          Serial.println("C");
          break;
        case 'D':
          D();
          delay(letterBreak);
          bt_comm.println("D");
          Serial.println("D");
          break;
        case 'E':
          E();
          delay(letterBreak);
          bt_comm.println("E");
          Serial.println("E");
          break;
        case 'F':
          Fr();
          delay(letterBreak);
          bt_comm.println("F");
          Serial.println("F");
          break;
        case 'G':
          G();
          delay(letterBreak);
          bt_comm.println("G");
          Serial.println("G");
          break;
        case 'H':
          H();
          delay(letterBreak);
          bt_comm.println("H");
          Serial.println("H");
          break;
        case 'I':
          I();
          delay(letterBreak);
          bt_comm.println("I");
          Serial.println("I");
          break;
        case 'J':
          J();
          delay(letterBreak);
          bt_comm.println("J");
          Serial.println("J");
          break;
        case 'K':
          K();
          delay(letterBreak);
          bt_comm.println("K");
          Serial.println("K");
          break;
        case 'L':
          L();
          delay(letterBreak);
          bt_comm.println("L");
          Serial.println("L");
          break;
        case 'M':
          M();
          delay(letterBreak);
          bt_comm.println("M");
          Serial.println("M");
          break;
        case 'N':
          N();
          delay(letterBreak);
          bt_comm.println("N");
          Serial.println("N");
          break;
        case 'O':
          O();
          delay(letterBreak);
          bt_comm.println("O");
          Serial.println("O");
          break;
        case 'P':
          P();
          delay(letterBreak);
          bt_comm.println("P");
          Serial.println("P");
          break;
        case 'Q':
          Q();
          delay(letterBreak);
          bt_comm.println("Q");
          Serial.println("Q");
          break;
        case 'R':
          R();
          delay(letterBreak);
          bt_comm.println("R");
          Serial.println("R");
          break;
        case 'S':
          S();
          delay(letterBreak);
          bt_comm.println("S");
          Serial.println("S");
          break;
        case 'T':
          T();
          delay(letterBreak);
          bt_comm.println("T");
          Serial.println("T");
          break;
        case 'U':
          U();
          delay(letterBreak);
          bt_comm.println("U");
          Serial.println("U");
          break;
        case 'V':
          V();
          delay(letterBreak);
          bt_comm.println("V");
          Serial.println("V");
          break;
        case 'W':
          W();
          delay(letterBreak);
          bt_comm.println("W");
          Serial.println("W");
          break;
        case 'X':
          X();
          delay(letterBreak);
          bt_comm.println("X");
          Serial.println("X");
          break;
        case 'Y':
          Y();
          delay(letterBreak);
          bt_comm.println("Y");
          Serial.println("Y");
          break;
        case 'Z':
          Z();
          delay(letterBreak);
          bt_comm.println("Z");
          Serial.println("Z");
          break;
        case ' ':
          delay(wordBreak);
          bt_comm.println(" ");
          Serial.println(" ");
        default:
          bt_comm.print("");
          Serial.println("");
          break;
      }
    }


    for (int i = 0; i < inputLen; i++) {  // clear the string array
      letters[i] = '\0';
    }
  }
}
