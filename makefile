EXEC = farmd
CXX = g++
CXXFLAGS =
LEX = flex
LEXFLAGS =
YACC = bison
YACCFLAGS = -d -v -fcaret
WARNING_FLAGS = -Wall -Wextra -Wshadow -Weffc++ -Wstrict-aliasing -ansi -pedantic -Werror

SRC_DIR = src/
BIN_DIR = bin/

SUBDIR_NAMES := $(shell ls -F $(SRC_DIR) | grep "\/" )
SUBDIRS := $(foreach subdir, $(SUBDIR_NAMES), $(SRC_DIR)$(subdir))
DIRS := $(SRC_DIR) $(SUBDIRS) 

SOURCES = $(foreach dir, $(DIRS), $(wildcard $(dir)*.cpp))
LEX_SOURCES = $(foreach dir, $(DIRS), $(wildcard $(dir)*.lpp))
YACC_SOURCES = $(foreach dir, $(DIRS), $(wildcard $(dir)*.ypp))

LEX_OUTPUT = $(patsubst %.lpp, %.cpp, $(LEX_SOURCES))
YACC_OUTPUT = $(patsubst %.ypp, %.cpp, $(YACC_SOURCES))
YACC_OUTPUT_ARTIFACTS = $(patsubst %.ypp, %.hpp, $(YACC_SOURCES)) $(patsubst %.ypp, %.output, $(YACC_SOURCES))

OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
LEX_OBJECTS = $(patsubst %.lpp, %.o, $(LEX_SOURCES))
YACC_OBJECTS = $(patsubst %.ypp, %.o, $(YACC_SOURCES))

%.cpp: %.lpp
	$(LEX) $(LEXFLAGS) -o $@ $<

%.cpp: %.ypp
	$(YACC) $(YACCFLAGS) -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(WARNING_FLAGS) $(CFLAGS) -o $@ $<

all: $(YACC_OUTPUT) $(LEX_OUTPUT) $(YACC_OBJECTS) $(LEX_OBJECTS) $(OBJECTS) $(BIN_DIR)$(EXEC)

$(BIN_DIR)$(EXEC): $(YACC_OBJECTS) $(LEX_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)$(EXEC) $(OBJECTS) $(YACC_OBJECTS) $(LEX_OBJECTS)

generatecode: lex yacc

clean:
	rm -f $(YACC_OUTPUT) $(YACC_OUTPUT_ARTIFACTS) $(LEX_OUTPUT) $(OBJECTS) $(YACC_OBJECTS) $(LEX_OBJECTS) $(BIN_DIR)$(EXEC)

lex: $(LEX_OUTPUT)

yacc: $(YACC_OUTPUT)