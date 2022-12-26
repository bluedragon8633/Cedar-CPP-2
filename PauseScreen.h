#pragma once
class PauseScreen {
public:
	bool areYouSure = false;
	void process();
};

class GameOverScreen {
public:
	bool areYouSure = false;
	void process();
};