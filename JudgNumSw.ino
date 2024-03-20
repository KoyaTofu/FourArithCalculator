/****************************************************
 * ファイル名　：JudgNumSw.ino
 * 役割　　　　：数値スイッチ状態を判定
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"  

/***** ファイル内グローバル変数 **********************/
bool decimal_frag = false;  /* rstNumFrag理由でグローバル */

/***** 非公開関数-定義 ******************************/
static int analNumSignal(void);

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：judgNumSw
 * 機能　　：数値スイッチ状態を判定
 * 引数　　：[Control_t] ctl_mode
 * 戻り値　：[NumState_t] num_state
 * 備考　　：
 ***************************************************/
NumState_t judgNumSw( Control_t ctl_mode)
{
  NumState_t num_state;

  /* 状態リセット */
  num_state.frag = OFF;
  num_state.mode = eINT_NUM;
  num_state.num  = 0;

  /* 1度でも押されればその後はrstNumFrag()されるまで少数入力モード */
  if (ctl_mode == eDECIMAL) { decimal_frag = true; }
  if (decimal_frag == true) { num_state.mode = eDEC_NUM; }

  /* スイッチ状態確認 */
  num_state.frag = analSwitch( NOMBER, HOW_MANY_NUMBER_PIN, g_number_pin);

  if (num_state.frag == ON) {
    /* 信号分析(読取・変換) */
    num_state.num = analNumSignal();
  }
  return(num_state);
}

 /****************************************************
 * 関数名　：rstNumFrag
 * 機能　　：数値ブロックの状態をリセット
 * 引数　　：なし
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
void rstDecFrag(void)
{ decimal_frag = false; }

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：analNumSignal
 * 機能　　：信号内容分析
 * 引数　　：なし
 * 戻り値　：[int] number
 * 備考　　：
 ***************************************************/
static int analNumSignal(void)
{
  int i;
  int number;
  bool num_signal[10] = {OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF};
  /* 信号読み取り */
  for( i = HOW_MANY_NUMBER_PIN - 1; i >= 0; i--) {
    num_signal[i] = digitalRead( g_number_pin[i] );
  }

  /* 10進数に読み取り・変換 */
  if      (num_signal[0] == ON ) { number = 0; }
  else if (num_signal[1] == ON ) { number = 1; }
  else if (num_signal[2] == ON ) { number = 2; }
  else if (num_signal[3] == ON ) { number = 3; }
  else if (num_signal[4] == ON ) { number = 4; }
  else if (num_signal[5] == ON ) { number = 5; }
  else if (num_signal[6] == ON ) { number = 6; }
  else if (num_signal[7] == ON ) { number = 7; }
  else if (num_signal[8] == ON ) { number = 8; }
  else if (num_signal[9] == ON ) { number = 9; }
  else { number = 0; }  /* とりあえず0(増やすときはこれを使う) */

  return(number);
}