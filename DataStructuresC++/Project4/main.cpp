#include <iostream>
#include "directoryLinkedList.h"
using namespace std;
#include "directoryLinkedList.h"
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <tchar.h> 
#include "atlstr.h"
#include <string>
#pragma comment(lib, "User32.lib")

int main() {

	directoryLinkedList a;

	int input;
	int size;
	string str;
	cout << "enter a directory:";
	getline(cin,str);
	a.Directory(str);

	cout << "Press 1 for the Search Filename" << endl;
	cout << "Press 2 for the Search Extension" << endl;
	cout << "Press 3 for the Search File Size" << endl;
	cout << "Press 4 for the Remove Filename From List" << endl;
	cout << "Press 5 for Update the list" << endl;
	cout << "Press 6 for Traverse list" << endl;
	cout << "Press 7 for Exit" << endl;
	while(true) {
		cin >> input;
		if (input == 1) {
			cout << "filename" << endl;
			cin.ignore();
			getline(cin,str);
			a.searchFileName(str);
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
	
		}
		else if (input == 2) {
			cout << "extension" << endl;
			cin.ignore();
			getline(cin,str);
			a.searchExtension(str);
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
		}
		else if (input == 3) {
			cout << "size" << endl;
			cin >> size;
			a.searchFileSize(size);
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
		}
		else if (input == 4) {
			cout << "Enter a filename for deleting:";
			cin.ignore();
			getline(cin,str);
			a.deleteNode(str);
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
		}
		else if (input == 5) {
			
			a.updateTheList();	
			cout << "List is deleted" << endl;
			cout << "enter new a directory";
			cin.ignore(); 
			getline(cin, str);
			a.Directory(str);
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
		
		}
		else if (input == 6) {
			
			cout << "Press 1 for Filename Ascending Order " << endl;
			cout << "Press 2 for Extension Ascending Order" << endl;
			cout << "Press 3 for Size Ascending Order " << endl;
			int in;
			cin >> in;
			if (in == 1) {
				a.printList();
				cout << endl;
			}
			else if (in == 2) {
				a.printList1();
				cout << endl;
			}
			else if (in == 3) {
				cout << endl;
				a.printList2();
			}
			cout << endl;
			cout << "Press 1 for the Search Filename" << endl;
			cout << "Press 2 for the Search Extension" << endl;
			cout << "Press 3 for the Search File Size" << endl;
			cout << "Press 4 for the Remove Filename From List" << endl;
			cout << "Press 5 for Update the list" << endl;
			cout << "Press 6 for Traverse list" << endl;
			cout << "Press 7 for Exit" << endl;
		}
		else if (input == 7) {
			return 0;
		}
	
	}

	getchar();
};

