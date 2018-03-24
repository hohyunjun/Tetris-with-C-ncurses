CC = g++
TARGET =tetris
SOURCES =Tetris.cpp \
	Pane.cpp \
	BoardPane.cpp \
	InfoPane.cpp \
	HelpPane.cpp \
	StatPane.cpp \
	NextPane.cpp \
	Block.cpp \
	OBlock.cpp \
	IBlock.cpp \
	LBlock.cpp \
	JBlock.cpp \
	SBlock.cpp \
	ZBlock.cpp \
	TBlock.cpp \
	Board.cpp \
	main.cpp 
LDFLAGS =-lncurses

all :
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean :
	rm -rf *.o $(TARGET)
