#include "pch.h"
#include "CLevelMgr.h"
#include "CLevel.h"
#include "CEngine.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CMissile.h"
#include "CThorn.h"

CLevelMgr::CLevelMgr()
    : m_arrLevel{}
    , m_CurLevel(nullptr)
{

}

CLevelMgr::~CLevelMgr()
{
    Delete_Array(m_arrLevel);
}

void CLevelMgr::Init()
{
    Vec2 vResolution = CEngine::GetInst()->GetResolution();

	// 레벨 제작       
    CLevel* pLevel = new CLevel;

    // Player 생성
    CObj* pObject = new CPlayer;
    pObject->SetPos(1200.f, vResolution.y / 2.f);
    pObject->SetScale(50.f, 50.f);    
    pLevel->AddObject(pObject);

    // Monster 생성
    CMonster* pMonster = new CMonster;
    pMonster->SetPos(600.f, 300.f);
    pMonster->SetScale(100.f, 100.f);

    pMonster->SetDistance(200.f);
    pMonster->SetSpeed(300.f);

    //pLevel->AddObject(pMonster);

    //가시 OBJ 추가
    CThorn* pThorn = new CThorn;
    pThorn->SetPos(250.f, 300.f);
    pThorn->SetScale(50.f, 50.f);

    pLevel->AddObject(pThorn);


    //DurationTime의 기본값은 1000임
    CThorn* pThorn1 = new CThorn;
    pThorn1->SetPos(450.f, 300.f);
    pThorn1->SetScale(50.f, 50.f);
    pThorn1->SetDurationTime(1500.f);
    pThorn1->SetDistance(100.f);

    pLevel->AddObject(pThorn1);

    CThorn* pThorn3 = new CThorn;
    pThorn3->SetPos(600.f, 500.f);
    pThorn3->SetScale(50.f, 50.f);
    pThorn3->SetDurationTime(1700.f);
    pThorn3->SetDistance(170.f);

    pLevel->AddObject(pThorn3);

    CThorn* pThorn5 = new CThorn;
    pThorn5->SetPos(750.f, 500.f);
    pThorn5->SetScale(50.f, 50.f);
    pThorn5->SetDurationTime(1250.f);
    pThorn5->SetDistance(300.f);

    pLevel->AddObject(pThorn5);

    CThorn* pThorn2 = new CThorn;
    pThorn2->SetPos(900.f, 300.f);
    pThorn2->SetScale(50.f, 50.f);
    pThorn2->SetDurationTime(1200.f);
    pThorn2->SetDistance(150.f);

    pLevel->AddObject(pThorn2);

    CThorn* pThorn4 = new CThorn;
    pThorn4->SetPos(1050.f, 450.f);
    pThorn4->SetScale(50.f, 50.f);
    pThorn4->SetDurationTime(500.f);
    pThorn4->SetDistance(700.f);

    pLevel->AddObject(pThorn4);

    m_CurLevel = m_arrLevel[(UINT)LEVEL_TYPE::START] = pLevel;
    m_CurLevel->Begin();
}

void CLevelMgr::Progress()
{
    if (nullptr == m_CurLevel)
        return;

    m_CurLevel->Tick();
    m_CurLevel->FinalTick();   
}

void CLevelMgr::Render()
{
    m_CurLevel->Render();
}