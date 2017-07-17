LIBLIFE_DIR = ../liblife
SOURCE_FILES = $(shell find src -type f -name '*.c')
HEADER_FILES = $(shell find include -type f -name '*.h')
OUTPUT_DIR = bin
OUTPUT_FILE = $(OUTPUT_DIR)/life

.PHONY: clean all run

all: $(OUTPUT_FILE)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(OUTPUT_FILE): $(OUTPUT_DIR) $(SOURCE_FILES) $(INCLUDE_FILES)
	cc -o $(OUTPUT_FILE) -Iinclude -I$(LIBLIFE_DIR)/include -L$(LIBLIFE_DIR)/lib -llife $(SOURCE_FILES)

clean:
	rm -vfR $(OUTPUT_DIR)

run: $(OUTPUT_FILE)
	DYLD_LIBRARY_PATH=$(LIBLIFE_DIR)/lib:${DYLD_LIBRARY_PATH} bin/life
