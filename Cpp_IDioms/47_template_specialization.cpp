#include <iostream>
#include <set>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

// Point 크기 비교용 함수 객체
struct LessPointer
{
	inline bool operator()(const Point& p1, const Point& p2) const{	return p1.x < p2.x;	}
};

// less 함수객체는 이미 있습니다.
// 구현방법은 크기 비교를 위해 < 를 사용합니다.

// Point 버전을 전문화 합니다.
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




