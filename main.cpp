
class baseObj {
public:
	int x, y;
	int dir;
	bool flip;
	
};

class animObj : public baseObj {
public:
	
};

class interactiveObj : public animObj {
public:
	int xv, yv;
	
	void move(xin,yin) {
		x = xin;
		y = yin;
	}
};

