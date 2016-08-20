#include "src/Game.h"
#include "TestLayer.h"
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
		LOG("Total components count: " << COMPONENT_COUNT);

		GetWindow()->EnableVSync(true);
		GetWindow()->GetRenderDevice()->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		SetRenderer(new ge::graphics::BufferedRenderer(GetWindow()->GetRenderDevice(), GetWindow()->GetRenderTarget()));

		PushLayer(new TestLayer(this));
	}
};

int main()
{
	TestGame game;
	game.Start();
	return 0;
}