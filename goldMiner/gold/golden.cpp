#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define Pi 3.1415926535    //定义Pi
#define high 800        //定义画面尺寸
#define width 500
#pragma comment(lib,"WINMM.LIB")

IMAGE img_start_bk, img_start1, img_start2, img_game_bk_level0, img_game_bk_level1, img_char1, img_char1_mask, img_char2, img_char2_mask, img_clear;      //定义图片
IMAGE img_gold, img_gold_mask,img_brick,img_barrel, img_barrel_mask;
IMAGE img_hook, img_hook_mask, stone_mask, stone, img_shop, img_A, img_B;
IMAGE img_start, startbottom1, startbottom, img_end, img_C, img_D;
int startbuttom_x, startbuttom_y;     //定义开始键的坐标
double char_x, char_y;       //角色的坐标
double x, y;         //绳子头
double x1, y1_;       //绳子尾
int Remain_Stone;     //剩余石头
int Remain_Gold;//剩余的黄金
int Remain_Barrel;//剩余的炸药桶
int Remain_Barrel1;
int Remain_Barrel2;
int Remain_Barrel3;
double stone_x;//石头的坐标
double stone_y;
double gold_x;//黄金的坐标
double gold_y;
double gold1_x;
double gold1_y;
double barrel_x;//炸药桶的坐标
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

