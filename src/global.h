/*
 * global.h
 *
 *  Created on: 2011/04/01
 *      Author: mizu
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_


/* GLOBAL.H - RSAREF 型と定数
 */

/* コンパイラーが関数の引数プロトタイプをサポートしている場合は、
   PROTOTYPESを1にするべきである。
次はもしPROTOTYPESが既にCコンパイラフラグで定義されていない場合に、
  初期値を0にするものである。
 */
#ifndef PROTOTYPES
#define PROTOTYPES 1
#endif

/* POINTERを汎用ポインタ型と定義する */
typedef unsigned char *POINTER;

/* UINT2を2バイトワードと定義する */
typedef unsigned short int UINT2;

/* UINT4を4バイトワードと定義する */
typedef unsigned long int UINT4;

/* PROTO_LISTはPROTOTYPESが上でどう定義されたかに依存して定義される。
PROTOTYPESを使う場合はPROTO_LISTはリストを返し、
　そうでない場合は空のリストを返す。
 */
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif


#endif /* GLOBAL_H_ */
