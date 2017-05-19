CC = g++
TARGET = tetris

SOURCES = main.cpp \
					Tetris.cpp \
					Pane.cpp \
					BoardPane.cpp \
					InfoPane.cpp \
					HelpPane.cpp \
					StatPane.cpp \
					NextPane.cpp \
					Block.cpp \
					O_Block.cpp \
					Stacked_Block.cpp


LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
