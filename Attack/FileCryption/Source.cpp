#include <iostream>
#pragma warning (disable:4996)

using namespace std;
void main()
{
	FILE* OpenFile = nullptr;
	FILE* sibalFile = nullptr;

	//cout << feof(OpenFile);
	int i;
	while ((i = fgetc(OpenFile)) != EOF)
	{
	}

	OpenFile = fopen("Z:\\새 텍스트 문서.txt", "rb");
	fclose(OpenFile);

	cout << "hello world" << endl;
}