#include"Level.h"
#include<iostream>
#include <math.h>
#include"Collectibles.h"
#include"Particles.h"
namespace particle {
	float particleData[PARTICLE_CAP][5] = {}; //0 = x, 1 = y, 2 = depth, 3 = type, 4 = xv,
	bool particleExists[PARTICLE_CAP] = {};
	int windDirection = 2; //positives move right, negatives move left. X-vel is set based on exact value.
	int maxHeight = 0;
	int minHeight = 480;

	/* TYPES OF PARTICLES
	0 = snow
	*/


	void makeParticle(int type) {
		bool foundSlot = false;
		int i = 0;
		while (i < PARTICLE_CAP && !foundSlot) {
			if (!particleExists[i]) {
				/*if (windDirection > 0) {
					particleData[i][0] = 0;
				}
				else {
					particleData[i][0] = level::scrnWidth;
				}*/
				particleExists[i] = true;
				particleData[i][0] = float(rand() % level::scrnWidth);
				particleData[i][1] = float(rand() % (minHeight - maxHeight) + maxHeight);
				particleData[i][2] = float(rand() % 4);
				particleData[i][3] = type;
				particleData[i][4] = float(rand() % 90);
				return;
			}
			i++;
		}
	}

	void particlesOn(int type,int amt) {
		for (int i = 0; i < amt; i++) {
			makeParticle(type);
		}
	}

	void particlesOff() {
		for (int i = 0; i < PARTICLE_CAP; i++) {
			particleExists[i] = false;
		}
	}

	void snowProcess(int address) {
		particleData[address][0] += 5 - particleData[address][2];
		particleData[address][4]++;
		particleData[address][1] += cos(particleData[address][4] * (4 - particleData[address][2]));
	}


	void fullProcess() {
		for (int i = 0; i < PARTICLE_CAP; i++) {
			if (particleData[i][3] == 0) {
				snowProcess(i);
			}
			if ((particleData[i][4] > 0 && particleData[i][0] > level::scrnWidth) || (particleData[i][4] < 0 && particleData[i][0] < 0)) {
				if (particleData[i][0] > 0) {
					particleData[i][0] = 0;
				}
				else {
					particleData[i][0] = level::scrnWidth;
				}
			}
		}
	}
}