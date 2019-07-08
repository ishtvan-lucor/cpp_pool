/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:06:07 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 19:50:40 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <vector>
#include <ncurses.h>

class TerminalDisplay : public IMonitorDisplay
{
private:
  std::vector<IMonitorModule *> modules;
  int x;
  int y;
  int finish;
  bool printCat;

public:
  TerminalDisplay(void);
  TerminalDisplay(std::vector<IMonitorModule *> modules);
  TerminalDisplay(TerminalDisplay &val);
  TerminalDisplay &operator=(TerminalDisplay const &val);
  ~TerminalDisplay(void);

  void screen(void);
  void freeSpace(void);
  int getFinish(void);
  void setFinish(void);
  void setCatFalse(void);
  std::vector<IMonitorModule *>& getModules(void);

};
