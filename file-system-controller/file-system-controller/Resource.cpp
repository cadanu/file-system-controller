#include "Resource.h"

ObjectPool<Resource>* Resource::Pool;

Resource::Resource()
{
	//m_val1 = 0;
	//m_val2 = 0.0f;
	//m_val3 = {};
	//m_subResource = nullptr;
	//m_asset = nullptr;
}

Resource::~Resource() 
{
}

void Resource::AssignNonDefaultValues()
{
	//m_val1 = 2;
	//m_val2 = 2.0f;
	//m_val3 = '2';
	//m_subResource = Resource::Pool->GetResource();
	//m_subResource->m_val1 = 3;
	//m_subResource->m_val2 = 3.0f;
	//m_subResource->m_val3 = '3';
	//m_asset = AssetController::Instance().GetAsset("./rsc/Emoji.jpg");
}

void Resource::ToString()
{
	//cout << "m_val1: " << m_val1 << " ";
	//cout << "m_val2: " << m_val2 << " ";
	//cout << "m_val3: " << m_val3 << " " << endl;
	//if (m_subResource != nullptr)
	//{
	//	m_subResource->ToString();
	//}
	//if (m_asset != nullptr)
	//{
	//	m_asset->ToString();
	//}

	cout << "BASE RESOURCE" << endl;
}

void Resource::SerializeAsset(std::ostream& _stream, Asset* _asset)
{
	byte guidLength = 0;
	if (_asset != nullptr)
	{
		guidLength = (byte)_asset->GetGuid().length();
	}
	_stream.write(reinterpret_cast<char*>(&guidLength), sizeof(guidLength));
	if (guidLength > 0)
	{
		_stream.write(_asset->GetGuid().c_str(), guidLength);
	}
}

void Resource::DeserializeAsset(std::istream& _stream, Asset*& _asset)
{
	byte guidLength = 0;
	_stream.read(reinterpret_cast<char*>(&guidLength), sizeof(byte));
	if (guidLength > 0)
	{
		char guid[255];
		_stream.read(guid, guidLength);
		guid[guidLength] = 0;// null terminate string
		_asset = AssetController::Instance().GetAsset(string(guid));
	}
}

//void Resource::SerializePointer(std::ostream& _stream, Resource* _pointer)
//{
//}

//void Resource::DeserializePointer(std::istream& _stream, Resource*& _pointer)
//{
//}

void Resource::Serialize(std::ostream& _stream)// in
{
	// 2
	//_stream.write(reinterpret_cast<char*>(&m_val1), sizeof(m_val1));
	//_stream.write(reinterpret_cast<char*>(&m_val2), sizeof(m_val2));
	//_stream.write(reinterpret_cast<char*>(&m_val3), sizeof(m_val3));
	//SerializeAsset(_stream, m_asset);
	//SerializePointer(_stream, m_subResource);
	
	// 1
	//byte exists = 1;
	//if (m_subResource != nullptr)
	//{
	//	_stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
	//	m_subResource->Serialize(_stream);
	//}
	//else
	//{
	//	exists = 0;
	//	_stream.write(reinterpret_cast<char*>(&exists), sizeof(byte));
	//}
}

void Resource::Deserialize(std::istream& _stream)// out
{
	// 2
	//_stream.read(reinterpret_cast<char*>(&m_val1), sizeof(m_val1));
	//_stream.read(reinterpret_cast<char*>(&m_val2), sizeof(m_val2));
	//_stream.read(reinterpret_cast<char*>(&m_val3), sizeof(m_val3));
	//DeserializeAsset(_stream, m_asset);
	//DeserializePointer(_stream, m_subResource);

	// 1
	//byte exists = 0;
	//_stream.read(reinterpret_cast<char*>(&exists), sizeof(exists));
	//if (exists == 1)
	//{
	//	m_subResource = Resource::Pool->GetResource();
	//	m_subResource->Deserialize(_stream); 
	//}
}

