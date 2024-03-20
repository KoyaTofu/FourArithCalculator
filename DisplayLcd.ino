/****************************************************
 * ファイル名　：DisplayLcd.ino
 * 役割　　　　：LCDを制御、表示
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/

/***** ファイル内-関数-宣言 ************************/
static String generateText(float value);
static int calculateDigit(float present_value);
/***** 公開関数 ***********************************************/
/****************************************************
 * 関数名　：displayLcd
 * 機能　　：LCDを制御、表示
 * 引数　　：[float] display_value
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
void displayLcd(float display_value)
{
  String text;
  /* 表示用文字列を生成 */
  text = generateText(display_value);
  
  static bool setup = false;
  /* LCD 初期設定(初めの１回限り) */
  if(setup == false) { 
    lcd.begin(16, 2);
    setup = true;
  }
  
  /* LCD 表示 */
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text); 
  wait(20);

}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：generateText
 * 機能　　：文字列を生成(編集)
 * 引数　　：[float] value
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
static String generateText(float value)
{
  String text;
  int digit = 0;

  digit = calculateDigit(value);

  /* 整数部は最大8桁、 小数部は整数込み全7桁まで */
  switch(digit) {
    case 0: text = String( value, 6); break;
    case 1: text = String( value, 6); break;
    case 2: text = String( value, 5); break;
    case 3: text = String( value, 4); break;
    case 4: text = String( value, 3); break;
    case 5: text = String( value, 2); break;
    case 6: text = String( value, 2); break;
    case 7: text = String( value, 1); break;
    case 8: text = String( value, 0); break;
  }
  
  return(text);
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：calculateDigit
 * 機能　　：桁数を計算
 * 引数　　：[float] present_value
 * 戻り値　：[int] digit
 * 備考　　：
 ***************************************************/
static int calculateDigit(float present_value)
{
  int digit = 0;
  long value;
  value = present_value;

  while (value > 0) {
    value /= 10;
    digit += 1;
  }
  
  return(digit);
}
