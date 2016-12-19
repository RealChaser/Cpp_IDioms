#include <Windows.h>
#include <stdio.h>

// 02_MultiStateMacro
// if, if-else �� ���� ���ɼ� �ִ� ��ũ��
// �ٽ� : ��ũ�� �Լ��� 2���̻����� �����Ҷ��� do { } while(0) ���� ���°��� ���� �����մϴ�.

void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// �Ʒ� ó�� ����� if () ������ ���� �� �ֽ��ϴ�.
#define xyprintf_1( x, y, ... )   gotoxy(x, y); printf( __VA_ARGS__)

// �Ʒ� ó�� �ϸ� if - else �������� ������ �ֽ��ϴ�.
#define xyprintf_2( x, y, ... )  { gotoxy(x, y); printf( __VA_ARGS__); }

// OK
#define xyprintf( x, y, ... )  do { gotoxy(x, y); printf( __VA_ARGS__); }while(0)

int main()
{
//1. -------------------------------
	if (0)
		xyprintf_1(10, 10, "hello");

	/*	
	�������� �ؼ��ϸ� �Ʒ�ó�� ����Ǿ� �ǵ��� �ٸ���.
	-------------------------
	if (0)
		gotoxy(x, y); 
	printf( __VA_ARGS__);
	-------------------------
	*/

//2. -------------------------------

	if (0)
		xyprintf_2(10, 10, "hello");
	else
	{
	}

//3. -------------------------------
	if (0)
		xyprintf(10, 10, "hello");	
}












