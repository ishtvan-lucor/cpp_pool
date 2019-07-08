/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:38:00 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 12:49:19 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void) : out(), moduleName("Network Module")
{
    std::system("top -l 1 | grep -E \"^Networks\" > ./system/netinfo");
    std::ifstream file("./system/netinfo");
    std::string line = "";
    std::vector<std::string> ram;

    while (getline(file, line, ' '))
    {
        ram.push_back(line);
    }

    file.close();

    std::string tmp = "Packets In: " + ram.at(2);
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Packets Out: " + ram.at(4);
    this->out.push_back(tmp);
}

NetworkModule::NetworkModule(NetworkModule &val)
{
    *this = val;
}

NetworkModule &NetworkModule::operator=(NetworkModule const &val)
{
    this->moduleName = val.moduleName;
    this->out = val.out;
    return *this;
}

NetworkModule::~NetworkModule(void)
{
}

std::string const &NetworkModule::getName(void) const
{
    return this->moduleName;
}

std::vector<std::string> const &NetworkModule::getOutput(void) const
{
    return this->out;
}
void NetworkModule::refresh(void)
{
    this->out.clear();
    std::system("top -l 1 | grep -E \"^Networks\" > ./system/netinfo");
    std::ifstream file("./system/netinfo");
    std::string line = "";
    std::vector<std::string> ram;

    while (getline(file, line, ' '))
    {
        ram.push_back(line);
    }

    file.close();

    std::string tmp = "Packets In: " + ram.at(2);
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Packets Out: " + ram.at(4);
    this->out.push_back(tmp);
}