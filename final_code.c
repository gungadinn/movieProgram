#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define CUSTOMER_MAX 50

//����� ������ �����ϴ� ����ü
typedef struct PPL {
	char moivename[20];
	char *seat_alpha[150];
	char *seat_num[150];
	int old;
	int adult;
	int young;
	int money; //�����ݾ�
	int total;
	int time;
} PPL;

//������ �� �ʿ��� ī���� ������ �����ϴ� ����ü
typedef struct CardInfo {
	char number[20];
	char period[6];
	int password;
	int birth;
} CardInfo;

//����� ������ �� �ʿ��� �������� �����ϴ� ����ü
typedef struct membership {
	char name[20];
	int number;
	int point;
}members;

//�¼� �迭 (20=���� / 0=��� �׸� / 15=�����׸� / ��Ÿ = ���� ��)
//�� 2���� �迭�� �¼����� ��µȴ�.

//���̶� 1ȸ��
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

//���̶� 2ȸ��
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

//������� 1ȸ��
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

//������� 2ȸ��
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

//�븳�� 1ȸ��
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

//�븳�� 2ȸ��
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

char *m_ppl = { "���� �ο��� �� ���Դϱ�?   ��� :    � :    û�ҳ� :     " };   //ũ�� 58
char *m_calmoney = { "      ���Դϴ�.    ���� �¼��� ����ּ���." };
char *m_ismem = { "����� ���̵� ��ȭ���� ȸ���̽ʴϱ�?   (1)��   (2)�ƴϿ�" };
char *m_pay1 = { "������" };
char *m_pay2 = { "������ �Ϸ�Ǿ����ϴ�." };

char m_name[3][10] = { "���̶�", "�������", "�븳��" };
char m_time1[3][18] = { "1ȸ : 11:00~12:50", "1ȸ : 10:40~12:40", "1ȸ : 13:10~14:54" };
char m_time2[3][18] = { "2ȸ : 14:30~15:20", "2ȸ : 13:15~15:15", "2ȸ : 17:00~18:44" };
char *m_function[3] = { "����ȭ����", "�����亸��", "���ٰŸ�����" };
char *m_screen = { "��ũ��" };

char *rev1 = { " ===���̶� ����===" };
char *rev2 = { " ===������� ����===" };
char *rev3 = { " ===�븳�� ����===" };
char *summ1 = { " ===���̶� �ٰŸ�===" };
char *summ2 = { " ===������� �ٰŸ�===" };
char *summ3 = { " ===�븳�� �ٰŸ�===" };

char *m_mem = { "����� ���̵� ��ȭ���� ȸ���̽ʴϱ�?  (1)�� (2)�ƴϿ� " };
char *m_join = { "����� ������ �Ͻðڽ��ϱ�? (1)��  (2)�ƴϿ�  " };
char* m_point = { "����Ʈ�� ����Ͻðڽ��ϱ�? (1)�� (2)�ƴϿ�  " };
char *m_bill = { "�������� ����ϴ� ���Դϴ�. " };

int count = 0;
int playcount = 0;

void gotoxy(int x, int y);

void show_intro(int c, int r);  //������ �ϴܱ��� �����Ͽ� ����ϴ� �Լ�
void show_movie(int c, int r, int k, int width);  //��ȭ������ ����ϱ� ���� ���Ǵ� �Լ�
void show_data(int c, int r, int k, int column);  //��ȭ������ ����Ѵ�. (show_movie�Լ� �ȿ��� ����ȴ�.)
void show_box(int c, int r, char *sen);  //������ �ؿ� ���ϴ� ������ ���� ��� �ش� ������� ������ִ� �Լ��̴�. �� ���� ������ �ڵ�����ϰ� �Լ��� �������.
void show_title(int c, int r);  //������ ��ܺκ�
void draw_rectangle2(int c, int r, int width);  //���簢�� ����ϴ� �Լ�.
//��ǥ�̵��� �Ͽ� ���簢���� ����� ��� 1���� ���簢���� ��µǴ� ���� ���� ������ ����Ͽ� ����ϰ� �������.
void ShowSeat(int arr[][14], int row, int col);  //�����Լ��� ������ seat 2���� �迭�� �¼����� ����ϰ� �Ѵ�.
void GetCardInfo(CardInfo *card);  //ī�������� �Է¹޴� �Լ�
void move_figure();  //�������̶�� ǥ�ð� �ߵ��� ���� �ִϸ��̼� �Լ�

//ù ȭ�鿡�� �޴��� ���� �� �ʿ��� �Լ����̴�.
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
int* check_movie(PPL *p);  //����ڰ� ��� ��ȭ�� ���� ��� ȸ���� ������ �˾Ƴ� �� �ش� �¼��� ��ȯ�Ѵ�.

//���� ��� �Լ�
int m_review01(int c, int r);
int m_review02(int c, int r);
int m_review03(int c, int r);
//�ٰŸ� ��� �Լ�
int m_story01(int c, int r);
int m_story02(int c, int r);
int m_story03(int c, int r);

void checkcheck();
void black_seat(int arr[][14], char alphabet, int num);

