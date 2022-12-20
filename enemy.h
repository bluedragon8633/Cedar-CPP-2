#include<iostream>
#include"game.h"
#include"interactiveObj.h"
//#include"basicObjs.h"



class Enemy : public interactiveObj, public healthyObj {
public:
	int id = -1;
	
	std::string name = "";
	bool processedCollision = false;
	
	Enemy(baseObj b);

	void create();
	void process();
	
	//FireWorm, not to be confused with fireworms
	void FireWormCreate();
	void FireWormProcess();
	
	//octoroks
	void OctorokCreate();
	void OctorokProcess();

	//ghost kaidi
	void GhostKaidiCreate();
	void GhostKaidiProcess();
	
	//rock shit
	const int rockSensingDist = 175;
	void RockCreate();
	void RockProcess();

	//horizontal and vertical ground enemies
	void VerticalCreate();
	void VerticalProcess();
	void HorizontalCreate();
	void HorizontalProcess();
};

class EnemyTable {
public:
	vector<Enemy> enemies;


	void clear();
	void addEnemies(vector<baseObj> newEnemies);
	void processAll();


	int enemiesLeft();
};