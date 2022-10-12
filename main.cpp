
class frameObj {
	int sourceX,sourceY;
	bool flip;
	int width,height;
};

class baseObj {
public:
	int x, y;
	int dir;
	int width, height;
	
};

class animObj : public baseObj {
public:
	
};

class interactiveObj : public animObj {
public:
	int xv, yv;
	bool isHarmful;
	
	
	
	
	
	void move(xin,yin) {
		x = xin;
		y = yin;
	}
};

