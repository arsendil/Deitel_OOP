#ifndef __TICTACTOE_HPP__
#define __TICTACTOE_HPP__

#include "Player.hpp"
#include "Board.hpp"

class TicTacToe
{
public:
    TicTacToe(Player& player1, Player& player2, Board& board);
    void playGame();

private:
    void printStatus(const Player* player) const;
    bool isGameOver(const Player* player) const;
    int input() const;

private:
    Player& player1_;
    Player& player2_;
    Board& board_;
};

#endif ///__TICTACTOE_HPP__
