/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:13:40 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 17:14:17 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class DiskModule : public IMonitorModule
{
  private:
    std::vector<std::string> out;
    std::string moduleName;

  public:
    DiskModule(void);
    DiskModule(DiskModule &val);
    DiskModule &operator=(DiskModule const &val);
    ~DiskModule(void);
    std::string const &getName(void) const;
    std::vector<std::string> const &getOutput(void) const;
    void refresh(void);
};