/*
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

// aliohjelmat
void luuppi ();
void valinnat ( char);
void init ();
void auto_laivanasettelu ();


// laivan ampuminen (koordinaattijen merkitseminen osuma/huti/uponnut)
void ampuminen (bool &, int &);

// globaali laivataulukko
const int RIVIT = 7;
const int KOLUMNIT = 7;
int laivat [RIVIT][KOLUMNIT] = {0};

// globaali osumataulukko
char osumat [RIVIT][KOLUMNIT];

// globaali laivojen idexitaulukko [mikä laiva], [mikä osa laivaa], [indexit]
int laivojen_indexit[6][5][2] = {0};


SDL_Surface* Surf_Display = NULL;
SDL_Surface* Surf_BG = NULL;


int main()
{
	init ();
	luuppi();

	system ("PAUSE");
	return 0;
}

void init ()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	Surf_BG = IMG_Load("gfx/grid.png");

    SDL_Rect DestR;
 
    DestR.x = 0;
    DestR.y = 0;
 
    SDL_BlitSurface(Surf_BG, NULL, Surf_Display, &DestR);
}

// Kysyy pelaajan valinnan ja pyörittää pelin silmukkaa
void luuppi(){
	srand(time(0));

	auto_laivanasettelu ();

	while (true)
	{

	}		
}

// automaattinen laivojen asettelu ei syötteitä pelaajalta
void auto_laivanasettelu ()
{
	int laivan_pituus = 5;
	char suunta[5] = "ilpe";
	char c_suunta;
	int rivi_indexi = 0;
	int kolumni_indexi = 0;

	while (laivan_pituus > 1)
	{
		bool portinvartija = false;
		bool vapaa_paikka = true;

		rivi_indexi = rand() % 7;
		kolumni_indexi = rand() % 7;
		c_suunta = suunta[rand() % 4];

		if (c_suunta == 'i')
		{
			if ( kolumni_indexi + laivan_pituus < 7)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi][kolumni_indexi + i] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'l')
		{
			if ( kolumni_indexi - laivan_pituus >= 0)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi][kolumni_indexi - i] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'e')
		{
			if ( rivi_indexi + laivan_pituus < 7)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi + i][kolumni_indexi] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}
		else if (c_suunta == 'p')
		{
			if ( rivi_indexi - laivan_pituus >= 0)
			{
				for (int i = 0; i < laivan_pituus; i++)
				{
					if (laivat[rivi_indexi - i][kolumni_indexi] != 0)
					{
						vapaa_paikka = false;
					}
				}

				if (vapaa_paikka)
				{
					portinvartija = true;
				}
			}
		}

		if (portinvartija)
		{
			for (int i = 0; i < laivan_pituus; i++)
			{

				laivat[rivi_indexi][kolumni_indexi] = laivan_pituus;

				laivojen_indexit[laivan_pituus][i][0] = rivi_indexi;
				laivojen_indexit[laivan_pituus][i][1] = kolumni_indexi;

				if (c_suunta == 'i')
					kolumni_indexi++;
				else if (c_suunta == 'l')
					kolumni_indexi--;
				else if (c_suunta == 'p')
					rivi_indexi--;
				else if (c_suunta == 'e')
					rivi_indexi++;
			} 

			laivan_pituus--;
		}
	}
}

// laivojen ampuminen (koordinaattien merkaaminen)
void ampuminen (bool &laivat_asetettu, int &LKM_OSUMAT)

{
	char koordinaatti[5];
	int rivi_indexi = 0;
	int kolumni_indexi = 0;
	int osumien_lkm = 0;
	int asciiKeno = 92;

	while(true)
	{
		osumien_lkm = 0;

		cout << endl << "Pelitilanne on seuraava:" << endl << endl;
		osumien_tulostus();

		cout << endl << "Anna ampumiskoordinaatti: ";
		cin.getline (koordinaatti,5);

		if ( koordinaatti[0] == asciiKeno && koordinaatti[1] == '@' )
		{
			cout << endl << "Laivat sijaitsevat seuraavissa paikoissa:" << endl;
			laivojen_tulostus ();
		}

		else
		{
			// Annettu koordinaatin kirjain muutetaan isokirjaimeksi
			koordinaatti[0] = char(toupper(koordinaatti[0]));

				switch (koordinaatti[0])
			{
				case 'A':
					rivi_indexi = 0;
					break;
				case 'B':
					rivi_indexi = 1;
					break;
				case 'C':
					rivi_indexi = 2;
					break;
				case 'D':
					rivi_indexi = 3;
					break;
				case 'E':
					rivi_indexi = 4;
					break;
				case 'F':
					rivi_indexi = 5;
					break;
				case 'G':
					rivi_indexi = 6;
					break;
				case 'P':
					return;
			}
			switch (koordinaatti[1])
			{
				case '1':
					kolumni_indexi = 0;
					break;
				case '2':
					kolumni_indexi = 1;
					break;
				case '3':
					kolumni_indexi = 2;
					break;
				case '4':
					kolumni_indexi = 3;
					break;
				case '5':
					kolumni_indexi = 4;
					break;
				case '6':
					kolumni_indexi = 5;
					break;
				case '7':
					kolumni_indexi = 6;
					break;
			}

			if ( laivat[rivi_indexi][kolumni_indexi] != 0) 
			{
				cout << endl << endl << "Laukaus kohtaan " << koordinaatti[0] << koordinaatti[1] << " osui laivaan.";
				int laivan_pituus = laivat[rivi_indexi][kolumni_indexi];

				osumat[rivi_indexi][kolumni_indexi]  = '*';

				LKM_OSUMAT++;

				for (int i = 0; i < laivan_pituus; i++)
				{
					rivi_indexi = laivojen_indexit[laivan_pituus][i][0];
					kolumni_indexi = laivojen_indexit[laivan_pituus][i][1];

					if (osumat[rivi_indexi][kolumni_indexi] == '*')
					{
						osumien_lkm++;
					}
					else
						break;
				}

				if (osumien_lkm == laivan_pituus)
				{
					cout << endl << "Laukaus upotti laivan.";
					for (int i = 0; i < laivan_pituus; i++)
					{
						osumat[laivojen_indexit[laivan_pituus][i][0]][laivojen_indexit[laivan_pituus][i][1]] = '#';
					}
				}
	
			}
			else
			{
				cout << endl << endl << "Laukaus kohtaan " << koordinaatti[0] << koordinaatti[1] << " ei osunut.";
				osumat [rivi_indexi][kolumni_indexi]  = 'X';
			}

			if (LKM_OSUMAT == 14)
			{
				osumien_tulostus();
				cout << endl << "WHOAAAAA UPOTIT KAIKKI FIDUN LAIVAT!!!" << endl << endl;

				laivat_asetettu = false;
				return;
			}
		}
	}
}*/