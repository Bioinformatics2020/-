#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>

int summine(int minearr[32][32], int x, int y)//����x��y����Χ�ж�����
{
	int n = 0;
	x++;
	y++;
	n = minearr[x - 1][y - 1] + minearr[x - 1][y] + n;
	n = minearr[x - 1][y + 1] + minearr[x][y - 1] + n;
	n = minearr[x][y + 1] + minearr[x + 1][y - 1] + n;
	n = minearr[x + 1][y] + minearr[x + 1][y + 1] + n;
	n = n / 42;
	return n;
}

void openboard1(char board[30][30], int minearr[32][32], int x, int y, int ROW, int COL, int* count)//�Զ��򿪿ո���Χ�ĵ�
{
	int sum;
	sum = summine(minearr, x, y);
	if (sum == 0)//�յ����м�
	{
		int sum1, sum2, sum3, sum4, sum6, sum7, sum8, sum9;
		if (y != 0)//���
		{
			if (x != 0)//�������Ͻ�����
			{
				if (board[x - 1][y - 1] == '?' || board[x - 1][y - 1] == '#')//�����ظ���
				{
					sum1 = summine(minearr, x - 1, y - 1);
					board[x - 1][y - 1] = sum1 + 48;
					*count = *count + 1;
					if (sum1 == 0)
						openboard1(board, minearr, x - 1, y - 1, ROW, COL, count);
				}
			}
			if (board[x][y - 1] == '?' || board[x][y - 1] == '#')//�����ظ���
			{
				sum2 = summine(minearr, x, y - 1);
				board[x][y - 1] = sum2 + 48;//�������һ������
				*count = *count + 1;
				if (sum2 == 0)
					openboard1(board, minearr, x, y - 1, ROW, COL, count);
			}

			if (x != ROW - 1)//�������½�����
			{
				if (board[x + 1][y - 1] == '?' || board[x + 1][y - 1] == '#')//�����ظ���
				{
					sum3 = summine(minearr, x + 1, y - 1);
					board[x + 1][y - 1] = sum3 + 48;
					*count = *count + 1;
					if (sum3 == 0)
						openboard1(board, minearr, x + 1, y - 1, ROW, COL, count);
				}
			}
		}
		if (x != 0)//�����ϱ�һ������
		{
			if (board[x - 1][y] == '?' || board[x - 1][y] == '#')//�����ظ���
			{
				sum4 = summine(minearr, x - 1, y);
				board[x - 1][y] = sum4 + 48;
				*count = *count + 1;
				if (sum4 == 0)
					openboard1(board, minearr, x - 1, y, ROW, COL, count);
			}
		}
		if (x != ROW - 1)//�����±�һ������
		{
			if (board[x + 1][y] == '?' || board[x + 1][y] == '#')//�����ظ���
			{
				sum6 = summine(minearr, x + 1, y);
				board[x + 1][y] = sum6 + 48;
				*count = *count + 1;
				if (sum6 == 0)
					openboard1(board, minearr, x + 1, y, ROW, COL, count);
			}
		}

		if (y != COL - 1)//�ұ�
		{
			if (x != 0)//�������Ͻ�����
			{
				if (board[x - 1][y + 1] == '?' || board[x - 1][y + 1] == '#')//�����ظ���
				{
					sum7 = summine(minearr, x - 1, y + 1);
					board[x - 1][y + 1] = sum7 + 48;
					*count = *count + 1;
					if (sum7 == 0)
						openboard1(board, minearr, x - 1, y + 1, ROW, COL, count);
				}
			}
			if (board[x][y + 1] == '?' || board[x][y + 1] == '#')//�����ظ���
			{
				sum8 = summine(minearr, x, y + 1);
				board[x][y + 1] = sum8 + 48;
				*count = *count + 1;
				if (sum8 == 0)
					openboard1(board, minearr, x, y + 1, ROW, COL, count);
			}

			if (x != ROW - 1)//�������½�����
			{
				if (board[x + 1][y + 1] == '?' || board[x + 1][y + 1] == '#')//�����ظ���
				{
					sum9 = summine(minearr, x + 1, y + 1);
					board[x + 1][y + 1] = sum9 + 48;
					*count = *count + 1;
					if (sum9 == 0)
						openboard1(board, minearr, x + 1, y + 1, ROW, COL, count);
				}
			}
		}

	}
}

