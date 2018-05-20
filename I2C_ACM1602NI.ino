#include <Wire.h>    /* I2C用ライブラリ */
byte lcd_address = 0x50;    /* スレーブアドレス */

int I2CWriteCmd(byte cmd){
   Wire.beginTransmission(lcd_address);    /* START、アドレス送信 */
   Wire.write(0x00);    /* データ送信 */
   Wire.write(cmd);
   return Wire.endTransmission();    /* STOP */
}

int I2CWriteData(byte data){
   Wire.beginTransmission(lcd_address);
   Wire.write(0x80);
   Wire.write(data);
   return Wire.endTransmission();
}

void Init_LCD(){
   delay(45);    /* 電源投入後の電源が安定化するまでの待ち時間 */
   I2CWriteCmd(0x38);    /* バイト・データを8ビット単位で受け渡しする設定 */
   delay(1);
   I2CWriteCmd(0x38);    /* 念のための同じ設定を繰り返す */
   delay(1);
   I2CWriteCmd(0x0C);    /* データ表示、2行表示の設定 */
   delay(1);
   I2CWriteCmd(0x01);    /* 表示をクリアするコマンド */
}

void setup() {
  Wire.begin();    /* I2C初期化 */
  delay(100);
  Init_LCD();
}

void loop() {
  I2CWriteData(0x41);
  delay(500);
}
