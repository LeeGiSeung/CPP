// C -> C++ -> C#

// printf, cout

// sturct

int g_Global = 0;


// 이름 중복문제 해결
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

// namespace 를 무효화
//using namespace OTHER_SPACE;

// namespace 안에 있는 특정 기능 or 항목만 무효화
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