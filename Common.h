
#pragma once
/****************************************************
 * ファイル名　：Common.h　
 * 役割　　　　：グローバル共有
 * 作成日　　　：2024.02.04
 ***************************************************/

/**** ※最重要考慮事項 *******************************
 * 7桁以上だとバグが発生する
 * operator という名前の変数は使えない
 ***************************************************/

/* LCDライブラリなど用意 */
#include <I2CLiquidCrystal.h>
#include <Wire.h>
I2CLiquidCrystal lcd(63,(bool)true);

/* スイッチ状態用 */
#define ON 1
#define OFF 0

/* 被演算子分類用 */
#define FIRST  1
#define SECOND 2

/****************************************************
 * 入力用pin 情報
 ***************************************************/
/* 数値-入力用ピン */
#define NOMBER 0
#define HOW_MANY_NUMBER_PIN 10  // 数値入力用(赤)PIN 数
int g_number_pin[ HOW_MANY_NUMBER_PIN] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

/* 制御値-入力用ピン */
#define CONTROL 1
#define HOW_MANY_CONTROL_PIN 2  // 制御値入力用(黄)PIN 数
int g_control_pin[ HOW_MANY_CONTROL_PIN] = { 12, 13};

/* 演算子-入力用ピン */
#define OPERATOR 2
#define HOW_MANY_OPERATOR_PIN 4  // 演算子入力用(緑))PIN 数
int g_operator_pin[ HOW_MANY_OPERATOR_PIN] = { 14, 15, 16, 17};  

/****************************************************
 * モード管理用 型定義-
 ***************************************************/
/***** 数値モード *****/
typedef enum {
  eINT_NUM,
  eDEC_NUM,
} Number_t;

typedef struct {
  bool      frag;
  Number_t  mode;
  int       num;
} NumState_t;

/***** 制御モード *****/
typedef enum {
  eNULL_CTL,
  eDECIMAL,
  eRESET,
} Control_t;

typedef struct {
  bool       frag;
  Control_t  mode;
} CtlState_t;

/***** 演算子モード *****/
typedef enum {
  eNULL_OPE,
  eADD,
  eSUB,
  eMUL,
  eDIV,
  eEND,
} Operator_t;

typedef struct {
  bool      frag;
  Operator_t  mode;
} OpeState_t;
