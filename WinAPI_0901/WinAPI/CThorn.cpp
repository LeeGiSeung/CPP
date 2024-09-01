#include "pch.h"
#include "CThorn.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CObj.h"

CThorn::CThorn()
//식물 자라는 시간 초기화
//식물이 자란 후 유지 시칸
	:GrowTime(100),
	DurationTime(1000),
	Distance(50.f),
	Direction(1.0f),
	//마이너스 초기화
	xPlus(0.f),
	yPlus(0.f),
	xMinus(0.f),
	yMinus(0.f)
{
}

CThorn::~CThorn()
{
}

void CThorn::Begin()
{
	//시작 할때 위치 값
	m_InitPos = GetPos();
}

void CThorn::Tick()
{
	//##############################
	//GrowDistance 기준으로 이동
	//##############################
	// 
	//Vec2 Size = GetPos();

	////매초 자라는 길이
	//float GrowDistance = GrowTime * DT * Direction;	

	//Size.y += GrowDistance;

	////얼마나 자랐는지 줄어들었는지
	//float minusscale = abs(Size.y - m_InitPos.y);

	//if (minusscale > Distance && Direction == 1) {
	//	Direction = -1;
	//}
	//else if (minusscale > Distance && Direction == -1) {
	//	Direction = 1;
	//}

	//SetPos(Size);

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	//자라는 속도 = 해당 객체는 1 프레임에서 Delta Time * Distance 픽셀만큼 움직여야 한다.
	float GrowSpeed = DT *  Distance;

	//현재 자란 시간이 지속시간 보다 적을때
	if (Flag == 1) {
		if (Direction == 1) {
			if (yPlus > 0) {
				yPlus -= GrowSpeed;
			}
			else {
				GrowTime = 0;
				Direction = -1;
				Flag = 0;
			}
		}
		else if (Direction == -1) {
			if (yMinus > 0) {
				yMinus -= GrowSpeed;
			}
			else {
				GrowTime = 0;
				Direction = 1;
				Flag = 0;
			}
		}
	}

	else if (GrowTime < DurationTime) {
		if (Direction == 1) {
			Set_yPlus(GrowSpeed + yPlus);
			GrowTime++;
		}
		else if (Direction == -1) {
			Set_yMinus(GrowSpeed + yMinus);
			GrowTime++;
		}
	}
	else if (GrowTime >= DurationTime) {
		Flag = 1;
	}

}

void CThorn::Render()
{
	HDC dc = CEngine::GetInst()->GetSecondDC();

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(dc, vPos.x - vScale.x / 2.f - xMinus, vPos.y - vScale.y / 2.f - yMinus
		, vPos.x + vScale.x / 2.f + xPlus, vPos.y + vScale.y / 2.f + yPlus);

}