void openboard2(char board[30][30], int minearr[32][32], int x, int y, int* count, int ROW, int COL)//��x,y��Χ�����������е�
{
	int sum;
	if (y != 0)//���
	{
		if (x != 0)//�������Ͻ�����
		{
			if (board[x - 1][y - 1] == '?')//�����ظ���
			{
				sum = summine(minearr, x - 1, y - 1);
				if(sum==0)
					openboard1(*board, *minearr, x-1, y-1, ROW, COL, count);
				board[x + 1][y + 1] = sum + 48;
				*count = *count + 1;
			}
		}
		if (board[x][y - 1] == '?')//�����ظ���
		{
			sum = summine(minearr, x, y - 1);
			board[x][y - 1] = sum + 48;//�������һ������
			if (sum == 0)
				openboard1(*board, *minearr, x, y-1, ROW, COL, count);
			*count = *count + 1;
		}

		if (x != ROW - 1)//�������½�����
		{
			if (board[x + 1][y - 1] == '?')//�����ظ���
			{
				sum = summine(minearr, x + 1, y - 1);
				board[x + 1][y - 1] = sum + 48;
				if (sum == 0)
					openboard1(*board, *minearr, x+1, y-1, ROW, COL, count);
				*count = *count + 1;
			}
		}
	}
	if (x != 0)//�����ϱ�һ������
	{
		if (board[x - 1][y] == '?')//�����ظ���
		{
			sum = summine(minearr, x - 1, y);
			board[x - 1][y] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x-1, y, ROW, COL, count);
			*count = *count + 1;
		}
	}
	if (x != ROW - 1)//�����±�һ������
	{
		if (board[x + 1][y] == '?')//�����ظ���
		{
			sum = summine(minearr, x + 1, y);
			board[x + 1][y] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x+1, y, ROW, COL, count);
			*count = *count + 1;
		}
	}

	if (y != COL - 1)//�ұ�
	{
		if (x != 0)//�������Ͻ�����
		{
			if (board[x - 1][y + 1] == '?')//�����ظ���
			{
				sum = summine(minearr, x - 1, y + 1);
				board[x - 1][y + 1] = sum + 48;
				if (sum == 0)
					openboard1(*board, *minearr, x-1, y+1, ROW, COL, count);
				*count = *count + 1;
			}
		}
		if (board[x][y + 1] == '?')//�����ظ���
		{
			sum = summine(minearr, x, y + 1);
			board[x][y + 1] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x, y+1, ROW, COL, count);
			*count = *count + 1;
		}

		if (x != ROW - 1)//�������½�����
		{
			if (board[x + 1][y + 1] == '?')//�����ظ���
			{
				sum = summine(minearr, x + 1, y + 1);
				board[x + 1][y + 1] = sum + 48;
				if (sum == 0)
					openboard1(*board, *minearr, x+1, y+1, ROW, COL, count);
				*count = *count + 1;
			}
		}
	}
}

void setmine(int minearr[32][32], int ROW, int COL, int mine)//��������
{
	int arr[200] = { 0 };
	for (int n = 0; n < mine; n++)//����mine�������
	{
		arr[n] = rand() % (ROW*COL) + 1;
		for (int i = 0; i < n; i++)//����������ظ����������������������ַ����
		{
			if (arr[n] == arr[i])
				n--;
		}

	}
	int x, y;
	for (int n = 0; n < mine; n++)//ȷ������λ��
	{
		y = arr[n] / ROW;
		x = arr[n] % ROW;
		minearr[x + 1][y + 1] = '*';
	}
}

