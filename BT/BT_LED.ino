#include <BluetoothSerial.h>
#include <string.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽廣播名稱，請自己記得
  pinMode(4,OUTPUT);
  
}

void loop() {
  
  if(SerialBT.available()){
    Serial.println("");
  }
  while(SerialBT.available())
  {
    String LED_State;
    char btdata = SerialBT.read();
    Serial.print(btdata);//查看藍芽輸入的值
    if (btdata=='1'){digitalWrite(4,HIGH);}
    if (btdata=='0'){digitalWrite(4,LOW);}
    if (btdata=='2'){
      if(digitalRead(4)==HIGH){SerialBT.write('1');}
      else{SerialBT.write('0');}
    }
    
  }  
  delay(100);
}
