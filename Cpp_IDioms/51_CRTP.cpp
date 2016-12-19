// 51_CRTP
#include <iostream>
using namespace std;

// CRTP : 부모가 템플릿 인데.. 자식 만들때 자신의 이름을 보내는 기술

// 1. CRTP를 사용한 다른 부모 만들기.
template<typename T> struct LimitCount
{
	static int count;

	LimitCount()  { if (++count > 5) throw 1; }
	~LimitCount() {	--count; }
};
template<typename T> int LimitCount<T>::count = 0;

class Car : public LimitCount<Car>
{};

class Truck : public LimitCount<Truck>
{};

int main()
{
	Car a1[4];
	Truck a2[3];
}






