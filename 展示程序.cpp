#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //����������ɺ���
#include <math.h>
#include <string.h> 
#include <graphics.h>  //ͼ����
#include <conio.h>
#include <windows.h> //Sleep����ʹ�ó�����ͣ

//drawtext����������λ�����õļ򻯰�
#define WORDLEFT DT_LEFT|DT_VCENTER|DT_SINGLELINE
#define WORDCENTER DT_CENTER|DT_VCENTER|DT_SINGLELINE

//��ɫ����
#define BKCOLOR RGB(255,192,203)      //����ɫΪ��ɫ
#define WORDCOLOR RGB(30,144,255)  //������ɫΪ��ɫ
//#define BKCOLOR RGB(192,192,192)      //����ɫΪ��ɫ
//#define WORDCOLOR RGB(65,105,225)  //������ɫΪ��ɫ
#define LINECOLOR RGB(0,255,225)      //������ɫΪ����ɫ
#define BUTTON RGB(176,23,31)           //��ť��ɫΪ���ɫ
#define BUTTONON RGB(255,0,0)         //��ť����ʱ����ɫΪ����ɫ
#define BUTTONWORD RGB(0,255,127) //��ť���ֵ���ɫΪ��ɫ
#define NEWBUTTON RGB(255,215,0)
#define NEWBUTTONWORD RGB(25,25,112)

//�����ͷ��ࣺ1*��ǿ�᣻2*�����᣻3*��ǿ�4*�����
//5*����ȼ���ʣ�6*�������������7*��ǿ���������ʣ�8*����������

//�⼸�������Ǽ������õı�����
//����ѭ�����Ǳ����Ҫ���ⶨ����ʵ����������ĵط�
//��ÿһ������ʱ������г�ʼ��
//������Щ��������Ϊȫ�ֱ�����Ϊ����һЩ
int i,j,m,serial2,check,lc1,lc2; 
FILE* filePtr=fopen("chemkillrecord.txt","a"); 

//�涨�˻���ս�漰�Ļ�������
//����Ѫ�����ڼ����ƣ�������������
int Hp_of_computer=5;
int Hp_of_player=6;
int num_card_computer=0;
int num_card_player=0;
//��Ϊ�������Ʊ�ſ���Ϊ��λ�����Զ���һ��100�������ܱ�֤��Խ��
int serial_num_computer[100]={0};
int serial_num_player[100]={0};

//������ҳ��ƽ׶ε���ʾ
//void tips()

//�ռ��������Ϣ������ƶ�Ӧ�ı��
//int choosecard()

//�ռ������������Ϣ
//�õ����ƶ�Ӧ��ţ�һ���ƻ������ƣ�
RECT pleaseuse1stcard={0,140,538,160};
//int youusecard() 

//�ú�������Ϊ
//�ڸ���λ���ϣ�x��y������ʾ���Ʊ�Ŷ�Ӧ��ͼ��
IMAGE img11,img12,img13,img14,img15,
	       img21,img22,img23,img24,
	       img31,img32,img33,img34,
	       img41,img42,img43,img44,img45,
	       img51,img52,img53,img54,img55,img56,img57,img58,
		   img61,img62,img63,img64,img65,img66,img67,img68,
	       img71,img72,img73,
		   img81,img82,img83,img84,img85;
//void pictureofthecard(int m , int x ,int y)

//�ú�������Ϊ
//�ڸ���λ���ϣ���ʾ���Ʊ�Ŷ�Ӧ����������
//void nameofthecardinbattleinfo(int m,int x,int y)

//ʹ���������������ظ�
int totalcard=0;

//���ƺ�������������Ƶı���
//�˺�����Ҫִ���������ܣ�
//1.	�����������m��ʹ��Ҽ����Ե����ƶ��������Ч��
//2.	����ÿ���Ƹ����Ĳ�ͬ��������������ָ��ÿ���ƶ�Ӧ��
//�����m�����䣬����m���������������Χ����ӳ��
//int getcard()



