const int ledPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  /* 如果缓冲区中有数据，则读取并输出 */
  if (Serial.available() > 0)
  {
    String cmd = Serial.readString();

    if (cmd == "led on")
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("turn on");
    }
    else if (cmd == "led off")
    {
      digitalWrite(ledPin, LOW);
      Serial.println("turn off");
    }
    else
    {
      Serial.println("invalid command!");
      Serial.println("command list:");
      Serial.println("led on: right on the led");
      Serial.println("led off: right out the led");
    }
  }
}
