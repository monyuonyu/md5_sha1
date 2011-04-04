/*
 * main.c
 *
 *  Created on: 2011/04/04
 *      Author: pino
 */


#include <stdio.h>
#include <time.h>
#include <string.h>
#include "md5.h"
#include "sha1.h"

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


