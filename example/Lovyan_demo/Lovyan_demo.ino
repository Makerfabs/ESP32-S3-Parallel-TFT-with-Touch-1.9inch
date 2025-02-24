/*
ESP32-S3 Parallel 1.9" TFT with Touch

Library version:
Arduino IDE V2.3.4
esp32 V2.0.16
LovyanGFX V0.4.18

Tools:
Flash size: 16MB(128Mb)
Partition Schrme: 16M Flash(3MB APP/9.9MB FATFS)
PSRAM: OPI PSRAM
*/

#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device
{
lgfx::Panel_ST7789      _panel_instance;
lgfx::Bus_Parallel8 _bus_instance;   // 8ビットパラレルバスのインスタンス (ESP32のみ)
lgfx::Light_PWM     _light_instance;

public:

  LGFX(void)
  {
    { // バス制御の設定を行います。
      auto cfg = _bus_instance.config();    // バス設定用の構造体を取得します。

// 8ビットパラレルバスの設定
      //cfg.i2s_port = I2S_NUM_1;     // 使用するI2Sポートを選択 (I2S_NUM_0 or I2S_NUM_1) (ESP32のI2S LCDモードを使用します)
      cfg.freq_write = 20000000;    // 送信クロック (最大20MHz, 80MHzを整数で割った値に丸められます)
      cfg.pin_wr =  38;              // WR を接続しているピン番号
      cfg.pin_rd =  39;              // RD を接続しているピン番号
      cfg.pin_rs = 47;              // RS(D/C)を接続しているピン番号
      cfg.pin_d0 = 9;              // D0を接続しているピン番号
      cfg.pin_d1 = 10;              // D1を接続しているピン番号
      cfg.pin_d2 = 11;              // D2を接続しているピン番号
      cfg.pin_d3 = 12;              // D3を接続しているピン番号
      cfg.pin_d4 = 13;              // D4を接続しているピン番号
      cfg.pin_d5 = 14;              // D5を接続しているピン番号
      cfg.pin_d6 = 15;              // D6を接続しているピン番号
      cfg.pin_d7 = 16;              // D7を接続しているピン番号
//

      _bus_instance.config(cfg);    // 設定値をバスに反映します。
      _panel_instance.setBus(&_bus_instance);      // バスをパネルにセットします。
    }

    { // 表示パネル制御の設定を行います。
      auto cfg = _panel_instance.config();    // 表示パネル設定用の構造体を取得します。

      cfg.pin_cs           =    46;  // CSが接続されているピン番号   (-1 = disable)
      cfg.pin_rst          =    1;  // RSTが接続されているピン番号  (-1 = disable)
      cfg.pin_busy         =    -1;  // BUSYが接続されているピン番号 (-1 = disable)

      // ※ 以下の設定値はパネル毎に一般的な初期値が設定されていますので、不明な項目はコメントアウトして試してみてください。

      cfg.panel_width      =   170;  // 実際に表示可能な幅
      cfg.panel_height     =   320;  // 実際に表示可能な高さ
      cfg.offset_x         =    35;  // パネルのX方向オフセット量
      cfg.offset_y         =     0;  // パネルのY方向オフセット量
      cfg.offset_rotation  =     0;  // 回転方向の値のオフセット 0~7 (4~7は上下反転)
      cfg.dummy_read_pixel =     8;  // ピクセル読出し前のダミーリードのビット数
      cfg.dummy_read_bits  =     1;  // ピクセル以外のデータ読出し前のダミーリードのビット数
      cfg.readable         =  true;  // データ読出しが可能な場合 trueに設定
      cfg.invert           = true;  // パネルの明暗が反転してしまう場合 trueに設定
      cfg.rgb_order        = false;  // パネルの赤と青が入れ替わってしまう場合 trueに設定
      cfg.dlen_16bit       = false;  // 16bitパラレルやSPIでデータ長を16bit単位で送信するパネルの場合 trueに設定
      cfg.bus_shared       =  false;  // SDカードとバスを共有している場合 trueに設定(drawJpgFile等でバス制御を行います)

      _panel_instance.config(cfg);
    }

//*
    { // バックライト制御の設定を行います。（必要なければ削除）
      auto cfg = _light_instance.config();    // バックライト設定用の構造体を取得します。

      cfg.pin_bl = 45;              // バックライトが接続されているピン番号
      cfg.invert = false;           // バックライトの輝度を反転させる場合 true
      cfg.freq   = 44100;           // バックライトのPWM周波数
      cfg.pwm_channel = 7;          // 使用するPWMのチャンネル番号

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);  // バックライトをパネルにセットします。
    }
    setPanel(&_panel_instance); // 使用するパネルをセットします。
  }
};

// 準備したクラスのインスタンスを作成します。
LGFX display;

void setup(void)
{
  // SPIバスとパネルの初期化を実行すると使用可能になります。
  display.init();
  display.fillScreen(TFT_RED);
  delay(1000);
  display.fillScreen(TFT_GREEN);
  delay(1000);
  display.fillScreen(TFT_BLUE);
  delay(1000);
  display.fillScreen(TFT_BLACK);
  delay(1000);
  display.fillScreen(TFT_WHITE);
}


void loop(void)
{
}