void PayMoney(int point);
void ismember(members* a);      // ����� ���� ���� Ȯ��
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

		//�ܼ�â ���� �ٲٱ� ���ؼ� �ʿ��ϴ�
		HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hC, &csbi);

		//ó��ȭ��
		gotoxy(7, 2);
		show_intro(33, 1);  //������ ���
		for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
		{
			gotoxy(1 + 28 * i, 5);
			show_movie(12, 18, i, 1 + 28 * i);
		}

		//�޴��� �޴´�.
		key = getch();

		if (key == 27)
			break;

		choose_menu00(hC, &P1);

		//���並 ���� �ٰŸ��� ���� �ᱹ�� �¼� ������ �� �ۿ� ������ �Ʒ��� �¼� �Է¹޴� �ڵ带 �д�.
		//�¼� ����ϴ°� ������

		//��� ���� ���
		gotoxy(7, 2);
		show_box(33, 1, m_ppl);

		//�ο��� �Է¹ޱ�
		gotoxy(46, 5);
		scanf("%d", &P1.old);
		gotoxy(56, 5);
		scanf("%d", &P1.adult);
		gotoxy(68, 5);
		scanf("%d", &P1.young);

		//�Է¹��� �ο����� ����� ���� ���� �ݾװ� ���� �ο����� ���Ѵ�.
		P1.money = (4000 * P1.old) + (10000 * P1.adult) + (7000 * P1.young);
		P1.total = P1.old + P1.adult + P1.young;


		//�¼��� �Է¹޴´�.
		gotoxy(78, 10);
		printf("�� %d���� �¼��� �Է����ּ��� ��", P1.total);

		for (i = 0; i < P1.total; i++) // �ο��� ��ŭ
		{
			gotoxy(78, 12);
			printf("���ϴ� �¼��� ���ĺ��� �Է����ּ���\n");//�ο�����ŭ for��
			gotoxy(78, 13);
			printf("����");
			gotoxy(84, 13);
			scanf("%s", &alphabet[i]);

			//���ĺ� �빮�ڰ� �ƴϸ�
			if (alphabet[i] <= 64 || alphabet[i] >= 74)
			{
				while (1)
				{
					gotoxy(86, 13);
					printf("!���ĺ� �빮�ڰ� �ƴմϴ�. �ٽ��Է����ּ���!");
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

			//���ĺ� �빮�ڸ�
			else if (alphabet[i] >= 64 && alphabet[i] <= 74)
				P1.seat_alpha[i] = alphabet[i];


			gotoxy(78, 15);
			printf("���ϴ� �¼��� ���� �Է����ּ���\n");
			gotoxy(78, 16);
			printf("����");
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

		checkcheck();  //�¼��� ����� ���ŵǾ����� Ȯ���Ѵ�.
		system("cls");

		ismember(M); //����� ���� Ȯ��

		gotoxy(1, 33);
		system("cls");
		P1.money = 0;  //�ٽ� money�� �ʱ�ȭ���ش�.
	}
}


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


//��ȭ ������ ���
void show_intro(int c, int r)  //c�� �ʺ�, r�� ����
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	show_title(c, r);

	for (j = 0; j < 6; j++)
		printf(" ");
	printf("%c%c", a, b[6]);   // �����
	for (i = 0; i < c; i++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   // �����
	printf("\n");
}

// ��ȭ����Լ�
void show_movie(int c, int r, int k, int width)     //(c�� �ʺ�, r�� ����)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	//������
	printf("%c%c", a, b[3]);   //�� ���
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);   // �� ���

	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//��� ���
	for (i = 0; i < 2; i++)   //�� ���
	{
		gotoxy(1 + 28 * k, 6 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	show_data(c, r - 2, k, 8);  //��ȭ ��� : 8�� ���� ��ġ

								//�ϴ����
	gotoxy(1 + 28 * k, 5 + r);
	printf("%c%c", a, b[6]);   // �����
	for (i = 0; i < c; i++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   // �����
	printf("\n");
}

//��ȭ ���� ���� ���
void show_data(int c, int r, int k, int column)   //c�� �ʺ�, r�� ����
{
	int i, j, n;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	gotoxy(1 + 28 * k, column);  //���� ��ġ : 8
	printf("%c%c", a, b[2]);//�� ���

							//��ȭ ���
	for (j = 0; j < (c * 2 - strlen(m_name[k]) - 2) / 2; j++)
		printf(" ");
	printf("<%s>", m_name[k]);
	for (j = 0; j < (c * 2 - strlen(m_name[k]) - 2) / 2; j++)
		printf(" ");
	printf("%c%c\n", a, b[2]);  //�� ���

	gotoxy(1 + 28 * k, column + 1);//�� ���
	printf("%c%c", a, b[2]);
	for (j = 0; j < c; j++)
		printf("  ");
	printf("%c%c", a, b[2]);
	printf("\n");


	//�� �Ѿ�� �󿵽ð� ���
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

	//�� ���� �߰����
	for (i = 0; i < 3; i++)   //�� ���
	{
		gotoxy(1 + 28 * k, column + 4 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	//��ɵ� ���
	for (i = 0; i < 3; i++)
	{
		gotoxy(1 + 28 * k, column + 7 + i);   //���� �ٷ� �Ѿ��
		n = strlen(m_function[i]);
		printf("%c%c", a, b[2]);   //�� ���
		for (j = 0; j < (c * 2 - n) / 2; j++)
			printf(" ");
		printf("%s", m_function[i]);
		for (j = 0; j < (c * 2 - n) / 2; j++)
			printf(" ");
		printf("%c%c", a, b[2]);   //�� ���
	}

	//����� ���
	for (i = 0; i < r - 10; i++)   //�� ���
	{
		gotoxy(1 + 28 * k, column + 10 + i);
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
}

//�߰� ���� ��� �κ� (��, ���� ũ��� �� ¦����!!)
void show_box(int c, int r, char *sen)  //c�� �ʺ�, r�� ����
{
	int i, j, n1 = strlen(sen);
	int n2 = c * 2 - n1;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	show_title(c, r); //����� ���̵� ������ ��ܺκ� ���

	for (j = 0; j < 6; j++)
		printf(" ");
	printf("��");   // �����
	for (i = 0; i < c; i++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("��");   // �����
	printf("\n");

	//�� �κп� ���ϴ� ���� ���
	gotoxy(7, 5);  //���� ��ġ : 5
	printf("%c%c", a, b[2]);//�� ���

							//��ȭ ���
	for (j = 0; j < n2 / 2; j++)
		printf(" ");
	printf("%s", sen);
	for (j = 0; j < n2 / 2; j++)
		printf(" ");
	printf("%c%c\n", a, b[2]);  //�� ���

								//�ϴ� ���
	for (j = 0; j < 6; j++)
		printf(" ");
	printf("%c%c", a, b[6]);   // �����
	for (i = 0; i < c; i++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
	printf("\n      ");
}



//����� ���̵� ������ ��� ���
void show_title(int c, int r)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);   //�� ���
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);   // �� ���

	printf("%c%c", a, b[4]);   // �����

	printf("\n");
	for (i = 0; i < r; i++)   //�� ���
	{
		for (j = 0; j < 6; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		for (j = 0; j < 11; j++)
			printf("  ");
		printf("�ڶ���� ���̵� ��ȭ����");
		for (j = 0; j < 10; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
}


//ī������ ����
void GetCardInfo(CardInfo *card)
{
	gotoxy(26, 14);
	printf("ī���ȣ : ");
	scanf("%s", card->number);
	gotoxy(26, 17);
	printf("��ȿ�Ⱓ : ");
	scanf("%s", card->period);
	gotoxy(26, 20);
	printf("��й�ȣ :   **");
	gotoxy(37, 20);
	scanf("%d", &card->password);
	gotoxy(26, 23);
	printf("�������� : ");
	scanf("%d", &card->birth);
	move_figure();
}

//������ ǥ�� �Լ�
void move_figure()
{
	gotoxy(33, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(33, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(33, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(32, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
	gotoxy(45, 5);
	printf("������");
	gotoxy(1, 33);
	Sleep(300);
}

//���� ����� ���� ���簢�� ����ϴ� �Լ�
void draw_rectangle2(int c, int r, int width)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	width = width - 1;   //�ʿ��� ����� ���

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);   //�� ���
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	for (i = 0; i < r; i++)   //�� ���
	{
		for (j = 0; j < width; j++)
			printf(" ");
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	for (j = 0; j < width; j++)  //������� �ʿ��Ѹ�ŭ ���
		printf(" ");
	printf("%c%c", a, b[6]);   // �����
	for (i = 0; i < c; i++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //�� ���
	printf("\n");
}

//�¼� ���  (
void ShowSeat(int arr[][14], int row, int col)
{
	int i, j;

	//������ �޴��� �����ϱ� ���ؼ� ȭ���� ���� �ٲ�����Ƿ� �ٽ� �����·� ������.
	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
	gotoxy(7, 9);  //�¼�ǥ�� ���� ���簢�� ���������� ����
	draw_rectangle2(33, 18, 7);  //���簢�� ���

	gotoxy(38, 12);  //��ũ�� ǥ��
	printf("%s", m_screen);

	for (i = 0; i < row; i++)
	{
		gotoxy(17, 15 + i);
		for (j = 0; j < 4; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("�� ");
			else if (arr[i][j] == 15)
				printf("�� ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);

			else
				printf(" %d ", arr[i][j]);
		printf("   ");

		for (j = 4; j < 11; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("�� ");
			else if (arr[i][j] == 15)
				printf("�� ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);
			else
				printf(" %d ", arr[i][j]);
		printf("   ");

		for (j = 11; j < 14; j++)
			if (arr[i][j] == 20)
				printf("  ");
			else if (arr[i][j] == 0)
				printf("�� ");
			else if (arr[i][j] == 15)
				printf("�� ");
			else if (i >= 1 && j == 0)
				printf("%c  ", arr[i][j]);
			else
				printf("%d ", arr[i][j]);
		printf("\n\n");
	}
}

//��� �����ϴ� �Լ���
void choose_menu00(HANDLE *x, PPL *p)
{
	char key = NULL;

	gotoxy(11, 8);
	printf("        ");    //���̶� �����
	gotoxy(11, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<���̶�>");
	key = getch();


	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(11, 8);
		printf("        ");
		gotoxy(11, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<���̶�>");
		choose_menu30(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(11, 8);
		printf("        ");
		gotoxy(11, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<���̶�>");
		choose_menu01(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "���̶�");
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
	printf("          ");    //������� �����
	gotoxy(38, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<�������>");

	key = getch();

	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(38, 8);
		printf("          ");    //������� �����
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<�������>");
		choose_menu31(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(38, 8);
		printf("          ");    //������� �����
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<�������>");
		choose_menu00(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(38, 8);
		printf("          ");    //������� �����
		gotoxy(38, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<�������>");
		choose_menu02(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�������");
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
	printf("        ");    //�پƿ� �����
	gotoxy(67, 8);
	SetConsoleTextAttribute(x, 112);
	printf("<�븳��>");

	key = getch();

	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(67, 8);
		printf("        ");
		gotoxy(67, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<�븳��>");
		choose_menu32(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(67, 8);
		printf("        ");
		gotoxy(67, 8);
		SetConsoleTextAttribute(x, 7);
		printf("<�븳��>");
		choose_menu01(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�븳��");
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
	printf("                 ");    //���̶� 1ȸ �����
	gotoxy(7, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1ȸ : 11:00~12:50");

	key = getch();

	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(7, 10);
		printf("                 ");
		gotoxy(7, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 11:00~12:50");
		choose_menu20(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "���̶�");
		p->time = 1;
		ShowSeat(seat1_1, 10, 14);
		break;
	case 8:
		gotoxy(7, 10);
		printf("                 ");
		gotoxy(7, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 11:00~12:50");
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
	printf("                 ");    //���Ѵ� 1ȸ �����
	gotoxy(35, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1ȸ : 10:40~12:40");

	key = getch();

	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(35, 10);
		printf("                 ");
		gotoxy(35, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 10:40~12:40");
		choose_menu21(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�������");
		p->time = 1;
		ShowSeat(seat2_1, 10, 14);
		break;
	case 8:
		gotoxy(35, 10);
		printf("                 ");
		gotoxy(35, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 10:40~12:40");
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
	printf("                 ");    //�پƿ� 1ȸ �����
	gotoxy(63, 10);
	SetConsoleTextAttribute(x, 112);
	printf("1ȸ : 13:10~14:54");

	key = getch();

	switch (key)
	{
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(63, 10);
		printf("                 ");
		gotoxy(63, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 13:10~14:54");
		choose_menu22(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�븳��");
		p->time = 1;
		ShowSeat(seat3_1, 10, 14);
		break;
	case 8:
		gotoxy(63, 10);
		printf("                 ");
		gotoxy(63, 10);
		SetConsoleTextAttribute(x, 7);
		printf("1ȸ : 13:10~14:54");
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
	printf("                 ");    //���̶� 2ȸ �����
	gotoxy(7, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2ȸ : 14:30~15:20");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(7, 11);
		printf("                 ");
		gotoxy(7, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 14:30~15:20");
		choose_menu10(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "���̶�");
		p->time = 2;
		ShowSeat(seat1_2, 10, 14);
		break;
	case 8:
		gotoxy(7, 11);
		printf("                 ");
		gotoxy(7, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 14:30~15:20");
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
	printf("                 ");    //���Ѵ� 2ȸ �����
	gotoxy(35, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2ȸ : 13:15~15:15");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(35, 11);
		printf("                 ");
		gotoxy(35, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 13:15~15:15");
		choose_menu11(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�������");
		p->time = 2;
		ShowSeat(seat2_2, 10, 14);
		break;
	case 8:
		gotoxy(35, 11);
		printf("                 ");
		gotoxy(35, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 13:15~15:15");
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
	printf("                 ");    //�پƿ� 2ȸ �����
	gotoxy(63, 11);
	SetConsoleTextAttribute(x, 112);
	printf("2ȸ : 17:00~18:44");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(63, 11);
		printf("                 ");
		gotoxy(63, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 17:00~18:44");
		choose_menu12(x, p);
		break;
	case 13://����
		strcpy(p->moivename, "�븳��");
		p->time = 2;
		ShowSeat(seat3_2, 10, 14);
		break;
	case 8:
		gotoxy(63, 11);
		printf("                 ");
		gotoxy(63, 11);
		SetConsoleTextAttribute(x, 7);
		printf("2ȸ : 17:00~18:44");
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
	printf("        ");    //���̶� �¼� �����
	gotoxy(10, 15);
	SetConsoleTextAttribute(x, 112);
	printf("����ȭ����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu00(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu40(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu31(x, p);
		break;
	case 13://����
		gotoxy(10, 15);
		printf("        ");
		gotoxy(10, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
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
	printf("        ");    //���Ѵ� �¼� �����
	gotoxy(38, 15);
	SetConsoleTextAttribute(x, 112);
	printf("����ȭ����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu01(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu41(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu30(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu32(x, p);
		break;
	case 13://����
		gotoxy(38, 15);
		printf("        ");
		gotoxy(38, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
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
	printf("        ");    //�پƿ� �¼� �����
	gotoxy(66, 15);
	SetConsoleTextAttribute(x, 112);
	printf("����ȭ����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu02(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu42(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
		choose_menu31(x, p);
		break;
	case 13://����
		gotoxy(66, 15);
		printf("        ");
		gotoxy(66, 15);
		SetConsoleTextAttribute(x, 7);
		printf("����ȭ����");
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
	printf("        ");    //���̶� ���� �����
	gotoxy(10, 16);
	SetConsoleTextAttribute(x, 112);
	printf("�����亸��");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu30(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu50(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(10, 16);
		printf("        ");
		gotoxy(10, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu41(x, p);
		break;
	case 13://����
		rrre = m_review01(35, 20);  //���̶� ����
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
	printf("        ");    //���Ѵ� ���� �����
	gotoxy(38, 16);
	SetConsoleTextAttribute(x, 112);
	printf("�����亸��");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu31(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu51(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu40(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(38, 16);
		printf("        ");
		gotoxy(38, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu42(x, p);
		break;
	case 13://����
		rrre = m_review02(35, 20);  //������� ���亸��
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
	printf("         ");    //�پƿ� ���� �����
	gotoxy(66, 16);
	SetConsoleTextAttribute(x, 112);
	printf("�����亸��");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu32(x, p);
		break;
	case 80://�Ʒ��� ȭ��ǥ
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu52(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(66, 16);
		printf("         ");
		gotoxy(66, 16);
		SetConsoleTextAttribute(x, 7);
		printf("�����亸��");
		choose_menu41(x, p);
		break;
	case 13://����
		rrre = m_review03(35, 20);  //�븳�� ���亸��
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
	printf("          ");    //���̶� �ٰŸ� �����
	gotoxy(9, 17);
	SetConsoleTextAttribute(x, 112);
	printf("���ٰŸ�����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(9, 17);
		printf("          ");
		gotoxy(9, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu40(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(9, 17);
		printf("          ");
		gotoxy(9, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu51(x, p);
		break;
	case 13://����
		rvw = m_story01(35, 20);
		//���̶� �ٰŸ� �����ֱ�
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
	printf("          ");    //���Ѵ� �ٰŸ� �����
	gotoxy(37, 17);
	SetConsoleTextAttribute(x, 112);
	printf("���ٰŸ�����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu41(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu50(x, p);
		break;
	case 77://������ ȭ��ǥ
		gotoxy(37, 17);
		printf("          ");
		gotoxy(37, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu52(x, p);
		break;
	case 13: //����
		rvw = m_story02(35, 20); //���Ѵ� �ٰŸ� �����ֱ�
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
	printf("          ");    //�پƿ� �ٰŸ� �����
	gotoxy(65, 17);
	SetConsoleTextAttribute(x, 112);
	printf("���ٰŸ�����");

	key = getch();

	switch (key)
	{
	case 72: //���� ȭ��ǥ
		gotoxy(65, 17);
		printf("          ");
		gotoxy(65, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu42(x, p);
		break;
	case 75://���� ȭ��ǥ
		gotoxy(65, 17);
		printf("          ");
		gotoxy(65, 17);
		SetConsoleTextAttribute(x, 7);
		printf("���ٰŸ�����");
		choose_menu51(x, p);
		break;
	case 13://����
		rvw = m_story03(35, 20);//�پƿ� �ٰŸ� �����ֱ�
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
	if (strcmp(("���̶�"), p->moivename) == 0)
		cmp_name = 1;
	else if (strcmp(("�������"), p->moivename) == 0)
		cmp_name = 3;
	else if (strcmp(("�븳��"), p->moivename) == 0)
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


//�������
int m_review01(int c, int r)
{     //c : ���簢�� �ʺ� / r : ���簢�� �� / m : �� / n: ��

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//�� �� ����
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���
	gotoxy(6, 11);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���

							//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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
{     //c : ���簢�� �ʺ� / r : ���簢�� �� / m : �� / n: ��

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//�� �� ����
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���
	gotoxy(6, 11);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���

							//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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
{     //c : ���簢�� �ʺ� / r : ���簢�� �� / m : �� / n: ��

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//�� �� ����
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���

							//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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

//�ٰŸ� ���
int m_story01(int c, int r)
{
	//c : ���簢�� �ʺ� / r : ���簢�� ��

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//�� �� ����
	gotoxy(6, 10);
	printf("%c%c", a, b[2]);//�� ���
	for (x = 0; x < c; x++)
		printf("  ");
	printf("%c%c", a, b[2]);//�� ���

							//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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
	//c : ���簢�� �ʺ� / r : ���簢�� ��

	int state;
	char buf[100], key;
	int i, j, x, y, length;

	unsigned char a = 0xa6;
	unsigned char b[7];

	HANDLE colorrr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(colorrr, &csbi);

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	gotoxy(6, 9);
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//4�� ����
	for (y = 0; y < 4; y++)
	{
		gotoxy(6, 10 + y);
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}


	//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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
	//c : ���簢�� �ʺ� / r : ���簢�� �� / m : �� / n: ��

	int state;
	char buf[100];
	int i, j, x, y, length, key;

	system("cls");  //�켱 ��üȭ�� �����
	system("color 07");  //������濡 ȸ�� �۾���
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
	printf("%c%c", a, b[3]);   //�� ���
	for (x = 0; x < c; x++)
		printf("%c%c", a, b[1]);     // �� ���
	printf("%c%c", a, b[4]);   // �����
	printf("\n");

	//3�� ����
	for (y = 0; y < 3; y++)
	{
		gotoxy(6, 10 + y);
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}


	//�� ����ŭ ���� ��� (���� �ڵ� ���)
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
		printf("%c%c", a, b[2]);//�� ���
		for (x = 0; x < c; x++)
			printf("  ");
		printf("%c%c", a, b[2]);//�� ���
	}

	//�ϴ� ���
	gotoxy(6, 30);
	printf("%c%c", a, b[6]);   // �����
	for (x = 0; x < c; x++)    //�� ���
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);   //  �����
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
			gotoxy(7, 2);  //ó��ȭ��
			show_intro(33, 1);  //������ ���
			for (i = 0; i < 3; i++)  //��ȭ ��Ʈ�� �����ش�.
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
	printf("����� �¼� ������ �Ϸ�Ǿ����ϴ٢�\n");
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
			printf("��");
		}
		else if (num == 2)
		{
			arr[1][2] = 15;
			gotoxy(23, 16);
			printf("��");
		}
		else if (num == 3)
		{
			arr[1][3] = 15;
			gotoxy(26, 16);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[1][4] = 15;
			gotoxy(32, 16);
			printf("��");
		}
		else if (num == 5)
		{
			arr[1][5] = 15;
			gotoxy(35, 16);
			printf("��");
		}
		else if (num == 6)
		{
			arr[1][6] = 15;
			gotoxy(38, 16);
			printf("��");
		}
		else if (num == 7)
		{
			arr[1][7] = 15;
			gotoxy(41, 16);
			printf("��");
		}
		else if (num == 8)
		{
			arr[1][8] = 15;
			gotoxy(44, 16);
			printf("��");
		}
		else if (num == 9)
		{
			arr[1][9] = 15;
			gotoxy(47, 16);
			printf("��");
		}
		else if (num == 10)
		{
			arr[1][10] = 15;
			gotoxy(50, 16);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[1][11] = 15;
			gotoxy(56, 16);
			printf("��");
		}
		else if (num == 12)
		{
			arr[1][12] = 15;
			gotoxy(59, 16);
			printf("��");
		}
		else if (num == 13)
		{
			arr[1][3] = 15;
			gotoxy(62, 16);
			printf("��");
		}
	}
	//***********************B**************************
	else if (alphabet == 'B')
	{
		if (num == 1)
		{
			arr[2][1] = 15;
			gotoxy(20, 17);
			printf("��");
		}
		else if (num == 2)
		{
			arr[2][2] = 15;
			gotoxy(23, 17);
			printf("��");
		}
		else if (num == 3)
		{
			arr[2][3] = 15;
			gotoxy(26, 17);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[2][4] = 15;
			gotoxy(32, 17);
			printf("��");
		}
		else if (num == 5)
		{
			arr[2][5] = 15;
			gotoxy(35, 17);
			printf("��");
		}
		else if (num == 6)
		{
			arr[2][6] = 15;
			gotoxy(38, 17);
			printf("��");
		}
		else if (num == 7)
		{
			arr[2][7] = 15;
			gotoxy(41, 17);
			printf("��");
		}
		else if (num == 8)
		{
			arr[2][8] = 15;
			gotoxy(44, 17);
			printf("��");
		}
		else if (num == 9)
		{
			arr[2][9] = 15;
			gotoxy(47, 17);
			printf("��");
		}
		else if (num == 10)
		{
			arr[2][10] = 15;
			gotoxy(50, 17);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[2][11] = 15;
			gotoxy(56, 17);
			printf("��");
		}
		else if (num == 12)
		{
			arr[2][12] = 15;
			gotoxy(59, 17);
			printf("��");
		}
		else if (num == 13)
		{
			arr[2][13] = 15;
			gotoxy(62, 17);
			printf("��");
		}
	}
	//***********************C**************************
	else if (alphabet == 'C')
	{
		if (num == 1)
		{
			arr[3][1] = 15;
			gotoxy(20, 18);
			printf("��");
		}
		else if (num == 2)
		{
			arr[3][2] = 15;
			gotoxy(23, 18);
			printf("��");
		}
		else if (num == 3)
		{
			arr[3][3] = 15;
			gotoxy(26, 18);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[3][4] = 15;
			gotoxy(32, 18);
			printf("��");
		}
		else if (num == 5)
		{
			arr[3][5] = 15;
			gotoxy(35, 18);
			printf("��");
		}
		else if (num == 6)
		{
			arr[3][6] = 15;
			gotoxy(38, 18);
			printf("��");
		}
		else if (num == 7)
		{
			arr[3][7] = 15;
			gotoxy(41, 18);
			printf("��");
		}
		else if (num == 8)
		{
			arr[3][8] = 15;
			gotoxy(44, 18);
			printf("��");
		}
		else if (num == 9)
		{
			arr[3][9] = 15;
			gotoxy(47, 18);
			printf("��");
		}
		else if (num == 10)
		{
			arr[3][10] = 15;
			gotoxy(50, 18);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[3][11] = 15;
			gotoxy(56, 18);
			printf("��");
		}
		else if (num == 12)
		{
			arr[3][12] = 15;
			gotoxy(59, 18);
			printf("��");
		}
		else if (num == 13)
		{
			arr[3][13] = 15;
			gotoxy(62, 18);
			printf("��");
		}
	}
	//***********************D**************************
	else if (alphabet == 'D')
	{
		if (num == 1)
		{
			arr[4][1] = 15;
			gotoxy(20, 19);
			printf("��");
		}
		else if (num == 2)
		{
			arr[4][2] = 15;
			gotoxy(23, 19);
			printf("��");
		}
		else if (num == 3)
		{
			arr[4][3] = 15;
			gotoxy(26, 19);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[4][4] = 15;
			gotoxy(32, 19);
			printf("��");
		}
		else if (num == 5)
		{
			arr[4][5] = 15;
			gotoxy(35, 19);
			printf("��");
		}
		else if (num == 6)
		{
			arr[4][6] = 15;
			gotoxy(38, 19);
			printf("��");
		}
		else if (num == 7)
		{
			arr[4][7] = 15;
			gotoxy(41, 19);
			printf("��");
		}
		else if (num == 8)
		{
			arr[4][8] = 15;
			gotoxy(44, 19);
			printf("��");
		}
		else if (num == 9)
		{
			arr[4][9] = 15;
			gotoxy(47, 19);
			printf("��");
		}
		else if (num == 10)
		{
			arr[4][10] = 15;
			gotoxy(50, 19);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[4][11] = 15;
			gotoxy(56, 19);
			printf("��");
		}
		else if (num == 12)
		{
			arr[4][12] = 15;
			gotoxy(59, 19);
			printf("��");
		}
		else if (num == 13)
		{
			arr[4][13] = 15;
			gotoxy(62, 19);
			printf("��");
		}
	}
	//***********************E**************************
	else if (alphabet == 'E')
	{
		if (num == 1)
		{
			arr[5][1] = 15;
			gotoxy(20, 20);
			printf("��");
		}
		else if (num == 2)
		{
			arr[5][2] = 15;
			gotoxy(23, 20);
			printf("��");
		}
		else if (num == 3)
		{
			arr[5][3] = 15;
			gotoxy(26, 20);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[5][4] = 15;
			gotoxy(32, 20);
			printf("��");
		}
		else if (num == 5)
		{
			arr[5][5] = 15;
			gotoxy(35, 20);
			printf("��");
		}
		else if (num == 6)
		{
			arr[5][6] = 15;
			gotoxy(38, 20);
			printf("��");
		}
		else if (num == 7)
		{
			arr[5][7] = 15;
			gotoxy(41, 20);
			printf("��");
		}
		else if (num == 8)
		{
			arr[5][8] = 15;
			gotoxy(44, 20);
			printf("��");
		}
		else if (num == 9)
		{
			arr[5][9] = 15;
			gotoxy(47, 20);
			printf("��");
		}
		else if (num == 10)
		{
			arr[5][10] = 15;
			gotoxy(50, 20);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[5][11] = 15;
			gotoxy(56, 20);
			printf("��");
		}
		else if (num == 12)
		{
			arr[5][12] = 15;
			gotoxy(59, 20);
			printf("��");
		}
		else if (num == 13)
		{
			arr[5][13] = 15;
			gotoxy(62, 20);
			printf("��");
		}
	}
	//***********************F**************************
	else if (alphabet == 'F')
	{
		if (num == 1)
		{
			arr[6][1] = 15;
			gotoxy(20, 21);
			printf("��");
		}
		else if (num == 2)
		{
			arr[6][2] = 15;
			gotoxy(23, 21);
			printf("��");
		}
		else if (num == 3)
		{
			arr[6][3] = 15;
			gotoxy(26, 21);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[6][4] = 15;
			gotoxy(32, 21);
			printf("��");
		}
		else if (num == 5)
		{
			arr[6][5] = 15;
			gotoxy(35, 21);
			printf("��");
		}
		else if (num == 6)
		{
			arr[6][6] = 15;
			gotoxy(38, 21);
			printf("��");
		}
		else if (num == 7)
		{
			arr[6][7] = 15;
			gotoxy(41, 21);
			printf("��");
		}
		else if (num == 8)
		{
			arr[6][8] = 15;
			gotoxy(44, 21);
			printf("��");
		}
		else if (num == 9)
		{
			arr[6][9] = 15;
			gotoxy(47, 21);
			printf("��");
		}
		else if (num == 10)
		{
			arr[6][10] = 15;
			gotoxy(50, 21);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[6][11] = 15;
			gotoxy(56, 21);
			printf("��");
		}
		else if (num == 12)
		{
			arr[6][12] = 15;
			gotoxy(59, 21);
			printf("��");
		}
		else if (num == 13)
		{
			arr[6][13] = 15;
			gotoxy(62, 21);
			printf("��");
		}
	}
	//***********************G**************************
	else if (alphabet == 'G')
	{
		if (num == 1)
		{
			arr[7][1] = 15;
			gotoxy(20, 22);
			printf("��");
		}
		else if (num == 2)
		{
			arr[7][2] = 15;
			gotoxy(23, 22);
			printf("��");
		}
		else if (num == 3)
		{
			arr[7][3] = 15;
			gotoxy(26, 22);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[7][4] = 15;
			gotoxy(32, 22);
			printf("��");
		}
		else if (num == 5)
		{
			arr[7][5] = 15;
			gotoxy(35, 22);
			printf("��");
		}
		else if (num == 6)
		{
			arr[7][6] = 15;
			gotoxy(38, 22);
			printf("��");
		}
		else if (num == 7)
		{
			arr[7][7] = 15;
			gotoxy(41, 22);
			printf("��");
		}
		else if (num == 8)
		{
			arr[7][8] = 15;
			gotoxy(44, 22);
			printf("��");
		}
		else if (num == 9)
		{
			arr[7][9] = 15;
			gotoxy(47, 22);
			printf("��");
		}
		else if (num == 10)
		{
			arr[7][10] = 15;
			gotoxy(50, 22);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[7][11] = 15;
			gotoxy(56, 22);
			printf("��");
		}
		else if (num == 12)
		{
			arr[7][12] = 15;
			gotoxy(59, 22);
			printf("��");
		}
		else if (num == 13)
		{
			arr[7][13] = 15;
			gotoxy(62, 22);
			printf("��");
		}
	}
	//***********************H**************************
	else if (alphabet == 'H')
	{
		if (num == 1)
		{
			arr[8][1] = 15;
			gotoxy(20, 23);
			printf("��");
		}
		else if (num == 2)
		{
			arr[8][2] = 15;
			gotoxy(23, 23);
			printf("��");
		}
		else if (num == 3)
		{
			arr[8][3] = 15;
			gotoxy(26, 23);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[8][4] = 15;
			gotoxy(32, 23);
			printf("��");
		}
		else if (num == 5)
		{
			arr[8][5] = 15;
			gotoxy(35, 23);
			printf("��");
		}
		else if (num == 6)
		{
			arr[8][6] = 15;
			gotoxy(38, 23);
			printf("��");
		}
		else if (num == 7)
		{
			arr[8][7] = 15;
			gotoxy(41, 23);
			printf("��");
		}
		else if (num == 8)
		{
			arr[8][8] = 15;
			gotoxy(44, 23);
			printf("��");
		}
		else if (num == 9)
		{
			arr[8][9] = 15;
			gotoxy(47, 23);
			printf("��");
		}
		else if (num == 10)
		{
			arr[8][10] = 15;
			gotoxy(50, 23);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[8][11] = 15;
			gotoxy(56, 23);
			printf("��");
		}
		else if (num == 12)
		{
			arr[8][12] = 15;
			gotoxy(59, 23);
			printf("��");
		}
		else if (num == 13)
		{
			arr[8][13] = 15;
			gotoxy(62, 23);
			printf("��");
		}
	}
	//***********************I**************************
	else if (alphabet == 'I')
	{
		if (num == 1)
		{
			arr[9][1] = 15;
			gotoxy(20, 24);
			printf("��");
		}
		else if (num == 2)
		{
			arr[9][2] = 15;
			gotoxy(23, 24);
			printf("��");
		}
		else if (num == 3)
		{
			arr[9][3] = 15;
			gotoxy(26, 24);
			printf("��");
		}
		//////////////////////
		else if (num == 4)
		{
			arr[9][4] = 15;
			gotoxy(32, 24);
			printf("��");
		}
		else if (num == 5)
		{
			arr[9][5] = 15;
			gotoxy(35, 24);
			printf("��");
		}
		else if (num == 6)
		{
			arr[9][6] = 15;
			gotoxy(38, 24);
			printf("��");
		}
		else if (num == 7)
		{
			arr[9][7] = 15;
			gotoxy(41, 24);
			printf("��");
		}
		else if (num == 8)
		{
			arr[9][8] = 15;
			gotoxy(44, 24);
			printf("��");
		}
		else if (num == 9)
		{
			arr[9][9] = 15;
			gotoxy(47, 24);
			printf("��");
		}
		else if (num == 10)
		{
			arr[9][10] = 15;
			gotoxy(50, 24);
			printf("��");
		}
		//////////////////////
		else if (num == 11)
		{
			arr[9][11] = 15;
			gotoxy(56, 24);
			printf("��");
		}
		else if (num == 12)
		{
			arr[9][12] = 15;
			gotoxy(59, 24);
			printf("��");
		}
		else if (num == 13)
		{
			arr[9][13] = 15;
			gotoxy(62, 24);
			printf("��");
		}
	}
}


//�Ѻ� �Լ� ����
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
	printf("�����ݾ� : %d", P1.money);

	gotoxy(7, 2);
	show_box(33, 1, m_pay1);
	GetCardInfo(&card);

	system("cls");
	gotoxy(7, 2);
	show_intro(33, 1);
	gotoxy(15, 7);
	draw_rectangle2(25, 20, 15);
	gotoxy(18, 15);
	printf("��*..::..*��..::..*��..::..*��..::..*��..::..*��");
	gotoxy(32, 17);
	printf("������ �Ϸ�Ǿ����ϴ� !");
	gotoxy(18, 19);
	printf("��*..::..*��..::..*��..::..*��..::..*��..::..*��");
	Sleep(2000);
	system("cls");

	bill_print();
}

void ismember(members *a)      // ����� ���� ���� Ȯ��
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

	if (yorn == 1)      //���� ������ �Ǿ��ִٸ�
		member(a);      //��ȣ�� Ȯ��.

	if (yorn == 2)      //������ �ȵǾ��ִٸ�
	{
		k = question();      //�����Ұ��� �����
		if (k == 1)
			input_member(a);   //yes�� ����
		if (k == 2)
			PayMoney(0);      //no�� ����
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
	printf("�ڵ�����ȣ ���ڸ� 4 �� ��ȣ�� �Է����ּ��� : ");
	scanf("%d", &phonenum);

	for (i = 0; i < CUSTOMER_MAX; i++) 
	{
		if (a[i].number == phonenum) {
			gotoxy(18, 18);
			printf("�� Ȯ���� �Ϸ�Ǿ����ϴ�.");
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
		printf("���� ���� �ʴ� ȸ���Դϴ�.");
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

	gotoxy(7, 2);  //ó��ȭ��
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
			printf("�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
	}
}

void input_member(members* a)
{
	if (count <= CUSTOMER_MAX)
	{
		system("color 07");
		gotoxy(18, 13);
		printf("�̸��� �Է��ϼ��� : ");
		scanf("%s", &a[count].name);
		gotoxy(18, 15);
		printf("�ڵ�����ȣ ���ڸ� 4 �� ��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &a[count].number);
		a[count].point = 0;

		gotoxy(35, 23);
		printf("�����մϴ� !");
		Sleep(1000);

		gotoxy(30, 25);
		printf("������ �Ϸ�Ǿ����ϴ� !\n");
		Sleep(1000);

		Getpoint(&a[count], P1.money);
		Sleep(1000);
		PayMoney(0);
		count++;
	}
	else {
		gotoxy(23, 25);
		printf("������ �� �ִ� ������ �ʰ��Ͽ����ϴ�.");
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
		printf("��� �� ����Ʈ�� �Է����ּ���.");
		gotoxy(18, 20);
		printf("���� �ܿ� ����Ʈ(%d point) :    ", a->point);
		gotoxy(48, 20);
		scanf("%d", &use);
		if (use > a->point) {
			gotoxy(18, 24);
			printf("��� �� ����Ʈ�� �ܿ� ����Ʈ���� �����ϴ�.");
			gotoxy(18, 26);
			printf("�ٽ� �Է����ּ���.\n");
			Sleep(1000);
			gotoxy(18, 24);
			printf("                                                ");
			gotoxy(18, 26);
			printf("                    ");
		} else {
			a->point = a->point - use;
			gotoxy(18, 22);
			printf("����� ����Ʈ�� %dp �̰� �ܿ�����Ʈ�� %dp�Դϴ�.", use, a->point);
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
	//���簢�� ��������Ʈ �ϰ� �� �ȿ� �Ʒ� �ؽ�Ʈ ���
	gotoxy(27, 11);
	printf("*****  ��    ��    ��  *****\n");
	gotoxy(30, 15);
	printf("��ȭ �̸� : %s\n", P1.moivename);
	gotoxy(30, 18);
	printf("�� �� : %d\n", P1.total);
	gotoxy(30, 21);
	printf("�¼� : ");
	for (int i = 0; i < P1.total; i++)
		printf("%c%d  ", P1.seat_alpha[i], P1.seat_num[i]);
	gotoxy(30, 24);
	printf("���� : %d\n", P1.money);

	Sleep(3000);
}

int choose_answer01(HANDLE *x)
{
	char key = NULL;

	gotoxy(53, 5);
	printf("    ");    //(1)�� �����
	gotoxy(53, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)��");
	key = getch();

	switch (key)
	{

	case 77://������ ȭ��ǥ
		gotoxy(53, 5);
		printf("    ");    //(1)�� �����
		gotoxy(53, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)��");
		choose_answer02(x);
		break;
	case 13://����
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
	printf("      ");    //(2)�ƴϿ� �����
	gotoxy(59, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)�ƴϿ�");
	key = getch();

	switch (key)
	{

	case 75://���� ȭ��ǥ
		gotoxy(59, 5);
		printf("      ");    //(2)�ƴϿ� �����
		gotoxy(59, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)�ƴϿ�");
		choose_answer01(hC);
		break;
	case 13://����
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
	printf("    ");    //(1)�� �����
	gotoxy(47, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)��");
	key = getch();

	switch (key)
	{

	case 77://������ ȭ��ǥ
		gotoxy(47, 5);
		printf("    ");    //(1)�� �����
		gotoxy(47, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)��");
		choose_answer04(x);
		break;
	case 13://����
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
	printf("      ");    //(2)�ƴϿ� �����
	gotoxy(54, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)�ƴϿ�");
	key = getch();

	switch (key)
	{

	case 75://���� ȭ��ǥ
		gotoxy(54, 5);
		printf("    ");    //(2)�ƴϿ� �����
		gotoxy(54, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)�ƴϿ�");
		choose_answer03(x);
		break;
	case 13://����
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
	printf("    ");    //(1)�� �����
	gotoxy(46, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(1)��");
	key = getch();

	switch (key)
	{

	case 77://������ ȭ��ǥ
		gotoxy(46, 5);
		printf("    ");    //(1)�� �����
		gotoxy(46, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(1)��");
		choose_answer06(x);
		break;
	case 13://����
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
	printf("      ");    //(2)�ƴϿ� �����
	gotoxy(52, 5);
	SetConsoleTextAttribute(x, 112);
	printf("(2)�ƴϿ�");
	key = getch();

	switch (key)
	{

	case 75://���� ȭ��ǥ
		gotoxy(52, 5);
		printf("      ");    //(2)�ƴϿ� �����
		gotoxy(52, 5);
		SetConsoleTextAttribute(x, 7);
		printf("(2)�ƴϿ�");
		choose_answer05(hC);
		break;
	case 13://����
		return 0;
	default:
		SetConsoleTextAttribute(x, 7);
		choose_answer06(x);
		break;
	}
}
