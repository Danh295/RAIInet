#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include "player_x.h"
#include "subject_x.h"

class Board;
class Player;

class Game : public Subject {
private:
    std::unique_ptr<Board> theboard;                   // Use unique_ptr for exclusive ownership of the board
    std::vector<std::shared_ptr<Player>> players;      // Use shared_ptr for players as they might be shared elsewhere
    int number_of_players;

    // Ability categories
    const std::vector<int> longTermLinkAbilitiesId = {'L', 'M'};
    const std::vector<int> shortTermLinkAbilitiesId = {'K'};
    const std::vector<int> attackAbilitiesId = {'D', 'S', 'P'};
    const std::vector<int> squareAbilitiesId = {'F'};
    const std::vector<int> gameAbilitiesId = {'V'};

public:
    // Constructor
    explicit Game(std::unique_ptr<Board> theboard, int number_of_players)
        : theboard{std::move(theboard)}, number_of_players{number_of_players} {}

    // Accessors
    Board& board() const { return *theboard; }  // Return reference to avoid direct ownership changes

    // Game setup
    bool isValidSetup();

    // Gameplay methods
    void opponentAbilityOnSquare(int turn, int row, int col);
    void removeLinkOnBoard(char link_name);
    void playerAbilityToOpponentLink(int turn, char link_name, char ability_id);
    void playerAbilityToPlayerLink(int turn, char link_name, char ability_id);
    int findWinner();

    // Player management
    void addPlayers(int id);
    std::shared_ptr<Player> getPlayer(int id);  // Return shared_ptr to allow shared ownership

    // Board state
    std::unordered_map<char, std::pair<int, int>> getLinkPositions();
    bool checkClashOnSquare(int turn, char linkName, char dir, int move);
    char getState(int row, int col) const override;

    // Abilities
    char getPlayerAbilityById(int id, int idx);
    char getAbilityIdThatAffectMovement(int id, char linkName);

    // Output methods
    void printDownloaded(int id);
    void printPlayerAbilityCount(int id);
    void printLinks(int id);
    void printOpponentLinks(int id);

    // Rendering and animations
    void render();
    void animate(int turn);
};

#endif
