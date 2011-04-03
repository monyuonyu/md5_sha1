/*
 * global.h
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_


/* GLOBAL.H - RSAREF �^�ƒ萔
 */

/* �R���p�C���[���֐��̈����v���g�^�C�v���T�|�[�g���Ă���ꍇ�́A
   PROTOTYPES��1�ɂ���ׂ��ł���B
���͂���PROTOTYPES������C�R���p�C���t���O�Œ�`����Ă��Ȃ��ꍇ�ɁA
  �����l��0�ɂ�����̂ł���B
 */
#ifndef PROTOTYPES
#define PROTOTYPES 1
#endif

/* POINTER��ėp�|�C���^�^�ƒ�`���� */
typedef unsigned char *POINTER;

/* UINT2��2�o�C�g���[�h�ƒ�`���� */
typedef unsigned short int UINT2;

/* UINT4��4�o�C�g���[�h�ƒ�`���� */
typedef unsigned long int UINT4;

/* PROTO_LIST��PROTOTYPES����łǂ���`���ꂽ���Ɉˑ����Ē�`�����B
PROTOTYPES���g���ꍇ��PROTO_LIST�̓��X�g��Ԃ��A
�@�����łȂ��ꍇ�͋�̃��X�g��Ԃ��B
 */
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif


#endif /* GLOBAL_H_ */
