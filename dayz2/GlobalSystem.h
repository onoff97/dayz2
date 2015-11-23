#pragma once
#include "EntitySystem.h"
#include "Input.h"
#include <string>
#include "SpriteBatch.h"
#include "StateSystem.h"
#include "SpriteRenderer.h"
#include "PlayerController.h"
#include "Client.h"
#include <cstdint>
#include "WindowSystem.h"

typedef std::string string;

class CGlobalSystem
{
public:
	CGlobalSystem() {};
	~CGlobalSystem();
	void init();

	CWindowSystem* pWindowSystem;
	CEntitySystem* pEntitySystem;
	CInput* pInput;
	CSpriteBatch* pSpriteBatch;
	CStateSystem* pStateSystem;
	CSpriteRenderer* pSpriteRenderer;
	CPlayerController* pPlayerController;
	CClient* pClient;
	CPlayer* pPlayer;

	void log(string);
private:

};

extern CGlobalSystem* gSys;
