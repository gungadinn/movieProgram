#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define CUSTOMER_MAX 50

//사용자 정보를 저장하는 구조체
typedef struct PPL {
	char moivename[20];
	char *seat_alpha[150];
	char *seat_num[150];
	int old;
	int adult;
	int young;
	int money; //결제금액
	int total;
	int time;
} PPL;

//결제할 때 필요한 카드의 정보를 저장하는 구조체
typedef struct CardInfo {
	char number[20];
	char period[6];
	int password;
	int birth;
} CardInfo;

//멤버십 가입할 때 필요한 정보들을 저장하는 구조체
typedef struct membership {
	char name[20];
	int number;
	int point;
}members;

//좌석 배열 (20=공백 / 0=흰색 네모 / 15=검정네모 / 기타 = 열과 행)
//이 2차원 배열이 좌석으로 출력된다.

//미이라 1회차
int seat1_1[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//미이라 2회차
int seat1_2[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//원더우먼 1회차
int seat2_1[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//원더우먼 2회차
int seat2_2[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//대립군 1회차
int seat3_1[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//대립군 2회차
int seat3_2[10][14] = { { 20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
{ 'A', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'B', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'C', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'D', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'F', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'G', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'H', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 'I', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

char *m_ppl = { "관람 인원은 몇 명입니까?   우대 :    어른 :    청소년 :     " };   //크기 58
char *m_calmoney = { "      원입니다.    명의 좌석을 골라주세요." };
char *m_ismem = { "라희와 아이들 영화관의 회원이십니까?   (1)예   (2)아니오" };
char *m_pay1 = { "결제중" };
char *m_pay2 = { "결제가 완료되었습니다." };

char m_name[3][10] = { "미이라", "원더우먼", "대립군" };
char m_time1[3][18] = { "1회 : 11:00~12:50", "1회 : 10:40~12:40", "1회 : 13:10~14:54" };
char m_time2[3][18] = { "2회 : 14:30~15:20", "2회 : 13:15~15:15", "2회 : 17:00~18:44" };
char *m_function[3] = { "▶영화예매", "▶리뷰보기", "▶줄거리보기" };
char *m_screen = { "스크린" };

char *rev1 = { " ===미이라 리뷰===" };
char *rev2 = { " ===원더우먼 리뷰===" };
char *rev3 = { " ===대립군 리뷰===" };
char *summ1 = { " ===미이라 줄거리===" };
char *summ2 = { " ===원더우먼 줄거리===" };
char *summ3 = { " ===대립군 줄거리===" };

char *m_mem = { "라희와 아이들 영화관의 회원이십니까?  (1)예 (2)아니오 " };
char *m_join = { "멤버십 가입을 하시겠습니까? (1)예  (2)아니오  " };
char* m_point = { "포인트를 사용하시겠습니까? (1)예 (2)아니오  " };
char *m_bill = { "영수증을 출력하는 중입니다. " };

int count = 0;
int playcount = 0;

void gotoxy(int x, int y);

void show_intro(int c, int r);  //광고판 하단까지 포함하여 출력하는 함수
void show_movie(int c, int r, int k, int width);  //영화정보를 출력하기 위해 사용되는 함수
void show_data(int c, int r, int k, int column);  //영화정보를 출력한다. (show_movie함수 안에서 실행된다.)
void show_box(int c, int r, char *sen);  //광고판 밑에 원하는 질문이 있을 경우 해당 문장까지 출력해주는 함수이다. 양 옆의 공백은 자동계산하게 함수를 만들었다.
void show_title(int c, int r);  //광고판 상단부분
void draw_rectangle2(int c, int r, int width);  //직사각형 출력하는 함수.
//좌표이동을 하여 직사각형을 출력할 경우 1열과 직사각형이 출력되는 왼쪽 선의 공백을 계산하여 출력하게 만들었다.
void ShowSeat(int arr[][14], int row, int col);  //전역함수로 선언한 seat 2차원 배열을 좌석으로 출력하게 한다.
void GetCardInfo(CardInfo *card);  //카드정보를 입력받는 함수
void move_figure();  //결제중이라는 표시가 뜨도록 만든 애니메이션 함수

//첫 화면에서 메뉴를 오갈 때 필요한 함수들이다.
void choose_menu00(HANDLE *x, PPL *p);  
void choose_menu01(HANDLE *x, PPL *p);
void choose_menu02(HANDLE *x, PPL *p);
void choose_menu10(HANDLE *x, PPL *p);
void choose_menu11(HANDLE *x, PPL *p);
void choose_menu12(HANDLE *x, PPL *p);
void choose_menu20(HANDLE *x, PPL *p);
void choose_menu21(HANDLE *x, PPL *p);
void choose_menu22(HANDLE *x, PPL *p);
void choose_menu30(HANDLE *x, PPL *p);
void choose_menu31(HANDLE *x, PPL *p);
void choose_menu32(HANDLE *x, PPL *p);
void choose_menu40(HANDLE *x, PPL *p);
void choose_menu41(HANDLE *x, PPL *p);
void choose_menu42(HANDLE *x, PPL *p);
void choose_menu50(HANDLE *x, PPL *p);
void choose_menu51(HANDLE *x, PPL *p);
void choose_menu52(HANDLE *x, PPL *p);
int* check_movie(PPL *p);  //사용자가 어느 영화를 보고 어느 회차를 보는지 알아낸 후 해당 좌석을 반환한다.

//리뷰 출력 함수
int m_review01(int c, int r);
int m_review02(int c, int r);
int m_review03(int c, int r);
//줄거리 출력 함수
int m_story01(int c, int r);
int m_story02(int c, int r);
int m_story03(int c, int r);

void checkcheck();
void black_seat(int arr[][14], char alphabet, int num);

void PayMoney(int point);
void ismember(members* a);      // 멤버십 가입 여부 확인
void member(members* a);
int question();
void input_member(members* a);
void Getpoint(members* a, int x);
int usingpoint(members* a);
void bill_print();
int choose_answer01(HANDLE *x);
int choose_answer02(HANDLE *x);
int choose_answer03(HANDLE *x);
int choose_answer04(HANDLE *x);
int choose_answer05(HANDLE *x);
int choose_answer06(HANDLE *x);



PPL P1;

void main()
{
	members* M;
	M = (members*)malloc(sizeof(members)*CUSTOMER_MAX);

	system("color 07");

	while (1)
	{

		int i, num;
		char key, alphabet[150];

		//콘솔창 색깔 바꾸기 위해서 필요하다
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);

		//처음화면
		gotoxy(7, 2);
		show_intro(33, 1);  //광고판 출력
		for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
		{
			gotoxy(1 + 28 * i, 5);
			show_movie(12, 18, i, 1 + 28 * i);
		}

		//메뉴를 받는다.
		key = getch();

		if (key == 27)
			break;

		choose_menu00(hC, &P1);

		//리뷰를 보던 줄거리를 보던 결국엔 좌석 선택할 수 밖에 없으니 아래에 좌석 입력받는 코드를 둔다.
		//좌석 출력하는거 보여줌

		//상단 광고 출력
		gotoxy(7, 2);
		show_box(33, 1, m_ppl);

		//인원수 입력받기
		gotoxy(46, 5);
		scanf("%d", &P1.old);
		gotoxy(56, 5);
		scanf("%d", &P1.adult);
		gotoxy(68, 5);
		scanf("%d", &P1.young);

		//입력받은 인원수를 계산해 최종 결제 금액과 최종 인원수를 구한다.
		P1.money = (4000 * P1.old) + (10000 * P1.adult) + (7000 * P1.young);
		P1.total = P1.old + P1.adult + P1.young;


		//좌석을 입력받는다.
		gotoxy(78, 10);
		printf("● %d명의 좌석을 입력해주세요 ●", P1.total);

		for (i = 0; i < P1.total; i++) // 인원수 만큼
		{
			gotoxy(78, 12);
			printf("원하는 좌석의 알파벳을 입력해주세요\n");//인원수만큼 for문
			gotoxy(78, 13);
			printf("▶▶");
			gotoxy(84, 13);
			scanf("%s", &alphabet[i]);

			//알파벳 대문자가 아니면
			if (alphabet[i] <= 64 || alphabet[i] >= 74)
			{
				while (1)
				{
					gotoxy(86, 13);
					printf("!알파벳 대문자가 아닙니다. 다시입력해주세요!");
					Sleep(1000);
					gotoxy(84, 13);
					printf("                                              ");
					gotoxy(84, 13);
					scanf("%S", &alphabet[i]);
					gotoxy(84, 13);
					if (alphabet[i] >= 64 && alphabet[i] <= 74)
					{
						P1.seat_alpha[i] = alphabet[i];
						break;
					}
				}
			}

			//알파벳 대문자면
			else if (alphabet[i] >= 64 && alphabet[i] <= 74)
				P1.seat_alpha[i] = alphabet[i];


			gotoxy(78, 15);
			printf("원하는 좌석의 열을 입력해주세요\n");
			gotoxy(78, 16);
			printf("▶▶");
			gotoxy(84, 16);
			scanf("%d", &num);
			P1.seat_num[i] = num;

			black_seat(check_movie(&P1), alphabet[i], num);

			Sleep(200);
			gotoxy(84, 13);
			printf("  ");
			gotoxy(84, 16);
			printf("  ");
		}

		checkcheck();  //좌석이 제대로 예매되었는지 확인한다.
		system("cls");

		ismember(M); //멤버십 유무 확인

		gotoxy(1, 33);
		system("cls");
		P1.money = 0;  //다시 money를 초기화해준다.
	}
}


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//영화 광고판 출력
void show_intro(int c, int r)  //c가 너비, r이 길이
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	show_title(c, r);

	for (j = 0; j < 6; j++)
		printf(" ");
	printf("%c%c", a, b[6]);   // └출력
	for (i = 0; i < c; i++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   // ┘출력
	printf("\n");
}

// 영화출력함수
void show_movie(int c, int r, int k, int width)     //(c가 너비, r이 길이)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	//상단출력
	printf("%c%c", a, b[3]);   //┌ 출력
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);   // ─ 출력

	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//가운데 출력
	for (i = 0; i < 2; i++)   //│ 출력
	{
		gotoxy(1 + 28 * k, 6 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	show_data(c, r - 2, k, 8);  //영화 출력 : 8은 열의 위치

								//하단출력
	gotoxy(1 + 28 * k, 5 + r);
	printf("%c%c", a, b[6]);   // └출력
	for (i = 0; i < c; i++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   // ┘출력
	printf("\n");
}

//영화 관련 정보 출력
void show_data(int c, int r, int k, int column)   //c가 너비, r이 길이
{
	int i, j, n;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	gotoxy(1 + 28 * k, column);  //열의 위치 : 8
	printf("%c%c", a, b[2]);//│ 출력

							//영화 출력
	for (j = 0; j < (c * 2 - strlen(m_name[k]) - 2) / 2; j++)
		printf(" ");
	printf("<%s>", m_name[k]);
	for (j = 0; j < (c * 2 - strlen(m_name[k]) - 2) / 2; j++)
		printf(" ");
	printf("%c%c\n", a, b[2]);  //│ 출력

	gotoxy(1 + 28 * k, column + 1);//│ 출력
	printf("%c%c", a, b[2]);
	for (j = 0; j < c; j++)
		printf("  ");
	printf("%c%c", a, b[2]);
	printf("\n");


	//줄 넘어가서 상영시간 출력
	for (i = 0; i < 2; i++)
	{
		gotoxy(1 + 28 * k, column + i + 2);
		printf("%c%c  ", a, b[2]);
		for (j = 0; j < (c * 2 - strlen(m_time1[k]) - 2) / 2; j++)
			printf(" ");
		printf("%s", m_time1[k]);
		for (j = 0; j < (c * 2 - strlen(m_time1[k]) - 2) / 2; j++)
			printf(" ");
		printf(" %c%c", a, b[2]);
	}

	for (i = 0; i < 2; i++)
	{
		gotoxy(1 + 28 * k, column + i + 3);
		printf("%c%c  ", a, b[2]);
		for (j = 0; j < (c * 2 - strlen(m_time2[k]) - 2) / 2; j++)
			printf(" ");
		printf("%s", m_time2[k]);
		for (j = 0; j < (c * 2 - strlen(m_time2[k]) - 2) / 2; j++)
			printf(" "); printf(" %c%c", a, b[2]);
	}

	//빈 공간 중간출력
	for (i = 0; i < 3; i++)   //│ 출력
	{
		gotoxy(1 + 28 * k, column + 4 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	//기능들 출력
	for (i = 0; i < 3; i++)
	{
		gotoxy(1 + 28 * k, column + 7 + i);   //다음 줄로 넘어가기
		n = strlen(m_function[i]);
		printf("%c%c", a, b[2]);   //│ 출력
		for (j = 0; j < (c * 2 - n) / 2; j++)
			printf(" ");
		printf("%s", m_function[i]);
		for (j = 0; j < (c * 2 - n) / 2; j++)
			printf(" ");
		printf("%c%c", a, b[2]);   //│ 출력
	}

	//빈공간 출력
	for (i = 0; i < r - 10; i++)   //│ 출력
	{
		gotoxy(1 + 28 * k, column + 10 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
}

//중간 문장 출력 부분 (단, 문장 크기는 꼭 짝수로!!)
void show_box(int c, int r, char *sen)  //c가 너비, r이 길이
{
	int i, j, n1 = strlen(sen);
	int n2 = c * 2 - n1;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	show_title(c, r); //라희와 아이들 광고판 상단부분 출력

	for (j = 0; j < 6; j++)
		printf(" ");
	printf("├");   // ├출력
	for (i = 0; i < c; i++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("┤");   // ┤출력
	printf("\n");

	//이 부분에 원하는 문장 출력
	gotoxy(7, 5);  //열의 위치 : 5
	printf("%c%c", a, b[2]);//│ 출력

							//영화 출력
	for (j = 0; j < n2 / 2; j++)
		printf(" ");
	printf("%s", sen);
	for (j = 0; j < n2 / 2; j++)
		printf(" ");
	printf("%c%c\n", a, b[2]);  //│ 출력

								//하단 출력
	for (j = 0; j < 6; j++)
		printf(" ");
	printf("%c%c", a, b[6]);   // └출력
	for (i = 0; i < c; i++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");
}



//라희와 아이들 광고판 상단 출력
void show_title(int c, int r)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);   //┌ 출력
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);   // ─ 출력

	printf("%c%c", a, b[4]);   // ┐출력

	printf("\n");
	for (i = 0; i < r; i++)   //│ 출력
	{
		for (j = 0; j < 6; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		for (j = 0; j < 11; j++)
			printf("  ");
		printf("★라희와 아이들 영화관★");
		for (j = 0; j < 10; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
}


//카드정보 저장
void GetCardInfo(CardInfo *card)
{
	gotoxy(26, 14);
	printf("카드번호 : ");
	scanf("%s", card->number);
	gotoxy(26, 17);
	printf("유효기간 : ");
	scanf("%s", card->period);
	gotoxy(26, 20);
	printf("비밀번호 :   **");
	gotoxy(37, 20);
	scanf("%d", &card->password);
	gotoxy(26, 23);
	printf("법정생일 : ");
	scanf("%d", &card->birth);
	move_figure();
}

//결제중 표시 함수
void move_figure()
{
	gotoxy(33, 5);
	printf("▶　　");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(33, 5);
	printf("　▶　");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(33, 5);
	printf("　　▶");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(32, 5);
	printf("　　　");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("▶　　");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("　▶　");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("　　▶");
	gotoxy(1, 33);
	Sleep(300);
}

//띄어쓰기 계산한 다음 직사각형 출력하는 함수
void draw_rectangle2(int c, int r, int width)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	width = width - 1;   //필요한 빈공간 계산

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);   //┌ 출력
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	for (i = 0; i < r; i++)   //│ 출력
	{
		for (j = 0; j < width; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	for (j = 0; j < width; j++)  //빈공간이 필요한만큼 출력
		printf(" ");
	printf("%c%c", a, b[6]);   // └출력
	for (i = 0; i < c; i++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //│ 출력
	printf("\n");
}

//좌석 출력  (
void ShowSeat(int arr[][14], int row, int col)
{
	int i, j;

	//기존에 메뉴를 선택하기 위해서 화면의 값이 바뀌었으므로 다시 원상태로 돌린다.
	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 9);  //좌석표를 감쌀 직사각형 시작점으로 가서
	draw_rectangle2(33, 18, 7);  //직사각형 출력

	gotoxy(38, 12);  //스크린 표시
	printf("%s", m_screen);

	for (i = 0; i < row; i++)
	{
		gotoxy(17, 15 + i);
		for (j = 0; j < 4; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("□ ");
			else if (arr[i][j] == 15)
				printf("■ ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);

			else
				printf(" %d ", arr[i][j]);
		printf("   ");

		for (j = 4; j < 11; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("□ ");
			else if (arr[i][j] == 15)
				printf("■ ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);
			else
				printf(" %d ", arr[i][j]);
		printf("   ");

		for (j = 11; j < 14; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("□ ");
			else if (arr[i][j] == 15)
				printf("■ ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);
			else
				printf("%d ", arr[i][j]);
		printf("\n\n");
	}
}

//기능 선택하는 함수들
void choose_menu00(HANDLE *x, PPL *p)
{
	char key = NULL;

	gotoxy(11, 8);
	printf("        ");    //미이라 지우기
	gotoxy(11, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<미이라>");
	key = getch();


	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(11, 8);
		printf("        ");
		gotoxy(11, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<미이라>");
		choose_menu30(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(11, 8);
		printf("        ");
		gotoxy(11, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<미이라>");
		choose_menu01(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "미이라");
		choose_menu00(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu00(x, p);
		break;
	}
}

void choose_menu01(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(38, 8);
	printf("          ");    //원더우먼 지우기
	gotoxy(38, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<원더우먼>");

	key = getch();

	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(38, 8);
		printf("          ");    //원더우먼 지우기
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<원더우먼>");
		choose_menu31(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(38, 8);
		printf("          ");    //원더우먼 지우기
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<원더우먼>");
		choose_menu00(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(38, 8);
		printf("          ");    //원더우먼 지우기
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<원더우먼>");
		choose_menu02(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "원더우먼");
		choose_menu01(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu01(x, p);
		break;
	}
}

void choose_menu02(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(67, 8);
	printf("        ");    //겟아웃 지우기
	gotoxy(67, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<대립군>");

	key = getch();

	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(67, 8);
		printf("        ");
		gotoxy(67, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<대립군>");
		choose_menu32(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(67, 8);
		printf("        ");
		gotoxy(67, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<대립군>");
		choose_menu01(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "대립군");
		choose_menu02(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu02(x, p);
		break;
	}
}

void choose_menu10(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(7, 10);
	printf("                 ");    //미이라 1회 지우기
	gotoxy(7, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1회 : 11:00~12:50");

	key = getch();

	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(7, 10);
		printf("                 ");
		gotoxy(7, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 11:00~12:50");
		choose_menu20(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "미이라");
		p->time = 1;
		ShowSeat(seat1_1, 10, 14);
		break;
	case 8:
		gotoxy(7, 10);
		printf("                 ");
		gotoxy(7, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 11:00~12:50");
		choose_menu30(x, p);
		break;
	default:
		choose_menu10(x, p);
		break;
	}
}

void choose_menu11(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(35, 10);
	printf("                 ");    //불한당 1회 지우기
	gotoxy(35, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1회 : 10:40~12:40");

	key = getch();

	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(35, 10);
		printf("                 ");
		gotoxy(35, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 10:40~12:40");
		choose_menu21(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "원더우먼");
		p->time = 1;
		ShowSeat(seat2_1, 10, 14);
		break;
	case 8:
		gotoxy(35, 10);
		printf("                 ");
		gotoxy(35, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 10:40~12:40");
		choose_menu31(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu11(x, p);
		break;
	}
}

void choose_menu12(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(63, 10);
	printf("                 ");    //겟아웃 1회 지우기
	gotoxy(63, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1회 : 13:10~14:54");

	key = getch();

	switch (key)
	{
	case 80://아래쪽 화살표
		gotoxy(63, 10);
		printf("                 ");
		gotoxy(63, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 13:10~14:54");
		choose_menu22(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "대립군");
		p->time = 1;
		ShowSeat(seat3_1, 10, 14);
		break;
	case 8:
		gotoxy(63, 10);
		printf("                 ");
		gotoxy(63, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1회 : 13:10~14:54");
		choose_menu32(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu12(x, p);
		break;
	}
}

void choose_menu20(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(7, 11);
	printf("                 ");    //미이라 2회 지우기
	gotoxy(7, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2회 : 14:30~15:20");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(7, 11);
		printf("                 ");
		gotoxy(7, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 14:30~15:20");
		choose_menu10(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "미이라");
		p->time = 2;
		ShowSeat(seat1_2, 10, 14);
		break;
	case 8:
		gotoxy(7, 11);
		printf("                 ");
		gotoxy(7, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 14:30~15:20");
		choose_menu30(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu20(x, p);
		break;
	}
}

void choose_menu21(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(35, 11);
	printf("                 ");    //불한당 2회 지우기
	gotoxy(35, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2회 : 13:15~15:15");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(35, 11);
		printf("                 ");
		gotoxy(35, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 13:15~15:15");
		choose_menu11(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "원더우먼");
		p->time = 2;
		ShowSeat(seat2_2, 10, 14);
		break;
	case 8:
		gotoxy(35, 11);
		printf("                 ");
		gotoxy(35, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 13:15~15:15");
		choose_menu31(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu21(x, p);
		break;
	}

}

void choose_menu22(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(63, 11);
	printf("                 ");    //겟아웃 2회 지우기
	gotoxy(63, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2회 : 17:00~18:44");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(63, 11);
		printf("                 ");
		gotoxy(63, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 17:00~18:44");
		choose_menu12(x, p);
		break;
	case 13://엔터
		strcpy(p->moivename, "대립군");
		p->time = 2;
		ShowSeat(seat3_2, 10, 14);
		break;
	case 8:
		gotoxy(63, 11);
		printf("                 ");
		gotoxy(63, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2회 : 17:00~18:44");
		choose_menu32(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu22(x, p);
		break;
	}
}

void choose_menu30(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(11, 15);
	printf("        ");    //미이라 좌석 지우기
	gotoxy(10, 15);
	SetConsoleTextAttribute(x, 112);
	printf("▶영화예매");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu00(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu40(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu31(x, p);
		break;
	case 13://엔터
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu10(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu30(x, p);
		break;
	}
}

void choose_menu31(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(39, 15);
	printf("        ");    //불한당 좌석 지우기
	gotoxy(38, 15);
	SetConsoleTextAttribute(x, 112);
	printf("▶영화예매");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu01(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu41(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu30(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu32(x, p);
		break;
	case 13://엔터
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu11(x, p);
		break;

	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu31(x, p);
		break;
	}
}

void choose_menu32(HANDLE *x, PPL *p)
{
	char key;

	gotoxy(67, 15);
	printf("        ");    //겟아웃 좌석 지우기
	gotoxy(66, 15);
	SetConsoleTextAttribute(x, 112);
	printf("▶영화예매");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu02(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu42(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu31(x, p);
		break;
	case 13://엔터
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("▶영화예매");
		choose_menu12(x, p);
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu32(x, p);
		break;
	}
}

void choose_menu40(HANDLE *x, PPL *p)
{
	char key;
	int rrre = 0;

	gotoxy(11, 16);
	printf("        ");    //미이라 리뷰 지우기
	gotoxy(10, 16);
	SetConsoleTextAttribute(x, 112);
	printf("▶리뷰보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu30(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu50(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu41(x, p);
		break;
	case 13://엔터
		rrre = m_review01(35, 20);  //미이라 리뷰
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu40(x, p);
		break;
	}
}

void choose_menu41(HANDLE *x, PPL *p)
{
	char key;
	int rrre = 0;

	gotoxy(39, 16);
	printf("        ");    //불한당 리뷰 지우기
	gotoxy(38, 16);
	SetConsoleTextAttribute(x, 112);
	printf("▶리뷰보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu31(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu51(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu40(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu42(x, p);
		break;
	case 13://엔터
		rrre = m_review02(35, 20);  //원더우먼 리뷰보기
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu41(x, p);
		break;
	}

}

void choose_menu42(HANDLE *x, PPL *p)
{
	char key;
	int rrre = 0;

	gotoxy(67, 16);
	printf("         ");    //겟아웃 리뷰 지우기
	gotoxy(66, 16);
	SetConsoleTextAttribute(x, 112);
	printf("▶리뷰보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu32(x, p);
		break;
	case 80://아래쪽 화살표
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu52(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("▶리뷰보기");
		choose_menu41(x, p);
		break;
	case 13://엔터
		rrre = m_review03(35, 20);  //대립군 리뷰보기
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu42(x, p);
		break;
	}
}

void choose_menu50(HANDLE *x, PPL *p)
{
	char key;
	int rvw;

	gotoxy(10, 17);
	printf("          ");    //미이라 줄거리 지우기
	gotoxy(9, 17);
	SetConsoleTextAttribute(x, 112);
	printf("▶줄거리보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(9, 17);
		printf("          ");
		gotoxy(9, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu40(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(9, 17);
		printf("          ");
		gotoxy(9, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu51(x, p);
		break;
	case 13://엔터
		rvw = m_story01(35, 20);
		//미이라 줄거리 보여주기
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu50(x, p);
		break;
	}
}

void choose_menu51(HANDLE *x, PPL *p)
{
	char key;
	int rvw;

	gotoxy(38, 17);
	printf("          ");    //불한당 줄거리 지우기
	gotoxy(37, 17);
	SetConsoleTextAttribute(x, 112);
	printf("▶줄거리보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu41(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu50(x, p);
		break;
	case 77://오른쪽 화살표
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu52(x, p);
		break;
	case 13: //엔터
		rvw = m_story02(35, 20); //불한당 줄거리 보여주기
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu51(x, p);
		break;
	}
}

void choose_menu52(HANDLE *x, PPL *p)
{
	char key;
	int rvw;

	gotoxy(66, 17);
	printf("          ");    //겟아웃 줄거리 지우기
	gotoxy(65, 17);
	SetConsoleTextAttribute(x, 112);
	printf("▶줄거리보기");

	key = getch();

	switch (key)
	{
	case 72: //위쪽 화살표
		gotoxy(65, 17);
		printf("          ");
		gotoxy(65, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu42(x, p);
		break;
	case 75://왼쪽 화살표
		gotoxy(65, 17);
		printf("          ");
		gotoxy(65, 17);
		SetConsoleTextAttribute(x, 7);
		printf("▶줄거리보기");
		choose_menu51(x, p);
		break;
	case 13://엔터
		rvw = m_story03(35, 20);//겟아웃 줄거리 보여주기
		break;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_menu52(x, p);
		break;
	}
}

int* check_movie(PPL *p)
{
	int cmp_time, cmp_name = 0, i;

	cmp_time = p->time;
	if (strcmp(("미이라"), p->moivename) == 0)
		cmp_name = 1;
	else if (strcmp(("원더우먼"), p->moivename) == 0)
		cmp_name = 3;
	else if (strcmp(("대립군"), p->moivename) == 0)
		cmp_name = 5;

	if (cmp_time*cmp_name == 1)
		return seat1_1;
	else if (cmp_time*cmp_name == 2)
		return seat1_2;
	else if (cmp_time*cmp_name == 3)
		return seat2_1;
	else if (cmp_time*cmp_name == 6)
		return seat2_2;
	else if (cmp_time*cmp_name == 5)
		return seat3_1;
	else if (cmp_time*cmp_name == 10)
		return seat3_2;
}


//리뷰출력
int m_review01(int c, int r)
{     //c : 직사각형 너비 / r : 직사각형 열 / m : 행 / n: 열

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, rev1);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("review01.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//한 줄 개행
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력
	gotoxy(6, 11);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력

							//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i < 16; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 12 + i);
		printf("%c%c", a, b[2]);
		printf("  ");
		printf("%s", buf);

		gotoxy(77, 12 + i);
		printf(" %c%c", a, b[2]);
	}

	for (y = 0; y < 2; y++)
	{
		gotoxy(6, 28 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu40(colorrr, &P1);
			break;
		}
	}

	return 0;
}

int m_review02(int c, int r)
{     //c : 직사각형 너비 / r : 직사각형 열 / m : 행 / n: 열

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, rev2);

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("review02.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//한 줄 개행
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력
	gotoxy(6, 11);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력

							//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i< 16; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 12 + i);
		printf("%c%c", a, b[2]);
		printf("  ");
		printf("%s", buf);

		gotoxy(77, 12 + i);
		printf(" %c%c", a, b[2]);
	}

	for (y = 0; y < 2; y++)
	{
		gotoxy(6, 28 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu41(colorrr, &P1);
			break;
		}
	}

	return 0;
}

int m_review03(int c, int r)
{     //c : 직사각형 너비 / r : 직사각형 열 / m : 행 / n: 열

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, rev3);

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("review03.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//한 줄 개행
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력

							//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i< 16; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 11 + i);
		printf("%c%c", a, b[2]);
		printf("  ");
		printf("%s", buf);

		gotoxy(77, 11 + i);
		printf(" %c%c", a, b[2]);
	}

	for (y = 0; y < 3; y++)
	{
		gotoxy(6, 27 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu42(colorrr, &P1);
			break;
		}
	}

	return 0;
}

//줄거리 출력
int m_story01(int c, int r)
{
	//c : 직사각형 너비 / r : 직사각형 열

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, summ1);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("story01.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//한 줄 개행
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//│ 출력
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//│ 출력

							//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i< 17; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 11 + i);
		printf("%c%c", a, b[2]);
		length = (c * 2 - strlen(buf)) / 2;
		if ((length % 2) == 0)
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 11 + i);
			printf(" %c%c", a, b[2]);
		}
		else
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 11 + i);
			printf(" %c%c", a, b[2]);
		}
	}

	for (y = 0; y < 2; y++)
	{
		gotoxy(6, 28 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu51(colorrr, &P1);
			break;
		}
	}

	return 0;
}

int m_story02(int c, int r)
{
	//c : 직사각형 너비 / r : 직사각형 열

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, summ2);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("story02.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//4줄 개행
	for (y = 0; y < 4; y++)
	{
		gotoxy(6, 10 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}


	//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i< 11; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 14 + i);
		printf("%c%c", a, b[2]);
		length = (c * 2 - strlen(buf)) / 2;
		if ((length % 2) == 0)
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 14 + i);
			printf(" %c%c", a, b[2]);
		}
		else
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 14 + i);
			printf(" %c%c", a, b[2]);
		}
	}

	for (y = 0; y < 5; y++)
	{
		gotoxy(6, 25 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu51(colorrr, &P1);
			break;
		}
	}

	return 0;
}

int m_story03(int c, int r)
{
	//c : 직사각형 너비 / r : 직사각형 열 / m : 행 / n: 열

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //우선 전체화면 지우고
	system("color 07");  //검정배경에 회색 글씨로
	gotoxy(7, 2);
	show_box(33, 1, summ3);

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	for (x = 1; x < 7; x++)
		b[x] = 0xa0 + x;

	FILE *fp = fopen("story03.txt", "r");

	if (fp == NULL)
	{
		printf("not open");
		return 1;
	}

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //┌ 출력
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // ─ 출력
	printf("%c%c", a, b[4]);   // ┐출력
	printf("\n");

	//3줄 개행
	for (y = 0; y < 3; y++)
	{
		gotoxy(6, 10 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}


	//줄 수만큼 문장 출력 (띄어쓰기 자동 계산)
	for (i = 0; i< 12; i++)
	{
		if (fgets(buf, sizeof(buf), fp) == NULL)
			break;
		gotoxy(6, 13 + i);
		printf("%c%c", a, b[2]);
		length = (c * 2 - strlen(buf)) / 2;
		if ((length % 2) == 0)
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 13 + i);
			printf(" %c%c", a, b[2]);
		}
		else
		{
			for (y = 0; y < length; y++)
				printf(" ");
			printf("%s", buf);
			for (y = 0; y < length; y++)
				printf(" ");
			gotoxy(77, 13 + i);
			printf(" %c%c", a, b[2]);
		}
	}

	for (y = 0; y < 5; y++)
	{
		gotoxy(6, 25 + y);
		printf("%c%c", a, b[2]);//│ 출력
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//│ 출력
	}

	//하단 출력
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // └출력
	for (x = 0; x < c; x++)    //─ 출력
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  ┘출력
	printf("\n      ");

	state = fclose(fp);
	if (state != 0)
	{
		printf("not close");
		return 1;
	}

	while (1)
	{
		key = getch();

		if (key == 8)
		{
			system("cls");
			gotoxy(7, 2);  //처음화면
			show_intro(33, 1);  //광고판 출력
			for (i = 0; i < 3; i++)  //영화 차트를 보여준다.
			{
				gotoxy(1 + 28 * i, 5);
				show_movie(12, 18, i, 1 + 28 * i);
			}
			choose_menu52(colorrr, &P1);
			break;
		}
	}

	return 0;
}



void checkcheck()
{
	int i;
	gotoxy(78, 22);
	printf("▶모든 좌석 예약이 완료되었습니다◀\n");
	gotoxy(78, 23);

	for (i = 0; i < P1.total; i++) {
		printf("%c", P1.seat_alpha[i]);
		printf("%d | ", P1.seat_num[i]);
	}
	Sleep(2000);

}

void black_seat(int arr[][14], char alphabet, int num)
{
	//***********************A**************************
	if (alphabet == 'A')
	{
		if (num == 1)
		{
			arr[1][1] = 15;
			gotoxy(20, 16);
			printf("■");
		}
		else if (num == 2)
		{
			arr[1][2] = 15;
			gotoxy(23, 16);
			printf("■");
		}
		else if (num == 3)
		{
			arr[1][3] = 15;
			gotoxy(26, 16);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[1][4] = 15;
			gotoxy(32, 16);
			printf("■");
		}
		else if (num == 5)
		{
			arr[1][5] = 15;
			gotoxy(35, 16);
			printf("■");
		}
		else if (num == 6)
		{
			arr[1][6] = 15;
			gotoxy(38, 16);
			printf("■");
		}
		else if (num == 7)
		{
			arr[1][7] = 15;
			gotoxy(41, 16);
			printf("■");
		}
		else if (num == 8)
		{
			arr[1][8] = 15;
			gotoxy(44, 16);
			printf("■");
		}
		else if (num == 9)
		{
			arr[1][9] = 15;
			gotoxy(47, 16);
			printf("■");
		}
		else if (num == 10)
		{
			arr[1][10] = 15;
			gotoxy(50, 16);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[1][11] = 15;
			gotoxy(56, 16);
			printf("■");
		}
		else if (num == 12)
		{
			arr[1][12] = 15;
			gotoxy(59, 16);
			printf("■");
		}
		else if (num == 13)
		{
			arr[1][3] = 15;
			gotoxy(62, 16);
			printf("■");
		}
	}
	//***********************B**************************
	else if (alphabet == 'B')
	{
		if (num == 1)
		{
			arr[2][1] = 15;
			gotoxy(20, 17);
			printf("■");
		}
		else if (num == 2)
		{
			arr[2][2] = 15;
			gotoxy(23, 17);
			printf("■");
		}
		else if (num == 3)
		{
			arr[2][3] = 15;
			gotoxy(26, 17);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[2][4] = 15;
			gotoxy(32, 17);
			printf("■");
		}
		else if (num == 5)
		{
			arr[2][5] = 15;
			gotoxy(35, 17);
			printf("■");
		}
		else if (num == 6)
		{
			arr[2][6] = 15;
			gotoxy(38, 17);
			printf("■");
		}
		else if (num == 7)
		{
			arr[2][7] = 15;
			gotoxy(41, 17);
			printf("■");
		}
		else if (num == 8)
		{
			arr[2][8] = 15;
			gotoxy(44, 17);
			printf("■");
		}
		else if (num == 9)
		{
			arr[2][9] = 15;
			gotoxy(47, 17);
			printf("■");
		}
		else if (num == 10)
		{
			arr[2][10] = 15;
			gotoxy(50, 17);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[2][11] = 15;
			gotoxy(56, 17);
			printf("■");
		}
		else if (num == 12)
		{
			arr[2][12] = 15;
			gotoxy(59, 17);
			printf("■");
		}
		else if (num == 13)
		{
			arr[2][13] = 15;
			gotoxy(62, 17);
			printf("■");
		}
	}
	//***********************C**************************
	else if (alphabet == 'C')
	{
		if (num == 1)
		{
			arr[3][1] = 15;
			gotoxy(20, 18);
			printf("■");
		}
		else if (num == 2)
		{
			arr[3][2] = 15;
			gotoxy(23, 18);
			printf("■");
		}
		else if (num == 3)
		{
			arr[3][3] = 15;
			gotoxy(26, 18);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[3][4] = 15;
			gotoxy(32, 18);
			printf("■");
		}
		else if (num == 5)
		{
			arr[3][5] = 15;
			gotoxy(35, 18);
			printf("■");
		}
		else if (num == 6)
		{
			arr[3][6] = 15;
			gotoxy(38, 18);
			printf("■");
		}
		else if (num == 7)
		{
			arr[3][7] = 15;
			gotoxy(41, 18);
			printf("■");
		}
		else if (num == 8)
		{
			arr[3][8] = 15;
			gotoxy(44, 18);
			printf("■");
		}
		else if (num == 9)
		{
			arr[3][9] = 15;
			gotoxy(47, 18);
			printf("■");
		}
		else if (num == 10)
		{
			arr[3][10] = 15;
			gotoxy(50, 18);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[3][11] = 15;
			gotoxy(56, 18);
			printf("■");
		}
		else if (num == 12)
		{
			arr[3][12] = 15;
			gotoxy(59, 18);
			printf("■");
		}
		else if (num == 13)
		{
			arr[3][13] = 15;
			gotoxy(62, 18);
			printf("■");
		}
	}
	//***********************D**************************
	else if (alphabet == 'D')
	{
		if (num == 1)
		{
			arr[4][1] = 15;
			gotoxy(20, 19);
			printf("■");
		}
		else if (num == 2)
		{
			arr[4][2] = 15;
			gotoxy(23, 19);
			printf("■");
		}
		else if (num == 3)
		{
			arr[4][3] = 15;
			gotoxy(26, 19);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[4][4] = 15;
			gotoxy(32, 19);
			printf("■");
		}
		else if (num == 5)
		{
			arr[4][5] = 15;
			gotoxy(35, 19);
			printf("■");
		}
		else if (num == 6)
		{
			arr[4][6] = 15;
			gotoxy(38, 19);
			printf("■");
		}
		else if (num == 7)
		{
			arr[4][7] = 15;
			gotoxy(41, 19);
			printf("■");
		}
		else if (num == 8)
		{
			arr[4][8] = 15;
			gotoxy(44, 19);
			printf("■");
		}
		else if (num == 9)
		{
			arr[4][9] = 15;
			gotoxy(47, 19);
			printf("■");
		}
		else if (num == 10)
		{
			arr[4][10] = 15;
			gotoxy(50, 19);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[4][11] = 15;
			gotoxy(56, 19);
			printf("■");
		}
		else if (num == 12)
		{
			arr[4][12] = 15;
			gotoxy(59, 19);
			printf("■");
		}
		else if (num == 13)
		{
			arr[4][13] = 15;
			gotoxy(62, 19);
			printf("■");
		}
	}
	//***********************E**************************
	else if (alphabet == 'E')
	{
		if (num == 1)
		{
			arr[5][1] = 15;
			gotoxy(20, 20);
			printf("■");
		}
		else if (num == 2)
		{
			arr[5][2] = 15;
			gotoxy(23, 20);
			printf("■");
		}
		else if (num == 3)
		{
			arr[5][3] = 15;
			gotoxy(26, 20);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[5][4] = 15;
			gotoxy(32, 20);
			printf("■");
		}
		else if (num == 5)
		{
			arr[5][5] = 15;
			gotoxy(35, 20);
			printf("■");
		}
		else if (num == 6)
		{
			arr[5][6] = 15;
			gotoxy(38, 20);
			printf("■");
		}
		else if (num == 7)
		{
			arr[5][7] = 15;
			gotoxy(41, 20);
			printf("■");
		}
		else if (num == 8)
		{
			arr[5][8] = 15;
			gotoxy(44, 20);
			printf("■");
		}
		else if (num == 9)
		{
			arr[5][9] = 15;
			gotoxy(47, 20);
			printf("■");
		}
		else if (num == 10)
		{
			arr[5][10] = 15;
			gotoxy(50, 20);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[5][11] = 15;
			gotoxy(56, 20);
			printf("■");
		}
		else if (num == 12)
		{
			arr[5][12] = 15;
			gotoxy(59, 20);
			printf("■");
		}
		else if (num == 13)
		{
			arr[5][13] = 15;
			gotoxy(62, 20);
			printf("■");
		}
	}
	//***********************F**************************
	else if (alphabet == 'F')
	{
		if (num == 1)
		{
			arr[6][1] = 15;
			gotoxy(20, 21);
			printf("■");
		}
		else if (num == 2)
		{
			arr[6][2] = 15;
			gotoxy(23, 21);
			printf("■");
		}
		else if (num == 3)
		{
			arr[6][3] = 15;
			gotoxy(26, 21);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[6][4] = 15;
			gotoxy(32, 21);
			printf("■");
		}
		else if (num == 5)
		{
			arr[6][5] = 15;
			gotoxy(35, 21);
			printf("■");
		}
		else if (num == 6)
		{
			arr[6][6] = 15;
			gotoxy(38, 21);
			printf("■");
		}
		else if (num == 7)
		{
			arr[6][7] = 15;
			gotoxy(41, 21);
			printf("■");
		}
		else if (num == 8)
		{
			arr[6][8] = 15;
			gotoxy(44, 21);
			printf("■");
		}
		else if (num == 9)
		{
			arr[6][9] = 15;
			gotoxy(47, 21);
			printf("■");
		}
		else if (num == 10)
		{
			arr[6][10] = 15;
			gotoxy(50, 21);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[6][11] = 15;
			gotoxy(56, 21);
			printf("■");
		}
		else if (num == 12)
		{
			arr[6][12] = 15;
			gotoxy(59, 21);
			printf("■");
		}
		else if (num == 13)
		{
			arr[6][13] = 15;
			gotoxy(62, 21);
			printf("■");
		}
	}
	//***********************G**************************
	else if (alphabet == 'G')
	{
		if (num == 1)
		{
			arr[7][1] = 15;
			gotoxy(20, 22);
			printf("■");
		}
		else if (num == 2)
		{
			arr[7][2] = 15;
			gotoxy(23, 22);
			printf("■");
		}
		else if (num == 3)
		{
			arr[7][3] = 15;
			gotoxy(26, 22);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[7][4] = 15;
			gotoxy(32, 22);
			printf("■");
		}
		else if (num == 5)
		{
			arr[7][5] = 15;
			gotoxy(35, 22);
			printf("■");
		}
		else if (num == 6)
		{
			arr[7][6] = 15;
			gotoxy(38, 22);
			printf("■");
		}
		else if (num == 7)
		{
			arr[7][7] = 15;
			gotoxy(41, 22);
			printf("■");
		}
		else if (num == 8)
		{
			arr[7][8] = 15;
			gotoxy(44, 22);
			printf("■");
		}
		else if (num == 9)
		{
			arr[7][9] = 15;
			gotoxy(47, 22);
			printf("■");
		}
		else if (num == 10)
		{
			arr[7][10] = 15;
			gotoxy(50, 22);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[7][11] = 15;
			gotoxy(56, 22);
			printf("■");
		}
		else if (num == 12)
		{
			arr[7][12] = 15;
			gotoxy(59, 22);
			printf("■");
		}
		else if (num == 13)
		{
			arr[7][13] = 15;
			gotoxy(62, 22);
			printf("■");
		}
	}
	//***********************H**************************
	else if (alphabet == 'H')
	{
		if (num == 1)
		{
			arr[8][1] = 15;
			gotoxy(20, 23);
			printf("■");
		}
		else if (num == 2)
		{
			arr[8][2] = 15;
			gotoxy(23, 23);
			printf("■");
		}
		else if (num == 3)
		{
			arr[8][3] = 15;
			gotoxy(26, 23);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[8][4] = 15;
			gotoxy(32, 23);
			printf("■");
		}
		else if (num == 5)
		{
			arr[8][5] = 15;
			gotoxy(35, 23);
			printf("■");
		}
		else if (num == 6)
		{
			arr[8][6] = 15;
			gotoxy(38, 23);
			printf("■");
		}
		else if (num == 7)
		{
			arr[8][7] = 15;
			gotoxy(41, 23);
			printf("■");
		}
		else if (num == 8)
		{
			arr[8][8] = 15;
			gotoxy(44, 23);
			printf("■");
		}
		else if (num == 9)
		{
			arr[8][9] = 15;
			gotoxy(47, 23);
			printf("■");
		}
		else if (num == 10)
		{
			arr[8][10] = 15;
			gotoxy(50, 23);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[8][11] = 15;
			gotoxy(56, 23);
			printf("■");
		}
		else if (num == 12)
		{
			arr[8][12] = 15;
			gotoxy(59, 23);
			printf("■");
		}
		else if (num == 13)
		{
			arr[8][13] = 15;
			gotoxy(62, 23);
			printf("■");
		}
	}
	//***********************I**************************
	else if (alphabet == 'I')
	{
		if (num == 1)
		{
			arr[9][1] = 15;
			gotoxy(20, 24);
			printf("■");
		}
		else if (num == 2)
		{
			arr[9][2] = 15;
			gotoxy(23, 24);
			printf("■");
		}
		else if (num == 3)
		{
			arr[9][3] = 15;
			gotoxy(26, 24);
			printf("■");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[9][4] = 15;
			gotoxy(32, 24);
			printf("■");
		}
		else if (num == 5)
		{
			arr[9][5] = 15;
			gotoxy(35, 24);
			printf("■");
		}
		else if (num == 6)
		{
			arr[9][6] = 15;
			gotoxy(38, 24);
			printf("■");
		}
		else if (num == 7)
		{
			arr[9][7] = 15;
			gotoxy(41, 24);
			printf("■");
		}
		else if (num == 8)
		{
			arr[9][8] = 15;
			gotoxy(44, 24);
			printf("■");
		}
		else if (num == 9)
		{
			arr[9][9] = 15;
			gotoxy(47, 24);
			printf("■");
		}
		else if (num == 10)
		{
			arr[9][10] = 15;
			gotoxy(50, 24);
			printf("■");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[9][11] = 15;
			gotoxy(56, 24);
			printf("■");
		}
		else if (num == 12)
		{
			arr[9][12] = 15;
			gotoxy(59, 24);
			printf("■");
		}
		else if (num == 13)
		{
			arr[9][13] = 15;
			gotoxy(62, 24);
			printf("■");
		}
	}
}


//한별 함수 정의
void PayMoney(int point)
{
	CardInfo card;
	system("color 07");

	P1.money = P1.money - point;

	system("cls");
	gotoxy(7, 2);
	show_intro(33, 1);
	gotoxy(15, 7);
	draw_rectangle2(25, 20, 15);

	gotoxy(26, 11);
	printf("결제금액 : %d", P1.money);

	gotoxy(7, 2);
	show_box(33, 1, m_pay1);
	GetCardInfo(&card);

	system("cls");
	gotoxy(7, 2);
	show_intro(33, 1);
	gotoxy(15, 7);
	draw_rectangle2(25, 20, 15);
	gotoxy(18, 15);
	printf("☆*..::..*☆..::..*☆..::..*☆..::..*☆..::..*☆");
	gotoxy(32, 17);
	printf("결제가 완료되었습니다 !");
	gotoxy(18, 19);
	printf("☆*..::..*☆..::..*☆..::..*☆..::..*☆..::..*☆");
	Sleep(2000);
	system("cls");

	bill_print();
}

void ismember(members *a)      // 멤버십 가입 여부 확인
{
	int yorn, k;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	gotoxy(7, 9);
	draw_rectangle2(33, 18, 7);
	gotoxy(7, 2);
	show_box(33, 1, m_mem);

	yorn = choose_answer01(hC);
	system("cls");
	system("color 07");
	gotoxy(7, 2);
	show_intro(33, 1);
	gotoxy(7, 9);
	draw_rectangle2(33, 18, 7);

	if (yorn == 1)      //만약 가입이 되어있다면
		member(a);      //번호로 확인.

	if (yorn == 2)      //가입이 안되어있다면
	{
		k = question();      //가입할건지 물어보고
		if (k == 1)
			input_member(a);   //yes면 가입
		if (k == 2)
			PayMoney(0);      //no면 결제
	}
}

void Getpoint(members* a, int x)
{
	a->point = a->point + x*0.05;
}

void member(members* a)
{
	int i, k, check = 0, tmp=0;
	int phonenum;

	gotoxy(18, 13);
	printf("핸드폰번호 뒷자리 4 개 번호를 입력해주세요 : ");
	scanf("%d", &phonenum);

	for (i = 0; i < CUSTOMER_MAX; i++) 
	{
		if (a[i].number == phonenum) {
			gotoxy(18, 18);
			printf("고객 확인이 완료되었습니다.");
			Sleep(2000);
			gotoxy(18, 13);
			printf("                                                    ");
			gotoxy(18, 18);
			printf("                                 ");

			tmp = P1.money;
			PayMoney(usingpoint(&a[i]));
			Getpoint(&a[i], tmp);
			check = 1;
		}
	}
	if (check == 0)
	{
		gotoxy(30, 19);
		printf("존재 하지 않는 회원입니다.");
		Sleep(1000);
		gotoxy(30, 19);
		printf("                                ");
		gotoxy(18, 13);
		printf("                                                        ");
		switch (question())
		{
		case 1:
			input_member(a);
			break;
		case 2:
			PayMoney(0);
			break;
		}
	}
	system("cls");

	gotoxy(7, 2);  //처음화면
	show_intro(33, 1);
	gotoxy(7, 9);
	draw_rectangle2(33, 18, 7);
}

int question()
{
	int answer;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	while (1) {
		gotoxy(7, 2);
		show_box(33, 1, m_join);
		answer = choose_answer03(hC);

		if (answer == 1 || answer == 2)
		{
			system("color 07");
			return answer;
		}
		else
			printf("잘 못 입력하셨습니다. 다시 입력해주세요.\n");
	}
}

void input_member(members* a)
{
	if (count <= CUSTOMER_MAX)
	{
		system("color 07");
		gotoxy(18, 13);
		printf("이름을 입력하세요 : ");
		scanf("%s", &a[count].name);
		gotoxy(18, 15);
		printf("핸드폰번호 뒷자리 4 개 번호를 입력하세요 : ");
		scanf("%d", &a[count].number);
		a[count].point = 0;

		gotoxy(35, 23);
		printf("축하합니다 !");
		Sleep(1000);

		gotoxy(30, 25);
		printf("가입이 완료되었습니다 !\n");
		Sleep(1000);

		Getpoint(&a[count], P1.money);
		Sleep(1000);
		PayMoney(0);
		count++;
	}
	else {
		gotoxy(23, 25);
		printf("저장할 수 있는 고객수를 초과하였습니다.");
	}
}

int usingpoint(members* a)
{
	int use, i;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	gotoxy(7, 2);
	show_box(33, 1, m_point);

	i = choose_answer05(hC);

	while (i)
	{
		system("color 07");
		gotoxy(18, 18);
		printf("사용 할 포인트를 입력해주세요.");
		gotoxy(18, 20);
		printf("현재 잔여 포인트(%d point) :    ", a->point);
		gotoxy(48, 20);
		scanf("%d", &use);
		if (use > a->point) {
			gotoxy(18, 24);
			printf("사용 할 포인트가 잔여 포인트보다 많습니다.");
			gotoxy(18, 26);
			printf("다시 입력해주세요.\n");
			Sleep(1000);
			gotoxy(18, 24);
			printf("                                                ");
			gotoxy(18, 26);
			printf("                    ");
		} else {
			a->point = a->point - use;
			gotoxy(18, 22);
			printf("사용한 포인트는 %dp 이고 잔여포인트는 %dp입니다.", use, a->point);
			Sleep(10000);
			return use;
		}
	}
}

void bill_print()
{
	system("cls");
	gotoxy(7, 2);
	show_box(33, 1, m_bill);
	gotoxy(15, 9);
	draw_rectangle2(25, 20, 15);
	//직사각형 도형프린트 하고 그 안에 아래 텍스트 출력
	gotoxy(27, 11);
	printf("*****  영    수    증  *****\n");
	gotoxy(30, 15);
	printf("영화 이름 : %s\n", P1.moivename);
	gotoxy(30, 18);
	printf("고객 수 : %d\n", P1.total);
	gotoxy(30, 21);
	printf("좌석 : ");
	for (int i = 0; i < P1.total; i++)
		printf("%c%d  ", P1.seat_alpha[i], P1.seat_num[i]);
	gotoxy(30, 24);
	printf("가격 : %d\n", P1.money);

	Sleep(3000);
}

int choose_answer01(HANDLE *x)
{
	char key = NULL;

	gotoxy(53, 5);
	printf("    ");    //(1)예 지우기
	gotoxy(53, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)예");
	key = getch();

	switch (key)
	{

	case 77://오른쪽 화살표
		gotoxy(53, 5);
		printf("    ");    //(1)예 지우기
		gotoxy(53, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)예");
		choose_answer02(x);
		break;
	case 13://엔터
		return 1;

	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer01(x);
		break;
	}
}
int choose_answer02(HANDLE *x)
{
	char key = NULL;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	gotoxy(59, 5);
	printf("      ");    //(2)아니오 지우기
	gotoxy(59, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)아니오");
	key = getch();

	switch (key)
	{

	case 75://왼쪽 화살표
		gotoxy(59, 5);
		printf("      ");    //(2)아니오 지우기
		gotoxy(59, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)아니오");
		choose_answer01(hC);
		break;
	case 13://엔터
		return 2;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer02(x);
		break;
	}
}
int choose_answer03(HANDLE *x)
{
	char key = NULL;

	gotoxy(47, 5);
	printf("    ");    //(1)예 지우기
	gotoxy(47, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)예");
	key = getch();

	switch (key)
	{

	case 77://오른쪽 화살표
		gotoxy(47, 5);
		printf("    ");    //(1)예 지우기
		gotoxy(47, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)예");
		choose_answer04(x);
		break;
	case 13://엔터
		return 1;

	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer03(x);
		break;
	}
}
int choose_answer04(HANDLE *x)
{
	char key = NULL;

	gotoxy(54, 5);
	printf("      ");    //(2)아니오 지우기
	gotoxy(54, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)아니오");
	key = getch();

	switch (key)
	{

	case 75://왼쪽 화살표
		gotoxy(54, 5);
		printf("    ");    //(2)아니오 지우기
		gotoxy(54, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)아니오");
		choose_answer03(x);
		break;
	case 13://엔터
		return 2;

	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer04(x);
		break;
	}
}
int choose_answer05(HANDLE *x)
{
	char key = NULL;

	gotoxy(46, 5);
	printf("    ");    //(1)예 지우기
	gotoxy(46, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)예");
	key = getch();

	switch (key)
	{

	case 77://오른쪽 화살표
		gotoxy(46, 5);
		printf("    ");    //(1)예 지우기
		gotoxy(46, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)예");
		choose_answer06(x);
		break;
	case 13://엔터
		return 1;

	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer05(x);
		break;
	}
}
int choose_answer06(HANDLE *x)
{
	char key = NULL;
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hC, &csbi);

	gotoxy(52, 5);
	printf("      ");    //(2)아니오 지우기
	gotoxy(52, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)아니오");
	key = getch();

	switch (key)
	{

	case 75://왼쪽 화살표
		gotoxy(52, 5);
		printf("      ");    //(2)아니오 지우기
		gotoxy(52, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)아니오");
		choose_answer05(hC);
		break;
	case 13://엔터
		return 0;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer06(x);
		break;
	}
}
