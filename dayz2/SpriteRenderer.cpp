#include "SpriteRenderer.h"
#include <algorithm>
#include "GlobalSystem.h"
#include "TextureCache.h"

CSpriteRenderer::~CSpriteRenderer()
{
	for (CSprite* s : m_sprites)
		delete s;

	m_sprites.clear();
}

void CSpriteRenderer::renderSprites()
{
	if (m_sprites.size() > 0)
	{
		CSpriteBatch* sb = gSys->pSpriteBatch;
		sb->begin(m_sprites.front()->m_texture);

		for (auto s : m_sprites)
		{
			if (s->m_texture != sb->getCurrentTexture())
				sb->begin(s->m_texture);

			sb->draw(s);
		}

		sb->end();
	}
}

void CSpriteRenderer::removeSprite(CSprite * pSprite)
{
	m_sprites.erase(std::remove(m_sprites.begin(), m_sprites.end(), pSprite));
	delete pSprite;
}

CSprite* CSpriteRenderer::addSprite(float width, float height, float u1, float v1, float u2, float v2, std::string texture)
{
	auto pSprite = new CSprite(width, height, u1, v1, u2, v2, gSys->pTextureCache->getTexture(texture));
	m_sprites.push_back(pSprite);
	return pSprite;
}

