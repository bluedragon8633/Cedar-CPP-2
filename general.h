#pragma once
#include<iostream>
#include<fstream>
#include "SFML/Graphics.hpp"

class General {
public:
	int findInt(std::string name);
	std::string getLineFromFile(std::string fileName, int line);
};

