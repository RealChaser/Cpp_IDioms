
// cafe.naver.com/cppmaster 에서 "2일차 사전소스 받으시면 됩니다."



// 객체를 힙에 만들수 없게 하거나, 반드시 힙에 만들게 하는 기법

class OnlyHeap
{
public:

	void Delete() { delete this; }

	// protected소멸자.. : stack 에 객체를 만들수 없게 한다.
protected:
	~OnlyHeap() {}
};
class NoHeap
{
public:
	// new 함수를 제거한다. (C++11 delete function)
	static void* operator new(size_t sz) 
	{
		static_assert(0, "NoHeap cannot make object in heap");
		return 0;
	}
	static void operator delete(void*) = delete;
};

int main()
{
	//OnlyHeap oh; // error
//	OnlyHeap* p = new OnlyHeap;
//	p->Delete();
//	delete p;

	// 힙에 만들수 없게 해보자..
	NoHeap* p = new NoHeap; // error
}



