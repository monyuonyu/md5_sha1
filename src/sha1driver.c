/*
 * sha1test.c
 *
 *  Created on: 2011/04/04
 *      Author: pino
 */

/*
 * Copyright (C) The Internet Society (2001).  All Rights Reserved.

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
 */


/*
 *  sha1test.c
 *
 *  Description:
 *      This file will exercise the SHA-1 code performing the three
 *      tests documented in FIPS PUB 180-1 plus one which calls
 *      SHA1Input with an exact multiple of 512 bits, plus a few
 *      error test checks.
 *
 *  Portability Issues:
 *      None.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "sha1.h"

char* tosha1(char* str)
{
	SHA1Context sha;
	int i, err;
	uint8_t Message_Digest[20];
	static char buf[41] =
	{ 0, };

	err = SHA1Reset(&sha);
	if (err)
	{
		fprintf(stderr, "SHA1Reset Error %d.\n", err);
	}

	err = SHA1Input(&sha, (const unsigned char *) str, strlen(str));
	if (err)
	{
		fprintf(stderr, "SHA1Input Error %d.\n", err);
	}

	err = SHA1Result(&sha, Message_Digest);
	if (err)
	{
		fprintf(stderr,
				"SHA1Result Error %d, could not compute message digest.\n", err);
	}
	else
	{
		for (i = 0; i < 20; ++i)
		{
			sprintf(&buf[i * 2], "%02X", Message_Digest[i]);
		}
	}

	for (i = 0; i < 40; i++)
		buf[i] = tolower(buf[i]);

	return buf;
}