//���ܳ���˫�������ƺ�Ѫ��
//�˺�����Ҫִ���������ܣ�
//1.	������ʾ������Ѫ�����������������Ѫ�����������
//2.	����ѭ��������ʾ����ҵ�Ŀǰ����
//void situation()

//������������player_use_1card,player_use_2cards�ڵ��Գ���ʱ����ȫ��Ӧ��
RECT comuse1card1={0,140,110,160}; 
RECT comuse1card2={200,140,350,160}; 
//void com_use_1card(int i)

//������������player_use_1card,player_use_2cards�ڵ��Գ���ʱ����ȫ��Ӧ��
RECT comuse2card1={0,140,110,160}; 
RECT comuse2card2={200,140,220,160}; 
RECT comuse2card3={310,140,350,160}; 
RECT comuse2card4={350,140,440,160};
//void com_use_2cards(int m,int n)

//void player_use_1card(int m)���˺�����Ҫִ���������ܣ�
//1.��ʾ����m����Ӧ���ƣ�����ʾ����Ե��Դ����XXX����
//2.�ı���ҵ������鼰���������Ƚ�������һ��
//֮��ͨ����m��~��n���ƶ�Ӧ����ȫ����ǰ�ƶ�һλ��
//�������һ���ƹ��㣬���ﵽ���m�ƣ�
//����֤��ҵ��Ƽ���������ǰn-1��λ�õ�Ŀ�ġ���nΪ����ǰ��������
RECT youuse1card1={0,140,110,160}; 
//void player_use_1card(int m)

//void player_use_2cards(int m1,int m2)����һ�������ƣ��˺�����������ҳ�������ʱ
//��ʾ����Ե��Դ����XXX��YYY�������ı���ҵ������鼰������
//���Ƚ�����������֮��ͨ����min{m1,m2}֮�����Ǩ��һλ��
//�ٽ�max{m1,m2}֮�����Ǩ��һλ����������������������ﵽ���m1��m2�ƣ�
//����֤��ҵ��Ƽ���������ǰn-2��λ�õ�Ŀ�ġ���nΪ����ǰ��������
RECT youuse2card1={0,140,110,160}; 
RECT youuse2card2={200,140,220,160}; 
RECT youuse2card3={310,140,350,160};
RECT youuse2card4={350,140,440,160};
//void player_use_2cards(int m1,int m2)

//�ú���������ʾ��ҵĳ��ƹ���
//��ѡ��һ���Ʋ��������������num_card_player��һ��
//ͬʱ���ƺ����ʣ�����ƣ�����serial_num_player[j] ��j>m����
//������ǰƽ��һλ�����һ�ſ����Ƹ�ֵΪ0
RECT youanswer1card={0,160,80,180}; 
//void player_answer_1card(int m)

//�ú���������ʾ���Եĳ��ƹ���
//��ѡ��һ���Ʋ��������������num_card_player��һ��
//ͬʱ���ƺ����ʣ�����ƣ�����serial_num_computer[j] ��j>m����
//������ǰƽ��һλ�����һ�ſ����Ƹ�ֵΪ0
RECT comanswer1card={0,160,100,180}; 
//void com_answer_1card(int m)

//�ú�����Ҫ����ҵ�Ѫ���ж��Ƿ���ֹ����
//1.	���롰��ʧ����ֵ������m
//2.	ÿ������ܵ�������ʧʱ����ʾ��������ʧm��������������ԭ�������Ļ����ϼ�m
//3.	���������Hp_of_playerС�ڵ���0ʱ����ʾ�������ˡ�
RECT youloseblood1={0,160,50,180}; 
RECT youloseblood2={50,160,70,180}; 
RECT youloseblood3={70,160,120,180}; 
RECT youloseblood4={120,160,180,180}; 
//void player_lose_blood(int m)

