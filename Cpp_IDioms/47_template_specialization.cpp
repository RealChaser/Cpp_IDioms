#include <iostream>
#include <set>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

// Point ũ�� �񱳿� �Լ� ��ü
struct LessPointer
{
	inline bool operator()(const Point& p1, const Point& p2) const{	return p1.x < p2.x;	}
};

// less �Լ���ü�� �̹� �ֽ��ϴ�.
// ��������� ũ�� �񱳸� ���� < �� ����մϴ�.

// Point ������ ����ȭ �մϴ�.
template<> struct less<Point>
{
	inline bool operator()(const Point& p1, const Point& p2) const { return p1.x < p2.x; }
};

int main()
{
	set<Point> s;   //set<Point, less<Point> > s;

	//set<Point, LessPointer> s;

	s.insert(Point(1, 1));
	s.insert(Point(2, 1));
}




