#include "CApp.h"
 
CApp::CApp() {
	Running = true;
	asking = true;
	in_newgame = false;
	turns = 0;
	points = 0;

	newG << "New Game";
	stuff << "Points:  " << points;

	white.r = 20;
	white.g = 20;
	white.b = 0;

	t_rect.x = 10;
	t_rect.y = 365;
	newgame_rect.x = 280;
	newgame_rect.y = 405;
 
    Surf_Display = NULL;
	Surf_Grid = NULL;
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
		OnRender();     
    }
 
    OnCleanup();
 
    return 0;
}

void CApp::NewGame()
{
	int button_y = 400;
	newgame_rect.y = 405;
	in_newgame = true;
    SDL_Event Event;
 
    while(asking) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

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

		CSurface::OnDraw(Surf_Display, Surf_Bg, 265, button_y);

		SDL_BlitSurface(Surf_NewGame, NULL, Surf_Display, &newgame_rect);
		SDL_Flip(Surf_Display);
		if(button_y > 362){
			button_y--;
			newgame_rect.y--;
		}
    }
	asking = true;
	
}

void CApp::Reset() {
    for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 5;j++) {
			laivat[i][j] = 0;
			osumat[i][j] = GRID_TYPE_X;
		}
    }
}

void CApp::Kuvien_asettelu()
{
	int counter = 0;
	

	while(counter < 20){
		bool set = false;
		int randint = rand() % 10 + 1;
		int max = 0;

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 5; j++){
				if (laivat[i][j] == randint){
					max++;
				}
			}
		}

		if(max < 2){

			for(int i = 0; i < 4; i++){
				if(set) break;
				for(int j = 0; j < 5; j++){
					if(laivat[i][j] == 0){

						laivat[i][j] = randint;
						counter++;
						set = true;
						break;
					}
				}
			}
		}
	}
	
}

void CApp::SetCell(int IDR, int IDK, int Type) {
    if(IDR < 0 || IDR >= 5) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;
 
    osumat[IDR][IDK] = Type;
}



int main(int argc, char* argv[]) {
	srand(time(0));
    CApp theApp;
 
    return theApp.OnExecute();
}