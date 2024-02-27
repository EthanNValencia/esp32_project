#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "rgb_led.h"

#include "nvs_flash.h"
#include "wifi_app.h"
#include "dht.c"

// static void rgb_test();

void app_main(void) {
	// rgb_test();
	/*
	esp_err_t ret = nvs_flash_init();
	if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);
	wifi_app_start();
	 */
	run_dht();
}
/*
static void rgb_test() {
    while (true) {
        printf("Hello from app_main!\n");
        rgb_led_wifi_app_started();
        sleep(1);
        rgb_led_http_server_started();
        sleep(1);
        rgb_led_wifi_connected();
        sleep(1);
    }
}
*/
