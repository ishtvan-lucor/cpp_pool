//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#include "HostUserNameModule.hpp"

HostUserNameModule::HostUserNameModule()
{
	_hostName = "Hostname: "+ getData("echo $(logname)");
	_userName = "Username: " + getData("hostname");
	_moduleName = "Host/User Module";
	this->_out.push_back(_hostName);
	this->_out.push_back(_userName);
}

HostUserNameModule::HostUserNameModule(HostUserNameModule const &copy)
{
	*this = copy;
}

HostUserNameModule& HostUserNameModule::operator=(HostUserNameModule const &target)
{
	this->_hostName = target.getHostName();
	this->_userName = target.getUserName();
	return (*this);
}
HostUserNameModule::~HostUserNameModule()
{}

std::string HostUserNameModule::getHostName() const
{
	return this->_hostName;
}
std::string HostUserNameModule::getUserName() const
{
	return this->_userName;
}

std::string const &HostUserNameModule::getName(void) const
{
	return this->_moduleName;
}

std::vector<std::string> const &HostUserNameModule::getOutput(void) const
{
	return this->_out;
}

std::string HostUserNameModule::getData(const char *command)
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

void HostUserNameModule::refresh()
{
	this->_out.clear();

	_hostName = "Hostname: "+ getData("echo $(logname)");
	_userName = "Username: " + getData("hostname");
	_moduleName = "Host/User Module";
	this->_out.push_back(_hostName);
	this->_out.push_back(_userName);
}