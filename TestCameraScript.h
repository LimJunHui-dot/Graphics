#pragma once
#include "MonoBehaviour.h"

// 키보드를 누를때 카메라의 위치를 변화시켜줌 
class TestCameraScript : public MonoBehaviour
{
public:
	TestCameraScript();
	virtual ~TestCameraScript();

	virtual void LateUpdate() override;

private:
	float   _speed = 100.f;
};
 
