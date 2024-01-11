MAIN = main
SUB1 = sub1
SUB2 = TimeCounter

CC = gcc
EDITOR = vim
EPARAM = -p
SRCS = ./src
INCS = ./include
BINS = ./bin
BUILD = ./build
LIBS = -lm
CFLAGS = -I $(INCS) -I $(SUB2)
PARAM = -O0
FILE = text

PROGRAM = hoge
OBJS = $(BINS)/$(MAIN).o $(BINS)/$(SUB1).o $(BINS)/$(SUB2).o
CODES = $(SRCS)/$(MAIN).c $(SRCS)/$(SUB1).c $(SUB2)/$(SUB2).c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(LIBS) $(PARAM)

chmod : $(PROGRAM)
	sudo chmod +x $(BUILD)/$(PROGRAM)

execute: all chmod
	$(BUILD)/$(PROGRAM) $(FILE)
	cat $(FILE)

all: clean mkdir $(PROGRAM)

clean:
	rm -rf $(BUILD) $(BINS)

mkdir:
	mkdir $(BUILD) $(BINS)

edit:
	$(EDITOR) $(EPARAM) $(SUB2)/* $(INCS)/* $(SRCS)/*

$(BINS)/$(MAIN).o: $(SRCS)/$(MAIN).c $(INCS)/$(MAIN).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB1).o: $(SRCS)/$(SUB1).c $(INCS)/$(SUB1).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB2).o: $(SUB2)/$(SUB2).c $(SUB2)/$(SUB2).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

