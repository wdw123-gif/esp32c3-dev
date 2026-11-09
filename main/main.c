/*
 * ESP32-C3 起步示例：串口打印 + LED 闪烁
 *
 * 目标芯片: ESP32-C3
 * 开发框架: ESP-IDF v5.3.x
 *
 * 说明:
 *   大部分 ESP32-C3 开发板板载 LED 接在 GPIO8，低电平点亮。
 *   如果你的板子 LED 接在其他引脚，请修改 LED_GPIO。
 */

#include <stdio.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_chip_info.h"
#include "esp_log.h"
#include "esp_system.h"

#define LED_GPIO 8
#define BLINK_PERIOD_MS 1000

static const char *TAG = "esp32c3-dev";

static void log_chip_info(void)
{
    esp_chip_info_t chip;
    esp_chip_info(&chip);

    ESP_LOGI(TAG, "chip: %s, cores: %d, revision: v%d.%d",
             CONFIG_IDF_TARGET,
             chip.cores,
             chip.full_revision / 100,
             chip.full_revision % 100);
    ESP_LOGI(TAG, "free heap: %" PRIu32 " bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "reset reason: %d", (int)esp_reset_reason());
}

void app_main(void)
{
    ESP_LOGI(TAG, "Hello from ESP32-C3!");
    log_chip_info();

    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    bool on = false;
    while (true) {
        on = !on;
        gpio_set_level(LED_GPIO, on ? 0 : 1);   /* 低电平点亮 */
        ESP_LOGI(TAG, "LED %s", on ? "ON" : "OFF");
        vTaskDelay(pdMS_TO_TICKS(BLINK_PERIOD_MS));
    }
}
