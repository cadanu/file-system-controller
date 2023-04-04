#ifndef ASSET_CONTROLLER_H
#define ASSET_CONTROLLER_H

#include "StdIncludes.h"
#include "StackAllocator.h"
#include "Asset.h"

class AssetController : public Singleton<AssetController>
{
public:
	// constructors/destructors
	AssetController();
	virtual ~AssetController();

	// methods
	void Initialize(int _stackSize);
	void Clear();
	Asset* GetAsset(string _guid);

	// members
	static StackAllocator* Stack;

private:
	// members
	map<string, Asset*> m_assets;
};

#endif// ASSET_CONTROLLER_H

