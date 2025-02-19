/*
 * Copyright 2022 Norbert Takacs
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#pragma once
#include <string>
#include <map>
#include <atomic>
#include <mutex>
#include <limits>
#include <cstddef>
#include "XPLMDataAccess.h"
#include "XPLMMenus.h"

class GenericDisplay
{
public:
	GenericDisplay();
	GenericDisplay(bool _use_bcd); // bcd: binary encoded decimal

	void set_nr_bytes(int _nr_of_bytes);

	// called from UsbHidDevice worker thread
	virtual bool get_display_value(unsigned char* buffer);

	// called from XPLane flight loop
	virtual void evaluate_and_store_dataref_value();
	void add_dataref(XPLMDataRef _data_ref);
	void add_const(double _const_value);
	void add_lua(std::string _lua_function);

protected:	
	double	display_value;
	double	display_value_old;
	bool display_value_changed;
	std::mutex guard;
	bool use_bcd;
	std::string lua_function;
	XPLMDataRef condition;
	XPLMDataTypeID data_ref_type;
	double	const_value;
	int nr_of_bytes;
private:
	bool get_decimal_components(int number, unsigned char* buffer);
	bool get_binary_components(int number, unsigned char* buffer);
};
