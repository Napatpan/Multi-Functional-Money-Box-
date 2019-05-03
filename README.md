# Multi-Functional-Money-Box

***

## Introduction
 สวัสดีค่ะ กลุ่มของเราได้ทำโปรเจ็คเรื่อง Multi-Functional Money Box หรือก็คือกระปุกออมสินอเนกประสงค์ ซึ่งกระปุกออมสินของเรานั้นมีความสามารถในการช่วยนับแยกเหรียญตั้งแต่เหรียญ 1 , 2 , 5 และ 10 บาท เพื่อให้ผู้ใช้มีความสะดวกสะบายในการนำกลับมาใช้ในครั้งต่อไป โดยโปรเจ็คนี้เราเขียนด้วยโปรแกรม Arduino ค่ะ

***

 
## How to use
 ### วิธีการใช้งานกระปุกออมสินอเนกประสงค์ สามารถทำได้ดังนี้ค่ะ 
 
 - ส่วนของการเก็บเหรียญ
 1. เสียบตัวจ่ายไฟ
 2. หยอดเหรียญที่ต้องการเก็บในช่องหยอดเหรียญ
 3. เหรียญจะไหลไปตามทางข้างใน และจะเก็บเข้าช่องเหรียญ
 4. ดูที่จอแสดงผล LED ว่าเหรียญที่เราหยอดมีค่าเพิ่มขึ้นหรือยัง
 
 - ส่วนของการนำออกมาใช้งาน
 1. กดที่ keypad โดยเริ่มจากเลือกประเภทของเหรียญ ( A = 1 บาท , B = 2 บาท , C = 5 บาท , D = 10 บาท)
 2. เมื่อเลือกประเภทเหรียญที่ต้องการเสร็จ ให้เลือกจำนวนที่ต้องการ โดยกดที่เลข 0 - 9 ที่ตัว keypad
 3. จากนั้นให้กด * ที่ตัว keypad เพื่อเป็นการตกลง หากต้องการยกเลิกให้กด # เพื่อเป็นจากยกเลิก
 4. จากนั้นเครื่องจะทำตามคำสั่ง เหรียญจะค่อยๆถยอยออกมาทีละเหรียญในขั้นตอนนี้อาจจะใช้เวลารอนานตามจำนวนเหรียญที่ต้องการ
 5. เมื่อได้เหรียญครบแล้วให้กด # ที่ตัว keypad 3 ครั้ง เพื่อเป็นการบันทึกผล
 6. เมื่อใช้งานเสร็จให้ถอดตัวจ่ายไฟออก
 
 ปล. กระปุกออมสินอเนกประสงค์ต้องใช้ Power Bank เป็นตัวจ่ายไฟ
 
 ![](https://github.com/Napatpan/Multi-Functional-Money-Box-/blob/master/Poster/2.jpg)

***

## Keywords
A = 1 บาท

B = 2 บาท
 
C = 5 บาท 

D = 10 บาท

"*" = ตกลง

"#" 1 ครั้ง = ยกเลิก 

"#" 3 ครั้ง = บันทึกผล

***

## Limitation
* จอแสดงผลจะแสดงเพียงจำนวนเหรียญว่ามีกี่เหรียญเท่านั้น ไม่ได้แสดงผลเป็นจำนวนเงินบาท

* กระปุกออมสินอเนกประสงค์นี้มีข้อจำกัดในการจัดเก็บที่เก็บได้ในปริมาณที่ไม่มาก

***

## Team Members

| ชื่อ | นามสกุล | GitHub Username | รหัสนักศึกษา |
|----|--------|-----------------|-----------|
|กิตติวัชร|เอี่ยมกิจการ|[Kittiwat17](https://github.com/Kittiwat17)|61070017|
|ชญานี|คำเจริญ|[cynbee](https://github.com/cynbee)|61070030|
|ชรินรัตน์|บูรณะพิสิฐ|[delldolly](https://github.com/delldolly)|61070037|
|ณภัทรพรรณ|แซ่โง้ว|[Napatpan](https://github.com/Napatpan)|61070046|


***
## Assistant Teacher
1. ผศ.ดร. กิติ์สุชาต พสุภา

2. ผศ. ดร. ปานวิทย์ ธุวะนุติ

งานนี้เป็นส่วนหนึ่งของวิชา การสร้างโปรแกรมคอมพิวเตอร์ Computer Programming (06016206)
หลักสูตรวิทยาศาสตร์บัณฑิต สาขาวิชาเทคโนโลยีสารสนเทศ
ภาคเรียนที่ 2 ปีการศึกษา 2561
คณะเทคโนโลยีสารสนเทศ
สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง
***

[![Multi-Functional Money Box]](https://www.youtube.com/watch?v=w796uZqj4PA&t=6s)
