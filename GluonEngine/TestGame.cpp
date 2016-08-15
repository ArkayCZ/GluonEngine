#include "src/Game.h"

#define WIDTH 1280
#define HEIGHT 720

class TestGame : public ge::Game
{
	
public:
	TestGame()
		: Game("Test game")
	{
		
	}

	virtual ~TestGame() override {

	}

	void OnInit() override {
		this->CreateWindow(WIDTH, HEIGHT, false);
	}
};

int main()
{
	TestGame* game = new TestGame();
	game->Start();
	delete game;
	return 0;
}