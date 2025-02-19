/*
 * Copyright 2022 Norbert Takacs
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
#pragma once
#include <list>
#include <mutex>
#include "Device.h"
#include "Configuration.h"
#include "XPLMUtilities.h"
#include "XPLMProcessing.h"

typedef enum {
    SC_ROTATION,
    SC_TRANSLATION_X,
    SC_TRANSLATION_Y,
    SC_UNKNOWN
} ScreenActionType;

class ScreenAction {
public:
    ScreenAction()
    {
        type = SC_UNKNOWN;
        page_index = 0;
        layer_index = 0;
        scale_factor = 1;
        value_old = 0;
        data_ref = NULL;
        data_ref_type = xplmType_Unknown;
        lua_str = "";
        constant_val = 0;
    }

    ScreenAction(const ScreenAction& other)
    {
        type = other.type;
        page_index = other.page_index;
        layer_index = other.layer_index;
        value_old = other.value_old;
        scale_factor = other.scale_factor;
        data_ref = other.data_ref;
        data_ref_type = other.data_ref_type;
        lua_str = other.lua_str;
        constant_val = other.constant_val;
    }

    ScreenActionType type;
    XPLMDataRef data_ref;
    XPLMDataTypeID data_ref_type;
    std::string lua_str;
    int constant_val;
    int page_index;
    int layer_index;

    int value_old;

    double scale_factor;
};

class GenericScreen
{
protected:
    std::list<ScreenAction*> screen_action_queue;
    int read_data_ref_int(XPLMDataRef data_ref, XPLMDataTypeID data_ref_type);
public:
    GenericScreen();
    ~GenericScreen();
    virtual void evaluate_and_store_screen_action()=0;
    virtual void render_page(int page_index, void** byte_buffer) = 0;
    void add_screen_action(ScreenAction* screen_action);
};

