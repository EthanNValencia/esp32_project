/*
 * rgb_led.h
 *
 *  Created on: Feb 19, 2024
 *      Author: ejoen
 */

#ifndef MAIN_RGB_LED_H_
#define MAIN_RGB_LED_H_

// Define LED GPIOs
#define RGB_LED_RED_GPIO 21
#define RGB_LED_GREEN_GPIO 22
#define RGB_LED_BLUE_GPIO 23

#define RGB_LED_CHANNEL_NUM 3

typedef struct {
	int channel;
	int gpio;
	int mode;
	int timer_index;
} led_info_t;


/**
 * Color to indicate that the WiFi application has started.
 */

void rgb_led_wifi_app_started(void);

/***
 * Color to indicate that the http server has started.
 */
void rgb_led_http_server_started(void);

/***
 * Color to indicate that the ESP32 is connected to an access point.
 */
void rgb_led_wifi_connected(void);

#endif /* MAIN_RGB_LED_H_ */
