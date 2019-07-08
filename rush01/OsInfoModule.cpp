//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#include "OsInfoModule.hpp"

OSInfoModule::OSInfoModule()
{
	_os = getData("sw_vers -productName");
	_version = "Version: " + getData("sw_vers -productVersion");
	_moduleName = "OS Info:";
	this->_out.push_back(_os);
	this->_out.push_back(_version);
}

OSInfoModule::OSInfoModule(OSInfoModule const &copy)
{
	*this = copy;
}

OSInfoModule& OSInfoModule::operator=(OSInfoModule const &target)
{

	this->_os = target.getOs();
	this->_version = target.getVersion();
	this->_moduleName = target.getName();
	this->_out = target.getOutput();
	return (*this);
}
OSInfoModule::~OSInfoModule()
{}

std::string OSInfoModule::getOs() const
{
	return this->_os;
}
std::string OSInfoModule::getVersion() const
{
	return this->_version;
}

std::string const &OSInfoModule::getName(void) const
{
	return this->_moduleName;
}

std::vector<std::string> const &OSInfoModule::getOutput(void) const
{
	return this->_out;
}

std::string OSInfoModule::getData(const char *command)
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

void OSInfoModule::refresh()
{
	this->_out.clear();

	_os = getData("sw_vers -productName");
	_version = "Version: " + getData("sw_vers -productVersion");
	_moduleName = "OS Info:";
	this->_out.push_back(_os);
	this->_out.push_back(_version);
}