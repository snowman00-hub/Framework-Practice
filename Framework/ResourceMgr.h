#pragma once
#include "Singleton.h"

template<typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;

protected:
	std::unordered_map<std::string, T*> resources;

	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;

	static T empty;

public:
	bool load(const std::string& id)
	{
		auto it = resources.find(id);
		if (it != resources.end())
		{
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(id);
		if (!success)
		{
			return false;
		}

		resources.insert({ id,res });
	}

	bool unload(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return false;
		}

		delete it->second;
		resources.erase(it);
		return true;
	}

	T& get(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return empty;
		}
		return *(it->second);
	}
};

template<typename T>
T ResourceMgr<T>::empty;

#define TEXTURE_MGR (ResourceMgr<sf::Texture>::instance())
#define FONT_MGR (ResourceMgr<sf::Font>::instance())
#define SOUNDBUFFER_MGR (ResourceMgr<sf::SoundBuffer>::instance())