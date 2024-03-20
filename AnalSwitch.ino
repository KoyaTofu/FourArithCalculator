/****************************************************
 * ファイル名　：AnalSwitch.ino　
 * 役割　　　　：スイッチからの信号を取得しフラグを立てる
 * 作成日　　　：2024.02.04
 * 分類　　　　：共用
 ***************************************************/
/*** 利用ファイルのヘッダ ***/

/***** 非公開関数宣言 *******************************/
static bool chattering( int , int*);
static bool analPush( int , int*);

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：analSwitch
 * 機能　　：スイッチのON-OFF切り替わり判定
 * 引数　　：[int] brock, [int] num, [int*] pin ( 読み取り対象pin-識別ブロック番号,pin本数,pin位置 )
 * 戻り値　：[bool] frag 
 * 備考　　：
 ***************************************************/
bool analSwitch( int brock, int num, int* pin) 
{
  bool frag = OFF;
  static bool old_sw[3] = {OFF, OFF, OFF};
  static bool new_sw[3] = {OFF, OFF, OFF};

  new_sw[brock] = chattering( num, pin);

  if (old_sw[brock] == OFF && new_sw[brock] == ON) {
    frag = ON;
  }
  old_sw[brock] = new_sw[brock];
 
  return(frag);
}

/***** 非公開関数 **********************************************/
/****************************************************
 * 関数名　：chattering
 * 機能　　：スイッチの状態を確認
 * 引数　　：[int] num, [int*] pin ( 読み取り対象pin-pin本数,pin位置 )
 * 戻り値　：[bool] frag
 * 備考　　：
 ***************************************************/
static bool chattering( int num, int* pin)
{
  bool frag = OFF;

  /* チャタリング対策 */
  if (analPush(num, pin) == ON) {
    wait(1);
    if (analPush(num, pin) == ON) {
      frag = ON;
    }
	}
  return(frag);
}

/****************************************************
 * 関数名　：analPush
 * 機能　　：スイッチが押されたか否か
 * 引数　　：[int] num, [int*] pin ( 読み取り対象pin-pin本数,pin位置 )
 * 戻り値　：[bool]state
 * 備考　　：
 ***************************************************/
static bool analPush( int num, int* pin)
{
  int i;
	bool state = OFF;

  for( i = 0; i < num; i++) {
    if (digitalRead( pin[i]) == 1) {
      state = ON;
    }
  }
  
  return(state);
}