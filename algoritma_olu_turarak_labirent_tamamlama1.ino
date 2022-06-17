int ileri_dugme = 8 ;
int sag_dugme = 9 ;
int geri_dugme = 10 ;
int sol_dugme = 11 ;
int buttonPin = 12 ; 

int my_array[50];

int buttonState = 0;
int buttonStateIleri = 0;
int buttonStateSag = 0;
int buttonStateGeri = 0;
int buttonStateSol = 0;

// Motor A Baglantilari
int enA = 7;
int in1 = 6;
int in2 = 5;
// Motor B Baglantilari
int enB = 2;
int in3 = 3;
int in4 = 4;

int calisma = 0 ;
int basilma = 0 ; 
int sayim = 0;

void setup() {

Serial.begin(9600);
pinMode(buttonPin,INPUT);
pinMode(ileri_dugme,INPUT);
pinMode(sag_dugme,INPUT);
pinMode(geri_dugme,INPUT);
pinMode(sol_dugme,INPUT);
Serial.println("merhaba");
  
  // Motorların çıkış pinlerini set ettik
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Motorlar kapali durumda - Kurulma durumunda
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 


}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  buttonStateIleri = digitalRead(ileri_dugme);
  buttonStateSag = digitalRead(sag_dugme);
  buttonStateGeri = digitalRead(geri_dugme);
  buttonStateSol = digitalRead(sol_dugme);
  
  if(buttonState == 1 )
  {
    calisma = 1;
    buttonState = 0 ;
    basilma++;
    Serial.print(basilma);
    Serial.println("Baslatildi");
  }
  if(calisma == 1)
  {
    calisma = 1 ;
    //int sayim = 0;
    //Serial.println("acildi ");
    if(buttonStateIleri == 1 )
    {
      my_array[sayim] = 8 ;
      sayim++;
      Serial.println("ileri dugme : ");
      buttonStateIleri == 0;
      delay(200);
    }
    if(buttonStateSag == 1 )
    {
      my_array[sayim] = 9 ;
      sayim++;
      Serial.println("sag dugme : ");
      buttonStateSag == 0;
      delay(200);
    }
    if(buttonStateGeri == 1 )
    {
      my_array[sayim] = 10 ;
      sayim++;
      Serial.println("geri dugme : ");
      buttonStateGeri == LOW;
      delay(150);
    }
    if(buttonStateSol == 1 )
    {
      my_array[sayim] = 11 ;
      sayim++;
      Serial.println("sol dugme : ");
      buttonStateSol == 0;
      delay(200);
    }
    delay(200);
  }


  if(basilma == 2)
  {
    Serial.println("kapatilmis hali ");
    basilma++;
    calisma++;
    Serial.print("sayim : ");
    Serial.println(sayim);
    
    // Motorların hızlarını max olarak ayarladık
    // For PWM maximum possible values are 0 to 255
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    
    for(int i = 0 ; i < sayim ; i++ )
    {
      Serial.print("dizinin : ");
      Serial.print(i);
      Serial.print("elamani : ");
      Serial.println(my_array[i]);
      
      if(my_array[i] == 8 )
      {
        // Turn on motor A & B
        // Ileri
  		digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(2000);
        // Now turn off motors
  		digitalWrite(in1, LOW);
  		digitalWrite(in2, LOW);
  		digitalWrite(in3, LOW);
  		digitalWrite(in4, LOW);
      }
      else if(my_array[i] == 9 )
      {
        //Saga
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
        // Now turn off motors
  		digitalWrite(in1, LOW);
  		digitalWrite(in2, LOW);
  		digitalWrite(in3, LOW);
  		digitalWrite(in4, LOW);
      }
      else if(my_array[i] == 10 )
      {
        // Geriye
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(2000);
        // Now turn off motors
  		digitalWrite(in1, LOW);
  		digitalWrite(in2, LOW);
  		digitalWrite(in3, LOW);
  		digitalWrite(in4, LOW);
      }
      else if(my_array[i] == 11 )
      {
        // Sola
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(2000);
        // Now turn off motors
  		digitalWrite(in1, LOW);
  		digitalWrite(in2, LOW);
  		digitalWrite(in3, LOW);
  		digitalWrite(in4, LOW);

      }
      else
      {
        // Now turn off motors
  		//digitalWrite(in1, LOW);
  		//digitalWrite(in2, LOW);
  		//digitalWrite(in3, LOW);
  		//digitalWrite(in4, LOW);
        break;
        
      }
      
    }
    
  }
  
   
}
 