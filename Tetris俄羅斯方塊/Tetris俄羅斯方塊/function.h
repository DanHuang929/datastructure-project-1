#ifndef TETRIS_H
#define TETRIS_H
#include <iostream>
#define maxrow 20
#define maxcol 40
struct point {
	int row, col;
};

class BLOCK {
public:
	BLOCK();
	BLOCK(char type, int type_n,int start_point, int move, int n, int m);
	friend void falling(BLOCK);
	friend int valid(BLOCK);
private:
	point box[4];
	int move;
};

void falling(BLOCK);
int valid(BLOCK);
int detect(void);
void erase(int);
#endif
