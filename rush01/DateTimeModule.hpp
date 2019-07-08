//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#ifndef RUSH01_DATETIMEMODULE_HPP
#define RUSH01_DATETIMEMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <iostream>

class DateTimeModule : public IMonitorModule
{
private:
	std::vector<std::string>	_out;
	std::string					_moduleName;

	std::string					_dateTime;
	std::string					getData(const char *command);

public:
	DateTimeModule();
	DateTimeModule(DateTimeModule const & copy);
	DateTimeModule &operator=(DateTimeModule const &target);
	~DateTimeModule();

	std::string			getDateTime() const;

	void				refresh();

	std::string const &getName(void) const;
	std::vector<std::string> const &getOutput(void) const;
};

#endif //RUSH01_DATETIMEMODULE_HPP
