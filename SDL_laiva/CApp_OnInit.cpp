#include "CApp.h"
 
bool CApp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		return false;
	}

	TTF_Init();

 
    if((Surf_Display = SDL_SetVideoMode(450, 400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Grid = CSurface::OnLoad("gfx/room.png")) == NULL) {
    return false;
    }

    if((Surf_Bg = CSurface::OnLoad("gfx/green_button.png")) == NULL) {
    return false;
    }

    if((Surf_Bar = CSurface::OnLoad("gfx/bar.png")) == NULL) {
    return false;
    }

    if((Surf_T = CSurface::OnLoad("gfx/foo_tile.png")) == NULL) {
    return false;
    }
 
    if((Surf_1 = CSurface::OnLoad("gfx/art.png")) == NULL) {
    return false;
    }
 
    if((Surf_2 = CSurface::OnLoad("gfx/badge.png")) == NULL) {
    return false;
    }
	
    if((Surf_3 = CSurface::OnLoad("gfx/books.png")) == NULL) {
    return false;
    }

    if((Surf_4 = CSurface::OnLoad("gfx/boombox.png")) == NULL) {
    return false;
    }

    if((Surf_5 = CSurface::OnLoad("gfx/bulb.png")) == NULL) {
    return false;
    }

    if((Surf_6 = CSurface::OnLoad("gfx/butterfly.png")) == NULL) {
    return false;
    }

    if((Surf_7 = CSurface::OnLoad("gfx/globe.png")) == NULL) {
    return false;
    }

    if((Surf_8 = CSurface::OnLoad("gfx/safe.png")) == NULL) {
    return false;
    }

    if((Surf_9 = CSurface::OnLoad("gfx/paper.png")) == NULL) {
    return false;
    }

    if((Surf_10 = CSurface::OnLoad("gfx/prick.png")) == NULL) {
    return false;
    }

    if((Surf_rim = CSurface::OnLoad("gfx/goldrim.png")) == NULL) {
    return false;
    }


    //CSurface::Transparent(Surf_X, 255, 0, 255);
    //CSurface::Transparent(Surf_O, 255, 0, 255);


	// Sound init
	if((SoundA = CSoundBank::SoundControl.OnLoad("sounds/button-29.wav")) == -1) { // Basic button sound
		return false;
	}

	if((SoundB = CSoundBank::SoundControl.OnLoad("sounds/button-30.wav")) == -1) { // Mach found sound
		return false;
	}

	if((SoundC = CSoundBank::SoundControl.OnLoad("sounds/open4.wav")) == -1) { // Replay sound
		return false;
	}

	times = TTF_OpenFont("fonts/Three-Sixty.ttf", 22);

	Surf_Points =  TTF_RenderText_Solid(times, stuff.str().c_str(), white);
	Surf_NewGame =  TTF_RenderText_Solid(times, newG.str().c_str(), white);

	Reset();
	Kuvien_asettelu();
 
    return true;
}