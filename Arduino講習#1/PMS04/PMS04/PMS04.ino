const int LED = 11;                      //LEDを11番ピンに接続
int val =0;                              //センサの値を記憶する

void setup() {
    pinMode(LED, OUTPUT);                //LEDは出力
}

void loop() {
    val = analogRead(0);                //センサの値を読む

    analogWrite(LED, val);              //センサの値でLEDを点灯
    delay(10);                          //少しの間プログラムを停止
}
