#ifndef _XLCD_SENSORS_CHAMBER_TEMP
#define _XLCD_SENSORS_CHAMBER_TEMP

#include <OneWire.h>
#include <DallasTemperature.h>

#define XTOUCH_CHAMBER_TEMP_PIN 22
#define XTOUCH_LED_BLUE_PIN 17
#define XTOUCH_LED_RED_PIN 4
#define XTOUCH_LED_GREEN_PIN 16
#define XTOUCH_CHAMBER_HEAT_PIN 27

// Setup a temperatureSensorsOneWire instance to communicate with any temperatureSensorsOneWire devices
OneWire temperatureSensorsOneWire(XTOUCH_CHAMBER_TEMP_PIN);

// Pass our temperatureSensorsOneWire reference to Dallas Temperature sensor
DallasTemperature xtouch_chamber_sensors(&temperatureSensorsOneWire);

lv_timer_t *xtouch_chambertemp_requestTemperaturesTimer;

void xtouch_chamber_requestTemperatures(lv_timer_t *timer);

void xtouch_chamber_timer_create()
{
    //xtouch_chambertemp_requestTemperaturesTimer = lv_timer_create(xtouch_chamber_requestTemperatures, 2500, NULL);
    xtouch_chambertemp_requestTemperaturesTimer = lv_timer_create(xtouch_chamber_requestTemperatures, 500, NULL);
    lv_timer_set_repeat_count(xtouch_chambertemp_requestTemperaturesTimer, 1);
}

void xtouch_chamber_requestTemperatures(lv_timer_t *timer)
{
    float temperatureC = xtouch_chamber_sensors.getTempCByIndex(0) + xTouchConfig.xTouchChamberSensorReadingDiff;
    float temperatureF = xtouch_chamber_sensors.getTempFByIndex(0) + xTouchConfig.xTouchChamberSensorReadingDiff;
    ConsoleInfo.println("Temeratures: " + String(temperatureC) + "C" + " " + String(temperatureF) + "F");
    bambuStatus.chamber_temper = temperatureC;
    if (temperatureF >= 75.5) {
      //Too hot, Heat off, Fan on, Blue
      digitalWrite(XTOUCH_LED_RED_PIN, HIGH); 
      digitalWrite(XTOUCH_LED_GREEN_PIN, HIGH);
      digitalWrite(XTOUCH_LED_BLUE_PIN, LOW);
      digitalWrite(XTOUCH_CHAMBER_HEAT_PIN, LOW);
      //Send mqtt to speed up fan
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TEMP, temperatureC);
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TARGET_TEMP, 0);
    } else if (temperatureF >= 74.5) {
      //Perfect, do nothing, Green
      digitalWrite(XTOUCH_LED_RED_PIN, HIGH); 
      digitalWrite(XTOUCH_LED_GREEN_PIN, LOW);
      digitalWrite(XTOUCH_LED_BLUE_PIN, HIGH);
      digitalWrite(XTOUCH_CHAMBER_HEAT_PIN, LOW);
      //Send mqtt to set fan back to original value
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TEMP, temperatureC);
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TARGET_TEMP, 0);
    } else {
      //Too cold, heat on, Red
      digitalWrite(XTOUCH_LED_RED_PIN, LOW); 
      digitalWrite(XTOUCH_LED_GREEN_PIN, HIGH);
      digitalWrite(XTOUCH_LED_BLUE_PIN, HIGH);
      digitalWrite(XTOUCH_CHAMBER_HEAT_PIN, HIGH);
      //Send mqtt to set fan back to original value
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TEMP, temperatureC);
      xtouch_mqtt_sendMsg(XTOUCH_ON_CHAMBER_TARGET_TEMP, temperatureC);
    }
    xtouch_chamber_sensors.requestTemperatures();
    xtouch_chamber_timer_create();
}

bool xtouch_chamber_started = false;
void xtouch_chamber_timer_start()
{
    if (!xtouch_chamber_started)
    {
        pinMode(XTOUCH_LED_RED_PIN, OUTPUT);
        pinMode(XTOUCH_LED_GREEN_PIN, OUTPUT);
        pinMode(XTOUCH_LED_BLUE_PIN, OUTPUT);
        pinMode(XTOUCH_CHAMBER_HEAT_PIN, OUTPUT);
        digitalWrite(XTOUCH_LED_RED_PIN, HIGH);
        digitalWrite(XTOUCH_LED_GREEN_PIN, HIGH);
        digitalWrite(XTOUCH_LED_BLUE_PIN, HIGH);
        digitalWrite(XTOUCH_CHAMBER_HEAT_PIN, LOW);
        xtouch_chamber_sensors.begin();
        xtouch_chamber_sensors.setWaitForConversion(false);
        xtouch_chamber_started = true;

        //bambuStatus.chamber_target_temper = 20;
        xtouch_mqtt_sendMsg(XTOUCH_COMMAND_CHAMBER_TARGET_TEMP, 20);
        //controlMode.target_chamber_temper = 20;
        //lv_msg_send(XTOUCH_COMMAND_CHAMBER_TARGET_TEMP, NULL);
    }
    xtouch_chamber_timer_create();
}

void xtouch_chamber_timer_stop()
{
    lv_timer_pause(xtouch_chambertemp_requestTemperaturesTimer);
}

void xtouch_chamber_timer_init()
{
    if (!xtouch_bblp_is_p1Series())
    {
        return;
    }

    if (xTouchConfig.xTouchChamberSensorEnabled)
    {
        xtouch_chamber_timer_start();
    }
    else
    {
        if (xtouch_chamber_started)
        {

            xtouch_chamber_timer_stop();
        }
    }
}

#endif
