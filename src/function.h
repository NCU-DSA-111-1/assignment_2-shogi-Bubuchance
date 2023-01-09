#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<ev.h> //libev
#include <time.h>



#define R(piece) "\033[31m"#piece"\033[0m"
#define B(piece) "\033[34m"#piece"\033[0m"
#define ROW 9
#define COLUMN 9
#define STACKSIZE 500

FILE *fptr;

//棋盤
char* chess_board[ROW][COLUMN];

typedef struct record{
	int x1,y1;//原始位置
	int x2,y2;//後來位置
	char* p0;//原始位置上的棋子
	char* p1;//後來位置上的棋子

	struct record *prev;
	struct record *next;
}Record;
//指標
Record *head = NULL;
Record *current = NULL;


//紀錄每一手資料（至多500手）
Record stack[STACKSIZE];
//最上,-1為空
int top=-1;
//test 符號
char SBL='A';
//暫存
Record * temp;


//時間
ev_timer timeB, timeR; 
static time_t now, before;
static time_t Btime, Rtime;
//毀棋
int regret = 0;

//是否為空
int Empty();
//拿出資料
void* pop();
//放入資料
void push(int x1,int y1,int x2,int y2,char* p0,char* p1);
//和局
void peace();

//遊戲是否結束,0為結束
bool gameOverSign =1;
//是否符合規則,0為符合,1為違反必須重新選擇移動棋子與位置
bool restart =0;
//是否符合遊戲規則 ,初始值為1(符合) 
bool isStandard=1; 
//初始棋盤
void InitGame();
//生成棋盤
void PrintChess();
//要移動的棋子位置
int xi,yi;
//要移動到的位置
int xj,yj;
//判斷現在輪到誰
int turn =-1;
//藍棋移動
void bluemove();
//紅棋移動
void redmove();
//判斷遊戲結束
void isGameOver();
//藍棋規則判斷
void blue_rule();
//紅棋規則判斷
void red_rule();
/*//載入棋譜
void Load;*/
//開新局為0,載入棋譜為1  
int NeworOld;
//印出時間
void showTime();
//時間
void gettime_B(struct ev_loop *loop, struct ev_timer *w, int revents);
void gettime_R(struct ev_loop *loop, struct ev_timer *w, int revents);

#endif
