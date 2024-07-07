


#define HELLO 100

// 매크로 함수
#define ADD(a, b)  a + b


// 오버 라이딩(클래스 상속)
// 함수 오버로딩
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

	// 파일과 헤더 분할
	int i = HELLO;

	i = ADD(17, 18);
	i = 3 * Add(20, 10);
	i = 3 * ADD(20, 10);

	return 0;
}