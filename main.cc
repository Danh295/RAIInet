

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include "game_x.h"
#include "player_x.h"
#include "board.h"
#include "text.h"
#include "boardsetup.h"
#include "linkboostdecorator.h"
#include "movedecorator.h"
#include "kingcrimsondecorator.h"
#include "firewalldecorator.h"

using namespace std;

// TODO: 1. determine how to track which player's turn it is
// TODO: 2. handle player commands specific to current player turn
// TODO: 3. handle win/loss conditions

int main () {

    // INITIALIZATION ----------------------------------------------------------------

    int numPlayers;
    cin >> numPlayers;

    cout<<numPlayers<<endl;

    // Board init
    Board* board = new BoardSetup(numPlayers); 

    // Game init
    Game game{board ,numPlayers }; // assumes Game ctor takes raw ptr
    // Game game {board};

    // Player setup
    // ! IF PLAYERS DON'T EXIST, THEN POINTER BECOMES NULL AND CAN LEAD TO ISSUES FOR >2 PLAYERS (mitigate for now by js commenting it out)
    
    for(int id = 1; id <= numPlayers; id++){
        game.addPlayers(id); // assumes addPlayers(id) takes int and creates a Player object with it
    }

    Player* p1= game.getPlayer(0);
    Player* p2= game.getPlayer(1);
    
    // Ability IDs init
    const vector<char> longTermLinkAbilitiesId = {'L','M'}; // abilities with lasting status effect on the link (sticks to it)
    const vector<char> attackAbilitiesId = {'D','S','P'}; // abilities used for attacking


    std::vector<Observer*> observers;
    

    // GAME LOOP ------------------------------------------------------------------------
    int turn = 0;

    Text *a1 = new Text(&game, 0);
    observers.emplace_back(a1);
    // Text *a2 = new Text(&game, 1);
    // observers.emplace_back(a2);
    string command;
    while (cin >> command){ // Player input command
        cerr << "Current turn: " << turn << command<< endl;

        // SETUP COMMANDS --------------------------------

        // Specifies abilities for player 1
            // Default: "LFDSP"
        if(command == "-ability1"){
            std::string abilities;
            
            if(cin>> abilities){
                for(size_t i=0; i<abilities.size(); i++){
                    p1->setAbility(i, abilities[i]);
                }
            }//otherwise it is already internally setup
        }
        // Specifies abilities for player 2
            // Default: "LFDSP"
        else if (command == "-ability2"){
            
            std::string abilities;
            if(cin>> abilities){

                for(size_t i=0; i<abilities.size(); i++){
                    p2->setAbility(i, abilities[i]);
                }    
            }
        
        // Specifies link tokens for player 1
        }else if (command == "-link1"){

            // TODO: remove redundant code duplication by checking for "-link" and 
            // then updating it for the specified player accordingly afterwards

            // Get input file for link tokens
            string fileName;
            if (cin >> fileName) {
                ifstream file(fileName);

                // TODO: use try catch for error handling???
                if (!file.is_open()) {
                    cerr << "Error: Could not open file: " << fileName << endl;
                    return 1;
                }

                // Assign link tokens to player 1 
                vector<string> linkTokens;
                string token;
                int i = 0;

                while (i < 8 && file >> token) {
                    linkTokens.emplace_back(token);

                    bool virus = (token[0] != 'D');
                    int strength = token[1] - '0'; // convert char to int using ascii
                    p1->setLink(i, strength, virus);
                    i++;
                }
                if (linkTokens.empty()){
                    p1->setRandomLinks();
                    cerr << "Error: No tokens found in file. Random values initialized." << endl;
                }

            } else {
                cerr << "Error: Missing file name for link tokens" << endl;
                return 1;
            } 

        // Specifies link tokens for player 2
        }else if(command == "-link2"){
            cout<<"link2"<<endl;
            
            // Get input file for link tokens
            string fileName;
            if (cin >> fileName) {
                ifstream file(fileName);

                // TODO: use try catch for error handling???
                if (!file.is_open()) {
                    cerr << "Error: Could not open file: " << fileName << endl;
                    return 1;
                }

                // Assign link tokens to player 1 
                vector<string> linkTokens;
                string token;
                int i = 0;

                while (i < 8 && file >> token) {
                    linkTokens.emplace_back(token);

                    bool virus = (token[0] != 'D');
                    int strength = token[1] - '0'; // convert char to int using ascii
                    p2->setLink(i, strength, virus);

                    i++;
                }

                if (linkTokens.empty()){
                    p2->setRandomLinks();
                    cerr << "Error: No tokens found in file. Random values initialized." << endl;
                }

            } else {
                cerr << "Error: Missing file name for link tokens" << endl;
                return 1;
            } 

        
        // TODO: check implementation & ensure functional display
        } else if (command == "-graphics") {
            // game.graphics();

        // INTERACTIVE COMMANDS ---------------------------------------------------------

        // "move a <dir>" moves the link 'a' in the direction 'dir'
            // a has to be a link the currrent player controls
            // dir can be 'U', 'D', 'L', or 'R'
        } else if (command == "move") {
            char link, dir;
            std::cin >> link;
            

            char linkAbilityId = game.getAbilityIdThatAffectMovement(turn%numPlayers, link);
            
            cout <<link <<"link, ability "<< linkAbilityId<<" yo"<<endl;
            if(linkAbilityId=='L'){//linkboost
                std::cin >> dir;
                if(game.checkClashOnSquare(turn%numPlayers, link, dir, 2)){
                    game.board() = new LinkBoostDecorator(game.board(), link, dir, game.getLinkPositions());
                }
            }
            else{ //normal movement
                std::cin >> dir;
                if(game.checkClashOnSquare(turn%numPlayers, link, dir, 1)){
                    cout << "display "<<game.board()->displayAt(7,0)<< game.board()->displayAt(6,0)<< endl;
                    game.board() = new MoveDecorator(game.board(), link, dir, game.getLinkPositions());
                    cout << "display "<<game.board()->displayAt(7,0)<< game.board()->displayAt(6,0)<< endl;
                }
            }
            turn++;
            
        
        // "ability <N>" uses ability with ID 'N', with some abilities requiring additional info
            // Linkboost: "ability <L> b" attaches linkboost to link 'b'
            // Firewall: "ability <F> x y" creates a firewall at position (x, y)
            // Download: "ability <D> b" immediately downloads the opponent's link 'b'
            // Polarize: "ability <P> b" changes the targeted data to a virus or vice versa for link 'b'
            // Scan: "ability <S> b" reveals the type and strength of any opponent link 'b'
            // MadeInHeaven: "ability <M> b: attaches permanent ability protection on link 'b'
            // KingCrimson: "ability <K> b x y" moves link 'b' to position (x, y)
            // Jumper: "ability <J>" skips the opponent's next turn (player gets 2 turns)
        } else if (command == "ability") {
            cout << "lol";
            int order, x, y;
            char link;
            cin >> order;
            
            char ability_id = game.getPlayerAbilityById(turn%numPlayers, order);
            cout<<ability_id<<" ability_id"<<endl;
            if(ability_id =='.'){
                cerr << "Error: invalid ability ID" << endl;
            }
            else if (find(longTermLinkAbilitiesId.begin(), longTermLinkAbilitiesId.end(), ability_id) != longTermLinkAbilitiesId.end()) {
                cin>>link;
                cout << "longterm";
                game.playerAbilityToPlayerLink(turn, link, ability_id);
            }
            else if (find(attackAbilitiesId.begin(), attackAbilitiesId.end(), ability_id) != attackAbilitiesId.end()) {
                cin >> link;
                cout << "shortterm";
                game.playerAbilityToOpponentLink(turn, link, ability_id);
            }
            else if (ability_id =='F') { // Firewall
                cin >> x >> y ;
                
                game.board() = new FirewallDecorator(game.board(), turn, numPlayers, x, y, game.getLinkPositions());
            }
            else if (ability_id == 'J') { // Jumper
                turn++;
                continue; // skips to next iteration immediately
            }
            else if(ability_id == 'K') { // KingCrimson
                cin >>link>> x >> y ;
                game.board() = new KingCrimsonDecorator(game.board(), link, x, y, game.getLinkPositions());
            }

        // Display abilities possessed by the current player
            // Display ability ID (1 - 8)
            // Display if ability has been used
        } else if (command == "abilities") {
            // game.displayAbilities(turn);  implement this next

        // Display the current board to the graphics section
        } else if (command == "board") {
            game.render();

        // Exit the game
        } else if (command == "quit" || command == "q") {
            cout << "Game exited successfully!" << endl;
            return 0;
        } else {
            cerr << "Error: invalid command. Please try again. " << endl;
        }

        // WIN/LOSS CONDITIONS ----------------------------------------------------------
        if (game.findWinner() != 0) {
            cout << "Congratulations! Player " <<  game.findWinner() << ", you have won the game!" << endl;
        } 
        // if (game.findLoser() != 0) {
        //     cout << "Sorry! Player " << game.findLoser() << ", you've downloaded 4 viruses, you have lost the game!" << endl;
        // }

    }
}