/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:56:04 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 11:24:50 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class RAMModule : public IMonitorModule
{
  private:
    std::vector<std::string> out;
    std::string moduleName;

  public:
    RAMModule(void);
    RAMModule(RAMModule &val);
    RAMModule &operator=(RAMModule const &val);
    ~RAMModule(void);
    std::string const &getName(void) const;
    std::vector<std::string> const &getOutput(void) const;
    void refresh(void);
};