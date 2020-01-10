#pragma once
#include <time.h>
#include <easyx.h>
#include "LoadImage.h"
#include "TransParent.h"
#include "TransFormation.h"

class WindowMessage
{
public:
	int Recorde = -100;                                          // ��¼
    bool showFPS = false;                                        // ��ʾfps	
    bool ButtonId[4];                                            // �ر�����С����ť

private:
	float GetFps();								                 // ���� fps
	
public:
	void windowmessage(MOUSEMSG &m, int t = 0);                  // �ƶ�����
	void GetFunctionName(LPCTSTR Name, int t = 0);               // ��ȡ��������
};

extern WindowMessage Window_Message;