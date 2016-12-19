// 42_Exception_Safety

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;
public:
	void push(const T& a) { buff[idx++] = a; }

	T pop()
	{
		if (idx < 1)
			throw 1;
		--idx;

		return buff[idx];
	}
};

int main()
{
	Stack<int> s;
	try	{	s.pop();	}
	catch (...) {}

	// s�� ��� ����Ҽ� ������ ?
}


// ���� ������(Exception Safety)
// ���� ���� : ���ܰ� ����. int a = 0
// ���� ���� : ���ܸ� ������ ��ü�� ���� �߻� �������¸� �����Ѵ�. ��ü ��밡��
// �⺻ ���� : ���ܸ� ������ �޸𸮵��� �ڿ� ������ ����. ������ ��ü�� ���´� �˼� ����. ��ü ���Ұ�
