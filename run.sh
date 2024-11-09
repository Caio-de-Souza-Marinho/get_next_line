#!/bin/bash

GREEN='\033[1;32m'
YELLOW='\e[1;33m'
PURPLE='\e[1;35m'
NO_COLOR='\033[0m'

echo -e "\n${GREEN}Running Norminette${NO_COLOR}"
cd src && \
norminette && \

echo -e "\n${GREEN}Compiling the test program with ${YELLOW}BUFFER_SIZE = 1${NO_COLOR}"
cd ../tests && \
make clean && \
make BUFFER_SIZE=1 && \

echo -e "${GREEN}Running Valgrind tests...${NO_COLOR}"
make leakfull && \

echo -e "\n${GREEN}Compiling the test program with ${YELLOW}BUFFER_SIZE = 10${NO_COLOR}"
make clean && \
make BUFFER_SIZE=10 && \

echo -e "${GREEN}Running Valgrind tests...${NO_COLOR}"
make leakfull && \

echo -e "\n${GREEN}Compiling the test program with ${YELLOW}BUFFER_SIZE = 1000000${NO_COLOR}"
make clean && \
make BUFFER_SIZE=1000000 && \

echo -e "${GREEN}Running Valgrind tests...${NO_COLOR}"
make leakfull && \

# echo -e "\n${GREEN}Compiling the bonus test program...${NO_COLOR}"
# make clean && \
# make bonus && \
# 
# echo -e "${GREEN}Running Valgrind bonus tests...${NO_COLOR}"
# make leakfullbonus && \

# echo -e "${GREEN}Compiling gnl-main.c...${NO_COLOR}"
# cd ../ && \
# cc -Wall -Wextra -Werror gnl-main.c src/get_next_line.c src/get_next_line_utils.c -o main.out

# Check if gnl-main compilation was successful
# if [ $? -eq 0 ]; then
    # echo -e "\n${GREEN}Running gnl-main.c function...${NO_COLOR}"
    # ./main.out
# else
    # echo -e "${NO_COLOR}Compilation of gnl-main.c failed.${NO_COLOR}"
    # exit 1
# fi

# echo -e "\n${GREEN}Compiling gnl-bonus-main.c...${NO_COLOR}"
# cc -Wall -Wextra -Werror gnl-bonus-main.c src/get_next_line_bonus.c src/get_next_line_utils_bonus.c -o main.out
# 
# # Check if gnl-bonus-main compilation was successful
# if [ $? -eq 0 ]; then
    # echo -e "\n${GREEN}Running gnl-bonus-main.c function...${NO_COLOR}"
    # ./main.out
# else
    # echo -e "${NO_COLOR}Compilation of gnl-bonus-main.c failed.${NO_COLOR}"
    # exit 1
# fi

# echo -e "\n${GREEN}Running Francinette tests...${NO_COLOR}"
# cd src && \
# ~/francinette/tester.sh && \

echo -e "\n${GREEN}All tasks completed successfully!${NO_COLOR}"
