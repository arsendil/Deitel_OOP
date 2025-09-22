#include "../headers/Player.hpp"

Player::Player(const std::string& playerName, const char choice)
{
    setPlayerName(playerName);
    setChoice(choice);
}

std::string
Player::getPlayerName() const
{
    return playerName_;
}

char
Player::getChoice() const
{
    return choice_;
}

void
Player::setPlayerName(const std::string& playerName)
{
    playerName_ = playerName;
}

void
Player::setChoice(const char choice)
{
    choice_ = choice;
}

