#include "../headers/Board.hpp"

#include <cassert>
#include <iostream>

Board::Board()
{
    init();
}

void
Board::init()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board_[i][j] = ' ';
        }
    }
}

void
Board::setCell(const int row, const int column, const char choice)
{
    assert(row >= 0 && row < SIZE && column >= 0 && column < SIZE);
    assert(isCellEmpty(row, column));
    board_[row][column] = choice;
}

bool
Board::isWin(const char choice) const
{
    return isHorizontalWin(choice) || isVerticalWin(choice) || isAngularWin(choice);
}

bool
Board::isEnd() const
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (' ' == board_[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool
Board::isCellEmpty(const int row, const int column) const
{
    return ' ' == board_[row][column];
}

bool
Board::isHorizontalWin(const char choice) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (isHorizontalWinByI(choice, i)) {
            return true;
        }
    }
    return false;
}

bool
Board::isVerticalWin(const char choice) const 
{
    for (int j = 0; j < SIZE; ++j) {
        if (isVerticalWinByJ(choice, j)) {
            return true;
        }
    }
    return false;
}

bool
Board::isAngularWin(const char choice) const
{
    bool mainDiag = true;
    bool antiDiag = true;

    for (int i = 0; i < SIZE; ++i) {
        if (board_[i][i] != choice) {
            mainDiag = false;
        }
        if (board_[i][SIZE - 1 - i] != choice) {
            antiDiag = false;
        }
    }
    return mainDiag || antiDiag;
}

bool
Board::isHorizontalWinByI(const char choice, const int indexI) const
{
    for (int j = 0; j < SIZE; ++j) {
        if (board_[indexI][j] != choice) {
            return false;
        }
    }
    return true;
}

bool
Board::isVerticalWinByJ(const char choice, const int indexJ) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (board_[i][indexJ] != choice) {
            return false;
        }
    }
    return true;
}

void
Board::printBoard() const
{
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << " " << board_[i][j];
            if (j < SIZE - 1) std::cout << " |";
        }
        std::cout << "\n";
        if (i < SIZE - 1) {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << std::endl;;
}

