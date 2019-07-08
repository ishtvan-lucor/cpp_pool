/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:00:08 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 11:57:35 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"

RAMModule::RAMModule(void) : out(), moduleName("RAM Module")
{
    std::system("top -l 1 | grep -E \"^CPU|^Phys\" > ./system/raminfo");
    std::ifstream file("./system/raminfo");
    std::string line = "";
    std::vector<std::string> ram;

    while (getline(file, line, ' '))
    {
        ram.push_back(line);
    }

    file.close();

    this->out.push_back("Max Capacity: 8192MB");
    std::string tmp = "Used: " + std::to_string(stoi(ram.at(9)) - stoi(ram.at(11).substr(1, ram.at(11).length()))) + "MB";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Wired: " + std::to_string(stoi(ram.at(11).substr(1, ram.at(11).length()))) + "MB";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Unused: " + std::to_string(stoi(ram.at(13))) + "MB";
    this->out.push_back(tmp);
}

RAMModule::RAMModule(RAMModule &val)
{
    *this = val;
}

RAMModule &RAMModule::operator=(RAMModule const &val)
{
    this->moduleName = val.moduleName;
    this->out = val.out;
    return *this;
}

RAMModule::~RAMModule(void)
{
}

std::string const &RAMModule::getName(void) const
{
    return this->moduleName;
}

std::vector<std::string> const &RAMModule::getOutput(void) const
{
    return this->out;
}
void RAMModule::refresh(void)
{
    this->out.clear();
    std::system("top -l 1 | grep -E \"^CPU|^Phys\" > ./system/raminfo");
    std::ifstream file("./system/raminfo");
    std::string line = "";
    std::vector<std::string> ram;

    while (getline(file, line, ' '))
    {
        ram.push_back(line);
    }

    file.close();

    this->out.push_back("Max Capacity: 8192MB");
    std::string tmp = "Used: " + std::to_string(stoi(ram.at(9)) - stoi(ram.at(11).substr(1, ram.at(11).length()))) + "MB";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Wired: " + std::to_string(stoi(ram.at(11).substr(1, ram.at(11).length()))) + "MB";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Unused: " + std::to_string(stoi(ram.at(13))) + "MB";
    this->out.push_back(tmp);
}