#pragma once
#include<iostream>
#include<fstream>
#include "SFML/Graphics.hpp"

class General {
public:
	int findInt(std::string name);
	std::string getLineFromFile(string fileName, int line);
};

