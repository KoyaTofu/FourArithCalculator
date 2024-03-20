/****************************************************
 * ファイル名　：Wait.ino　
 * 役割　　　　：指定時間待つ
 * 作成日　　　：2024.02.04
 * 分類　　　　：共用
 ***************************************************/
/*** 自ファイルのヘッダ ***/

/***** 公開関数 ************************************************/
/****************************************************
 * 関数名　：wait
 * 機能　　：引数(ミリ秒)待つ
 * 引数　　：[int] ms
 * 戻り値　：なし
 * 備考　　：
 ***************************************************/
void wait( unsigned int ms)
{
  unsigned int time_before;

  time_before = millis();

  while(millis()- time_before < ms ) {
    ;
  }
}