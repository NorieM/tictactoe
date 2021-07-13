#include <iostream>
#include <vector>

// show the TicTacToe board
void show_board(std::vector<std::vector<std::string>> board)
{

  std::cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "\n";
  std::cout << std::string(6, '-') << "\n";
  std::cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "\n";
  std::cout << std::string(6, '-') << "\n";
  std::cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "\n";
};

// get a move from a user
std::string get_move(std::string player)
{
  std::string move;

  std::cout << player << " please enter your move:\n";
  std::cin >> move;

  return move;
}

// check user's move is valid, i.e. space not already used
bool check_move(int x, int y, std::vector<std::vector<std::string>> board)
{
  bool valid;

  valid = board[x][y] == " ";

  return valid;
};

// check to see if there's a winner
// if there is a winner returns Player1/Player2
std::string check_winner(std::vector<std::vector<std::string>> board)
{
  std::string winner;

  if(board[0][0]!=" " && board[0][0]==board[0][1] && board[0][1] ==board[0][2]) {
    winner = board[0][0];
    std::cout<<winner<<"\n";
  } else if (board[1][0]!=" " && board[1][0]==board[1][1] && board[1][1] ==board[1][2]) {
    winner =board[1][0];
    std::cout<<winner<<"\n";
  } else if (board[2][0]!=" " && board[2][0]==board[2][1] && board[2][1] ==board[2][2]){
    winner = board[2][0];
    std::cout<<winner<<"\n";
  }

  std::cout<<winner<<"\n";

  if(board[0][0]!=" " && board[0][0]==board[1][0] && board[1][0] ==board[2][0]) {
    winner = board[0][0];
    std::cout<<winner<<"\n";
  } else if (board[0][1]!=" " && board[0][1]==board[1][1] && board[1][1] ==board[2][1]) {
    winner =board[1][0];
    std::cout<<winner<<"\n";
  } else if (board[0][2]!=" " && board[0][2]==board[1][2] && board[1][2] ==board[2][2]){
    winner = board[2][0];
    std::cout<<winner<<"\n";
  }

  if(board[0][0]!=" " && board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
    winner = board[0][0];
    std::cout<<winner<<"\n";
  } else if (board[0][2]!=" " && board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
    winner = board[0][2];
    std::cout<<winner<<"\n";

  }

  std::cout<<winner<<"\n";

  if (winner!=""){
    winner = winner=="X" ? "Player1": "Player2";
  }

  return winner;
}

void start_game() {
  
  bool game_over;
  bool valid_move;
  int x;
  int y;
  int squares = 9;
  std::string move;
  std::string winner;
  std::string current_player = "Player1";
  std::vector<std::vector<std::string>> board = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};

  while (!game_over)
  {
    show_board(board);
    move = get_move(current_player);
    x = (int)move[0] - 49;
    y = (int)move[1] - 49;
    valid_move = check_move(x, y, board);
    while (!valid_move)
    {
      if (!valid_move)
      {
        std::cout << "That isn't a valid move, please try again!\n";
        move = get_move(current_player);
        x = (int)move[0] - 49;
        y = (int)move[1] - 49;
        valid_move = check_move(x, y, board);
      }
    }

    board[x][y] = current_player == "Player1" ? "X" : "O";
    squares--;
    current_player = current_player == "Player1" ? "Player2" : "Player1";
    winner = check_winner(board);
    game_over = squares == 0 || winner != "";
  }
  show_board(board);
  if (winner != "")
  {
    std::cout << "The winner was " << winner << "!\n";
  }
  else
  {
    std::cout << "It's a draw!\n";
  }
}