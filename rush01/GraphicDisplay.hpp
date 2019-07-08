//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#ifndef RUSH01_GRAPHICDISPLAY_HPP
#define RUSH01_GRAPHICDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <unistd.h>


class GraphicDisplay : public IMonitorDisplay
{
private:
	int	_width;
	int	_height;
	SDL_Window*	_window;
	SDL_Renderer*	_image;

public:
	GraphicDisplay();
	GraphicDisplay(GraphicDisplay const &copy);
	GraphicDisplay &operator=(GraphicDisplay const &target);
	~GraphicDisplay();

	void	display();
	void	init();

};


#endif //RUSH01_GRAPHICDISPLAY_HPP
