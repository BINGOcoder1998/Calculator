#include"PassWord.h"

PassWord password(200, 1, 0.5);

PassWord::PassWord()
{
	memset(buttons, 0, sizeof(buttons));                    // ������ʼ��
	memset(point, 0, sizeof(point));                        // ���ʼ��
	H = 190; S = 1; L = 0.5f;                               // ��ɫ������ʼ��
	number = 0;                                             // ���ų�ʼ��
	move = 400;                                             // ���ƶ������ʼ��
	mouse_isdown = false;                                   // ����Ƿ��³�ʼ��
	passwordcorrect = false;                                // �����Ƿ���ȷ��ʼ��  
	start = end = 0;                                        // ��ʱ������ʼ��
	control = false;                                        // ���Ƴ�ʼ��
	control_1 = false;
	DrawPassWordNumber = 0;                                 // �����������
	memset(StandardPassWord, 0, sizeof(StandardPassWord));  // �洢���������ʼ��
	memset(inputprompt, 0, sizeof(inputprompt));            // �洢������ʾ������ʼ��
	memset(initpassword1, 0, sizeof(initpassword1));        // �ݴ����������ʼ��
	memset(initpassword2, 0, sizeof(initpassword2));
    memset(on_button, 0, sizeof(on_button));                // ����Ƿ��ڰ����ϱ���
	memset(down_button, 0, sizeof(on_button));
	inputnumber = 0;                                        // ��������Ĵ���
	UpdatePassWord = false;                                 // �Ƿ���и�������
	No_UpdatePassWord = false;                              // ȡ����������
}
	
PassWord::PassWord(float h, float s, float l)
{
	H = h; S = s; L = l;
	memset(buttons, 0, sizeof(buttons));                    // ������ʼ��
	memset(point, 0, sizeof(point));                        // ���ʼ��
	number = 0;                                             // ���ų�ʼ��
	move = 400;                                             // ���ƶ������ʼ��
	mouse_isdown = false;                                   // ����Ƿ��³�ʼ��
	passwordcorrect = false;                                // �����Ƿ���ȷ��ʼ�� 
	start = end = 0;                                        // ��ʱ������ʼ��
	control = false;                                        // ���Ƴ�ʼ��
	control_1 = false;
	DrawPassWordNumber = 0;                                 // �����������
	memset(StandardPassWord, 0, sizeof(StandardPassWord));  // �洢���������ʼ��
	memset(inputprompt, 0, sizeof(inputprompt));            // �洢������ʾ������ʼ��
	memset(initpassword1, 0, sizeof(initpassword1));        // �ݴ����������ʼ��
	memset(initpassword2, 0, sizeof(initpassword2));
	memset(on_button, 0, sizeof(on_button));                // ����Ƿ��ڰ����ϱ���
	memset(down_button, 0, sizeof(on_button));
	inputnumber = 0;                                        // ��������Ĵ���
	UpdatePassWord = false;                                 // �Ƿ���и�������
	No_UpdatePassWord = false;                              // ȡ����������
}

void PassWord::drawcolor()
{
	float l(0.8f);
	for (int y = 0; y <= 600; y++)
	{
		l -= 0.0008f;
		setlinecolor(HSLtoRGB(H, S, l));
		line(0, y, 406, y);
	}
}

