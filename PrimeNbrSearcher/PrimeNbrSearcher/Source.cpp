#include "PrimeSearcher.h"

int main()
{
	PrimeSearcher *p = new PrimeSearcher("SourceXml.xml");
	p->startPrimeSearch();

	delete p;
	system("pause");
	return 0;
}
