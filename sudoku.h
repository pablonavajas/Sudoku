/* Presupplied functions */

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);


/* Solutions: */

bool is_complete(const char board[9][9]);

bool make_move(const char position[], int int_digit, char board[9][9]);

