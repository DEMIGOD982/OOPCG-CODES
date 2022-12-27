/*Write C++ program to draw a concave polygon and fill it with desired color using scan fill
algorithm.*/
#include<math.h>
#include<iostream>
#include<graphics.h>
using namespace std;

class initial
{
public:
	int c;
	void check(int z)
	  {
			c = z;
      }
};

class action:public initial
{
public:
	int a[20][2], x[20];
	float slope[20];
	int temp,k,y,dy,dx,f;
	void look()
	{
		f = c;
		if (f < 3)
		{
			cout << "sorry polygon need at least three edges" << endl;

		}
		else
		{
			for (int i = 0; i < f; i++)
			{
				cout << "enter co-ordinate of edges x1,y1=" << endl;
				cin >> a[i][0] >> a[i][1];
				a[f][0] = a[0][0];
				a[f][1] = a[0][1];
			}
		}
		int gd = DETECT, gm;
		initgraph(&gd, &gm, 0);
		for (int i = 0; i < f; i++)
		{
			line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
		}
		for (int i = 0; i < f; i++)
		{
			dy = a[i + 1][1] - a[i][1];
			dx = a[i + 1][0] - a[i][0];
			if (dy == 0)
			{
				slope[i] = 1.0;
			}
			if (dx == 0)
			{
				slope[i] = 0;
			}
			if ((dy != 0) && (dx != 0))
			{
				slope[i] = (float)dx / dy;
			}
		}
		for (y = 0; y < 480; y++)
		{
			k = 0;
			for (int i = 0; i < f; i++)
			{
				if ((a[i][1] <= y) && (a[i + 1][1] > y) || (a[i][1] > y) && (a[i + 1][1] <= y))
				{
					x[k] = (int)(a[i][0] + slope[i] * (y - a[i][1]));//intersection find out formula
					k++;
				}
			}
			for (int j = 0; j < k - 1; j++)
			{
				for (int i = 0; i < k - 1; i++)
				{
					if (x[i] > x[i + 1])
					{
						temp = x[i];
						x[i] = x[i + 1];
						x[i + 1] = temp;
					}
				}
			}
			setcolor(BLUE);
			for (int i = 0; i < k; i += 2)
			{
				line(x[i], y, x[i + 1] + 1, y);
				delay(20);
			}
		}
	}
};

int main()
{
	int x;
	action p;
	cout << "enter no of edges of polygon=" << endl;
	cin >> x;
	p.check(x);
	p.look();
	getch();
	closegraph();
	return 0;
}
