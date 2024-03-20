/****************************************************
 * ファイル名　：CalcManager.ino　
 * 役割　　　　：演算処理のスケジューリング管理
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"        

/***** ファイル内グローバル変数 *******************/
float first_operand  = 0;
float second_operand = 0;
int   target         = FIRST;
float upd_value    = 0;

/***** 非公開関数宣言 *******************************/
static void updFirst(void);
static float startCalc(Operator_t);
static float endCalc(Operator_t);

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名  : calcManager
 * 機能　　：演算処理のスケジューリング管理
 * 引数　　：[NumState_t] num_state, [OpeState_t] ope_state
 * 戻り値　：[float] display_value
 * 備考　　：
 ***************************************************/
float calcManager( NumState_t num_state, OpeState_t ope_state)
{
  static float display_value = 0;
  static Operator_t calc_ope = eNULL_OPE;

  if (num_state.frag == ON) {
    /* 現在値-更新指示 */
    upd_value = updateValue( num_state, upd_value);
    display_value = upd_value;
  }
  

  /* 演算子が押されたら */
  if (ope_state.frag == ON) {
    if (ope_state.mode != eEND) {

      if (target == FIRST) { 
        updFirst();
        }

      /* target == SECOND  なら計算開始 */
      else {  
        display_value = startCalc(calc_ope);
        
      }
      calc_ope =  ope_state.mode;
    }

    /* 入力された演算子が「＝(eEND)」の場合、計算を終了・初期化 */
    else {  
      display_value = endCalc(calc_ope);
    }
  }
  
  return(display_value);
}

/****************************************************
 * 関数名　：rstCalc
 * 機能　　：ファイル内グローバル変数を初期化
 * 引数　　：なし
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
void rstCalc(void)
{
  first_operand  = 0;
  second_operand = 0;
  target         = FIRST;
  upd_value    = 0; 
}

/***** 非公開関数 **********************************************/
/****************************************************
 * 関数名　：updFirst
 * 機能　　：現在値をfirst_operandとして確定
 * 引数　　：なし
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
static void updFirst()
{
  first_operand = upd_value; 
  upd_value = 0;
  target = SECOND;
}

/****************************************************
 * 関数名　：startCalc
 * 機能　　：演算を開始
 * 引数　　：[Operator_t] calc_ope
 * 戻り値　：[float] first_operand
 * 備考　　：
 ***************************************************/
static float startCalc( Operator_t calc_ope)
{
  second_operand = upd_value;
  /* 四則演算-計算指示 */
  first_operand = fourArith( calc_ope, first_operand, second_operand);
  upd_value = 0;
  return(first_operand);
}

/****************************************************
 * 関数名　：endCalc
 * 機能　　：演算を終了・初期化
 * 引数　　：[Operator_t] calc_ope
 * 戻り値　：[float] value
 * 備考　　：
 ***************************************************/
static float endCalc( Operator_t calc_ope)
{
  float value = 0;
  second_operand = upd_value;
  /* 四則演算-計算指示 */
  value = fourArith( calc_ope, first_operand, second_operand);
  reset();
  return(value);
}