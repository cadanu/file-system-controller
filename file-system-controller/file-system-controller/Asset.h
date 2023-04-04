#ifndef ASSET_H
#define ASSET_H

#include "StdIncludes.h"
#include "ObjectPool.h"

class Asset
{
public:
	// constructors/destructors
	Asset();
	virtual ~Asset() { }

	// accessors
	string GetGuid() { return m_Guid; }
	void SetGuid(string _guid) { m_Guid = _guid; }
	int GetDataSize() { return m_dataSize; }
	void SetDataSize(int _size) { m_dataSize = _size; }
	byte* GetData() { return m_data; }
	void SetData(byte* _data) { m_data = _data; }

	// methods
	void ToString();
	static ObjectPool<Asset>* Pool;

private:
	// members
	string m_Guid;
	int m_dataSize;
	byte* m_data;
};

#endif// ASSET_H
