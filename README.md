# Doxygenの出力結果から構造体を帳票に展開するプログラム

## ■要件
過去作成物を晒すプレイ。  
c言語の構造体を、Doxygenの出力結果からExcelに展開する。  
言語はExcel VBAです。  

## ■どういうプログラムか
オフシェアで作られたc言語のプログラムのデータ構造（構造体・共用体）を解析するのに、手動でExcelに展開していたのですが、手間がかかりすぎるため、半自動化としてDoxygenの出力結果を使いExcelに取り込むことようにしてみました。  
階層構造となっている、構造体も展開できます。
それにしてもオフシェアって糞コードしか作らないんですかね？  

  ![doxygen_struct 1](pict\1.jpg)  


（１）ソースの書き方（コメント）  
Doxygenで概略説明タグ<briefdescription>を出力するには、ソースに以下のように記述する。  
- 構造体の説明は、構造体の前に"/\*\* brief"で開始する説明コメントを書く。（/\*\*の後に改行入れてもOK）
- メンバ変数の説明は、メンバ変数の後に"/\*\*<breif"で開始する説明コメントを置く。

読み取りテスト用コード
 ```
#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include "test_define.h"

typedef unsigned long UINT32;	/**< breif Datatype UINT32(unsigned long). */

/** breif Union Test2.	*/
typedef union uTEST2_ {
	unsigned long	ulmember1;		/**<breif uTest2 Member ulmember1. */
	unsigned int	uimember2;		/**<breif uTest2 Member uimember2. */
	unsigned char	ucmember3[5];	/**<breif uTest2 Member ucmember3. */
} uTest2;

/** breif Struct Test1_1.	*/
typedef struct stTEST1_1_ {
	UINT32	ui32test1;		/**<breif test1_1 Member test1. */
	UINT8	ui8Padding[4];	/**<breif test1_1 Member Padding.	*/
	eTEST01 eTest01;		/**<breif test1_1 Member enum Test01.	*/
} stTest1_1;

/** breif Struct Test1.	*/
typedef struct stTEST1_ {
	uTest2	utest2;			/**<breif test1 Member test2. */
	UINT32	ui32test1;		/**<breif test1 Member test1. */
	UINT8	ui8Padding[4];	/**<breif test1 Member Padding.	*/
	stTest1_1	sttest1_1;	/**<breif test1 Member stTest1_1.	*/
	struct stTEST1_ *pNext;	/**<breif test1 Member pNext - Next Pointer. */
} stTest1;


#endif /* TEST_STRUCT_H */
 ```
（２）Doxygenの設定  
BRIEF_MEMBER_DESC、JAVADOC_AUTOBRIEF、GENERATE_XML、XML_OUTPUTに"YES"を設定する。  
Doxygenの使い方はググってください。DoxygenWizardを使えば簡単です。

（３）Doxygen Struct Excelの使い方  
XML出力結果のディレクトリ（index.xmlのあるフォルダ）を指定して、「XML解析」ボタンを押す→構造体名コンボボックスから構造体名を選択、または直接入力して「構造体解析」ボタンを押下。
- 特定の構造体の帳票を作る場合  
構造体名コンボボックスに解析した構造体名一覧が入るので、構造体名を選択して、「構造体展開」ボタンを押下する。
- すべての構造体の帳票を作る場合  
「全体構造体展開」ボタンを押下する。  
構造体の数が多いと時間がかかります。

![doxygen_struct 2](pict\2.jpg)  

出力結果はExcel表としてシートに出力。  
シート名は構造体名。  
すでに同名シートがある場合は削除してから出力（削除確認ダイアログが出ます）

以下、出力結果。  
* 全体構造体展開を実行したときは、「構造体一覧」シートを作成します。  
![doxygen_struct 2](pict\2-1.jpg)  

* 出力結果は、メンバ名（変数）を階層的に出力、データ型、概要説明の順。　　
![doxygen_struct 2](pict\2-2.jpg)  
![doxygen_struct 2](pict\2-3.jpg)  


## ■免責・お願い

本プログラムは、商用利用および個人利用、そして改造を自由に行ってくださってもかまいません。  
ただし、改造したソース・Excelファイルは公開してください。  
利用・改造の連絡は不要です。  
なお、本プログラムの利用によりあなた、またはあなたの周囲に損害が発生しても、 当方は一切関知しません。  