void printboard(char board[30][30], int ROW, int COL)//��ӡ��ɨ�׽���
{
	Sleep(300);
	system("cls");
	int i, j;
	printf("\n");
	for (i = 0; i < ROW; i++)
	{
		printf("%2d ", ROW - i);//������
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == '0')
				board[i][j] = ' ';
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n   ");
	for (j = 1; j <= COL; j++)//������
		printf("%2d ", j);
	printf("\n\n");
}

void game()
{
	char board[30][30] = { 0 };//����һ������
	int minearr[32][32] = { 0 };
	int grade, ROW, COL, mine, x, y, o, count, sum;
	printf("��ѡ���Ѷ�\n");
	printf("1.����  2.�м�  3.�߼�  4.�Զ���\n");
choose:
	scanf("%d", &grade);//ѡ����Ϸ�Ѷ�
	switch (grade)
	{
	case 1:
		ROW = 9;
		COL = 9;
		mine = 10;		
		break;
	case 2:
		ROW = 16;
		COL = 16;
		mine = 40;
		break;
	case 3:
		ROW = 16;
		COL = 30;
		mine = 100;
		break;
	case 4:
		printf("��ֱ����������������Լ����������ÿո����\n");
		do
		{
			printf("�������Ϊ30*30�����������Ϊ200\n");
			scanf("%d%d%d", &ROW, &COL, &mine);
		} while ((ROW <= 30 && COL <= 30 && mine <= 200) == 0);
		break;
	default:
		printf("ѡ�����������ѡ��\n");
		goto choose;
	}
	printf("��ע���ܹ���%d����\n", mine);
	Sleep(1000);
	for (int i = 0; i < ROW; i++)//�������Ѷȳ�ʼ��
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = '?';
	}
	printboard(board, ROW, COL);
	srand(time(NULL));//���������
	setmine(minearr, ROW, COL, mine);//��������
	printf("\n��ʼɨ�װɣ�\n\n");
	for (count = 0; count < (ROW*COL - mine);)//�����׵�ѭ������
	{
		printf("��������������,�����������\nȻ������1.�ڿ��� 2.���Ϊ�� 3.������Χ�����������е�\n");
	back:
		scanf("%d%d%d", &x, &y, &o);//���ѡ����
		x = ROW - x;//���������ת��Ϊ��ʵ����
		y = y - 1;//���������ת��Ϊ��ʵ����
		if ((x >= 0 && x < ROW) && (y >= 0 && y < COL) == 0)
		{
			printf("���������������������\n");
			goto back;
		}
		if (board[x][y] == '?' || board[x][y] == '#')
		{

			if (o == 1)//�ڿ����꣨x��y���ĵ�
			{
				if (minearr[x + 1][y + 1] == '*')
				{
					board[x][y] = '*';
					printboard(board, ROW, COL);
					printf("bong~~bong~~\n\n");
					Sleep(500);
					printf("�ȵ����ף���Ϸ����\n");
					return;
				}
				else
				{
					sum = summine(minearr, x, y);//��x,y��Χ������Ŀ
					board[x][y] = sum + 48;
					if (sum == 0)
					{
						openboard1(board, minearr, x, y, ROW, COL, &count);//�򿪿ո���Χ9���ַ�						
					}
					printboard(board, ROW, COL);
					count++;
				}
			}
			else if (o == 2)//������꣨x��y���ĵ�
			{
				board[x][y] = '#';
				printboard(board, ROW, COL);
			}
			else
				printf("�������ж���ô������\n");
		}
		else if (o == 3)//��x,y��Χ�����������е�
		{
			openboard2(board, minearr, x, y, &count, ROW, COL);
			printboard(board, ROW, COL);
		}
		else
		{
			printf("���������ظ�������������\n");
			goto back;
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == '?' || board[i][j] == '#')
				board[i][j] = '*';
		}
	}
	printboard(board, ROW, COL);
	printf("***�� �� ��!***\n");
}