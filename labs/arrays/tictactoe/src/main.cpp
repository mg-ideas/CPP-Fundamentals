/*
Game of Tic Tac Toe using 2D arrays.

The game board is represented as a 3x3 grid, and players take turns placing their marks (X or O)
on the board.
The program checks for win conditions after each move and displays the current state of the board.
The game continues until one player wins or the board is full, resulting in a draw.

Algorithm Steps:
1. Initialize the game board as a 3x3 2D array filled with spaces.
2. Display the initial empty board to the players.
3. Loop until the game is over:
   a. Prompt the current player to enter their move (row and column).
   b. Validate the move and place the player's mark on the board.
   c. Display the updated board.
   d. Check for a winner or a draw:
      - If a player has three marks in a row, declare them the winner and end the game.
      - If the board is full without a winner, declare a draw and end the game.
   e. Switch to the other player and repeat the process.
*/

#include <iostream>
#include "../includes/tictactoe.hpp"

int main()
{
    char board[ROWS][COLS];
    bool loop = true;
    while (loop)
    {
        tictactoe::init_board(board);
        unsigned short option = tictactoe::get_menu_option();
        switch (option)
        {
        case 1:
            tictactoe::two_player_game_loop(board);
            break;
        // FIXME: call single-player game loop against computer for option 2
        case 3:
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            loop = false;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            continue; // Skip the rest of the loop and show the menu again
        }
    }
    return 0;
}