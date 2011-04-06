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

char* tomd5(char *string);

#endif /* MD5_H_ */
