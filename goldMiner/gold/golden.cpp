#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define Pi 3.1415926535    //����Pi
#define high 800        //���廭��ߴ�
#define width 500
#pragma comment(lib,"WINMM.LIB")

IMAGE img_start_bk, img_start1, img_start2, img_game_bk_level0, img_game_bk_level1, img_char1, img_char1_mask, img_char2, img_char2_mask, img_clear;      //����ͼƬ
IMAGE img_gold, img_gold_mask,img_brick,img_barrel, img_barrel_mask;
IMAGE img_hook, img_hook_mask, stone_mask, stone, img_shop, img_A, img_B;
IMAGE img_start, startbottom1, startbottom, img_end, img_C, img_D;
int startbuttom_x, startbuttom_y;     //���忪ʼ��������
double char_x, char_y;       //��ɫ������
double x, y;         //����ͷ
double x1, y1_;       //����β
int Remain_Stone;     //ʣ��ʯͷ
int Remain_Gold;//ʣ��Ļƽ�
int Remain_Barrel;//ʣ���ըҩͰ
int Remain_Barrel1;
int Remain_Barrel2;
int Remain_Barrel3;
double stone_x;//ʯͷ������
double stone_y;
double gold_x;//�ƽ������
double gold_y;
double gold1_x;
double gold1_y;
double barrel_x;//ըҩͰ������
double barrel_y;
double barrel1_x;
double barrel1_y;
double barrel2_x;
double barrel2_y;
double barrel3_x;
double barrel3_y;
double barrel4_x;
double barrel4_y;
double C_x;
double C_y;

