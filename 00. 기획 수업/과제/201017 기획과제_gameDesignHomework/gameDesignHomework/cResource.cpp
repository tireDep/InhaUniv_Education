#include "cResource.h"

cResource::cResource()
{
}

cResource* cResource::GetInstance()
{
	static cResource resource;
	return &resource;
	// return nullptr;
}

cResource::~cResource()
{
}

void cResource::SetUp()
{
}

void cResource::Update()
{
}

void cResource::AddResource(string name, int value)
{
}

void cResource::MinusResource(string name, int value)
{
}

bool cResource::CheckResourceZero(string name)
{
	return false;
}

bool cResource::CheckCanTrade(string name, int price)
{
	return false;
}
