<< 共用ファイル >>
・Common.h        (共用変数や構造体などの定義)
・AnalSwitch.ino  (スイッチ状態分析)
・Reset.ino       (既存数値のリセット)
・Wait.ino        (millis()を使い,引数ms で待つ)

*******************************************************************************************

<<< BOSS: 四則演算電卓 >>>  FourArithCalcuator
┃
┣━━ < 制御 SW 入力判定 > JudgCtlSw  {他関数:analCtlSignal}
┃        judgCtlSw()  return( [CtlState_t] ctl_state )
┃
┣━━ < 数値 SW 入力判定 > JudgNumSw {他関数:rstDecFrag, analNumSignal}
┃        judgNumSw( [Control_t] ctl_mode )  return( [NumState_t] num_state )
┃
┣━━ < 演算 SW 入力判定 > JudgOpeSw {他関数:analOpeSignal}
┃        judgOpeSw()  return( [OpeState_t] ope_state )
┃
┣━ << 演算管理 >> CalcManager {他関数:rstCalc, updFirst, startCalc, endCalc}
┃  ┃       calcManager( [NumState_t] num_state, [OpeState_t] ope_state)  
┃  ┃                                           return( [float] display_value ) 
┃  ┃
┃  ┣━ < 現在値更新 > UpdateValue {他関数:rstDecDigit}
┃  ┃       updateValue( [NumState_t] num_state, [float] upd_value)
┃  ┃                                           return( [float] input_number ) 
┃  ┃
┃  ┗━ < 四則演算 > FourArith
┃           fourArith( [Operator_t] ope_mode, [float] first_operand, [float] second_operand)
┃                                           return( [float] value )
┃
┗━ << LCD 表示 >> DisplayLcd {他関数:generateText, caculateDigit}
         displayLcd( [float] display_value )
