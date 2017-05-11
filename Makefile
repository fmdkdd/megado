CC := clang
CFLAGS := -Wall -Wextra -pedantic -std=c11 -O3

BUILD_DIR := build
INCLUDES := -I./ `sdl2-config --cflags`
LIBS := `sdl2-config --libs`

.PHONY: all
all: $(BUILD_DIR)/genesis

$(BUILD_DIR)/genesis: test/main.c $(BUILD_DIR)/*.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(BUILD_DIR)/genesis test/main.c $(BUILD_DIR)/*.o

$(BUILD_DIR)/*.o:
	make -C m68k
	make -C genesis

.PHONY: clean
clean:
	make -C m68k clean
	make -C genesis clean
	rm --force $(BUILD_DIR)/genesis
