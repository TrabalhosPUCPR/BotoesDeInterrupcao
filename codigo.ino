// C++ code
//
int leds[] = {13, 12, 11, 10, 9 , 8};
int botao1 = A0;
int botao2 = A1;

void setup()
{
  for(int i = 0; i < sizeof(leds)/sizeof(int);i++){
    pinMode(leds[i], OUTPUT);

  }
  Serial.begin(9600);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

}

void loop()
{
  //Serial.println(analogRead(botao2));
  ligarLed();
}

void ligarLed(){
  switch(analogRead(botao1)){
    case 236:
    liga_spec(1);
      break;
    case 205:
    liga_spec(2);
      break;
      case 170:
    liga_spec(3);
      break;
  }
  
  switch(analogRead(botao2)){
    case 236:
    	liga_spec(4);
      	break;
    case 205:
    	liga_spec(5);
      	break;
    case 170:
    	liga_spec(6);
      	break;
  }

}

int estadosled[] = {LOW,LOW,LOW,LOW,LOW,LOW};
void liga_spec(int led) {
  if(estadosled[led-1] == HIGH){
  	estadosled[led-1] = LOW;
  }else{
  	estadosled[led-1] = HIGH;
  }
  digitalWrite(leds[led - 1], estadosled[led-1]);

}