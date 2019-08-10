#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //随机种子生成函数
#include <math.h>
#include <string.h> 
#include <graphics.h>  //图像函数
#include <conio.h>
#include <windows.h> //Sleep函数使得程序暂停

//drawtext函数中字体位置设置的简化版
#define WORDLEFT DT_LEFT|DT_VCENTER|DT_SINGLELINE
#define WORDCENTER DT_CENTER|DT_VCENTER|DT_SINGLELINE

//颜色设置
#define BKCOLOR RGB(255,192,203)      //背景色为粉色
#define WORDCOLOR RGB(30,144,255)  //字体颜色为蓝色
//#define BKCOLOR RGB(192,192,192)      //背景色为灰色
//#define WORDCOLOR RGB(65,105,225)  //字体颜色为蓝色
#define LINECOLOR RGB(0,255,225)      //线条颜色为亮蓝色
#define BUTTON RGB(176,23,31)           //按钮颜色为深红色
#define BUTTONON RGB(255,0,0)         //按钮按下时，颜色为亮红色
#define BUTTONWORD RGB(0,255,127) //按钮上字的颜色为绿色
#define NEWBUTTON RGB(255,215,0)
#define NEWBUTTONWORD RGB(25,25,112)

//牌类型分类：1*：强酸；2*：弱酸；3*：强碱；4*：弱碱；
//5*：可燃物质；6*：氧气与氧化物；7*：强氧化性物质；8*：其他物质

//这几个函数是几个常用的变量，
//用在循环或是别的需要额外定义无实际意义变量的地方
//在每一次引用时都会进行初始化
//所以这些变量定义为全局变量更为方便一些
int i,j,m,serial2,check,lc1,lc2; 
FILE* filePtr=fopen("chemkillrecord.txt","a"); 

//规定人机对战涉及的基本属性
//包括血量，第几张牌，总牌数等数据
int Hp_of_computer=5;
int Hp_of_player=6;
int num_card_computer=0;
int num_card_player=0;
//因为输入手牌编号可能为两位数所以定义一个100的数组能保证不越界
int serial_num_computer[100]={0};
int serial_num_player[100]={0};

//给予玩家出牌阶段的提示
//void tips()

//收集鼠标点击信息输出出牌对应的编号
//int choosecard()

//收集三次鼠标点击信息
//得到出牌对应编号（一张牌或两张牌）
RECT pleaseuse1stcard={0,140,538,160};
//int youusecard() 

//该函数功能为
//在给定位置上（x，y），显示手牌编号对应的图像
IMAGE img11,img12,img13,img14,img15,
	       img21,img22,img23,img24,
	       img31,img32,img33,img34,
	       img41,img42,img43,img44,img45,
	       img51,img52,img53,img54,img55,img56,img57,img58,
		   img61,img62,img63,img64,img65,img66,img67,img68,
	       img71,img72,img73,
		   img81,img82,img83,img84,img85;
//void pictureofthecard(int m , int x ,int y)

//该函数功能为
//在给定位置上，显示手牌编号对应的手牌名称
//void nameofthecardinbattleinfo(int m,int x,int y)

//使得两张牌连续不重复
int totalcard=0;

//抽牌函数，随机给予牌的编码
//此函数主要执行下述功能：
//1.	运用随机函数m，使玩家及电脑的摸牌都具有随机效果
//2.	根据每种牌个数的不同，按照牌数比例指定每种牌对应的
//随机数m的区间，即将m的区间与随机数范围构成映射
//int getcard()



//介绍场上双方的手牌和血量
//此函数主要执行下述功能：
//1.	依次显示出电脑血量、电脑牌数、玩家血量、玩家牌数
//2.	利用循环依次显示出玩家的目前手牌
//void situation()

//这两个函数是player_use_1card,player_use_2cards在电脑出牌时的完全对应体
RECT comuse1card1={0,140,110,160}; 
RECT comuse1card2={200,140,350,160}; 
//void com_use_1card(int i)

//这两个函数是player_use_1card,player_use_2cards在电脑出牌时的完全对应体
RECT comuse2card1={0,140,110,160}; 
RECT comuse2card2={200,140,220,160}; 
RECT comuse2card3={310,140,350,160}; 
RECT comuse2card4={350,140,440,160};
//void com_use_2cards(int m,int n)

//void player_use_1card(int m)：此函数主要执行两个功能：
//1.显示参数m所对应的牌，即显示“你对电脑打出了XXX”；
//2.改变玩家的牌数组及牌数，首先将牌数减一，
//之后通过将m牌~第n张牌对应数字全部向前移动一位，
//并将最后一张牌归零，来达到清除m牌，
//并保证玩家的牌集中在数组前n-1个位置的目的。（n为出牌前总牌数）
RECT youuse1card1={0,140,110,160}; 
//void player_use_1card(int m)

//void player_use_2cards(int m1,int m2)与上一函数类似，此函数用于在玩家除两张牌时
//显示“你对电脑打出了XXX和YYY”；并改变玩家的牌数组及牌数，
//首先将牌数减二，之后通过将min{m1,m2}之后的牌迁移一位，
//再将max{m1,m2}之后的牌迁移一位，并将最后两张牌清零来达到清除m1、m2牌，
//并保证玩家的牌集中在数组前n-2个位置的目的。（n为出牌前总牌数）
RECT youuse2card1={0,140,110,160}; 
RECT youuse2card2={200,140,220,160}; 
RECT youuse2card3={310,140,350,160};
RECT youuse2card4={350,140,440,160};
//void player_use_2cards(int m1,int m2)

//该函数用来表示玩家的出牌过程
//在选择一张牌并打出后，手牌数量num_card_player减一，
//同时该牌后面的剩余手牌（数组serial_num_player[j] （j>m））
//依次向前平移一位，最后一张空手牌赋值为0
RECT youanswer1card={0,160,80,180}; 
//void player_answer_1card(int m)

//该函数用来表示电脑的出牌过程
//在选择一张牌并打出后，手牌数量num_card_player减一，
//同时该牌后面的剩余手牌（数组serial_num_computer[j] （j>m））
//依次向前平移一位，最后一张空手牌赋值为0
RECT comanswer1card={0,160,100,180}; 
//void com_answer_1card(int m)

//该函数主要起到玩家掉血并判断是否终止函数
//1.	输入“损失体力值”变量m
//2.	每次玩家受到体力损失时，显示出“你损失m点体力”，并在原有体力的基础上减m
//3.	当玩家体力Hp_of_player小于等于0时，显示“你输了”
RECT youloseblood1={0,160,50,180}; 
RECT youloseblood2={50,160,70,180}; 
RECT youloseblood3={70,160,120,180}; 
RECT youloseblood4={120,160,180,180}; 
//void player_lose_blood(int m)

//该函数主要起到电脑掉血并判断是否终止函数
//1.	输入“损失体力值”变量m
//2.	每次电脑受到体力损失时，显示出“电脑损失m点体力”，并在原有体力的基础上减m
//3.	当电脑体力Hp_of_computer小于等于0时，显示“你赢了”
RECT comloseblood1={0,160,65,180}; 
RECT comloseblood2={65,160,80,180}; 
RECT comloseblood3={80,160,130,180}; 
RECT comloseblood4={130,160,180,180}; 
//void com_lose_blood(int m)

//游戏开始时显示游戏开始和摸牌
RECT gamebegin={0,100,540,120};
//void gamestart(int inicardcom,int inicardplayer)


