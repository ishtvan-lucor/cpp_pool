/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:09:03 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/06 16:30:08 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class IMonitorDisplay
{
  public:
    IMonitorDisplay(void);
    IMonitorDisplay(IMonitorDisplay &val);
    IMonitorDisplay &operator=(IMonitorDisplay const &val);
    virtual ~IMonitorDisplay();
};
