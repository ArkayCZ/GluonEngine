#include "src/Game.h"

#define WIDTH 1280
#define HEIGHT 720

class TestGame : public ge::Game
{
	
public:
	TestGame() : Game("Test game", 1280, 720, false)
	{
		
	}

	void OnInit() override 
	{

	}
};

int main()
{
	TestGame* game = new TestGame();
	game->Start();
	delete game;
	return 0;
}