#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<fstream>
using namespace std;
class Book
{
public:
	char* type;
	virtual char* Type()=0;
	virtual void print()=0;
	virtual void edit()=0;
	virtual void add(string method) = 0;
	//virtual void save(ofstream&F)=0;
	//virtual void load(ifstream&F)=0;
};