#pragma once
#pragma once
#include<iostream>

namespace particle {
	const int PARTICLE_CAP = 64;
	extern float particleData[PARTICLE_CAP][5]; //0 = x, 1 = y, 2 = depth, 3 = type, 4 = xv, 5 = yv
	 extern bool particleExists[PARTICLE_CAP];
	 extern int windDirection;
	 extern int maxHeight;
	 extern int minHeight;

	void particlesOn(int type,int amt);
	void particlesOff();
	void makeParticle(int type);
	void fullProcess();

}