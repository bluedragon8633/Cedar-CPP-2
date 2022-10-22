#include<iostream>
#include<string>
#include<fstream>
#include"SFML/Graphics.hpp"
#include"general.h"
using namespace std;

int General::findInt(string name) {
    string plainText;
    ifstream ScrnData("./assets/presets.txt");
    for (int i = 0; i < 3; i++) {
        if (plainText.find(name) != string::npos) {
            break;
        }
        getline(ScrnData, plainText);
    }
    int startOfValue = 0;
    for (int i = 0; i < plainText.length(); i++) {
        if (plainText[i] == ':') {
            startOfValue = i + 1;
            break;
        }
    }
    return stoi(plainText.substr(startOfValue, plainText.length()));
}


/*
string General::getLineFromFile(string fileName, int line) {
    ifstream TextFile(fileName);
    string returnThis;
    for (int i = 0; i < line; i++) {
        getline(TextFile, returnThis);
    }
    return returnThis;
}
*/