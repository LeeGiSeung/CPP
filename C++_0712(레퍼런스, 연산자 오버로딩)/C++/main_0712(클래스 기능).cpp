

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
	// �⺻(Default) ������
	// �����ڰ� �ϳ��� �����Ǿ����� ������, �����Ϸ��� �ڵ����� ����

	// �⺻�����ڰ� �ƴ϶�, 1�� �̻��� �����ڰ� ������ �Ǿ�������,
	// �����Ϸ��� �⺻�����ڸ� ��������� �ʴ´�.

	MyClass(void) 
		: m_i(0)  // �̴ϼȶ�����
		, m_f(0.f)
		, m_s(0)
	{
		m_i = 0;		// ����
		m_f = 0.f;		// ����
		//m_s = 20;		// ����
	}

	// ������ �����ε�
	MyClass(int _i, float _f, short _s)
		: m_i(_i)
		, m_f(_f)
		, m_s(_s)
	{

	}


	// �Ҹ��ڰ� �����Ǿ����� ������, �����Ϸ��� �ڵ����� ����
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
	MyClass my; // �⺻������ ȣ��
	my.SetInt(10);

	int i = 0; // �ʱ�ȭ
	i = 100; // ����

	// �����ε� �� �ٸ� �����ڸ� ȣ���Ű�鼭 ��ü ����
	MyClass my1(100, 200.f, 300);
	// MyClass my2(); // ��ȯŸ���� MyClass, �Լ��̸��� my2, �Լ� �Է����ڰ� void �� �Լ� ���漱���� ����.
	// Ŭ������ ��ü�� ������ �� �⺻�����ڸ� ȣ���ϰ� ������ () ��ȣ�� ���� �ʴ´�.


	// ������ ���ȭ ��ų ���, �ʱ�ȭ �������� ���� ó�����ѹ� �Է� �����ϴ�.
	//const int ci = 200;
	//ci = 500;


	// C++
	// ���۷��� (����)
	int value = 0;

	int* pInt = &value;
	*pInt = 100;

	int& ref = value;
	ref = 200;
	
	SetData(&value);
	SetData(value);


	return 0;
}