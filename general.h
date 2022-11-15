#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include "SFML/Graphics.hpp"

class General {
public:
	static int findInt(std::string name);
	static std::string findString(std::string fileName, std::string name);
	static bool contains(int listin[], int arrayLen, int in);
	//static bool contains(vector<int> list, int find);
	static std::string getLineFromFile(std::string fileName, int line);


};

