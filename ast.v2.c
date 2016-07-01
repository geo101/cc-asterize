/* 

   To Compile : 
   
   Nav to : E:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts
   Run "Developer Command Prompt for VS2013"
   cl ast.c
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char * cCard = argv[1];
	char * cDigits = "0123456789";
	int i = 0, j = 0, nLen = 0, nMaxChr = 25;
	int nCCLen = 0;
	char * cChar = malloc(2);
	char * cCharPos;
	char cRet[26] = "****************         \0";

	nLen = strlen(cCard);
	nCCLen = atoi(argv[2]);

	if (nLen > 420){
		printf("cclast4: parm too long\n");
		return 1;
	}

	cChar = " ";

	for(i=0;i<nMaxChr;i++){
		if (i<nLen){
			cCharPos =  strchr(cDigits, cCard[i]);
			if (cCharPos != NULL){
				cChar =  strncpy(cChar, cCharPos, 1);
				j++;
				if ((j > nCCLen - 4) && (j <= nCCLen)){
					cRet[j-1] = (char)cChar[0];
				}
			}
		} else  {
			cRet[i] = ' ';
		}
	}

	if (j != nCCLen){
		for (i=0;i<nMaxChr;i++){
			cRet[i] = ' ';
		}
		printf("cclast4 : cc # length wrong at %i\n", j);
		return 1;
	}

	strcpy(argv[1], cRet);
	printf("[%s]\n", cRet);

	return 0;
}
