#include "stdafx.h"
#include "Input.h"
#include "Weapon.h"
#include "ToEazyM8.h"
#include <time.h>
#include <windows.h>
#include <iostream>

// D3D
#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")
LPDIRECT3D9 d3d;
LPDIRECT3DDEVICE9 d3ddev;
typedef interface ID3DXLine ID3DXLine;
typedef interface ID3DXLine *LPD3DXLINE;

using namespace std;

/*VARIABLES*/
boolean run = true;
boolean sarEnabled = false;
boolean m92enabled = false;
boolean p2enabled = false;
boolean m249enabled = false;
boolean m2494Xenabled = false;
boolean ak47enabled = false;
boolean pythonEnabled = false;
boolean customSMGenabled = false;
boolean crosshair = false;
boolean rapidFireenabled = false;
boolean lr300enabled = false;

int bulletNr = 0;
int divider = 10;
int restX = 0;
int restY = 0;

/*WEAPON SETTINGS                                     10             15                  20                     */
int ak47crouchedOffsetY[30] = { 58 ,56, 50,46 ,40,26,24,34,16,12,14,16,36,34,42 ,46 ,36 ,40 ,30 ,20 ,16 ,8  ,8  ,12,26,0,0,0,0,0 };
int ak47crouchedOffsetX[30] = { -41,5 ,-60,-52,0 ,20,28,46,58,48,52,30,28,-8,-20,-30,-52,-54,-60,-56,-52,-44,-42,18,0 ,0,0,0,0,0 };
Weapon ak47crouched = Weapon(120, 30, ak47crouchedOffsetY, ak47crouchedOffsetX);

int ak47standingOffsetY[30] = 
{ 68 ,56, 50,46 ,40,26,24,34,16,12,14,16,36,34,42 ,46 ,36 ,40 ,30 ,20 ,16 ,8  ,8  ,12,26,8,8,8,8,8 };
int ak47standingOffsetX[30] = { -41,6 ,-60,-52,0 ,20,28,46,58,48,52,30,28,-8,-20,-30,-52,-54,-60,-56,-52,-44,-42,18,5 ,5,5,5,5,5 };
Weapon ak47standing = Weapon(120, 30, ak47standingOffsetY, ak47standingOffsetX);

