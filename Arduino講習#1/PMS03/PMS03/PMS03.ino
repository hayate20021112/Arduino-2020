const int LED = 11;             //LEDが繋がってるピン
int val = 0;                    //センサの値を記憶する変数

void setup() {
    pinMode(LED, OUTPUT);       //LEDのピンを出力に設定
                                //アナログピンは自動で入力になる
}

void loop() {
    val = analogRead(0);        //センサ（A0ピン）から値を読み込む

    digitalWrite(LED, HIGH);    //LEDをオン
    delay(val);                 //valの分プログラムを停止

    digitalWrite(LED, LOW);     //LEDをオン
    delay(val);                 //valの分プログラムを停止

}
