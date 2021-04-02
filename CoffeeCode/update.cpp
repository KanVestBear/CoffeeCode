// update.cpp

#include "kanDevEngine.h"


void kanDevEngine::update(float dtAsSeconds)
{

	hero.update(dtAsSeconds);
	coffeeBean.update(dtAsSeconds);

	programmer.update(dtAsSeconds);
}