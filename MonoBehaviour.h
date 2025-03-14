#pragma once
#include "Component.h"

// Script를 MonoBehaviour로 따로 관리하기 위해 class를 만듬


class MonoBehaviour : public Component
{
public:
	MonoBehaviour();
	virtual ~MonoBehaviour();

public:
	
private:
	virtual void FinalUpdate() sealed{}
};

