#pragma once
class EnemyTable {
public:
	int enemyInts[10][18] = { 0 }; //first field == maxEnemies
	bool enemyBools[10][6] = { 0 }; //exists, visible, vulnerable, collidesWithWall, centeredOrigin, flip

	EnemyTable();
};