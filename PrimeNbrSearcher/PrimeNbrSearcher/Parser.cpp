#include "Parser.h"

Parser::Parser() : rangeList_(0){}

Parser::~Parser(){}

bool Parser::ftStrCmp(std::string src1, std::string src2, int size)
{
	for (int i(0); i < size; i++)
	{
		if (src1[i] != src2[i])
			return (false);
	}
	return (true);
}

std::list<s_range> Parser::getRangeList()
{
	return (rangeList_);
}
