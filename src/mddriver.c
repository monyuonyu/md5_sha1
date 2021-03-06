/*
 * mddriver.c
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

/* MDDRIVER.C - MD2,MD4,MD5用のテストドライバー
 */

/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All
rights reserved.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.

 */

/* Cコンパイラフラグによって定義されていない場合は下記によりMDの初期値
  はMD5にされる。
 */
#ifndef MD
#define MD 5
#endif

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "global.h"

#if MD == 2
#include "md2.h"
#endif
#if MD == 4
#include "md4.h"
#endif
#if MD == 5
#include "md5.h"
#endif

/* テストブロックの長さ、テストブロックの数
 */
#define TEST_BLOCK_LEN 1000
#define TEST_BLOCK_COUNT 1000

void MDString PROTO_LIST ((char *));
//static void MDPrint PROTO_LIST ((unsigned char [16]));

#if MD == 2
#define MD_CTX MD2_CTX
#define MDInit MD2Init
#define MDUpdate MD2Update
#define MDFinal MD2Final
#endif
#if MD == 4
#define MD_CTX MD4_CTX
#define MDInit MD4Init
#define MDUpdate MD4Update
#define MDFinal MD4Final
#endif
#if MD == 5
#define MD_CTX MD5_CTX
#define MDInit MD5Init
#define MDUpdate MD5Update
#define MDFinal MD5Final
#endif

/* メインドライバー

Arguments (may be any combination):
  -sstring - digests string
  -t       - runs time trial
  -x       - runs test script
  filename - digests file
  (none)   - digests standard input
 */
//int main(int argc, char *argv[])
//{
//	int cnt;
//
//	if (argc > 1)
//		for (cnt = 1; cnt < argc; cnt++)
//		{
//			MDString(argv[cnt]);
//		}
//
//	return (0);
//}

/* 文字列を要約し結果を出力する
 */
char* tomd5(char *string)
{
	unsigned int cnt;
	static char buf[33] = {0,};

	MD_CTX context;
	unsigned char digest[16];
	unsigned int len = strlen(string);

	MDInit(&context);
	MDUpdate(&context, string, len);
	MDFinal(digest, &context);

	for (cnt = 0; cnt < 16; cnt++)
		sprintf(&buf[cnt * 2], "%02X", digest[cnt]);

	for(cnt = 0; cnt < 32; cnt++)
		buf[cnt] = tolower(buf[cnt]);


//	printf("MD%d (\"%s\") = ", MD, string);
//	MDPrint(digest);
//	printf("\n");

	return buf;
}


/* 16進法でメッセージ要約を出力する
 Prints a message digest in hexadecimal.
 */
//static void MDPrint(unsigned char digest[16])
//{
//
//	unsigned int cnt;
//
//	for (cnt = 0; cnt < 16; cnt++)
//		printf("%02x", digest[cnt]);
//}
