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
DWORD LocalPlayer = 0xCC96A4;
DWORD EntityList = 0x4CD9FEC;
DWORD m_iGlowIndex = 0xA3F8;
DWORD m_dwGlowObject = 0x5219F38; //A minha estava mal
DWORD isDormant = 0xED; //m_bDormant
DWORD m_iTeamNum = 0xF4;
DWORD m_iHealth = 0x100;
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
