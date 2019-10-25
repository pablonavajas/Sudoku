#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============" << "\n\n";

  cout << "Calling load_board():" << '\n';
  load_board("easy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";

  /*
  
  cout << "=================== Question 1 ===================" << "\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";
  

  cout << "=================== Question 2 ===================" << "\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", 1, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  // 5 more test cases:

  cout << "Putting '8' into A1 is ";
  if (!make_move("A1", 8, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '3' into E5 is ";
  if (!make_move("E5", 3, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '6' into B3 is ";
  if (!make_move("B3", 6, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '7' into d7 is ";
  if (!make_move("d7", 7, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);
  
  cout << "Putting '9' into D2 is ";
  if (!make_move("D2", 9, board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  */

  /* Code to test many numbers in a specific position: 

  int digit;

  cout << "\n Enter the digit you would like to insert in H6: ";
  cin >> digit;
  
  cout << "\n\nPutting \'" << digit <<"\' into H6 is ";
  if (!make_move("H6", digit, board))
    cout << "NOT ";
  cout << "a valid move.\n\n The board is:" << "\n\n";
  display_board(board);

  */

  /*
  cout << "=================== Question 3 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << '\n';
  else
    cout << "Save board failed." << '\n';
  cout << '\n';
  
  */
  
  cout << "=================== Question 4 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << '\n';
    display_board(board);
  } else 
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

	// write more tests

  cout << "=================== Question 5 ===================" << "\n\n";

	// write more tests

	

  return 0;
}
