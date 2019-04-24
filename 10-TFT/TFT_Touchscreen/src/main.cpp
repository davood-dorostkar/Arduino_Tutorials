#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
//==========================================================================================
MCUFRIEND_kbv TFT;

Adafruit_GFX_Button redButton, blueButton, greenButton, yellowButton;

#define MINPRESSURE 200
#define MAXPRESSURE 1000
const int XP = 6, XM = A2, YP = A1, YM = 7;
const int touchLeftLimit = 107, touchhRightLimit = 910, touchUpLimit = 954, touchButtomLimit = 100;
TouchScreen touch = TouchScreen(XP, YP, XM, YM, 300);
int touchX, touchY;
bool Touch_getXY(void)
{
    TSPoint touchPoint = touch.getPoint();
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);
    digitalWrite(XM, HIGH);
    bool pressed = (touchPoint.z > MINPRESSURE && touchPoint.z < MAXPRESSURE);
    if (pressed)
    {
        touchX = map(touchPoint.x, touchLeftLimit, touchhRightLimit, 0, TFT.width());
        touchY = map(touchPoint.y, touchUpLimit, touchButtomLimit, 0, TFT.height());
    }
    return pressed;
}

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

void makeIcons()
{
    redButton.initButton(&TFT, 60, 100, 100, 40, WHITE, MAGENTA, BLACK, "Red", 2);
    blueButton.initButton(&TFT, 180, 100, 100, 40, WHITE, MAGENTA, BLACK, "Blue", 2);
    greenButton.initButton(&TFT, 60, 200, 100, 40, WHITE, MAGENTA, BLACK, "Green", 2);
    yellowButton.initButton(&TFT, 180, 200, 100, 40, WHITE, MAGENTA, BLACK, "Yellow", 2);
    redButton.drawButton(false);
    blueButton.drawButton(false);
    greenButton.drawButton(false);
    yellowButton.drawButton(false);
}
void initStartPage()
{
    uint16_t TFTID = TFT.readID();
    TFT.begin(TFTID);
    TFT.fillScreen(BLACK);
    TFT.setRotation(0);
    TFT.setCursor(15, 140);
    TFT.setTextColor(RED);
    TFT.setTextSize(2);
    TFT.setTextWrap(false);
    TFT.print("www.sanatbazar.com");
}
void setup()
{
    initStartPage();
    delay(2000);
    TFT.fillScreen(BLACK);
    makeIcons();
}

void loop()
{
}
// void setup(void)
// {

//     uint16_t ID = TFT.readID();

//     TFT.begin(ID);
//     TFT.setRotation(0);
//     TFT.fillScreen(BLACK);
//     on_btn.initButton(&TFT, 60, 200, 100, 40, WHITE, CYAN, BLACK, "ON", 2);
//     off_btn.initButton(&TFT, 180, 200, 100, 40, WHITE, CYAN, BLACK, "OFF", 2);
//     on_btn.drawButton(false);
//     off_btn.drawButton(false);
//     TFT.fillRect(40, 80, 160, 80, RED);
// }

// /* two buttons are quite simple
//  */
// void loop(void)
// {
//     bool down = Touch_getXY();
//     on_btn.press(down && on_btn.contains touchX, touchY));
//     off_btn.press(down && off_btn.contains touchX, touchY));
//     if (on_btn.justReleased())
//         on_btn.drawButton();
//     if (off_btn.justReleased())
//         off_btn.drawButton();
//     if (on_btn.justPressed())
//     {

//         on_btn.drawButton(true);

//         TFT.fillRect(40, 80, 160, 80, GREEN);
//     }
//     if (off_btn.justPressed())
//     {
//         off_btn.drawButton(true);
//         TFT.fillRect(40, 80, 160, 80, RED);
//     }
// }