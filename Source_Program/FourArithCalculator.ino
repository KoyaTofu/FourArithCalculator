/****************************************************
 * ファイル名　：[BOSS]FourArithCalcuator.ino
 * 役割　　　　：全ファイル総括boss(setup,loop)
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/***** 公開関数 ***********************************************/
/****************************************************
 * setup
 ***************************************************/
void setup() {
  /***** 入力ピン設定 *******************************/
  int i;
  /* 制御ブロック */
  for( i = 0; i < HOW_MANY_CONTROL_PIN; i++) {
    pinMode(g_control_pin[i], INPUT);
  }
  /* 数値ブロック */
  for( i = 0; i < HOW_MANY_NUMBER_PIN; i++) {
    pinMode(g_number_pin[i], INPUT);
  }
  /* 演算ブロック */
  for( i = 0; i < HOW_MANY_OPERATOR_PIN; i++) {
    pinMode(g_operator_pin[i], INPUT);
  }

  /***** デバック用　シリアルポートを有効化 ***********/
  Serial.begin(9600);
  Serial.println("start!!");
}

/****************************************************
 * loop
 ***************************************************/
void loop() {
  CtlState_t ctl_state;
  NumState_t num_state;
  OpeState_t ope_state;
  static float display_value = 0;
  
  /***** 入力信号・モード管理 ************************/
  /* 制御sw判定 */
  ctl_state = judgCtlSw();
  /* 数値sw判定 */
  num_state = judgNumSw(ctl_state.mode);
  /* 演算sw判定 */
  ope_state = judgOpeSw();

  /* リセットスイッチが押されたらリセット*/
  if (ctl_state.frag == ON && ctl_state.mode == eRESET) {
    reset(); 
    display_value = 0;
   }
   
  /***** 演算処理 ***********************************/
  if (num_state.frag == ON || ope_state.frag == ON) {
    if (ope_state.frag == ON) {
      /* 演算子が押されたら以前の被演算子入力状態をリセット */
      rstDecDigit(); //decimal_digit = 0;  
      rstDecFrag();  //decimal_frag  = 0;
    }
    display_value = calcManager( num_state, ope_state);
  }
  /***** LCD-表示 **********************************/
  displayLcd(display_value);
}
