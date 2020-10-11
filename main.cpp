#include <iostream>
#include <stdio.h>
#include "function.h"
using namespace std;

int main()
{
	cin >> row >> col;
	char type;
	int type_n = 0;
	int start_point, move;
	for (int i = 0; i < maxrow; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = 0;
	while (cin >> type) {
		if (type == 'E')
			break;
		else {
			if (type != 'O')
				cin >> type_n >> start_point >> move;
			else {
				cin >> start_point >> move;
				type_n = 0;
			}
			BLOCK block(type, type_n, start_point, move);
			falling(block);
			if (moving(block, move) == 0) {
				lose();
				break;
			}
		}
		print();

		
	}
}
