#pragma once
#include "PrimeNbrSearcher.h"

class Parser
{
protected:
	std::string fileContent_;
	std::list<s_range> rangeList_;
public:
	Parser();
	virtual ~Parser();
	std::list<s_range> getRangeList();
	virtual bool parseFile(std::string fileName) = 0;
	virtual bool addPrimesToFile(std::string fileName_, std::list<int> *primeNumbers) = 0;
	bool ftStrCmp(std::string src1, std::string src2, int size);
private:
	virtual int getValue(std::string line, int startPos) = 0;
	virtual bool checkValidXmlFile(std::string file) = 0;
	virtual std::string makeStrPrimeNbr(std::list<int> *primeNumbers) = 0;
};

