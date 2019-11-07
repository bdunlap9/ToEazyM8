#include "stdafx.h"
#include "Input.h"

using namespace std;

/*VARIABLES*/
int shutDownTimer = 0;

boolean mousePressed() {
	if (GetKeyState(VK_LBUTTON) & 0x8000)
		return true;
	else
		return false;
}

boolean ctrlPressed() {
	if (GetKeyState(VK_LCONTROL) & 0x8000)
		return true;
	else
		return false;
}

boolean rbPressed() {
	if (GetKeyState(VK_RBUTTON) & 0x8000)
		return true;
	else
		return false;
}

void shutDown(boolean & run){
	if (GetKeyState(VK_F6) & 0x8000) {
		shutDownTimer++;
		Sleep(100);
		if (shutDownTimer == 30)
			run = false;
	}
	else
		shutDownTimer = 0;
}

void turnOnOffSAR(boolean &sarEnabled) 
{
	if (GetKeyState(VK_NUMPAD9) & 0x8000) {
		sarEnabled = !sarEnabled;
		if (sarEnabled)
			cout << "SAR ON" << endl;
		else
			cout << "SAR OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffm92(boolean & m92enabled) {
	if (GetKeyState(VK_SUBTRACT) & 0x8000) {
		m92enabled = !m92enabled;
		if (m92enabled)
			cout << "m92 ON" << endl;
		else
			cout << "m92 OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffP2(boolean & p2enabled) {
	if (GetKeyState(VK_ADD) & 0x8000) {
		p2enabled = !p2enabled;
		if (p2enabled)
			cout << "P2 ON" << endl;
		else
			cout << "P2 OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffm249(boolean & m249enabled) {
	if (GetKeyState(VK_NUMPAD7) & 0x8000) {
		m249enabled = !m249enabled;
		if (m249enabled)
			cout << "M249 ON" << endl;
		else
			cout << "M249 OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffm2494X(boolean & m2494Xenabled) {
	if (GetKeyState(VK_NUMPAD2) & 0x8000) {
		m2494Xenabled = !m2494Xenabled;
		if (m2494Xenabled)
			cout << "M249 + 4x Scope ON" << endl;
		else
			cout << "M249 + 4x Scope OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffak47(boolean & ak47enabled) {
	if (GetKeyState(VK_NUMPAD8) & 0x8000) {
		ak47enabled = !ak47enabled;
		if (ak47enabled)
			cout << "ak47 ON" << endl;
		else
			cout << "ak47 OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffpython(boolean & pythonEnabled) {
	if (GetKeyState(VK_NUMPAD5) & 0x8000) {
		pythonEnabled = !pythonEnabled;
		if (pythonEnabled)
			cout << "Python ON" << endl;
		else
			cout << "Python OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffCustomSMG(boolean & customSMGenabled) {
	if (GetKeyState(VK_NUMPAD6) & 0x8000) {
		customSMGenabled = !customSMGenabled;
		if (customSMGenabled)
			cout << "Custom SMG ON" << endl;
		else
			cout << "Custom SMG OFF" << endl;
		Sleep(350);
	}
}

void turnOnOffCrosshair(boolean & crosshair) {

	if (GetKeyState(VK_MULTIPLY) & 0x8000) {
		crosshair = !crosshair;
		if (crosshair) {
			cout << "Crosshair ON" << endl;
		}
		else
			cout << "Crosshair Off" << endl;
		Sleep(350);
	}
}

void turnOnOffRapidFire(boolean & rapidFireenabled) {
	if (GetKeyState(VK_NUMPAD4) & 0x8000) {
		rapidFireenabled = !rapidFireenabled;
		if (rapidFireenabled) {
			cout << "Rapid Fire ON" << endl;
		}
		else
			cout << "Rapid Fire OFF" << endl;
		Sleep(350);
	}
}

void turnOnOfflr300(boolean & lr300enabled) {
	if (GetKeyState(VK_NUMPAD1) & 0x8000) {
		lr300enabled = !lr300enabled;
		if (lr300enabled) {
			cout << "LR300 ON" << endl;
		}
		else
			cout << "LR300 OFF" << endl;
		Sleep(350);
	}
}