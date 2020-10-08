#include <iostream>
#include <stdio.h>
#include <string>
#include "function.h"
using namespace std;

extern int map[maxrow][maxcol];
extern int col, row;
BLOCK::BLOCK()
{
	for (int i = 0; i < 4; i++)
		this->box->col = this->box->row = 0;
	this->move = 0;
}

BLOCK::BLOCK(char type, int type_n, int start_point, int move, int m, int n)
{
	this->move = move;
	if (type == 'T') {
		if (type_n == 1) {
			this->box[0].row = maxrow - m - 2;
			this->box[0].col = start_point;

			this->box[1].row = maxrow - m - 2;
			this->box[1].col = start_point + 1;

			this->box[2].row = maxrow - m - 2;
			this->box[2].col = start_point + 2;

			this->box[3].row = maxrow - m - 1;
			this->box[3].col = start_point + 1;
		}
		else if (type_n == 2) {

		}
		else if (type_n == 3) {

		}
		else if (type_n == 4) {

		}

	}
	else if (type == 'L') {
		if (type_n == 1) {

		}
		else if (type_n == 2) {

		}
		else if (type_n == 3) {

		}
		else if (type_n == 4) {

		}
	}
	else if (type == 'J') {
		if (type_n == 1) {

		}
		else if (type_n == 2) {

		}
		else if (type_n == 3) {

		}
		else if (type_n == 4) {

		}
	}
	else if (type == 'S') {
		if (type_n == 1) {

		}
		else if (type_n == 2) {

		}
	}
	else if (type == 'Z') {
		if (type_n == 1) {

		}
		else if (type_n == 2) {

		}
	}
	else if (type == 'I') {
		if (type_n == 1) {

		}
		else if (type_n == 2) {

		}
	}
	else if (type == 'O') {
		
	}
}

void falling(BLOCK block)
{
	while (valid(block)) {
		for (int i = 0; i < 4; i++) {
			map[block.box[i].row][block.box[i].col] = 0;
			map[block.box[i].row - 1][block.box[i].col] = 1;
		}
	}
	int erase_target = detect();
	if (erase_target != 0)
		erase(erase_target);
}

int valid(BLOCK block)
{
	for (int i = 0; i < 4; i++) {
		if (map[block.box[i].row + 1][block.box[i].col] == 1 or (block.box[i].row - 1) < 1)
			return 0;
	}
	return 1;
}

int detect(void)
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

void erase(int target_row)
{
	for (int i = target_row; i >= maxrow - row; i--) { //ª`·N³Ìtop
		for (int j = 1; j <= col; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
}