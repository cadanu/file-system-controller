#include "Asset.h"

ObjectPool<Asset>* Asset::Pool;

Asset::Asset()
{
	m_Guid = "";
	m_dataSize = 0;
	m_data = nullptr;
}

void Asset::ToString()
{
	cout << "Asset Guid: " << m_Guid << endl;
	cout << "Asset Data Size: " << m_dataSize << endl;
}
