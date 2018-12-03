#pragma once

#include "PrimeNbrSearcher.h"
#include "XmlFileParser.h"

class PrimeSearcher
{
	Parser *fileParser_;
	std::list<s_range> rangeList_;
	std::list<int> *primeNumbers_;
	std::string content_;
	std::string fileName_;
public:
	PrimeSearcher(std::string fileName);
	~PrimeSearcher();
	bool startPrimeSearch();
private:
	bool readFile();
	bool checkPrime();
	bool writeOutput();
	void findPrimeNumber(s_range range);
};

