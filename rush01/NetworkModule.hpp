/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:37:59 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 12:38:53 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorModule.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class NetworkModule : public IMonitorModule
{
  private:
    std::vector<std::string> out;
    std::string moduleName;

  public:
    NetworkModule(void);
    NetworkModule(NetworkModule &val);
    NetworkModule &operator=(NetworkModule const &val);
    ~NetworkModule(void);
    std::string const &getName(void) const;
    std::vector<std::string> const &getOutput(void) const;
    void refresh(void);
};