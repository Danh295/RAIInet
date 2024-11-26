# RAIInet

RAIInet(similar in style to Stratego) is a game played between two opposing players, who take on the role of computer hackers. 
Each player controls eight pieces, called links.There are two different kinds of links: viruses and data. 
Each player has two goals:
• Download four data.
• Make their opponent download four viruses.
Upon achieving either goal, the player wins the game.
A game of RAIInet consists of an 8 × 8 board on which players initially place links face-down. 
In this way, only the player who placed the link knows whether it is data or a virus.
Play then proceeds in turns. On each player’s turn, a player may use a single ability, and then must move one of their links in any cardinal direction.
When a player moves a link off their opponent’s end of the board, they immediately download it. 
When a player moves a link onto their opponent’s server ports, their opponent downloads it. 
Additionally, when a player’s link loses to an opponent’s link in battle, their opponent immediately downloads it.
These mechanics are explained in greater detail below.
As which links are viruses and which links are data is hidden information, you can keep your opponent guessing as to what your game plan is!


The base logic is that anything affecting the player or board directly should be handle by the game class. the game also triggers all changes to the link class. for ex if a new ability is applied to the link and when it is applied. 