void PassWord::update(int k)
{
	// ���������Ϣ
	MOUSEMSG m;	
	// ����Ƿ��������Ϣ
	while (MouseHit())	
	{
		m = GetMouseMsg();

		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++)
			{
				if (m.x > 92 + 100 * i &&m.x < 110 + 100 * i && m.y>250 + 100 * j && m.y < 265 + 100 * j)
				{
					if(!buttons[i][j].mouse_down)  // ���û�а������
						buttons[i][j].button= true;
					
					if (m.mkLButton) // �������
					{
						mouse_isdown = true; //��갴��
						if (!buttons[i][j].mouse_down)// û�а���
						{
							buttons[i][j].pointnumber = number++; // ��ı��
							buttons[i][j].mouse_down = true; // �������갴��
							
							X = 92 + 100 * i + 9; //��¼ѡ�е������
							Y = 250 + 100 * j + 9;
							point[buttons[i][j].pointnumber].X = X; // ��˳���¼��갴�µĵ������
							point[buttons[i][j].pointnumber].Y = Y;
						}
					}
				}
				else
					buttons[i][j].button= false;

				if (buttons[i][j].mouse_down) // ��갴�� 
				{
					m_X = m.x; // ��¼�������
					m_Y = m.y;
				}

				if (!m.mkLButton&&mouse_isdown)
				{
					mouse_isdown = false;
					CheckPassWord();
					DrawPassWordNumber++;
					start = clock(); // ��ʱ��ʼ
					control = true;
					if(!passwordcorrect)control_1 = true;
				}
			}
		}
		if (m.x > 225 && m.x < 285 && m.y>545 && m.y < 565)
		{
			on_button[2] = true;
			if (m.uMsg == WM_LBUTTONUP)
			{
				UpdatePassWord = true;
				No_UpdatePassWord = false;
			}
		}
		else on_button[2] = false;

		if (k == -1)
		{
			if (m.x > 150 && m.x < 250 && m.y>520 && m.y < 550)
			{
				on_button[4] = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					No_UpdatePassWord = true;
					UpdatePassWord = false;
				}
			}
			else on_button[4] = false;
		}

		if (k != -1)
		{
			//�رմ���
			if (m.x > 376 && m.x < 406 && m.y>0 && m.y < 30)
			{
				on_button[5] = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					SendMessage(GetHWnd(), WM_CLOSE, 0, 0);// ���͹رմ�����Ϣ
				}
			}
			else
				on_button[5] = false;
		}
	}

	//�������ƶ�
	move = move > 0 ? move - 50 : move;
}

