
// 연산자 오버로딩
class CData
{
private:
	int			m_i;
	long long	m_ll;

public:
	void SetInt(int _i) { m_i = _i; }
	void SetLongLong(long long _ll) { m_ll = _ll; }

	int GetInt() { return m_i; }
	long long GetLongLong() { return m_ll; }

	// 연산자 오버로딩
public:
	CData operator + (const CData& _Other) const // 해당 맴버함수를 호출시킨 객체를 수정하지 않겠다.
	{
		CData data;

		data.m_i = m_i + _Other.m_i;
		data.m_ll = m_ll + _Other.m_ll;

		// m_i = 200;
		// _Other.m_i = 200;

		return data;
	}

public:
	CData()
		: m_i(0)
		, m_ll(0)
	{
	}

	~CData()
	{
	}
};

//CData operator+(const CData& _Left, const CData& _Right)
//{
//	CData data;
//
//	data.SetInt(_Left.GetInt() + _Right.GetInt());
//	data.SetLongLong(_Left.GetLongLong() + _Right.GetLongLong());
//
//	return data;
//}


int main()
{
	CData d1, d2;

	d1.SetInt(10);
	d1.SetLongLong(10);

	d2.SetInt(20);
	d2.SetLongLong(20);
		
	CData d3 = d1 + d2;

	int a = 0, b = 0;

	a = 10;
	b = 20;

	int c = a + b;

	return 0;
}