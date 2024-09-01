#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"

#include "CMissile.h"
#include "CBomb.h"
#include "CLevelMgr.h"
#include "CLevel.h"


CPlayer::CPlayer()
	: m_Speed(200.f)
	, m_AttSpeed(3.f)
	, m_AccTime(0.f)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Begin()
{
	m_AccTime = 1.f / m_AttSpeed;
}

void CPlayer::Tick()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESSED(LEFT))
		vPos.x -= DT * m_Speed;
	if (KEY_PRESSED(RIGHT))
		vPos.x += DT * m_Speed;
	if (KEY_PRESSED(UP))
		vPos.y -= DT * m_Speed;
	if (KEY_PRESSED(DOWN))
		vPos.y += DT * m_Speed;

	m_AccTime += DT;
	
	if (KEY_PRESSED(SPACE))
	{

		//3�ʰ� ������� ���
		if ( m_AttSpeed <= m_AccTime)
		{
			m_AccTime -= m_AttSpeed;

			// ���� ������ ������
			CLevel* pCurLevel = CLevelMgr::GetInst()->GetCurrentLevel();

			CBomb* pBomb = new CBomb;
			pBomb->SetPos(vPos);
			pBomb->SetScale(70.f, 70.f);

			// ������ �߰�
			pCurLevel->AddObject(pBomb);
			m_AccTime = 0.f;
		}
	}

	SetPos(vPos);
}