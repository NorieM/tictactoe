#include <iostream>
#include <vector>

void show_board(std::vector<std::vector<std::string>> board);

std::string get_move(std::string player);

bool check_move(int x, int y, std::vector<std::vector<std::string>> board);

std::string check_winner(std::vector<std::vector<std::string>> board);

void start_game();
