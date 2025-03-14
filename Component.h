#pragma once
#include "Object.h"

enum class COMPONENT_TYPE : uint8
{
	TRANSFORM,
	MESH_RENDERER,
	CAMERA,
	LIGHT,
	// ...
	MONO_BEHAVIOUR,
	END,
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(COMPONENT_TYPE::END) - 1

};

class GameObject;
class Transform;

class Component : public Object // Component Class는 베이스 클래스로 사용할 예정
{
public:
	Component(COMPONENT_TYPE type);
	// 꼭 virtual을 붙여줘야 메모리 락을 예방

	virtual ~Component();

public:
	virtual void Awake(){}
	virtual void Start(){}
	// 시점을 분리하기 위한 용도
	virtual void Update(){}
	virtual void LateUpdate(){}
	virtual void FinalUpdate(){}

public:
	COMPONENT_TYPE GetType() { return _type; }
	// 어떤 타입인지 갖고 있고 오브젝트가 소멸되었는지를 체크라는 함수도 일단은 넣어놓은다.
	//
	bool isValid() { return _gameObject.expired() == false; }

	shared_ptr<GameObject> GetGameObject();
	shared_ptr<Transform> GetTransform();

private:
	friend class GameObject;
	void SetGameObjeect(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }
private:
	COMPONENT_TYPE _type;
	// 지금까지는 shared_ptr이었지만 왜 weak_ptr일까
	// 컴포넌트에서도 자기가 누구한테 포함이 되는지를 서로 가리키는 형태로 
	// 알고 있어야 된다. 컴포넌트에서도 내 주인님을 알아야 하고 게임 오브젝트에서도
	// 내가 들고 있는 컴포넌트를 알아야 하기 때문에 만약에 shared_ptr로 설정하게 
	// 되면 서로가 서로를 가리키게 되어 레퍼런스 카운터가 영영 줄어들지 않게 된다.
	weak_ptr<GameObject> _gameObject;

};

