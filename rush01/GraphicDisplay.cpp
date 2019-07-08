//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-07.
//

#include "GraphicDisplay.hpp"

GraphicDisplay::GraphicDisplay(): _width(500), _height(700)
{}

GraphicDisplay::GraphicDisplay(GraphicDisplay const &copy)
{
	*this = copy;
}

GraphicDisplay& GraphicDisplay::operator=(GraphicDisplay const &target)
{
	_window	= target._window;
	_image = target._image;
	return (*this);
}

GraphicDisplay::~GraphicDisplay()
{}

void GraphicDisplay::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("gkrellm", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN);

	_image = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(_image, 0xff, 0xff, 0xff, 0xff);
	TTF_Init();
}

void GraphicDisplay::display()
{
	bool		quit = false;
	SDL_Event	e;

	init();
	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
			if(e.type == SDL_QUIT)
				quit = true;

		SDL_Rect r = { 0, 0, _width, _height};
		SDL_RenderDrawRect(_image, &r);
		SDL_RenderDrawLine(_image, 0 ,0, 100, 100);
		SDL_RenderPresent(_image);
		usleep(100000);
	}
}