/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:10:07 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 22:56:13 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"
#include "RAMModule.hpp"
#include "CPUModule.hpp"
#include "NetworkModule.hpp"
#include "HostUserNameModule.hpp"
#include "OsInfoModule.hpp"
#include "DateTimeModule.hpp"
#include "DiskModule.hpp"

void print_usage(void)
{
    std::cout << "You must enter a valid mode for ft_gkrellm" << std::endl
              << "USAGE: 	ft_gkrellm [MODE] [MODULES]" << std::endl
              << "-w 		enables graphic mode" << std::endl
              << "-t 		enables text mode" << std::endl
              << "-o 		add OS Information Module" << std::endl
              << "-h 		add Host/User name Module" << std::endl
              << "-d 		add Date Module" << std::endl
              << "-r 		add RAM Module" << std::endl
              << "-c 		add CPU Module" << std::endl
              << "-n 		add Net Module" << std::endl
              << "-di 		add Disk Module" << std::endl
              << "-all 		add All Modules" << std::endl;
}

void parseFlags(int argc, char **argv, std::vector<IMonitorModule *> *vec)
{
    for (int i = 2; i < argc; i++)
    {
        if (!strcmp(argv[i], "-all"))
        {
            OSInfoModule *os = new OSInfoModule;
            vec->push_back(os);
            HostUserNameModule *host = new HostUserNameModule;
            vec->push_back(host);
            DateTimeModule *date = new DateTimeModule;
            vec->push_back(date);
            RAMModule *ram = new RAMModule;
            vec->push_back(ram);
            CPUModule *cpu = new CPUModule;
            vec->push_back(cpu);
            NetworkModule *net = new NetworkModule;
            vec->push_back(net);
            DiskModule *disk = new DiskModule;
            vec->push_back(disk);
            return;
        }
    }

    for (int i = 2; i < argc; i++)
    {
        if (!strcmp(argv[i], "-o"))
        {
            OSInfoModule *os = new OSInfoModule;
            vec->push_back(os);
        }
        else if (!strcmp(argv[i], "-h"))
        {
            HostUserNameModule *host = new HostUserNameModule;
            vec->push_back(host);
        }
        else if (!strcmp(argv[i], "-d"))
        {
            DateTimeModule *date = new DateTimeModule;
            vec->push_back(date);
        }
        else if (!strcmp(argv[i], "-r"))
        {
            RAMModule *ram = new RAMModule;
            vec->push_back(ram);
        }
        else if (!strcmp(argv[i], "-c"))
        {
            CPUModule *cpu = new CPUModule;
            vec->push_back(cpu);
        }
        else if (!strcmp(argv[i], "-n"))
        {
            NetworkModule *net = new NetworkModule;
            vec->push_back(net);
        }
        else if (!strcmp(argv[i], "-di"))
        {
            DiskModule *disk = new DiskModule;
            vec->push_back(disk);
        }
        else
            print_usage();
    }
}

void refresh(TerminalDisplay *term)
{
    std::vector<IMonitorModule *>::const_iterator it;
    std::vector<IMonitorModule *>::const_iterator ite = term->getModules().end();
    for (it = term->getModules().begin(); it != ite; ++it)
    {
        (*it)->refresh();
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage();
        return 0;
    }

    if (!strcmp(argv[1], "-t"))
    {
        std::vector<IMonitorModule *> vec;
        parseFlags(argc, argv, &vec);
        TerminalDisplay term(vec);
        if (vec.size() == 0)
        {
            term.setFinish();
        }
        while (!term.getFinish())
        {
            refresh(&term);
            term.screen();
        }
        std::vector<IMonitorModule *>::const_iterator it;
        std::vector<IMonitorModule *>::const_iterator ite = term.getModules().end();
        for (it = term.getModules().begin(); it != ite; ++it)
        {
             delete (*it);
        }
    }
    else if (!strcmp(argv[1], "-w"))
    {
    }
    else
    {
        print_usage();
    }
    return 0;
}