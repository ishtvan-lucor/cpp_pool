/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:54:31 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/06 16:56:00 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay(void)
{
}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay &val)
{
    *this = val;
}

IMonitorDisplay &IMonitorDisplay::operator=(IMonitorDisplay const &val)
{
    (void)val;
    return *this;
}

IMonitorDisplay::~IMonitorDisplay(void)
{
}
