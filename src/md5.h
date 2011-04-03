/*
 * md5.h
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

#ifndef MD5_H_
#define MD5_H_

#include "global.h"


/* MD5.H - MD5C.C�p�w�b�_�t�@�C��
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

[��Ғ�:�ȉ��͏�̕��͂����ɖ󂵂����̂ł��萳���Ȍ��͂����̂͏�̉p��
�̕��͂ł��B]

���̃\�t�g�܂��͊֐��ɂ��ďq�ׂ�������͎Q�l�����Ƃ��ĕt����S�Ă̎�
���ɂ����Ă��ꂪ�uRSA�f�[�^�Z�L�����e�B�� MD5���b�Z�[�W�v��A���S���Y
���v�Ɩ��炩�ɂ���Ă���ꍇ�Ɍ���A���̃\�t�g�𕡐��E�g�p���郉�C�Z��
�X����������B

�񎟒��앨�ɂ��ďq�ׂ�������͎Q�l�����Ƃ��ĕt����S�Ă̎����ɂ�����
���̒��앨���uRSA�f�[�^�Z�L�����e�B�� MD5���b�Z�[�W�v��A���S���Y����
�R�����Ă���v�Ɩ��炩�ɂ���Ă���ꍇ�Ɍ���A�񎟒��앨�̍쐬�E�g�p��
�郉�C�Z���X����������B

RSA�f�[�^�Z�L�����e�B�Ђ͂��̃\�t�g�̏��i���������͂��̃\�t�g�̓����
�I�ւ̓K�����Ɋւ��邢���Ȃ�\�����s��Ȃ��B����͖����E�Öق��킸��
���Ȃ�ۏ؂��Ȃ��u���̂܂܁v�̏�ԂŔz�z�����B

���̕��������(��������)�\�t�g�̂����Ȃ镔���̕������ɂ������̒��ӏ�
����������Ă��Ȃ���΂Ȃ�Ȃ��B
 */

/* MD5�R���e�L�X�g */
typedef struct {
  UINT4 state[4];                                     /* ���(ABCD) */
  UINT4 count[2];         /* 2^64��@�Ƃ����r�b�g��(���ʃr�b�g����) */
  unsigned char buffer[64];                 /* ���̓f�[�^�̃o�b�t�@ */
} MD5_CTX;

void MD5Init PROTO_LIST ((MD5_CTX *));
void MD5Update PROTO_LIST((MD5_CTX *, unsigned char *, unsigned int));
void MD5Final PROTO_LIST ((unsigned char [16], MD5_CTX *));


#endif /* MD5_H_ */
