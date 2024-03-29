#ifndef _UI_COMP_HOMECOMPONENT_H
#define _UI_COMP_HOMECOMPONENT_H

#include "../ui.h"

#ifdef __cplusplus

extern "C"
{
#endif

#include "../ui_msgs.h"

// COMPONENT homeComponent
#define UI_COMP_HOMECOMPONENT_HOMECOMPONENT 0
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT 1
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR 2
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENWIFIICON 3
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENCAMERAICON 4
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENAMS 5
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENAMS_MAINSCREENAMSCOLOR0 6
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENAMS_MAINSCREENAMSCOLOR1 7
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENAMS_MAINSCREENAMSCOLOR2 8
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENSTATUSBAR_MAINSCREENAMS_MAINSCREENAMSCOLOR3 9
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENIDLE 10
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER 11
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER 12
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER_MAINSCREENNOZZLEICON 13
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER_MAINSCREENPLAYPAUSEBUTTON 14
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER_MAINSCREENSTOPBUTTON 15
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENPROGRESSBAR 16
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER1 17
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER1_MAINSCREENTIMELEFTICON 18
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER1_MAINSCREENTIMELEFT 19
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER2 20
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER2_MAINSCREENLAYERICON 21
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENPLAYER_MAINSCREENCONTROLLER2_MAINSCREENLAYER 22
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENCENTRAL 23
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENCENTRAL_MAINSCREENSPEEDICON 24
#define UI_COMP_HOMECOMPONENT_MAINSCREENLEFT_MAINSCREENCENTRAL_MAINSCREENSPEEDDROPDOWN 25
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT 26
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENLIGHTBUTTON 27
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENLIGHTBUTTON_MAINSCREENLIGHTBUTTONICON 28
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS 29
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENNOZZLETEMP 30
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENNOZZLETEMP_MAINSCREENNOZZLETEMPICON 31
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENNOZZLETEMP_MAINSCREENNOZZLETEMPVALUE 32
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENBEDTEMP 33
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENBEDTEMP_MAINSCREENBEDTEMPICON 34
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENBEDTEMP_MAINSCREENBEDTEMPVALUE 35
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENCHAMBERTEMP 36
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENCHAMBERTEMP_MAINSCREENCHAMBERTEMPICON 37
#define UI_COMP_HOMECOMPONENT_MAINSCREENRIGHT_MAINSCREENTEMPS_MAINSCREENCHAMBERTEMP_MAINSCREENCHAMBERTEMPVALUE 38
#define _UI_COMP_HOMECOMPONENT_NUM 39
    lv_obj_t *ui_homeComponent_create(lv_obj_t *comp_parent);
    void ui_event_comp_homeComponent_mainScreenPlayPauseButton(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenStopButton(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenSpeedDropDown(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenLightButton(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenBedTemp(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenNozzleTemp(lv_event_t *e);
    void ui_event_comp_homeComponent_mainScreenChamberTemp(lv_event_t *e);

    void onXTouchLightMessage(lv_event_t *e);
    void onXTouchBedTemp(lv_event_t *e);
    void onXTouchBedTempTarget(lv_event_t *e);
    void onXTouchChamberTemp(lv_event_t *e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
