#include <iostream>
#include <stdio.h>
#include "function.h"
using namespace std;

int map[maxrow][maxcol];
int col = 0, row = 0;
BLOCK::BLOCK()
{
	for (int i = 0; i < 4; i++)
		this->box[i].col = this->box[i].row = 0;
	this->move = 0;
}
BLOCK::BLOCK(BLOCK& block)
{
	for (int i = 0; i < 4; i++) {
		this->box[i].col = block.box[i].col;
		this->box[i].row = block.box[i].row;
	}
	this->move = block.move;
}
BLOCK::BLOCK(char type, int type_n, int start_point, int move)
{
	this->move = move;
	if (type == 'T') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 2;           //012
			this->box[0].col = start_point;                // 3
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 2;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
			
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 2;           // 1
			this->box[0].col = start_point;                //02
			map[this->box[0].row][this->box[0].col] = 1;   // 3

			this->box[1].row = maxrow - row - 3;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 3) {
			this->box[0].row = maxrow - row - 2;           
			this->box[0].col = start_point + 1;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 4) {
			this->box[0].row = maxrow - row - 3;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 2;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}

	}
	else if (type == 'L') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 3;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 2;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 2;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 3) {
			this->box[0].row = maxrow - row - 3;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 3;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 2;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 4) {
			this->box[0].row = maxrow - row - 1;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point + 2;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 2;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
	}
	else if (type == 'J') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 1;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 3;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 2;          
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 3) {
			this->box[0].row = maxrow - row - 3;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 3;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 4) {
			this->box[0].row = maxrow - row - 2;
			this->box[0].col = start_point;
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 2;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
	}
	else if (type == 'S') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 1;
			this->box[0].col = start_point;
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 2;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 3;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
	}
	else if (type == 'Z') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 2;           
			this->box[0].col = start_point;               
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 2;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 2;           
			this->box[0].col = start_point;                
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 2;
			this->box[2].col = start_point + 1;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 3;
			this->box[3].col = start_point + 1;
			map[this->box[3].row][this->box[3].col] = 1;
		}
	}
	else if (type == 'I') {
		if (type_n == 1) {
			this->box[0].row = maxrow - row - 1;           //012
			this->box[0].col = start_point;                // 3
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 2;
			this->box[1].col = start_point;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 3;
			this->box[2].col = start_point;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 4;
			this->box[3].col = start_point;
			map[this->box[3].row][this->box[3].col] = 1;
		}
		else if (type_n == 2) {
			this->box[0].row = maxrow - row - 1;           //012
			this->box[0].col = start_point;                // 3
			map[this->box[0].row][this->box[0].col] = 1;

			this->box[1].row = maxrow - row - 1;
			this->box[1].col = start_point + 1;
			map[this->box[1].row][this->box[1].col] = 1;

			this->box[2].row = maxrow - row - 1;
			this->box[2].col = start_point + 2;
			map[this->box[2].row][this->box[2].col] = 1;

			this->box[3].row = maxrow - row - 1;
			this->box[3].col = start_point + 3;
			map[this->box[3].row][this->box[3].col] = 1;
		}
	}
	else if (type == 'O') {
		this->box[0].row = maxrow - row - 2;           
		this->box[0].col = start_point;                
		map[this->box[0].row][this->box[0].col] = 1;

		this->box[1].row = maxrow - row - 2;
		this->box[1].col = start_point + 1;
		map[this->box[1].row][this->box[1].col] = 1;

		this->box[2].row = maxrow - row - 1;
		this->box[2].col = start_point;
		map[this->box[2].row][this->box[2].col] = 1;

		this->box[3].row = maxrow - row - 1;
		this->box[3].col = start_point + 1;
		map[this->box[3].row][this->box[3].col] = 1;
	}
}

void falling(BLOCK& block)
{
	while (valid_falling(block)) {
		for (int i = 0; i < 4; i++) {
			map[block.box[i].row][block.box[i].col] = 0;
			block.box[i].row += 1;
		}
		for (int i = 0; i < 4; i++)
			map[block.box[i].row ][block.box[i].col] = 1;

	}
	int erase_target;
	erase_target = detect_falling();
	while (erase_target != 0) {
		erase(erase_target);
		erase_target = detect_falling();
	}
}

int valid_falling (BLOCK& block)
{
	for (int i = 0; i < 4; i++) {
		if (map[block.box[i].row + 1][block.box[i].col] == 1 or (block.box[i].row + 1) > maxrow - 1) {
			int self = 0;
			for (int k = 0; k < 4; k++) 
				if ((block.box[i].row + 1 == block.box[k].row) && (block.box[i].col == block.box[k].col)) 
					self = 1;
			if (self) continue;
			else return 0;
		}
	}
	return 1;
}

int detect_falling(void)
{
	for (int i = maxrow - 1; i >= maxrow - row; i--) {
		int bingo = 1;
		for (int j = 1; j <= col; j++) 
			if (map[i][j] == 0)
				bingo = 0;
		if (bingo)
			return i;
	}
	return 0;
} 
//回傳需要被削除的row

void erase(int target_row)
{
	for (int i = target_row; i >= maxrow - row - 4; i--) { //注意最top
		for (int j = 1; j <= col; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
}

int moving(BLOCK& block, int move)
{
	int step = (move > 0) ? 1 : -1;
	for (int i = 0; i < move * step; i++) {
		if (valid_moving(block, step)) {
			for (int i = 0; i < 4; i++) {
				map[block.box[i].row][block.box[i].col] = 0;
				block.box[i].col += step;
			}
			for (int i = 0; i < 4; i++)
				map[block.box[i].row][block.box[i].col] = 1;
		}
		else return 0;
	}
	return 1;
}

int valid_moving(BLOCK& block, int step)
{
	for (int i = 0; i < 4; i++) {		
		if (map[block.box[i].row][block.box[i].col + step] == 1
			or (block.box[i].col + step) < 1
			or (block.box[i].col + step) > col) {
			int self = 0;
			for (int k = 0; k < 4; k++)
				if ((block.box[i].row == block.box[k].row) && (block.box[i].col + step == block.box[k].col))
					self = 1;
			cout << "ti\n";
			if (self) continue;
			else return 0;
		}
	}
	return 1;
}

void lose(void)
{
	cout << "lose" << endl;
}

void print(void)
{
	for (int i = maxrow - row - 4; i < maxrow; i++) {
		cout << i << " ";
		for (int j = 1; j <= col; j++)
			cout << map[i][j];
		cout << "\n";
	}
}