#pragma once
#include "Component.h"

class Texture2D;

class SpriteComponent :
	public Component
{
public:
	/// <param name = "texture"> Sets the sprite's image to the texture </param>
	/// <param name = "name"> The name of the compotent instance </param>
	SpriteComponent(Texture2D* texture, const char* name = "SpriteComponent");

	/// <param name = "path"> the path of the texture to load </param>
	/// <param name = "name"> The name of the compotent instance </param>
	SpriteComponent(const char* path, const char* name = "SpriteComponent");
	~SpriteComponent() override;

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

