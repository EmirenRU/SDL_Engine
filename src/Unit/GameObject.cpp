#include "GameObject.hpp"

GameObject::GameObject() 
{

}

GameObject::GameObject(const char* textureSheet, const int& x, const int& y, const int& width, const int& height)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	xpos = x;
	ypos = y;

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = x;
	srcRect.y = y;
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	destRect = { (++xpos) % 800, (++ypos) % 800, 32, 32};
}

void GameObject::Render()
{
	SDL_RenderCopy(Engine::getRenderer(), objTexture, &srcRect, &destRect);
}

void GameObject::FreeObject()
{

}