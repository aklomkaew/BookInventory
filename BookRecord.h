// -----------------------------------------------------------
// File: BookRecord.h
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------

#ifndef BOOKRECORD_H
#define BOOKRECORD_H

class BookRecord
{
private:
	char m_sName[128];
	long m_lStockNum;
	int m_iClassification;
	double m_dCost;
	int m_iCount;
	BookRecord *m_pNext;
public:
	BookRecord();
	BookRecord(char *name, long sn, int cl, double cost);
	~BookRecord();
	void getName(char *name);
	void setName(char *name);
	long getStockNum();
	void setStockNum(long sn);
	int getClassification();
	void setClassification(int cl);
	double getCost();
	void setCost(double c);
	int getNumberInStock();
	void setNumberInStock(int count);
	void printRecord();
	void setNext(BookRecord *next);
	BookRecord *getNext();
};

#endif