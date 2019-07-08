//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{
	_dateTime = getData("echo $(date +%x' '%r)");
	_moduleName = "Time:";
	this->_out.push_back(_dateTime);
}

DateTimeModule::DateTimeModule(DateTimeModule const &copy)
{
	*this = copy;
}

DateTimeModule& DateTimeModule::operator=(DateTimeModule const &target)
{
	this->_dateTime = target.getDateTime();
	this->_moduleName = target.getName();
	this->_out = target.getOutput();
	return (*this);
}
DateTimeModule::~DateTimeModule()
{}

std::string DateTimeModule::getDateTime() const
{
	return this->_dateTime;
}

std::string const &DateTimeModule::getName(void) const
{
	return this->_moduleName;
}

std::vector<std::string> const &DateTimeModule::getOutput(void) const
{
	return this->_out;
}

std::string DateTimeModule::getData(const char *command)
{
	std::string	resultOut = "";
	FILE*		readOutPut;
	char		temp[512];

	readOutPut = popen(command, "r");
	if (!readOutPut)
		return resultOut;
	try
	{
		while (!feof(readOutPut))
			if (fgets(temp, 512, readOutPut) != NULL)
				resultOut += temp;
	}
	catch (std::exception &e)
	{
		pclose(readOutPut);
	}
	pclose(readOutPut);
	return resultOut;
}

void DateTimeModule::refresh()
{
	this->_out.clear();

	_dateTime = getData("echo $(date +%x' '%r)");
	this->_out.push_back(_dateTime);
}