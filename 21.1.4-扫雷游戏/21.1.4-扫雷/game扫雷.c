#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>

int summine(int minearr[32][32], int x, int y)//数（x，y）周围有多少雷
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

void openboard1(char board[30][30], int minearr[32][32], int x, int y, int ROW, int COL, int* count)//自动打开空格周围的点
{
	int sum;
	sum = summine(minearr, x, y);
	if (sum == 0)//空的在中间
	{
		int sum1, sum2, sum3, sum4, sum6, sum7, sum8, sum9;
		if (y != 0)//左边
		{
			if (x != 0)//不对左上角运行
			{
				if (board[x - 1][y - 1] == '?' || board[x - 1][y - 1] == '#')//避免重复打开
				{
					sum1 = summine(minearr, x - 1, y - 1);
					board[x - 1][y - 1] = sum1 + 48;
					*count = *count + 1;
					if (sum1 == 0)
						openboard1(board, minearr, x - 1, y - 1, ROW, COL, count);
				}
			}
			if (board[x][y - 1] == '?' || board[x][y - 1] == '#')//避免重复打开
			{
				sum2 = summine(minearr, x, y - 1);
				board[x][y - 1] = sum2 + 48;//不对左边一个运行
				*count = *count + 1;
				if (sum2 == 0)
					openboard1(board, minearr, x, y - 1, ROW, COL, count);
			}

			if (x != ROW - 1)//不对左下角运行
			{
				if (board[x + 1][y - 1] == '?' || board[x + 1][y - 1] == '#')//避免重复打开
				{
					sum3 = summine(minearr, x + 1, y - 1);
					board[x + 1][y - 1] = sum3 + 48;
					*count = *count + 1;
					if (sum3 == 0)
						openboard1(board, minearr, x + 1, y - 1, ROW, COL, count);
				}
			}
		}
		if (x != 0)//不对上边一个运行
		{
			if (board[x - 1][y] == '?' || board[x - 1][y] == '#')//避免重复打开
			{
				sum4 = summine(minearr, x - 1, y);
				board[x - 1][y] = sum4 + 48;
				*count = *count + 1;
				if (sum4 == 0)
					openboard1(board, minearr, x - 1, y, ROW, COL, count);
			}
		}
		if (x != ROW - 1)//不对下边一个运行
		{
			if (board[x + 1][y] == '?' || board[x + 1][y] == '#')//避免重复打开
			{
				sum6 = summine(minearr, x + 1, y);
				board[x + 1][y] = sum6 + 48;
				*count = *count + 1;
				if (sum6 == 0)
					openboard1(board, minearr, x + 1, y, ROW, COL, count);
			}
		}

		if (y != COL - 1)//右边
		{
			if (x != 0)//不对右上角运行
			{
				if (board[x - 1][y + 1] == '?' || board[x - 1][y + 1] == '#')//避免重复打开
				{
					sum7 = summine(minearr, x - 1, y + 1);
					board[x - 1][y + 1] = sum7 + 48;
					*count = *count + 1;
					if (sum7 == 0)
						openboard1(board, minearr, x - 1, y + 1, ROW, COL, count);
				}
			}
			if (board[x][y + 1] == '?' || board[x][y + 1] == '#')//避免重复打开
			{
				sum8 = summine(minearr, x, y + 1);
				board[x][y + 1] = sum8 + 48;
				*count = *count + 1;
				if (sum8 == 0)
					openboard1(board, minearr, x, y + 1, ROW, COL, count);
			}

			if (x != ROW - 1)//不对右下角运行
			{
				if (board[x + 1][y + 1] == '?' || board[x + 1][y + 1] == '#')//避免重复打开
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

void openboard2(char board[30][30], int minearr[32][32], int x, int y, int* count, int ROW, int COL)//打开x,y周围除标记外的所有点
{
	int sum;
	if (y != 0)//左边
	{
		if (x != 0)//不对左上角运行
		{
			if (board[x - 1][y - 1] == '?')//避免重复打开
			{
				sum = summine(minearr, x - 1, y - 1);
				if(sum==0)
					openboard1(*board, *minearr, x-1, y-1, ROW, COL, count);
				board[x + 1][y + 1] = sum + 48;
				*count = *count + 1;
			}
		}
		if (board[x][y - 1] == '?')//避免重复打开
		{
			sum = summine(minearr, x, y - 1);
			board[x][y - 1] = sum + 48;//不对左边一个运行
			if (sum == 0)
				openboard1(*board, *minearr, x, y-1, ROW, COL, count);
			*count = *count + 1;
		}

		if (x != ROW - 1)//不对左下角运行
		{
			if (board[x + 1][y - 1] == '?')//避免重复打开
			{
				sum = summine(minearr, x + 1, y - 1);
				board[x + 1][y - 1] = sum + 48;
				if (sum == 0)
					openboard1(*board, *minearr, x+1, y-1, ROW, COL, count);
				*count = *count + 1;
			}
		}
	}
	if (x != 0)//不对上边一个运行
	{
		if (board[x - 1][y] == '?')//避免重复打开
		{
			sum = summine(minearr, x - 1, y);
			board[x - 1][y] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x-1, y, ROW, COL, count);
			*count = *count + 1;
		}
	}
	if (x != ROW - 1)//不对下边一个运行
	{
		if (board[x + 1][y] == '?')//避免重复打开
		{
			sum = summine(minearr, x + 1, y);
			board[x + 1][y] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x+1, y, ROW, COL, count);
			*count = *count + 1;
		}
	}

	if (y != COL - 1)//右边
	{
		if (x != 0)//不对右上角运行
		{
			if (board[x - 1][y + 1] == '?')//避免重复打开
			{
				sum = summine(minearr, x - 1, y + 1);
				board[x - 1][y + 1] = sum + 48;
				if (sum == 0)
					openboard1(*board, *minearr, x-1, y+1, ROW, COL, count);
				*count = *count + 1;
			}
		}
		if (board[x][y + 1] == '?')//避免重复打开
		{
			sum = summine(minearr, x, y + 1);
			board[x][y + 1] = sum + 48;
			if (sum == 0)
				openboard1(*board, *minearr, x, y+1, ROW, COL, count);
			*count = *count + 1;
		}

		if (x != ROW - 1)//不对右下角运行
		{
			if (board[x + 1][y + 1] == '?')//避免重复打开
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

void setmine(int minearr[32][32], int ROW, int COL, int mine)//产生地雷
{
	int arr[200] = { 0 };
	for (int n = 0; n < mine; n++)//生成mine个随机数
	{
		arr[n] = rand() % (ROW*COL) + 1;
		for (int i = 0; i < n; i++)//如果产生了重复的数，就重新生成这个地址的数
		{
			if (arr[n] == arr[i])
				n--;
		}

	}
	int x, y;
	for (int n = 0; n < mine; n++)//确定地雷位置
	{
		y = arr[n] / ROW;
		x = arr[n] % ROW;
		minearr[x + 1][y + 1] = '*';
	}
}

void printboard(char board[30][30], int ROW, int COL)//打印出扫雷界面
{
	Sleep(300);
	system("cls");
	int i, j;
	printf("\n");
	for (i = 0; i < ROW; i++)
	{
		printf("%2d ", ROW - i);//纵坐标
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == '0')
				board[i][j] = ' ';
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n   ");
	for (j = 1; j <= COL; j++)//横坐标
		printf("%2d ", j);
	printf("\n\n");
}

void game()
{
	char board[30][30] = { 0 };//创建一个数组
	int minearr[32][32] = { 0 };
	int grade, ROW, COL, mine, x, y, o, count, sum;
	printf("请选择难度\n");
	printf("1.初级  2.中级  3.高级  4.自定义\n");
choose:
	scanf("%d", &grade);//选择游戏难度
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
		printf("请分别输入行数和列数以及地雷数，用空格隔开\n");
		do
		{
			printf("行列最大为30*30，地雷数最大为200\n");
			scanf("%d%d%d", &ROW, &COL, &mine);
		} while ((ROW <= 30 && COL <= 30 && mine <= 200) == 0);
		break;
	default:
		printf("选择错误，请重新选择\n");
		goto choose;
	}
	printf("请注意总共有%d个雷\n", mine);
	Sleep(1000);
	for (int i = 0; i < ROW; i++)//按给定难度初始化
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = '?';
	}
	printboard(board, ROW, COL);
	srand(time(NULL));//随机数种子
	setmine(minearr, ROW, COL, mine);//产生地雷
	printf("\n开始扫雷吧！\n\n");
	for (count = 0; count < (ROW*COL - mine);)//找挖雷的循环次数
	{
		printf("请先输入纵坐标,再输入横坐标\n然后输入1.挖开它 2.标记为雷 3.打开它周围除标记外的所有点\n");
	back:
		scanf("%d%d%d", &x, &y, &o);//玩家选坐标
		x = ROW - x;//将玩家坐标转换为真实坐标
		y = y - 1;//将玩家坐标转换为真实坐标
		if ((x >= 0 && x < ROW) && (y >= 0 && y < COL) == 0)
		{
			printf("坐标输入错误，请重新输入\n");
			goto back;
		}
		if (board[x][y] == '?' || board[x][y] == '#')
		{

			if (o == 1)//挖开坐标（x，y）的点
			{
				if (minearr[x + 1][y + 1] == '*')
				{
					board[x][y] = '*';
					printboard(board, ROW, COL);
					printf("bong~~bong~~\n\n");
					Sleep(500);
					printf("踩到地雷，游戏结束\n");
					return;
				}
				else
				{
					sum = summine(minearr, x, y);//求x,y周围的雷数目
					board[x][y] = sum + 48;
					if (sum == 0)
					{
						openboard1(board, minearr, x, y, ROW, COL, &count);//打开空格周围9个字符						
					}
					printboard(board, ROW, COL);
					count++;
				}
			}
			else if (o == 2)//标记坐标（x，y）的点
			{
				board[x][y] = '#';
				printboard(board, ROW, COL);
			}
			else
				printf("请重新判断怎么处理它\n");
		}
		else if (o == 3)//打开x,y周围除标记外的所有点
		{
			openboard2(board, minearr, x, y, &count, ROW, COL);
			printboard(board, ROW, COL);
		}
		else
		{
			printf("坐标输入重复，请重新输入\n");
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
	printf("***过 关 啦!***\n");
}