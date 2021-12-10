#include "StartingScene.h"

void StartingScene::start()
{
	m_playerChar = new Player(300, 300, 'p', 30, MathLibrary::Vector2(30, 30));

}
