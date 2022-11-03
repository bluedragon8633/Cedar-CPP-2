#pragma once
#include<iostream>
#include<fstream>
#include "SFML/Graphics.hpp"

class General {
public:
	int findInt(std::string name);
	static bool contains(int listin[], int arrayLen, int in);
	std::string getLineFromFile(std::string fileName, int line);
};

