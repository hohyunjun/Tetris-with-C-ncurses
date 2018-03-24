#ifndef _BLOCK_H_
#define _BLOCK_H_

enum Cell{VOID, I, O, L, J, S, Z, T};

class Block{

protected:
	int rotate; // 회전 횟수를 세는 변수
	int height;
	int width;

public:
	Block();	
	virtual bool insertBlock(int &x, int &y, Cell **cells) = 0;
	virtual bool moveBlockLeft(int &x, int &y, Cell **cells) = 0;
	virtual bool moveBlockRight(int &x, int &y, Cell **cells) = 0;
	virtual bool moveBlockDown(int &x, int &y, Cell **cells)= 0;
	virtual bool rotateBlock(int &x, int &y, Cell **cells)= 0;
	virtual void dropBlock(int &x, int &y, Cell **cells)=0; 
};

class OBlock : public Block{

public:
	OBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);
};

class IBlock: public Block{

public:
	IBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);

};

class LBlock: public Block{

public:
	LBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);
};

class JBlock: public Block{

public:
	JBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);
};

class SBlock: public Block{

public:
	SBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);

};

class ZBlock: public Block{

public:
	ZBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);

};

class TBlock: public Block{

public:
	TBlock();
	bool insertBlock(int &x, int &y, Cell **cells);
	bool moveBlockLeft(int &x, int &y, Cell **cells);
	bool moveBlockRight(int &x, int &y, Cell **cells);
	bool moveBlockDown(int &x, int &y, Cell **cells);
	bool rotateBlock(int &x, int &y, Cell **cells);
	void dropBlock(int &x, int &y, Cell **cells);

};

#endif
