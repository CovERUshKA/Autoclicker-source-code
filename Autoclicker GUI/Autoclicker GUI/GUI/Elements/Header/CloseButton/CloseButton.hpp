#pragma once

#include <Windows.h>
#include "../../../Draw/Draw.hpp"
#include "../../../CoGUI.hpp"
#include "../../../IO/IO.hpp"
#include "../../../Def.hpp"

class CloseButton : public Element
{
public:
	CloseButton();

	bool pressed;

	// Overrides Init function to not do anything
	void Init(COGUI_ElementCreateStruct createStruct) override { return; };

	BOOL Render();
	BOOL ApplyMessage(LPVOID lpCOGUIWndProc);
};