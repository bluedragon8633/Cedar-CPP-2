#pragma once
#include<iostream>

class Portal {
public:
	int x, y, width, height, startLevel, targetLevel;
	int targetX, targetY;
	bool isPortalInScreen;
	
	bool isEntityInBounds(int ex, int ey);
	void loadPortal();
	void erase();
};
