/*
 * mddriver.c
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

/* MDDRIVER.C - MD2,MD4,MD5�p�̃e�X�g�h���C�o�[
 */

/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All
rights reserved.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.

[��Ғ�:�ȉ��͏�̕��͂����ɖ󂵂����̂ł��萳���Ȍ��͂����̂͏�̉p��
�̕��͂ł��B]

RSA�f�[�^�Z�L�����e�B�Ђ͂��̃\�t�g�̏��i���������͂��̃\�t�g�̓����
�I�ւ̓K�����Ɋւ��邢���Ȃ�\�����s��Ȃ��B����͖����E�Öق��킸��
���Ȃ�ۏ؂��Ȃ��u���̂܂܁v�̏�ԂŔz�z�����B

���̕��������(��������)�\�t�g�̂����Ȃ镔���̕������ɂ������̒��ӏ�
����������Ă��Ȃ���΂Ȃ�Ȃ��B
 */

/* C�R���p�C���t���O�ɂ���Ē�`����Ă��Ȃ��ꍇ�͉��L�ɂ��MD�̏����l
  ��MD5�ɂ����B
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

/* �e�X�g�u���b�N�̒����A�e�X�g�u���b�N�̐�
 */
#define TEST_BLOCK_LEN 1000
#define TEST_BLOCK_COUNT 1000

static void MDString PROTO_LIST ((char *));
//static void MDTimeTrial PROTO_LIST ((void));
//static void MDTestSuite PROTO_LIST ((void));
//static void MDFile PROTO_LIST ((char *));
//static void MDFilter PROTO_LIST ((void));
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

/* ���C���h���C�o�[

Arguments (may be any combination):
  -sstring - digests string
  -t       - runs time trial
  -x       - runs test script
  filename - digests file
  (none)   - digests standard input
 */
int main(argc, argv)
	int argc;char *argv[];
{
	int cnt;

	if (argc > 1)
		for (cnt = 1; cnt < argc; cnt++)
		{
			MDString(argv[cnt]);
		}

	return (0);
}

/* �������v�񂵌��ʂ��o�͂���
 */
static void MDString(string)
	char *string;
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

/* TEST_BLOCK_COUNT��TEST_BLOCK_LEN�o�C�g�u���b�N��v�񂷂鎞�Ԃ��v��
 */
//static void MDTimeTrial()
//{
//	MD_CTX context;
//	time_t endTime, startTime;
//	unsigned char block[TEST_BLOCK_LEN], digest[16];
//	unsigned int i;
//
//	printf("MD%d time trial. Digesting %d %d-byte blocks ...", MD,
//			TEST_BLOCK_LEN, TEST_BLOCK_COUNT);
//
//	/* Initialize block */
//	for (i = 0; i < TEST_BLOCK_LEN; i++)
//		block[i] = (unsigned char) (i & 0xff);
//
//	/* Start timer */
//	time(&startTime);
//
//	/* Digest blocks */
//	MDInit(&context);
//	for (i = 0; i < TEST_BLOCK_COUNT; i++)
//		MDUpdate(&context, block, TEST_BLOCK_LEN);
//	MDFinal(digest, &context);
//
//	/* Stop timer */
//	time(&endTime);
//
//	printf(" done\n");
//	printf("Digest = ");
//	MDPrint(digest);
//	printf("\nTime = %ld seconds\n", (long) (endTime - startTime));
//	printf("Speed = %ld bytes/second\n", (long) TEST_BLOCK_LEN
//			* (long) TEST_BLOCK_COUNT / (endTime - startTime));
//}

/* �Q�l�ƂȂ镶����̑g��v�񂵌��ʂ��o�͂���
 */
//static void MDTestSuite()
//{
//	printf("MD%d test suite:\n", MD);
//
//	MDString("");
//	MDString("a");
//	MDString("abc");
//	MDString("message digest");
//	MDString("abcdefghijklmnopqrstuvwxyz");
//	MDString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
//	MDString("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
//}

/* �t�@�C����v�񂵌��ʂ��o�͂���
 */
//static void MDFile(filename)
//	char *filename;
//{
//	FILE *file;
//	MD_CTX context;
//	int len;
//	unsigned char buffer[1024], digest[16];
//
//	if ((file = fopen(filename, "rb")) == NULL)
//		printf("%s can't be opened\n", filename);
//
//	else
//	{
//		MDInit(&context);
//		while (len = fread(buffer, 1, 1024, file))
//			MDUpdate(&context, buffer, len);
//		MDFinal(digest, &context);
//
//		fclose(file);
//
//		printf("MD%d (%s) = ", MD, filename);
//		MDPrint(digest);
//		printf("\n");
//	}
//}

/* �W�����͂�v�񂵌��ʂ��o�͂���
 */
//static void MDFilter()
//{
//	MD_CTX context;
//	int len;
//	unsigned char buffer[16], digest[16];
//
//	MDInit(&context);
//	while (len = fread(buffer, 1, 16, stdin))
//		MDUpdate(&context, buffer, len);
//	MDFinal(digest, &context);
//
//	MDPrint(digest);
//	printf("\n");
//}

/* 16�i�@�Ń��b�Z�[�W�v����o�͂���
 Prints a message digest in hexadecimal.
 */
static void MDPrint(digest)
	unsigned char digest[16];
{

	unsigned int cnt;

	for (cnt = 0; cnt < 16; cnt++)
		printf("%02x", digest[cnt]);
}
