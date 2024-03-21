/****************************************************
 * ファイル名　：JudgCtlSw.ino
 * 役割　　　　：制御スイッチ状態を判定
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"  

/***** 非公開関数-定義 ******************************/
static Control_t analCtlSignal(void);

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：judgCtlSw
 * 機能　　：制御スイッチ状態を判定
 * 引数　　：なし
 * 戻り値　：[CtlState_t] ctl_state
 * 備考　　：
 ***************************************************/
CtlState_t judgCtlSw(void)
{
  CtlState_t ctl_state;

  /* 状態リセット */
  ctl_state.frag = OFF;
  ctl_state.mode  = eNULL_CTL;

  /* スイッチ状態確認 */
  ctl_state.frag = analSwitch( CONTROL, HOW_MANY_CONTROL_PIN, g_control_pin);

  if (ctl_state.frag == ON) {
    /* 信号分析(読取・変換) */
    ctl_state.mode = analCtlSignal();
  }

  return(ctl_state);
}

/***** 非公開関数 ***********************************************/
/****************************************************
 * 関数名　：analCtlSignal
 * 機能　　：信号内容分析
 * 引数　　：なし
 * 戻り値　：[Control_t] mode
 * 備考　　：
 ***************************************************/
static Control_t analCtlSignal(void)
{
  int i;
  Control_t mode;
  bool ctl_signal[2] = {OFF,OFF};
  /* 信号読み取り */
  for( i = 0; i < HOW_MANY_CONTROL_PIN; i++) {
    ctl_signal[i] = digitalRead( g_control_pin[i] );
  }

  /* 制御値読み取り */
  if      (ctl_signal[0] == ON) { mode = eDECIMAL; }
  else if (ctl_signal[1] == ON) { mode = eRESET;   }
  else { mode = eNULL_CTL; }  /* とりあえず0(増やすときはこれを使う) */

  return(mode);
}