/*
 * md5.h
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

#ifndef MD5_H_
#define MD5_H_

#include "global.h"


/* MD5.H - MD5C.C用ヘッダファイル
 */

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.

[訳者注:以下は上の文章を仮に訳したものであり正式な効力を持つのは上の英語
の文章です。]

このソフトまたは関数について述べるもしくは参考資料として付ける全ての資
料においてそれが「RSAデータセキュリティ社 MD5メッセージ要約アルゴリズ
ム」と明らかにされている場合に限り、このソフトを複製・使用するライセン
スを許諾する。

二次著作物について述べるもしくは参考資料として付ける全ての資料において
その著作物が「RSAデータセキュリティ社 MD5メッセージ要約アルゴリズムに
由来している」と明らかにされている場合に限り、二次著作物の作成・使用す
るライセンスを許諾する。

RSAデータセキュリティ社はこのソフトの商品性もしくはこのソフトの特定目
的への適合性に関するいかなる表明も行わない。これは明示・暗黙を問わずい
かなる保証もない「そのまま」の状態で配布される。

この文書および(もしくは)ソフトのいかなる部分の複製物にもこれらの注意書
きが書かれていなければならない。
 */

/* MD5コンテキスト */
typedef struct {
  UINT4 state[4];                                     /* 状態(ABCD) */
  UINT4 count[2];         /* 2^64を法としたビット数(下位ビットが先) */
  unsigned char buffer[64];                 /* 入力データのバッファ */
} MD5_CTX;

void MD5Init PROTO_LIST ((MD5_CTX *));
void MD5Update PROTO_LIST((MD5_CTX *, unsigned char *, unsigned int));
void MD5Final PROTO_LIST ((unsigned char [16], MD5_CTX *));


#endif /* MD5_H_ */
