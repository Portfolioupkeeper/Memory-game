#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
#include <time.h>
#include <string.h>
#include <sstream>
 
#include "CEvent.h"
#include "CSurface.h"
#include "CSoundBank.h"
#include "SDL_ttf.h"

using namespace std;
 
class CApp : public CEvent {
    private:
        bool            Running;
 
        SDL_Surface*    Surf_Display;
 
    private:
        SDL_Surface*    Surf_Grid;
        SDL_Surface*    Surf_T;
		SDL_Surface*    Surf_NewGame;
		SDL_Surface*    Surf_Points;
		SDL_Surface*    Surf_Bg;
		SDL_Surface*    Surf_Br;
		SDL_Surface*    Surf_Bar;
		SDL_Surface*    Surf_rim;
 
        SDL_Surface*    Surf_1;
        SDL_Surface*    Surf_2;
		SDL_Surface*    Surf_3;
        SDL_Surface*    Surf_4;
        SDL_Surface*    Surf_5;
		SDL_Surface*    Surf_6;
        SDL_Surface*    Surf_7;
        SDL_Surface*    Surf_8;
		SDL_Surface*    Surf_9;
        SDL_Surface*    Surf_10;


    private:
        int laivat[4][5];
		int osumat[4][5];

		int CurrentPlayer;

		enum {
			GRID_TYPE_R,
			GRID_TYPE_X,
			GRID_TYPE_O
		};
	public:
		
		
		SDL_Rect t_rect;
		SDL_Rect newgame_rect;
		int turns;
		int points;
		bool asking;
		bool in_newgame;
		string s1;
		char c;
		TTF_Font *times;
		stringstream stuff;
		stringstream newG;
		SDL_Color white;
		int moveX;
		int moveY;


    public:
        CApp();
 
        int OnExecute();

    public:
        int SoundA;
        int SoundB;
		int SoundC;
 
    public:
        bool OnInit();
 
        void OnEvent(SDL_Event* Event);
 
        void OnLButtonDown(int mX, int mY);        void OnExit();

		void OnLButtonUp(int mX, int mY);

		void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();

		void Laivanasettelu();

		void Kuvien_asettelu();

	public:
		void Reset();

		void SetCell(int IDR, int IDK, int Type);

		void NewGame();

};
 
#endif