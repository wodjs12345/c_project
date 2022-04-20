// ttteee.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <stdio.h>
#pragma comment (lib , "ws2_32.lib")
#include <WinSock2.h>
#include <process.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include <string.h>
#include<MMSystem.h>
#include<process.h>
#define RIGHT 0x4d
#define LEFT 0x4b
#define UP 0x48
#define DOWN 0x50
#define SPACE 0x32
WSADATA wsaData;
SOCKET serv_sock;
SOCKADDR_IN serv_addr = { 0 };
SOCKADDR_IN clnt_addr = { 0 };
SOCKET clnt_sock;
int otherscore;
int size;//socket
int retval;//socket
int difficulty;
int i, j, r = 0, r1 = 0, x = 10, y = 0;
int q[][4][4] = { { //블록 모양  표시
	{0,0,0,0},
	{1,0,0,0},
	{1,1,1,0},
	{0,0,0,0}},
	{
		{0,0,1,0},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,0}},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}},
			{
				{1,1,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{0,0,0,0}},
				{
					{0,0,0,0},
					{0,0,1,0},
					{1,1,1,0},
					{0,0,0,0}},
					{
						{0,1,1,0},
						{0,0,1,0},
						{0,0,1,0},
						{0,0,0,0}},
						{
							{1,1,1,0},
							{1,0,0,0},
							{0,0,0,0},
							{0,0,0,0}},
							{
								{1,0,0,0},
								{1,0,0,0},
								{1,1,0,0},
								{0,0,0,0}},
								{
									{0,1,0,0},
									{0,1,0,0},
									{0,1,0,0},
									{0,1,0,0}},
									{
										{0,0,0,0},
										{0,0,0,0},
										{1,1,1,1},
										{0,0,0,0}},
										{
											{0,1,0,0},
											{0,1,0,0},
											{0,1,0,0},
											{0,1,0,0}},
											{
												{0,0,0,0},
												{0,0,0,0},
												{1,1,1,1},
												{0,0,0,0}},
												{
													{0,0,0,0},
													{0,1,1,0},
													{0,1,1,0},
													{0,0,0,0}},
													{
														{0,0,0,0},
														{0,1,1,0},
														{0,1,1,0},
														{0,0,0,0}},
														{
															{0,0,0,0},
															{0,1,1,0},
															{0,1,1,0},
															{0,0,0,0}},
															{
																{0,0,0,0},
																{0,1,1,0},
																{0,1,1,0},
																{0,0,0,0}},
																{
																	{0,0,0,0},
																	{0,0,1,0},
																	{0,1,1,0},
																	{0,1,0,0}},
																	{
																		{0,0,0,0},
																		{0,1,1,0},
																		{0,0,1,1},
																		{0,0,0,0}},
																		{
																			{0,0,0,0},
																			{0,0,1,0},
																			{0,1,1,0},
																			{0,1,0,0}},
																			{
																				{0,0,0,0},
																				{0,1,1,0},
																				{0,0,1,1},
																				{0,0,0,0}},
																				{
																					{0,0,0,0},
																					{0,1,0,0},
																					{0,1,1,0},
																					{0,0,1,0}},
																					{
																						{0,0,0,0},
																						{0,1,1,0},
																						{1,1,0,0},
																						{0,0,0,0}},
																						{
																							{0,0,0,0},
																							{0,1,0,0},
																							{0,1,1,0},
																							{0,0,1,0}},
																							{
																								{0,0,0,0},
																								{0,1,1,0},
																								{1,1,0,0},
																								{0,0,0,0}},
																								{
																									{0,0,0,0},
																									{0,1,0,0},
																									{1,1,1,0},
																									{0,0,0,0}},
																									{
																										{0,1,0,0},
																										{1,1,0,0},
																										{0,1,0,0},
																										{0,0,0,0}},
																										{
																											{0,0,0,0},
																											{1,1,1,0},
																											{0,1,0,0},
																											{0,0,0,0}},
																											{
																												{0,1,0,0},
																												{0,1,1,0},
																												{0,1,0,0},
																												{0,0,0,0}},
																												{
																													{0,1,0,0},
																													{1,1,1,0},
																													{0,1,0,0},
																													{0,0,0,0}},
																													{
																														{0,1,0,0},
																														{1,1,1,0},
																														{0,1,0,0},
																														{0,0,0,0}},
																														{
																															{0,1,0,0},
																															{1,1,1,0},
																															{0,1,0,0},
																															{0,0,0,0}},
																															{
																																{0,1,0,0},
																																{1,1,1,0},
																																{0,1,0,0},
																																{0,0,0,0}},
																																{
																																	{1,1,1,0},
																																	{1,1,1,0},
																																	{1,1,1,0},
																																	{0,0,0,0}},
																																	{
																																		{1,1,1,0},
																																		{1,1,1,0},
																																		{1,1,1,0},
																																		{0,0,0,0}},
																																		{
																																			{1,1,1,0},
																																			{1,1,1,0},
																																			{1,1,1,0},
																																			{0,0,0,0}},
																																			{
																																				{1,1,1,0},
																																				{1,1,1,0},
																																				{1,1,1,0},
																																				{0,0,0,0}},



};
int gameover = 0;// 1이면 게임 오버
int nx = 0, ny = 0; //좌표를 나타내는 변수
int board[12][27]; //보드판을 표시
const char* tile[3] = { "  ","■","□" };
enum { empty, brick, wall };//empty=0,brick=1,wall=2를 차례대로 열거
int score = 0; //점수 
int waschogi()//윈속 초기화 함수
{
	wsaData;
	retval = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (retval != 0)
	{
		printf("WSAStartup() Error\n");
		return 0;
	}
}
int bbind() {
	serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv_sock == SOCKET_ERROR)
	{
		printf("socket() Error\n");
		return 0;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(4000);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	retval = bind(serv_sock, (SOCKADDR*)&serv_addr, sizeof(SOCKADDR));
	if (retval == SOCKET_ERROR)
	{
		printf("bind() Error\n");
		return 0;
	}
}//bind 함수
int aaccept() {//accept 함수
	size = sizeof(SOCKADDR_IN);
	clnt_sock = accept(serv_sock, (SOCKADDR*)&clnt_addr, &size);
	if (clnt_sock == SOCKET_ERROR)
	{
		printf("accept() Error\n");
		return 0;
	}
	//printf("클라이언트 접속\n");
	//printf("IP : %s, Port : %d\n",inet_ntoa(clnt_addr.sin_addr),clnt_addr.sin_port);
}
void ssend()
{
	while (1)
	{
		char buf[255] = { 0 };
		printf(">> ");
		gets_s(buf);
		int sendsize = send(clnt_sock, buf, strlen(buf), 0);
		if (sendsize == 0)
			break;
	}
}
void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void GAMEOVER()// 게임종료시 나타나는 함수
{
	system("cls");
	gotoxy(7, 2);
	printf("      ■■■         ■■         ■        ■   ■■■■■    \n");
	gotoxy(7, 3);
	printf("    ■              ■  ■        ■ ■  ■ ■   ■            \n");
	gotoxy(7, 4);
	printf("    ■             ■    ■       ■  ■■  ■   ■            \n");
	gotoxy(7, 5);
	printf("    ■   ■■■    ■■■■       ■   ■   ■   ■■■■■    \n");
	gotoxy(7, 6);
	printf("    ■     ■      ■     ■      ■        ■   ■            \n");
	gotoxy(7, 7);
	printf("      ■■ ■      ■     ■      ■        ■   ■            \n");
	gotoxy(7, 8);
	printf("           ■      ■     ■      ■        ■   ■■■■■    \n");
	Sleep(1000);
	gotoxy(7, 12);
	printf("      ■■■      ■        ■     ■■■■■   ■■■■      \n");
	gotoxy(7, 13);
	printf("    ■      ■    ■        ■     ■           ■      ■    \n");
	gotoxy(7, 14);
	printf("    ■      ■    ■        ■     ■           ■      ■    \n");
	gotoxy(7, 15);
	printf("    ■      ■     ■      ■      ■■■■■   ■■■■      \n");
	gotoxy(7, 16);
	printf("    ■      ■      ■    ■       ■           ■     ■     \n");
	gotoxy(7, 17);
	printf("    ■      ■       ■  ■        ■           ■       ■   \n");
	gotoxy(7, 18);
	printf("      ■■■           ■          ■■■■■   ■         ■ \n");
	gotoxy(30, 23);
	printf("score = %d", score);
}
void pMode1()//게임시작시 처음나타나는 화면
{
	gotoxy(7, 2);
	printf("■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(7, 3);
	printf("■                                  ■\n");
	gotoxy(7, 4);
	printf("■      상대방과 연결되었 습니다.   ■\n");
	gotoxy(7, 5);
	printf("■      IP = %s", inet_ntoa(clnt_addr.sin_addr));
	gotoxy(43, 5); printf("■\n");
	gotoxy(7, 6);
	printf("■      port = %d  ", clnt_addr.sin_port);
	gotoxy(43, 6); printf("■\n");
	gotoxy(7, 7);
	printf("■                                  ■\n");
	gotoxy(7, 8);
	printf("■■■■■■■■■■■■■■■■■■■\n");

}//게임시작시 /
void pMode2()
{
	gotoxy(7, 2);
	printf("■■■■■  ■■■■■  ■■■■■  ■■■■    ■■■    ■■■  \n");
	gotoxy(7, 3);
	printf("    ■      ■              ■      ■      ■    ■    ■      ■\n");
	gotoxy(7, 4);
	printf("    ■      ■              ■      ■      ■    ■    ■        \n");
	gotoxy(7, 5);
	printf("    ■      ■■■■■      ■      ■■■■      ■      ■■■  \n");
	gotoxy(7, 6);
	printf("    ■      ■              ■      ■      ■    ■            ■\n");
	gotoxy(7, 7);
	printf("    ■      ■              ■      ■      ■    ■    ■      ■\n");
	gotoxy(7, 8);
	printf("    ■      ■■■■■      ■      ■      ■  ■■■    ■■■  \n");
	gotoxy(23, 14); printf("┌──<  Key Instructions  >──┐");
	gotoxy(23, 15); printf("│     ROTATE         ↑        │");
	gotoxy(23, 16); printf("│     RIGHT          →        │");
	gotoxy(23, 17); printf("│     LEFT           ←        │");
	gotoxy(23, 18); printf("│     SOFT DROP      ↓        │");
	gotoxy(23, 19); printf("│     HARD DROP     Space      │");
	gotoxy(23, 20); printf("└───────────────┘");
	gotoxy(33, 21); printf("Press any key");
	getch();
	system("cls");
}//게임시작전 나타나는 화면
void print()//블럭모양을 프린트해주는 함수
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r][i][j] == 1)
			{
				gotoxy(nx + j * 2, ny + i);
				printf("■");
			}
		}
		printf("\n");
	}
}
void nprint()//블럭을 지울때 쓰는 함수
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r][i][j] == 1)
			{
				gotoxy(nx + j * 2, ny + i);
				printf("  ");
			}
		}
		printf("\n");
	}
}
void down()//블럭이 내려가는 함수
{
	nprint();
	ny++;
	print();
}
void next()//다음블록을 보여주는 함수
{
	int i, j;
	gotoxy(28, 6);
	printf("★next block★");
	gotoxy(30, 10);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r1][i][j] == 1)
			{
				gotoxy(30 + j * 2, 2 + i);
				printf("■");
			}
			else
			{
				gotoxy(30 + j * 2, 2 + i);
				printf("  ");
			}
			printf("\n");
		}
	}
}
void DrawScreen() // 게임판을 그리는 함수
{
	int x, y;
	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 27; y++)
		{
			gotoxy(x * 2, y); //블록 하나의 크기의 x값이 2임으로 *2 를 해줌
			puts(tile[board[x][y]]); //tile 값이 1이면 블록을 표시 2면 벽을 표시
		}
	}
}
int gamgi() // 아래에 벽과 블록을 감지한다.
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if (q[r][3 - j][i] == 1 && board[nx / 2 + i][(ny + 4 - j)] == 2)
			{
				return 1;
			}
			if (q[r][3 - j][i] == 1 && board[nx / 2 + i][(ny + 4 - j)] == 1)
			{
				return 1;
			}
		}
	}
}
int gamgi2()  //양옆의 벽과 블록을 감지한다.
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{

			if (q[r][i][j] == 1 && board[nx / 2 - 1 + j][(ny + i)] == 2)//왼쪽감지
				return 2;
			if (q[r][i][j] == 1 && board[nx / 2 - 1 + j][(ny + i)] == 1)//왼쪽감지
				return 2;
			if (q[r][i][3 - j] == 1 && board[nx / 2 + 4 - j][(ny + i)] == 2)//오른쪽감지
				return 3;
			if (q[r][i][3 - j] == 1 && board[nx / 2 + 4 - j][(ny + i)] == 1)//오른쪽감지
				return 3;
		}
	}
}
void Sboard() //블록을 board[x][y]에 저장하는함수
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r][i][j] == 1)
			{
				board[nx / 2 + j][ny + i] = 1;
			}
		}
	}
}
void Rboard()   //블록을 지우는 함수
{
	int i, j, x, y, jull, sjull = 0;
	int jungbo[2];
	for (i = 1; i < 27; i++) // y축을 검사
	{
		jull = 0;
		for (j = 1; j < 11; j++) //한줄이 전부 블록으로 되어있으면 지운줄을 +시킴
		{
			if (board[j][i] == 1)
				++jull;
			if (jull == 10)
			{
				++sjull;  //총 지운 줄의 갯수를 저장
				for (y = i; y > 0; y--)
				{
					for (x = 1; x < 11; x++)
					{
						board[x][y] = board[x][y - 1]; //블록을 이동시킴
						board[x][1] = 0;
					}
				}
			}
		}
	}
	if (sjull != 0)
	{
		if (sjull == 1)  //지운 줄에따른 점수 획득
		{
			score += 10;
			Beep(523, 200); // '도' 를 출력
			Beep(988, 200);
		}
		else if (sjull == 2)
		{
			score += 25;
			Beep(523, 200);
			Beep(988, 200);
		}
		else if (sjull == 3)
		{
			score += 40;
			Beep(523, 200);
			Beep(988, 200);
		}
		else if (sjull == 4)
		{
			score += 60;
			Beep(523, 200);
			Beep(988, 200);
		}
		jungbo[0] = 1;
		jungbo[1] = score;
		jungbo[0] = htons(jungbo[0]);
		jungbo[1] = htons(jungbo[1]);
		send(clnt_sock, (char*)jungbo, sizeof(jungbo), 0);
	}
	DrawScreen(); //줄을 지운후 게임판을 다시그림

}//블록을 
void Pboard()
{
	int i, j, x, y, rannum;
	for (y = 2; y < 26; y++)
	{
		for (x = 1; x < 11; x++)
		{
			board[x][y - 1] = board[x][y]; //블록을 이동시킴
		}
	}
	for (x = 1; x < 11; x++)
	{
		board[x][25] = 1; //블록을 이동시킴
	}
	rannum = rand() % 10 + 1;
	board[rannum][25] = 0;

}//상대방에게서 전달받은 값에따라 블록을 추가해주는 함수
void __cdecl RecvThread2(void* p)
{
	int jungbo[2];
	while (1)
	{
		int recvsize = recv(clnt_sock, (char*)jungbo, sizeof(jungbo), 0);
		if (recvsize == 0) {
			printf("접속종료\n");
			break;
		}
		jungbo[0] = ntohs(jungbo[0]);
		jungbo[1] = ntohs(jungbo[1]);
		if (jungbo[0] == 1)	//상대방이 한줄 지웠을떄
		{
			Pboard();
			DrawScreen();
		}
		else if (jungbo[0] == 3) {//상대방이 게임에서 졌을떄
			gameover = 1;
			return;
		}
		otherscore = jungbo[1];
	}
}
unsigned __stdcall Thread2(void* arg) //스레드 키처리 함수
{
	int key;
	while (1)
	{
		if (kbhit()) {
			key = getch();
			if (key == RIGHT)
			{
				if (gamgi() != 1)
				{
					if (gamgi2() != 3)
					{
						nprint();
						nx += 2;
						print();
					}
				}
			}
			else if (key == LEFT)
			{
				if (gamgi() != 1)
				{
					if (gamgi2() != 2)
					{
						nprint();
						nx -= 2;
						print();
					}
				}
			}
			else if (key == DOWN)
			{
				if (gamgi() != 1)
				{
					nprint();
					ny++;
					print();
				}

			}
			else if (key == UP) {
				nprint();
				if (nx < 2)  //회전시 왼쪽 벽과 블록의 충돌방지
					nx = 2;
				if (nx > 14)  //회전시 오른쪽 벽과 블록의 충돌 방지
					nx = 14;
				r += 1;
				if (r % 4 == 0) //다음 블록으로 넘어가지 않게 하기위해서
				{
					r -= 4;
				}
				print();
			}
			else if (key == 32)
			{
				while (1)
				{
					nprint();
					ny++;
					if (gamgi() == 1)
					{
						print();
						break;
					}
				}
			}
		}
	}
	return 0;
}
void game()
{

	int check; //게임이 종료됫는지 알려주는 함수
	int jungbo[2];//상대방에서 온 데이터
	srand(time(NULL));
	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 27; y++)
		{
			board[x][y] = (y == 0 || y == 26 || x == 0 || x == 11) ? wall : empty; //보드판정의
		}
	}
	DrawScreen(); // 게임판 그리기
	r1 = rand() % 6; //다음 블록을 위한 변수
	r1 = r1 * 4;
	gotoxy(50, 1);
	printf("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐");
	gotoxy(50, 2);
	printf("│                    │");
	gotoxy(50, 3);
	printf("└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘");
	_beginthread(RecvThread2, NULL, NULL);
	_beginthreadex(NULL, 0, Thread2, 0, 0, NULL);  //스레드 시작
	for (;;)
	{


		if (gameover == 1)		//게임을 종료한다.
		{
			Sleep(1000);
			break;
		}
		gotoxy(52, 2);
		printf("score : %d   ", score);		//자신과 상대방의 점수 출력
		gotoxy(52, 5);
		printf("other score : %d  ", otherscore);

		r = r1; // 블록을 랜덤으로 뽑기 위한 변수
		if (difficulty == 1)
		{
			r1 = rand() % 7;
		}
		else if (difficulty == 2)		//난이도를 올려 블록수를 추가해주는 변수
			r1 = rand() % 9;

		r1 = r1 * 4;
		next(); // 다음 블록을 보여주는 함수
		nx = 10, ny = 1;

		for (;;)
		{
			gotoxy(nx, ny);
			print();

			if (gamgi() == 1)		//바닥또는 블럭과 닿지않으면
			{
				Sboard();
				Rboard();
				for (check = 1; check < 11; check++)
				{
					if (board[check][1] == 1)
					{
						gameover = 1; //게임오버가 1이면 게임 오버
						jungbo[0] = 3;
						jungbo[1] = 9999;
						jungbo[0] = htons(jungbo[0]);
						jungbo[1] = htons(jungbo[1]);
						send(clnt_sock, (char*)jungbo, sizeof(jungbo), 0);
					}
				}
				break;
			}
			else
			{
				if (gamgi() != 1)			//바닥또는 블럭과 닿지 않으면
				{
					down();
					if (score < 40)		//점수에따라 내려오는 속도가 변한다.
						Sleep(150);
					else if (40 <= score < 80)
						Sleep(200);
					else if (80 <= score < 120)
					{
						difficulty = 2;
						Sleep(100);
					}
					else if (120 <= score < 150)
						Sleep(50);
					else if (150 <= score < 200)
						Sleep(30);
				}
			}
		}

	}
}
int main() {
	waschogi();		//윈속 초기화
	bbind();		//bind
	listen(serv_sock, 5);//listen
	aaccept();			//accept
	pMode1();			//게임시작전 첫번째 화면
	Sleep(3000);
	pMode2();			//게임시작전 두번째 화면
	system("cls");
	difficulty = 1;		//나오는 블록수의 단계를 1단계로 설정
	gameover = 0;			//게임 오버를 0으로 설정
	game();				//게임을 시작한다.
	system("cls");
	if (gameover == 1) {	//게임오버가 1이되면 게임을 종료
		GAMEOVER();		//게임을 종료하는 화면을 출력한다.
		Sleep(3000);
		system("cls");
	}
}
