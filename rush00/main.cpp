#include <ncurses.h>
#include <unistd.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Vec2.hpp"
#include "Controller.hpp"
#include "Squad.hpp"
#include "time.h"
#define DELAY 30000
#define PLAYER_SPEED 3
#define BULLET_SPEED 2
#define FRAME_RATE 60.0f

void startMenu(int ww, int wh)
{
    mvprintw(wh / 5 + 0, ww / 3 + 6, "    ____       __             ");
    mvprintw(wh / 5 + 1, ww / 3 + 6, "   / __ \\___  / /__________   ");
    mvprintw(wh / 5 + 2, ww / 3 + 6, "  / /_/ / _ \\/ __/ ___/ __ \\  ");
    mvprintw(wh / 5 + 3, ww / 3 + 6, " / _, _/  __/ /_/ /  / /_/ /  ");
    mvprintw(wh / 5 + 4, ww / 3 + 6, "/_/ |_|\\___/\\__/_/   \\____/   ");

    mvprintw(wh / 5 + 13, ww / 3 + 8, "Space - START");
    mvprintw(wh / 5 + 14, ww / 3 + 8, "Esc   - END");
}

void endMenu(int score, int ww, int wh)
{

    mvprintw(wh / 5 + 0, ww / 3, "   ______                     ____                 ");
    mvprintw(wh / 5 + 1, ww / 3, "  / ____/___ _____ ___  ___  / __ \\_   _____  _____");
    mvprintw(wh / 5 + 2, ww / 3, " / / __/ __ `/ __ `__ \\/ _ \\/ / / / | / / _ \\/ ___/");
    mvprintw(wh / 5 + 3, ww / 3, "/ /_/ / /_/ / / / / / /  __/ /_/ /| |/ /  __/ /    ");
    mvprintw(wh / 5 + 4, ww / 3, "\\____/\\__,_/_/ /_/ /_/\\___/\\____/ |___/\\___/_/     ");

    mvprintw(wh / 5 + 13, ww / 3 + 12, "Final Score: %d", score);
}

int main(void)
{
    Controller controller;
    Controller menuController;
    int winX, winY;
    int key;
    float prevSec;
    float currSec;

    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    srand(time(0));
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    key = 0;
    getmaxyx(stdscr, winY, winX);
    Player player(winX / 2, winY - 10);
    Squad stars;
    Squad enemies;
    refresh();
    while (true)
    {
        clear();
        startMenu(winX, winY);
        key = getch();
        menuController.listen(key);
        if (menuController.attack)
            break;
        else if (menuController.end)
        {
            endwin();
            exit(0);
        }
        usleep(DELAY);
    }
    size_t initTime = time(0);
    size_t currentTime = time(0);
    currSec = (currentTime - initTime) % 60;
    key = 0;
    player.setMovementEdge(2, 2, winX - 2, winY - 2);
    enemies.setMovementEdge(2, 2, winX - 2, winY - 2);
    stars.setMovementEdge(2, 2, winX - 2, winY - 2);
    while (true)
    {

        clear();
        controller.listen(key);

        stars.generateObjects(1, winX, "star");
        player.move(controller.getVector(), PLAYER_SPEED); // * Time.DeltaTime
        player.display();
        prevSec = currSec;
        currentTime = time(0);
        currSec = (currentTime - initTime) % 60;
        mvprintw(2, winX - 10, "Time: %02d", currSec);
        if (currSec != prevSec)
        {
            enemies.generateObjects(3, winX, "enemy");
        }
        if (controller.attack)
            player.attack();
        Bullet *bullet = player.getBullet();
        if (bullet)
        {
            bullet->move(Vec2(0, -1), BULLET_SPEED);
            bullet->display();
            enemies.filterCollision(bullet->getPos());
        }
        mvprintw(2, 10, "Score: %d", enemies.getScore());
        stars.displayObjects();
        stars.moveObjects(Vec2(0, 1), 2);
        enemies.displayObjects();
        enemies.moveObjects(Vec2(0, 1), currSec - prevSec);
        key = getch();

        usleep(DELAY);

        if (controller.end || enemies.playerCollision(player.getPos()))
            break;
        controller.refresh();
        refresh();
    }

    currentTime = time(0);

    size_t nextSec = 0;
    while (nextSec <= 3)
    {
        size_t newTime = time(0);
        nextSec = (newTime - currentTime) % 60;
        clear();
        endMenu(enemies.getScore(), winX, winY);
        key = getch();
        usleep(DELAY);
    }
    endwin();
}