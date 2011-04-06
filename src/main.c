/*
 * main.c
 *
 *  Created on: 2011/04/04
 *      Author: pino
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "md5.h"
#include "sha1.h"

char* getpass_1()
{
	int i;
	static char buf[128] =
	{ 0, };

	printf("\n%s", "UNIX password: ");
	i = 0;
	while (1)
	{
		buf[i] = getch();
		if (buf[i] == 0x0d)
		{
			buf[i] = 0x00;
			break;
		}
		i++;
		printf("*");
	}

	return buf;
}

char* getpass_2()
{
	int i, ii, iii;
	static char buf[2][128] ={{ 0, } };

	for(iii= 0; iii < 3; iii++)
	{
		const char *str[] =
		{ "UNIX password: ", "Retype UNIX password:" };

		// パスワードを二回入力
		for (ii = 0; ii < 2; ii++)
		{
			printf("\n%s", str[ii]);
			i = 0;
			while (1)
			{
				buf[ii][i] = getch();
				if (buf[ii][i] == 0x0d)
				{
					buf[ii][i] = 0x00;
					break;
				}
				i++;
				printf("*");
			}
		}

		// 比較
		if (strcmp(buf[0], buf[1]))
		{
			printf("\nDoes not match!!\n");
			continue;
		}

		return buf[0];
	}
	exit(0);
}

int main(int argc, char *argv[])
{


	if(!(argc > 1))
		return 0;

	switch (strlen(argv[1]))
	{
	case 2:
//		if (argc > 2)
			switch (argv[1][1])
			{
			case 'm':
				printf("\nMD5pass -> %s\n", tomd5(getpass_1()));
				break;
			case 's':
				printf("\nSHA1pass -> %s\n", tosha1(getpass_1()));
				break;
			}
		break;
	case 3:
		if (argv[1][1] == 'c')
			switch (argv[1][2])
			{
			case 'm':
				printf("\ngenerated MD5pass -> %s", tomd5(getpass_2()));
				break;

			case 's':
				printf("\ngenerated SHA1pass -> %s", tosha1(getpass_2()));
				break;

			}
		break;
	}

	return (0);
}
