graf_line   = "\033[33m============================================\033[0m"
command_str =         "gcc -std=c99 src/main.c && ./a.out ./project"
command     =  gcc -std=c99 src/main.c && ./a.out ./project

define build
	@echo $(graf_line)
	@echo $(command_str)
	@echo $(graf_line)
	@$(command)
endef

default: clear
	clear
	$(build)

build:
	$(build)

clear:
	@rm -rf dist

# Show all *.c files, maybe for future usage
SOURCES = $(wildcard ./src/*.c)
echo:
	@echo "\033[31mList of all source files:\033[0m"
	@echo $(SOURCES)