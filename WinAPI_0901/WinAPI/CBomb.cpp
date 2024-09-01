#include "pch.h"
#include "CBomb.h"

#include "CEngine.h"
#include "CTimeMgr.h"

#include "CSelectGDI.h"

#define RED BRUSH_TYPE::RED
#define GRAY BRUSH_TYPE::GRAY
#define BLUE BRUSH_TYPE::BLUE


CBomb::CBomb()
	:LimitTime(2.f),
	CurTime(0),
	Brush(BLUE)
{
}

CBomb::~CBomb()
{

}

void CBomb::Tick()
{

	CurTime += DT;

	if (CurTime < LimitTime) {
		//2�� ������
		 if (CurTime >= (LimitTime - 0.5)) {
			 Brush = RED;

		 }
		 else {
			 Brush = BLUE;
		 }
	}

	//�ð� ������ ����
	else if (CurTime >= LimitTime) {
		//�������� ��ü ����°� ���庸��
		Brush = GRAY;
	}
}

void CBomb::Render()
{

	HDC dc = CEngine::GetInst()->GetSecondDC();
	
	SELECT_BRUSH(Brush);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2
		, vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);

}
