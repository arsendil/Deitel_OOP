#include <gtest/gtest.h>
#include "headers/Board.hpp"
#include "headers/Player.hpp"
#include "headers/TicTacToe.hpp"


TEST(BoardTest, InitBoardIsEmpty)
{
    Board board;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            EXPECT_TRUE(board.isCellEmpty(i, j));
        }
    }
}

TEST(BoardTest, SetCellAndCheckEmpty)
{
    Board board;
    board.setCell(1, 1, 'X');
    EXPECT_FALSE(board.isCellEmpty(1, 1));
    EXPECT_TRUE(board.isCellEmpty(0, 0));
}

TEST(BoardTest, HorizontalWinDetect)
{
    Board board;
    board.setCell(0, 0, 'X');
    board.setCell(0, 1, 'X');
    board.setCell(0, SIZE - 1, 'X');
    EXPECT_TRUE(board.isWin('X'));
}

TEST(BoardTest, VerticalWinDetect)
{
    Board board;
    board.setCell(0, 0, 'O');
    board.setCell(1, 0, 'O');
    board.setCell(SIZE - 1, 0, 'O');
    EXPECT_TRUE(board.isWin('O'));
}

TEST(BoardTest, DiagonalWinDetect)
{
    Board board;
    board.setCell(0, 0, 'X');
    board.setCell(1, 1, 'X');
    board.setCell(SIZE - 1, SIZE - 1, 'X');
    EXPECT_TRUE(board.isWin('X'));
}

TEST(BoardTest, BoardIsEndDetect)
{
    Board board;
    char symbols[SIZE][SIZE] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'}
    };
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            board.setCell(i, j, symbols[i][j]);
        }
    }
    EXPECT_TRUE(board.isEnd());
}

TEST(PlayerTest, ConstructorAndGetters)
{
    Player p("Alice", 'X');
    EXPECT_EQ(p.getPlayerName(), "Alice");
    EXPECT_EQ(p.getChoice(), 'X');
}

TEST(PlayerTest, SettersWork)
{
    Player p("Alice", 'X');
    p.setPlayerName("Bob");
    p.setChoice('O');
    EXPECT_EQ(p.getPlayerName(), "Bob");
    EXPECT_EQ(p.getChoice(), 'O');
}

TEST(PlayerTest, playGame)
{
    Player p1("Gago", 'X');
    Player p2("Hamo", '0');
    Board b1;
    TicTacToe game1(p1, p2, b1);
    game1.playGame();
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
