#include "GlobalSystem.h"
#include "Console.h"
#include "TextureCache.h"
#include "AnimationLoader.h"

CGlobalSystem::~CGlobalSystem()
{
	delete pStateSystem;
	delete pSpriteBatch;
	delete pWindowSystem;
	delete pEntitySystem;
	delete pInput;
	delete pSpriteRenderer;
	delete pPlayerController;
	delete pClient;
	delete pConsole;
	delete pTextureCache;
	delete pGame;
	delete pAnimLoader;
}

void CGlobalSystem::init()
{
	pWindowSystem = new CWindowSystem;
	pWindowSystem->init(1280, 720);
	pb2World = new b2World(b2Vec2(0.0f, 0.0f));
	pEntitySystem = new CEntitySystem;
	pInput = new CInput;
	pPlayerController = new CPlayerController;
	pSpriteBatch = new CSpriteBatch(1024);
	pStateSystem = new CStateSystem();
	pSpriteRenderer = new CSpriteRenderer;
	pClient = new CClient;
	pConsole = new CConsole;
	pTextureCache = new CTextureCache;
	pClient->init();
	pGame = new CGameState;
	pAnimLoader = new CAnimationLoader;
}

void CGlobalSystem::log(string text)
{
	printf(std::string(text+"\n").c_str());
}
