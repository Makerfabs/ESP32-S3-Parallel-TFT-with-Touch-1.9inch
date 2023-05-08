# ESP32-S3-Parallel-TFT-with-Touch-1.9inch
```
/*  Version:      V1.1
    Author:       Ricardo
    Create Date:  2023/4/27
*/
```
# Makerfabs

[Makerfabs home page](https://www.makerfabs.com/)

[Makerfabs Wiki](https://wiki.makerfabs.com/)

## Intruduce

Product Link:[ESP32-S3 Parallel TFT with Touch 1.9"](https://www.makerfabs.com/matouch-esp32-s3-parallel-tft-with-touch-1-9-inch.html?search=Esp32%20s3%201.9)

Wiki Link : [ESP32-S3 Parallel 1.9 TFT with Touch](https://wiki.makerfabs.com/ESP32_S3_Parallel_1.9_TFT_with_Touch.html)

IoT applications have a certain demand for the 1.9" screen. The small screen brings higher cost performance and utilization rate. Its main control chip adopts ESP32-S3R8 Dual-core LX7 microcontroller, it features Wifi/ WiFi& Bluetooth 5.0 + BT mesh.

At the same time, it supports battery and USB power supply methods, which brings many possibilities to its application. At the same time, it has a TF card, which can store and transfer sensor data. Also there 2 expansion connectors, with UART/ADC. The colorful display resolution is 320*170, with capacitive touch, which could be a proper solution for IoT applications.

## Features

- Controller: ESP32-S3
- Wireless: WiFi& Bluetooth 5.0
- LCD: 1.9", 320x170 resolution, driver ST7789V2
- LCD interface: 8 bit 8080
- Touch Panel Driver: CST816D
- USB: USB Native, Type-C
- Power Supply: USB Type-C 5.0V(4.0V~5.25V); 3.7V Lipo battery
- Button: Flash button and reset button
- Expansion interface: 2 (UART/ADC)
- MicroSD
- Arduino support
- MicroPython support: Yes
- Operation temperature: -40℃ to +85℃

## Usage

related library versions

![library](https://github.com/Makerfabs/ESP32-S3-Parallel-TFT-with-Touch-1.9inch/blob/main/md_pic/MaTouch_ESP32-S3-Parallel-TFT-1.9-lib%20version.jpg)

- Use type-c use cable connect USB-TTL to PC.
- Select "ESP32-S3 DEV Module"
- Select PSRAM "OPI PSRAM"

"mf_Lvgl" library is modified from Lvgl library (version 8.3.2). 

Please unzip "lib/mf_Lvgl.zip"."TouchLib" and copy to arduino library directory.
