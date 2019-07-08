/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <pmartyny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:10:57 by pmartyny          #+#    #+#             */
/*   Updated: 2019/07/07 19:51:09 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalDisplay.hpp"

TerminalDisplay::TerminalDisplay(void) : modules()
{
}

TerminalDisplay::TerminalDisplay(std::vector<IMonitorModule *> modules) : modules(modules), finish(0), printCat(1)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    refresh();
    getmaxyx(stdscr, this->y, this->x);
}

TerminalDisplay::TerminalDisplay(TerminalDisplay &val)
{
    *this = val;
}

TerminalDisplay &TerminalDisplay::operator=(TerminalDisplay const &val)
{
    this->modules = val.modules;
    this->x = val.x;
    this->y = val.y;
    return *this;
}

TerminalDisplay::~TerminalDisplay(void)
{
    endwin();
}

int TerminalDisplay::getFinish(void)
{
    return this->finish;
}

std::vector<IMonitorModule *> &TerminalDisplay::getModules(void)
{
    return this->modules;
}

void TerminalDisplay::setCatFalse(void)
{
    this->printCat = false;
}

void TerminalDisplay::setFinish(void)
{
    this->finish = 1;
}

void TerminalDisplay::screen(void)
{
    static bool cat = true;
    size_t i;
    size_t x;
    int length;
    int y = 1;
    i = 0;

    freeSpace();
    if (getch() == 27)
    {
        this->finish = 1;
        endwin();
    }
    while (i < this->modules.size())
    {
        x = 0;
        length = 1;
        mvprintw(y + i, 1, this->modules.at(i)->getName().c_str());
        y++;
        while (x < (this->modules.at(i)->getOutput().size()))
        {

            mvprintw(y + i, length, this->modules.at(i)->getOutput().at(x).c_str());
            length += this->modules.at(i)->getOutput().at(x).length();
            length++;
            x++;
        }
        if (!strcmp(this->modules.at(i)->getName().c_str(), "RAM Module"))
        {
            y++;
            mvprintw(y + i, 1, "Used:   [");
            attron(COLOR_PAIR(2));
            double tmp = std::stoi(this->modules.at(i)->getOutput().at(1).substr(6, 15));
            double max = 8192;
            double res = tmp / max;
            double out = 0;
            for (int k = 2; k < 42; k++)
            {
                if (out < res)
                {
                    mvaddch(y + i, k + 8, '#');
                    out += 0.025;
                }
                else
                {
                    attroff(COLOR_PAIR(2));
                    mvaddch(y + i, k + 8, '#');
                }
            }
            mvprintw(y + i, 50, "]");
        }
        else if (!strcmp(this->modules.at(i)->getName().c_str(), "CPU Module"))
        {
            y++;
            mvprintw(y + i, 1, "User:   [");
            attron(COLOR_PAIR(2));
            double tmp = std::stoi(this->modules.at(i)->getOutput().at(0).substr(6, 12));
            tmp /= 100;
            double out = 0;
            for (int k = 2; k < 42; k++)
            {
                if (out < tmp)
                {
                    mvaddch(y + i, k + 8, '#');
                    out += 0.025;
                }
                else
                {
                    attroff(COLOR_PAIR(2));
                    mvaddch(y + i, k + 8, '#');
                }
            }
            mvprintw(y + i, 50, "]");

            y++;
            mvprintw(y + i, 1, "System: [");
            attron(COLOR_PAIR(2));
            tmp = std::stoi(this->modules.at(i)->getOutput().at(1).substr(8, 15));
            tmp /= 100;
            out = 0;
            for (int k = 2; k < 42; k++)
            {
                if (out < tmp)
                {
                    mvaddch(y + i, k + 8, '#');
                    out += 0.025;
                }
                else
                {
                    attroff(COLOR_PAIR(2));
                    mvaddch(y + i, k + 8, '#');
                }
            }
            mvprintw(y + i, 50, "]");

            y++;
            mvprintw(y + i, 1, "Idle:   [");
            attron(COLOR_PAIR(2));
            tmp = std::stoi(this->modules.at(i)->getOutput().at(2).substr(6, 15));
            tmp /= 100;
            out = 0;
            for (int k = 2; k < 42; k++)
            {
                if (out < tmp)
                {
                    mvaddch(y + i, k + 8, '#');
                    out += 0.025;
                }
                else
                {
                    attroff(COLOR_PAIR(2));
                    mvaddch(y + i, k + 8, '#');
                }
            }
            mvprintw(y + i, 50, "]");
        }
        y++;
        i++;
    }
    if (this->printCat)
    {
        if (cat)
        {
            mvprintw(y + i, 0, "\nX XXXXX                                       XXX\n \
X     XXX                                   XXX X\n \
 X      XXX                                XX   XX\n \
 X        XXX                            XX      X\n \
 XX         XX                          XX       X                      XXX\n \
  X           XX      XXXXX             X        X                     XX XX  XXX\n \
  X            XX XXXX     XXXXXXX     X         X                    XX   XXXX X\n \
  XX            XXX              XXXXXXX         X                   XXXXXXXX  XX\n \
  XX            XX                   XX          X                 XXX   XXX  XX\n \
  XX                                  XXXXXXX    X               XXX       XXXXXXXX\n \
    X                  XX         XXXXX   XXXXX XX             XXX           X XXXX\n \
     X             XXXXX X     XXX            X X            XX            XXXXX\n \
      X           XX  X  XXXXXXX           XXXX X         XXXX          XXX\n \
       XX          XXXXXXXX                 XX  X      XXXX           XXX\n \
        XX       XXXXXXX          XXXXXXXXXXXX XX    XXX            XX\n \
          XXXXXXX              XXXXX           X   XX             XX\n \
        XXXXXX             XXXXX              X  XX            XXX\n \
     XXXX    XXX       XXXXX XX              XX XX           XX\n \
   XX          XXXXXXXX                     XXXX          XXX\n \
   XXX        XXXXXXX         XXXXX        XXX         XXX\n \
     XXX      XX  X  XXXX    XX    XX     XXX        XXX\n \
       XXX     XX X     XXXX           XXX X       XXX\n \
         XXX    XXX         XXXXXXXXXXX    XX     XX\n \
           XXX  XX                          X  XXX\n \
             XXX X                          XXXX\n \
                XX                          XX\n \
                 X                          X\n \
                 X                          X\n \
                 X                          X\n \
                 X                          X\n");
        }
        else
        {
            mvprintw(y + i, 0, "\n\
                         XXX                                             X\n\
                         X XXXXX                                       XXX\n\
                         X     XXX                                   XXX X\n\
                          X      XXX                                XX   XX\n\
                          X        XXX                            XX      X\n\
      XXXX                XX         XX                          XX       X\n\
  XX X   XX                X           XX      XXXXX             X        X\n\
 XX XXXX  X                X            XX XXXX     XXXXXXX     X         X\n\
  XXXX   XX                XX            XXX              XXXXXXX         X\n\
XX  XXX   XX               XX            XX                   XX          X\n\
XX          XX             XX                                             X\n\
  XXXXX      XXX             X                XXXX         XXX           XX\n\
      XXX      XXX            X           XXXXX  XXXXX  XXX   XXX        X\n\
         XX       XX           X          XX           XXXX  X  X        X\n\
           XXX      XXX         XX        XX               XXXXXX        X\n\
             XXXX     XXX        XX      XX                  XXXXXXXXX  XX\n\
                XXX      XXXX      XX     XXXXXXXXXXXXX              XXXXXX\n\
                  XXX       XXXX     XX              XXXXXXXX              XXXX\n\
                     XXX       XXX    XXX             XX     XXXXXXX          XXX\n\
                        XXX       XXX   XXX                        XXX        XX\n\
                          XXX       XXXX   XXX         XXXXX        XXX      XX\n\
                            XXXX       XXX X  XXXX    XX    XX     XXXX     XX\n\
                               XXX        XX     XXXX           XXX XX    XX\n\
                                 XXXX     XX         XXXXXXXXXXX    XX   XX\n\
                                     XXXX X                          X  XX\n\
                                        XXX                          X XX\n\
                                          X                          XXX\n\
                                          X                          X\n\
                                          X                          X\n\
                                         XX                          X\n\
                                         X                           X\n\
                                         X                           X\n\
                                         X                           XX\n");
        }
        cat = !cat;
    }
    box(stdscr, 0, 0);
    refresh();
}

void TerminalDisplay::freeSpace(void)
{
    int x = 0;
    int y = 0;

    while (y < this->y)
    {
        x = 0;
        while (x < this->x)
        {
            mvprintw(y, x, "      ");
            x++;
        }

        y++;
    }
}