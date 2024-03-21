/****************************************************
 * ファイル名　：JudgOpeSw.ino
 * 役割　　　　：演算子スイッチ状態を判定
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"

/***** 非公開関数-定義 ******************************/
static Operator_t analOpeSignal(void);

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：judgOpeSw
 * 機能　　：演算子スイッチ状態を判定
 * 引数　　：なし
 * 戻り値　：[OpeState_t] ope_state
 * 備考　　：
 ***************************************************/
OpeState_t judgOpeSw()
{
  OpeState_t ope_state;

  /* 状態リセット */
  ope_state.frag = OFF;
  ope_state.mode = eNULL_OPE;

  /* スイッチ状態確認 */
  ope_state.frag = analSwitch( OPERATOR, HOW_MANY_OPERATOR_PIN, g_operator_pin);

  if (ope_state.frag == ON) {
    /* 信号分析(読取・変換) */
    ope_state.mode = analOpeSignal();
  }
  return(ope_state);
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：analOpeSignal
 * 機能　　：信号内容分析
 * 引数　　：なし
 * 戻り値　：[Operator_t] mode
 * 備考　　：
 ***************************************************/
static Operator_t analOpeSignal(void)
{
  int i;
  Operator_t mode;
  bool ope_signal[4] = {OFF,OFF,OFF,OFF};
  /* 演算スイッチの入力信号を取得 */
  for( i = 0 ; i < HOW_MANY_OPERATOR_PIN ; i++) {
    ope_signal[i] = digitalRead( g_operator_pin[i] );
    
  }

  /* 演算子読み取り */
  if      (ope_signal[0] == ON && ope_signal[3] == ON) { mode = eEND; }
  else if (ope_signal[0] == ON) { mode = eADD; }
  else if (ope_signal[1] == ON) { mode = eSUB; }
  else if (ope_signal[2] == ON) { mode = eMUL; }
  else if (ope_signal[3] == ON) { mode = eDIV; }
  else { mode = eNULL_OPE; }  /* とりあえず0(増やすときはこれを使う) */

  return(mode);
}