//�ú�����Ҫ�𵽵��Ե�Ѫ���ж��Ƿ���ֹ����
//1.	���롰��ʧ����ֵ������m
//2.	ÿ�ε����ܵ�������ʧʱ����ʾ����������ʧm��������������ԭ�������Ļ����ϼ�m
//3.	����������Hp_of_computerС�ڵ���0ʱ����ʾ����Ӯ�ˡ�
RECT comloseblood1={0,160,65,180}; 
RECT comloseblood2={65,160,80,180}; 
RECT comloseblood3={80,160,130,180}; 
RECT comloseblood4={130,160,180,180}; 
//void com_lose_blood(int m)

//��Ϸ��ʼʱ��ʾ��Ϸ��ʼ������
RECT gamebegin={0,100,540,120};
//void gamestart(int inicardcom,int inicardplayer)


//void comturn(int comgetcard)
//***����ʹ��һ�����Ƶĳ���ʵ��
//���԰��������Զ�˳�������ƣ��������������
//����ִ�е��Գ��Ƴ��򣬼���ʾ���Գ���ʲô�Ʋ�ѯ���Ƿ�ش�
//���Ե��Ե������������Ӧ�ı�
//��ʱ¼����������Լ���Ҫ�����Ƶı��
//�����ҳ���Mg/Al/Zn/CuO��ǿ������е�һ�֣�
//�����������������Ӧ�Ķ��������˺����������Ѫ����һ��
//
//***����ʹ���������Ƶĳ���ʵ��
//���԰��������Զ�˳�������ƣ��������������
//��ʼ��������ȼ�յ����ʣ���Al/CH4/Mg/H2/C/P4/S8/Zn��
//������������ִ�е��Գ������Ƴ��򣬼���ʾ���Գ����������Ʋ���ʾ������ȼ�շ�Ӧ
//��ѯ���Ƿ�ش𣬲��Ե��Ե������������Ӧ�ı䡣
//�����ҳ���Al(OH)3/H20/CO2�е�һ�֣�
//�����������������Ӧ�Ķ��������˺����������Ѫ��������
RECT comstart={0,120,180,140}; 
RECT comget_card={180,120,200,140};
RECT comstart2={200,120,300,140}; 
//void comturn(int comgetcard) 

/*���Գ��ƻغ�����ҳ��ƻغϺ����ķֽ���*/

//void yourturn(int yougetcard)
//***��ʹ��һ�����Ƶĳ���ʵ��
//����������HCl�ƣ�����ִ����ҳ��Ƴ���
//����ʾ��ҳ���ʲô�ƣ�������ҵ������������Ӧ�ı�
//��ʱ�����������е������ƣ���������Mg/Al/Zn/CuO��ǿ������е�һ��
//����Գ�֮���Ե��������������Ӧ�Ķ��ұ����˺����������Ѫ����һ��
//
//�����Ҫȼ�չ�������Ҫ������
//�˺���ʾ��ҳ���ʲô�ƣ�������ҵ������������Ӧ�ı�
//��ʱ�����������е������ƣ���������Al(OH)3/H20/CO2�е�һ��
//��Ե��������������Ӧ�Ķ��������˺����������Ѫ��������
RECT yourstart={0,120,155,140}; 
RECT youget_card={155,120,180,140};
RECT yourstart2={180,120,260,140};
RECT dropcard={0,120,540,140};
RECT dropcard2={0,140,540,160};
RECT usemycard={1010,460,1070,520};
RECT reuseyourcard={0,140,530,160}; 
RECT newbuttonword={1010,300,1070,340};
//void yourturn(int yougetcard)


//iniconcard������������Ϸ��ʼʱ��������
//iniplayercard�����������Ϸ��ʼʱ��������
//speed�������Ժ��������Ϸ�غ��е�������-1
int inicomcard=0,iniplayercard=0,speed=0;

