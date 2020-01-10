#include "WindowMessage.h"

WindowMessage Window_Message;

void WindowMessage::GetFunctionName(LPCTSTR Name, int t)
{
	setbkmode(TRANSPARENT);
	switch (option.WindowStyle)
	{
	case 0:  settextcolor(WHITE); break;
	case 1:  settextcolor(BLACK); break;
	}
	settextstyle(20, 0, _T("΢���ź�"), 0, 0, 200, 0, 0, 0);
	outtextxy(5, 2, _T("Calculator"));
	
	settextstyle(17, 0, _T("΢���ź�"), 0, 0, 20, false, false, false);
	if (showFPS)
	{
		MyChar fps[20];
		_stprintf_s(fps, _T("FPS : %.2lf"), GetFps());
		outtextxy(240, 6, fps);
	}

	//settextcolor(WHITE);
	settextstyle(30, 0, _T("΢���ź�"), 0, 0, 900, 0, 0, 0);
	outtextxy(40, 25, Name);

	if (t != -1)
	{
		if (transformation.help[0])settextcolor(RGB(0, 255, 255));
		else {
			switch (option.WindowStyle)
			{
			case 0:  settextcolor(WHITE); break;
			case 1:  settextcolor(BLACK); break;
			}
		}
		settextstyle(25, 0, _T("Segoe MDL2 Assets"), 0, 0, 900, false, false, false);
		outtextxy(05, 27, 0xE700);
	}

	if (ButtonId[0])
	{
		IMAGE Red = MyLoadImage.setimage(30, 30, RED);	        // ���û�ͼ
		putimage(376, 0, &Red);
	}
	else if (ButtonId[1])
	{
		IMAGE White = MyLoadImage.setimage(30, 30, WHITE);	    // ���û�ͼ
		MyPutimage.my_putimage(346, 0, &White, 0, 0, 1, 50, 0);
	}
	else if (ButtonId[2])
	{
		IMAGE White = MyLoadImage.setimage(30, 30, WHITE);	    // ���û�ͼ
		MyPutimage.my_putimage(316, 0, &White, 0, 0, 1, 50, 0);
	}
	if (!t || t == -1)
	{
		switch (option.WindowStyle)
		{
		case 0:  settextcolor(WHITE); break;
		case 1:  settextcolor(BLACK); break;
		}
		settextstyle(15, 0, _T("Segoe MDL2 Assets"), 0, 0, 100, false, false, false);
		outtextxy(384, 7, 0xE106);                      // �˳�ͼ��
		outtextxy(353, 7, 0xE108);                      // ��С��ͼ��
		if (t != -1)
		{
			settextstyle(18, 0, _T("Segoe MDL2 Assets"), 0, 0, 100, false, false, false);
			outtextxy(322, 5, 0xE713);
		}
		else {
			settextstyle(20, 0, _T("Segoe MDL2 Assets"), 0, 0, 100, false, false, false);
			outtextxy(322, 3, 0xE248);
		}
	}
}

void WindowMessage::windowmessage(MOUSEMSG &m, int t)
{
	//�����ƶ�
	if (m.x > 0 && m.x < 310 && m.y>0 && m.y < 30)
	{
		PostMessage(GetHWnd(), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(m.x, m.y));// ���ʹ��ڵ��ƶ���Ϣ
	}

	if (!t || t == -1) {

		//�رմ���
		if (m.x > 376 && m.x < 404 && m.y>0 && m.y < 30)
		{
			ButtonId[0] = true;
			if (m.uMsg == WM_LBUTTONUP)
			{
				SendMessage(GetHWnd(), WM_CLOSE, 0, 0);// ���͹رմ�����Ϣ
			}
		}
		else
			ButtonId[0] = false;

		//������С��
		if (m.x >= 346 && m.x <= 376 && m.y > 0 && m.y < 30)
		{
			ButtonId[1] = true;
			if (m.uMsg == WM_LBUTTONUP)
				ShowWindow(GetHWnd(), SW_SHOWMINIMIZED);
		}
		else
			ButtonId[1] = false;

		if (t != -1)
		{
			//ѡ��
			if (m.x >= 316 && m.x < 346 && m.y > 0 && m.y < 30)
			{
				ButtonId[2] = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					Recorde = transformation.software[0];
					transformation.software[0] = 18;
				}

			}
			else
				ButtonId[2] = false;
		}
		else
		{
			//ѡ��
			if (m.x >= 316 && m.x < 346 && m.y > 0 && m.y < 30)
			{
				ButtonId[2] = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					transformation.software[0] = Recorde;
				}

			}
			else
				ButtonId[2] = false;
		}
	}
}

// ����fps
float WindowMessage::GetFps()
{
	static int i(0);
	static DWORD oldtime = GetTickCount();
	static float fps(0);
	if (i > 8)
	{
		i = 0;
		int newtime = GetTickCount();
		int elapsedtime = newtime - oldtime;
		fps = 8 / (elapsedtime / 1000.0f);
		oldtime = newtime;
	}
	i++;
	return fps;
}