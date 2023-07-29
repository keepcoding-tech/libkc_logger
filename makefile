# kclog lib
#
# Daniel Tanase
# 29/07/23
#
#                  _         __ _ _
#                 | |       / _(_) |
#  _ __ ___   __ _| | _____| |_ _| | ___
# | '_ ` _ \ / _` | |/ / _ \  _| | |/ _ \
# | | | | | | (_| |   <  __/ | | | |  __/
# |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___|
#

# Specify the compiler and compiler flags
CC := gcc
STD := -std=c89
CFLAGS := -Wall -Werror -Wpedantic -g -Iinclude

# Specify the source and the include directory
HDR_DIR := include
SRC_DIR := src

# Specify the source files and headers
SOURCES := $(wildcard $(SRC_DIR)/*.c)
HEADERS := $(wildcard $(HDR_DIR)/*.h)

# Specify the build directory
OBJ_DIR  := build/obj
BIN_DIR  := build/bin
TEST_DIR := build/bin/test

OBJ_DIRS := $(sort $(dir $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)))

#################################### BUILD #####################################

# Create a list of object files by replacing the file extensions
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Extract the test file names from the source file names
TEST_FILES := $(basename $(notdir $(wildcard tests/*.c)))

# Generate the test targets dynamically
TEST_TARGETS := $(addprefix $(TEST_DIR)/, $(TEST_FILES))

# Specify the list of all test executables
ALL_TESTS := $(addprefix $(TEST_DIR)/, $(TEST_FILES))

# Set the default target
all: $(TEST_TARGETS) libkclog.a

# Create the build directory and compile the object files
$(OBJECTS): | $(OBJ_DIRS)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

# Generic pattern rule to compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(STD) $(CFLAGS) -c $< -o $@

# Create the test directory
$(TEST_DIR):
	mkdir -p $(TEST_DIR)

# Dynamically generate the test targets and compile the test files
$(TEST_DIR)/%: tests/%.c $(OBJECTS) | $(TEST_DIR)
	$(CC) $(STD) $(CFLAGS) $^ -o $@

libkclog.a: $(OBJECTS)
	ar rcs libkclog.a $(OBJECTS)

##################################### TEST #####################################

# Test command to run all test executables consecutively
test: $(ALL_TESTS)
	@for test_executable in $(ALL_TESTS); do \
		$$test_executable; \
	done

#################################### CLEAN #####################################

clean:
	rm -fr build *.o *.a

##################################### HELP #####################################

# Help command to display available targets
help:
	@echo "Available targets:"
	@echo "  all         : Compile all test executables"
	@echo "  test        : Run all test executables consecutively"
	@echo "  clean       : Clean up the object files and build directory"
	@echo "  help        : Display this help message"

.PHONY: all test clean help