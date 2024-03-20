/****************************************************
 * ファイル名　：FourArith.ino　
 * 役割　　　　：四則演算
 * 作成日　　　：2024.02.04
 ***************************************************/
/*** 利用ファイルのヘッダ ***/
#include "Common.h"  

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：fourArith
 * 機能　　：四則演算
 * 引数　　：[Operator_t] ope_mode, [float] first_operand, [float] second_operand)
 * 戻り値　：[float] value
 * 備考　　：
  ***************************************************/
float fourArith( Operator_t ope_mode, float first_operand, float second_operand)
{
  float value = 0;
  if      (ope_mode == eADD) { value = first_operand + second_operand; }
  else if (ope_mode == eSUB) { value = first_operand - second_operand; }
  else if (ope_mode == eMUL) { value = first_operand * second_operand; }
  else if (ope_mode == eDIV) { value = first_operand / second_operand; }
  
  return(value);
}