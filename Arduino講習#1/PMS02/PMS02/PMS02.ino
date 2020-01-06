//ボタンを離すとLEDが点灯し、
//ボタンから手を離してもついたままにする
//バウンジングを解消する簡単な方法を取り入れる
//ボタンを押したままだと明るさが変化する

const int LED = 11;                 //LEDを定数で指定する
const int BUTTON = 8;               //BUTTONを定数で指定する

int val = 0;                        //入力ピンの状態がvalに記憶される
int old_val = 0;                    //valの前の値を保存しておく
int state = 0;                      //LEDの状態

int brightness = 128;               //明るさの値を保存する
unsigned long startTime = 0;        //いつ押し始めたか

void setup() {
    pinMode(LED,OUTPUT);            //LEDは出力
    pinMode(BUTTON,INPUT);          //BUTTONは入力
}
void loop() {
    val = digitalRead(BUTTON);      //入力を読みvalに保存

    if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;              //オフからオンへ、オンからオフへ
    startTime = millis();           //millis()はArduinoの時計
                                    //ボードがリセットされてからの時間を
                                    //m秒で単位で返す
                                    //（最後にボタンが押された時間を記憶）
    delay(10);
    }

    if ((val == HIGH) && (old_val == HIGH)) {
            if (state == 1 && (millis() - startTime) > 50) {
                brightness++;       //brightnessに１を足す
                delay(10);          //brightnessが早くならないように
                if (brightness > 255) {     //255が最大値
                    brightness = 0; //255を超えたら0に戻す
                }
            }
    }

old_val = val;                      //valは古いでしまっておく

if (state == 1) {
    analogWrite(LED, brightness);   //現在の明るさでLEDを点灯
    } else {
    analogWrite(LED,0);             //LEDをオフ
    }
}
