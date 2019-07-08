/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:13:43 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 17:25:18 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiskModule.hpp"

DiskModule::DiskModule(void) : out(), moduleName("Disk Module")
{
    std::system("top -l 1 | grep -E \"^Disks\" > ./system/diskinfo");
    std::ifstream file("./system/diskinfo");
    std::string line = "";
    std::vector<std::string> disk;

    while (getline(file, line, ' '))
    {
        disk.push_back(line);
    }

    file.close();

    std::string tmp = "Read: " + disk.at(1);
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Writen: " + disk.at(3);
    this->out.push_back(tmp);

}

DiskModule::DiskModule(DiskModule &val)
{
    *this = val;
}

DiskModule &DiskModule::operator=(DiskModule const &val)
{
    this->moduleName = val.moduleName;
    this->out = val.out;
    return *this;
}

DiskModule::~DiskModule(void)
{
}

std::string const &DiskModule::getName(void) const
{
    return this->moduleName;
}

std::vector<std::string> const &DiskModule::getOutput(void) const
{
    return this->out;
}

void DiskModule::refresh(void)
{
    this->out.clear();
    std::system("top -l 1 | grep -E \"^Disks\" > ./system/diskinfo");
    std::ifstream file("./system/diskinfo");
    std::string line = "";
    std::vector<std::string> disk;

    while (getline(file, line, ' '))
    {
        disk.push_back(line);
    }

    file.close();

    std::string tmp = "Read: " + disk.at(1);
    this->out.push_back(tmp);
    tmp = "";
    tmp = "Writen: " + disk.at(3);
    this->out.push_back(tmp);
}