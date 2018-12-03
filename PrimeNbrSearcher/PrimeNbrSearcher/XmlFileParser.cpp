#include "XmlFileParser.h"

XmlFileParser::XmlFileParser(){}

XmlFileParser::~XmlFileParser(){}

bool XmlFileParser::parseFile(std::string fileName_)
{
	std::ifstream fileReader;
	s_range rangeStore;
	int isFull = 0;

	fileReader.open(fileName_);
	if (fileReader.is_open())
	{
		if (!checkValidXmlFile(fileName_))
		{
			fileReader.close();
			return (false);
		}
		while (getline(fileReader, fileContent_))
		{
			std::string tmp;
			for (int i(0); i < fileContent_.length(); i++)
			{
				if (fileContent_[i] != ' ' && fileContent_[i] != '\t')
					tmp += fileContent_[i];
			}
			if (ftStrCmp(tmp, "<low>", 5))
			{
				rangeStore.min = getValue(tmp, 5);
				isFull++;
			}
			else if (ftStrCmp(tmp, "<high>", 6))
			{
				rangeStore.max = getValue(tmp, 6);
				isFull++;
			}
			if (isFull == 2)
			{
				rangeList_.push_back(rangeStore);
				isFull = 0;
			}
		}
		fileReader.close();
		return (true);
	}
	else
	{
		return (false);
	}
}

int	XmlFileParser::getValue(std::string line, int startPos)
{
	std::string value;
	int number;

	for (int i(startPos); i < line.length(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
			value += line[i];
	}
	number = std::stoi(value); 
	return (number);
}

bool XmlFileParser::checkValidXmlFile(std::string file)
{
	int pointDot = 0;
	std::string xmlFormat = ".xml";

	for (int i(0); i < file.length(); i++)
	{
		pointDot++;
		if (file[i] == '.')
			break;
		
	}
	return (file.compare(pointDot, 0, xmlFormat));
}

bool XmlFileParser::addPrimesToFile(std::string fileName_, std::list<int> *primeNumbers)
{
	std::ifstream fileReader;
	std::ofstream fileWriter;
	std::string buf;
	std::list<std::string> fileContent(0);
	std::string primeNbrToFile;

	fileReader.open(fileName_);
	if (fileReader.is_open())
	{
		while (getline(fileReader, buf))
		{
			fileContent.push_back(buf);
		}
		fileReader.close();
		fileWriter.open(fileName_);
		if (fileWriter.is_open())
		{
			primeNbrToFile = makeStrPrimeNbr(primeNumbers);
			for (auto content : fileContent)
			{
				fileWriter << content + "\n";
				if (!strcmp((char*)content.data(), "    </intervals>"))
					fileWriter << primeNbrToFile;
			}
			fileWriter.close();
		}
		else
			return (false);
	}
	else
		return (false);
	return (true);
}

std::string XmlFileParser::makeStrPrimeNbr(std::list<int> *primeNbr)
{
	std::string primeLine = "    <primes> ";

	primeNbr->sort();
	for (auto prime : *primeNbr)
	{
		primeLine += std::to_string(prime) + " ";
	}
	primeLine += "</primes>\n";
	return (primeLine);
}