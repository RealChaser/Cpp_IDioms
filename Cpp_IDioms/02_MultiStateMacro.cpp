#include <Windows.h>
#include <stdio.h>

// 02_MultiStateMacro
// if, if-else 와 같이 사용될수 있는 매크로
// 핵심 : 매크로 함수를 2줄이상으로 구현할때는 do { } while(0) 으로 묶는것이 가장 안전합니다.

void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 아래 처럼 만들면 if () 문에서 문제 가 있습니다.
#define xyprintf_1( x, y, ... )   gotoxy(x, y); printf( __VA_ARGS__)

// 아래 처럼 하면 if - else 구문사용시 에러가 있습니다.
#define xyprintf_2( x, y, ... )  { gotoxy(x, y); printf( __VA_ARGS__); }

// OK
#define xyprintf( x, y, ... )  do { gotoxy(x, y); printf( __VA_ARGS__); }while(0)

int main()
{
//1. -------------------------------
	if (0)
		xyprintf_1(10, 10, "hello");

	/*	
	위문장을 해석하면 아래처럼 적용되어 의도와 다르다.
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












