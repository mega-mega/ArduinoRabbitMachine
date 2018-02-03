#include <Servo.h>//ライブラリの読み込み          
#define PBS1 5//置き換え（PBS1→“5”）         
#define PBS2 6//置き換え（PBS2→“6”）         
#define analogPin 0//置き換え（analogPin→“0”）         
int value = 0; //変数「value」はint型。valueをクリア（0）
Servo servo0, servo1, servo2; //Servo型の変数は「servo0」～「servo2」にする
void setup()//初期設定
{
  servo0.attach(2);//Srevo型の変数「servo0」をピン2に割り当て
  servo1.attach(3);//Srevo型の変数「servo1」をピン3に割り当て
  servo2.attach(4);//Srevo型の変数「servo2」をピン4に割り当て
  pinMode(PBS1, INPUT); //PBS1（ピン5）を入力に設定
  pinMode(PBS2, INPUT); //PBS2（ピン6）を入力に設定
}
void loop()//メインの処理
{
  int s2 = digitalRead(PBS2); //PBS2の値を読み取り、s2に代入（s2はint型）
  if (s2 == LOW) //s2がLOW（PBS2がON）ならば、次に行く
  {
    while (1) //ループ(1)
    {
      while (1) //ループ(2)
      {
        while (1) //ループ(3)。ここからロボットは、うさぎ跳びで前進動作
        {
          servo2.write(30);//サーボ出力。servo2の角度は40°。尾は下がる
          delay(500);//タイマ(0.3s)
          servo0.write(20);//servo0の角度は20°。左脚を前に出す
          servo1.write(160);//servo1の角度は160°。右脚を前に出す
          delay(300);//タイマ(0.3s)
          servo2.write(80);//servo2の角度は80°。尾は水平近くまで上がる
          delay(300);//タイマ(0.3s)
          servo0.write(90);//servo0の角度は90°。左脚は垂直
          servo1.write(90); //servo1の角度は90°。右脚は垂直
          delay(300);//タイマ(0.3s)
          value = analogRead(analogPin); //A-D変換。デジタル値をvalueに代入
          if (value >= 460) {break;} //break文でループ(3)を脱出
          servo2.write(40);//servo2の角度は40°。尾は下がる
          delay(500);//タイマ(0.3s)
          servo0.write(20);//servo1の角度は20°。
          servo1.write(160);//servo1の角度は160°。右脚を前に出す
          delay(300);//タイマ(0.3s)
          servo2.write(80);//servo2の角度は80°
          delay(300);
          servo0.write(90);
          servo1.write(90);//servo1の角度は90°。右脚は垂直
          delay(300);//タイマ(0.3s)
          value = analogRead(analogPin); //A-D変換、デジタル値をvalueに代入
          if (value >= 460) {break;}//break文でループ（3）を脱出
        }
        if (value >= 460) //value >=460ならば、次へ行く
        {
          servo2.write(80);//servo2の角度は80°。尾は水平近くまで上がる
          servo1.write(90); //servo1の角度は90°。右脚は垂直
          delay(300);
          servo0.write(90);//servo0 の角度は90°。左脚は垂直
          for(int count=0;count<5;count++){back2();}
          //back2(); back2(); back2(); back2(); back2();//関数back2を呼び出す
          for(int count=0;count<4;count++){left();}
          //left(); left(); left(); left();//関数leftを呼び出す
          break;//break文でループ(2)を脱出
        }
      }
    }
  }
}
void back2()//関数back2の本体
{
  servo2.write(30);
  delay(500);
  servo0.write(140);
  servo1.write(40);
  delay(400);
  servo2.write(80);
  delay(300);
  servo0.write(90);
  servo1.write(90);
  delay(400);
}
void left()//関数leftの本体（左方向へ旋回操作）
{
  servo2.write(30);
  delay(500);
  servo0.write(90);
  servo1.write(160);
  delay(400);
  servo2.write(80);
  delay(400);
  servo0.write(90);
  servo1.write(90);
  delay(400);
}
