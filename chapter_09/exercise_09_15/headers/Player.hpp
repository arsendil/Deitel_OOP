#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>

class Player
{
public:
    Player(const std::string& playerName = "Haykaz", const char choice = 'X');
    std::string getPlayerName() const;
    char getChoice() const;
    void setPlayerName(const std::string& playerName);
    void setChoice(const char choice);

private:
    std::string playerName_;
    char choice_;
};

#endif /// __PLAYER_HPP__