int gameStatus;   //定义状态
int i, j, k;     //循环变量
int radius;     //定义绳子长度
char input;
double alpla;  //转过弧度
int bomb_num;  //炸弹数量
char bomb_Num;
int Get_Stone;      //是否捉取到某物
int Get_Gold;
int Get_Barrel;
int Get_Barrel1;
int Get_Barrel2;
int Get_Barrel3;
int is_Bomb;     //判断是否是炸弹
int is_Caughted;    //判断是否抓住某物
int is_Dead;    //判断是否已被炸死
int score;     //分数的个位数
char Score;
int Stage = 1;    //初始关卡设定为1
char stage;
int score_Extra;      //分数的十位数
char Score_Extra;
int sigh;
int sigh_extra;
int speed;     //抓住不同的物体速度不同速度
int temp_sec, temp_min;
int sec, min;
SYSTEMTIME it;
int time_out;
int out_time;
char out_Time;
int out_time_extra;
char out_Time_extra;
void startup()//加载图片，初始化数据
{
	initgraph(high, width);
	gameStatus = 0;
	//加载图片
	loadimage(&img_start_bk, "./start.png");               //开始界面背景图
	loadimage(&img_end, "./gameover.png");                       //结束界面背景图
	loadimage(&img_start1, "./startbottom1.png");       //开始按键1
	loadimage(&img_start2, "./startbottom2.png");		 //开始键2
	loadimage(&img_game_bk_level0, "./background-0.jpg");           //关卡背景1
	loadimage(&img_game_bk_level1, "./background-1.jpg");		   //关卡背景2
	loadimage(&img_char1, "./char1.jpg");            //角色图片（动作1）
	loadimage(&img_char1_mask, "./char1_mask.jpg");
	loadimage(&img_char2, "./char2.jpg");             //角色动作（动作2）
	loadimage(&img_char2_mask, "./char2_mask.jpg");
	loadimage(&img_brick, "./brick.png");           //角色脚下砖块
	loadimage(&stone, "./stone.jpg");       //石头
	loadimage(&stone_mask, "./stone_mask.jpg");
	loadimage(&img_shop, "./shop.png");           //商店
	loadimage(&img_A, "./A.bmp");            //炸弹
	loadimage(&img_B, "./B.bmp");
	loadimage(&img_hook, "./hook.bmp");               //钩子
	loadimage(&img_hook_mask, "./hook_mask.bmp");
	loadimage(&img_gold, "./gold.png");
	loadimage(&img_gold_mask, "./gold_mask.png");    //金块
	loadimage(&img_barrel, "./barrel.png");
	loadimage(&img_barrel_mask, "./barrel_mask.png");         //炸药桶
	loadimage(&img_clear, "./clear.png");               //通关背景图
	loadimage(&img_C, "./rule.png");
	loadimage(&img_D, "./rule1.png");
	char_x = 340;        //人物坐标
	char_y = 30;
	x = char_x + 40;  //绳子固定一端的坐标
	y = char_y + 60;
	startbuttom_x = 100; //开始键的坐标
	startbuttom_y = 100;
	C_x = 300;   //游戏规则键的坐标
	C_y = 400;
	alpla = 0;     //绳子转过的弧度
	Get_Stone = 0;  //是否抓取石头
	Get_Gold = 0;   //是否抓取大黄金
	Get_Barrel = 0; //是否抓取炸药桶
	Get_Barrel1 = 0;
	Get_Barrel2 = 0;
	Get_Barrel3 = 0;
	is_Caughted = 0;
	is_Dead = 0;
	is_Bomb = 0;
	score = 0;
	Score = score + '0';    //将int转换成char，可以被outtext识别
	score_Extra = 0;
	Score_Extra = score_Extra + '0';
	radius = 50;  //绳子原来的长度
	bomb_num = 0;  //炸弹数量
	bomb_Num = bomb_num + '0';
	Remain_Stone = 1; //剩余的石头
	Remain_Gold = 1;  //剩余的黄金
	Remain_Barrel = 1;  //剩余的炸药桶
	Remain_Barrel1 = 1;
	Remain_Barrel2 = 1;
	Remain_Barrel3 = 1;
	stage = Stage + '0';  //关卡数
	sigh = 1;
	sigh_extra = 1;
	speed = 0;
	time_out = 0;
	out_time = 1;
	out_Time = out_time + '0';
	out_time_extra = 0;
	out_Time_extra = out_time_extra + '0';

	if (Stage == 1)        //第一关设定
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
	if (Stage == 2)       //第二关设定
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
	if (Stage == 3)  //第三关设定
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
void gamecontent()//游戏绘制
{
	BeginBatchDraw();//开启双缓冲绘图
	if (gameStatus == 1)  //处于游戏状态中
	{
		if (Stage == 1)     //第一关背景图
			putimage(0, 0, &img_game_bk_level0);
		if (Stage == 2)    //第二关背景图
			putimage(0, 0, &img_game_bk_level1);
		if (Stage == 3)   //第三关背景图
			putimage(0, 0, &img_game_bk_level0);
		putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);     //人物
		putimage(char_x, char_y, &img_char1, SRCINVERT);
		for (j = 0; j < 15; j++)                     //脚下的砖
			putimage(j * 70, 100, &img_brick);
		if (score >= 20)  //记分牌
		{
			score_Extra = 2;//十位数字
			Score_Extra = score_Extra + '0';
			score = score - 20;//个位
			Score = score + '0';
		}
		if (score >= 10 && score < 20)
		{
			score_Extra = 1;
			Score_Extra = score_Extra + '0';
			score = score - 10;
			Score = score + '0';
		}
		outtextxy(0, 0, "Score=");    //显示得分
		outtextxy(49, 0, Score_Extra);
		outtextxy(57, 0, Score);
		outtextxy(745, 0, "bomb=");   //显示炸弹数
		outtextxy(790, 0, bomb_Num);
		outtextxy(360, 0, "Stage:");  //显示关卡
		outtextxy(400, 0, stage);
	}
}
void show()//开始界面
{
	BeginBatchDraw();//开启双缓冲绘图
	if (gameStatus == 0)    //显示背景图片
		putimage(0, 0, &img_start_bk);
	    putimage(200, 400, &img_C);
	MOUSEMSG m;//鼠标感应
	m = GetMouseMsg();
	if (m.uMsg == WM_MOUSEMOVE)                  //当鼠标移动时
	{
		if ((abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) <= 200) && (gameStatus == 0))     //如果鼠标靠近开始键 “开始”的图片改变
			putimage(startbuttom_x, startbuttom_y, &img_start2);
		if ((abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) > 200) && (gameStatus == 0))       //如果未靠近则图片不变
			putimage(startbuttom_x, startbuttom_y, &img_start1);
	}
	if (m.uMsg == WM_LBUTTONDOWN)               //按鼠标左键时，进入关卡
	{
		if (abs(m.x - startbuttom_x) + abs(m.y - startbuttom_y) <= 200)
			gameStatus = 1;
	}
	if (m.uMsg == WM_LBUTTONDOWN)               //按鼠标左键时，出现规则
	{
		if (m.x > 250 && m.x < 350 && m.y>350 && m.y < 450)
			putimage(0, 0, &img_D);

	}
	FlushBatchDraw();
	Sleep(5);
	EndBatchDraw();
}
void gameover()                 //游戏结束
{
	if (gameStatus == 3)
	{
		Sleep(200);
		cleardevice();
		putimage(0, 0, &img_end);      //显示结束图片
		outtextxy(50, 50, "游戏结束");     //输出文字
		x1 = -100;          //清除绳子
		y1_ = -100;
		x = -100;
		y = -100;
		_getch();
		putimage(0, 0, &img_end);
		outtextxy(50, 50, "游戏结束");
	}
}
void time()//显示游戏时间
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
void rope();    //调用后面的函数
void midfield()   //中间界面
{
	putimage(0, 0, &img_clear); //放置中场背景图
	Sleep(1000);
	if (gameStatus == 2)
	{
		MOUSEMSG input;
		cleardevice();//清屏
		putimage(0, 0, &img_shop);//显示商店界面
		putimage(300, 360, &img_B, NOTSRCERASE);  //在商店里显示炸弹
		putimage(300, 360, &img_A, SRCINVERT);
		while (1)//防闪退
		{
			if (MouseHit())
			{
				input = GetMouseMsg();
				if (input.uMsg == WM_LBUTTONDOWN)        //鼠标移动
				{
					if (input.x >= 600 && input.x <= 700 && input.y >= 50 && input.y <= 150)     //若点击下一关
					{
						Stage++; //进入下一关
						int temp_bomb = bomb_num;    //定义临时变量记录炸弹数，防止在startup中被初始化为0
						int temp_score = score;    //定义临时变量记录积分的个位数，防止在startup中被初始化为0
						int temp_score_Extra = score_Extra;      //定义临时变量记录积分的十位数，防止在startup中被初始化为其他值
						startup();
						bomb_num = temp_bomb;
						bomb_Num = bomb_num + '0';
						score_Extra = temp_score_Extra;
						Score_Extra = score_Extra + '0';
						score = temp_score;
						Score = score + '0';
						cleardevice();
						gameStatus = 1;          //游戏状态变为1
						gamecontent();
						rope();
					}
					if (input.x >= 200 && input.x <= 350 && input.y >= 250 && input.y <= 450)    //若点击炸弹
					{
						if (score > 2)  //花费三积分购买一个炸弹
						{
							score = score - 3;
							Score = score + '0';//字符串与整型转换
							bomb_num++;
							bomb_Num = bomb_num + '0';
						}
						if (score_Extra == 1)  //如果积分大于10 小于20
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
						if (score_Extra == 2) //如果积分大于20
						{
							if (score <= 2)      //以下为积分的减法
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
			outtextxy(0, 0, "Score=");      //显示中场界面文字
			outtextxy(46, 0, Score_Extra);
			outtextxy(54, 0, Score);
			outtextxy(340, 400, "x");
			outtextxy(350, 400, bomb_Num);
			outtextxy(275, 450, "炸弹价格为3积分");
		}
	}
}

void item()            //使用道具
{
	char input;
	if (bomb_num > 0)      //当炸弹数量大于0时才能使用
	{
		if (_kbhit())
		{
			input = _getch();
			if (Get_Barrel == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //按下q键使用道具，破坏炸药桶 避免死亡
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel1 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //按下q键使用道具，破坏炸药桶 避免死亡
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel2 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //按下q键使用道具，破坏炸药桶 避免死亡
				{
					bomb_num--;
					bomb_Num = bomb_num + '0';
					is_Bomb = 0;
					is_Dead = 0;
				}
			}
			if (Get_Barrel3 == 1)
			{
				if ((input == 'q') || (input == 'Q'))            //按下q键使用道具，破坏炸药桶 避免死亡
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
void rope_body(double* m)             //使用指针记录此时的角度
{
	BeginBatchDraw();//开启双缓冲绘图
	int p;
	double temp_alpla;
	temp_alpla = *m;
	if (gameStatus == 1)            //处于游戏中的状态
	{
		for (i = 100; i <= 1000; i += 15)     //伸长
		{
			cleardevice();
			gamecontent();
			time();
			if (i % 4 != 0)                      //人物动作
			{
				putimage(char_x, char_y + 1, &img_char2_mask, NOTSRCERASE);
				putimage(char_x, char_y + 1, &img_char2, SRCINVERT);
			}
			if (i % 4 == 0)
			{
				putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);
				putimage(char_x, char_y, &img_char1, SRCINVERT);
			}
			//共同的道具的位置
			if (Remain_Stone > 0)  //放置石头图片
			{
				putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
				putimage(stone_x, stone_y, &stone, SRCINVERT);
			}
			if (Remain_Gold > 0)//放置金
			{
				putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
				putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			}
			if (Remain_Barrel > 0)          //放置炸药桶
			{
				putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel1 > 0)          //放置炸药桶
			{
				putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel2 > 0)          //放置炸药桶
			{
				putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
			}
			if (Remain_Barrel3 > 0)          //放置炸药桶
			{
				putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
			}
		x1 = x - radius * i * cos(temp_alpla) * 0.01;            //绳子尾端随着转过弧度的变化而变化的坐标
		y1_ = y + radius * i * sin(temp_alpla) * 0.01;
		if (fabs(x1 - 20 - stone_x) + fabs(y1_ - stone_y) <= 50)     //捉住石头
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
		if (fabs(x1 - 20 - gold_x) + fabs(y1_ - gold_y) <= 50)     //捉住金块
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
		if (fabs(x1 - 20 - barrel_x) + fabs(y1_ - barrel_y) <= 50 || fabs(x1 + 30 - barrel_x) + fabs(y1_ + 50 - barrel_y) <= 50)     //拾取到炸药桶
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
		if (fabs(x1 - 20 - barrel1_x) + fabs(y1_ - barrel1_y) <= 50 || fabs(x1 + 30 - barrel1_x) + fabs(y1_ + 50 - barrel1_y) <= 50)     //拾取到炸药桶
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
		if (fabs(x1 - 20 - barrel2_x) + fabs(y1_ - barrel2_y) <= 50 || fabs(x1 + 30 - barrel2_x) + fabs(y1_ + 50 - barrel2_y) <= 50)     //拾取到炸药桶
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
		if (fabs(x1 - 20 - barrel3_x) + fabs(y1_ - barrel3_y) <= 50 || fabs(x1 + 30 - barrel3_x) + fabs(y1_ + 50 - barrel3_y) <= 50)     //拾取到炸药桶
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
		if (is_Caughted == 1)            //当捉取到某物时，结束循环并记录绳子此时的位置
		{
			p = i;
			break;
		}
		Sleep(80);
	}

		if (is_Caughted == 0)       //若未捉取到物体，则伸到最远处后原路返回
			p = 1000;
		for (i = p; i >= 100; i -= 15)     //收缩
		{
			cleardevice();
			gamecontent();
			time();
			BeginBatchDraw();
			if (i % 4 != 0)     //动作
			{
				putimage(char_x, char_y + 1, &img_char2_mask, NOTSRCERASE);
				putimage(char_x, char_y + 1, &img_char2, SRCINVERT);
			}
			if (i % 4 == 0)
			{
				putimage(char_x, char_y, &img_char1_mask, NOTSRCERASE);
				putimage(char_x, char_y, &img_char1, SRCINVERT);
			}
			if (Remain_Stone > 0)      //石头未被抓走，则在此处继续放置石头，以下同理
			{
				putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
				putimage(stone_x, stone_y, &stone, SRCINVERT);
			}
			if (Remain_Gold > 0)
			{
				putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
				putimage(gold_x, gold_y, &img_gold, SRCINVERT);
			}
			
				if (Remain_Barrel > 0)      //静止的炸药桶
				{
					putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel1 > 0)      //静止的炸药桶
				{
					putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel2 > 0)      //静止的炸药桶
				{
					putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);

				}
				if (Remain_Barrel3 > 0)      //静止的炸药桶
				{
					putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
					putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);

				}
			x1 = x - radius * i * cos(temp_alpla) * 0.01;
			y1_ = y + radius * i * sin(temp_alpla) * 0.01;
			if (Get_Stone == 1)     //抓住某个物体后，物体跟随绳子移动，以下同理
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
				item();      //是否使用道具
				Sleep(10);
				if (is_Bomb == 1)     //不使用道具则爆炸
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //若使用道具，则等于0，不会爆炸
					gameover();
				}
			}
			if (Get_Barrel1 == 1)
			{
				barrel1_x = x1 - 20;
				barrel1_y = y1_;
				putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
				item();      //是否使用道具
				Sleep(10);
				if (is_Bomb == 1)     //不使用道具则爆炸
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //若使用道具，则等于0，不会爆炸
					gameover();
				}
			}
			if (Get_Barrel2 == 1)
			{
				barrel2_x = x1 - 20;
				barrel2_y = y1_;
				putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
				item();      //是否使用道具
				Sleep(10);
				if (is_Bomb == 1)     //不使用道具则爆炸
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //若使用道具，则等于0，不会爆炸
					gameover();
				}
			}
			if (Get_Barrel3 == 1)
			{
				barrel3_x = x1 - 20;
				barrel3_y = y1_;
				putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
				putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
				item();      //是否使用道具
				Sleep(10);
				if (is_Bomb == 1)     //不使用道具则爆炸
				{
					Sleep(100);
					gameStatus = 3;
					is_Dead = 1;     //若使用道具，则等于0，不会爆炸
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
			Sleep(speed);      //速度控制
			if (i == 100)    //结束后恢复钩子状态为没有东西
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
void rope()     //绳子本体
{
	setlinecolor(BLACK);    //设置绳子颜色为黑色
	GetLocalTime(&it);
	sec = it.wSecond;
	min = it.wMinute;
	if (gameStatus == 1)
	{
		BeginBatchDraw();
		while (1)
		{
			for (alpla = 0; alpla <= Pi; alpla += 0.02)          //绳子旋转
			{
				cleardevice();
				gamecontent();
				time();
				//当没有抓住任何东西时
				//收获某个物品后将其隐藏
				if (Remain_Stone > 0)       //当没有抓住任何东西时
				{
					putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
					putimage(stone_x, stone_y, &stone, SRCINVERT);
				}
				else if (Remain_Stone == 0)          //收获某个物品后将其隐藏
				{
					stone_x = -100;
					stone_y = -100;
				}
				if (Remain_Gold > 0)            //是否收获大金
				{
					putimage(gold_x, gold_y, &img_gold_mask, NOTSRCERASE);
					putimage(gold_x, gold_y, &img_gold, SRCINVERT);
				}
				else if (Remain_Gold == 0)
				{
					gold_x = -100;
					gold_y = -100;
				}
					if (Remain_Barrel>0)        //是否收获炸药桶
					{
						putimage(barrel_x, barrel_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel_x, barrel_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel == 0)
					{
						gameover();
					}
					if (Remain_Barrel1 > 0)        //是否收获炸药桶
					{
						putimage(barrel1_x, barrel1_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel1_x, barrel1_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel1 == 0)
					{
						gameover();
					}
					if (Remain_Barrel2 > 0)        //是否收获炸药桶
					{
						putimage(barrel2_x, barrel2_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel2_x, barrel2_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel2 == 0)
					{
						gameover();
					}
					if (Remain_Barrel3 > 0)        //是否收获炸药桶
					{
						putimage(barrel3_x, barrel3_y, &img_barrel_mask, NOTSRCERASE);
						putimage(barrel3_x, barrel3_y, &img_barrel, SRCINVERT);
					}
					else if (Remain_Barrel3 == 0)
					{
						gameover();
					}
				x1 = x - radius * cos(alpla);     //随角度变化而变的绳子尾坐标
				y1_ = y + radius * sin(alpla);
				putimage(x1 - 20, y1_, &img_hook_mask, NOTSRCERASE);
				putimage(x1 - 20, y1_, &img_hook, SRCINVERT);
				line(x, y, x1, y1_);
				FlushBatchDraw();
				EndBatchDraw();
				if (_kbhit())     //当键盘按下后
				{
					input = _getch();
					if (input == ' ')    //当按下空格时
						rope_body(&alpla);
				}
				Sleep(10);
			}
			if (gameStatus == 2)      //跳出游戏循环
			{
				break;
				gameover();
			}
			for (alpla = Pi; alpla >= 0; alpla -= 0.02)     //绳子反向旋转
			{
				cleardevice();
				gamecontent();
				time();
				if (Remain_Stone > 0)             //是否放置石头
				{
					putimage(stone_x, stone_y, &stone_mask, NOTSRCERASE);
					putimage(stone_x, stone_y, &stone, SRCINVERT);
				}
				else if (Remain_Stone == 0)
				{
					stone_x = -100;
					stone_y = -100;
				}
				if (Remain_Gold > 0)     //是否放置大金
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
				x1 = x - radius * cos(alpla);          //绳尾坐标随弧度变化而变化
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
						rope_body(&alpla);     //当按下空格后，记录当前弧度，且暂停转动
				}
				Sleep(10);
			}
			if (Stage == 1)    //以下为判断关卡结束的条件
			{
				if (score >= 4 && is_Dead == 0 && time_out == 0)                //结束条件为4分且不被炸死
				{
					gameStatus = 2;
					midfield();
				}
			}
			if (Stage == 2)
			{
				if (score + 10 * score_Extra >= 8 && is_Dead == 0 && time_out == 0)        //结束条件为8分且不被炸死
				{
					gameStatus = 2;
					midfield();
				}
			}
			if (Stage == 3)
			{
				if (score + 10 * score_Extra >= 12 && is_Dead == 0 && time_out == 0)    //结束条件为12分且不被炸死
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
	startup();   //数据初始化
	while (1)
	{
		if (gameStatus == 0)      //游戏状态为0，开始界面
			show();
		else if (gameStatus == 1)    //游戏状态为1，进入游戏
		{
			gamecontent();
			rope();
		}
	}
	return 0;
}