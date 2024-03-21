/****************************************************
 * ファイル名　：UpdateValue.ino　
 * 役割　　　　：現在値を更新
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"  

/***** ファイル内グローバル変数 *******************/
int   decimal_digit  = 0;

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：updateValue
 * 機能　　：現在値を更新
 * 引数　　：[NumState_t] num_state, [float] upd_value
 * 戻り値　：[float] upd_value 
 * 備考　　：
  ***************************************************/
float updateValue( NumState_t num_state, float upd_value) 
{
  int i;
  float input_number;

  /* 入力数値を取得 */
  input_number = num_state.num;

  /* 整数入力モード時の処理 */
  if (num_state.mode == eINT_NUM) {
    upd_value = upd_value*10 + input_number;
  }
  
  /* 小数入力モード時の処理 */
  else {
    decimal_digit += 1;

    for( i = 0; i < decimal_digit; i++) {
      input_number /= 10;
    }
    upd_value += input_number;
  }

  /* 都合の良い桁で制限 & オーバーフロー対策 */
  if (upd_value >= 99999999.999999 || upd_value < 0) { upd_value = 99999999.999999; }
  return(upd_value);
}

/****************************************************
 * 関数名　：rstDecDigit
 * 機能　　：decimal_digitを初期化
 * 引数　　：なし
 * 戻り値　：なし
 * 備考　　：
  ***************************************************/
void rstDecDigit(void)
{
  decimal_digit = 0;
}
