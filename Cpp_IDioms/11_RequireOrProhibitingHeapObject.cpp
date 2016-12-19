
// cafe.naver.com/cppmaster ���� "2���� �����ҽ� �����ø� �˴ϴ�."



// ��ü�� ���� ����� ���� �ϰų�, �ݵ�� ���� ����� �ϴ� ���

class OnlyHeap
{
public:

	void Delete() { delete this; }

	// protected�Ҹ���.. : stack �� ��ü�� ����� ���� �Ѵ�.
protected:
	~OnlyHeap() {}
};
class NoHeap
{
public:
	// new �Լ��� �����Ѵ�. (C++11 delete function)
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

	// ���� ����� ���� �غ���..
	NoHeap* p = new NoHeap; // error
}



