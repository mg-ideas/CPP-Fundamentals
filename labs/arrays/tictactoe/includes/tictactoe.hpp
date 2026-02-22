#pragma once
#include <tuple>

#ifdef _WIN32
#define CLEAR_SCREEN system("cls")
#else
#define CLEAR_SCREEN system("clear")
#endif

const size_t ROWS = 3;
const size_t COLS = 3;

namespace tictactoe
{
    // Function prototypes for the Tic Tac Toe game
    // Initializes the game board with empty spaces
    void init_board(char board[][3]);
    // Displays the current state of the game board
    void display_board(char board[][3]);
    // Get the player's move as a tuple of row and column indices
    std::tuple<unsigned short, unsigned short> get_player_move(char current_player);
    // Places a mark (X or O) on the board at the specified row and column
    bool place_mark(char board[][3], size_t row, size_t col, const char mark);
    // Checks if the specified mark has won the game
    bool check_winner(char board[][3], const char mark);
    // Checks if the game is a draw (no more empty spaces and no winner)
    bool check_draw(char board[][3]);
    // Switches the current player from X to O or vice versa
    void switch_player(char &current_player);
    // Clears the game board by resetting all spaces to empty
    void clear_board(char board[][3]);
    // Two-player game loop where players take turns until the game is over
    void two_player_game_loop(char board[][3]);
    // Displays the main menu and returns the user's choice
    unsigned short get_menu_option();
    // FIXME: Implement single-player game loop against computer
    void single_player_game_loop(char board[][3]);
    // Makes a move for the computer by placing its mark on the first available space
    bool computer_move(char board[][3], const char mark);
}
