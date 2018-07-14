// -----------------------------------------------------------
// File: Main.cpp
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

//#define DEBUG_1
//#define DEBUG_2
//#define DEBUG_3
//#define DEBUG_4
//#define DEBUG_5
#define DEBUG_6

#include "Book_Inventory.h"
#include "BookRecord.h"
#include <iostream>
using namespace std;

int main()
{
	Book_Inventory* invent = new Book_Inventory();
	BookRecord* br = new BookRecord();
	char filename[128];

	//cout << "Please enter filename: " << endl;
	//scanf("%s", filename);

	invent->readInventory("BookData.txt");
	invent->printAll();

	cout << "********************************" << endl;

#ifdef DEBUG_1
	br = invent->searchByStockNumber(1234);
	br->printRecord();
	br = invent->searchByStockNumber(9999);
	if(br == NULL)
	{
		cout << "Success!" << endl;
	}
#endif

#ifdef DEBUG_2
	invent->searchByClassification(613);
	cout << "\n****************************" << endl;
#endif

#ifdef DEBUG_3
	invent->searchByCost(20.0, 30.0);
	cout << "\n****************************" << endl;
	invent->searchByCost(50.0, 60.0);
	cout << "\n****************************" << endl;
#endif

#ifdef DEBUG_4
	cout << invent->getNumberInStock(1234) << endl;
	cout << "\n****************************" << endl;
	cout << invent->getNumberInStock(9999) << endl;
	cout << "\n****************************" << endl;
#endif

#ifdef DEBUG_5
	br = invent->removeBook(9999);
	br = invent->removeBook(3456);
	if((br != NULL) && (br->getStockNum() == 3456))
	{
		cout << "Test succeeded" << endl;
		delete br;
	}
#endif

#ifdef DEBUG_6
	delete invent;
#endif

	scanf("%s", filename);

	return 0;
}