int gameStatus;   //����״̬
int i, j, k;     //ѭ������
int radius;     //�������ӳ���
char input;
double alpla;  //ת������
int bomb_num;  //ը������
char bomb_Num;
int Get_Stone;      //�Ƿ�׽ȡ��ĳ��
int Get_Gold;
int Get_Barrel;
int Get_Barrel1;
int Get_Barrel2;
int Get_Barrel3;
int is_Bomb;     //�ж��Ƿ���ը��
int is_Caughted;    //�ж��Ƿ�ץסĳ��
int is_Dead;    //�ж��Ƿ��ѱ�ը��
int score;     //�����ĸ�λ��
char Score;
int Stage = 1;    //��ʼ�ؿ��趨Ϊ1
char stage;
int score_Extra;      //������ʮλ��
char Score_Extra;
int sigh;
int sigh_extra;
int speed;     //ץס��ͬ�������ٶȲ�ͬ�ٶ�
int temp_sec, temp_min;
int sec, min;
SYSTEMTIME it;
int time_out;
int out_time;
char out_Time;
int out_time_extra;
char out_Time_extra;
void startup()//����ͼƬ����ʼ������
{
	initgraph(high, width);
	gameStatus = 0;
	//����ͼƬ
	loadimage(&img_start_bk, "./start.png");               //��ʼ���汳��ͼ
	loadimage(&img_end, "./gameover.png");                       //�������汳��ͼ
	loadimage(&img_start1, "./startbottom1.png");       //��ʼ����1
	loadimage(&img_start2, "./startbottom2.png");		 //��ʼ��2
	loadimage(&img_game_bk_level0, "./background-0.jpg");           //�ؿ�����1
	loadimage(&img_game_bk_level1, "./background-1.jpg");		   //�ؿ�����2
	loadimage(&img_char1, "./char1.jpg");            //��ɫͼƬ������1��
	loadimage(&img_char1_mask, "./char1_mask.jpg");
	loadimage(&img_char2, "./char2.jpg");             //��ɫ����������2��
	loadimage(&img_char2_mask, "./char2_mask.jpg");
	loadimage(&img_brick, "./brick.png");           //��ɫ����ש��
	loadimage(&stone, "./stone.jpg");       //ʯͷ
	loadimage(&stone_mask, "./stone_mask.jpg");
	loadimage(&img_shop, "./shop.png");           //�̵�
	loadimage(&img_A, "./A.bmp");            //ը��
	loadimage(&img_B, "./B.bmp");
	loadimage(&img_hook, "./hook.bmp");               //����
	loadimage(&img_hook_mask, "./hook_mask.bmp");
	loadimage(&img_gold, "./gold.png");
	loadimage(&img_gold_mask, "./gold_mask.png");    //���
	loadimage(&img_barrel, "./barrel.png");
	loadimage(&img_barrel_mask, "./barrel_mask.png");         //ըҩͰ
	loadimage(&img_clear, "./clear.png");               //ͨ�ر���ͼ
	loadimage(&img_C, "./rule.png");
	loadimage(&img_D, "./rule1.png");
	char_x = 340;        //��������
	char_y = 30;
	x = char_x + 40;  //���ӹ̶�һ�˵�����
	y = char_y + 60;
	startbuttom_x = 100; //��ʼ��������
	startbuttom_y = 100;
	C_x = 300;   //��Ϸ�����������
	C_y = 400;
	alpla = 0;     //����ת���Ļ���
	Get_Stone = 0;  //�Ƿ�ץȡʯͷ
	Get_Gold = 0;   //�Ƿ�ץȡ��ƽ�
	Get_Barrel = 0; //�Ƿ�ץȡըҩͰ
	Get_Barrel1 = 0;
	Get_Barrel2 = 0;
	Get_Barrel3 = 0;
	is_Caughted = 0;
	is_Dead = 0;
	is_Bomb = 0;
	score = 0;
	Score = score + '0';    //��intת����char�����Ա�outtextʶ��
	score_Extra = 0;
	Score_Extra = score_Extra + '0';
	radius = 50;  //����ԭ���ĳ���
	bomb_num = 0;  //ը������
	bomb_Num = bomb_num + '0';
	Remain_Stone = 1; //ʣ���ʯͷ
	Remain_Gold = 1;  //ʣ��Ļƽ�
	Remain_Barrel = 1;  //ʣ���ըҩͰ
	Remain_Barrel1 = 1;
	Remain_Barrel2 = 1;
	Remain_Barrel3 = 1;
	stage = Stage + '0';  //�ؿ���
	sigh = 1;
	sigh_extra = 1;
	speed = 0;
	time_out = 0;
	out_time = 1;
	out_Time = out_time + '0';
	out_time_extra = 0;
	out_Time_extra = out_time_extra + '0';

	if (Stage == 1)        //��һ���趨
	{
		stone_x = 700;
		stone_y = 300;
		gold_x = 120;
		gold_y = 400;
		barrel_x = 500;
		barrel_y = 280;
		barrel1_x = rand()%500;
		barrel1_y = rand()%500;
		barrel2_x = 77;
		barrel2_y = 155;
		barrel3_x = 325;
		barrel3_y = 200;
		barrel4_x = rand() % 500;
		barrel4_y = rand() % 500;
	}
	if (Stage == 2)       //�ڶ����趨
	{
		stone_x = 600;
		stone_y = 350;
		gold_x = 160;
		gold_y = 400;
		barrel_x = 380;
		barrel_y = 300;
		barrel1_x = rand() % 500;
		barrel1_y = rand() % 500;
		barrel2_x = 122;
		barrel2_y = 256;
		barrel3_x = rand() % 500;
		barrel3_y = rand() % 500;
		barrel4_x = 290;
		barrel4_y = 310;
	}
	if (Stage == 3)  //�������趨
	{
	    stone_x = 500;
		stone_y = 300;
		gold_x = 260;
		gold_y = 350;
		barrel_x = 330;
		barrel_y = 300;
		barrel1_x = 400;
		barrel1_y = 200;
		barrel2_x = rand() % 500;
		barrel2_y = rand() % 500;
		barrel3_x = 200;
		barrel3_y = 150;
		barrel4_x = rand() % 500;
		barrel4_y = rand() % 500;
	}
}
void gamecontent()//��Ϸ����
{
	BeginBatchDraw();//����˫�����ͼ
	if (gameStatus == 1)  //������Ϸ״̬��
	{
		if (Stage == 1)     //��һ�ر���ͼ
			putimage(0, 0, &img_game_bk_level0);
		if (Stage == 2)    //�ڶ��ر���ͼ
			putimage(0, 0, &img_game_bk_level1);
		if (Stage == 3)   //�����ر���ͼ
			putimage(0, 0, &img_game_bk_level0);
		putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);     //����
		putimage(char_x, char_y, &img_char1, SRCINVERT);
		for (j = 0; j < 15; j++)                     //���µ�ש
			putimage(j * 70, 100, &img_brick);
		if (score >= 20)  //�Ƿ���
		{
			score_Extra = 2;//ʮλ����
			Score_Extra = score_Extra + '0';
			score = score - 20;//��λ
			Score = score + '0';
		}
		if (score >= 10 && score < 20)
		{
			score_Extra = 1;
			Score_Extra = score_Extra + '0';
			score = score - 10;
			Score = score + '0';
		}
		outtextxy(0, 0, "Score=");    //��ʾ�÷�
		outtextxy(49, 0, Score_Extra);
		outtextxy(57, 0, Score);
		outtextxy(745, 0, "bomb=");   //��ʾը����
		outtextxy(790, 0, bomb_Num);
		outtextxy(360, 0, "Stage:");  //��ʾ�ؿ�
		outtextxy(400, 0, stage);
	}
}
void show()//��ʼ����
{
	BeginBatchDraw();//����˫�����ͼ
	if (gameStatus == 0)    //��ʾ����ͼƬ
		putimage(0, 0, &img_start_bk);
	    putimage(200, 400, &img_C);
	MOUSEMSG m;//����Ӧ
	m = GetMouseMsg();
	if (m.uMsg == WM_MOUSEMOVE)                  //������ƶ�ʱ
	{
		if ((abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) <= 200) && (gameStatus == 0))     //�����꿿����ʼ�� ����ʼ����ͼƬ�ı�
			putimage(startbuttom_x, startbuttom_y, &img_start2);
		if ((abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) > 200) && (gameStatus == 0))       //���δ������ͼƬ����
			putimage(startbuttom_x, startbuttom_y, &img_start1);
	}
	if (m.uMsg == WM_LBUTTONDOWN)               //��������ʱ������ؿ�
	{
		if (abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) <= 200)
			gameStatus = 1;
	}
	if (m.uMsg == WM_LBUTTONDOWN)               //��������ʱ�����ֹ���
	{
		if (m.x > 250 && m.x < 350 && m.y>350 && m.y < 450)
			putimage(0, 0, &img_D);

	}
	FlushBatchDraw();
	Sleep(5);
	EndBatchDraw();
}
void gameover()                 //��Ϸ����
{
	if (gameStatus == 3)
	{
		Sleep(200);
		cleardevice();
		putimage(0, 0, &img_end);      //��ʾ����ͼƬ
		outtextxy(50, 50, "��Ϸ����");     //�������
		x1 = -100;          //�������
		y1_ = -100;
		x = -100;
		y = -100;
		_getch();
		putimage(0, 0, &img_end);
		outtextxy(50, 50, "��Ϸ����");
	}
}
void time()//��ʾ��Ϸʱ��
{
	int temp_time;
	temp_time = temp_sec;
	GetLocalTime(&it);
	temp_sec = it.wSecond;
	temp_min = it.wMinute;
	if (temp_time != temp_sec)
		out_time++;
	if (out_time == 10)
	{
		out_time = 0;
		out_time_extra++;
	}
	out_Time = out_time + '0';
	out_Time_extra = out_time_extra + '0';
	outtextxy(355, 485, "Time:");
	outtextxy(392, 485, out_Time_extra);
	outtextxy(400, 485, out_Time);
	if (sec == temp_sec && min + 1 == temp_min)
		time_out = 1;
}
void rope();    //���ú���ĺ���
void midfield()   //�м����
{
	putimage(0, 0, &img_clear); //�����г�����ͼ
	Sleep(1000);
	if (gameStatus == 2)
	{
		MOUSEMSG input;
		cleardevice();//����
		putimage(0, 0, &img_shop);//��ʾ�̵����
		putimage(300, 360, &img_B, NOTSRCERASE);  //���̵�����ʾը��
		putimage(300, 360, &img_A, SRCINVERT);
		while (1)//������
		{
			if (MouseHit())
			{
				input = GetMouseMsg();
				if (input.uMsg == WM_LBUTTONDOWN)        //����ƶ�
				{
					if (input.x >= 600 && input.x <= 700 && input.y >= 50 && input.y <= 150)     //�������һ��
					{
						Stage++; //������һ��
						int temp_bomb = bomb_num;    //������ʱ������¼ը��������ֹ��startup�б���ʼ��Ϊ0
						int temp_score = score;    //������ʱ������¼���ֵĸ�λ������ֹ��startup�б���ʼ��Ϊ0
						int temp_score_Extra = score_Extra;      //������ʱ������¼���ֵ�ʮλ������ֹ��startup�б���ʼ��Ϊ����ֵ
						startup();
						bomb_num = temp_bomb;
						bomb_Num = bomb_num + '0';
						score_Extra = temp_score_Extra;
						Score_Extra = score_Extra + '0';
						score = temp_score;
						Score = score + '0';
						cleardevice();
						gameStatus = 1;          //��Ϸ״̬��Ϊ1
						gamecontent();
						rope();
					}
					if (input.x >= 200 && input.x <= 350 && input.y >= 250 && input.y <= 450)    //�����ը��
					{
						if (score > 2)  //���������ֹ���һ��ը��
						{
							score = score - 3;
							Score = score + '0';//�ַ���������ת��
							bomb_num++;
							bomb_Num = bomb_num + '0';
						}
						if (score_Extra == 1)  //������ִ���10 С��20
						{
							if (score <= 2)
							{
								score = score - 3;
								score_Extra = 0;
								score = 10 + score;
								Score = score + '0';
								Score_Extra = score_Extra + '0';
								bomb_num++;
								bomb_Num = bomb_num + '0';
							}
							if (score > 2)
							{
								score = score - 3;
								Score = score + '0';
								Score_Extra = score_Extra + '0';
								bomb_num++;
								bomb_Num = bomb_num + '0';
							}
						}
						if (score_Extra == 2) //������ִ���20
						{
							if (score <= 2)      //����Ϊ���ֵļ���
							{
								score = score - 3;
								score_Extra = 1;
								score = 10 + score;
								Score = score + '0';
								Score_Extra = score_Extra + '0';
								bomb_num++;
								bomb_Num = bomb_num + '0';
							}
							if (score > 2)
							{
								score = score - 3;
								Score = score + '0';
								Score_Extra = score_Extra + '0';
								bomb_num++;
								bomb_Num = bomb_num + '0';
							}
						}
					}
				}
			}
			outtextxy(0, 0, "Score=");      //��ʾ�г���������
			outtextxy(46, 0, Score_Extra);
			outtextxy(54, 0, Score);
			outtextxy(340, 400, "x");
			outtextxy(350, 400, bomb_Num);
			outtextxy(275, 450, "ը���۸�Ϊ3����");
		}
	}
}

