#ifndef _BOARD_H_
#define _BOARD_H_

#include "Block.h"

class Board{
	friend class StatPane;
	friend class InfoPane;
	friend class BoardPane;
	friend class NextPane;
	friend class Block;

private:
	int height;
	int width;
	Cell **cells; // 블록을 그릴 2차원배열
	int t_x, t_y;
	int nextblock;
	Block *iblock, *oblock, *lblock, *jblock, *sblock, *zblock, *tblock; 
	int fulllines;
	int Iblockcount, Oblockcount, Lblockcount, Jblockcount, Sblockcount, Zblockcount, Tblockcount;
	int total;
	char name[100];
public:
	Board(int w, int h);
	~Board();
	bool insertBlock(int curblock);
	bool moveBlockLeft(int curblock);
	bool moveBlockRight(int curblock);
	bool moveBlockDown(int curblock);
	bool rotateBlock(int curblock);
	void dropBlock(int curblock);
	void eraseBlock();
	void setNextBlock(int nextblock);
	void setName(char *string);
};

#endif
