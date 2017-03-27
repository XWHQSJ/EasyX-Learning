//////////////////////////////////////////////////////////////////////////
/*ʹ��EasyX���ƿƺ�ѩ��
*�̻������㷨�Ǻ���
*/
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <time.h>

//�ƺ������㷨
void koch(double x0, double y0, double x1, double y1, int k)
{
	//�ƺ����ߵ�5������
	double x2, y2, x3, y3, x4, y4;
	x2 = 2.0 / 3 * x0 + 1.0 / 3 * x1;
	y2 = 2.0 / 3 * y0 + 1.0 / 3 * y1;
	x3 = 1.0 / 3 * x0 + 2.0 / 3 * x1;
	y3 = 1.0 / 3 * y0 + 2.0 / 3 * y1;
	x4 = 1.0 / 2 * (x0 + x1) + sqrt(3.0) / 6 * (y1 - y0);	//��ѧ��ʽ�Ƶ�
	y4 = 1.0 / 2 * (y0 + y1) - sqrt(3.0) / 6 * (x1 - x0);	//��ѧ��ʽ�Ƶ�

	//���������������1�����еݹ����
	if (k > 1)
	{
		koch(x0, y0, x2, y2, k - 1);
		koch(x2, y2, x4, y4, k - 1);
		koch(x4, y4, x3, y3, k - 1);
		koch(x3, y3, x1, y1, k - 1);
	}
	//�����������Ϊһ��ֱ�ӻ��ƿƺ�����
	else
	{
		//�����Ƶ�ÿ�����ߵ���ɫ����Ϊ�����ɫ
		setlinecolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		line(x0, y0, x2, y2);
		line(x2, y2, x4, y4);
		line(x4, y4, x3, y3);
		line(x3, y3, x1, y1);
	}
}

//���ƺ����߷�װΪ�ƺ�ѩ��
void kochsnow(int n)
{
	koch(50, 120, 450, 120, n);
	koch(450, 120, 250, 120 + 200 * sqrt(3.0), n);
	koch(250, 120 + 200 * sqrt(3.0), 50, 120, n);
}

int main()
{
	srand((unsigned)time(NULL));	//���������

	initgraph(640, 480);			//���ڳ�ʼ��

	//���õ����Ĵ���
	int n;
	char s[10];
	InputBox((LPTSTR)s, 10, _T("����������Ĵ���(<=9)"));
	sscanf(s, "%d", &n);

	//���ÿƺ�ѩ������
	kochsnow(n);

	getch();
	closegraph();

	return 0;
}