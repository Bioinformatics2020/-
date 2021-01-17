
void game();//扫雷游戏主体
void printboard(char board[30][30], int ROW, int COL);//打印出扫雷界面
void setmine(int minearr[32][32], int ROW, int COL, int mine);//产生地雷
int summine(int minearr[32][32], int x, int y);//数（x，y）周围有多少雷
void openboard2(char board[30][30], int minearr[32][32], int x, int y, int* count, int ROW, int COL);//打开x,y周围除标记外的所有点
void openboard1(char board[30][30], int minearr[32][32], int x, int y, int ROW, int COL, int* count);//自动打开空格周围的点