// C -> C++ -> C#

// printf, cout

// sturct

int g_Global = 0;


// �̸� �ߺ����� �ذ�
namespace MY_SPACE
{
	int g_Global = 0;
}

namespace OTHER_SPACE
{
	int g_Global = 0;

	int Add(int a, int b)
	{
		return a + b;
	}
}

// namespace �� ��ȿȭ
//using namespace OTHER_SPACE;

// namespace �ȿ� �ִ� Ư�� ��� or �׸� ��ȿȭ
using OTHER_SPACE::Add;


int main()
{
	g_Global = 0;

	MY_SPACE::g_Global = 100;

	OTHER_SPACE::g_Global = 10;

	int c = OTHER_SPACE::Add(10, 29090);

	Add(10, 10);

	return 0;
}