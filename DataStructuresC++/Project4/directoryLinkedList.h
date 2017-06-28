#pragma once
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")
#include <string>

using namespace std;
typedef struct {
	std::string name;
	std::string type;
	int size;
}Info;
class Node {
public:
	string name;
	string extension;
	int size;
	Node* nextNAME;
	Node* nextEX;
	Node* nextSize;
	Node::Node() {
		nextNAME = nextEX = nextSize = nullptr;
	}
	Node::Node(string name, string extension, int size) {
		this->name = name;
		this->extension = extension;
		this->size = size;
		nextNAME = nextEX = nextSize = nullptr;
	};
};
class directoryLinkedList {
	int count = 0;
	Node* nameHead;
	Node* nameTail;
	Node* exHead;
	Node* exTail;
	Node* sizeHead;
	Node* sizeTail;
public:
	directoryLinkedList::directoryLinkedList() {
		nameHead = 0;
		nameTail = 0;
		exHead = 0;
		exTail = 0;
		sizeHead = 0;
		sizeTail = 0;
	};
	void NodeAdd(Info);
	void Directory(string);
	void addName(Node*);
	void addEx(Node* p);
	void addSize(Node* p);
	void printList();
	void printList1();
	void printList2();
	void searchFileName(string);
	void searchExtension(string);
	void searchFileSize(int);
	void deleteNode(string);
	void updateTheList();

};

char* substr(char const* input, size_t start, size_t len)
{
	char* ret = static_cast<char*>(malloc(len + 1));
	memcpy(ret, input + start, len);
	ret[len] = '\0';
	return ret;
}

