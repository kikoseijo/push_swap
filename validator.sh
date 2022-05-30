make re && ./push_swap "2 1 3 6 5 8"
make re && ./push_swap "2 1 3 6 5 8 10 -30 -10"
make re && lldb ./push_swap "2 1 3 6 5 8"
make re && valgrind --leak-check=full --track-origins=yes  ./push_swap "2 1 3 6 5 8"
# Radix single function sort.
kcc src/radix_sort.c && ./a.out && rm -rf a.out

# checker_OS validator
chmod 755 checker_Mac
ARG="2 1 42 3 6 5 8 30 10 20 33"; ./push_swap $ARG | ./checker_Mac $ARG
