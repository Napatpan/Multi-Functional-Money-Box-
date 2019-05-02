#include <EEPROM.h>

//#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal.h>


// full //

#include <Wire.h>

#include <LiquidCrystal_I2C.h> // import libaly : http://www.allarduino.com/download/lcd_i2c.rar
//#include <OnewireKeypad.h>
#include <String.h>
#include <Servo.h>

#define I2C_ADDR 0x27 // กำหนดตำแหน่ง Address ของ I2C

#define BACKLIGHT_PIN 3

LiquidCrystal_I2C lcd(0x27, 16, 2);


Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;
int count[4] = {
  0,0,0,0
};
int count4 = count[0] + count[1] + count[2] +count[3];

char KEYS[16] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};
int kee[16] = {
  1,2,3,0,
  4,5,6,0,
  7,8,9,0,
  0,0,0,0
};
int counter = 0;
int swish = 0, swish2 = 0, swish3 = 0, swish4 = 0, check = 0, check2 = 0, check3 = 0, check4 = 0;
char keypad1 = 'n', keypad2 = 'n', keypad3 = 'n', keypad4 = 'n', selec = 'n';
int numpad = 0, num = 0, i =10, numpad2 = 0, numpad3 = 0, numpad4 = 0;
int pin_counter1 = 0,pin_counter2 = 4, pin_counter3 = 3, pin_counter4 = 7;//digital pin ก้ามปู
int keyvalue = 0;
//ขา 6 9 10 11 servo

const byte interruptPin = 2;//กำหนด Interrupt pin
volatile byte keyValue=0;
volatile bool printState = false;

void keypadRead();
char Key = KEYS[keyvalue];
void setup () {
  Serial.begin(9600);
  
 
  attachInterrupt(digitalPinToInterrupt(interruptPin), keypadRead,FALLING);
    
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
   
  
  
  lcd.init();                                                    
  lcd.setCursor(13,1);
  lcd.print(count4);
  lcd.setCursor(13,0);
  lcd.print("ALL");
      
  lcd.setCursor(0,0);
  lcd.print("1:");
  lcd.print(count[0]);
  lcd.setCursor(7,0);
  lcd.print("2:");
  lcd.print(count[1]);
  lcd.setCursor(0,1);
  lcd.print("5:");
  lcd.print(count[2]);
  lcd.setCursor(6,1);
  lcd.print("10:");
  lcd.print(count[3]);
 

  
  servo.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo.write(check*180);
  servo2.write(check2*180);
  servo3.write(check3*180);
  servo4.write(check4*180);
  
  pinMode(pin_counter1, INPUT);
  pinMode(pin_counter2, INPUT);
  pinMode(pin_counter3, INPUT);
  pinMode(pin_counter4, INPUT);
  
//  Serial.println("99");
  
}


  //

