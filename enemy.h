#include<iostream>
#include"game.h"
#include"interactiveObj.h"
#include"basicObjs.h"

class Enemy : public interactiveObj, public healthyObj {
public:
	int id = -1;
	std::string className = "";
	std::string name = "";
};

class FireWorm : public Enemy {
public:
	FireWorm();
};

class Octorok : public Enemy {
public:
	Octorok();
};


class GhostKaidi : public Enemy {
public:
	GhostKaidi();
	GhostKaidi(Enemy e);
	void process();
};


class Rock : public Enemy {
public:
	const int sensingDist = 175;
	Rock();
	void process();
};