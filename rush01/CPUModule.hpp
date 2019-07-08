/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:16:10 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 11:25:41 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class CPUModule : public IMonitorModule
{
  private:
    std::vector<std::string> out;
    std::string moduleName;

  public:
    CPUModule(void);
    CPUModule(CPUModule &val);
    CPUModule &operator=(CPUModule const &val);
    ~CPUModule(void);
    std::string const &getName(void) const;
    std::vector<std::string> const &getOutput(void) const;
    void refresh(void);
};