void loop() {
  
  int isCount1 = digitalRead(pin_counter1); 
  int isCount2 = digitalRead(pin_counter2); 
  int isCount3 = digitalRead(pin_counter3); 
  int isCount4 = digitalRead(pin_counter4); 
   
  if(isCount1 == 1)
  {
      count[0]++;
      count4 =count[0] + count[1] + count[2] + count[3];
      lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(2,0);
      lcd.print(count[0]);
      delay(1000);
  }
  if(isCount2 == 1)
  {
      count[1]++;
      count4 =count[0] + count[1] + count[2] + count[3];
      lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(9,0);
      lcd.print(count[1]);
      delay(1000);
      
  }
  if(isCount3 == 1)
  {
      count[2]++;
      count4 =count[0] + count[1] + count[2] + count[3];
      lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(2,1);
      lcd.print(count[2]);
      delay(1000);
      
  }
  if(isCount4 == 1)
  {
      count[3]++;
      count4 =count[0] + count[1] + count[2] + count[3];
      lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(9,1);
      lcd.print(count[3]);
      delay(1000);
      
  }
  
        
        
      
  
  
  
  if(swish == 1)
  {
    if(count[0] == 0)
    {
      numpad = 0;
    }
    for(int x = 0;x < numpad; x += 0)
    {
      if(count[0] == 1 && numpad > 0)
      {
        numpad = 1;
      }
      else if(check == 0)
      {
        servo.write(180);
        check = 1;
        delay(1000);
      }
      else if(check == 1)
      {
        servo.write(0);
        check = 0;
        delay(1000);
        
      }numpad--;
      count[0]--;
      count4 = count[0] + count[1] + count[2] +count[3];
      
      if(count[0] <10)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1:");
        
        lcd.setCursor(7,0);
        lcd.print("2:");
        lcd.setCursor(9,0);
        lcd.print(count[1]);
        lcd.setCursor(13,0);
        lcd.print("ALL");
        lcd.setCursor(0,1);
        lcd.print("5:");
        lcd.setCursor(2,1);
        lcd.print(count[2]);
        lcd.setCursor(6,1);
        lcd.print("10:");
        lcd.setCursor(9,1);
        lcd.print(count[3]);
      }
      lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(2,0);
      
      lcd.print(count[0]);
    }swish = 0;
    keypad1='n';
  }
  
  if(swish2 == 1)
  {
    if(count[1] == 0)
    {
      numpad2 = 0;
    }
    for(int v = 0;v < numpad2; v += 0)
    {
      if(count[1] == 1 && numpad2 > 0)
      {
        numpad2 = 1;
      }
      else if(check2 == 0)
      {
        servo2.write(180);
        check2 = 1;
        delay(1000);
      }
      else if(check2 == 1)
      {
        servo2.write(0);
        check2 = 0;
        delay(1000);
      }
      numpad2--;
      count[1]--;
      count4 = count[0] + count[1] + count[2] +count[3];
      if(count[1] <11)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1:");
        lcd.setCursor(2,0);
        lcd.print(count[0]);
        
        lcd.setCursor(7,0);
        lcd.print("2:");
        
        lcd.setCursor(13,0);
        lcd.print("ALL");
        lcd.setCursor(0,1);
        lcd.print("5:");
        lcd.setCursor(2,1);
        lcd.print(count[2]);
        lcd.setCursor(6,1);
        lcd.print("10:");
        lcd.setCursor(9,1);
        lcd.print(count[3]);
        
      }
    lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(9,0);
      
      lcd.print(count[1]);
    }swish2 = 0;
    keypad2 = 'n';
    
  }
  if(swish3 == 1)
  {
    if(count[2] == 0)
    {
      numpad3 = 0;
    }
    for(int b = 0;b < numpad3; b += 0)
    {
      if(count[2] == 1 && numpad3 > 0)
      {
        numpad3 = 1;
      }
      else if(check3 == 0)
      {
        servo3.write(180);
        check3 = 1;
        delay(1000);
      }
      else if(check3 == 1)
      {
        servo3.write(0);
        check3 = 0;
        delay(1000);
      }
      numpad3--;
      count[2]--;
       count4 = count[0] + count[1] + count[2] +count[3];
      if(count[2] <11)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1:");
        lcd.setCursor(2,0);
        lcd.print(count[0]);
        lcd.setCursor(7,0);
        lcd.print("2:");
        lcd.setCursor(9,0);
        lcd.print(count[1]);
        lcd.setCursor(13,0);
        lcd.print("ALL");
        lcd.setCursor(0,1);
        lcd.print("5:");
        
        lcd.setCursor(6,1);
        lcd.print("10:");
        lcd.setCursor(9,1);
        lcd.print(count[3]);
      }
    lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(2,1);
      
      lcd.print(count[2]);
      
    }swish3 = 0;
    keypad3 = 'n';
  }
  if(swish4 == 1)
  {
    if(count[3] == 0)
    {
      numpad4 = 0;
    }
    for(int z = 0;z < numpad4; z += 0)
    {
      if(count[3] == 1 && numpad4 > 0)
      {
        numpad4 = 1;
      }
      else if(check4 == 0)
      {
        servo4.write(180);
        check4 = 1;
        delay(1000);
      }
      else if(check4 == 1)
      {
        servo4.write(0);
        check4 = 0;
        delay(1000);
      }
      numpad4--;
      count[3]--;
      count4 = count[0] + count[1] + count[2] +count[3];
      if(count[3] <11)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1:");
        lcd.setCursor(2,0);
        lcd.print(count[0]);
        lcd.setCursor(2,0);
        lcd.print(count[0]);
        lcd.setCursor(7,0);
        lcd.print("2:");
        lcd.setCursor(9,0);
        lcd.print(count[1]);
        
        lcd.setCursor(13,0);
        lcd.print("ALL");
        lcd.setCursor(0,1);
        lcd.print("5:");
        lcd.setCursor(2,1);
        lcd.print(count[2]);
        lcd.setCursor(6,1);
        lcd.print("10:");
        
      }
      
    lcd.setCursor(13,1);
      lcd.print(count4);
      
      lcd.setCursor(9,1);
      
      lcd.print(count[3]);
    }swish4 = 0;
    keypad4 = 'n';
  }
  count4 = count[0] + count[1] + count[2] +count[3];
}

