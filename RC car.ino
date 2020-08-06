#include <SoftwareSerial.h>
#include <NewPing.h>
SoftwareSerial mySerial(13, 12); // RX, TX
NewPing us (7,8,400); //triger , echo 
char command ;
float distance ;
int spark = 255 ;
int speedym = 100 ; int speedys = 75;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
   pinMode ( 5 , OUTPUT);
   pinMode ( 6 , OUTPUT);
   pinMode ( 3 , OUTPUT);
   pinMode ( 4 , OUTPUT);
   pinMode ( 7 ,OUTPUT) ;
   pinMode (A0 , INPUT) ;
   pinMode (A1 ,OUTPUT) ;
   pinMode (A2 ,OUTPUT) ;
   pinMode (A3 ,OUTPUT) ;
   pinMode (A4 ,OUTPUT) ;
   pinMode (A5 ,OUTPUT) ;
   pinMode (9 ,OUTPUT) ; 
   pinMode (2 ,OUTPUT) ;
   pinMode (10 ,OUTPUT) ; 
   analogWrite (10 , 50) ; delay (600); analogWrite (10 , 100) ; delay (600);
   analogWrite (10 , 150) ; delay (800);  analogWrite (10 , 200) ; delay (600); analogWrite (10 , 250) ; delay (400);
   analogWrite (10 , 0) ;  
  
  
}

void loop() {   float distance = us.ping_cm(); 
  if ( distance >= 10 || distance == 0) {
                         if (mySerial.available()) {  command = mySerial.read ();  } 
                          switch (command){ case 'f' : forward (); break ;
                                            case 'l' : left (); break ;
                                            case 'r' : right (); break ;
                                            case 'b' : backward (); break ;
                                            case 's' : stopp (); break ;
                                            case 'z' : fronteyesop (); break ;
                                            case 'x' : fronteyescl (); break ;
                                            case 'c' : backeyesop  (); break ;
                                            case 'v' : backeyescl  (); break ;
                                            case 'n' : rotatecw  () ; break;
                                            case 'w' : rotateccw () ; break;
                                            case 'p' : zomaraO () ; break;
                                            case 'P' : zomaraC () ; break;
                                            case '1' : {speedym=100; speedys = 75 ;}  break;
                                            case '2' : {speedym=190; speedys = 130 ;} break;
                                            case '3' : {speedym=255; speedys = 175 ;} break;
                                            case '4' : {spark = 250;} break;
                                            case '5' : {spark = 150;} break;
                                            case 'm' : melody1 () ; break;
                                            case 'u' : uturn () ; break;
                                            
                                           
                                            }
                        }                                          
  else  { backward (); delay (1000); stopp ();  }
  }
   // motor A left : F,B = 5,6 , motor B right : F,B = 3,9 .
void forward ()   { analogWrite(3,speedym);     digitalWrite(9,LOW);     analogWrite(5,speedym);   digitalWrite(6,LOW);       }    
void backward ()  { digitalWrite(3,LOW);        analogWrite(9,speedym);  digitalWrite(5,LOW);      analogWrite(6,speedym);    }
void left ()      { analogWrite(3,210);         digitalWrite(9,LOW);     analogWrite(5,speedys);   digitalWrite(6,LOW);       }
void right ()     { analogWrite(3,speedys);     digitalWrite(9,LOW);     analogWrite(5,210);       digitalWrite(6,LOW);       }
void stopp ()     { digitalWrite(3,0);          digitalWrite(9,0);       digitalWrite(5,0);        digitalWrite(6,0);               }
void lights ()    {int spark = analogRead ( A0 ); spark = constrain (spark , 60 , 300 );  spark = map (spark , 60 , 300 , 0 , 255) ;  }
void fronteyesop ()  { analogWrite (A1 , spark) ; }        
void fronteyescl ()  { analogWrite (A1 , 0) ;     }
void backeyesop ()   { analogWrite (A0 , spark) ; }        
void backeyescl ()   { analogWrite (A0 , 0) ;     }
void rotateccw  ()   { analogWrite(3,75); analogWrite(9,LOW);  analogWrite(5,LOW);    analogWrite(6,75); }
void rotatecw ()     { analogWrite(3,LOW);  analogWrite(9,75); analogWrite(5,75);   analogWrite(6,LOW);}
void zomaraO ()       {analogWrite (10 , 100) ;  }      void zomaraC ()       {analogWrite (10 , 0) ;}
void melody () { 
  analogWrite (10 , 261); delay(1000);//Middle C
  analogWrite (10 , 277); delay(1000); //C#
  analogWrite (10 , 294); delay(1000); //D
  analogWrite (10 , 311); delay(1000); //D#
  analogWrite (10 , 330); delay(1000); //E
  analogWrite (10 , 349); delay(1000);//F
  analogWrite (10 , 370); delay(1000); //F#
  analogWrite (10 , 392); delay(1000); //G
  analogWrite (10 , 415); delay(1000); //G#
  analogWrite (10 , 440); delay(1000);//a
  analogWrite (10,0);
                } 
void melody1 () {
  analogWrite (10 , 261); delay(900);//Middle C
  analogWrite (10 , 294); delay(900); //D
  analogWrite (10 , 330); delay(900); //E
  analogWrite (10 , 349); delay(900);//F
  analogWrite (10 , 392); delay(900); //G
  analogWrite (10 , 440); delay(500);//a
  analogWrite (10 , 0);}
  void uturn () { forward () ;  delay (2000); rotateccw  (); delay (500);forward () ;  delay (2000);  }
