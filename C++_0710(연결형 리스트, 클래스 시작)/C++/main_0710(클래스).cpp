

class MyType
{
	// 접근 제한 지정자
private:
	int		a;
	float	b;
};





int main()
{
	// 사용자 정의 자료형
	// struct
	// class

	// C-struct -> C++-class
	// 은닉성, 맴버에 대한 접근레벨을 지정할 수 있게 됨


	MyType type = {};

	type.a = 100;
	type.b = 200.f;



	return 0;
}