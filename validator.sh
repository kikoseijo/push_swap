make re && ./push_swap "2 1 3 6 5 8"
make re && lldb ./push_swap "2 1 3 6 5 8"
make re && valgrind --leak-check=full --track-origins=yes  ./push_swap "2 1 3 6 5 8"
