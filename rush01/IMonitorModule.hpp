/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:09:07 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 18:01:31 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class IMonitorModule
{
public:
  IMonitorModule(void);
  IMonitorModule(IMonitorModule &val);
  IMonitorModule &operator=(IMonitorModule const &val);
  virtual ~IMonitorModule(void);
  virtual std::vector<std::string> const &getOutput(void) const = 0;
  virtual std::string const &getName(void) const = 0;
  virtual void refresh(void) = 0;
};