void item()            //ʹ�õ���
{
	char input;
	if (bomb_num > 0)      //��ը����������0ʱ����ʹ��
	{
		if (_kbhit())
		{
			input = _getch();
			if (Get_Barrel == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //����q��ʹ�õ��ߣ��ƻ�ըҩͰ ��������
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel1 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //����q��ʹ�õ��ߣ��ƻ�ըҩͰ ��������
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel2 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //����q��ʹ�õ��ߣ��ƻ�ըҩͰ ��������
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel3 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //����q��ʹ�õ��ߣ��ƻ�ըҩͰ ��������
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
		}
	}
}
void rope_body(double* m)             //ʹ��ָ���¼��ʱ�ĽǶ�
{
	BeginBatchDraw();//����˫�����ͼ
	int p;
	double temp_alpla;
	temp_alpla = *m;
	if (gameStatus == 1)            //������Ϸ�е�״̬
	{
		for (i = 100; i <= 1000; i += 15)     //�쳤
		{
			cleardevice();
			gamecontent();
			time();
			if (i % 4 != 0)                      //���ﶯ��
			{
				putimage(char_x, char_y + 1, &img_char2_mask, NOTSRCERASE);
				putimage(char_x, char_y + 1, &img_char2, SRCINVERT);
			}
			if (i % 4 == 0)
			{
				putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);
				putimage(char_x, char_y, &img_char1, SRCINVERT);
			}
			//��ͬ�ĵ��ߵ�λ��
			if (Remain_Stone > 0)  //����ʯͷͼƬ
			{
				putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
				putimage(stone_x, stone_y, &stone, SRCINVERT);
			}
			if (Remain_Gold > 0)//���ý�
			{
				putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
				putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			}
			if (Remain_Barrel > 0)          //����ըҩͰ
			{
				putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel1 > 0)          //����ըҩͰ
			{
				putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel2 > 0)          //����ըҩͰ
			{
				putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel3 > 0)          //����ըҩͰ
			{
				putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
			}
		x1 = x - radius * i * cos(temp_alpla) * 0.01;            //����β������ת�����ȵı仯���仯������
		y1_ = y + radius * i * sin(temp_alpla) * 0.01;
		if (fabs(x1 - 20 - stone_x) + fabs(y1_ - stone_y) <= 50)     //׽סʯͷ
		{
			score++;
			Get_Stone = 1;
			is_Caughted = 1;
			Remain_Stone--;
			stone_x = x1 - 20;
			stone_y = y1_;
			putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
			putimage(stone_x, stone_y, &stone, SRCINVERT);
			Score = score + '0';
			speed = 200;
		}
		if (fabs(x1 - 20 - gold_x) + fabs(y1_ - gold_y) <= 50)     //׽ס���
		{
			Get_Gold = 1;
			is_Caughted = 1;
			Remain_Gold--;
			score += 3;
			gold_x = x1 - 20;
			gold_y = y1_;
			putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
			putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			Score = score + '0';
			speed = 150;
		}
		if (fabs(x1 - 20 - barrel_x) + fabs(y1_ - barrel_y) <= 50 || fabs(x1 + 30 - barrel_x) + fabs(y1_ + 50 - barrel_y) <= 50)     //ʰȡ��ըҩͰ
		{
			sigh = 0;
			Get_Barrel = 1;
			is_Caughted = 1;
			is_Bomb = 1;
			Remain_Barrel--;
			barrel_x = x1 - 20;
			barrel_y = y1_;
			putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
			putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
			Score = score + '0';
			speed = 120;
		}
		if (fabs(x1 - 20 - barrel1_x) + fabs(y1_ - barrel1_y) <= 50 || fabs(x1 + 30 - barrel1_x) + fabs(y1_ + 50 - barrel1_y) <= 50)     //ʰȡ��ըҩͰ
		{
			sigh = 0;
			Get_Barrel1 = 1;
			is_Caughted = 1;
			is_Bomb = 1;
			Remain_Barrel1--;
			barrel1_x = x1 - 20;
			barrel1_y = y1_;
			putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
			putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
			Score = score + '0';
			speed = 120;
		}
		if (fabs(x1 - 20 - barrel2_x) + fabs(y1_ - barrel2_y) <= 50 || fabs(x1 + 30 - barrel2_x) + fabs(y1_ + 50 - barrel2_y) <= 50)     //ʰȡ��ըҩͰ
		{
			sigh = 0;
			Get_Barrel2 = 1;
			is_Caughted = 1;
			is_Bomb = 1;
			Remain_Barrel2--;
			barrel2_x = x1 - 20;
			barrel2_y = y1_;
			putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
			putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
			Score = score + '0';
			speed = 120;
		}
		if (fabs(x1 - 20 - barrel3_x) + fabs(y1_ - barrel3_y) <= 50 || fabs(x1 + 30 - barrel3_x) + fabs(y1_ + 50 - barrel3_y) <= 50)     //ʰȡ��ըҩͰ
		{
			sigh = 0;
			Get_Barrel3 = 1;
			is_Caughted = 1;
			is_Bomb = 1;
			Remain_Barrel3--;
			barrel3_x = x1 - 20;
			barrel3_y = y1_;
			putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
			putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
			Score = score + '0';
			speed = 120;
		}
		putimage(x1 - 20, y1_, &img_hook_mask, NOTSRCERASE);
		putimage(x1 - 20, y1_, &img_hook, SRCINVERT);
		line(x, y, x1, y1_);
		if (is_Caughted == 1)            //��׽ȡ��ĳ��ʱ������ѭ������¼���Ӵ�ʱ��λ��
		{
			p = i;
			break;
		}
		Sleep(80);
	}

		if (is_Caughted == 0)       //��δ׽ȡ�����壬���쵽��Զ����ԭ·����
			p = 1000;
		for (i = p; i >= 100; i -= 15)     //����
		{
			cleardevice();
			gamecontent();
			time();
			BeginBatchDraw();
			if (i % 4 != 0)     //����
			{
				putimage(char_x, char_y + 1, &img_char2_mask, NOTSRCERASE);
				putimage(char_x, char_y + 1, &img_char2, SRCINVERT);
			}
			if (i % 4 == 0)
			{
				putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);
				putimage(char_x, char_y, &img_char1, SRCINVERT);
			}
			if (Remain_Stone > 0)      //ʯͷδ��ץ�ߣ����ڴ˴���������ʯͷ������ͬ��
			{
				putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
				putimage(stone_x, stone_y, &stone, SRCINVERT);
			}
			if (Remain_Gold > 0)
			{
				putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
				putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			}
			
				if (Remain_Barrel > 0)      //��ֹ��ըҩͰ
				{
					putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel1 > 0)      //��ֹ��ըҩͰ
				{
					putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel2 > 0)      //��ֹ��ըҩͰ
				{
					putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel3 > 0)      //��ֹ��ըҩͰ
				{
					putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);

				}
			x1 = x - radius * i * cos(temp_alpla) * 0.01;
			y1_ = y + radius * i * sin(temp_alpla) * 0.01;
			if (Get_Stone == 1)     //ץסĳ�������������������ƶ�������ͬ��
			{
				stone_x = x1 - 20;
				stone_y = y1_;
				putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
				putimage(stone_x, stone_y, &stone, SRCINVERT);
			}
			if (Get_Gold == 1)
			{
				gold_x = x1 - 20;
				gold_y = y1_;
				putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
				putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			}
			if (Get_Barrel == 1)
			{
				barrel_x = x1 - 20;
				barrel_y = y1_;
				putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
				item();      //�Ƿ�ʹ�õ���
				Sleep(10);
				if (is_Bomb == 1)     //��ʹ�õ�����ը
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //��ʹ�õ��ߣ������0�����ᱬը
					gameover();
				}
			}
			if (Get_Barrel1 == 1)
			{
				barrel1_x = x1 - 20;
				barrel1_y = y1_;
				putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
				item();      //�Ƿ�ʹ�õ���
				Sleep(10);
				if (is_Bomb == 1)     //��ʹ�õ�����ը
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //��ʹ�õ��ߣ������0�����ᱬը
					gameover();
				}
			}
			if (Get_Barrel2 == 1)
			{
				barrel2_x = x1 - 20;
				barrel2_y = y1_;
				putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
				item();      //�Ƿ�ʹ�õ���
				Sleep(10);
				if (is_Bomb == 1)     //��ʹ�õ�����ը
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //��ʹ�õ��ߣ������0�����ᱬը
					gameover();
				}
			}
			if (Get_Barrel3 == 1)
			{
				barrel3_x = x1 - 20;
				barrel3_y = y1_;
				putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
				item();      //�Ƿ�ʹ�õ���
				Sleep(10);
				if (is_Bomb == 1)     //��ʹ�õ�����ը
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //��ʹ�õ��ߣ������0�����ᱬը
					gameover();
				}
			}
			FlushBatchDraw();
			EndBatchDraw();
			BeginBatchDraw();
			putimage(x1 - 20, y1_, &img_hook_mask, NOTSRCERASE);
			putimage(x1 - 20, y1_, &img_hook, SRCINVERT);
			line(x, y, x1, y1_);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(speed);      //�ٶȿ���
			if (i == 100)    //������ָ�����״̬Ϊû�ж���
			{
				Get_Stone = 0;
				Get_Gold = 0;
				Get_Barrel = 0;
				Get_Barrel1 = 0;
				Get_Barrel2 = 0;
				Get_Barrel3 = 0;
				is_Bomb = 0;
				is_Caughted = 0;
				speed = 0;
			}
			Sleep(80);
		}
	}
}
void rope()     //���ӱ���
{
	setlinecolor(BLACK);    //����������ɫΪ��ɫ
	GetLocalTime(&it);
	sec = it.wSecond;
	min = it.wMinute;
	if (gameStatus == 1)
	{
		BeginBatchDraw();
		while (1)
		{
			for (alpla = 0; alpla <= Pi; alpla += 0.02)          //������ת
			{
				cleardevice();
				gamecontent();
				time();
				//��û��ץס�κζ���ʱ
				//�ջ�ĳ����Ʒ��������
				if (Remain_Stone > 0)       //��û��ץס�κζ���ʱ
				{
					putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
					putimage(stone_x, stone_y, &stone, SRCINVERT);
				}
				else if (Remain_Stone == 0)          //�ջ�ĳ����Ʒ��������
				{
					stone_x = -100;
					stone_y = -100;
				}
				if (Remain_Gold > 0)            //�Ƿ��ջ���
				{
					putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
					putimage(gold_x, gold_y, &img_gold, SRCINVERT);
				}
				else if (Remain_Gold == 0)
				{
					gold_x = -100;
					gold_y = -100;
				}
					if (Remain_Barrel>0)        //�Ƿ��ջ�ըҩͰ
					{
						putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel == 0)
					{
						gameover();
					}
					if (Remain_Barrel1 > 0)        //�Ƿ��ջ�ըҩͰ
					{
						putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel1 == 0)
					{
						gameover();
					}
					if (Remain_Barrel2 > 0)        //�Ƿ��ջ�ըҩͰ
					{
						putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel2 == 0)
					{
						gameover();
					}
					if (Remain_Barrel3 > 0)        //�Ƿ��ջ�ըҩͰ
					{
						putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel3 == 0)
					{
						gameover();
					}
				x1 = x - radius * cos(alpla);     //��Ƕȱ仯���������β����
				y1_ = y + radius * sin(alpla);
				putimage(x1 - 20, y1_, &img_hook_mask, NOTSRCERASE);
				putimage(x1 - 20, y1_, &img_hook, SRCINVERT);
				line(x, y, x1, y1_);
				FlushBatchDraw();
				EndBatchDraw();
				if (_kbhit())     //�����̰��º�
				{
					input = _getch();
					if (input == ' ')    //�����¿ո�ʱ
						rope_body(&alpla);
				}
				Sleep(10);
			}
			if (gameStatus == 2)      //������Ϸѭ��
			{
				break;
				gameover();
			}
			for (alpla = Pi; alpla >= 0; alpla -= 0.02)     //���ӷ�����ת
			{
				cleardevice();
				gamecontent();
				time();
				if (Remain_Stone > 0)             //�Ƿ����ʯͷ
				{
					putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
					putimage(stone_x, stone_y, &stone, SRCINVERT);
				}
				else if (Remain_Stone == 0)
				{
					stone_x = -100;
					stone_y = -100;
				}
				if (Remain_Gold > 0)     //�Ƿ���ô��
				{
					putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
					putimage(gold_x, gold_y, &img_gold, SRCINVERT);
				}
				else if (Remain_Gold == 0)
				{
					gold_x = -100;
					gold_y = -100;
				}
					if (Remain_Barrel > 0)
					{
						putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel == 0)
					{
						gameover();
					}
					if (Remain_Barrel1 > 0)
					{
						putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel1 == 0)
					{
						gameover();
					}
					if (Remain_Barrel2 > 0)
					{
						putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel2 == 0)
					{
						gameover();
					}
					if (Remain_Barrel3 > 0)
					{
						putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel3 == 0)
					{
						gameover();
					}
				x1 = x - radius * cos(alpla);          //��β�����满�ȱ仯���仯
				y1_ = y + radius * sin(alpla);
				putimage(x1 - 20, y1_, &img_hook_mask, NOTSRCERASE);
				putimage(x1 - 20, y1_, &img_hook, SRCINVERT);
				line(x, y, x1, y1_);
				FlushBatchDraw();
				EndBatchDraw();
				if (_kbhit())
				{
					input = _getch();
					if (input == ' ')
						rope_body(&alpla);     //�����¿ո�󣬼�¼��ǰ���ȣ�����ͣת��
				}
				Sleep(10);
			}
			if (Stage == 1)    //����Ϊ�жϹؿ�����������
			{
				if (score >= 4 && is_Dead == 0 && time_out == 0)                //��������Ϊ4���Ҳ���ը��
				{
					gameStatus = 2;
					midfield();
				}
			}
			if (Stage == 2)
			{
				if (score + 10 * score_Extra >= 8 && is_Dead == 0 && time_out == 0)        //��������Ϊ8���Ҳ���ը��
				{
					gameStatus = 2;
					midfield();
				}
			}
			if (Stage == 3)
			{
				if (score + 10 * score_Extra >= 12 && is_Dead == 0 && time_out == 0)    //��������Ϊ12���Ҳ���ը��
				{
					gameStatus = 3;
					gameover();
				}
			}
			if (Stage == 1 || Stage == 2 || Stage == 3)
			{
				if (time_out == 1)
				{
					gameStatus = 3;
					gameover();
				}
			}
		}
	}
}

int main()
{   
	startup();   //���ݳ�ʼ��
	while (1)
	{
		if (gameStatus == 0)      //��Ϸ״̬Ϊ0����ʼ����
			show();
		else if (gameStatus == 1)    //��Ϸ״̬Ϊ1��������Ϸ
		{
			gamecontent();
			rope();
		}
	}
	return 0;
}