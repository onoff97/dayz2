#include "Player.h"
#include "Console.h"
#include "ByteDecoder.h"
#include "GlobalSystem.h"

CPlayer::CPlayer(uint32_t id)
{
	m_id = id;
	gSys->pEntitySystem->registerEntity(this);

	gSys->pConsole->registerCVar("movementSpeed", &m_attributes.movementSpeed);
}
CPlayer::~CPlayer()
{
	gSys->pSpriteRenderer->removeSprite(m_pPlayerSprite);
};

void CPlayer::init()
{
	m_pPlayerSprite = gSys->pSpriteRenderer->addSprite(50, 50, 0, 0, 1, 1, "data/survivor.png");
}

void CPlayer::update()
{
	m_pPlayerSprite->m_pos = m_pos.getLerp(gSys->pGame->gameTime - 0.1);
}

void CPlayer::parsePacket(uint8_t * data, unsigned int length)
{
	//Process other players differently
	if (this != gSys->pPlayer)
	{
		IActor::parsePacket(data, length);
	}
	else
	{
		if (length == 8)
		{
			glm::vec2 serverPos(readFloat(data), readFloat((data + 4)));
			glm::vec2 clientPos = m_pos.getLerp(0);

			float diff = (serverPos.x - clientPos.x) * (serverPos.x - clientPos.x)
				+ (serverPos.y - clientPos.y) * (serverPos.y - clientPos.y);
			
			//gSys->log(std::to_string(diff));

			//TODO Lerp small differences
			if (diff > 10 * 10)
				m_pos.addValue(serverPos, 0);
		}
	}
}
