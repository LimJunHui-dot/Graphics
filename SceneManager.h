#pragma once

class Scene;

class SceneManager
{

	DECLARE_SINGLE(SceneManager);
/*
private:
	SceneManager();
	~SceneManager();
	//static SceneManager* _instance;

public:
	static SceneManager* GetInstance()
	{
		if (_instance == nullptr)
			_instance = new SceneManager();

		return _instance;
	}

	static SceneManager* GetInstance2()
	{
		static SceneManager instance;
		return &instance;
	}
*/
public:
	// Update와 Render를 분리
	void Update();
	void Render();
	void LoadScene(wstring sceneName); 

public:
	shared_ptr<Scene> GetActiveScene() { return _activeScene; }

private:
	shared_ptr<Scene> LoadTestScene();

private:
	shared_ptr<Scene> _activeScene;
};

