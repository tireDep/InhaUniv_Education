#include "cPlayer.h"

cPlayer::cPlayer()
{
}

cPlayer * cPlayer::GetInstance()
{
	static cPlayer player;
	return &player;
}

cPlayer::~cPlayer()
{
}

void cPlayer::SetUp()
{
}

void cPlayer::Update()
{
}

void cPlayer::Render()
{
}

bool cPlayer::Explor(Position position)
{
	return false;
}

bool cPlayer::Build(Position position, string type)
{
	return false;
}
