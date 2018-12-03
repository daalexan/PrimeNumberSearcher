#pragma once

#include "PrimeNbrSearcher.h"

class XmlFileParser : public Parser
{
public:
	XmlFileParser();
	~XmlFileParser();
	bool parseFile(std::string fileName_);
	bool addPrimesToFile(std::string fileName_, std::list<int> *primeNumbers);
private:
	int getValue(std::string line, int startPos);
	bool checkValidXmlFile(std::string file);
	std::string makeStrPrimeNbr(std::list<int> *primeNumbers);
};

