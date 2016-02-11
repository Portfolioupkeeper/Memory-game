#include "CApp.h"
 
void CApp::OnCleanup() {
    SDL_FreeSurface(Surf_Grid);

    SDL_FreeSurface(Surf_Display);

	TTF_Quit();
    SDL_Quit();
}