void directoryLinkedList::Directory(string el)
{
	HANDLE dir;
	WIN32_FIND_DATA file_data;
	el = el + "*";
	if ((dir = FindFirstFile(el.c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		return; /* No files found */

	do
	{
		const std::string file = file_data.cFileName;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
		Info info;

		if (file[0] == '.')
			continue;
		//Find filetype filename and filesize
		if (is_directory)
		{
			info.type = "dir";
			info.name = file;
		}

		else
		{
			int i;
			for (i = file.size() - 1; file[i] != '.' && i > 0; i--)
			{
			};
			if (i > 0)
			{
				
				info.type.append(substr(file.c_str(), i + 1, file.size() - i));
				info.name.append(substr(file.c_str(), 0, i));
			}
			else
			{
				info.name = file;
			}
		}
		info.size = file_data.nFileSizeLow;
		NodeAdd(info);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);
}

void directoryLinkedList::NodeAdd(Info info) {
	Node* a = new Node(info.name, info.type, info.size);
	addName(a);
	addEx(a);
	addSize(a);
}
string toLower(string s) {
	string r;
	for (size_t i = 0; i < s.size(); i++)
	{
		char x = tolower(s[i]);
		r.push_back(x);
	}
	return r;
}
void directoryLinkedList::addName(Node* p) {
	Node* current;
	if (nameHead == NULL || toLower(nameHead->name) >= toLower(p->name)) {
		p->nextNAME = nameHead;
		nameHead = p;
	}
	else {
		current = nameHead;
		while (current->nextNAME != NULL && toLower(current->nextNAME->name) < toLower(p->name)) {
			current = current->nextNAME;
		}
		p->nextNAME = current->nextNAME;
		current->nextNAME = p;
	}
}
void directoryLinkedList::addEx(Node* p) {
	Node* current;
	if (exHead == NULL || toLower(exHead->extension) >= toLower(p->extension)) {
		p->nextEX = exHead;
		exHead = p;
	}
	else {
		current = exHead;
		while (current->nextEX != NULL && toLower(current->nextEX->extension) < toLower(p->extension)) {
			current = current->nextEX;
		}
		p->nextEX = current->nextEX;
		current->nextEX = p;
	}
}
void directoryLinkedList::addSize(Node* p) {
	Node* current;

	if (sizeHead == NULL || sizeHead->size >= p->size) {
		p->nextSize = sizeHead;
		sizeHead = p;
	}
	else {
		current = sizeHead;
		while (current->nextSize != NULL && current->nextSize->size < p->size) {
			current = current -> nextSize;
		}
		p->nextSize = current->nextSize;
		current->nextSize = p;
	}
}

void directoryLinkedList::printList() {
	Node* tmp = nameHead;
	count = 0;
	int a;
	while (tmp != nullptr) {
		cout << tmp->name << endl;
		count++;
		tmp = tmp->nextNAME;
		if (count % 40 == 0) {
			cout << endl;
			cout << "Press 1 for next page:";
			cin >> a;
			cout<< endl;
		}
	}
}


void directoryLinkedList::printList1() {
	Node* tmp = exHead;
	count = 0;
	int a;
	while (tmp != nullptr) {
		cout << tmp->extension << endl;
		count++;
		tmp = tmp->nextEX;
		if (count % 40 == 0) {
			cout << endl;
			cout << "Press 1 for next page:";
			cin >> a;
			cout << endl;
		}
	}
}
void directoryLinkedList::printList2() {
	Node* tmp = sizeHead;
	count = 0;
	int a;
	while (tmp != nullptr) {
		cout << tmp->size << endl;
		count++;
		tmp = tmp->nextSize;
		if (count % 40 == 0) {
			cout << endl;
			cout << "Press 1 for next page:";
			cin >> a;
			cout << endl;
		}
	}
}
void directoryLinkedList::searchFileName(string value){
	Node* current = nameHead;

	/* traverse the list */
	while (current != nullptr) {
		
		if (current->name == value)
		{
			cout << current->name<<" "<< current->extension <<" "<< current->size << endl;
		}
		/* move to the next one */
		current = current->nextNAME;
	}
	return;
}
void directoryLinkedList::searchExtension(string value)
{
	Node* current = nameHead;
	/* traverse the list */
	while (current != nullptr) {
		/* Target! */
		if (current->extension == value)
		{
			cout << current->name << endl;
		}
		/* move to the next one */
		current = current->nextNAME;
	}
	return;
}
void directoryLinkedList::searchFileSize(int value) {
	Node* current = nameHead;

	/* traverse the list */
	while (current != nullptr) {
		
		if (current->size > value)
		{
			cout << current->name <<" "<<current->size <<endl;
		}
		/* move to the next one */
		current = current->nextNAME;
	}
	return;
}

void directoryLinkedList::deleteNode(string el) {
	Node *nametemp = nameHead;
	Node *extemp = exHead;
	Node *sizetemp = sizeHead;
	Node *nameprev = nameHead;
	Node *exprev = exHead;
	Node *sizeprev = sizeHead;
	if (nameHead != 0) {
		while (nametemp != NULL && nametemp->name != el)
		{
			nameprev = nametemp;
			nametemp = nametemp->nextNAME;
			if (nametemp != 0) {
				if (nametemp == nameTail)
					nameTail = nameprev;
			}
		}
		if (nametemp == nameHead) {
			nameHead = nameHead->nextNAME;
		}
		else {
			nameprev->nextNAME = nametemp->nextNAME;
		}
//---------------------------------------------------------------------------------
		while (extemp != NULL && extemp != nametemp )
		{
			exprev = extemp;
			extemp = extemp->nextEX;
			if (extemp != 0) {
				if (extemp == exTail)
					exTail = exprev;
			}
		}
		if (extemp == exHead) {
			exHead = exHead->nextEX;
		}
		else {
			exprev->nextEX = extemp->nextEX;
		}
//--------------------------------------------------------------------------------------
		while (sizetemp != NULL && sizetemp != nametemp)
		{
			sizeprev = sizetemp;
			sizetemp = sizetemp->nextSize;
			if (sizetemp != 0) {
				if (sizetemp == sizeTail)
					sizeTail = sizeprev;
			}
		}
		if (sizetemp == sizeHead) {
			sizeHead = sizeHead->nextSize;
		}
		else {
			sizeprev->nextSize = sizetemp->nextSize;
		}
//-----------------------------------------------------------------------------------------
		if (nametemp == NULL) {
			nameprev = nameTail;
			exprev = exTail;
			sizeprev = sizeTail;
			return;
		}
		delete nametemp;
	}
}
void directoryLinkedList::updateTheList()
{
	Node *Del = nameHead;

	/* Traverse the list and delete the node one by one from the head */
	while (Del != nullptr) {
		/* take out the head node */
		nameHead = nameHead->nextNAME;
		delete Del;
		/* update the head node */
		Del = nameHead;
	}
	/* Reset the head and tail node */
	nameTail = nameHead = nullptr;
	exTail = exHead = nullptr;
	sizeTail = sizeHead = nullptr;

//-------------------------------------------------------------------------------
}



