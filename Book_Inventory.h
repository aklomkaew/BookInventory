// -----------------------------------------------------------
// File: Book_Inventory.h
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#ifndef BOOK_INVENTORY_H
#define BOOK_INVENTORY_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "BookRecord.h"

using namespace std;

class Book_Inventory
{
private:
	BookRecord *m_pHead;
	ifstream m_InFile;

public:
	Book_Inventory();
	~Book_Inventory();
	void ClearList();
	bool readInventory(char *filename);
	bool addBook(BookRecord *br);
	BookRecord *removeBook(long stockNum);
	BookRecord *searchByStockNumber(long stockNum);
	void searchByClassification(int cl);
	void searchByCost(double min, double max);
	int getNumberInStock(long sn);
	void printAll();
private:
	bool getNextLine(char *line, int lineLen);
};

#endif