//void comturn(int comgetcard)
//***电脑使用一张手牌的程序实现
//电脑按照摸牌自动顺序来出牌，如果遇到了盐酸
//则先执行电脑出牌程序，即显示电脑出了什么牌并询问是否回答，
//并对电脑的牌数组进行相应改变
//此时录入玩家输入自己想要出的牌的编号
//如果玩家出了Mg/Al/Zn/CuO或强碱、弱碱中的一种，
//则对玩家牌数组进行相应改动并避免伤害，否则玩家血量减一。
//
//***电脑使用两张手牌的程序实现
//电脑按照摸牌自动顺序来出牌，如果遇到了氧气
//则开始检索可以燃烧的物质（即Al/CH4/Mg/H2/C/P4/S8/Zn）
//若检索到则先执行电脑出两张牌程序，即显示电脑出了哪两张牌并显示发生了燃烧反应
//并询问是否回答，并对电脑的牌数组进行相应改变。
//如果玩家出了Al(OH)3/H20/CO2中的一种，
//则对玩家牌数组进行相应改动并避免伤害，否则玩家血量减二。
RECT comstart={0,120,180,140}; 
RECT comget_card={180,120,200,140};
RECT comstart2={200,120,300,140}; 
//void comturn(int comgetcard) 

/*电脑出牌回合与玩家出牌回合函数的分界线*/

//void yourturn(int yougetcard)
//***你使用一张手牌的程序实现
//玩家如果摸到HCl牌，则先执行玩家出牌程序，
//即显示玩家出了什么牌，并对玩家的牌数组进行相应改变
//此时，搜索电脑有的所有牌，若遇到了Mg/Al/Zn/CuO或强碱、弱碱中的一种
//则电脑出之并对电脑牌数组进行相应改动且避免伤害，否则电脑血量减一。
//
//玩家想要燃烧攻击则需要两张牌
//此后显示玩家出了什么牌，并对玩家的牌数组进行相应改变
//此时，搜索电脑有的所有牌，若遇到了Al(OH)3/H20/CO2中的一种
//则对电脑牌数组进行相应改动并避免伤害，否则电脑血量减二。
RECT yourstart={0,120,155,140}; 
RECT youget_card={155,120,180,140};
RECT yourstart2={180,120,260,140};
RECT dropcard={0,120,540,140};
RECT dropcard2={0,140,540,160};
RECT usemycard={1010,460,1070,520};
RECT reuseyourcard={0,140,530,160}; 
RECT newbuttonword={1010,300,1070,340};
//void yourturn(int yougetcard)


//iniconcard决定电脑在游戏开始时的摸牌数
//iniplayercard决定玩家在游戏开始时的摸牌数
//speed决定电脑和玩家在游戏回合中的摸牌数-1
int inicomcard=0,iniplayercard=0,speed=0;

//通过画文本和按键实现玩家选择游戏难度和游戏速度的功能
//按键点亮操作是通过画一个更亮的按键进行覆盖
RECT gamerule1={0,0,540,20};
RECT gamerule2={0,20,1000,40};
RECT gamerule3={0,40,1000,60};
RECT welcome1={0,60,1000,80};
RECT mode1={0,80,80,100};
RECT mode2={90,80,170,100};
RECT mode3={180,80,260,100};
RECT speedtext={300,60,500,80};
RECT speed1={300,80,380,100};
RECT speed2={390,80,470,100};
RECT nocard={1010,380,1070,440};
//void gamechoice()

//int main()





