/* Presupplied functions */

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);


/* Solutions Exercise 1: */

bool is_complete(const char board[9][9]);

/* Solutions Exercise 2: */

bool make_move(const char position[], int int_digit, char board[9][9]);

/* Solutions Exercise 3: */

bool save_board(const char* filename, char board[9][9]);
