#include"four_bar.H"
#include<cmath>

void four_bar( float bar[4] ,float sita[4])
{
	float deltasita3 = 10;
	float deltasita4 = 10;
	float f1 = 0;
	float f2 = 0;
	float delta3 = 0;
	float delta4 = 0;
	float delta = 0;
	const float pi = 3.1415926;

    while(abs(deltasita3)+abs(deltasita4) >0.1)
	{
		f1 = bar[1]*cos(sita[1])+bar[2]*cos(sita[2])-bar[3]*cos(sita[3])-bar[0]*cos(sita[0]);
	    f2 = bar[1]*sin(sita[1])+bar[2]*sin(sita[2])-bar[3]*sin(sita[3])-bar[0]*sin(sita[0]);
		delta = (-bar[2]*sin(sita[2]))*(bar[3]*cos(sita[3]))+(bar[2]*cos(sita[2]))*(bar[3]*sin(sita[3]));
		 delta3 = (-f1*bar[3]*cos(sita[3]))-(f2*bar[3]*sin(sita[3]));
        delta4 = (-bar[2]*sin(sita[2])*f2)-(bar[2]*cos(sita[2])*f1);  
        deltasita3 =delta3/delta;
		deltasita4 =delta4/delta;
		sita[2] = sita[2] + deltasita3;
		sita[3] = sita[3] + deltasita4;
	};

	while(sita[2]>2*pi)
		sita[2] = sita[2] - 2*pi;

	while(sita[2]<0)
		sita[2] = sita[2] + 2*pi;

	while(sita[3]>2*pi)
		sita[3] = sita[3] - 2*pi;

	while(sita[3]<0)
		sita[3] = sita[3] + 2*pi;
}