#pragma once
#include "CObj.h"

#include "CSelectGDI.h"

class CBomb :
    public CObj
{

private:
    //��ź�� ��������� �ɸ��� �ð�
    float LimitTime;
    //���� �ð�
    float CurTime;
    BRUSH_TYPE Brush;
public:
    virtual void Tick() override;
    virtual void Render() override;

public:
    CBomb();
    ~CBomb();
};

