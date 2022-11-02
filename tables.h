#include<iostream>
#include<vector>
#include"enemy.h"
#include"interactiveObj.h"


class Tables {
	vector<Enemy> enemies;

	void add(Enemy e);
	void del(Enemy e);
	void processAll();
};