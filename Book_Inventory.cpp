// -----------------------------------------------------------
// File: Book_Inventory.cpp
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include "Book_Inventory.h"
#include "BookRecord.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

Book_Inventory::Book_Inventory()
{
	m_pHead = NULL;
}

Book_Inventory::~Book_Inventory()
{
	ClearList();
}

void Book_Inventory::ClearList()
{
	BookRecord *temp = NULL;

	while(m_pHead != NULL)
	{
		temp = m_pHead;
		m_pHead = m_pHead->getNext();

		delete temp;
	}
}

bool Book_Inventory::readInventory(char *filename)
{
	char line[128];
	int numBooks;

	m_InFile.open(filename, ifstream::in);
	if(!m_InFile.is_open())
	{
		// m_InFile.is_open() returns false if the file could not be found or
		// if for some other reason the open failed.
		cout << "Unable to open file" << filename << "\nProgram terminanting...\n";
		return false;
	}
	// Read number of books
	getNextLine(line, 128);
	numBooks = atoi(line);
	for(int i = 0; i < numBooks; i++)
	{
		BookRecord *book = new BookRecord();
		// book ID
		getNextLine(line, 128);
		book->setStockNum(atoi(line));

		// title
		getNextLine(line, 128);
		book->setName(line);

		// classification
		getNextLine(line, 128);
		book->setClassification(atoi(line));

		// cost
		getNextLine(line, 128);
		book->setCost(atof(line));

		// number in stock
		getNextLine(line, 128);
		book->setNumberInStock(atoi(line));

		addBook(book);
	}

	return true;
}

bool Book_Inventory::addBook(BookRecord *br)
{
	BookRecord *check = searchByStockNumber(br->getStockNum());
	BookRecord *temp = m_pHead;
	BookRecord *back = NULL;

	if(check == NULL)
	{
		if(m_pHead == NULL)
		m_pHead = br;
		else
		{
			while((temp != NULL) && (temp->getStockNum() < br->getStockNum()))
			{
				back = temp;
				temp = temp->getNext();
			}
			if(back == NULL)		// adding at head
			{
				br->setNext(m_pHead);
				m_pHead = br;
			}
			else
			{
				br->setNext(back->getNext());
				back->setNext(br);
			}
		}
	}
	else
	{
		check->setNumberInStock((check->getNumberInStock())+1);
	}
	return true;
}

BookRecord *Book_Inventory::removeBook(long stockNum)
{
	BookRecord *temp = m_pHead;
	BookRecord *back = NULL;

	while((temp != NULL) && (temp->getStockNum() != stockNum))
	{
		back = temp;
		temp = temp->getNext();
	}
	if(back == NULL)		// deleting in front
		return m_pHead;
	else if(temp == NULL)	// not found
		return NULL;
	else
		return temp;
}

BookRecord *Book_Inventory::searchByStockNumber(long stockNum)
{
	BookRecord *temp = m_pHead;
	BookRecord *back = NULL;

	while((temp != NULL) && (temp->getStockNum() != stockNum))
	{
		back = temp;
		temp = temp->getNext();
	}
	if(back == NULL)			// found at head
		return m_pHead;
	else if(temp == NULL)		// not found
		return NULL;
	else
		return temp;
}

void Book_Inventory::searchByClassification(int cl)
{
	BookRecord *temp = m_pHead;

	while(temp != NULL)
	{
		if(temp->getClassification() == cl)
			temp->printRecord();
		
		temp = temp->getNext();
	}
}

void Book_Inventory::searchByCost(double min, double max)
{
	BookRecord *temp = m_pHead;

	while(temp != NULL)
	{
		if((temp->getCost() >= min) && (temp->getCost() <= max))
			temp->printRecord();

		temp = temp->getNext();
	}
}

int Book_Inventory::getNumberInStock(long sn)
{
	BookRecord *temp = searchByStockNumber(sn);
	if(temp != NULL)
		return temp->getNumberInStock();
	return 0;
}

void Book_Inventory::printAll()
{
	BookRecord *temp = m_pHead;
	while(temp != NULL)
	{
		temp->printRecord();
		temp = temp->getNext();
	}
}

bool Book_Inventory::getNextLine(char *line, int lineLen)
{
	int done = false;
	while(!done)
	{
		m_InFile.getline(line, lineLen);

		if(m_InFile.good())		// if a line was successfully read
		{
			if(strlen(line) == 0)		// skip any blank lines
				continue;
			else if(line[0] == '#')		// skip any comment lines
				continue;
			else return true;			// got a valid data line so return with this line
		}
		else
		{
			strcpy(line, "");		// copy empty string into line as sentinal value
			return false;
		}
	}
	return false;
}