#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>

void prepare()//��Ϸ��ʼǰ��׼��
{
	int lun = 0;
	srand(time(NULL));//Ҫ������������
	printf("******һ��������ֵ���Ϸ�ɣ�******\n\n");
	Sleep(500);
	printf("***** 1.������Ϸ  2.�˳���Ϸ *****\n\n");
	int a;
play1:
	scanf("%d", &a);
	Sleep(500);
	switch (a)
	{
	case 1:
	play2:
		printf("\n****    ��^v^��!    ****\n\n");
		Sleep(500);
		system("cls");
		Sleep(500);
		time_t start, end;
		time(&start);
		game();//����Ϸ����
		time(&end);
		printf("\n��������Ϸʱ��Ϊ%ld��\n", end - start);
		lun++;
		break;
	case 2:
		printf("\n*****   ȷ���˳���? ��~��~   *****\n\n");
		Sleep(500);
		printf("***** 1.���̷���  2.��쿪ʼ *****\n\n");
		for (;;)
		{
			scanf("%d", &a);
			Sleep(500);
			if (a == 1)
			{
				printf("\n**(������)Bye~Bye~���´�һ����Ŷ**\n\n");
				return 0;
			}
			else if (a == 2)
			{
				printf("\n*������һ����ȷ�ľ���Ŷ^v^*\n");
				goto play2;
			}
			else
			{
				printf("���ʿ������������������ʶ���˚G��\n");
				break;
			}
		}
	default:
		printf("���ʿ������������������ʶ���˚G��\n");
		goto play1;
	}
	printf("\n***��Ϸ�����(^v^)! ����һ���£�**\n\n");
	Sleep(500);
	printf("***** 1.������ʼ  2.�´����� *****\n");
	scanf("%d", &a);
	if (a == 1)
		goto play2;
	Sleep(500);
	system("cls");//�����Ļ
	printf("**���ܹ�����%d�֣��´μǵ�������~*\n\n",lun);
	printf("Bye~ Bye~");
}