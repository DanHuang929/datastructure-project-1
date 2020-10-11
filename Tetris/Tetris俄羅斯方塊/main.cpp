#include <iostream>
#include <stdio.h>
#include<fstream>
#include<sstream>
#include "function.h"
using namespace std;

int main(int argc, char *argv[])
{
	char a[10];
	ifstream fin;
	fin.open(argv[1]);
	fin.getline(a, 10);
	stringstream str(a);
	str>> row;
	str >> col;
	char type;
	int type_n = 0;
	int start_point, move;
	char oper[20];
	for (int i = 0; i < maxrow; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = 0;
	while (!fin.eof()) {
		fin.getline(oper, 10);
		cout << oper << endl;
		stringstream ss(oper);
		ss >> type;
		if (type == 'E')
			break;
		else {
			if (type != 'O')
				ss >> type_n >> start_point >> move;
			else {
				ss >> start_point >> move;
				type_n = 0;
			}
			cout << "tututu " << type << type_n << start_point << move << endl;
			BLOCK block(type, type_n, start_point, move);
			falling(block);
			if (moving(block, move) == 0) {
				lose();
				break;
			}
			falling(block);
			if (test()) {
				lose();
				break;
			}
		}
		print();

		
	}
}
