<< 共用ファイル >> <br>
・Common.h        (共用変数や構造体などの定義) <br>
・AnalSwitch.ino  (スイッチ状態分析) <br>
・Reset.ino       (既存数値のリセット) <br>
・Wait.ino        (millis()を使い,引数ms で待つ) <br> 

******************************************************************************************* <br> 

<<< BOSS: 四則演算電卓 >>>  FourArithCalcuator  
┃  
┣━━ < 制御 SW 入力判定 > JudgCtlSw  {他関数:analCtlSignal}  
┃&emsp;   judgCtlSw()  &emsp;   return( [CtlState_t] ctl_state )  
┃  
┣━━ < 数値 SW 入力判定 > JudgNumSw {他関数:rstDecFrag, analNumSignal}  
┃&emsp;   judgNumSw( [Control_t] ctl_mode )  &emsp;   return( [NumState_t] num_state )  
┃  
┣━━ < 演算 SW 入力判定 > JudgOpeSw {他関数:analOpeSignal}  
┃&emsp;   judgOpeSw()  &emsp;   return( [OpeState_t] ope_state )  
┃  
┣━ << 演算管理 >> CalcManager {他関数:rstCalc, updFirst, startCalc, endCalc}  
┃  ┃&emsp;   calcManager( [NumState_t] num_state, [OpeState_t] ope_state)  
┃  ┃&emsp;&emsp;   return( [float] display_value )  
┃  ┃  
┃  ┣━ < 現在値更新 > UpdateValue {他関数:rstDecDigit}  
┃  ┃&emsp;   updateValue( [NumState_t] num_state, [float] upd_value)  
┃  ┃&emsp;&emsp;   return( [float] input_number )   
┃  ┃  
┃  ┗━ < 四則演算 > FourArith  
┃&emsp;   fourArith( [Operator_t] ope_mode, [float] first_operand, [float] second_operand) 
┃  ┃&emsp;&emsp;   return( [float] value )  
┃  
┗━ << LCD 表示 >> DisplayLcd {他関数:generateText, caculateDigit}  
&emsp;   displayLcd( [float] display_value )  
