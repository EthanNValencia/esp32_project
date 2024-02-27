/*
 * wifi_app.h
 *
 *  Created on: Feb 20, 2024
 *      Author: ejon
 */

#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H_

#include "esp_netif.h"
#include "freertos/FreeRTOS.h"

#define WIFI_AP_SSID "ESP32_AP"
#define WIFI_AP_PASSWORD "password"
#define WIFI_AP_CHANNEL 1
#define WIFI_AP_SSID_HIDDEN 0 // Access point visibility 0
#define WIFI_AP_MAX_CONNECTIONS 5
#define WIFI_AP_BEACON_INTERVAL 100 // Beacon interval 100-60000 (100 ms is recommended)
#define WIFI_AP_IP "192.168.0.1"
#define WIFI_AP_GATEWAY "192.168.0.1"
#define WIFI_AP_NETMASK "255.255.255.0"
#define WIFI_AP_BANDWIDTH WIFI_BW_HT20 // 20mhz but 40mhz is the other option (40 would be better for higher data transfer)
#define WIFI_STA_POWER_SAVE WIFI_PS_NONE
#define MAX_SSID_LENGTH 32
#define MAX_PASSWORD_LENGTH 64
#define MAX_CONNECTION_RETRIES 5

extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;

typedef enum wifi_app_message {
	WIFI_APP_MSG_START_HTTP_SERVER = 0,
	WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
	WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_app_message_enum;

/**
 * Structure for the message queue.
 * @note Expand this based on requirements.
 */
typedef struct wifi_app_queue_message {
	wifi_app_message_enum msgID;
} wifi_app_queue_message_t;

/**
 * Sends a message to the queue.
 * @param msgId message Id from the wifi_app_message_enum.
 * @return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE.
 * @note Expand the parameter list based on your requirements.
 */
BaseType_t wifi_app_send_message(wifi_app_message_enum msgId);

/**
 * Starts the WiFi RTOs task.
 */
void wifi_app_start(void);

#endif /* MAIN_WIFI_APP_H_ */
