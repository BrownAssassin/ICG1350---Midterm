#include "Game.h"

int main()
{
	Game game("TestOpenGL", 800, 600, 4, 4, false);
 
	//MAIN LOOP
	while (!game.getWindowShouldClose())
	{
		//UPDATE INPUT ---
		game.update();
		game.render();
		
	}    
	
	return 0; 
}