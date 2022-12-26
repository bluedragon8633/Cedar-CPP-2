#include<iostream>
#include"Collectibles.h"


collectibles::collectibles() {
		int coins[32][3] = {};
		bool coinsExist[32] = {};

	}
	void collectibles::processCoinFrame() {
		if (coinTimer == 6) {
			coinTimer = 0;
			if (coinFrame == 3) {
				coinFrame = 0;
			}
			else {
				coinFrame++;
			}
		}
		else {
			coinTimer++;
		}
	}

	void collectibles::setTo(collectibles newCol) {
		memcpy(coins, newCol.coins, sizeof(coins));
		memcpy(coinsExist, newCol.coinsExist, sizeof(coinsExist));

	}

	void collectibles::makeCoin(int x, int y, int value) {
		bool foundSlot = false;
		int i = 0;
		while (i < maxNumOfCoins - 1 && !foundSlot) {
			if (!coinsExist[i]) {
				foundSlot = true;
				coinsExist[i] = true;
				coins[i][0] = x;
				coins[i][1] = y;
				coins[i][2] = value;
			}
			i++;
		}
	}
	void collectibles::clearCoins() {
		for (int i = 0; i < 32; i++) {
			coinsExist[i] = false;
		}
	}
