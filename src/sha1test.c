/*
 * sha1test.c
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
#include "sha1.h"

/*
 *  Define patterns for testing
 */
//#define TEST1   "abc"
//#define TEST2a  "abcdbcdecdefdefgefghfghighijhi"

//#define TEST2b  "jkijkljklmklmnlmnomnopnopq"
//#define TEST2   TEST2a TEST2b
//#define TEST3   "a"
//#define TEST4a  "01234567012345670123456701234567"
//#define TEST4b  "01234567012345670123456701234567"
    /* an exact multiple of 512 bits */
//#define TEST4   TEST4a TEST4b
//char *testarray[4] =
//{
//    TEST1,
//    TEST2,
//    TEST3,
//    TEST4
//};
//long int repeatcount[4] = { 1, 1, 1000000, 10 };
//char *resultarray[4] =
//{
//    "A9 99 3E 36 47 06 81 6A BA 3E 25 71 78 50 C2 6C 9C D0 D8 9D",
//    "84 98 3E 44 1C 3B D2 6E BA AE 4A A1 F9 51 29 E5 E5 46 70 F1",
//    "34 AA 97 3C D4 C4 DA A4 F6 1E EB 2B DB AD 27 31 65 34 01 6F",
//    "DE A3 56 A2 CD DD 90 C7 A7 EC ED C5 EB B5 63 93 4F 46 04 52"
//};

int sha1(char* str)
{
    SHA1Context sha;
//    int i, j, err;
    int i, err;
    uint8_t Message_Digest[20];

    /*
     *  Perform SHA-1 tests
     */
//    for(j = 0; j < 4; ++j)
//    {
//        printf("\nTest %d: %d, '%s'\n", j + 1, repeatcount[j], testarray[j]);
        printf("SHA1 (\"%s\") = ", str);

        err = SHA1Reset(&sha);
        if (err)
        {
            fprintf(stderr, "SHA1Reset Error %d.\n", err );
//            break;    /* out of for j loop */
        }

//        for(i = 0; i < repeatcount[j]; ++i)
//        {

            err = SHA1Input(&sha, (const unsigned char *) str,
					strlen(str));
            if (err)
            {
                fprintf(stderr, "SHA1Input Error %d.\n", err );
//                break;    /* out of for i loop */
            }
//        }

        err = SHA1Result(&sha, Message_Digest);
        if (err)
        {
            fprintf(stderr,
					"SHA1Result Error %d, could not compute message digest.\n",
					err);
        }
        else
        {
//            printf("\t");
            for(i = 0; i < 20 ; ++i)
            {
                printf("%X", Message_Digest[i]);
            }
//            printf("\n");
        }
//        printf("Should match:\n");
//        printf("\t%s\n", resultarray[j]);
        printf("\n");
//    }

    /* Test some error returns */
//    err = SHA1Input(&sha,(const unsigned char *) testarray[1], 1);
//    printf ("\nError %d. Should be %d.\n", err, shaStateError );
//    err = SHA1Reset(0);
//    printf ("\nError %d. Should be %d.\n", err, shaNull );
    return 0;
}
