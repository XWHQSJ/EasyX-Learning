//////////////////////////////////////////////////////////////////////////
//л��˹�������Σ�Ҳ�е�Ƭ���ƣ��㷨�Ƚϼ�
//0.������� 3 ���� P[0]��P[1]��P[2]��
//1.������� 1 ���� P��
//2.���Ƶ� P��
//3.�������[0, 2] �ڵ����� n��
//4.�� P = P �� P[n] ���е㣻
//5.�ظ�ִ�в���(3)��(5) ����Ρ�
//////////////////////////////////////////////////////////////////////////

#include <graphics.h>
#include <conio.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));		//���������

	//����������㣨�����������Ҳ���Զ��壩
	POINT P[3] = { { 320, 50 },{ 120, 400 },{ 520, 400 } };
	//POINT P[3] = { { rand() % 640,rand() % 480 },{ rand() % 480,rand() % 480 },{ rand() % 480,rand() % 480 } };
	
	//����ĵ�
	POINT p = { rand()%640, rand()%480};

	initgraph(640, 480);

	int n;
	for (int i = 0; i < 30000; i++)
	{
		//ȡ[0,3)�е�������ʾ�����е�ĳ��Ԫ��
		n = rand() % 3;
		p.x = (p.x + P[n].x)/2;
		p.y = (p.y + P[n].y)/2;

		//�������ص�������С����״
		//setlinecolor(RED);
		//line(p.x - 2, p.y, p.x + 2, p.y);
		//line(p.x, p.y - 2, p.x, p.y + 2);
		//line(p.x - 2, p.y - 2, p.x + 2, p.y + 2);
		//line(p.x - 2, p.y + 2, p.x + 2, p.y - 2);
		//putpixel(p.x, p.y, RGB(rand() % 255, rand() % 255, rand() % 255));
		putpixel(p.x, p.y, BLUE);
	}

	getch();
	closegraph();

	return 0;
}