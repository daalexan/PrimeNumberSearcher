#include "PrimeSearcher.h"

PrimeSearcher::PrimeSearcher(std::string fileName) : fileParser_(new XmlFileParser()), 
primeNumbers_(new std::list<int>()), fileName_(fileName){}

PrimeSearcher::~PrimeSearcher()
{
	delete fileParser_;
	delete primeNumbers_;
}

bool PrimeSearcher::readFile()
{
	return ((fileParser_->parseFile(fileName_)) ? (true) : (false));
}

bool PrimeSearcher::startPrimeSearch()
{
	readFile();
	rangeList_ = fileParser_->getRangeList();
	if (!rangeList_.empty())
	{
		checkPrime();
		return ((writeOutput()) ? (true) : (false));
	}
	return (false);
}

bool PrimeSearcher::checkPrime()
{
	std::vector<std::thread> thrd;

	for (s_range rangeTmp : rangeList_)
	{
		thrd.push_back(std::thread(&PrimeSearcher::findPrimeNumber, this, rangeTmp));
	}
	for (auto i = thrd.begin(); i < thrd.end(); ++i)
	{
		i->join();
	}
	if (primeNumbers_->empty())
	{
		return (false);
	}
	return (true);
}

bool PrimeSearcher::writeOutput()
{
	return ((fileParser_->addPrimesToFile(fileName_, primeNumbers_)) ? (true) : (false));
}

void PrimeSearcher::findPrimeNumber(s_range range)
{
	int counter;

	for (int i(range.min); i < range.max; i++)
	{
		counter = 0;
		for (int j(2); j <= i; j++)
		{
			if (i % j == 0)
				counter++;
		}
		if (counter == 1)
			primeNumbers_->push_back(i);
	}
}
