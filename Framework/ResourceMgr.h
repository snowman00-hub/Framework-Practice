#pragma once
#include <vector>
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

	void load(const std::vector<std::string>& ids)
	{
		for (const auto& id : ids)
		{
			load(id);
		}
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

	void unload(const std::vector<std::string>& ids)
	{
		for (const auto& id : ids)
		{
			bool success = unload(id);
		}
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