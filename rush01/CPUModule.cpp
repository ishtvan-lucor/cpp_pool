/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:16:12 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 19:14:19 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"

CPUModule::CPUModule(void) : out(), moduleName("CPU Module")
{
    std::system("top -l 1 | grep -E \"^CPU|^Phys\" > ./system/cpuinfo");
    std::ifstream file("./system/cpuinfo");
    std::string line = "";
    std::vector<std::string> cpu;

    while (getline(file, line, ' '))
    {
        cpu.push_back(line);
    }

    file.close();

    std::string tmp = "User: " + cpu.at(2) + "%";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "System :" + cpu.at(4) + "%";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Idle: " + cpu.at(6) + "%";
    this->out.push_back(tmp);
}

CPUModule::CPUModule(CPUModule &val)
{
    *this = val;
}

CPUModule &CPUModule::operator=(CPUModule const &val)
{
    this->moduleName = val.moduleName;
    this->out = val.out;
    return *this;
}

CPUModule::~CPUModule(void)
{
}

std::string const &CPUModule::getName(void) const
{
    return this->moduleName;
}

std::vector<std::string> const &CPUModule::getOutput(void) const
{
    return this->out;
}

void CPUModule::refresh(void)
{
    this->out.clear();
    std::system("top -l 1 | grep -E \"^CPU|^Phys\" > ./system/cpuinfo");
    std::ifstream file("./system/cpuinfo");
    std::string line = "";
    std::vector<std::string> cpu;

    while (getline(file, line, ' '))
    {
        cpu.push_back(line);
    }

    file.close();

    std::string tmp = "User: " + cpu.at(2) + "%";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "System: " + cpu.at(4) + "%";
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Idle: " + cpu.at(6) + "%";
    this->out.push_back(tmp);
}