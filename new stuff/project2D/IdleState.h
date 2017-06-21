#pragma once
#include "State.h"
class IdleState :
	public State
{
public:
	IdleState();
	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(Agent* agent, StateManager* sm);
	~IdleState();
};

