
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
		case 0://����
			del();
			exit(0);
		case 1:
			make();//����Ʈ����
			break;
		case 2:
			ls();//��Ʈ����
			break;
		case 3:
			ls_r();//��Ʈ�б�
			break;
		case 4:
			modify();//��Ʈ����
			break;
		default:
			while (getchar() != '\0');
		}

	}
	
	return 0;
}

//�����ʱ�ȭ 