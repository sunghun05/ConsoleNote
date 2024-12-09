
#define _CRT_SECURE_NO_WARNINGS
#define MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "node.h"
#include "list.c"

int main(void) {
	int mode = 0;

	init();
	while(1)
	{
		printf("enter mode>>");
		scanf("%d", &mode);
		switch (mode) {
		case 0://종료
			del();
			exit(0);
		case 1:
			make();//새노트생성
			break;
		case 2:
			ls();//노트보기
			break;
		case 3:
			ls_r();//노트읽기
			break;
		case 4:
			modify();//노트수정
			break;
		default:
			while (getchar() != '\0');
		}

	}
	
	return 0;
}

//버퍼초기화 