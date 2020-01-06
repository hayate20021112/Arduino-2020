const int LED = 11;     //定数でLEDのピンを指定する
int i = 0;				//データを格納する変数


void setup() {
   pinMode(LED, OUTPUT);	//LEDを出力と指定する
    }
void loop() {
   for(i = 0; i < 255; i++) {		//iの数値が0から255まで1ずつ増える
       analogWrite(LED, i);		//LED(11)のピンからiの数値出力する
       delay(10);				//10msずつ
   }
   for(i = 255; i > 0; i--) {			//iの数値が255から0まで1ずつ減る
       analogWrite(LED, i);		//LED(11)のピンからiの数値出力する
       delay(10);				//10msずつ
   }
}
