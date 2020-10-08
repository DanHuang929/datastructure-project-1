#include <iostream>
#include <stdio.h>
#include <string>
#include "function.h"
using namespace std;

int map[20][40];
int col, row;

int main()
{
	cin >> row >> col;
	char type;
	int type_n = 0;
	int start_point, move;
	while (cin >> type) {
		if (type == 'E')
			break;
		else {
			if (type == 'T') {
				cin >> type_n >> start_point >> move;
				BLOCK block(type, type_n, start_point, move, row, col);
				falling(block);
				
			}
			else if (type == 'L') {
				cin >> type_n >> start_point >> move;
			}
			else if (type == 'J') {
				cin >> type_n >> start_point >> move;
			}
			else if (type == 'S') {
				cin >> type_n >> start_point >> move;
			}
			else if (type == 'Z') {
				cin >> type_n >> start_point >> move;
			}
			else if (type == 'I') {
				cin >> type_n >> start_point >> move;
			}
			else if (type == 'O') {
				cin >> type_n >> start_point >> move;
			}
		}
	}
}
