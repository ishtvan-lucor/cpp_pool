/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:56:33 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 12:37:01 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule(void)
{
}

IMonitorModule::IMonitorModule(IMonitorModule &val)
{
    *this = val; 
}

IMonitorModule &IMonitorModule::operator=(IMonitorModule const &val)
{
    (void)val;
    return *this;
}

IMonitorModule::~IMonitorModule(void)
{
}
