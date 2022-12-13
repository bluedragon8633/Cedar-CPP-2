#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"SFML/Graphics.hpp"
#include"general.h"

using namespace std;

int General::findInt(string name) {
    string plainText;
    ifstream ScrnData("./assets/presets.txt");
    for (int i = 0; i < 64; i++) {
        if (plainText.find(name) != string::npos) {
            break;
        }
        getline(ScrnData, plainText);
    }
    cout << plainText << endl;
    int startOfValue = 0;
    for (int i = 0; i < plainText.length(); i++) {
        if (plainText[i] == ':') {
            startOfValue = i + 1;
            break;
        }
    }
    return stoi(plainText.substr(startOfValue, plainText.length()));
}

string General::findString(string fileName, string name) {
    string plainText;
    ifstream ScrnData(fileName);
    for (int i = 0; i < 64; i++) {
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
    printf("got string\n");
    return plainText.substr(startOfValue, plainText.length());
}
/*
bool General::contains(vector<int> list, int find) {
    for (int i = 0; i < list.size();i++) {
        if (list.at(i) == find) {
            return true;
        }
    }
    return false;
}
*/
bool General::contains(int listin[], int arrayLen, int in) {
    for (int i = 0; i < arrayLen; i++) {
        if (listin[i] == in) {
            return true;
        }
    }
    return false;
}

/*
bool General::contains(int listin[], int in) {
    for (int i = 0; i < (sizeof(listin) / sizeof(listin[0])); i++) {
        if (listin[i] == in) {
            return true;
        }
    }
    return false;
}

bool General::contains(vector<int> listin, int in) {
    for (int i = 0; i < listin.size(); i++) {
        if (listin[i] == in) {
            return true;
        }
    }
    return false;
}
*/
string General::getLineFromFile(string fileName, int line) {
    ifstream TextFile(fileName);
    string returnThis;
    for (int i = 0; i < line; i++) {
        getline(TextFile, returnThis);
    }
    return returnThis;
}

