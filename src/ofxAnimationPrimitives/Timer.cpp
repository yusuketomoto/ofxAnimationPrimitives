#include "Timer.h"

OFX_ANIMATION_PRIMITIVES_BEGIN_NAMESPACE

Clock* Clock::system_clock = NULL;

struct DefaultClock
{
	Clock clock;
	
	DefaultClock()
	{
		clock.makeSystemClock();
		ofAddListener(ofEvents().update, this, &DefaultClock::onUpdate);
	}
	
	void onUpdate(ofEventArgs &e)
	{
		Clock::getClock()->update();
	}
};

static DefaultClock default_clock;

void Ticker::play()
{
	Clock::regist(this);
}

void Ticker::stop()
{
	Clock::unregist(this);
}

OFX_ANIMATION_PRIMITIVES_END_NAMESPACE