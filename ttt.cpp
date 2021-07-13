#include <iostream>
#include <vector>
#include "functions.hpp"

int main()
{
  bool play_game=true;
  std::string play_again;

  while (play_game) {
    start_game();
    std::cout<<"Do you want to play again (Y/N)?";
    std::cin>>play_again;
    play_game = tolower(play_again[0])=='y';
  }

}