# FourArithCalculator  
## 【概要】  
基本的な電卓と同様に数値(0～9),演算子(+-×÷),小数点,確定(=),リセット機能の実装。  
基本的な入力信号はダイレクトピン方式を採用。  
ピン本数の問題から確定機能のみダイオードを使用し複合入力。  

## 【開発環境・使用部品】
プログラミング-統合開発環境 : Arduino IDE  
回路設計・シミュレーション : Circuit Simulator Applet (https://www.falstad.com/circuit/)  
マイコン : Arduino Nano  
その他 : LCD(I2C)1個、スイッチ17個、整流用ダイオード2個、1KΩ抵抗17個、10KΩ抵抗２個、ワイヤー  

## 各種 写真  
### 完成写真
![完成写真](https://github.com/KoyaTofu/BidiTranslator/assets/163281871/df986dba-6ee9-4718-9fbe-a2d9363d9d34)  

### ファイル構造設計  
![ファイル構造設計](https://github.com/KoyaTofu/BidiTranslator/assets/163281871/734a73a5-ef52-426a-abff-ae4f04617936)
