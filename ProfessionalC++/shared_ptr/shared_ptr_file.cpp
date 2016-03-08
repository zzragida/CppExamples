#include <iostream>
#include <memory>
#include <cstdio>

using namespace std;

void CloseFile(FILE* filePtr)
{
	if (filePtr == nullptr)
		return;
	fclose(filePtr);
	cout << "File closed" << endl;
}

int main()
{
	shared_ptr<FILE> filePtr(fopen("data.text", "w"), CloseFile);
	if (filePtr == nullptr) {
		cout << "Error opening file" << endl;
	} else {
		cout << "File opended" << endl;
	}

	return 0;
}
