#pragma once
#include "Object.h"

class Texture;

// [유니티짱]과 같이 정점으로 이루어진 물체
// resource를 object로 상속을 받지 않고 리소스를 공통으로 관리하는
// 클래스를 파줘도 되긴 하는데 유니티는 보통 이렇게 되어 있다.
// Mesh가 Object를 상속을 받는 형태로 만들어져 있다.
class Mesh : public Object
{
public:
	Mesh();
	virtual ~Mesh();

	void Init(const vector<Vertex>& vertexBuffer, const vector<uint32>& indexBuffer);
	void Render();

	//void SetMaterial(shared_ptr<Material> mat) { _mat = mat; }
	//void SetTransform(const Transform& t) { _transform = t; }
	//void SetTexture(shared_ptr<Texture> tex) { _tex = tex; }

private:
	void CreateVertexBuffer(const vector<Vertex>& buffer);
	void CreateIndexBuffer(const vector<uint32>& buffer);

private:
	ComPtr<ID3D12Resource> _vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW _vertexBufferView = {};
	uint32 _vertexCount = 0; 

	ComPtr<ID3D12Resource> _indexBuffer;
	D3D12_INDEX_BUFFER_VIEW _indexBufferView;
	uint32 _indexCount = 0;

	//shared_ptr<Material> _mat = {}; 
	//Transform _transform = {};
	//shared_ptr<Texture> _tex = {};
};

