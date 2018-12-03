#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../PrimeNbrSearcher/PrimeSearcher.h"

PrimeSearcher *prime = new PrimeSearcher("SourceXml.xml");

TEST(PrimeSearcherTest, startPrimeSearchShouldReturnTrue)
{
	EXPECT_EQ(true, prime->startPrimeSearch());
}

PrimeSearcher primeInvalidFile("InvalidFile.xml");

TEST(PrimeSearcherTest, startPrimeSearchShouldReturnFalse)
{
	EXPECT_EQ(false, primeInvalidFile.startPrimeSearch());
}

XmlFileParser *parseCompare = new XmlFileParser();

TEST(XmlFileParserTest, ftStrCmpSouldReturnTrue)
{
	EXPECT_EQ(parseCompare->ftStrCmp("Hello", "Hello", 5), true);
}

TEST(XmlFileParserTest, ftStrCmpShouldReturnFalse)
{
	EXPECT_EQ(parseCompare->ftStrCmp("var", "val", 3), false);
}

XmlFileParser *parserTestAddListToFile = new XmlFileParser();

TEST(XmlFileParserTest, parseFileShouldReturnTrue)
{
	EXPECT_EQ(true, parserTestAddListToFile->parseFile("SourceXml.xml"));
}

TEST(XmlFileParserTest, getRangeListShouldReturnTrue)
{
	std::list<s_range> rangeList(0);

	rangeList = parserTestAddListToFile->getRangeList();
	EXPECT_EQ(true, !rangeList.empty());
}

TEST(XmlFileParserTest, addPrimesToFileShouldReturnTrue)
{
	std::list<int> listOfValue = {3, 4, 23, 5};

	EXPECT_EQ(true, parserTestAddListToFile->addPrimesToFile("SourceXml.xml", &listOfValue));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return (RUN_ALL_TESTS());
}