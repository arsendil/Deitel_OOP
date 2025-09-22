#ifndef __BOARD_HPP__
#define __BOARD_HPP__

const int SIZE = 3;

class Board
{
public:
    Board();
    void init();
    void printBoard() const;
    void setCell(const int row, const int column, const char choice);
    bool isWin(const char choice) const;
    bool isEnd() const;
    bool isCellEmpty(const int row, const int column) const;

private:
    bool isHorizontalWin(const char choice) const;
    bool isVerticalWin(const char choice) const;
    bool isAngularWin(const char choice) const;
    bool isHorizontalWinByI(const char choice, const int indexI) const;
    bool isVerticalWinByJ(const char choice, const int indexJ) const;

private:
    char board_[SIZE][SIZE];
};


#endif /// __BOARD_HPP__
