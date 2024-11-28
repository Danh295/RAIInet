


int main () {

    vector <Player*> players;

    int number_of_players;
    cin>> number_of_players;

    Board* board= new BoardSetup{number_of_players}; // 2 is the default num of player

    Game game{board}

    for(int id =1; id<= number_of_players;id++){
        game.addPlayers(id);
    }
    
    std::string command;

    Player* p1= game->getPlayer(1);
    Player* p2= game->getPlayer(2);
    Player* p3= game->getPlayer(3);
    Player* p4= game->getPlayer(4);
    
    const vector<int> longTermLinkAbilitiesId = {'L','M'};//abilities that stick to the link
    const vector<int> attackAbilitiesId = {'D','S','P'};

    while (std::cin >> command) {

        if(command == "-ability1"){

            std::string abilities;
            cin>> abilities;

            if(abilities==""){
                p1->setDefaultAbilities();
            }
            else{
                for(int i=0; i<size(abilities); i++){
                    if(abilities[i] == 'L'){
                        p1->setAbility(i, new Linkboost());
                    }
                    else if(abilities[i] == 'F'){
                        p1->setAbility(i, new Firewall());
                    }
                    else if(abilities[i] == 'D'){
                        p1->setAbility(i, new Download());
                    }
                    else if(abilities[i] == 'S'){
                        p1->setAbility(i, new Scan());
                    }
                    else if(abilities[i] == 'P'){
                        p1->setAbility(i, new Polarize());
                    }
                    else if(abilities[i] == 'Z'){
                        p1->setAbility(i, new Z());
                    }
                    else if(abilities[i] == 'K'){
                        p1->setAbility(i, new KingCrimson());
                    }
                    else if(abilities[i] == 'M'){
                        p1->setAbility(i, new MadeInHaven());
                    }

                }
            }
        }
        else if (command == "-ability2"){
            
            std::string abilities;
            cin>> abilities;

            if(abilities==""){
                p2->setDefaultAbilities();
            }
            else{
                for(int i=0; i<size(abilities); i++){
                    if(abilities[i] == 'L'){
                        p2->setAbility(i, new Linkboost());
                    }
                    else if(abilities[i] == 'F'){
                        p2->setAbility(i, new Firewall());
                    }
                    else if(abilities[i] == 'D'){
                        p2->setAbility(i, new Download());
                    }
                    else if(abilities[i] == 'S'){
                        p2->setAbility(i, new Scan());
                    }
                    else if(abilities[i] == 'P'){
                        p2->setAbility(i, new Polarize());
                    }
                    else if(abilities[i] == 'Z'){
                        p2->setAbility(i, new Z());
                    }
                    else if(abilities[i] == 'K'){
                        p2->setAbility(i, new KingCrimson());
                    }
                    else if(abilities[i] == 'M'){
                        p2->setAbility(i, new MadeInHaven());
                    }

                }
            }
        }
        else if (command == "-ability3"){
            
            std::string abilities;
            cin>> abilities;

            if(abilities==""){
                p3->setDefaultAbilities();
            }
            else{
                for(int i=0; i<size(abilities); i++){
                    if(abilities[i] == 'L'){
                        p3->setAbility(i, new Linkboost());
                    }
                    else if(abilities[i] == 'F'){
                        p3->setAbility(i, new Firewall());
                    }
                    else if(abilities[i] == 'D'){
                        p3->setAbility(i, new Download());
                    }
                    else if(abilities[i] == 'S'){
                        p3->setAbility(i, new Scan());
                    }
                    else if(abilities[i] == 'P'){
                        p3->setAbility(i, new Polarize());
                    }
                    else if(abilities[i] == 'Z'){
                        p3->setAbility(i, new Z());
                    }
                    else if(abilities[i] == 'K'){
                        p3->setAbility(i, new KingCrimson());
                    }
                    else if(abilities[i] == 'M'){
                        p3->setAbility(i, new MadeInHaven());
                    }

                }
            }
        }
        else if (command == "-ability4"){
            
            std::string abilities;
            cin>> abilities;

            if(abilities==""){
                p4->setDefaultAbilities();
            }
            else{
                for(int i=0; i<size(abilities); i++){
                    if(abilities[i] == 'L'){
                        p4->setAbility(i, new Linkboost());
                    }
                    else if(abilities[i] == 'F'){
                        p4->setAbility(i, new Firewall());
                    }
                    else if(abilities[i] == 'D'){
                        p4->setAbility(i, new Download());
                    }
                    else if(abilities[i] == 'S'){
                        p4->setAbility(i, new Scan());
                    }
                    else if(abilities[i] == 'P'){
                        p4->setAbility(i, new Polarize());
                    }
                    else if(abilities[i] == 'Z'){
                        p4->setAbility(i, new Z());
                    }
                    else if(abilities[i] == 'K'){
                        p4->setAbility(i, new KingCrimson());
                    }
                    else if(abilities[i] == 'M'){
                        p4->setAbility(i, new MadeInHaven());
                    }

                }
            }
        }
        else if (command == "-link1"){
            
            vector<string> links;

            while(i<8 && cin>>links[i]){
                bool virus = true;
                int strength = link[i][1];
                if(links[i][0] == "D"){
                    virus = false;
                }
                p1->setLink(i, strength, virus);
                i++;
            }
            if(size(links)==0){
                p1->setRandomLinks();
            }

        }
        else if (command == "-link2"){
            
            vector<string> links;

            while(i<8 && cin>>links[i]){
                bool virus = true;
                int strength = link[i][1];
                if(links[i][0] == "D"){
                    virus = false;
                }
                p2->setLink(i, strength, virus);
                i++;
            }
            if(size(links)==0){
                p2->setRandomLinks();
            }

        }
        else if (command == "-link3"){
            
            vector<string> links;

            while(i<8 && cin>>links[i]){
                bool virus = true;
                int strength = link[i][1];
                if(links[i][0] == "D"){
                    virus = false;
                }
                p3->setLink(i, strength, virus);
                i++;
            }
            if(size(links)==0){
                p3->setRandomLinks();
            }

        }
        else if (command == "-link4"){
            
            vector<string> links;

            while(i<8 && cin>>links[i]){
                bool virus = true;
                int strength = link[i][1];
                if(links[i][0] == "D"){
                    virus = false;
                }
                p4->setLink(i, strength, virus);
                i++;
            }
            if(size(links)==0){
                p4->setRandomLinks();
            }

        }
        else if (command == "-graphics") {
            game.graphics();
        }
        else if (command == "move") {
            char link, dir;
            std::cin >> link;

            char linkAbilityId = game.getAbilityIdThatAffectMovement(turn, link);

            if(linkAbilityId=='L'){//linkboost
                stc::cin >> dir;
                game.Board() = new LinkBoostDecorator(game.Board(), link, dir, game.getLinkPositions());
            }
            else{ //normal movement
                stc::cin >> dir;
                game.Board() = new MoveDecorator(game.Board(), link, dir, game.getLinkPositions());
            }
            turn++;
        }
        else if (command == "ability") {
            int order, x, y;
            char link;
            std::cin >> order;
            char ability_id = game.getPlayerAbilityId(turn, order);

            if(ability_id ==''){
                cout << "you do not have that abilitiy please re-enter the command and an ability you have!"
            }
            else if (find(longTermLinkAbilitiesId.begin(), longTermLinkAbilitiesId.end(), ability_id) != longTermLinkAbilitiesId.end()){
                game.playerAbilityToPlayerLink(turn, link, ability_id);
            }
            else if (find(attackAbilitiesId.begin(), attackAbilitiesId.end(), ability_id) != attackAbilitiesId.end()){
                game.playerAbilityToOpponentLink(turn, link, ability_id);
            }

            else if(ability_id=='F'){
                std::cin >> x >> y ;
                
                game.Board() = new FirewallDecorator(game.Board(), turn, number_of_players, x, y, game.getLinkPositions());
            }
            else if(ability_id=='J'){//Jumper
                turn++;
            }
            else if(ability_id=='K'){
                std::cin >>link>> x >> y ;
                game.Board() = new KingCrimsonDecorator(game.Board(), link, x, y, game.getLinkPositions());
            }
        }
        else if (command == "abilities") {
            game.displayAbilities(turn);
        }
        else if (command == "board") {
            gameboard.render();
        }
        else if (command == "quit" || command == "q") {
        
        }
        else{
            cout << "the command and parameters could not be found, please re-enter the command and parameters!"
        }

        if (game.findWinner()!=0) {
            cout << "player" <<  game.findWinner() << " won!";
        }        

    }
  delete game;
}