void PassWord::drawscreen(int k)
{
	BeginBatchDraw();

	setbkmode(TRANSPARENT);
	setfillstyle(BS_SOLID);
	settextstyle(60, 0, _T("΢���ź�"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

	PassWord::drawcolor();  // �汳��ɫ

	IMAGE black = MyLoadImage.setimage(406, 600, RGB(0, 0, 0));	// ���û�ͼ
	MyPutimage.my_putimage(0, 0, &black, RGB(255, 255, 255), 0, 1, 20, 0);

	settextcolor(WHITE);
	settextstyle(25, 0, _T("΢���ź�"), 0, 0, 400, 0, 0, 0);
	RECT r = { 0, 100 + move, 400, 200 + move };
	if (mouse_isdown)
		drawtext(_T("������ɺ����ɿ�����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	else
		if (!DrawPassWordNumber)
			drawtext(_T("��������Ľ���ͼ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		else
			drawtext(inputprompt, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 8); // �����ߵĸ�ʽ
	if (mouse_isdown || end - start < 1000) {
		if (!mouse_isdown&&control)
		{
			end = clock();
			passwordcorrect == false ? setlinecolor(RGB(250, 0, 250)) : setlinecolor(WHITE);
			if (passwordcorrect)move -= 40;
		}
		else
			setlinecolor(WHITE);
		for (int i = 0; i < 8; i++)
		{
			if (point[i].X&&point[i + 1].X)
				line(point[i].X, point[i].Y + move, point[i + 1].X, point[i + 1].Y + move);
		}
	}
	if (mouse_isdown)
	{
		setlinecolor(WHITE);
		line(X, Y, m_X, m_Y);// ����
	}
	if (end - start > 900 && control)
	{
		control = false;
		memset(initpassword1, 0, sizeof(initpassword1));        // ��ʱ�洢���������ʼ��
		memset(buttons, 0, sizeof(buttons));                    // ������ʼ��
		memset(point, 0, sizeof(point));                        // ���ʼ��
		number = 0;                                             // ���ų�ʼ��
		mouse_isdown = false;                                   // ����Ƿ��³�ʼ��  
	}

	settextstyle(18, 0, _T("Segoe MDL2 Assets"), 0, 0, 900, false, false, false);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//���õ����ɫ
			COLORREF rgb = (buttons[i][j].button == true) ? RGB(250, 0, 250) : WHITE;
			settextcolor(rgb);
			outtextxy(92 + 100 * i, 250 + 100 * j + move, 0xE1F5); // �����
		}
	}

	if (k != -1)
	{
		//���õ����ɫ
		on_button[3] == true ? settextcolor(HSLtoRGB(190, 1, 0.5f)) : settextcolor(WHITE);
		settextstyle(18, 0, _T("΢���ź�"), 0, 0, 100, 0, 1, 0);
		RECT r1 = { 100, 530 + move, 200, 580 + move };
		drawtext(_T("��������"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		(on_button[2] == true) ? settextcolor(HSLtoRGB(190, 1, 0.5f)) : settextcolor(WHITE);
		RECT r2 = { 210, 530 + move, 300, 580 + move };
		drawtext(_T("�޸�����"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		if (on_button[5])
		{
			IMAGE Red = MyLoadImage.setimage(30, 30, RED);	        // ���û�ͼ
			putimage(370, 0, &Red);
		}
		settextcolor(WHITE);
		settextstyle(15, 0, _T("Segoe MDL2 Assets"), 0, 0, 100, false, false, false);
		outtextxy(378, 7, 0xE106);                      // �˳�ͼ��
	}

	if (k > 0)
	{
		settextstyle(20, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
		MyChar ZFC[10], ZFC1[40];
		_stprintf(ZFC, _T("%d"), k);
		_tcscpy(ZFC1, _T("�����ƵĴ������̫�࣬�� "));
		_tcscat(ZFC1, ZFC);
		_tcscat(ZFC1, _T(" �������"));
		RECT r2 = { 0, 100 + move, 400, 300 + move };
		drawtext(ZFC1, &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	if (k == -1)
	{
		settextcolor(WHITE);
		settextstyle(20, 0, _T("΢���ź�"), 0, 0, 100, 0, 0, 0);
		RECT r2 = { 0, 100 + move, 400, 300 + move };
		drawtext(_T("�����������"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		settextstyle(25, 0, _T("΢���ź�"), 0, 0, 900, 0, 0, 0);
		MyChar ButtonText[] = { _T("ȡ��") };
		on_button[4] == false ? setfillcolor(HSLtoRGB(200, 1, 0.5)) : setfillcolor(HSLtoRGB(180, 1, 0.5));
		solidroundrect(150, 520, 250, 550, 5, 5);
		settextcolor(WHITE);
		outtextxy(183 , 523, ButtonText);
	}

	EndBatchDraw();
}

void PassWord::LoadPassWord()
{
	FILE *p;
	if (!_tfopen_s(&p, _T(address), _T("r")))  // ���ļ�
	{ 
		fwscanf(p, _T("%s"), StandardPassWord);// ��ȡ
		fclose(p);
	}
}

void PassWord::CheckPassWord()
{
	for (int i = 0; i < 9; i++)
	{
		MyChar ZFC[30];
		_stprintf(ZFC, _T("%d"), point[i].X * 10 + point[i].Y * 2);
		_tcscat(initpassword1, ZFC);
		
	}
	if (_tcscmp(initpassword1, StandardPassWord) == 0) // �����������ȷ
	{
		_tcscpy(inputprompt, _T("��ϲ����ͼ��������ȷ"));
		passwordcorrect = true;
		memset(initpassword1, 0, sizeof(initpassword1));
		if (UpdatePassWord)  // Ҫ��������
		{
			inputnumber = 0;
			memset(StandardPassWord, 0, sizeof(StandardPassWord));
			initfunction(0);
		}
	}
	else // ������������
	{
		_tcscpy(inputprompt, _T("ͼ�����ƴ���������"));
		passwordcorrect = false;
	}
}

void PassWord::SavePassWord()
{
	if (!_tcslen(StandardPassWord)) // ���û������
	{
		for (int i = 0; i < 9; i++)
		{
			MyChar ZFC[30];
			_stprintf(ZFC, _T("%d"), point[i].X * 10 + point[i].Y * 2);
			_tcscat(StandardPassWord, ZFC);
		}
		//����������
		FILE *p;
		if (!_tfopen_s(&p, _T(address), _T("w"))) // ���ļ�
		{
			fwprintf(p, _T("%s"), StandardPassWord);
			fclose(p);
		}
	}
}

bool PassWord::Check()
{
	return _tcslen(StandardPassWord) == 0 ? true : false;
}

void PassWord::update_establish_password()
{
	// ���������Ϣ
	MOUSEMSG m;
	// ����Ƿ��������Ϣ
	while (MouseHit())
	{
		m = GetMouseMsg();
		
		for (int i = 0; i < 2; i++)
		{
			if (m.x > 80 + 140 * i&&m.x < 180 + 140 * i&&m.y>520 && m.y < 550)
			{
				if (!i || (i&&number >= 2))
				{
					on_button[i] = true;
					if (m.uMsg == WM_LBUTTONUP)
					{
						down_button[i] = true;
						if (i == 1)
							initpassword();
						initfunction(i);
					}
				}
			}
			else
				on_button[i] = false;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (m.x > 92 + 100 * i &&m.x < 110 + 100 * i && m.y>250 + 100 * j && m.y < 265 + 100 * j)
				{
					if (!buttons[i][j].mouse_down)  // ���û�а������
						buttons[i][j].button = true;

					if (m.mkLButton) // �������
					{
						mouse_isdown = true; //��갴��
						if (!buttons[i][j].mouse_down)// û�а���
						{
							buttons[i][j].pointnumber = number++; // ��ı��
							buttons[i][j].mouse_down = true; // �������갴��

							X = 92 + 100 * i + 9; //��¼ѡ�е������
							Y = 250 + 100 * j + 9;
							point[buttons[i][j].pointnumber].X = X; // ��˳���¼��갴�µĵ������
							point[buttons[i][j].pointnumber].Y = Y;
						}
					}
				}
				else
					buttons[i][j].button = false;

				if (buttons[i][j].mouse_down) // ��갴�� 
				{
					m_X = m.x; // ��¼�������
					m_Y = m.y;
				}

				if (!m.mkLButton&&mouse_isdown)
				{
					mouse_isdown = false;
				}
			}
		}
	}

	//�������ƶ�
	move = move > 0 ? move - 50 : move;
}

void PassWord::show_establish_password()
{
	BeginBatchDraw();

	setbkmode(TRANSPARENT);
	setfillstyle(BS_SOLID);
	settextstyle(60, 0, _T("΢���ź�"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

	PassWord::drawcolor();  // �汳��ɫ

	IMAGE black = MyLoadImage.setimage(406, 600, RGB(0, 0, 0));	// ���û�ͼ
	MyPutimage.my_putimage(0, 0, &black, RGB(255, 255, 255), 0, 1, 20, 0);

	settextstyle(18, 0, _T("Segoe MDL2 Assets"), 0, 0, 900, false, false, false);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//���õ����ɫ
			COLORREF rgb = (buttons[i][j].button == true) ? RGB(250, 0, 250) : WHITE;
			settextcolor(rgb);
			outtextxy(92 + 100 * i, 250 + 100 * j + move, 0xE1F5); // �����
		}
	}

    settextcolor(WHITE);
	settextstyle(25, 0, _T("΢���ź�"), 0, 0, 400, 0, 0, 0);
	RECT r = { 0, 100 + move, 400, 200 + move };
	if (inputnumber == 1)
	{
		if (mouse_isdown)
			drawtext(_T("������ɺ����ɿ�����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		else
			drawtext(inputprompt, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	}
	else if (inputnumber == 2)
	{
		drawtext(_T("����ͼ���½��ɹ���"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		static int a(0);
		a++;
		if (a > 25)inputnumber = 3;
	}
	else
	{
		if (mouse_isdown)
			drawtext(_T("������ɺ����ɿ�����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		else
			drawtext(_T("��������µĽ���ͼ��������������������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	RECT r1 = { 0, 130 + move, 400, 230 + move };
	settextstyle(18, 0, _T("΢���ź�"), 0, 0, 400, 0, 0, 0);
	drawtext(_T("���μ��������룬���Ǻ��޷��һ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 8); // �����ߵĸ�ʽ
	if (mouse_isdown)
	{
		setlinecolor(WHITE);
		line(X, Y, m_X, m_Y);// ����
	}

	if (!down_button[0] && !down_button[1])
	{
		for (int i = 0; i < 8; i++)
		{
			setlinecolor(WHITE);
			if (point[i].X&&point[i + 1].X)
				line(point[i].X, point[i].Y, point[i + 1].X, point[i + 1].Y);
		}
	}
	settextstyle(25, 0, _T("΢���ź�"), 0, 0, 900, 0, 0, 0);
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1); // �����ߵĸ�ʽ
	MyChar ButtonText[][5] = { {_T("�ػ�")},{_T("ȷ��")} };
	for (int i = 0; i < 2; i++)
	{
		COLORREF rgb = (on_button[i]==false) ? HSLtoRGB(200, 1, 0.5) : HSLtoRGB(180, 1, 0.5);
		setfillcolor(rgb);
		solidroundrect(80 + 140 * i, 520 + move, 180 + 140 * i, 550 + move, 5, 5);
		settextcolor(WHITE);
		outtextxy(112 + 140 * i, 523 + move, ButtonText[i]);

	}
	
	EndBatchDraw();
}

void PassWord::initpassword()
{
	for (int i = 0; i < 9; i++)
	{
		MyChar ZFC[50];
		_stprintf(ZFC, _T("%d"), point[i].X * 10 + point[i].Y * 2);
		if(!inputnumber) _tcscat(initpassword1, ZFC);
		else _tcscat(initpassword2, ZFC);
	}

	if (inputnumber)
	{
		if (_tcscmp(initpassword1, initpassword2) == 0) // ����������ͬ
		{
			SavePassWord(); // ��������
			inputnumber = 2;
		}
		else
		{
			inputnumber = 1;
			_tcscpy(inputprompt, _T("���λ��Ƶ�ͼ������ͬ�������»��ơ�"));
		}
	}

	if (!inputnumber) {
		inputnumber = 1;
		_tcscpy(inputprompt, _T("���ٴλ���ͼ������ȷ��"));
	}
}

void PassWord::initfunction(int num)
{
	memset(buttons, 0, sizeof(buttons));                    // ������ʼ��
	memset(point, 0, sizeof(point));                        // ���ʼ��
	number = 0;                                             // ���ų�ʼ��
	mouse_isdown = false;                                   // ����Ƿ��³�ʼ��               
	memset(on_button, 0, sizeof(bool) * 2);                 // ����Ƿ��ڰ����ϱ���
	memset(down_button, 0, sizeof(bool) * 2);                              
	if (!inputnumber || inputnumber == 1)                   //��һ������
		memset(initpassword2, 0, sizeof(initpassword2));    // �ݴ�ڶ������������
	if (inputnumber == 2)
	{
		memset(inputprompt, 0, sizeof(inputprompt));        // ��ʼ��������ʾ
		memset(initpassword1, 0, sizeof(initpassword1));    // �ݴ����������ʼ��
		memset(initpassword2, 0, sizeof(initpassword2));    // ����ʹ��
		DrawPassWordNumber = 0;                             // ���ƴ�����ʼ��
	}
	if (!num) //���ػ水ť
	{
		inputnumber = 0;                                    // ��������Ĵ���
		memset(initpassword1, 0, sizeof(initpassword1));    // �ݴ����������ʼ��
	    memset(initpassword2, 0, sizeof(initpassword2));
	}
}

void PassWord::InputPassWordNumbers()
{
	if (DrawPassWordNumber > option.DrawPasswordNumbers && control_1)
	{
		control_1 = false;
		static int a(-1); a++;
		int second[10] = { 10,30,60,180,500,1800,3600,3600 * 24,3600 * 24 * 24,3600 * 24 * 24 * 24 * 24 };
		clock_t start(0), end(0), sum(0);
		start = clock();
		while (true)
		{
			end = clock();
			sum = (end - start) / 1000;
			drawscreen(second[a] - sum);
			if (sum > second[a])
				break;
			Sleep(option.Performance);
		}
	}
}

void PassWord::UpdatePassWordFuction()
{
	if (UpdatePassWord)                           // ��������
	{
		while (true)
		{
			drawscreen(-1);                       // ��ʾ����
			update(-1);                           // ��������
			if (passwordcorrect ||No_UpdatePassWord)
				break;
			Sleep(option.Performance);
		}
		passwordcorrect = false;
		DrawPassWordNumber = 0;
	}
}

void PassWord::FoundPassWord()
{
	if (Check())                                      // û������
	{
		UpdatePassWord = false;
		while (inputnumber <= 2)                      // ����������
		{
			update_establish_password();
			show_establish_password();
			Sleep(option.Performance);
		}
	}
}

bool PassWord::PassWordRight()
{
	if (passwordcorrect &&                            // ������ȷ
		!control &&                             
		!UpdatePassWord)                              // ����������
		 return true;
	else return false;
}