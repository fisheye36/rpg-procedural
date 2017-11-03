CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -MMD -MP
CXXFLAGS += -std=c++03
LDFLAGS = -lm

ZIP = rpg-procedural.tgz

APP = rpg-procedural.out
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)
DEP = $(SRC:.cpp=.d)
OBJ = $(SRC:.cpp=.o)

all: $(APP)

help:
	@echo "'make all' to build $(APP)"
	@echo "'make help' to show help"
	@echo "'make rebuild' to build from scratch"
	@echo "'make zip' to compress source and header files into $(ZIP)"
	@echo "'make run' to start application (building it if necessary)"
	@echo "'make crun' to clear screen and start application (building it if necessary)"
	@echo "'make clean' to delete everything except source and header files"
	@echo "'make vars' to print file-related variables"

rebuild: clean $(APP)

$(APP): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

	@echo
	@echo "$(APP): build complete"
	@echo "'make run' to start application"
	@echo "'make crun' to clear screen and start application"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

zip: $(SRC) $(HDR)
	tar czf $(ZIP) $^ Makefile

run: $(APP)
	@./$(APP)

crun: $(APP)
	@clear
	@./$(APP)

clean:
	rm -rf $(APP) $(OBJ) $(DEP) $(ZIP)

vars:
	@echo "SRC = $(SRC)"
	@echo "HDR = $(HDR)"
	@echo "DEP = $(DEP)"
	@echo "OBJ = $(OBJ)"

.PHONY: all help rebuild zip run crun clean vars

-include $(DEP)