void keypadRead(){
  count4 = count[0] + count[1] + count[2] +count[3];
  keyValue=0;
printState=true;//จะมีหรือไม่ขึ้นอยู่กับโปรแกรม
 keyValue=(-digitalRead(13))&1;    //กำหนดindex จากข้อมูลของIC
 keyValue+=((-digitalRead(12))&2);
 keyValue+=((-digitalRead(8))&4);
 keyValue+=((-digitalRead(5))&8);
 
 Serial.println(KEYS[keyValue]);
 Serial.println(Key);
 if(KEYS[keyValue] == 'A' && keypad1 == 'n' && selec == 'n')
        {
          
          selec = 'A';
          keypad1 = 'A';
        }
        if(KEYS[keyValue] == 'B' && keypad2 == 'n' && selec == 'n')
        {
          selec = 'B';
          keypad2 = 'B';
        }
        if(KEYS[keyValue] == 'C' && keypad3 == 'n' && selec == 'n')
        {
          selec = 'C';
          keypad3 = 'C';
        }
        if(KEYS[keyValue] == 'D' && keypad4 == 'n' && selec == 'n')
        {
          selec = 'D';
          keypad4 = 'D';
        
        }
        if((KEYS[keyValue]>='0'&& KEYS[keyValue]<='9') && keypad1 == 'A'&& selec == 'A')
        {
           
            numpad = (numpad*i) + kee[keyValue];
            
        }
        if((KEYS[keyValue]>='0'&& KEYS[keyValue]<='9') && keypad2 == 'B'&& selec == 'B')
        {
            numpad2 = (numpad2*i) + kee[keyValue];
            
        }
        if((KEYS[keyValue]>='0'&& KEYS[keyValue]<='9') && keypad3 == 'C' && selec == 'C')
        {
           numpad3 = (numpad3*i) + kee[keyValue];
            
        }
        if((KEYS[keyValue]>='0'&& KEYS[keyValue]<='9') && keypad4 == 'D' && selec == 'D')
        {
            numpad4 = (numpad4*i) + kee[keyValue];
            
        }
        

        else if(KEYS[keyValue] == '#')
        {
            keypad1 = 'n';
            keypad2 = 'n';
            keypad3 = 'n';
            keypad4 = 'n';
            numpad = 0;
            numpad2 = 0;
            numpad3 = 0;
            numpad4 = 0;
            selec = 'n';
            swish = 0;
            swish2 = 0;
            swish3 = 0;
            swish4 = 0;
            counter++;
            Serial.println(counter);
        }
        if(counter == 3)
        {
          Serial.println("123");
          EEPROM.update(&count[0], count[0]);
          EEPROM.update(&count[1], count[1]);
          EEPROM.update(&count[2], count[2]);
          EEPROM.update(&count[3], count[3]);
          EEPROM.update(&count4, count4);
          EEPROM.update(&check, check);
          EEPROM.update(&check2, check2);
          EEPROM.update(&check3, check3);
          EEPROM.update(&check4, check4);
          counter = 0;
        }
        else if(KEYS[keyValue] == '*' && keypad1 == 'A')
        {
            selec = 'n';
            swish = 1;
            
        }
        else if(KEYS[keyValue] == '*' && keypad2 == 'B')
        {
            selec = 'n';
            swish2 = 1;
            
        }
        else if(KEYS[keyValue] == '*' && keypad3 == 'C')
        {
            selec = 'n';
            swish3 = 1;
            
        }
        else if(KEYS[keyValue] == '*' && keypad4 == 'D')
        {
            selec = 'n';
            swish4 = 1;
            
        }
 
}
