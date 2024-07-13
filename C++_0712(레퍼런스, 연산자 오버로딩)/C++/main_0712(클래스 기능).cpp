

class MyClass
{
private:
	int			m_i;
	float		m_f;
	//const short m_s;
	short		m_s;
public:
	void SetInt(int _i) { m_i = _i; }
	void SetFloat(int _Float) {  m_f = _Float; }
	
	int GetInt() { return m_i; }
	float GetFloat() { return m_f; }
	short GetShort() { return m_s; }


public:
	// 기본(Default) 생성자
	// 생성자가 하나도 구현되어있지 않으면, 컴파일러가 자동으로 구현

	// 기본생성자가 아니라도, 1개 이상의 생성자가 구현이 되어있으면,
	// 컴파일러는 기본생성자를 만들어주지 않는다.

	MyClass(void) 
		: m_i(0)  // 이니셜라이저
		, m_f(0.f)
		, m_s(0)
	{
		m_i = 0;		// 대입
		m_f = 0.f;		// 대입
		//m_s = 20;		// 대입
	}

	// 생성자 오버로딩
	MyClass(int _i, float _f, short _s)
		: m_i(_i)
		, m_f(_f)
		, m_s(_s)
	{

	}


	// 소멸자가 구현되어있지 않으면, 컴파일러가 자동으로 구현
	~MyClass()
	{

	}
};



void SetData(int* _Data)
{
	*_Data = 300;
}


void SetData(int& _Data)
{
	_Data = 400;
}





int main()
{
	MyClass my; // 기본생성자 호출
	my.SetInt(10);

	int i = 0; // 초기화
	i = 100; // 대입

	// 오버로딩 한 다른 생성자를 호출시키면서 객체 생성
	MyClass my1(100, 200.f, 300);
	// MyClass my2(); // 반환타입이 MyClass, 함수이름이 my2, 함수 입력인자가 void 인 함수 전방선으로 본다.
	// 클래스로 객체를 선언할 때 기본생성자를 호출하고 싶으면 () 괄호를 적지 않는다.


	// 변수를 상수화 시킬 경우, 초기화 시점에만 값을 처음에한번 입력 가능하다.
	//const int ci = 200;
	//ci = 500;


	// C++
	// 레퍼런스 (참조)
	int value = 0;

	int* pInt = &value;
	*pInt = 100;

	int& ref = value;
	ref = 200;
	
	SetData(&value);
	SetData(value);


	return 0;
}