void tips()
{
	int tipcard,tipcard2,possible;
	for(i=1;i<=num_card_player;i++)
	{
		tipcard=serial_num_player[i];
		if(tipcard/10==1||tipcard/10==3||tipcard==65||tipcard==66){
			setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);Sleep(1000);
			setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
			break;
		}
		else if(tipcard==61){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2/10==5){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		}
		else if(tipcard==23||tipcard==24){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2/10==3||tipcard2==44||tipcard2==45||tipcard2==84){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		}
		else if(tipcard==51||tipcard==53||tipcard==55||tipcard==56||tipcard==57
			||tipcard==58||tipcard==82||tipcard==84){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2==12){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		} 
		 else if(tipcard==67){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2==21){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		} 
		 else if(tipcard==71||tipcard==72||tipcard==73){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2==11){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		} 
		else if(tipcard==56){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2/10==3){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		} 
		else if(tipcard==82||tipcard==84){
			possible=0;
			for(serial2=1;serial2<=num_card_player;serial2++)
			{
				tipcard2=serial_num_player[serial2];
				if(tipcard2==11||tipcard2==13||tipcard2==14){
					setcolor(BUTTONON);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);Sleep(1500);
			        setcolor(WORDCOLOR);rectangle(10+110*(i-1),380,110*i,520);
					rectangle(10+110*(serial2-1),380,110*serial2,520);possible=1;break;
				}
			}
			if(possible==1)break;
		}
	}
}
int choosecard()
{
	while(1)
	{
		MOUSEMSG m=GetMouseMsg();
		if(m.mkLButton)
		{
			if(m.y>=380&&m.y<=520&&m.x>=10&&m.x<=110){return 1;break;}
			if(m.y>=380&&m.y<=520&&m.x>=120&&m.x<=220){return 2;break;}
			if(m.y>=380&&m.y<=520&&m.x>=230&&m.x<=330){return 3;break;}
			if(m.y>=380&&m.y<=520&&m.x>=340&&m.x<=440){return 4;break;}
			if(m.y>=380&&m.y<=520&&m.x>=450&&m.x<=550){return 5;break;}
			if(m.y>=380&&m.y<=520&&m.x>=560&&m.x<=660){return 6;break;}
			if(m.y>=380&&m.y<=520&&m.x>=670&&m.x<=770){return 7;break;}
			if(m.y>=380&&m.y<=520&&m.x>=780&&m.x<=880){return 8;break;}
			if(m.y>=380&&m.y<=520&&m.x>=890&&m.x<=990){return 9;break;}
			if(m.y>=380&&m.y<=440&&m.x>=1010&&m.x<=1070){return 0;break;}
			if(m.y>=300&&m.y<=340&&m.x>=1010&&m.x<=1070){tips();}
		}
	}
}
int youusecard()                    
{
	int calc=0;
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,179);
	setcolor(WORDCOLOR);
	drawtext(_T("请点击第一张牌,若不出牌请点击“不出牌”"),&pleaseuse1stcard,WORDLEFT);
    calc+=choosecard();
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,160);
	setcolor(WORDCOLOR);
	drawtext(_T("请点击第二张牌，若只出一张牌或不出牌请点击“不出牌”"),&pleaseuse1stcard,WORDLEFT);
	calc+=(10*choosecard());
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,160);
	setcolor(WORDCOLOR);
	drawtext(_T("请点击“出牌”"),&pleaseuse1stcard,WORDLEFT);
	while(1)
	{
		MOUSEMSG m=GetMouseMsg();
	    if(m.mkLButton)
		{
			if(m.y>=460&&m.y<=520&&m.x>=1010&&m.x<=1070){break;}
		}
	}
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,160);
	setcolor(WORDCOLOR);
	return calc;
}
void pictureofthecard(int m , int x ,int y)
{
switch(m)
{
    case 11:loadimage(&img11,_T("picture\\HCl.jpg"));putimage(x,y,&img11);break;
    case 12:loadimage(&img12,_T("picture\\HNO3.jpg"));putimage(x,y,&img12);break;
    case 13:loadimage(&img13,_T("picture\\H2SO4.jpg"));putimage(x,y,&img13);break;
    case 14:loadimage(&img14,_T("picture\\HI.jpg"));putimage(x,y,&img14);break;
    case 15:loadimage(&img15,_T("picture\\HClO4.jpg"));putimage(x,y,&img15);break;

    case 21:loadimage(&img21,_T("picture\\HF.jpg"));putimage(x,y,&img21);break;
    case 22:loadimage(&img22,_T("picture\\H2S.jpg"));putimage(x,y,&img22);break;
    case 23:loadimage(&img23,_T("picture\\NH4Cl.jpg"));putimage(x,y,&img23);break;
    case 24:loadimage(&img24,_T("picture\\NH4NO3.jpg"));putimage(x,y,&img24);break;

    case 31:loadimage(&img31,_T("picture\\NaOH.jpg"));putimage(x,y,&img31);break;
    case 32:loadimage(&img32,_T("picture\\KOH.jpg"));putimage(x,y,&img32);break;
    case 33:loadimage(&img33,_T("picture\\Ca(OH)2.jpg"));putimage(x,y,&img33);break;
	case 34:loadimage(&img34,_T("picture\\Ba(OH)2.jpg"));putimage(x,y,&img34);break;

    case 41:loadimage(&img41,_T("picture\\NH3·H2O.jpg"));putimage(x,y,&img41);break;
    case 42:loadimage(&img42,_T("picture\\Al(OH)3.jpg"));putimage(x,y,&img42);break;
    case 43:loadimage(&img43,_T("picture\\Al2O3.jpg"));putimage(x,y,&img43);break;
    case 44:loadimage(&img44,_T("picture\\NaHCO3.jpg"));putimage(x,y,&img44);break;
    case 45:loadimage(&img45,_T("picture\\Na2CO3.jpg"));putimage(x,y,&img45);break;

    case 51:loadimage(&img51,_T("picture\\Al.jpg"));putimage(x,y,&img51);break;
    case 52:loadimage(&img52,_T("picture\\CH4.jpg"));putimage(x,y,&img52);break;
    case 53:loadimage(&img53,_T("picture\\Mg.jpg"));putimage(x,y,&img53);break;
    case 54:loadimage(&img54,_T("picture\\H2.jpg"));putimage(x,y,&img54);break;
    case 55:loadimage(&img55,_T("picture\\C.jpg"));putimage(x,y,&img55);break;
    case 56:loadimage(&img56,_T("picture\\P4.jpg"));putimage(x,y,&img56);break;
    case 57:loadimage(&img57,_T("picture\\S8.jpg"));putimage(x,y,&img57);break;
    case 58:loadimage(&img58,_T("picture\\Zn.jpg"));putimage(x,y,&img58);break;

    case 61:loadimage(&img61,_T("picture\\O2.jpg"));putimage(x,y,&img61);break;
    case 62:loadimage(&img62,_T("picture\\H2O.jpg"));putimage(x,y,&img62);break;
    case 63:loadimage(&img63,_T("picture\\CO2.jpg"));putimage(x,y,&img63);break;
    case 64:loadimage(&img64,_T("picture\\P2O5.jpg"));putimage(x,y,&img64);break;
    case 65:loadimage(&img65,_T("picture\\NO.jpg"));putimage(x,y,&img65);break;
    case 66:loadimage(&img66,_T("picture\\NO2.jpg"));putimage(x,y,&img66);break;
    case 67:loadimage(&img67,_T("picture\\SiO2.jpg"));putimage(x,y,&img67);break;
    case 68:loadimage(&img68,_T("picture\\CuO.jpg"));putimage(x,y,&img68);break;

    case 71:loadimage(&img71,_T("picture\\KMnO4.jpg"));putimage(x,y,&img71);break;
    case 72:loadimage(&img72,_T("picture\\K2Cr2O7.jpg"));putimage(x,y,&img72);break;
    case 73:loadimage(&img73,_T("picture\\NaClO.jpg"));putimage(x,y,&img73);break;

    case 81:loadimage(&img81,_T("picture\\H2O2.jpg"));putimage(x,y,&img81);break;
    case 82:loadimage(&img82,_T("picture\\NaHSO3.jpg"));putimage(x,y,&img82);break;
    case 83:loadimage(&img83,_T("picture\\Na2O2.jpg"));putimage(x,y,&img83);break;
    case 84:loadimage(&img84,_T("picture\\Na2S.jpg"));putimage(x,y,&img84);break;
    case 85:loadimage(&img85,_T("picture\\FeSO4.jpg"));putimage(x,y,&img85);break;
}
}
void nameofthecardinbattleinfo(int m,int x,int y)
{
	int x_=x,y_=y;
	RECT whichcarduse={x_,y_,x_+90,y_+20};
	switch (m)
	{
//1*：强酸
	case 11:drawtext(_T("HCl"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 12:drawtext(_T("HNO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 13:drawtext(_T("H2SO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 14:drawtext(_T("HI"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 15:drawtext(_T("HClO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//2*：弱酸
	case 21:drawtext(_T("HF"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 22:drawtext(_T("H2S"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 23:drawtext(_T("NH4Cl"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 24:drawtext(_T("NH4NO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//3*：强碱
	case 31:drawtext(_T("NaOH"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 32:drawtext(_T("KOH"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 33:drawtext(_T("Ca(OH)2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 34:drawtext(_T("Ba(OH)2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//4*：弱碱
	case 41:drawtext(_T("NH3·H2O"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 42:drawtext(_T("Al(OH)3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 43:drawtext(_T("Al2O3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 44:drawtext(_T("NaHCO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 45:drawtext(_T("Na2CO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//5*：可燃物质
	case 51:drawtext(_T("Al"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 52:drawtext(_T("CH4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 53:drawtext(_T("Mg"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 54:drawtext(_T("H2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 55:drawtext(_T("C"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 56:drawtext(_T("P4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 57:drawtext(_T("S8"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 58:drawtext(_T("Zn"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//6*：氧气与氧化物
	case 61:drawtext(_T("O2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 62:drawtext(_T("H2O"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 63:drawtext(_T("CO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 64:drawtext(_T("P2O5"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 65:drawtext(_T("NO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 66:drawtext(_T("NO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 67:drawtext(_T("SiO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 68:drawtext(_T("CuO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//7*：强氧化性物质
	case 71:drawtext(_T("KMnO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 72:drawtext(_T("K2Cr2O7"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 73:drawtext(_T("NaClO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//8*：其他物质
	case 81:drawtext(_T("H2O2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 82:drawtext(_T("NaHSO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 83:drawtext(_T("Na2O2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 84:drawtext(_T("Na2S"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 85:drawtext(_T("FeSO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	}
}
int getcard()
{
	srand((unsigned) time (NULL));
	int m =(rand()+totalcard)%112;
	totalcard+=1;
    if(m==0)return 15;
	else if(m==2)return 62;
	else if(m==3)return 61;
	else if(m==4)return 14;
	else if(m==5)return 11;
	else if(m==6)return 73;
	else if(m==7)return 72;
	else if(m==8)return 52;
	else if(m==9)return 73;
	else if(m==1)return 24;
	else if(m==10)return 62;
	else if(m==11)return 53;
	else if(m==12)return 61;
	else if(m==13)return 73;
	else if(m==14)return 66;
	else if(m==15)return 57;
	else if(m==16)return 54;
	else if(m==17)return 63;
	else if(m==18)return 44;
	else if(m==19)return 12;
	else if(m==20)return 62;
	else if(m==21)return 41;
	else if(m==22)return 41;
	else if(m==23)return 11;
	else if(m==24)return 11;
	else if(m==25)return 61;
	else if(m==26)return 11;
	else if(m==27)return 65;
	else if(m==28)return 58;
	else if(m==29)return 31;
	else if(m==30)return 11;
	else if(m==31)return 41;
	else if(m==32)return 41;
	else if(m==33)return 62;
	else if(m==34)return 31;
	else if(m==35)return 64;
	else if(m==36)return 82;
	else if(m==37)return 84;
	else if(m==38)return 57;
	else if(m==39)return 41;
	else if(m==40)return 41;
	else if(m==41)return 82;
	else if(m==42)return 31;
	else if(m==43)return 12;
	else if(m==44)return 57;
	else if(m==45)return 62;
	else if(m==46)return 63;
	else if(m==47)return 11;
	else if(m==48)return 61;
	else if(m==49)return 11;
	else if(m==50)return 31;
	else if(m==51)return 21;
	else if(m==52)return 71;
	else if(m==53)return 31;
	else if(m==54)return 13;
	else if(m==55)return 41;
	else if(m==56)return 13;
	else if(m==57)return 51;
	else if(m==58)return 11;
	else if(m==59)return 82;
	else if(m==60)return 45;
	else if(m==61)return 31;
	else if(m==62)return 11;
	else if(m==63)return 85;
	else if(m==64)return 32;
	else if(m==65)return 61;
	else if(m==66)return 84;
	else if(m==67)return 12;
	else if(m==68)return 41;
	else if(m==69)return 41;
	else if(m==70)return 12;
	else if(m==71)return 12;
	else if(m==72)return 34;
	else if(m==73)return 43;
	else if(m==74)return 23;
	else if(m==75)return 45;
	else if(m==76)return 12;
	else if(m==77)return 12;
	else if(m==78)return 33;
	else if(m==79)return 81;
	else if(m==80)return 83;
	else if(m==81)return 61;
	else if(m==82)return 56;
	else if(m==83)return 21;
	else if(m==84)return 21;
	else if(m==85)return 71;
	else if(m==86)return 42;
	else if(m==87)return 83;
	else if(m==88)return 11;
	else if(m==89)return 13;
	else if(m==90)return 56;
	else if(m==91)return 11;
	else if(m==92)return 12;
	else if(m==93)return 41;
	else if(m==94)return 72;
	else if(m==95)return 62;
	else if(m==96)return 53;
	else if(m==97)return 67;
	else if(m==98)return 23;
	else if(m==99)return 22;
	else if(m==100)return 11;
	else if(m==101)return 54;
	else if(m==102)return 12;
	else if(m==103)return 71;
	else if(m==104)return 41;
	else if(m==105)return 82;
	else if(m==106)return 68;
	else if(m==107)return 45;
	else if(m==108)return 82;
	else if(m==109)return 24;
	else if(m==110)return 41;
	else if(m==111)return 55;
	else return 11;
}
void situation()
{
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(1,179,1010,540);
	setcolor(LINECOLOR);
	line(540,0,540,180);
	line(0,180,1080,180);
	line(0,360,1080,360);
	line(0,540,1080,540);
	setcolor(WORDCOLOR);
	for(i=1;i<=num_card_player;i++)
	{
		pictureofthecard(serial_num_player[i],10+110*(i-1),380);
		rectangle(110*i-100,380,110*i,520);
	}
	setcolor(RGB(255,0,0));
	RECT r={0,240,540,300};
	drawtext(_T("HP of the computer"),&r,WORDLEFT);
	if(num_card_computer==0)
	{
		drawtext(_T("电脑手里没牌"),&r,WORDCENTER);
	}
	if(num_card_computer==1)
	{
		drawtext(_T("电脑手里有1张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==2)
	{
		drawtext(_T("电脑手里有2张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==3)
	{
		drawtext(_T("电脑手里有3张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==4)
	{
		drawtext(_T("电脑手里有4张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==5)
	{
		drawtext(_T("电脑手里有5张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==6)
	{
		drawtext(_T("电脑手里有6张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==7)
	{
		drawtext(_T("电脑手里有7张牌"),&r,WORDCENTER);
	}
	if(num_card_computer==8)
	{
		drawtext(_T("电脑手里有8张牌"),&r,WORDCENTER);
	}
	if(Hp_of_computer>=1)
	{   setfillcolor(RGB( 255, 0, 0));
		fillrectangle( 10, 305, 70, 355);
	}
	if(Hp_of_computer>=2)
	{   setfillcolor(RGB( 215, 40, 0));
		fillrectangle( 70, 305, 130, 355);
	}
	if(Hp_of_computer>=3)
	{   setfillcolor(RGB(175,80, 0));
		fillrectangle( 130, 305, 190, 355);
	}
	if(Hp_of_computer>=4)
	{   setfillcolor(RGB( 135, 120, 0));
		fillrectangle( 190, 305, 250, 355);
	}
	if(Hp_of_computer>=5)
	{   setfillcolor(RGB( 95, 160, 0));
		fillrectangle( 250, 305, 310, 355);
	}
	setcolor(RGB(255,0,0));
	RECT r2={540,240,1080,300};
	drawtext(_T("HP of the player"),&r2,WORDLEFT);
	if(num_card_player==0)
	{
		drawtext(_T("你手里没牌了"),&r2,WORDCENTER);
	}
	if(num_card_player==1)
	{
		drawtext(_T("你手里有1张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==2)
	{
		drawtext(_T("你手里有2张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==3)
	{
		drawtext(_T("你手里有3张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==4)
	{
		drawtext(_T("你手里有4张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==5)
	{
		drawtext(_T("你手里有5张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==6)
	{
		drawtext(_T("你手里有6张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==7)
	{
		drawtext(_T("你手里有7张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==8)
	{
		drawtext(_T("你手里有8张牌"),&r2,WORDCENTER);
	}
	if(num_card_player==9)
	{
		drawtext(_T("你手里有9张牌"),&r2,WORDCENTER);
	}
	if(Hp_of_player>=1)
	{   setfillcolor(RGB( 255, 0, 0));
		fillrectangle( 10+540, 305, 70+540, 355);
	}
	if(Hp_of_player>=2)
	{   setfillcolor(RGB( 215, 40, 0));
		fillrectangle( 70+540, 305, 130+540, 355);
	}
	if(Hp_of_player>=3)
	{   setfillcolor(RGB(175,80, 0));
		fillrectangle( 130+540, 305, 190+540, 355);
	}
	if(Hp_of_player>=4)
	{   setfillcolor(RGB( 135, 120, 0));
		fillrectangle( 190+540, 305, 250+540, 355);
	}
	if(Hp_of_player>=5)
	{   setfillcolor(RGB( 95, 160, 0));
		fillrectangle( 250+540, 305, 310+540, 355);
	}
	if(Hp_of_player>=6){   
		setfillcolor(RGB( 35, 220, 0));
		fillrectangle( 310+540, 305, 370+540, 355);
	}
}
void com_use_1card(int i)
{
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
	pictureofthecard(serial_num_computer[i],560,20);
	fillrectangle(0,140,538,180);
	setcolor(WORDCOLOR);
	drawtext(_T("电脑对你使用了"),&comuse1card1,WORDLEFT);
	int k=serial_num_computer[i];
	nameofthecardinbattleinfo(k,110,140);
	drawtext(_T("请问你是否应答"),&comuse1card2,WORDLEFT);
	num_card_computer-=1;
	for (j=i;j<=num_card_computer;j++)
	{
		serial_num_computer[j]=serial_num_computer[j+1];
	}
	serial_num_computer[num_card_computer+1]=0;
	situation();
}
void com_use_2cards(int m,int n)
{
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
	pictureofthecard(serial_num_computer[m],560,20);
	pictureofthecard(serial_num_computer[n],760,20);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(0,140,538,180);
	setcolor(WORDCOLOR);
	drawtext(_T("电脑对你使用了"),&comuse2card1,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_computer[m],110,140);
	drawtext(_T("和"),&comuse2card2,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_computer[n],220,140);
	drawtext(_T("生成"),&comuse2card3,WORDLEFT);
	num_card_computer-=2;
	if(n<m)
	{
		for (j=m;j<=num_card_computer+1;j++)
	    {
			serial_num_computer[j]=serial_num_computer[j+1];
		}
		for (j=n;j<=num_card_computer;j++)
		{
			serial_num_computer[j]=serial_num_computer[j+1];
		}
	}
	else
	{
	    for (j=n;j<=num_card_computer+1;j++)
		{
		    serial_num_computer[j]=serial_num_computer[j+1];
		}
		for (j=m;j<=num_card_computer;j++)
		{
			serial_num_computer[j]=serial_num_computer[j+1];
		}
	}
	serial_num_computer[num_card_computer+1]=0;
	serial_num_computer[num_card_computer+2]=0;
}
void player_use_1card(int m)
{
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
	pictureofthecard(serial_num_player[m],560,20);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(0,140,538,178);
	setcolor(WORDCOLOR);
	drawtext(_T("你对电脑使用了"),&youuse1card1,WORDLEFT);
	int k=serial_num_player[m];
	nameofthecardinbattleinfo(k,110,140);
	num_card_player--;
	for (j=m;j<=num_card_player;j++)
	{
		serial_num_player[j]=serial_num_player[j+1];
	}
	serial_num_player[num_card_player+1]=0;
}
void player_use_2cards(int m1,int m2)
{
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
	pictureofthecard(serial_num_player[m1],560,20);
	pictureofthecard(serial_num_player[m2],760,20);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(0,140,538,178);
	setcolor(WORDCOLOR);
	drawtext(_T("你对电脑使用了"),&youuse2card1,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_player[m1],110,140);
	drawtext(_T("和"),&youuse2card2,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_player[m2],220,140);
	drawtext(_T("生成"),&youuse2card3,WORDLEFT);
	num_card_player-=2;
	if(m2>m1)
	{
		for (j=m2;j<=num_card_player+1;j++)
	    {
			serial_num_player[j]=serial_num_player[j+1];
		}
		for (j=m1;j<=num_card_player;j++)
		{
			serial_num_player[j]=serial_num_player[j+1];
		}
	}
	else
	{
	    for (j=m1;j<=num_card_player+1;j++)
		{
		    serial_num_player[j]=serial_num_player[j+1];
		}
		for (j=m2;j<=num_card_player;j++)
		{
			serial_num_player[j]=serial_num_player[j+1];
		}
	}
	serial_num_player[num_card_player+1]=0;
	serial_num_player[num_card_player+2]=0;
}
void player_answer_1card(int m)
{
	pictureofthecard(serial_num_player[m],960,20);
	setcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("你打出了"),&youanswer1card,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_player[m],80,160);
	num_card_player--;
	for (j=m;j<=num_card_player;j++)
	{
		serial_num_player[j]=serial_num_player[j+1];
	}
	situation();
	serial_num_player[num_card_player+1]=0;
	Sleep(2000);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
}
void com_answer_1card(int m)
{
	pictureofthecard(serial_num_computer[m],960,20);
	setcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("电脑打出了"),&youanswer1card,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_computer[m],100,160);
	num_card_computer-=1;
	for (j=m;j<=num_card_computer;j++)
	{
		serial_num_computer[j]=serial_num_computer[j+1];
	}
	serial_num_computer[num_card_computer+1]=0;
	situation(); 
	Sleep(2000);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
}
void player_lose_blood(int m)
{
	Hp_of_player-=m;
	setcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("你损失"),&youloseblood1,WORDLEFT);
	if(m==1){drawtext(_T("1"),&youloseblood2,WORDCENTER);}
	if(m==2){drawtext(_T("2"),&youloseblood2,WORDCENTER);}
	drawtext(_T("点体力"),&youloseblood3,WORDLEFT);
	situation();
	if(Hp_of_player<=0)
	{
		drawtext(_T("你输了"),&youloseblood4,DT_LEFT|DT_VCENTER|DT_SINGLELINE);
		fputs("You lose.",filePtr);
		fclose(filePtr);
		situation();
		Sleep(10000);
		exit(1);
	}
	Sleep(2000);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
}
void com_lose_blood(int m)
{
	setcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("电脑损失"),&comloseblood1,WORDLEFT);
	if(m==1){drawtext(_T("1"),&comloseblood2,WORDCENTER);}
	if(m==2){drawtext(_T("2"),&comloseblood2,WORDCENTER);}
	drawtext(_T("点体力"),&comloseblood3,WORDLEFT);
	Hp_of_computer-=m;
	if(Hp_of_computer<=0)
	{
		drawtext(_T("你赢了"),&comloseblood4,WORDLEFT);
		fputs("You win.",filePtr);
		fclose(filePtr);
		situation();
		Sleep(10000);
		exit(1);
	}
	situation();
	Sleep(2000);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(541,0,1080,178);
}
void gamestart(int inicardcom,int inicardplayer)
{
	//初始阶段，角色摸取规定数量的牌
	for(i=1;i<=inicardcom;i++)
	{
		num_card_computer++;
		serial_num_computer[num_card_computer] = getcard();
	} 
	for(i=1;i<=inicardplayer;i++)
	{ 
		num_card_player++;
		serial_num_player[num_card_player] = getcard();
	}
	//欢迎界面
	drawtext(_T("欢迎来到chemkill3.0，现在进行的是人机对战"),&gamebegin,WORDLEFT);
	situation();
}
void comturn(int comgetcard) 
{
//电脑出牌回合
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(1010,300,1070,340);
	setcolor(BKCOLOR);
	setfillcolor(BKCOLOR);
	fillrectangle(1009,459,1071,521);
	setfillcolor(BKCOLOR);
	setbkcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,120,538,200);
	setcolor(WORDCOLOR);
	drawtext(_T("电脑的回合开始 电脑摸取"),&comstart,WORDLEFT);
	int k=comgetcard;
	if(comgetcard==2){drawtext(_T("2"),&comget_card,WORDCENTER);}
	if(comgetcard==3){drawtext(_T("3"),&comget_card,WORDCENTER);}
	drawtext(_T("张牌"),&comstart2,WORDLEFT);
    for(m=1;m<=k;m++)//电脑先摸三张牌
    {
		num_card_computer++;
	    serial_num_computer[num_card_computer] = getcard();
    }
    int serial=1;//这里i表示电脑的手牌编号
    while(serial<=num_card_computer&&Hp_of_player>0)
	{
//*******2.1.1电脑使用盐酸
	    if (serial_num_computer[serial]==11)
	    {
		    //使用这张牌对电脑的手牌带来的改变
		    com_use_1card(serial);
		    //询问是否对此进行应答
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //如果你能避免这张牌给你带来的伤害
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==51||yourcard==53||yourcard==58||yourcard==68))
		    {
			    player_answer_1card(usingcard);
		    }
		    //否则
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.1.2电脑使用硫酸，氢碘酸
	    else if (serial_num_computer[serial]==13||serial_num_computer[serial]==14)
	    {
		    //使用这张牌对电脑的手牌带来的改变
		    com_use_1card(serial);
		    //询问是否对此进行应答
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //如果你能避免这张牌给你带来的伤害
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==68||yourcard==73||yourcard==51||yourcard==53||yourcard==58||yourcard==83))
		    {
			    player_answer_1card(usingcard);
		    }
		    //否则
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.1.3电脑使用硝酸、高氯酸
	    else if (serial_num_computer[serial]==12||serial_num_computer[serial]==15)
	    {
	    //使用这张牌对电脑的手牌带来的改变
		    com_use_1card(serial);
		    //询问是否对此进行应答
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //如果你能避免这张牌给你带来的伤害
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==68||yourcard==73))
		    {
			    player_answer_1card(usingcard);
		    }
		    //否则
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.2.1电脑使用强碱
	    else if (serial_num_computer[serial]/10==3)
	    {
		    //使用这张牌对电脑的手牌带来的改变
		    com_use_1card(serial);
		    //询问是否对此进行应答
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //如果你能避免这张牌给你带来的伤害
		    if(usingcard>=0&&usingcard<=num_card_player
			&&(yourcard/10==1||yourcard/10==2||yourcard==42||yourcard==43||yourcard==44||yourcard==51||yourcard==57||yourcard==58
			||yourcard==63||yourcard==64||yourcard==66||yourcard==67||yourcard==72||yourcard==82||yourcard==85))
		    {
			    player_answer_1card(usingcard);
		    }
		    //否则
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.3.1电脑使用燃烧
       	else if (serial_num_computer[serial]==61)
	    {
	    	check=0;
		    for(serial2=1;serial2<=num_card_computer;serial2++)
		    {
			    if(serial_num_computer[serial2]/10==5)
			    {
	                com_use_2cards(serial,serial2);
					drawtext(_T("燃烧反应"),&comuse2card4,WORDCENTER);
					situation();
	                //询问是否对此进行应答
	                int usingcard=0;
	                usingcard=choosecard();
		            int yourcard=serial_num_player[usingcard];
	                //如果你能避免这张牌给你带来的伤害
				    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard==42||yourcard==62||yourcard==63))
	                {
		                player_answer_1card(usingcard);
	                }
	                //否则
	                else
	                {
		                player_lose_blood(2);
	                }
	                check=1;
				    break;
                }
			}
		    if(check==0)
		    {
		    	serial+=1;
			}
		}
//*******2.4.1
        else if (serial_num_computer[serial]==65)
        {
            com_use_1card(serial);
            int usingcard=0;
            usingcard=choosecard();
            int yourcard=serial_num_player[usingcard];
            if(usingcard>=0&&usingcard<=num_card_player&&(yourcard==83))
            {
                player_answer_1card(usingcard);
            }
            else
            {
                player_lose_blood(2);
            }
        }
//*******2.4.2
        else if (serial_num_computer[serial]==66)
        {
            com_use_1card(serial);
            int usingcard=0;
            usingcard=choosecard();
            int yourcard=serial_num_player[usingcard];
            if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45||yourcard==85))
            {
                player_answer_1card(usingcard);
            }
            else
            {
                player_lose_blood(2);
            }
        }
            
//*******2.5.1
        else if (serial_num_computer[serial]==23)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]/10==3||serial_num_computer[serial2]==44||serial_num_computer[serial2]==45||serial_num_computer[serial2]==84)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NH3"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==1||yourcard==21||yourcard==22||yourcard==62||yourcard==65||yourcard==66||yourcard==82||yourcard==85))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.2
        else if (serial_num_computer[serial]==24)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]/10==3||serial_num_computer[serial2]==44||serial_num_computer[serial2]==45||serial_num_computer[serial2]==84)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NH3"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==1||yourcard==21||yourcard==22||yourcard==62||yourcard==65||yourcard==66||yourcard==82||yourcard==85))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.3
        else if (serial_num_computer[serial]==51||serial_num_computer[serial]==53||serial_num_computer[serial]==58
			||serial_num_computer[serial]==82||serial_num_computer[serial]==84)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==12)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NO"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard==83))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        } 
            
//*******2.5.4
        else if (serial_num_computer[serial]==55)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==12)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NO2"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
                                          
//*******2.5.5
        else if (serial_num_computer[serial]==57)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==12)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NO2与SO2"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.6
        else if (serial_num_computer[serial]==67)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==21)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("SiF4"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45||yourcard==62))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
        
//*******2.5.7
        else if (serial_num_computer[serial]==71||serial_num_computer[serial]==72||serial_num_computer[serial]==73)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==11)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("Cl2"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45||yourcard==84||yourcard==85))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.8
        else if (serial_num_computer[serial]==82)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==11||serial_num_computer[serial2]==13||serial_num_computer[serial2]==14
					||serial_num_computer[serial2]==21)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("SO2"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45||yourcard/10==7||yourcard==84))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.9
        else if (serial_num_computer[serial]==84)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==11||serial_num_computer[serial2]==13||serial_num_computer[serial2]==14
					||serial_num_computer[serial2]==21)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("H2S"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45||yourcard/10==7))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }
            
//*******2.5.10
        else if (serial_num_computer[serial]==56)
        {
            check=0;
            for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]/10==3)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("PH3"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==7||yourcard==14||yourcard==81))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
			for(serial2=1;serial2<=num_card_computer;serial2++)
            {
                if(serial_num_computer[serial2]==12)
                {
                    com_use_2cards(serial,serial2);
                    drawtext(_T("NO2"),&comuse2card4,WORDCENTER);
                    situation();
                    int usingcard=0;
                    usingcard=choosecard();
                    int yourcard=serial_num_player[usingcard];
                    if(usingcard>=0&&usingcard<=num_card_player&&
					(yourcard/10==3||yourcard==41||yourcard==44||yourcard==45))
                    {
                        player_answer_1card(usingcard);
                    }
                    else
                    {
                        player_lose_blood(2);
                    }
                    check=1;
                    break;
                }
            }
            if(check==0)
            {
                serial+=1;
            }
        }


//其余部分
	    else
	    {
            serial+=1;//查看下一张牌是否可出
        }
		if(Hp_of_player<=0)
		{
			break;
		}
	}
	
//弃牌阶段	    
	if(num_card_computer>Hp_of_computer)
	{
	    int gap=num_card_computer-Hp_of_computer;
		num_card_computer=Hp_of_computer;
		for(i=1;i<=num_card_computer;i++)
	    {
	    	serial_num_computer[i]=serial_num_computer[i+gap];
		}
		for(i=num_card_computer+1;i<=num_card_computer+gap;i++)
	    {
	    	serial_num_computer[i]=0;
		}
	}
}
void yourturn(int yougetcard)
{
//现在是你的出牌阶段
	setcolor(NEWBUTTON);
	setfillcolor(NEWBUTTON);
	fillrectangle(1010,300,1070,340);
	setcolor(NEWBUTTONWORD);
	setbkcolor(NEWBUTTON);
	drawtext(_T("提示"),&newbuttonword,WORDCENTER);
	setcolor(BUTTON);
	setbkcolor(BKCOLOR);
	setfillcolor(BUTTON);
	fillrectangle(1010,460,1070,520);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("出牌"),&usemycard,WORDCENTER);
	setfillcolor(WORDCOLOR);
	setfillcolor(BKCOLOR);
	setbkcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,120,540,180);
	setcolor(WORDCOLOR);
	drawtext(_T("你的回合开始   你摸取"),&yourstart,WORDLEFT);
	int k=yougetcard;
	if(yougetcard==2){drawtext(_T("2"),&youget_card,WORDCENTER);}
	if(yougetcard==3){drawtext(_T("3"),&youget_card,WORDCENTER);}
	drawtext(_T("张牌"),&yourstart2,WORDLEFT);	
    for(m=1;m<=k;m++)//你摸牌
    {
	    num_card_player++;
	    serial_num_player[num_card_player] = getcard();
    }
	situation();
	int choice=0;
	choice=youusecard();
	while(Hp_of_computer>0)
	{
	    if(choice==0) 
	    {
	    	break;
		}
//*********3.1.1盐酸
	    else if (serial_num_player[choice]==11)//打出盐酸
	    {
			player_use_1card(choice);
			//电脑的回应
			int responce=0;
			for(i=1;i<=num_card_computer;i++)
			{
				int comcard=serial_num_computer[i];
			    if(comcard/10==3||comcard/10==4||comcard==51||comcard==53||comcard==58||comcard==68)
			    {
				    responce=1;
				    com_answer_1card(i);
					break;
			    }
		    }
		    if(responce==0)
		    {
		        com_lose_blood(1);
	        }
		    choice=youusecard();
        }
//*********3.1.2硫酸和氢碘酸
		else if (serial_num_player[choice]==13||serial_num_player[choice]==14)
		{
			player_use_1card(choice);
			//电脑的回应
			int responce=0;
			for(i=1;i<=num_card_computer;i++)
			{
				int comcard=serial_num_computer[i];
				if(comcard/10==3||comcard/10==4||comcard==68||comcard==73||comcard==51||comcard==53||comcard==58||comcard==83)
				{
				    responce=1;
				    com_answer_1card(i);
					break;
			    }
		    }
		    if(responce==0)
		    {
			    com_lose_blood(1);
		    }
		    choice=youusecard();
	    }
//*********3.1.3硝酸和高氯酸 
	    else if (serial_num_player[choice]==12||serial_num_player[choice]==15)
		{
			player_use_1card(choice);
			//电脑的回应
			int responce=0;
			for(i=1;i<=num_card_computer;i++)
			{
				int comcard=serial_num_computer[i];
				if(comcard/10==3||comcard/10==4||comcard==68||comcard==73)
				{
					responce=1;
					com_answer_1card(i);
					break;
				}
			}
			if(responce==0)
			{
				com_lose_blood(1);
			}
		    choice=youusecard();
	    }
//*********3.2.1强碱
		else if (serial_num_player[choice]/10==3)
		{
			player_use_1card(choice);
			//电脑的回应
			int responce=0;
			for(i=1;i<=num_card_computer;i++)
			{
				int comcard=serial_num_computer[i];
				if(comcard/10==1||comcard/10==2||comcard==42||comcard==43||comcard==44||comcard==51
				||comcard==57||comcard==58||comcard==63||comcard==64||comcard==66||comcard==67||comcard==72||comcard==82||comcard==85)
				{
					responce=1;
					com_answer_1card(i);
					break;
				}
			}
			if(responce==0)
			{
				com_lose_blood(1);
			}
			choice=youusecard();
		}
//*********3.3.1燃烧反应
		//出两张牌时，用2位数字表示，后一位表示一张手牌的编号，前一位表示另一张手牌的编号
		else if ((serial_num_player[choice/10]==61&&serial_num_player[choice%10]/10==5)
		||(serial_num_player[choice%10]==61&&serial_num_player[choice/10]/10==5))
		{
			player_use_2cards(choice/10,choice%10);
			drawtext(_T("燃烧反应"),&youuse2card4,WORDCENTER);
			situation();
			//电脑的回应
			int responce=0;
			for(i=1;i<=num_card_computer;i++)
			{
				int comcard=serial_num_computer[i];
				if(comcard==42||comcard==62||comcard==63)
				{
					responce=1;
					com_answer_1card(i);
					break;
				}
			}
			if(responce==0)
			{
				com_lose_blood(2);
			}
			choice=youusecard();
		}
//*********3.4.1
        else if (serial_num_player[choice]==65)//
        {
            player_use_1card(choice);
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard==83)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.4.2
        else if (serial_num_player[choice]==66)//
        {
            player_use_1card(choice);
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==83 || comcard==41 || comcard==44 || comcard==45 || comcard==85 )
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.1
        else if ((serial_num_player[choice%10]==23&&serial_num_player[choice/10]/10==3)
		|| (serial_num_player[choice%10]==23&&serial_num_player[choice/10]==44) 
		|| (serial_num_player[choice%10]==23&&serial_num_player[choice/10]==45) 
		|| (serial_num_player[choice%10]==23&&serial_num_player[choice/10]==84)
		|| (serial_num_player[choice/10]==23&&serial_num_player[choice%10]/10==3)
		|| (serial_num_player[choice/10]==23&&serial_num_player[choice%10]==44) 
		|| (serial_num_player[choice/10]==23&&serial_num_player[choice%10]==45) 
		|| (serial_num_player[choice/10]==23&&serial_num_player[choice%10]==84))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("NH3"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==1||comcard==21||comcard==22||comcard==62||comcard==66||comcard==82||comcard==85)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
           
//*********3.5.2
        else if ((serial_num_player[choice%10]==24&&serial_num_player[choice/10]/10==3)
		|| (serial_num_player[choice%10]==24&&serial_num_player[choice/10]==44) 
		|| (serial_num_player[choice%10]==24&&serial_num_player[choice/10]==45) 
		|| (serial_num_player[choice%10]==24&&serial_num_player[choice/10]==84)
		|| (serial_num_player[choice/10]==24&&serial_num_player[choice%10]/10==3)
		|| (serial_num_player[choice/10]==24&&serial_num_player[choice%10]==44) 
		|| (serial_num_player[choice/10]==24&&serial_num_player[choice%10]==45) 
		|| (serial_num_player[choice/10]==24&&serial_num_player[choice%10]==84))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("NH3"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==1||comcard==21||comcard==22||comcard==62||comcard==66||comcard==82||comcard==85)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.3
        else if ((serial_num_player[choice/10]==51&&serial_num_player[choice%10]==12)
		|| (serial_num_player[choice/10]==53&&serial_num_player[choice%10]==12) 
		|| (serial_num_player[choice/10]==58&&serial_num_player[choice%10]==12)
		|| (serial_num_player[choice%10]==51&&serial_num_player[choice/10]==12)
		|| (serial_num_player[choice%10]==53&&serial_num_player[choice/10]==12) 
		|| (serial_num_player[choice%10]==58&&serial_num_player[choice/10]==12)
		|| (serial_num_player[choice%10]==82&&serial_num_player[choice/10]==12) 
		|| (serial_num_player[choice%10]==12&&serial_num_player[choice/10]==82)
		|| (serial_num_player[choice%10]==12&&serial_num_player[choice/10]==84) 
		|| (serial_num_player[choice%10]==84&&serial_num_player[choice/10]==12))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("NO"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard==83)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.4
        else if ((serial_num_player[choice/10]==55&&serial_num_player[choice%10]==12)
		|| (serial_num_player[choice/10]==56&&serial_num_player[choice%10]==12)
		|| (serial_num_player[choice%10]==55&&serial_num_player[choice/10]==12)
		|| (serial_num_player[choice%10]==56&&serial_num_player[choice/10]==12))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("NO2"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.5
        else if ((serial_num_player[choice/10]==57&&serial_num_player[choice%10]==12)
		||(serial_num_player[choice%10]==57&&serial_num_player[choice/10]==12))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("NO2与SO2"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.6
        else if ((serial_num_player[choice/10]==67&&serial_num_player[choice%10]==21)
		||(serial_num_player[choice%10]==67&&serial_num_player[choice/10]==21))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("SiF4"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45||comcard==62)
                {
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.7
        else if ((serial_num_player[choice/10]/10==7&&serial_num_player[choice%10]==11)
		||(serial_num_player[choice%10]/10==7&&serial_num_player[choice/10]==11) )
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("Cl2"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45||comcard==84||comcard==85)                    
				{
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.8
        else if ((serial_num_player[choice/10]==82&&serial_num_player[choice%10]==11)
		|| (serial_num_player[choice%10]==82&&serial_num_player[choice/10]==11)
		|| (serial_num_player[choice/10]==82&&serial_num_player[choice%10]==13)
		|| (serial_num_player[choice%10]==82&&serial_num_player[choice/10]==13)
		|| (serial_num_player[choice/10]==82&&serial_num_player[choice%10]==14)
		|| (serial_num_player[choice%10]==82&&serial_num_player[choice/10]==14))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("SO2"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45||comcard==84||comcard/10==7)                    
				{
                    responce=1;
                    com_answer_1card(i);
                    break;
                } 
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.9
        else if ((serial_num_player[choice/10]==84&&serial_num_player[choice%10]==11)
		|| (serial_num_player[choice%10]==84&&serial_num_player[choice/10]==11)
		|| (serial_num_player[choice/10]==84&&serial_num_player[choice%10]==13)
		|| (serial_num_player[choice%10]==84&&serial_num_player[choice/10]==13)
		|| (serial_num_player[choice/10]==84&&serial_num_player[choice%10]==14)
		|| (serial_num_player[choice%10]==84&&serial_num_player[choice/10]==14) )
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("H2S"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard/10==3||comcard==41||comcard==44||comcard==45||comcard/10==7)                    
				{
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//*********3.5.10
        else if ((serial_num_player[choice/10]==56&&serial_num_player[choice%10]/10==3)
		||(serial_num_player[choice%10]==56&&serial_num_player[choice/10]/10==3))
        {
            player_use_2cards(choice/10,choice%10);
            drawtext(_T("PH3"),&youuse2card4,WORDCENTER);
            situation();
            int responce=0;
            for(i=1;i<=num_card_computer;i++)
            {
                int comcard=serial_num_computer[i];
                if(comcard==14||comcard/10==7||comcard==81)                    
				{
                    responce=1;
                    com_answer_1card(i);
                    break;
                }
            }
            if(responce==0)
            {
                com_lose_blood(2);
            }
            choice=youusecard();
        }
            
//其余的部分 
		else
		{
			drawtext(_T("请重新选择出牌"),&reuseyourcard,WORDCENTER);
			Sleep(800);
			choice=youusecard();
		}
		if(Hp_of_computer<=0)
		{
		    break;
		}
	}
	
	
	    
//弃牌阶段
	if(num_card_player>Hp_of_player)
	{
	    int gap=num_card_player-Hp_of_player;
		setcolor(BKCOLOR);
	    setfillcolor(BKCOLOR);
	    fillrectangle(0,120,538,178);
	    setcolor(WORDCOLOR);
		if(gap==1){drawtext(_T("请弃1张牌"),&dropcard,WORDLEFT);}
		if(gap==2){drawtext(_T("请弃2张牌"),&dropcard,WORDLEFT);}
		if(gap==3){drawtext(_T("请弃3张牌"),&dropcard,WORDLEFT);}
		if(gap==4){drawtext(_T("请弃4张牌"),&dropcard,WORDLEFT);}
		if(gap==5){drawtext(_T("请弃5张牌"),&dropcard,WORDLEFT);}
		if(gap==6){drawtext(_T("请弃6张牌"),&dropcard,WORDLEFT);}
		if(gap==7){drawtext(_T("请弃7张牌"),&dropcard,WORDLEFT);}
		if(gap==8){drawtext(_T("请弃8张牌"),&dropcard,WORDLEFT);}
		int gap2;
	    for(lc1=1;lc1<=gap;lc1++)
	    {
	    	while(1)
			{
	    	    j=choosecard();
	    	    if(j!=0&&j<=num_card_player)
			    {
			        for(lc2=j;lc2<=num_card_player;lc2++)
	    	        {				
	    	            serial_num_player[lc2]=serial_num_player[lc2+1];
	    	        }
			        num_card_player-=1;
					break;
			    }
			    else
			    {
				    drawtext(_T("请重新选择弃牌"),&dropcard2,WORDLEFT);
			    }
			}
			situation();
			gap2=num_card_player-Hp_of_player;
			setcolor(WORDCOLOR);
			if(gap2==1){drawtext(_T("请弃1张牌"),&dropcard,WORDLEFT);}
		    if(gap2==2){drawtext(_T("请弃2张牌"),&dropcard,WORDLEFT);}
		    if(gap2==3){drawtext(_T("请弃3张牌"),&dropcard,WORDLEFT);}
		    if(gap2==4){drawtext(_T("请弃4张牌"),&dropcard,WORDLEFT);}
		    if(gap2==5){drawtext(_T("请弃5张牌"),&dropcard,WORDLEFT);}
		    if(gap2==6){drawtext(_T("请弃6张牌"),&dropcard,WORDLEFT);}
		    if(gap2==7){drawtext(_T("请弃7张牌"),&dropcard,WORDLEFT);}
		}
		num_card_player=Hp_of_player;
	}
}
void gamechoice()
{
	initgraph(1080,540);
	setfillcolor(BKCOLOR);
	fillrectangle(0,0,1080,540);
	setbkcolor(BKCOLOR);
	setcolor(LINECOLOR);
	line(540,0,540,180);
	line(0,180,1080,180);
	line(0,360,1080,360);
	line(0,540,1080,540);
	setcolor(WORDCOLOR);
	drawtext(_T("chemkill游戏规则：通过使用化学物质造成伤害，血量小于等于0时被淘汰"),&gamerule1,WORDLEFT);
	drawtext(_T("伤害方式：强酸强碱：伤害为1；燃烧、有毒气体：伤害为2"),&gamerule2,WORDLEFT);
	drawtext(_T("抵御伤害的方式：使强酸强碱有毒气体转化为不具有上述性质的物质"),&gamerule3,WORDLEFT);
	drawtext(_T("欢迎来到chemkill3.0，请选择游戏模式"),&welcome1,WORDLEFT);
	setfillcolor(BUTTON);
	fillrectangle(0,80,80,100);fillrectangle(90,80,170,100);fillrectangle(180,80,260,100);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("1.简单模式"),&mode1,WORDCENTER);
	drawtext(_T("2.一般模式"),&mode2,WORDCENTER);
	drawtext(_T("3.困难模式"),&mode3,WORDCENTER);
	int mode;
	while(1)
	{
		MOUSEMSG m=GetMouseMsg();
		if(m.mkLButton)
		{
			if(m.x>=0&&m.x<=80&&m.y>=80&&m.y<=100){mode=1;break;}
			if(m.x>=90&&m.x<=170&&m.y>=80&&m.y<=100){mode=2;break;}
			if(m.x>=180&&m.x<260&&m.y>=80&&m.y<=100){mode=3;break;}
		}
	}
	if(mode==1)
	{
		inicomcard=3;
		iniplayercard=6;
		Hp_of_computer=4;
		Hp_of_player=6;
		setfillcolor(BUTTONON);
		fillrectangle(0,80,80,100);
		setbkcolor(BUTTONON);
		drawtext(_T("1.简单模式"),&mode1,WORDCENTER);
	}
	else if(mode==2)
	{
		inicomcard=3;
		iniplayercard=5;
		Hp_of_computer=5;
		Hp_of_player=6;
		setfillcolor(BUTTONON);
		fillrectangle(90,80,170,100);
		setbkcolor(BUTTONON);
		drawtext(_T("2.一般模式"),&mode2,WORDCENTER);
	}
	else if(mode==3)
	{
		inicomcard=4;
		iniplayercard=5;
		Hp_of_computer=6;
		Hp_of_player=6;
		setfillcolor(BUTTONON);
		fillrectangle(180,80,260,100);
		setbkcolor(RGB(255,0,0));
		drawtext(_T("3.困难模式"),&mode3,WORDCENTER);
	}
	setbkcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("请选择游戏速度"),&speedtext,WORDLEFT);
	setfillcolor(BUTTON);
	fillrectangle(300,80,380,100);fillrectangle(390,80,470,100);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("1.一般模式"),&speed1,WORDCENTER);
	drawtext(_T("2.快速模式"),&speed2,WORDCENTER);
	while(1)
	{
		MOUSEMSG m=GetMouseMsg();
		if(m.mkLButton)
		{
			if(m.x>=300&&m.x<=380&&m.y>=80&&m.y<=100){speed=1;break;}
			if(m.x>=390&&m.x<=470&&m.y>=80&&m.y<=100){speed=2;break;}
		}
	}
	if(speed==1)
	{
		setfillcolor(BUTTONON);
		fillrectangle(300,80,380,100);
		setbkcolor(BUTTONON);
		drawtext(_T("1.一般模式"),&speed1,WORDCENTER);
	}
	else if(speed==2)
	{
		setfillcolor(BUTTONON);
		fillrectangle(390,80,470,100);
		setbkcolor(BUTTONON);
		drawtext(_T("2.快速模式"),&speed2,WORDCENTER);
	}
	setfillcolor(BUTTON);
	fillrectangle(1010,380,1070,440);
	setbkcolor(BUTTON);
	drawtext(_T("不出牌"),&nocard,WORDCENTER);
	setfillcolor(WORDCOLOR);
	for(i=1;i<=9;i++)
	{
		fillrectangle(110*i-100,380,110*i,420);
	}
}
int main()
{
	gamechoice();
	setbkcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	gamestart(inicomcard,iniplayercard);
	while(1)
	{
		comturn(speed+1);
		if(Hp_of_player<=0)
		{
			break;
		}
		Sleep(1000);//电脑和玩家回合间间隔1s
		yourturn(speed+1);
		if(Hp_of_computer<=0)
		{
			break;
		}
		Sleep(1000);//电脑和玩家回合间间隔1s
	}
	fclose(filePtr);
	return 0;
}