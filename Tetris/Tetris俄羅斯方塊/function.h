#ifndef TETRIS_H
#define TETRIS_H
#include <iostream>
#define maxrow 20
#define maxcol 45
extern int map[maxrow][maxcol];
extern int col, row;
struct point {
	int row, col;
};

class BLOCK {
public:
	BLOCK();
	BLOCK(BLOCK&);
	BLOCK(char, int, int, int);
	friend void falling(BLOCK&);
	friend int valid_falling(BLOCK&);
	friend int moving(BLOCK&, int);
	friend int valid_moving(BLOCK&, int);
private:
	point box[4];
	int move;
};

void falling(BLOCK&);
int valid_falling(BLOCK&);
int detect_falling(void); //回傳需要被削除的row
void erase(int);

int moving(BLOCK&, int);
int valid_moving(BLOCK&, int);

void lose(void);
void print(void);
int test(void);

#endif
