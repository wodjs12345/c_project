// ttteee.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
int q[][4][4] = { { //��� ���  ǥ��
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
int gameover = 0;// 1�̸� ���� ����
int nx = 0, ny = 0; //��ǥ�� ��Ÿ���� ����
int board[12][27]; //�������� ǥ��
const char* tile[3] = { "  ","��","��" };
enum { empty, brick, wall };//empty=0,brick=1,wall=2�� ���ʴ�� ����
int score = 0; //���� 
int waschogi()//���� �ʱ�ȭ �Լ�
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
}//bind �Լ�
int aaccept() {//accept �Լ�
	size = sizeof(SOCKADDR_IN);
	clnt_sock = accept(serv_sock, (SOCKADDR*)&clnt_addr, &size);
	if (clnt_sock == SOCKET_ERROR)
	{
		printf("accept() Error\n");
		return 0;
	}
	//printf("Ŭ���̾�Ʈ ����\n");
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
void GAMEOVER()// ��������� ��Ÿ���� �Լ�
{
	system("cls");
	gotoxy(7, 2);
	printf("      ����         ���         ��        ��   ������    \n");
	gotoxy(7, 3);
	printf("    ��              ��  ��        �� ��  �� ��   ��            \n");
	gotoxy(7, 4);
	printf("    ��             ��    ��       ��  ���  ��   ��            \n");
	gotoxy(7, 5);
	printf("    ��   ����    �����       ��   ��   ��   ������    \n");
	gotoxy(7, 6);
	printf("    ��     ��      ��     ��      ��        ��   ��            \n");
	gotoxy(7, 7);
	printf("      ��� ��      ��     ��      ��        ��   ��            \n");
	gotoxy(7, 8);
	printf("           ��      ��     ��      ��        ��   ������    \n");
	Sleep(1000);
	gotoxy(7, 12);
	printf("      ����      ��        ��     ������   �����      \n");
	gotoxy(7, 13);
	printf("    ��      ��    ��        ��     ��           ��      ��    \n");
	gotoxy(7, 14);
	printf("    ��      ��    ��        ��     ��           ��      ��    \n");
	gotoxy(7, 15);
	printf("    ��      ��     ��      ��      ������   �����      \n");
	gotoxy(7, 16);
	printf("    ��      ��      ��    ��       ��           ��     ��     \n");
	gotoxy(7, 17);
	printf("    ��      ��       ��  ��        ��           ��       ��   \n");
	gotoxy(7, 18);
	printf("      ����           ��          ������   ��         �� \n");
	gotoxy(30, 23);
	printf("score = %d", score);
}
void pMode1()//���ӽ��۽� ó����Ÿ���� ȭ��
{
	gotoxy(7, 2);
	printf("��������������������\n");
	gotoxy(7, 3);
	printf("��                                  ��\n");
	gotoxy(7, 4);
	printf("��      ����� ����Ǿ� ���ϴ�.   ��\n");
	gotoxy(7, 5);
	printf("��      IP = %s", inet_ntoa(clnt_addr.sin_addr));
	gotoxy(43, 5); printf("��\n");
	gotoxy(7, 6);
	printf("��      port = %d  ", clnt_addr.sin_port);
	gotoxy(43, 6); printf("��\n");
	gotoxy(7, 7);
	printf("��                                  ��\n");
	gotoxy(7, 8);
	printf("��������������������\n");

}//���ӽ��۽� /
void pMode2()
{
	gotoxy(7, 2);
	printf("������  ������  ������  �����    ����    ����  \n");
	gotoxy(7, 3);
	printf("    ��      ��              ��      ��      ��    ��    ��      ��\n");
	gotoxy(7, 4);
	printf("    ��      ��              ��      ��      ��    ��    ��        \n");
	gotoxy(7, 5);
	printf("    ��      ������      ��      �����      ��      ����  \n");
	gotoxy(7, 6);
	printf("    ��      ��              ��      ��      ��    ��            ��\n");
	gotoxy(7, 7);
	printf("    ��      ��              ��      ��      ��    ��    ��      ��\n");
	gotoxy(7, 8);
	printf("    ��      ������      ��      ��      ��  ����    ����  \n");
	gotoxy(23, 14); printf("������<  Key Instructions  >������");
	gotoxy(23, 15); printf("��     ROTATE         ��        ��");
	gotoxy(23, 16); printf("��     RIGHT          ��        ��");
	gotoxy(23, 17); printf("��     LEFT           ��        ��");
	gotoxy(23, 18); printf("��     SOFT DROP      ��        ��");
	gotoxy(23, 19); printf("��     HARD DROP     Space      ��");
	gotoxy(23, 20); printf("����������������������������������");
	gotoxy(33, 21); printf("Press any key");
	getch();
	system("cls");
}//���ӽ����� ��Ÿ���� ȭ��
void print()//������� ����Ʈ���ִ� �Լ�
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r][i][j] == 1)
			{
				gotoxy(nx + j * 2, ny + i);
				printf("��");
			}
		}
		printf("\n");
	}
}
void nprint()//���� ���ﶧ ���� �Լ�
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
void down()//���� �������� �Լ�
{
	nprint();
	ny++;
	print();
}
void next()//��������� �����ִ� �Լ�
{
	int i, j;
	gotoxy(28, 6);
	printf("��next block��");
	gotoxy(30, 10);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (q[r1][i][j] == 1)
			{
				gotoxy(30 + j * 2, 2 + i);
				printf("��");
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
void DrawScreen() // �������� �׸��� �Լ�
{
	int x, y;
	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 27; y++)
		{
			gotoxy(x * 2, y); //��� �ϳ��� ũ���� x���� 2������ *2 �� ����
			puts(tile[board[x][y]]); //tile ���� 1�̸� ����� ǥ�� 2�� ���� ǥ��
		}
	}
}
int gamgi() // �Ʒ��� ���� ����� �����Ѵ�.
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
int gamgi2()  //�翷�� ���� ����� �����Ѵ�.
{
	int i, j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 4; i++)
		{

			if (q[r][i][j] == 1 && board[nx / 2 - 1 + j][(ny + i)] == 2)//���ʰ���
				return 2;
			if (q[r][i][j] == 1 && board[nx / 2 - 1 + j][(ny + i)] == 1)//���ʰ���
				return 2;
			if (q[r][i][3 - j] == 1 && board[nx / 2 + 4 - j][(ny + i)] == 2)//�����ʰ���
				return 3;
			if (q[r][i][3 - j] == 1 && board[nx / 2 + 4 - j][(ny + i)] == 1)//�����ʰ���
				return 3;
		}
	}
}
void Sboard() //����� board[x][y]�� �����ϴ��Լ�
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
void Rboard()   //����� ����� �Լ�
{
	int i, j, x, y, jull, sjull = 0;
	int jungbo[2];
	for (i = 1; i < 27; i++) // y���� �˻�
	{
		jull = 0;
		for (j = 1; j < 11; j++) //������ ���� ������� �Ǿ������� �������� +��Ŵ
		{
			if (board[j][i] == 1)
				++jull;
			if (jull == 10)
			{
				++sjull;  //�� ���� ���� ������ ����
				for (y = i; y > 0; y--)
				{
					for (x = 1; x < 11; x++)
					{
						board[x][y] = board[x][y - 1]; //����� �̵���Ŵ
						board[x][1] = 0;
					}
				}
			}
		}
	}
	if (sjull != 0)
	{
		if (sjull == 1)  //���� �ٿ����� ���� ȹ��
		{
			score += 10;
			Beep(523, 200); // '��' �� ���
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
	DrawScreen(); //���� ������ �������� �ٽñ׸�

}//����� 
void Pboard()
{
	int i, j, x, y, rannum;
	for (y = 2; y < 26; y++)
	{
		for (x = 1; x < 11; x++)
		{
			board[x][y - 1] = board[x][y]; //����� �̵���Ŵ
		}
	}
	for (x = 1; x < 11; x++)
	{
		board[x][25] = 1; //����� �̵���Ŵ
	}
	rannum = rand() % 10 + 1;
	board[rannum][25] = 0;

}//���濡�Լ� ���޹��� �������� ����� �߰����ִ� �Լ�
void __cdecl RecvThread2(void* p)
{
	int jungbo[2];
	while (1)
	{
		int recvsize = recv(clnt_sock, (char*)jungbo, sizeof(jungbo), 0);
		if (recvsize == 0) {
			printf("��������\n");
			break;
		}
		jungbo[0] = ntohs(jungbo[0]);
		jungbo[1] = ntohs(jungbo[1]);
		if (jungbo[0] == 1)	//������ ���� ��������
		{
			Pboard();
			DrawScreen();
		}
		else if (jungbo[0] == 3) {//������ ���ӿ��� ������
			gameover = 1;
			return;
		}
		otherscore = jungbo[1];
	}
}
unsigned __stdcall Thread2(void* arg) //������ Űó�� �Լ�
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
				if (nx < 2)  //ȸ���� ���� ���� ����� �浹����
					nx = 2;
				if (nx > 14)  //ȸ���� ������ ���� ����� �浹 ����
					nx = 14;
				r += 1;
				if (r % 4 == 0) //���� ������� �Ѿ�� �ʰ� �ϱ����ؼ�
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

	int check; //������ ����̴��� �˷��ִ� �Լ�
	int jungbo[2];//���濡�� �� ������
	srand(time(NULL));
	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 27; y++)
		{
			board[x][y] = (y == 0 || y == 26 || x == 0 || x == 11) ? wall : empty; //����������
		}
	}
	DrawScreen(); // ������ �׸���
	r1 = rand() % 6; //���� ����� ���� ����
	r1 = r1 * 4;
	gotoxy(50, 1);
	printf("���ѤѤѤѤѤѤѤѤѤѦ�");
	gotoxy(50, 2);
	printf("��                    ��");
	gotoxy(50, 3);
	printf("���ѤѤѤѤѤѤѤѤѤѦ�");
	_beginthread(RecvThread2, NULL, NULL);
	_beginthreadex(NULL, 0, Thread2, 0, 0, NULL);  //������ ����
	for (;;)
	{


		if (gameover == 1)		//������ �����Ѵ�.
		{
			Sleep(1000);
			break;
		}
		gotoxy(52, 2);
		printf("score : %d   ", score);		//�ڽŰ� ������ ���� ���
		gotoxy(52, 5);
		printf("other score : %d  ", otherscore);

		r = r1; // ����� �������� �̱� ���� ����
		if (difficulty == 1)
		{
			r1 = rand() % 7;
		}
		else if (difficulty == 2)		//���̵��� �÷� ��ϼ��� �߰����ִ� ����
			r1 = rand() % 9;

		r1 = r1 * 4;
		next(); // ���� ����� �����ִ� �Լ�
		nx = 10, ny = 1;

		for (;;)
		{
			gotoxy(nx, ny);
			print();

			if (gamgi() == 1)		//�ٴڶǴ� ���� ����������
			{
				Sboard();
				Rboard();
				for (check = 1; check < 11; check++)
				{
					if (board[check][1] == 1)
					{
						gameover = 1; //���ӿ����� 1�̸� ���� ����
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
				if (gamgi() != 1)			//�ٴڶǴ� ���� ���� ������
				{
					down();
					if (score < 40)		//���������� �������� �ӵ��� ���Ѵ�.
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
	waschogi();		//���� �ʱ�ȭ
	bbind();		//bind
	listen(serv_sock, 5);//listen
	aaccept();			//accept
	pMode1();			//���ӽ����� ù��° ȭ��
	Sleep(3000);
	pMode2();			//���ӽ����� �ι�° ȭ��
	system("cls");
	difficulty = 1;		//������ ��ϼ��� �ܰ踦 1�ܰ�� ����
	gameover = 0;			//���� ������ 0���� ����
	game();				//������ �����Ѵ�.
	system("cls");
	if (gameover == 1) {	//���ӿ����� 1�̵Ǹ� ������ ����
		GAMEOVER();		//������ �����ϴ� ȭ���� ����Ѵ�.
		Sleep(3000);
		system("cls");
	}
}
