/*
 * wifi_app.c
 *
 *  Created on: Feb 20, 2024
 *      Author: ejn
 */
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "esp_err.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "lwip/netdb.h"

#include "rgb_led.h"
#include "tasks_common.h"
#include "wifi_app.h"

// Tag used for ESP serial console messages.
static const char TAG [] = "wifi_app";

static QueueHandle_t wifi_app_queue_handle;

// BaseType_t wifi_app_send_message(wifi_app_message_enum msgId) {}

void wifi_app_start(void) {
	ESP_LOGI(TAG, "STARTING WIFI APPLICATION");
	rgb_led_wifi_app_started();
	esp_log_level_set("wifi", ESP_LOG_NONE);
	wifi_app_queue_handle = xQueueCreate(3, sizeof(wifi_app_queue_message_t));
}

