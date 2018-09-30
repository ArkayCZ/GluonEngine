#include "src/Game.h"
#include "TestLayer.h"
#include "TestLayer2D.h"
#include "src/Graphics/BufferedRenderer.h"

#define WIDTH 1440
#define HEIGHT 900

using namespace ge;

class TestGame : public Game
{
public:
	TestGame() : Game("Test game", WIDTH, HEIGHT, false)
	{
		
	}

	~TestGame()
	{
		
	}

	void OnInit() override 
	{
		this->GetWindow()->EnableVSync(true);
		this->GetWindow()->GetRenderDevice()->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		this->PushLayer(new TestLayer2D(this));
	}
};

int main()
{
	TestGame game;
	game.Start();
	return 0;
}