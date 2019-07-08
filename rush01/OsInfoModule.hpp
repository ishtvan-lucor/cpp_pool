//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#ifndef RUSH01_OSINFOMODUL_HPP
#define RUSH01_OSINFOMODUL_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <iostream>

class OSInfoModule : public IMonitorModule
{
private:
	std::vector<std::string>	_out;
	std::string					_moduleName;

	std::string					_os;
	std::string					_version;

	std::string					getData(const char *command);

public:
	OSInfoModule();
	OSInfoModule(OSInfoModule const & copy);
	OSInfoModule &operator=(OSInfoModule const &target);
	~OSInfoModule();

	std::string			getOs() const;
	std::string			getVersion() const;

	void				refresh();

	std::string const &getName(void) const;
	std::vector<std::string> const &getOutput(void) const;
};

#endif //RUSH01_OSINFOMODUL_HPP
