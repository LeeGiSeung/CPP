
#include <iostream>

// C++ ���� class �� struct �� ������ �������� 
// Default ���� �����ڰ� class �� Private, struct �� Public �̴�

class MyType
{
	// ���� ���� ������
private:
	// �ɹ� ����
	int		a;
	float	b;

	// �ɹ� �Լ� - Ư�� Ŭ����, ����ü
	// �ɹ��Լ��� ȣ���ϱ� ���ؼ�, ��ü�� �ʿ��ϴ�.
public:
	void SetInt(int _a)
	{
		a = _a;
	}

	void SetFloat(float _f)
	{
		b = _f;
	}

	MyType* GetAdress()
	{
		return this;
	}

public:
	// ������ 
	// - �ɹ��Լ�, �������� �ʾƵ� �ڵ� �����Ǵ� �ɹ��Լ�
	// - ��ü�� ������ �� ȣ��
	MyType()
	{
		printf("������ ȣ���\n");
	}

	// �Ҹ��� 
	// - �ɹ��Լ�, �������� �ʾƵ� �ڵ� �����Ǵ� �ɹ��Լ�
	// - ��ü�� ������ �� ȣ�� ��
	~MyType()
	{
		printf("�Ҹ��� ȣ���\n");
	}
};

struct MyStruct
{
	int		a;
	float	b;
};

// ���� �Լ�
void SetInt(MyStruct* _this, int _a)
{
	_this->a = _a;
}


int main()
{
	// ����� ���� �ڷ���
	// struct
	// class

	// C-struct -> C++-class
	// ���м�, �ɹ��� ���� ���ٷ����� ������ �� �ְ� ��
	MyType type = {};	
	MyType type1 = {};
	MyType type2 = {};

	//type.a = 100;
	//type.b = 200.f;

	type1.SetInt(100);
	type.SetFloat(200.f);

	MyType* pAdress = type.GetAdress();


	// C ������ �����Ҵ�
	// �ܼ��ϰ� ���ϴ� �޸��� ũ�⸸ �����ϱ� ������, ���޸� ������ �Ҵ�Ǵ� ������ ���� �뵵�� 
	// ���������� �� ���� ����.

	// ���� C++ �� Ŭ����(����������ڷ���) �� ��Ģ�� ��ü ������ ������ ȣ��, ��ü �Ҹ� �� 
	// �Ҹ��� ȣ��� ����� �� ����.
	MyType* pMyType	= (MyType*)malloc(sizeof(MyType) * 4);

	pMyType[0];
	pMyType[1];
	pMyType[2];
	pMyType[3];

	// C ������ ���޸� ����
	free(pMyType);


	// C++ ������ �����Ҵ�
	// �����Ҵ翡 ����� �ڷ��� ������ ����
	// �ڷ��� ������ ���ؼ� ũ��������, Ŭ���� Ÿ���� ��� Ŭ������ ������ ȣ����� ������ �� �ִ�.
	MyType* pMyType1 = new MyType;
	
	// C++ ������ ���޸� ����
	// delete Ű���忡 �����͸� ���޽�Ŵ, ���޽�Ű�� �����Ͱ� � Ÿ���̳Ŀ� ���� ���޸� ������
	// � �뵵�� ������ �� �� ����, ���� �Ҹ��ڱ��� ȣ���� ����
	delete pMyType1;


	// C++ ������ �����Ҵ� ������
	MyType* pMyType2 = new MyType[4];

	// C++ ������ ���޸� ����
	delete[] pMyType2;


	return 0;
}