int semiCrouchedOffsetY[16] = { 60,60,60,60,60,60,60,60,61,61,61,61,61,60,60,60 };
int semiCrouchedOffsetX[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon semiCrouched = Weapon(200, 1, semiCrouchedOffsetY, semiCrouchedOffsetX);

int semiStandingOffsetY[16] = { 136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136 };
int semiStandingOffsetX[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon semiStanding = Weapon(200, 1, semiStandingOffsetY, semiStandingOffsetX);

int m92crouchedOffsetY[15] = { 53,53,53,53,53,53,53,53,53,53,53,53,53,53,53 };
int m92crouchedOffsetX[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m92crouched = Weapon(200, 1, m92crouchedOffsetY, m92crouchedOffsetX);

int m92standingOffsetY[15] = { 127,127,127,127,127,127,127,127,127,127,127,127,127,127,127 };
int m92standingOffsetX[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m92standing = Weapon(200, 1, m92standingOffsetY, m92standingOffsetX);

int p2crouchedOffsetY[10] = { 76,76,76,76,76,76,76,76,76,76 };
int p2crouchedOffsetX[10] = { 0,0,0,1,2,3,0,0,0,0 };
Weapon p2crouched = Weapon(200, 1, p2crouchedOffsetY, p2crouchedOffsetX);

int p2standingOffsetY[10] = { 145,145,145,145,145,145,145,145,145,145 };
int p2standingOffsetX[10] = { 0,1,0,1,2,3,1,2,1,0 };
Weapon p2standing = Weapon(200, 1, p2standingOffsetY, p2standingOffsetX);

int pythonCrouchedOffsetY[6] = { 129,129,129,129,129,129 };
int pythonCrouchedOffsetX[6] = { 0,0,0,0,0,0 };
Weapon pythonCrouched = Weapon(200, 1, pythonCrouchedOffsetY, pythonCrouchedOffsetX);

int pythonStandingOffsetY[6] = { 240,240,240,240,240,240 };
int pythonStandingOffsetX[6] = { 1,-2,2,-2,2,2 };
Weapon pythonStanding = Weapon(200, 1, pythonStandingOffsetY, pythonStandingOffsetX);

/*                                                  10                            20                            30                            40                            50                            60                         70                            80                            90                           100*/
int m249crouchedOffsetY[100] = { 66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66 };
int m249crouchedOffsetX[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m249crouched = Weapon(200, 1, m249crouchedOffsetY, m249crouchedOffsetX);

int m249standingOffsetY[100] = { 150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150 };
int m249standingOffsetX[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m249standing = Weapon(200, 1, m249standingOffsetY, m249standingOffsetX);

int m2494XcrouchedOffsetY[100] = { 258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258,258 };
int m2494XcrouchedOffsetX[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m2494Xcrouched = Weapon(200, 1, m2494XcrouchedOffsetY, m2494XcrouchedOffsetX);

int m2494XstandingOffsetY[100] = { 535,535,535,535,535,535,535,535,535,535,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525,525 };
int m2494XstandingOffsetX[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon m2494Xstanding = Weapon(200, 1, m2494XstandingOffsetY, m2494XstandingOffsetX);

int customSMGcrouchedOffsetY[24] = { 57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57 };
int customSMGcrouchedOffsetX[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon customSMGcrouched = Weapon(200, 1, customSMGcrouchedOffsetY, customSMGcrouchedOffsetX);

int customSMGStandingOffsetY[24] = { 57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57,57 };
int customSMGStandingOffsetX[24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon customSMGStanding = Weapon(200, 1, customSMGStandingOffsetY, customSMGStandingOffsetX);

int lr300crouchedOffsetY[30] = { 63,63,63,63,63,63,63,63,45,45,45,45,45,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15 };
int lr300crouchedOffsetX[30] = { 0,0,-15,-10,-3,-2,-10,-10,-10,-10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon lr300crouched = Weapon(200, 1, lr300crouchedOffsetY, lr300crouchedOffsetX);

int lr300standingOffsetY[30] = { 45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45 };
int lr300standingOffsetX[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
Weapon lr300standing = Weapon(200, 1, lr300standingOffsetY, lr300standingOffsetX);

// Some code I found online
void macro(Weapon weapon) {
	Sleep(weapon.sleepTime);
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = weapon.offsetX[bulletNr];
	input.mi.dy = weapon.offsetY[bulletNr];
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
	bulletNr++;
}

// Some code I found online
void recoil_ControlSystem(Weapon weapon) {
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;

	for (int i = 1; i <= divider; i++) {
		Sleep(weapon.sleepTime / divider);
		input.mi.dx = weapon.offsetX[bulletNr] / divider;
		input.mi.dy = weapon.offsetY[bulletNr] / divider;

		restX += weapon.offsetX[bulletNr] % divider;
		restY += weapon.offsetY[bulletNr] % divider;
		if (restX >= 10) {
			restX -= 10;
			input.mi.dx++;
		}
		if (restY >= 10) {
			restY -= 10;
			input.mi.dy++;
		}

		SendInput(1, &input, sizeof(input));
	}
	bulletNr++;
	if (bulletNr > weapon.capacity)
		bulletNr = 0;
}

int main()
{

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int col = 10;

	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, col);

	cout << "	  _______  _______  _        _______" << endl;
	cout << "|\       |(  ____ \ (  ____ \ | \ /\(  ____ \"" << endl;
	cout << "| )   ( || (    \/ |  (   \/ |  \  / /| (    \/" << endl;
	cout << "| | _ | || (__    | (__    |  (_/ / | (__    " << endl;
	cout << "| |( )| ||  __)   |  __)   |   _ (  |  __)   " << endl;
	cout << "| || || || (      | (      |  ( \ \ | (      " << endl;
	cout << "| () () || (____/\ | (____/\ |  /  \ \| (____/\"" << endl;
	cout << "(_______)(_______/(_______/|_/    \/(_______/" << endl;

	cout << "" << endl;

	cout << "VK_F6 = Shutdown" << endl;
	cout << "VK_NUMPAD9 = SAR" << endl;
	cout << "VK_SUBTRACT = m92" << endl;
	cout << "VK_ADD = P2" << endl;
	cout << "VK_NUMPAD7 = M249" << endl;
	cout << "VK_NUMPAD2 = M249 + 4x Scope" << endl;
	cout << "VK_NUMPAD8 = AK47" << endl;
	cout << "VK_NUMPAD5 = Python" << endl;
	cout << "VK_NUMPAD6 = Custom SMG" << endl;
	cout << "VK_NUMPAD1 = LR300" << endl;
	cout << "VK_MULTIPLY = Crosshair ( buggy )" << endl;
	cout << "" << endl;

	SetConsoleTextAttribute(hConsole, 10);

	while (run) {

		if (rapidFireenabled) {
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 10, 0, 0);
				Sleep(60);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(20);
			}
		}
		else if (m92enabled) {

			if (m92enabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = m92crouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (m92enabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = m92standing;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (p2enabled) {

			if (p2enabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = p2crouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (p2enabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = p2standing;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (m249enabled) {

			if (m249enabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = m249crouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (m249enabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = m249standing;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (m2494Xenabled) {

			if (m2494Xenabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = m2494Xcrouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (m2494Xenabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = m2494Xstanding;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (ak47enabled) {

			if (ak47enabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = ak47crouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (ak47enabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = ak47standing;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (sarEnabled) {

			if (sarEnabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = semiCrouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (sarEnabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = semiStanding;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (pythonEnabled) {

			if (pythonEnabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = pythonCrouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (pythonEnabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = pythonStanding;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (customSMGenabled) {

			if (customSMGenabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = customSMGcrouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (customSMGenabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = customSMGStanding;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		else if (lr300enabled) {

			if (lr300enabled && rbPressed() && mousePressed() && ctrlPressed()) {
				Weapon actualWeapon = lr300crouched;

				recoil_ControlSystem(actualWeapon);
			}
			else if (lr300enabled && rbPressed() && mousePressed()) {
				Weapon actualWeapon = lr300standing;

				recoil_ControlSystem(actualWeapon);
			}
			else {
				bulletNr = 0;
				restX = 0;
				restY = 0;
			}
		}
		turnOnOffm92(m92enabled);
		turnOnOffP2(p2enabled);
		turnOnOffpython(pythonEnabled);
		turnOnOffm249(m249enabled);
		turnOnOffm2494X(m2494Xenabled);
		turnOnOffak47(ak47enabled);
		turnOnOffSAR(sarEnabled);
		turnOnOffCustomSMG(customSMGenabled);
		turnOnOffRapidFire(rapidFireenabled);
		turnOnOffCrosshair(crosshair);
		turnOnOfflr300(lr300enabled);
	}
    return 0;
}
