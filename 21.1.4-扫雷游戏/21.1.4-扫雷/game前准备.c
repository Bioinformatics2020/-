#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>

void prepare()//游戏开始前的准备
{
	int lun = 0;
	srand(time(NULL));//要放在主函数中
	printf("******一起来玩快乐的游戏吧！******\n\n");
	Sleep(500);
	printf("***** 1.进入游戏  2.退出游戏 *****\n\n");
	int a;
play1:
	scanf("%d", &a);
	Sleep(500);
	switch (a)
	{
	case 1:
	play2:
		printf("\n****    （^v^）!    ****\n\n");
		Sleep(500);
		system("cls");
		Sleep(500);
		time_t start, end;
		time(&start);
		game();//主游戏程序
		time(&end);
		printf("\n您愉快的游戏时间为%ld秒\n", end - start);
		lun++;
		break;
	case 2:
		printf("\n*****   确定退出吗? 呜~呜~   *****\n\n");
		Sleep(500);
		printf("***** 1.残忍放弃  2.愉快开始 *****\n\n");
		for (;;)
		{
			scanf("%d", &a);
			Sleep(500);
			if (a == 1)
			{
				printf("\n**(￣▽￣)Bye~Bye~！下次一起玩哦**\n\n");
				return 0;
			}
			else if (a == 2)
			{
				printf("\n*你做了一个正确的决定哦^v^*\n");
				goto play2;
			}
			else
			{
				printf("请问可以重新输入吗，这个我识别不了欸。\n");
				break;
			}
		}
	default:
		printf("请问可以重新输入吗，这个我识别不了欸。\n");
		goto play1;
	}
	printf("\n***游戏好玩吧(^v^)! 再来一局呗？**\n\n");
	Sleep(500);
	printf("***** 1.继续开始  2.下次再玩 *****\n");
	scanf("%d", &a);
	if (a == 1)
		goto play2;
	Sleep(500);
	system("cls");//清空屏幕
	printf("**您总共玩了%d轮，下次记得找我玩~*\n\n",lun);
	printf("Bye~ Bye~");
}