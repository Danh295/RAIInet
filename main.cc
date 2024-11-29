

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "player_x.h"
#include "board_x.h"

using namespace std;

// TODO: 1. determine how to track which player's turn it is
// TODO: 2. handle player commands specific to current player turn
// TODO: 3. handle win/loss conditions

int main () {

    // INITIALIZATION ----------------------------------------------------------------

    int numPlayers;
    cin >> numPlayers;

    // Board init
    unique_ptr<Board> board = make_unique<Board>(numPlayers);
    // Board* board = new BoardSetup{numPlayers}; 

    // Game init
    Game game{board.get()}; // assumes Game ctor takes raw ptr
    // Game game {board};

    // Player setup
    // ! IF PLAYERS DON'T EXIST, THEN POINTER BECOMES NULL AND CAN LEAD TO ISSUES FOR >2 PLAYERS (mitigate for now by js commenting it out)
    
    for(int id = 1; id <= number_of_players; id++){
        game.addPlayers(id); // assumes addPlayers(id) takes int and creates a Player object with it
    }

    Player* p1= game->getPlayer(1);
    Player* p2= game->getPlayer(2);
    // Player* p3= game->getPlayer(3);
    // Player* p4= game->getPlayer(4);
    // Player* p3= game->getPlayer(3);
    // Player* p4= game->getPlayer(4);
    
    // Ability IDs init
    const vector<int> longTermLinkAbilitiesId = {'L','M'}; // abilities with lasting status effect on the link (sticks to it)
    const vector<int> attackAbilitiesId = {'D','S','P'}; // abilities used for attacking

    // GAME LOOP ------------------------------------------------------------------------
    int turn = 0;
    string command;
    while (cin >> command){ // Player input command
        cerr << "Curreent turn: " << turn << endl;

        // SETUP COMMANDS --------------------------------

        // Specifies abilities for player 1
            // Default: "LFDSP"
        if(command == "-ability1"){

            std::string abilities;
            
            if(cin>> abilities){
                for(int i=0; i<size(abilities); i++){
                    p1->setAbility(i, abilities[i]);
                }
            }
            else{
                p1->setDefaultAbilities();
            }
        }
        // Specifies abilities for player 2
            // Default: "LFDSP"
        else if (command == "-ability2"){
            
            std::string abilities;
            cin>> abilities;

            if(cin>> abilities){
                for(int i=0; i<size(abilities); i++){
                    p2->setAbility(i, abilities[i]);
                }    
            }
            else{
                p2->setDefaultAbilities();
            }

        // // Specifies abilities for player 3
        // // NOTE: not necessary at the moment (not implemented yet)
        // // }else if (command == "-ability3"){
            
        //     std::string abilities;
        //     cin >> abilities;

        //     if(abilities == ""){
        //         p3->setDefaultAbilities();
        //     }else{
        //         for(int i = 0; i < size(abilities); i++){
        //             if(abilities[i] == 'L'){
        //                 p3->setAbility(i, new Linkboost());
        //             }
        //             else if(abilities[i] == 'F'){
        //                 p3->setAbility(i, new Firewall());
        //             }
        //             else if(abilities[i] == 'D'){
        //                 p3->setAbility(i, new Download());
        //             }
        //             else if(abilities[i] == 'S'){
        //                 p3->setAbility(i, new Scan());
        //             }
        //             else if(abilities[i] == 'P'){
        //                 p3->setAbility(i, new Polarize());
        //             }
        //             else if(abilities[i] == 'Z'){
        //                 p3->setAbility(i, new Z());
        //             }
        //             else if(abilities[i] == 'K'){
        //                 p3->setAbility(i, new KingCrimson());
        //             }
        //             else if(abilities[i] == 'M'){
        //                 p3->setAbility(i, new MadeInHaven());
        //             }
        //         }
        //     }

        // // Specifies abilities for player 3
        // // NOTE: not necessary at the moment (not implemented yet)
        // }else if (command == "-ability4"){
            
        //     std::string abilities;
        //     cin >> abilities;
        //     std::string abilities;
        //     cin >> abilities;

        //     if(abilities == ""){
        //         p4->setDefaultAbilities();
        //     }else{
        //         for(int i = 0; i < size(abilities); i++){
        //             if(abilities[i] == 'L'){
        //                 p4->setAbility(i, new Linkboost());
        //             }
        //             else if(abilities[i] == 'F'){
        //                 p4->setAbility(i, new Firewall());
        //             }
        //             else if(abilities[i] == 'D'){
        //                 p4->setAbility(i, new Download());
        //             }
        //             else if(abilities[i] == 'S'){
        //                 p4->setAbility(i, new Scan());
        //             }
        //             else if(abilities[i] == 'P'){
        //                 p4->setAbility(i, new Polarize());
        //             }
        //             else if(abilities[i] == 'Z'){
        //                 p4->setAbility(i, new Z());
        //             }
        //             else if(abilities[i] == 'K'){
        //                 p4->setAbility(i, new KingCrimson());
        //             }
        //             else if(abilities[i] == 'M'){
        //                 p4->setAbility(i, new MadeInHaven());
        //             }
        //         }
        //     }

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
                    linkToken.emplace_back(token);

                    bool virus = (token[0] != 'D');
                    int strength = token[1] - '0'; // convert char to int using ascii
                    p1->setLink(i, strength, virus);

                    i++;
                }

                if (linkTokens.empty()){
                    p1->setRandomLinks();
                    cerr << "Error: No tokens found in file. Random values initialized." << endl;
                }
        //     if(abilities == ""){
        //         p4->setDefaultAbilities();
        //     }else{
        //         for(int i = 0; i < size(abilities); i++){
        //             if(abilities[i] == 'L'){
        //                 p4->setAbility(i, new Linkboost());
        //             }
        //             else if(abilities[i] == 'F'){
        //                 p4->setAbility(i, new Firewall());
        //             }
        //             else if(abilities[i] == 'D'){
        //                 p4->setAbility(i, new Download());
        //             }
        //             else if(abilities[i] == 'S'){
        //                 p4->setAbility(i, new Scan());
        //             }
        //             else if(abilities[i] == 'P'){
        //                 p4->setAbility(i, new Polarize());
        //             }
        //             else if(abilities[i] == 'Z'){
        //                 p4->setAbility(i, new Z());
        //             }
        //             else if(abilities[i] == 'K'){
        //                 p4->setAbility(i, new KingCrimson());
        //             }
        //             else if(abilities[i] == 'M'){
        //                 p4->setAbility(i, new MadeInHaven());
        //             }
        //         }
        //     }

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
                    linkToken.emplace_back(token);

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
            } else {
                cerr << "Error: Missing file name for link tokens" << endl;
                return 1;
            } 

        // Specifies link tokens for player 2
        }else if(command == "-link2"){
            
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
                    linkToken.emplace_back(token);

                    bool virus = (token[0] != 'D');
                    int strength = token[1] - '0'; // convert char to int using ascii
                    p2->setLink(i, strength, virus);

                    i++;
                }

                if (linkTokens.empty()){
                    p2->setRandomLinks();
                    cerr << "Error: No tokens found in file. Random values initialized." << endl;
                }
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
                    linkToken.emplace_back(token);

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

        // // Specifies link tokens for player 3
        // } else if (command == "-link3"){
            } else {
                cerr << "Error: Missing file name for link tokens" << endl;
                return 1;
            } 

        // // Specifies link tokens for player 3
        // } else if (command == "-link3"){
            
        //     // Get input file for link tokens
        //     string fileName;
        //     if (cin >> fileName) {
        //         ifstream file(fileName);

        //         // TODO: use try catch for error handling???
        //         if (!file.is_open()) {
        //             cerr << "Error: Could not open file: " << fileName << endl;
        //             return 1;
        //         }

        //         // Assign link tokens to player 1 
        //         vector<string> linkTokens;
        //         string token;
        //         int i = 0;

        //         while (i < 8 && file >> token) {
        //             linkToken.emplace_back(token);

        //             bool virus = (token[0] != 'D');
        //             int strength = token[1] - '0'; // convert char to int using ascii
        //             p3->setLink(i, strength, virus);

        //             i++;
        //         }

        //         if (linkTokens.empty()){
        //             p3->setRandomLinks();
        //             cerr << "Error: No tokens found in file. Random values initialized." << endl;
        //         }
        //     // Get input file for link tokens
        //     string fileName;
        //     if (cin >> fileName) {
        //         ifstream file(fileName);

        //         // TODO: use try catch for error handling???
        //         if (!file.is_open()) {
        //             cerr << "Error: Could not open file: " << fileName << endl;
        //             return 1;
        //         }

        //         // Assign link tokens to player 1 
        //         vector<string> linkTokens;
        //         string token;
        //         int i = 0;

        //         while (i < 8 && file >> token) {
        //             linkToken.emplace_back(token);

        //             bool virus = (token[0] != 'D');
        //             int strength = token[1] - '0'; // convert char to int using ascii
        //             p3->setLink(i, strength, virus);

        //             i++;
        //         }

        //         if (linkTokens.empty()){
        //             p3->setRandomLinks();
        //             cerr << "Error: No tokens found in file. Random values initialized." << endl;
        //         }

        //     } else {
        //         cerr << "Error: Missing file name for link tokens" << endl;
        //         return 1;
        //     } 

        // // Specifies link tokens for player 4
        // }else if (command == "-link4"){
        //     } else {
        //         cerr << "Error: Missing file name for link tokens" << endl;
        //         return 1;
        //     } 

        // // Specifies link tokens for player 4
        // }else if (command == "-link4"){
            
        //     // Get input file for link tokens
        //     string fileName;
        //     if (cin >> fileName) {
        //         ifstream file(fileName);

        //         // TODO: use try catch for error handling???
        //         if (!file.is_open()) {
        //             cerr << "Error: Could not open file: " << fileName << endl;
        //             return 1;
        //         }

        //         // Assign link tokens to player 1 
        //         vector<string> linkTokens;
        //         string token;
        //         int i = 0;

        //         while (i < 8 && file >> token) {
        //             linkToken.emplace_back(token);

        //             bool virus = (token[0] != 'D');
        //             int strength = token[1] - '0'; // convert char to int using ascii
        //             p3->setLink(i, strength, virus);

        //             i++;
        //         }

        //         if (linkTokens.empty()){
        //             p3->setRandomLinks();
        //             cerr << "Error: No tokens found in file. Random values initialized." << endl;
        //         }
        //     // Get input file for link tokens
        //     string fileName;
        //     if (cin >> fileName) {
        //         ifstream file(fileName);

        //         // TODO: use try catch for error handling???
        //         if (!file.is_open()) {
        //             cerr << "Error: Could not open file: " << fileName << endl;
        //             return 1;
        //         }

        //         // Assign link tokens to player 1 
        //         vector<string> linkTokens;
        //         string token;
        //         int i = 0;

        //         while (i < 8 && file >> token) {
        //             linkToken.emplace_back(token);

        //             bool virus = (token[0] != 'D');
        //             int strength = token[1] - '0'; // convert char to int using ascii
        //             p3->setLink(i, strength, virus);

        //             i++;
        //         }

        //         if (linkTokens.empty()){
        //             p3->setRandomLinks();
        //             cerr << "Error: No tokens found in file. Random values initialized." << endl;
        //         }

        //     } else {
        //         cerr << "Error: Missing file name for link tokens" << endl;
        //         return 1;
        //     } 
        // TODO: check implementation & ensure functional display
        } else if (command == "-graphics") {
        //     } else {
        //         cerr << "Error: Missing file name for link tokens" << endl;
        //         return 1;
        //     } 
        // TODO: check implementation & ensure functional display
        } else if (command == "-graphics") {
            game.graphics();

        // INTERACTIVE COMMANDS ---------------------------------------------------------

        // "move a <dir>" moves the link 'a' in the direction 'dir'
            // a has to be a link the currrent player controls
            // dir can be 'U', 'D', 'L', or 'R'
        } else if (command == "move") {
            char link, dir;
            std::cin >> link;

            char linkAbilityId = game.getAbilityIdThatAffectMovement(turn%number_of_players, link);

            if(linkAbilityId=='L'){//linkboost
                stc::cin >> dir;
                if(checkClashOnSquare(turn%number_of_players, link, dir, 2)){
                    game.Board() = new LinkBoostDecorator(game.Board(), link, dir, game.getLinkPositions());
                }
            }
            else{ //normal movement
                stc::cin >> dir;
                if(checkClashOnSquare(turn%number_of_players, link, dir, 2)){
                    game.Board() = new MoveDecorator(game.Board(), link, dir, game.getLinkPositions());
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
            int order, x, y;
            char link;
            cin >> order;
            cin >> order;
            char ability_id = game.getPlayerAbilityId(turn, order);

            if(ability_id ==''){
                cerr << "Error: invalid ability ID" << endl;
                cerr << "Error: invalid ability ID" << endl;
            }
            else if (find(longTermLinkAbilitiesId.begin(), longTermLinkAbilitiesId.end(), ability_id) != longTermLinkAbilitiesId.end()) {
            else if (find(longTermLinkAbilitiesId.begin(), longTermLinkAbilitiesId.end(), ability_id) != longTermLinkAbilitiesId.end()) {
                game.playerAbilityToPlayerLink(turn, link, ability_id);
            }
            else if (find(attackAbilitiesId.begin(), attackAbilitiesId.end(), ability_id) != attackAbilitiesId.end()) {
            else if (find(attackAbilitiesId.begin(), attackAbilitiesId.end(), ability_id) != attackAbilitiesId.end()) {
                game.playerAbilityToOpponentLink(turn, link, ability_id);
            }
            else if (ability_id =='F') { // Firewall
                cin >> x >> y ;
            else if (ability_id =='F') { // Firewall
                cin >> x >> y ;
                
                game.Board() = new FirewallDecorator(game.Board(), turn, numPlayers, x, y, game.getLinkPositions());
                game.Board() = new FirewallDecorator(game.Board(), turn, numPlayers, x, y, game.getLinkPositions());
            }
            else if (ability_id == 'J') { // Jumper
            else if (ability_id == 'J') { // Jumper
                turn++;
                continue; // skips to next iteration immediately
                continue; // skips to next iteration immediately
            }
            else if(ability_id == 'K') { // KingCrimson
                cin >>link>> x >> y ;
            else if(ability_id == 'K') { // KingCrimson
                cin >>link>> x >> y ;
                game.Board() = new KingCrimsonDecorator(game.Board(), link, x, y, game.getLinkPositions());
            }

        // Display abilities possessed by the current player
            // Display ability ID (1 - 8)
            // Display if ability has been used
        } else if (command == "abilities") {

        // Display abilities possessed by the current player
            // Display ability ID (1 - 8)
            // Display if ability has been used
        } else if (command == "abilities") {
            game.displayAbilities(turn);

        // Display the current board to the graphics section
        } else if (command == "board") {

        // Display the current board to the graphics section
        } else if (command == "board") {
            gameboard.render();

        // Exit the game
        } else if (command == "quit" || command == "q") {
            cout << "Game exited successfully!" << endl;
            return 0;
        } else {
            cerr << "Error: invalid command. Please try again. " << endl;

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