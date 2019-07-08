//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#ifndef RUSH01_HOSTUSERNAMEMODULE_HPP
#define RUSH01_HOSTUSERNAMEMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <iostream>

class HostUserNameModule : public IMonitorModule
{
private:
	std::vector<std::string>	_out;
	std::string					_moduleName;

	std::string					_hostName;
	std::string					_userName;

	std::string					getData(const char *command);

public:
	HostUserNameModule();
	HostUserNameModule(HostUserNameModule const & copy);
	HostUserNameModule &operator=(HostUserNameModule const &target);
	~HostUserNameModule();

	std::string	getHostName() const;
	std::string	getUserName() const;

	void		refresh();

	std::string const &getName(void) const;
	std::vector<std::string> const &getOutput(void) const;
};


#endif //RUSH01_HOSTUSERNAMEMODULE_HPP
