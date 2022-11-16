#include<iostream>
#include"game.h"
#include"interactiveObj.h"
#include"basicObjs.h"

class Enemy : public interactiveObj, public healthyObj {
public:
	int id = -1;
	std::string className = "";
	std::string name = "";
	void FireWormCreate();
	void OctorokCreate();
	void GhostKaidiCreate();
	void GhostKaidiProcess();
	
	const int rockSensingDist = 175;
	void RockCreate();
	void RockProcess();
};
