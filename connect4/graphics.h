/***************************************************************************
                          graphics.h  -  description
                             -------------------
    begin                : Sat Jul 21 2001
    copyright            : (C) 2001 by Sam "Criswell" Hart
    email                : criswell@geekcomix.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation                             *
 *                                                                         *
 ***************************************************************************/

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <unistd.h>

#define MAX_UPDATES 100
#define DEFAULT_FPS 50

class graphicInit
{
    public:
        graphicInit();
        ~graphicInit();

        /* Lib init constructor */
        graphicInit(Uint32 lib_flags, bool verb);

        /* Screen methods */
        SDL_Surface *setVideoMode(int w, int h, int bpp, Uint32 vid_flags);
        void restartVideo(void);
        SDL_Surface *getScreen(void);
        void setFPS(int newfps);
        int getFPS(void);
        void centerWindow();
        void draw(SDL_Rect *rect);
        void update(void);
        void update(bool tf);
        void waitFrame(int i);

        /* Image Loading methods */
        SDL_Surface *loadImage(char *datafile);
        SDL_Surface *loadImage(char *datafile, bool alpha);
        SDL_Surface *loadImage(char *datafile, Uint32 alphackey);

        /* Other misc image methods */
        SDL_Rect *overlap(SDL_Rect *object1, SDL_Rect *object2);

        /* Text Loading methods */
        char *loadTextLine(char *datafile, int max);

        /* TTF utils */
        void ttfInit(void);
        TTF_Font *loadFont(char *datafile, int ptsize);

        /* Load Prefix Items */
        void setLoadPrefix(char *prefix, bool tf);
    private:
        bool verbose;
        SDL_Surface *screen;
        int PID;
        char *data_prefix;
        bool use_prefix;
        bool use_ttf;

        SDL_Rect blits[MAX_UPDATES];
        int numupdates;

        int fps;
};

#endif
/* __GRAPHICS_H__ */