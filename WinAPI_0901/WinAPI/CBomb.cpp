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
		//2초 전부터
		 if (CurTime >= (LimitTime - 0.5)) {
			 Brush = RED;

		 }
		 else {
			 Brush = BLUE;
		 }
	}

	//시간 지나면 폭파
	else if (CurTime >= LimitTime) {
		//레벨에서 객체 지우는거 여쭤보기
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
