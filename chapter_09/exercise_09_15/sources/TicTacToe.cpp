#include "../headers/TicTacToe.hpp"

#include <iostream>
#include <cassert>

TicTacToe::TicTacToe(Player& player1, Player& player2, Board& board) : player1_(player1), player2_(player2), board_(board)
{
    assert(player1_.getChoice() != player2_.getChoice());
}

int
TicTacToe::input() const
{
    int number1;
    std::cin >> number1;
    return number1;
}

bool
TicTacToe::isGameOver(const Player* player) const
{
    return board_.isWin(player->getChoice()) || board_.isEnd();
}

void
TicTacToe::printStatus(const Player* player) const
{
    std::cout << "\nCurrent board:\n";
    board_.printBoard();
    std::cout << "Next move: " << player->getPlayerName() << " (" << player->getChoice() << ")\n";
}

void
TicTacToe::playGame()
{
    int i = 0;
    while (true) {
        Player* players[] = {&player1_, &player2_};
        printStatus(players[i]);

        const int row = input() - 1;
        const int column = input() - 1;

        if (row < 0 || row >= SIZE || column < 0 || column >= SIZE) {
            std::cout << "Warning 1: Please input values between 1 and " << SIZE << "!\n";
            continue;
        }
        if (!board_.isCellEmpty(row, column)) {
            std::cout << "Warning 2: Cell already occupied. Try again!\n";
            continue;
        }

        board_.setCell(row, column, players[i]->getChoice());
        
        if (board_.isWin(players[i]->getChoice())) {
            printStatus(players[i]);
            std::cout << players[i]->getPlayerName() << " wins!\n";
            return;
        }
        if (board_.isEnd()) {
            printStatus(players[i]);
            std::cout << "It's a draw!\n";
            return;
        }

        i = (i + 1) % 2;
    }
}

