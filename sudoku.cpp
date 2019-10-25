#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << '\n';
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* PROPOSED FUNCTIONS: */

/* Exercise 1: Function to check whether all board positions are occupied by digits (returning True, and False otherwise) */

/* SOLUTION: The function will iterate over the board positions and will return false if it encounters an empty ('.') position. If all positions are filled it will return true */

bool is_complete(const char board[9][9]){

  for (int row = 0; row < 9; row++) {

    for (int col = 0; col < 9; col++) {

      if (board[row][col] == '.'){
	
	return false;
      }
    }
  }

  return true;
}


/* Exercise 2: Function that inserts a number at a specific position returning true. Alternatively, if the move or the position are invalid it returns flase and leaves the board unchanged. It uses five helper functions. */

/* Helper Function that checks whether the input position is valid and modifies the values of the row and the column (NOTE: it allows the user to input low case characters to identify the row) */

bool valid_position(int& row, int& col){

  if ( col < 0 || col > 8 || row < 0 || row > 8){

    if (row >= 32 && row <= 40) {

      row -= 32;
      return true;
    }

    return false;
  }

  else {
    
    return true;
  }
}

/* Helper Function that checks whether the input digit is in the destination's column */

bool digit_in_col(char board[9][9], int col, char digit){

  for (int x_row = 0; x_row < 9; x_row++){

    if (board[x_row][col] == digit){
      
      return true;
    }
  }
  return false;
}

/* Helper Function that checks whether the input digit is in the destination's row */

bool digit_in_row(char board[9][9], int row, char digit){

  for (int y_col = 0; y_col < 9; y_col++){

    if (board[row][y_col] == digit){
      
      return true;
    }
  }
  return false;
}

/* Helper Function that checks whether the input digit is in the destination's sub-square */

bool digit_in_square(char board[9][9], int row, int col, char digit){

  for (int j_col = col - col % 3; j_col <= col - col % 3 + 2; j_col++) {

    for (int i_row = row - row % 3; i_row <= row - row % 3 + 2; i_row++) {

      if (board[i_row][j_col] == digit){

	return true;
      }
    }
  }
  return false;
}

/* Helper Function that combines the four previous functions to return the validity of the move in one single statement */

bool valid_move(int row, int col, char digit, char board[9][9]){

  if (digit_in_col(board, col, digit)){
      
    return false;
  }
  
  else if (digit_in_row(board, row, digit)){

    return false;
  }

  else if (digit_in_square(board, row, col, digit)){
      
    return false;
  }

  return true;
}

/* SOLUTION: the function will convert the position string values into integers, and the input digit to a character. It will check whether the input digit is valid, returning false if it is not. It will then check if the position is valid and if the move is valid to make the move and return true. It will return false otherwise and leave the board unchanged. */

bool make_move(const char position[], int int_digit, char board[9][9]){

  int row = position[0];
  int col = position[1];

  row -= 65;
  col -= 49;
  
  char digit = int_digit + '0';
  
  if (int_digit > 9 || int_digit < 1) {

    return false;
  }
  
  else { 

    if (valid_position(row, col) && valid_move(row, col, digit, board)) {
      
      board[row][col] = digit;
      return true;
    }
    return false;
  }
}

/* Exercise 3: function to output the 2D character array to a file named filename (using one helper function) */

/* Helper Function to copy the content of the board to the output file */

void copy_to(char board[9][9], ofstream& out){

  char character;
  
  for (int row = 0; row < 9; row++){

    for (int col = 0; col < 9; col++){

      character = board[row][col];
      out.put(character);

      if (col == 8){

	out.put('\n');
      }
    }
  }
}

/* SOLUTION: the solution includes a checking mechanism in case the stream operation was not successful */

bool save_board(const char* filename, char board[9][9]){

  ofstream out(filename);

  if (!out){

    cout << "Failed!" << "\n";
    return false;
  }

  copy_to(board,out);
  out.close();
  return true;
}


/* Exercise 4: recursive function that attempts to resolve the Sudoku puzzle */

/* Helper Function that finds the row and column of an empty position */

bool empty_entry(char board[9][9], int& row, int& col){

  for (row = 0; row < 9; row++){

    for (col = 0; col < 9; col++){

      if (board[row][col] == '.'){
	
	return true;
      }
    }
  }
  return false;
}

/* SOLUTION: the function will find an empty position and assig it a value (1-9)in a for loop. It will check if the move is valid (recalling our helper function from exercise 2). 
If it is valid, it will assign that value to the position and call itself: 
Next, it will try to fill the next empty position with a value (1-9) if it finds that there is no valid solution, it will unassign the value of the previous empty position and will try another value. 
Once all positions are filled with valid numbers it will return true */


bool solve_board(char board[9][9]){

  int row, col;

  if (!empty_entry(board, row, col)){

    return true;
  }

  for (int digit = 1; digit <= 9; digit++){

    char char_digit = digit + '0';

    if (valid_move(row, col, char_digit, board)){

      board[row][col] = char_digit;

      if (solve_board(board)){

	return true;
      }
      board[row][col] = '.';
    }
  }
  return false;
}
