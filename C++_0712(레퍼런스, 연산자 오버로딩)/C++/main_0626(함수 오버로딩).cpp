


#define HELLO 100

// ��ũ�� �Լ�
#define ADD(a, b)  a + b


// ���� ���̵�(Ŭ���� ���)
// �Լ� �����ε�
int Add(int a, int b)
{
	int k = 0;

	return a + b;
}

int Add(float _a, float _b)
{
	return _a + _b;
}

int Add(int a)
{
	return a;
}

int main()
{
	int d = Add(10, 20);
	Add(1.f, 2.222f);
	Add(20);

	// ���ϰ� ��� ����
	int i = HELLO;

	i = ADD(17, 18);
	i = 3 * Add(20, 10);
	i = 3 * ADD(20, 10);

	return 0;
}