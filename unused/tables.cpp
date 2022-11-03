#include<iostream>
#include<vector>
#include"tables.h"
#include"enemy.h"
#include"interactiveObj.h"

void Tables::add(Enemy e) {
	enemies.push_back(e);
}

void Tables::del(Enemy e) {

}

void Tables::processAll() {
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies.at(i).className == "GhostKaidi") {
			GhostKaidi(enemies.at(i)).process();
		}
		//
	}
}
