#include<bits/stdc++.h>

using namespace std;

float x[3];
float y[3];

float dis(float x1,float y1,float x2,float y2)
{
	float dis;
	dis=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	return dis;
}

int main()
{
	float c=0;
	for(int i=0;i<3;i++)
	{
		scanf("%f",&x[i]);
		scanf("%f",&y[i]);
	}
	c+=dis(x[0],y[0],x[1],y[1]);
	c+=dis(x[1],y[1],x[2],y[2]);
	c+=dis(x[0],y[0],x[2],y[2]);
	printf("%.2f",c);
	return 0;
}
