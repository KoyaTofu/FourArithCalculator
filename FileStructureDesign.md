<< 共用ファイル >>  
・Common.h        (共用変数や構造体などの定義)  
・AnalSwitch.ino  (スイッチ状態分析)  
・Reset.ino       (既存数値のリセット)  
・Wait.ino        (millis()を使い,引数ms で待つ)   

*******************************************************************************************   

<<< BOSS: 四則演算電卓 >>>  FourArithCalcuator  
┃  
┣━━ < 制御 SW 入力判定 > JudgCtlSw &emsp; {他関数:analCtlSignal}  
┃&emsp;&emsp; judgCtlSw()&emsp; return( [CtlState_t] ctl_state )  
┃  
┣━━ < 数値 SW 入力判定 > JudgNumSw &emsp; {他関数:rstDecFrag, analNumSignal}  
┃&emsp;&emsp; judgNumSw( [Control_t] ctl_mode ) &emsp; return( [NumState_t] num_state )  
┃  
┣━━ < 演算 SW 入力判定 > JudgOpeSw &emsp; {他関数:analOpeSignal}  
┃&emsp;&emsp; judgOpeSw() &emsp; return( [OpeState_t] ope_state )  
┃  
┣━ << 演算管理 >> CalcManager &emsp; {他関数:rstCalc,&nbsp; updFirst,&nbsp; startCalc,&nbsp; endCalc}  
┃&emsp;┃&emsp;&emsp; calcManager( [NumState_t] num_state,&nbsp; [OpeState_t] ope_state)  
┃&emsp;┃&emsp;&emsp;&emsp;&emsp; return( [float] display_value )  
┃&emsp;┃  
┃&emsp;┣━ < 現在値更新 > UpdateValue &emsp; {他関数:rstDecDigit}  
┃&emsp;┃&emsp;&emsp; updateValue( [NumState_t] num_state,&nbsp; [float] upd_value)  
┃&emsp;┃&emsp;&emsp;&emsp;&emsp; return( [float] input_number )   
┃&emsp;┃  
┃&emsp;┗━ < 四則演算 > FourArith  
┃&emsp;&emsp;&emsp;   fourArith( [Operator_t] ope_mode,&nbsp; [float] first_operand,&nbsp; [float] second_operand)  
┃&emsp;&emsp;&emsp;&emsp;&emsp; return( [float] value )  
┃  
┗━ << LCD 表示 >> DisplayLcd&emsp; {他関数:generateText,&nbsp; caculateDigit}  
&emsp;&emsp; displayLcd( [float] display_value )  
