#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
	int gd = DETECT, gm, tx, ty, sx, sy, m;
	initgraph(&gd, &gm, NULL);
	int l;
	cout << "perform operation on equilateral or rohmbas=enter 1 for euilateral enter 2 for rhombas" << endl;
	cin >> l;
	if (l == 1)
	{
		int gd = DETECT, gm, tx, ty, sx, sy, m;
		int a[3][3];
		cout << "enter co ordinate of equilateral triangel=x1,y1=" << endl;
		cin >> a[0][0] >> a[0][1];
		cout << "enter co ordinate of equilateral x2,y2" << endl;
		cin >> a[1][0] >> a[1][1];
		cout << "enter co ordinate of equilateral x3,y3=" << endl;
		cin >> a[2][0] >> a[2][1];
		setcolor(WHITE);
		line(a[0][0], a[0][1], a[1][0], a[1][1]);
		line(a[1][0], a[1][1], a[2][0], a[2][1]);
		line(a[2][0], a[2][1], a[0][0], a[0][1]);
		delay(100);
		cout << "enter 1 for translation=\nenter 2 for scalling=\nenter 3 for rotation=" << endl;
		int c;
		cout << "enter your choice" << endl;
		cin >> c;
		switch (c)
		{
		case 1: {int b[3][3], c[3][3];
			cout << "enter translation factor tx,ty" << endl;
			cin >> tx >> ty;
			b[2][0] = tx;
			b[2][1] = ty;
			b[0][0] = b[1][1] = b[2][2] = 1;
			b[0][1] = b[0][2] = b[1][2] = b[1][0] = 0;


			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < 3; k++)
					{
						c[i][j] = c[i][j] + a[i][k] * b[k][j];
					}

				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << c[i][j] << "\t";
				}
			}

			setcolor(RED);
			line(c[0][0], c[0][1], c[1][0], c[1][1]);
			line(c[1][0], c[1][1], c[2][0], c[2][1]);
			line(c[2][0], c[2][1], c[0][0], c[0][1]);
			delay(10);
			break; }
		case 2:
		{float l[3][3];
		cout << "entee scaling  factor sx,sy=" << endl;
		cin >> l[0][0] >> l[1][1];
		l[2][2] = 1;
		l[0][1] = l[0][2] = l[1][2] = l[1][0] = l[2][0] = l[2][1] = 0;
		float m[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m[i][j] = 0;
				for (int k = 0; k < 3; k++)
				{
					m[i][j] = m[i][j] + a[i][k] * l[k][j];
				}

			}
		}
		setcolor(RED);
		line(m[0][0], m[0][1], m[1][0], m[1][1]);
		line(m[1][0], m[1][1], m[2][0], m[2][1]);
		line(m[2][0], m[2][1], m[0][0], m[0][1]);
		delay(1000);
		break; }
		case 3:

		{
			float b[3][3];
			float  z;
			cout << "enter angle of rotation=" << endl;
			cin >> m;
			z = (m * 3.14) / 180;
			b[0][0] = b[1][1] = cos(z);
			b[0][1] = (-(sin(z)));
			b[1][0] = sin(z);
			b[2][2] = 1;
			b[2][0] = b[2][1] = b[0][2] = b[1][2] = 0;
			float c[3][3];
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < 3; k++)
					{
						c[i][j] = c[i][j] + a[i][k] * b[k][j];
					}
				}

			}

			setcolor(RED);
			line(c[0][0], c[0][1], c[1][0], c[1][1]);
			line(c[1][0], c[1][1], c[2][0], c[2][1]);
			line(c[2][0], c[2][1], c[0][0], c[0][1]);
			delay(1000);
			break;
		}
		}
	}
	else
	{
		int x  [4][4];
		cout << "enter co-ordinate of rhombus x1,y1=" << endl;
		cin >> x[0][0] >> x[0][1];
		cout << "enter co-ordinate of rhombus x2,y2=" << endl;
		cin >> x[1][0] >> x[1][1];
		cout << "enter co-ordinate of rhombus x3,y3=" << endl;
		cin >> x[2][0] >> x[2][1];
		cout << "enter co-ordinate of rhombus x2,y2=" << endl;
		cin >> x[3][0] >> x[3][1];
		setcolor(BLUE);
		line(x[0][0], x[0][1], x[1][0], x[1][1]);
		line(x[1][0], x[1][1], x[2][0], x[2][1]);
		line(x[2][0], x[2][1], x[3][0], x[3][1]);
		line(x[3][0], x[3][1], x[0][0], x[0][1]);
		delay(1000);
		cout << "enter 1 for translation=\nenter 2 for scalling=\nenter 3 for rotation=" << endl;
		int c;
		cout << "enter your choice" << endl;
		cin >> c;
		switch (c)
		{
		case 1: {int b[4][4], c[4][4];
			cout << "enter translation factor tx,ty" << endl;
			cin >> tx >> ty;
			b[3][0] = tx;
			b[3][1] = ty;
			b[0][0] = b[1][1] = b[2][2] = b[3][3] = 1;
			b[0][1] = b[0][2] = b[1][2] = b[1][0] = b[0][3] = b[1][3] = b[2][0] = b[2][1]=b[2][3] = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < 4; k++)
					{
						c[i][j] = c[i][j] + x[i][k] * b[k][j];
					}

				}
			}
			setcolor(RED);
			line(c[0][0], c[0][1], c[1][0], c[1][1]);
			line(c[1][0], c[1][1], c[2][0], c[2][1]);
			line(c[2][0], c[2][1], c[3][0], c[3][1]);
			line(c[3][0], c[3][1], c[0][0], c[0][1]);
			delay(100);
			break; }
		case 2: {int b[4][4], c[4][4];
			cout << "enter scalling factor factor sx,sy" << endl;
			cin >> sx >> sy;
			b[0][0] = sx;
			b[1][1] = sy;
			b[2][2] = b[3][3] = 1;
			b[0][1] = b[0][2] = b[1][2] = b[1][0] = b[0][3] = b[1][3] = b[2][0] = b[2][1] = 0;
			b[3][0] = b[3][1]=b[2][3] = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < 4; k++)
					{
						c[i][j] = c[i][j] + x[i][k] * b[k][j];
					}
				}
			}
			setcolor(RED);
			line(c[0][0], c[0][1], c[1][0], c[1][1]);
			line(c[1][0], c[1][1], c[2][0], c[2][1]);
			line(c[2][0], c[2][1], c[3][0], c[3][1]);
			line(c[3][0], c[3][1], c[0][0], c[0][1]);
			delay(100);
			break; }
		case 3: {
			float b[4][4], c[4][4];
			float  z;
			cout << "enter angle of rotation=" << endl;
			cin >> m;
			z = (m * 3.14) / 180;
			b[0][0] =b[1][1]=cos(z);
			b[0][1] = (-(sin(z)));
			b[1][0] = sin(z);
			b[2][2] = b[3][3] = 1;
            b[0][2] = b[1][2] = b[0][3] = b[1][3] = b[2][0] = b[2][1] = 0;
			b[3][0] = b[3][1] = b[2][3] = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < 4; k++)
					{
						c[i][j] = c[i][j] + x[i][k] * b[k][j];
					}
				}
			}
			setcolor(RED);
			line(c[0][0], c[0][1], c[1][0], c[1][1]);
			line(c[1][0], c[1][1], c[2][0], c[2][1]);
			line(c[2][0], c[2][1], c[3][0], c[3][1]);
			line(c[3][0], c[3][1], c[0][0], c[0][1]);

			delay(100);
			break; }
		}
	}
	getch();
	closegraph();
	return 0;
}
