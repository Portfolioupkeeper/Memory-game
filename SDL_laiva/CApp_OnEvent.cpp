#include "CApp.h"
 
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}
 
void CApp::OnExit() {
    Running = false;
	asking = false;
}

void CApp::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle){
}

void CApp::OnLButtonUp(int mX, int mY) {
}

void CApp::OnLButtonDown(int mX, int mY) {
    int IDK    = mX / 90;
    int IDR    = mY / 90;
    int max = 0; 
	int max_R = 0; 
	int compare = 0;
	int indexes[4] = {-1,-1,-1,-1};

	// Kun ei olla newgame ikkunassa.
	if(!in_newgame){

		// Katsoo kuinka monta luukkua on auki. Ratkaistuja ei lasketa.
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 5; j++){
				if(osumat[i][j] == GRID_TYPE_O){
					if(indexes[0] == -1){
						indexes[0] = i;
						indexes[1] = j;
					}else {
						indexes[2] = i;
						indexes[3] = j;
					}
					max++;
				}
			}
		}

		// Jos kaksi erilaista luukkua auki ne suljetaan.
		if(max == 2 && osumat[IDR][IDK] != GRID_TYPE_O || max == 2 && osumat[IDR][IDK] != GRID_TYPE_R){
			if(laivat[indexes[0]][indexes[1]] != laivat[indexes[2]][indexes[3]]){
				SetCell(indexes[0], indexes[1], GRID_TYPE_X);
				SetCell(indexes[2], indexes[3], GRID_TYPE_X);
			}
		}

		if(IDR < 4){
			// Jos klikatussa kohdassa on avattu tai ratkaistu ei tehdä mitään.
			if(osumat[IDR][IDK] == GRID_TYPE_O || osumat[IDR][IDK] == GRID_TYPE_R) {
				moveY = mY;
				moveX = mX;
				return;
			}else  {
				SetCell(IDR, IDK, GRID_TYPE_O);
				CSoundBank::SoundControl.Play(SoundA);

				turns ++;
				stuff.str("");
				stuff << "Points:  " << points - turns;
				Surf_Points =  TTF_RenderText_Solid(times, stuff.str().c_str(), white);
			}
		}

		for(int i = 0; i < 4; i++) indexes[i] = -1;
		max = 0;

		// Katsoo kuinka monta luukkua on auki. Ratkaistuja ei lasketa.
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 5; j++){
				if(osumat[i][j] == GRID_TYPE_O){
					if(indexes[0] == -1){
						indexes[0] = i;
						indexes[1] = j;
					}else {
						indexes[2] = i;
						indexes[3] = j;
					}
					max++;
				}
			}
		}

		// Jos kaksi luukkua auki katsotaan saatiinko ratkaistua.
		if(max == 2){
			if(laivat[indexes[0]][indexes[1]] == laivat[indexes[2]][indexes[3]]){
				SetCell(indexes[0], indexes[1], GRID_TYPE_R);
				SetCell(indexes[2], indexes[3], GRID_TYPE_R);

				points += 10;
				CSoundBank::SoundControl.Play(SoundB);
				stuff.str("");
				stuff << "Points:  " << points - turns;
				Surf_Points =  TTF_RenderText_Solid(times, stuff.str().c_str(), white);

				// Katsotaan onko kaikki ratkaistuja.
				for(int i = 0; i < 4; i++){
					for(int j = 0; j < 5; j++){
						if(osumat[i][j] == GRID_TYPE_R){
							max_R++;
						}
					}
				}
				// Jos kaikki on ratkaistu mennään newgame ikkunaan.
				if(max_R >= 20){
					stuff.str("");
					stuff << "Points:  " << points - turns;
					Surf_Points =  TTF_RenderText_Solid(times, stuff.str().c_str(), white);

					NewGame();
				}	
			}
		}
	}

	// Newgame napin ohjaus newgame ikkunassa.
	if(in_newgame && mX >= 280 && mX <= 409 && mY >= 365 && mY <= 405){
		CSoundBank::SoundControl.Play(SoundC);

		Reset();
		Kuvien_asettelu();	

		turns = 0;
		points = 0;
		asking = false;
		in_newgame = false;
		stuff.str("");
		stuff << "Points:  " << points;
		Surf_Points =  TTF_RenderText_Solid(times, stuff.str().c_str(), white);
	}
}