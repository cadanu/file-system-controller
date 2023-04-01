// file-system-controller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FileController.h"
#include "StackAllocator.h"
#include "ObjectPool.h"
#include "Resource.h"

int main()
{
	//ObjectPool<Resource>* objP = new ObjectPool<Resource>();
	//Resource* r1 = objP->GetResource();
	Resource::Pool = new ObjectPool<Resource>();// 1
	Resource* r1 = Resource::Pool->GetResource();// 2

	r1->AssignNonDefaultValues();

	ofstream writeStream("./rsc/resource.bin", ios::out | ios::binary);
	r1->Serialize(writeStream);
	writeStream.close();

	cout << "r1 values: ";
	r1->ToString();

	//Resource* r2 = objP->GetResource();
	Resource* r2 = Resource::Pool->GetResource();// 3

	ifstream readStream("./rsc/resource.bin", ios::in | ios::binary);
	r2->Deserialize(readStream);// 4
	readStream.close();

	cout << "r2 values: ";
	r1->ToString();

	//delete objP;// 
	delete Resource::Pool;



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

