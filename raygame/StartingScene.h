#pragma once
#include "Scene.h"
class StartingScene :
	public Scene
{
public:
	void start() override;

private:
	Player* m_playerChar;
};

