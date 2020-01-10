#pragma once
#include <cmath>
#include <ctime>
#include <easyx.h>
#include "Option.h"
#include "Standard.h"
#include "LoadImage.h"
#include "TransParent.h"
#include "WindowMessage.h"
#include "Transformation.h"

class Set
{
private:
	// �������»������µ����겻��ȷ
#define H_XS (int)round(transformation.fly1/(double)40)			
    // ѡ���ĸ����ܵı�־
	bool buttons[101] = { false };
	// �����ɫ����						
	int colors = 0;
	// ��ʱ����									
	clock_t start = 0, end = 0;
	// ���ã��������йصĸ���
	void updatewithinput0();
	// ���ã���ʾ����							
	void showscreen0();
	// ���û�����									
	void setline();
public:
	Set() {};
	~Set() {};
	void SetFuction(int &);
};

extern Set set;
