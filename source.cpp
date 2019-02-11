#include "types.h"
#include "theseusmem.h"

using namespace std;

ProcMem Theseus;

int main()
{
    Theseus.Process("csgo.exe");
	Client = Theseus.Module("client.dll");
	SetConsoleTitle("Theseus PRO");
	inicio();
    HANDLE rghThreads[] = {

    	CreateThread(NULL, NULL, teclas, NULL, NULL, NULL),
		CreateThread(NULL, NULL, data, NULL, NULL, NULL),
		CreateThread(NULL, NULL, parede, NULL, NULL, NULL),
	};
	WaitForMultipleObjects(sizeof(rghThreads) / sizeof(HANDLE), rghThreads, TRUE, INFINITE);
    return 0;
}

void texto(int Color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
}

void inicio(){

	string TheseusMessage1 = "___ _  _ ____ ____ ____ _  _ ____    ___  ____ ____  ";
	string TheseusMessage2 = " |  |__| |___ [__  |___ |  | [__     |__] |__/ |  |  ";
	string TheseusMessage3 = " |  |  | |___ ___] |___ |__| ___]    |    |  \\ |__| ";
	string TheseusMessage4 = "Theseus [F3] is: ";
    system("cls");
    texto(15);
    cout << TheseusMessage1 << endl << TheseusMessage2 << endl << TheseusMessage3 << endl << endl << endl;

    if (TheseusON == false){
        cout << TheseusMessage4;
        texto(12);
        cout << "OFF" << endl;
    }
    else if (TheseusON == true){
        cout << TheseusMessage4;
        texto(10);
        cout << "ON" << endl;
    }
    Sleep(100);

}

DWORD WINAPI teclas(LPVOID lpParam){
	while(true){
		if (GetAsyncKeyState(VK_F3)){
			TheseusON = !TheseusON;
			inicio();
			Sleep(200);
		}
	}
}

DWORD WINAPI data(LPVOID lpParam){
	while (true) {
		LocalBase = Theseus.Read<DWORD>(Client + LocalPlayer);/* CLIENT LOCAL BASE */
		[swap_lines]
		MyTeam = Theseus.Read<int>(LocalBase + m_iTeamNum); /* GET LOCAL TEAM */
		MaxObjects = Theseus.Read<int>(Client + EntityList + 0x4);
		[/swap_lines]
		Sleep(1);
	}
	return NULL;
}

void DesenharGlow(int GlowIndex, BrilhoBrilhante Cor){
    [swap_lines]
	Theseus.Write<bool>((GlowPointer + ((GlowIndex*0x38) + 0x24)), Cor.tapado);
	Theseus.Write<bool>((GlowPointer + ((GlowIndex*0x38) + 0x25)), Cor.destapado);
	Theseus.Write<float>((GlowPointer + ((GlowIndex*0x38) + 0x10)), Cor.express);
	Theseus.Write<float>((GlowPointer + ((GlowIndex*0x38) + 0x4)), Cor.vermelho);
	Theseus.Write<float>((GlowPointer + ((GlowIndex*0x38) + 0x8)), Cor.verde);
	Theseus.Write<float>((GlowPointer + ((GlowIndex* 0x38) + 0xC)), Cor.azul);
	[/swap_lines]
}

DWORD WINAPI parede(LPVOID lpParam){
	while(true){
		for (int contador = 0; contador < MaxObjects; contador++){

			GlowPointer = Theseus.Read<DWORD>(Client + m_dwGlowObject);	 /* POINTER TO LOCAL PLAYER GLOW VIEW */
			currentplayer = Theseus.Read<DWORD>(Client + EntityList + ((contador - 1) * 16)); /* READ ENTITY DATA FROM LOOP */ /*Porquê o 4?*/
			currentplayerdormant = Theseus.Read<bool>(currentplayer + isDormant); /* CHECK IF IS DORMANT */
			//HealthBasedESP = Theseus.Read<int>(currentplayer + m_iHealth); /* READ ENTITY HP */

			if(TheseusON){
				if(!currentplayerdormant){
					currentplayerglowindex = Theseus.Read<int>(currentplayer + m_iGlowIndex); /* READ ENTITY GLOW INDEX */
					currentplayerteam = Theseus.Read<int>(currentplayer + m_iTeamNum);
					if(currentplayerteam != MyTeam){
						DesenharGlow(currentplayerglowindex, TRosa);
					}
				}
			}
		}
		Sleep(1);
	}
	return NULL;
}
