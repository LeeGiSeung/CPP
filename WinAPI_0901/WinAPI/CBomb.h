#pragma once
#include "CObj.h"

#include "CSelectGDI.h"

class CBomb :
    public CObj
{

private:
    //폭탄이 터지기까지 걸리는 시간
    float LimitTime;
    //현재 시간
    float CurTime;
    BRUSH_TYPE Brush;
public:
    virtual void Tick() override;
    virtual void Render() override;

public:
    CBomb();
    ~CBomb();
};

