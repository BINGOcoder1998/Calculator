#include "LoadImage.h"

My_LoadImage MyLoadImage;

IMAGE  My_LoadImage::setimage(int wigth, int height, COLORREF rgb, int a, int b)
{
	IMAGE blacks(wigth, height);	// ���� img ����

	SetWorkingImage(&blacks);		// ���û�ͼĿ��Ϊ img ����
	setfillcolor(rgb);
	solidroundrect(0, 0, wigth, height, a, b);

	SetWorkingImage();				// ���û�ͼĿ��Ϊ��ͼ����

	return blacks;
}