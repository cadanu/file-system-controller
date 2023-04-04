// file-system-controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "FileController.h"
//#include "StackAllocator.h"
//#include "ObjectPool.h"
//#include "Resource.h"
//#include "Asset.h"
//#include "AssetController.h"
#include "Level.h"

int main()
{
	// level test
	Level* level = new Level();
	level->AssignNonDefaultValues();
	ofstream writeStream("./rsc/bin/level.bin", ios::out | ios::binary);
	level->Serialize(writeStream);
	writeStream.close();
	cout << "Level ToSave:";
	level->ToString();
	delete level;
	cout << endl;

	Level* loadedLevel = new Level();
	ifstream readStream("./rsc/bin/level.bin", ios::in | ios::binary);
	loadedLevel->Deserialize(readStream);
	readStream.close();
	cout << "Loaded Level:";
	loadedLevel->ToString();
	delete loadedLevel;
	// level test end


	// asset controller test
	//AssetController::Instance().Initialize(10000000);// allocate 10mb
	////Asset* asset = AssetController::Instance().GetAsset("./rsc/emoji.jpg");
	////cout << "Bytes used by image.bmp: " << AssetController::Stack->GetBytesUsed() << endl;
	//Resource::Pool = new ObjectPool<Resource>();
	//Resource* r1 = Resource::Pool->GetResource();// 1
	//r1->AssignNonDefaultValues();// 2, 3

	//ofstream writeStream("./rsc/resource.bin", ios::out | ios::binary);
	//r1->Serialize(writeStream);
	//writeStream.close();
	//cout << "r1 values: ";
	//r1->ToString();

	//Resource* r2 = Resource::Pool->GetResource();
	//ifstream readStream("resource.bin", ios::in | ios::binary);
	//r2->Deserialize(readStream);
	//readStream.close();
	//cout << "r2 values: ";
	//r2->ToString();

	//delete Resource::Pool;
	// asset controller test end


	// memory-management test 2
	//ObjectPool<Resource>* objP = new ObjectPool<Resource>();
	//Resource* r1 = objP->GetResource();
	//
	//Resource::Pool = new ObjectPool<Resource>();// 1
	//Resource* r1 = Resource::Pool->GetResource();// 2

	//r1->AssignNonDefaultValues();

	//ofstream writeStream("./rsc/resource.bin", ios::out | ios::binary);
	//r1->Serialize(writeStream);
	//writeStream.close();

	//cout << "r1 values: ";
	//r1->ToString();

	//Resource* r2 = objP->GetResource();
	//
	//Resource* r2 = Resource::Pool->GetResource();// 3

	//ifstream readStream("./rsc/resource.bin", ios::in | ios::binary);
	//r2->Deserialize(readStream);// 4
	//readStream.close();

	//cout << "r2 values: ";
	//r1->ToString();

	//delete objP;// 
	//
	//delete Resource::Pool;
	// memory management test 2 end



	// file-controller + memory-management test
	//FileController* fileControl = &FileController::Instance();

	// memory-management test begin
	//StackAllocator* stackAlloc = new StackAllocator();
	//stackAlloc->AllocateStack(100);// allocate 100 bytes on the heap

	//string filePath = "./files/File1.txt";
	//int fileSize1 = fileControl->GetFileSize(filePath);
	//unsigned char* file1 = stackAlloc->GetMemory(fileSize1);
	//fileControl->ReadFile(filePath, file1, fileSize1);
	//cout << file1 << endl;

	//filePath = "./files/File2.txt";
	//int fileSize2 = fileControl->GetFileSize(filePath);
	//unsigned char* file2 = stackAlloc->GetMemory(fileSize2);
	//fileControl->ReadFile(filePath, file2, fileSize2);
	//stackAlloc->Mark();
	//cout << file2 << endl;

	//filePath = "./files/File3.txt";
	//int fileSize3 = fileControl->GetFileSize(filePath);
	//unsigned char* file3 = stackAlloc->GetMemory(fileSize3);
	//fileControl->ReadFile(filePath, file3, fileSize3);
	//cout << file3 << endl;

	//cout << "Bytes used: " << stackAlloc->GetBytesUsed() << " Content: " << file1 << endl;
	//stackAlloc->FreeToMarker();
	//cout << file1 << endl;
	//cout << "Bytes used: " << stackAlloc->GetBytesUsed() << " Content: " << file1 << endl;

	//delete stackAlloc;
	// memory-management test end


	// file directory test begin
	//cout << fc->GetCurrDir() << endl;

	//int fs = fc->GetFileSize("FileController.cpp");
	//unsigned char* buffer = new unsigned char[fs];
	//fc->ReadFileAsync("FileController.cpp", buffer, fs);

	//while(!fc->GetFileReadDone())
	//{
	//	cout << "Thread running..." << endl;
	//}
	//if (fc->GetFileReadSuccess())
	//{
	//	cout << "File size: " << fs << endl;
	//}
	//else
	//{
	//	cout << "File read operation unsuccessful." << endl;
	//}

	//delete[] buffer;
	// file directory test end

}

