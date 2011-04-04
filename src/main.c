/*
 * main.c
 *
 *  Created on: 2011/04/04
 *      Author: pino
 */

/*
Copyright (C) The Internet Society (2001).  All Rights Reserved.

   This document and translations of it may be copied and furnished to
   others, and derivative works that comment on or otherwise explain it
   or assist in its implementation may be prepared, copied, published
   and distributed, in whole or in part, without restriction of any
   kind, provided that the above copyright notice and this paragraph are
   included on all such copies and derivative works.  However, this
   document itself may not be modified in any way, such as by removing
   the copyright notice or references to the Internet Society or other
   Internet organizations, except as needed for the purpose of
   developing Internet standards in which case the procedures for
   copyrights defined in the Internet Standards process must be
   followed, or as required to translate it into languages other than
   English.

   The limited permissions granted above are perpetual and will not be
   revoked by the Internet Society or its successors or assigns.

   This document and the information contained herein is provided on an
   "AS IS" basis and THE INTERNET SOCIETY AND THE INTERNET ENGINEERING
   TASK FORCE DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
   BUT NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION
   HEREIN WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF
   MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

Acknowledgement

   Funding for the RFC Editor function is currently provided by the
   Internet Society.
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

static void MDString PROTO_LIST ((char *));
static void MDPrint PROTO_LIST ((unsigned char [16]));

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
int main(int argc, char *argv[])
{
	int cnt;

	if (argc > 2)
		for (cnt = 2; cnt < argc; cnt++)
		{
			if (argv[1][0] == '-')
				switch (argv[1][1])
				{
				case 'm':
					MDString(argv[cnt]);
					break;
				case 's':
					sha1(argv[cnt]);
					break;
				}
		}

	return (0);
}

/* 文字列を要約し結果を出力する
 */
static void MDString(char *string)
{
	MD_CTX context;
	unsigned char digest[16];
	unsigned int len = strlen(string);

	MDInit(&context);
	MDUpdate(&context, string, len);
	MDFinal(digest, &context);

	printf("MD%d (\"%s\") = ", MD, string);
	MDPrint(digest);
	printf("\n");
}


/* 16進法でメッセージ要約を出力する
 Prints a message digest in hexadecimal.
 */
static void MDPrint(unsigned char digest[16])
{

	unsigned int cnt;

	for (cnt = 0; cnt < 16; cnt++)
		printf("%02x", digest[cnt]);
}
