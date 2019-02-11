#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED


#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <windows.h>
#include <TlHelp32.h>
#include "Decrypt.h"

/*Estruturas*/
struct BrilhoBrilhante
{
	float vermelho;
	float verde;
	float azul;
	float express; /*Não actualiza*/
	bool tapado;
	bool destapado;
};

BrilhoBrilhante Tvermelho = {2.f, 0.f, 0.f, 1.f, true, false};
BrilhoBrilhante TVerde = {0.0f, 2.f, 0.f, 1.f, true, false};
BrilhoBrilhante TAmarelo = {1.f, 0.8f, 0.f, 1.f, true, false};
BrilhoBrilhante TLaranja = { 1.f, 0.5, 0.f, 1.f, true, false};
BrilhoBrilhante TAzul = { 1.f, 1.f, 1.0f, 0.5f, true, false };
BrilhoBrilhante TRosa = {1.0, 0.0, 0.55, 1.f, true, false};

/*Variaveis*/
DWORD LocalPlayer = 0x00A8D53C;
DWORD EntityList = 0x04AAECC4;
DWORD m_iGlowIndex = 0x0000A320;
DWORD m_dwGlowObject = 0x04FC60B4; //A minha estava mal
DWORD isDormant = 0x000000E9; //m_bDormant
DWORD m_iTeamNum = 0x000000F0;
DWORD m_iHealth = 0x000000FC;
//DWORD m_iCrossHairID = 0xAA44;
DWORD tEntity;
DWORD Client;
DWORD LocalBase;
DWORD GlowPointer;
DWORD currentplayer;
int MaxObjects;
//int crosshair;
int MyTeam;
int currentplayerteam;
int currentplayerglowindex;
//int LocalPlayerTeam;
int HealthBasedESP;
bool TheseusON;
bool currentplayerdormant;

/*Funcoes*/
void inicio();
void DesenharGlow();
void texto(int Color);
DWORD WINAPI teclas(LPVOID lpParam);
DWORD WINAPI parede(LPVOID lpParam);
DWORD WINAPI data(LPVOID lpParam);


#endif // TYPES_H_INCLUDED
