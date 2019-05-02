
const byte interruptPin = 2;//กำหนด Interrupt pin
volatile byte keyValue=0;
volatile bool printState = false;
const char charSetting[]={'Z','2','3','A',
                          '4','5','6','B',
                          '7','8','9','C',
                           '*','0','#','D'}; //กำหนดตัวอักษรที่จะได้ของแต่ละปุ่ม
void keypadRead();
void setup() {
  Serial.begin(9600);
  for(int i=3;i<=6;i++){pinMode(i,INPUT);}//loop กำหนด pinMode
  attachInterrupt(digitalPinToInterrupt(interruptPin), keypadRead,FALLING);//setup Interrupt keypadRead=ฟังก์ชั่นที่จะทำงานเมื่อInterrupt ,FALLING=Interruptเมื่อเป็นขอบขาลง
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(printState){
    Serial.println(charSetting[keyValue]);//charSetting[keyValue] ตัวอักษรที่จะให้แสดง keyValu=indexของarray charSetting
    printState=false;
  }

}
void keypadRead(){
  keyValue=0;
printState=true;//จะมีหรือไม่ขึ้นอยู่กับโปรแกรม
 keyValue=(-digitalRead(6))&1;    //กำหนดindex จากข้อมูลของIC
 keyValue+=((-digitalRead(5))&2);
 keyValue+=((-digitalRead(4))&4);
 keyValue+=((-digitalRead(3))&8);
}
