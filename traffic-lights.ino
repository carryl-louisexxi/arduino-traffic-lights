const int sswitch=2;
const int button1=3;
const int button2=4;
const int green=5;
const int yellow=6;
const int red=7;
const int pgreen=8;
const int pred=9;
const int buttonlight=10;

int blinkk=0;
int state=0;


void setup() {
 pinMode(sswitch, INPUT);
 pinMode(button1, INPUT);
 pinMode(button2, INPUT);
 pinMode(green, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(red, OUTPUT);
 pinMode(pgreen, OUTPUT);
 pinMode(pred, OUTPUT);
 pinMode(buttonlight, OUTPUT);
}

void loop() {
  switch(state){
    case 0:
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pred, LOW);
    digitalWrite(buttonlight, LOW);
    if(digitalRead(sswitch)==HIGH){
      state=1;
    } else {
      state=0;
    }
    break;
    case 1:
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pred, HIGH);
    digitalWrite(buttonlight, LOW);
    if(digitalRead(button1)==HIGH || digitalRead(button2)==HIGH){
      state=2;
    }else{
      state=1;
    }
    break;
    case 2:
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pred, HIGH);
    digitalWrite(buttonlight, HIGH);
    delay(5000);
    state=3;
    break;
    case 3:
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(pgreen, HIGH);
    digitalWrite(pred, LOW);
    digitalWrite(buttonlight, LOW);
    delay(10000);
    state=4;
    break;
    case 4:
    for(blinkk=0; blinkk<10; ++blinkk){
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(pgreen, HIGH);
    digitalWrite(pred, LOW);
    delay(250);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(pgreen, LOW);
    digitalWrite(pred, LOW);
    delay(250);   
    if(digitalRead(button1)==HIGH || digitalRead(button2)==HIGH){
      digitalWrite(buttonlight, HIGH);
    }
    }
    state=5;
    break;
   case 5:
    for(blinkk=0; blinkk <5; ++blinkk){
      if(digitalRead(button1)==HIGH || digitalRead(button2)==HIGH){
        digitalWrite(buttonlight,HIGH);
      }
       digitalWrite(green, HIGH);
       digitalWrite(yellow, LOW);
       digitalWrite(red, LOW);
       digitalWrite(pgreen, LOW);
       digitalWrite(pred, HIGH); 
       delay(1000);
    }
       if(digitalRead(buttonlight)==HIGH){
         state=2;
       }else if(digitalRead(buttonlight)==LOW){
         state=1;
       }
    break;     
  }
}
