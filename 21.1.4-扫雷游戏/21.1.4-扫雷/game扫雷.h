
void game();//ɨ����Ϸ����
void printboard(char board[30][30], int ROW, int COL);//��ӡ��ɨ�׽���
void setmine(int minearr[32][32], int ROW, int COL, int mine);//��������
int summine(int minearr[32][32], int x, int y);//����x��y����Χ�ж�����
void openboard2(char board[30][30], int minearr[32][32], int x, int y, int* count, int ROW, int COL);//��x,y��Χ�����������е�
void openboard1(char board[30][30], int minearr[32][32], int x, int y, int ROW, int COL, int* count);//�Զ��򿪿ո���Χ�ĵ