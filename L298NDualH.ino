/*
  L298N Motor Demo

*/

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()
{
  // Set all the motor control pins to outputs

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void demoONE()
{
  //This function will run the motor in both directions at a fixed seep
  
  //Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  //Set speed to 200 out of possible range 0~255

  analogWrite(enB, 200);

  // now change motor directions

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(2000);

  //now turn off motor

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

  void demoTWO()
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    //Accelerate from zero to maximum speed

    for (int i=0; i < 256; i++)
    {
      analogWrite(enB, i);
      delay(20);
      
    }

    //Decelerate
    for (int i=255; i>=0; --i)
    {
      analogWrite(enB, i);

      delay(20);
    }

  //Turn off motor

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  }


  void loop()
  {
    demoONE();
    delay(3000);

    demoTWO();
    delay(2000);
  }
  

  
