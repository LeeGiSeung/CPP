#pragma once
#include "CObj.h"

class CThorn :
    public CObj
{
private:
    float GrowTime;
    float DurationTime;

    Vec2        m_InitPos;
    float Distance;
    float Direction;
    UINT Flag = 0;

//가시 증가 
private:
    float xPlus;
    float yPlus;
    float xMinus;
    float yMinus;

public:
    void SetGrowTime(float _in) { GrowTime = _in; }
    void SetDurationTime(float _in) { DurationTime = _in; }
    void SetDistance(float _in) { Distance = _in; }

public:
    void Set_xPlus(float _in) { xPlus = _in; }
    void Set_yPlus(float _in) { yPlus = _in; }
    void Set_xMinus(float _in) { xMinus = _in; }
    void Set_yMinus(float _in) { yMinus = _in; }

public:
    virtual void Tick() override;
    virtual void Begin() override;
    virtual void Render() override;


public:
    CThorn();
    ~CThorn();
};

