#include "CApp.h"
 
void CApp::OnRender() {
	SDL_FillRect(Surf_Display, NULL, 0x000000);
    CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);
	CSurface::OnDraw(Surf_Display, Surf_Bar, 0, 360);

	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 5;j++) {

			int Y = i * 90;
			int X = j * 90;
 
			if(osumat[i][j] == GRID_TYPE_O || osumat[i][j] == GRID_TYPE_R){

				if(laivat[i][j] == 1) {
					CSurface::OnDraw(Surf_Display, Surf_1, X, Y);
				}
				else if(laivat[i][j] == 2) {
					CSurface::OnDraw(Surf_Display, Surf_2, X, Y);
				}
				else if(laivat[i][j] == 3) {
					CSurface::OnDraw(Surf_Display, Surf_3, X, Y);
				}
				else if(laivat[i][j] == 4) {
					CSurface::OnDraw(Surf_Display, Surf_4, X, Y);
				}
				else if(laivat[i][j] == 5) {
					CSurface::OnDraw(Surf_Display, Surf_5, X, Y);
				}
				else if(laivat[i][j] == 6) {
					CSurface::OnDraw(Surf_Display, Surf_6, X, Y);
				}
				else if(laivat[i][j] == 7) {
					CSurface::OnDraw(Surf_Display, Surf_7, X, Y);
				}
				else if(laivat[i][j] == 8) {
					CSurface::OnDraw(Surf_Display, Surf_8, X, Y);
				}
				else if(laivat[i][j] == 9) {
					CSurface::OnDraw(Surf_Display, Surf_9, X, Y);
				}
				else if(laivat[i][j] == 10) {
					CSurface::OnDraw(Surf_Display, Surf_10, X, Y);
				}
			}else CSurface::OnDraw(Surf_Display, Surf_T, X, Y);
			
		}
	}
	SDL_BlitSurface(Surf_Points, NULL, Surf_Display, &t_rect);

    SDL_Flip(Surf_Display);
}