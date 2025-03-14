#pragma once

enum class OBJECT_TYPE : uint8
{
	NONE,
	GAMEOBJECT, // 유니티:PREFAB  언리얼:blueprint
	COMPONENT,
	MATERIAL,
	MESH,
	SHADER,
	TEXTURE,

	END
};

enum
{
	OBJECT_TYPE_COUNT = static_cast<uint8>(OBJECT_TYPE::END)
};

// Object 자체가 최상위 클래스 역할
// Object를 복사하는 클론을 만들어가지고 복사본을 생성해주는 역할
// 구분을 해주기 위해 Object마다 맵을 만들어준다.
class Object
{
public:
	Object(OBJECT_TYPE type);
	virtual ~Object();

	OBJECT_TYPE GetType() { return _objectType; }

	void SetName(const wstring& name) { _name = name; }
	const wstring& GetName() { return _name; }

	// TODO : Instantiate
protected:
	friend class Resources;
	virtual void Load(const wstring& path){ }
	virtual void Save(const wstring& path){ }

protected:
	OBJECT_TYPE _objectType = OBJECT_TYPE::NONE;
	wstring _name;
};