//ͨ�����ı��Ͱ���ʵ�����ѡ����Ϸ�ѶȺ���Ϸ�ٶȵĹ���
//��������������ͨ����һ�������İ������и���
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
	drawtext(_T("������һ����,�������������������ơ�"),&pleaseuse1stcard,WORDLEFT);
    calc+=choosecard();
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,160);
	setcolor(WORDCOLOR);
	drawtext(_T("�����ڶ����ƣ���ֻ��һ���ƻ򲻳��������������ơ�"),&pleaseuse1stcard,WORDLEFT);
	calc+=(10*choosecard());
	setfillcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,140,538,160);
	setcolor(WORDCOLOR);
	drawtext(_T("���������ơ�"),&pleaseuse1stcard,WORDLEFT);
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

    case 41:loadimage(&img41,_T("picture\\NH3��H2O.jpg"));putimage(x,y,&img41);break;
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
//1*��ǿ��
	case 11:drawtext(_T("HCl"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 12:drawtext(_T("HNO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 13:drawtext(_T("H2SO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 14:drawtext(_T("HI"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 15:drawtext(_T("HClO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//2*������
	case 21:drawtext(_T("HF"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 22:drawtext(_T("H2S"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 23:drawtext(_T("NH4Cl"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 24:drawtext(_T("NH4NO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//3*��ǿ��
	case 31:drawtext(_T("NaOH"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 32:drawtext(_T("KOH"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 33:drawtext(_T("Ca(OH)2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 34:drawtext(_T("Ba(OH)2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//4*������
	case 41:drawtext(_T("NH3��H2O"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 42:drawtext(_T("Al(OH)3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 43:drawtext(_T("Al2O3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 44:drawtext(_T("NaHCO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 45:drawtext(_T("Na2CO3"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//5*����ȼ����
	case 51:drawtext(_T("Al"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 52:drawtext(_T("CH4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 53:drawtext(_T("Mg"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 54:drawtext(_T("H2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 55:drawtext(_T("C"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 56:drawtext(_T("P4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 57:drawtext(_T("S8"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 58:drawtext(_T("Zn"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//6*��������������
	case 61:drawtext(_T("O2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 62:drawtext(_T("H2O"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 63:drawtext(_T("CO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 64:drawtext(_T("P2O5"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 65:drawtext(_T("NO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 66:drawtext(_T("NO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 67:drawtext(_T("SiO2"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 68:drawtext(_T("CuO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//7*��ǿ����������
	case 71:drawtext(_T("KMnO4"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 72:drawtext(_T("K2Cr2O7"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
	case 73:drawtext(_T("NaClO"),&whichcarduse,DT_CENTER|DT_VCENTER|DT_SINGLELINE);break;
//8*����������
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
		drawtext(_T("��������û��"),&r,WORDCENTER);
	}
	if(num_card_computer==1)
	{
		drawtext(_T("����������1����"),&r,WORDCENTER);
	}
	if(num_card_computer==2)
	{
		drawtext(_T("����������2����"),&r,WORDCENTER);
	}
	if(num_card_computer==3)
	{
		drawtext(_T("����������3����"),&r,WORDCENTER);
	}
	if(num_card_computer==4)
	{
		drawtext(_T("����������4����"),&r,WORDCENTER);
	}
	if(num_card_computer==5)
	{
		drawtext(_T("����������5����"),&r,WORDCENTER);
	}
	if(num_card_computer==6)
	{
		drawtext(_T("����������6����"),&r,WORDCENTER);
	}
	if(num_card_computer==7)
	{
		drawtext(_T("����������7����"),&r,WORDCENTER);
	}
	if(num_card_computer==8)
	{
		drawtext(_T("����������8����"),&r,WORDCENTER);
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
		drawtext(_T("������û����"),&r2,WORDCENTER);
	}
	if(num_card_player==1)
	{
		drawtext(_T("��������1����"),&r2,WORDCENTER);
	}
	if(num_card_player==2)
	{
		drawtext(_T("��������2����"),&r2,WORDCENTER);
	}
	if(num_card_player==3)
	{
		drawtext(_T("��������3����"),&r2,WORDCENTER);
	}
	if(num_card_player==4)
	{
		drawtext(_T("��������4����"),&r2,WORDCENTER);
	}
	if(num_card_player==5)
	{
		drawtext(_T("��������5����"),&r2,WORDCENTER);
	}
	if(num_card_player==6)
	{
		drawtext(_T("��������6����"),&r2,WORDCENTER);
	}
	if(num_card_player==7)
	{
		drawtext(_T("��������7����"),&r2,WORDCENTER);
	}
	if(num_card_player==8)
	{
		drawtext(_T("��������8����"),&r2,WORDCENTER);
	}
	if(num_card_player==9)
	{
		drawtext(_T("��������9����"),&r2,WORDCENTER);
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
	drawtext(_T("���Զ���ʹ����"),&comuse1card1,WORDLEFT);
	int k=serial_num_computer[i];
	nameofthecardinbattleinfo(k,110,140);
	drawtext(_T("�������Ƿ�Ӧ��"),&comuse1card2,WORDLEFT);
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
	drawtext(_T("���Զ���ʹ����"),&comuse2card1,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_computer[m],110,140);
	drawtext(_T("��"),&comuse2card2,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_computer[n],220,140);
	drawtext(_T("����"),&comuse2card3,WORDLEFT);
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
	drawtext(_T("��Ե���ʹ����"),&youuse1card1,WORDLEFT);
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
	drawtext(_T("��Ե���ʹ����"),&youuse2card1,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_player[m1],110,140);
	drawtext(_T("��"),&youuse2card2,WORDLEFT);
	nameofthecardinbattleinfo(serial_num_player[m2],220,140);
	drawtext(_T("����"),&youuse2card3,WORDLEFT);
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
	drawtext(_T("������"),&youanswer1card,WORDLEFT);
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
	drawtext(_T("���Դ����"),&youanswer1card,WORDLEFT);
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
	drawtext(_T("����ʧ"),&youloseblood1,WORDLEFT);
	if(m==1){drawtext(_T("1"),&youloseblood2,WORDCENTER);}
	if(m==2){drawtext(_T("2"),&youloseblood2,WORDCENTER);}
	drawtext(_T("������"),&youloseblood3,WORDLEFT);
	situation();
	if(Hp_of_player<=0)
	{
		drawtext(_T("������"),&youloseblood4,DT_LEFT|DT_VCENTER|DT_SINGLELINE);
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
	drawtext(_T("������ʧ"),&comloseblood1,WORDLEFT);
	if(m==1){drawtext(_T("1"),&comloseblood2,WORDCENTER);}
	if(m==2){drawtext(_T("2"),&comloseblood2,WORDCENTER);}
	drawtext(_T("������"),&comloseblood3,WORDLEFT);
	Hp_of_computer-=m;
	if(Hp_of_computer<=0)
	{
		drawtext(_T("��Ӯ��"),&comloseblood4,WORDLEFT);
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
	//��ʼ�׶Σ���ɫ��ȡ�涨��������
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
	//��ӭ����
	drawtext(_T("��ӭ����chemkill3.0�����ڽ��е����˻���ս"),&gamebegin,WORDLEFT);
	situation();
}
void comturn(int comgetcard) 
{
//���Գ��ƻغ�
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
	drawtext(_T("���ԵĻغϿ�ʼ ������ȡ"),&comstart,WORDLEFT);
	int k=comgetcard;
	if(comgetcard==2){drawtext(_T("2"),&comget_card,WORDCENTER);}
	if(comgetcard==3){drawtext(_T("3"),&comget_card,WORDCENTER);}
	drawtext(_T("����"),&comstart2,WORDLEFT);
    for(m=1;m<=k;m++)//��������������
    {
		num_card_computer++;
	    serial_num_computer[num_card_computer] = getcard();
    }
    int serial=1;//����i��ʾ���Ե����Ʊ��
    while(serial<=num_card_computer&&Hp_of_player>0)
	{
//*******2.1.1����ʹ������
	    if (serial_num_computer[serial]==11)
	    {
		    //ʹ�������ƶԵ��Ե����ƴ����ĸı�
		    com_use_1card(serial);
		    //ѯ���Ƿ�Դ˽���Ӧ��
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //������ܱ��������Ƹ���������˺�
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==51||yourcard==53||yourcard==58||yourcard==68))
		    {
			    player_answer_1card(usingcard);
		    }
		    //����
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.1.2����ʹ�����ᣬ�����
	    else if (serial_num_computer[serial]==13||serial_num_computer[serial]==14)
	    {
		    //ʹ�������ƶԵ��Ե����ƴ����ĸı�
		    com_use_1card(serial);
		    //ѯ���Ƿ�Դ˽���Ӧ��
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //������ܱ��������Ƹ���������˺�
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==68||yourcard==73||yourcard==51||yourcard==53||yourcard==58||yourcard==83))
		    {
			    player_answer_1card(usingcard);
		    }
		    //����
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.1.3����ʹ�����ᡢ������
	    else if (serial_num_computer[serial]==12||serial_num_computer[serial]==15)
	    {
	    //ʹ�������ƶԵ��Ե����ƴ����ĸı�
		    com_use_1card(serial);
		    //ѯ���Ƿ�Դ˽���Ӧ��
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //������ܱ��������Ƹ���������˺�
		    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard/10==3||yourcard/10==4||yourcard==68||yourcard==73))
		    {
			    player_answer_1card(usingcard);
		    }
		    //����
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.2.1����ʹ��ǿ��
	    else if (serial_num_computer[serial]/10==3)
	    {
		    //ʹ�������ƶԵ��Ե����ƴ����ĸı�
		    com_use_1card(serial);
		    //ѯ���Ƿ�Դ˽���Ӧ��
		    int usingcard=0;
		    usingcard=choosecard();
			int yourcard=serial_num_player[usingcard];
		    //������ܱ��������Ƹ���������˺�
		    if(usingcard>=0&&usingcard<=num_card_player
			&&(yourcard/10==1||yourcard/10==2||yourcard==42||yourcard==43||yourcard==44||yourcard==51||yourcard==57||yourcard==58
			||yourcard==63||yourcard==64||yourcard==66||yourcard==67||yourcard==72||yourcard==82||yourcard==85))
		    {
			    player_answer_1card(usingcard);
		    }
		    //����
		    else
		    {
			     player_lose_blood(1);
		    }
	    }
//*******2.3.1����ʹ��ȼ��
       	else if (serial_num_computer[serial]==61)
	    {
	    	check=0;
		    for(serial2=1;serial2<=num_card_computer;serial2++)
		    {
			    if(serial_num_computer[serial2]/10==5)
			    {
	                com_use_2cards(serial,serial2);
					drawtext(_T("ȼ�շ�Ӧ"),&comuse2card4,WORDCENTER);
					situation();
	                //ѯ���Ƿ�Դ˽���Ӧ��
	                int usingcard=0;
	                usingcard=choosecard();
		            int yourcard=serial_num_player[usingcard];
	                //������ܱ��������Ƹ���������˺�
				    if(usingcard>=0&&usingcard<=num_card_player&&(yourcard==42||yourcard==62||yourcard==63))
	                {
		                player_answer_1card(usingcard);
	                }
	                //����
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
                    drawtext(_T("NO2��SO2"),&comuse2card4,WORDCENTER);
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


//���ಿ��
	    else
	    {
            serial+=1;//�鿴��һ�����Ƿ�ɳ�
        }
		if(Hp_of_player<=0)
		{
			break;
		}
	}
	
//���ƽ׶�	    
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
//��������ĳ��ƽ׶�
	setcolor(NEWBUTTON);
	setfillcolor(NEWBUTTON);
	fillrectangle(1010,300,1070,340);
	setcolor(NEWBUTTONWORD);
	setbkcolor(NEWBUTTON);
	drawtext(_T("��ʾ"),&newbuttonword,WORDCENTER);
	setcolor(BUTTON);
	setbkcolor(BKCOLOR);
	setfillcolor(BUTTON);
	fillrectangle(1010,460,1070,520);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("����"),&usemycard,WORDCENTER);
	setfillcolor(WORDCOLOR);
	setfillcolor(BKCOLOR);
	setbkcolor(BKCOLOR);
	setcolor(BKCOLOR);
	fillrectangle(0,120,540,180);
	setcolor(WORDCOLOR);
	drawtext(_T("��ĻغϿ�ʼ   ����ȡ"),&yourstart,WORDLEFT);
	int k=yougetcard;
	if(yougetcard==2){drawtext(_T("2"),&youget_card,WORDCENTER);}
	if(yougetcard==3){drawtext(_T("3"),&youget_card,WORDCENTER);}
	drawtext(_T("����"),&yourstart2,WORDLEFT);	
    for(m=1;m<=k;m++)//������
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
//*********3.1.1����
	    else if (serial_num_player[choice]==11)//�������
	    {
			player_use_1card(choice);
			//���ԵĻ�Ӧ
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
//*********3.1.2����������
		else if (serial_num_player[choice]==13||serial_num_player[choice]==14)
		{
			player_use_1card(choice);
			//���ԵĻ�Ӧ
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
//*********3.1.3����͸����� 
	    else if (serial_num_player[choice]==12||serial_num_player[choice]==15)
		{
			player_use_1card(choice);
			//���ԵĻ�Ӧ
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
//*********3.2.1ǿ��
		else if (serial_num_player[choice]/10==3)
		{
			player_use_1card(choice);
			//���ԵĻ�Ӧ
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
//*********3.3.1ȼ�շ�Ӧ
		//��������ʱ����2λ���ֱ�ʾ����һλ��ʾһ�����Ƶı�ţ�ǰһλ��ʾ��һ�����Ƶı��
		else if ((serial_num_player[choice/10]==61&&serial_num_player[choice%10]/10==5)
		||(serial_num_player[choice%10]==61&&serial_num_player[choice/10]/10==5))
		{
			player_use_2cards(choice/10,choice%10);
			drawtext(_T("ȼ�շ�Ӧ"),&youuse2card4,WORDCENTER);
			situation();
			//���ԵĻ�Ӧ
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
            drawtext(_T("NO2��SO2"),&youuse2card4,WORDCENTER);
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
            
//����Ĳ��� 
		else
		{
			drawtext(_T("������ѡ�����"),&reuseyourcard,WORDCENTER);
			Sleep(800);
			choice=youusecard();
		}
		if(Hp_of_computer<=0)
		{
		    break;
		}
	}
	
	
	    
//���ƽ׶�
	if(num_card_player>Hp_of_player)
	{
	    int gap=num_card_player-Hp_of_player;
		setcolor(BKCOLOR);
	    setfillcolor(BKCOLOR);
	    fillrectangle(0,120,538,178);
	    setcolor(WORDCOLOR);
		if(gap==1){drawtext(_T("����1����"),&dropcard,WORDLEFT);}
		if(gap==2){drawtext(_T("����2����"),&dropcard,WORDLEFT);}
		if(gap==3){drawtext(_T("����3����"),&dropcard,WORDLEFT);}
		if(gap==4){drawtext(_T("����4����"),&dropcard,WORDLEFT);}
		if(gap==5){drawtext(_T("����5����"),&dropcard,WORDLEFT);}
		if(gap==6){drawtext(_T("����6����"),&dropcard,WORDLEFT);}
		if(gap==7){drawtext(_T("����7����"),&dropcard,WORDLEFT);}
		if(gap==8){drawtext(_T("����8����"),&dropcard,WORDLEFT);}
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
				    drawtext(_T("������ѡ������"),&dropcard2,WORDLEFT);
			    }
			}
			situation();
			gap2=num_card_player-Hp_of_player;
			setcolor(WORDCOLOR);
			if(gap2==1){drawtext(_T("����1����"),&dropcard,WORDLEFT);}
		    if(gap2==2){drawtext(_T("����2����"),&dropcard,WORDLEFT);}
		    if(gap2==3){drawtext(_T("����3����"),&dropcard,WORDLEFT);}
		    if(gap2==4){drawtext(_T("����4����"),&dropcard,WORDLEFT);}
		    if(gap2==5){drawtext(_T("����5����"),&dropcard,WORDLEFT);}
		    if(gap2==6){drawtext(_T("����6����"),&dropcard,WORDLEFT);}
		    if(gap2==7){drawtext(_T("����7����"),&dropcard,WORDLEFT);}
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
	drawtext(_T("chemkill��Ϸ����ͨ��ʹ�û�ѧ��������˺���Ѫ��С�ڵ���0ʱ����̭"),&gamerule1,WORDLEFT);
	drawtext(_T("�˺���ʽ��ǿ��ǿ��˺�Ϊ1��ȼ�ա��ж����壺�˺�Ϊ2"),&gamerule2,WORDLEFT);
	drawtext(_T("�����˺��ķ�ʽ��ʹǿ��ǿ���ж�����ת��Ϊ�������������ʵ�����"),&gamerule3,WORDLEFT);
	drawtext(_T("��ӭ����chemkill3.0����ѡ����Ϸģʽ"),&welcome1,WORDLEFT);
	setfillcolor(BUTTON);
	fillrectangle(0,80,80,100);fillrectangle(90,80,170,100);fillrectangle(180,80,260,100);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("1.��ģʽ"),&mode1,WORDCENTER);
	drawtext(_T("2.һ��ģʽ"),&mode2,WORDCENTER);
	drawtext(_T("3.����ģʽ"),&mode3,WORDCENTER);
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
		drawtext(_T("1.��ģʽ"),&mode1,WORDCENTER);
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
		drawtext(_T("2.һ��ģʽ"),&mode2,WORDCENTER);
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
		drawtext(_T("3.����ģʽ"),&mode3,WORDCENTER);
	}
	setbkcolor(BKCOLOR);
	setcolor(WORDCOLOR);
	drawtext(_T("��ѡ����Ϸ�ٶ�"),&speedtext,WORDLEFT);
	setfillcolor(BUTTON);
	fillrectangle(300,80,380,100);fillrectangle(390,80,470,100);
	setbkcolor(BUTTON);
	setcolor(BUTTONWORD);
	drawtext(_T("1.һ��ģʽ"),&speed1,WORDCENTER);
	drawtext(_T("2.����ģʽ"),&speed2,WORDCENTER);
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
		drawtext(_T("1.һ��ģʽ"),&speed1,WORDCENTER);
	}
	else if(speed==2)
	{
		setfillcolor(BUTTONON);
		fillrectangle(390,80,470,100);
		setbkcolor(BUTTONON);
		drawtext(_T("2.����ģʽ"),&speed2,WORDCENTER);
	}
	setfillcolor(BUTTON);
	fillrectangle(1010,380,1070,440);
	setbkcolor(BUTTON);
	drawtext(_T("������"),&nocard,WORDCENTER);
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
		Sleep(1000);//���Ժ���һغϼ���1s
		yourturn(speed+1);
		if(Hp_of_computer<=0)
		{
			break;
		}
		Sleep(1000);//���Ժ���һغϼ���1s
	}
	fclose(filePtr);
	return 0;
}