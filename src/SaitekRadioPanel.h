/*
 * Copyright 2022 Norbert Takacs
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <vector>
#include "Device.h"
#include "UsbHidDevice.h"
#include "Configuration.h"

class SaitekRadioPanel : public UsbHidDevice
{
private:
	std::vector<PanelButton> radio_buttons;
	std::vector<PanelButton> radio_selectors;
	std::vector<PanelDisplay> radio_displays;
public:
	SaitekRadioPanel(DeviceConfiguration& config);
	int connect();
	void start();
	void stop(int timeout);
};
