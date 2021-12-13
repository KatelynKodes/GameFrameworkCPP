#include "StartingScene.h"
#include "SpriteComponent.h"
#include "PlayerMovement.h"

void StartingScene::start()
{
	m_playerChar = new Player(300, 300, "p", 30, MathLibrary::Vector2(30, 30));
	m_playerChar->getTransform()->setScale(MathLibrary::Vector2(50,50));

	addActor(m_playerChar);
}
