#include "pch.h"
#include "CThorn.h"
#include "CEngine.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CLevelMgr.h"
#include "CLevel.h"
#include "CObj.h"

CThorn::CThorn()
//�Ĺ� �ڶ�� �ð� �ʱ�ȭ
//�Ĺ��� �ڶ� �� ���� ��ĭ
	:GrowTime(100),
	DurationTime(1000),
	Distance(50.f),
	Direction(1.0f),
	//���̳ʽ� �ʱ�ȭ
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
	//���� �Ҷ� ��ġ ��
	m_InitPos = GetPos();
}

void CThorn::Tick()
{
	//##############################
	//GrowDistance �������� �̵�
	//##############################
	// 
	//Vec2 Size = GetPos();

	////���� �ڶ�� ����
	//float GrowDistance = GrowTime * DT * Direction;	

	//Size.y += GrowDistance;

	////�󸶳� �ڶ����� �پ�������
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


	//�ڶ�� �ӵ� = �ش� ��ü�� 1 �����ӿ��� Delta Time * Distance �ȼ���ŭ �������� �Ѵ�.
	float GrowSpeed = DT *  Distance;

	//���� �ڶ� �ð��� ���ӽð� ���� ������
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