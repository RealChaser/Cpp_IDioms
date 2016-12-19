// 51_CRTP
#include <iostream>
using namespace std;

// CRTP : �θ� ���ø� �ε�.. �ڽ� ���鶧 �ڽ��� �̸��� ������ ���

// 1. CRTP�� ����� �ٸ� �θ� �����.
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






