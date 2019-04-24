#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

MCUFRIEND_kbv TFT;

Adafruit_GFX_Button redButton, blueButton, greenButton, yellowButton;

#define minPressure 200
#define maxPressure 1000
const int XP = 6, XM = A2, YP = A1, YM = 7;
const int touchLeftLimit = 107, touchhRightLimit = 910, touchUpLimit = 954, touchButtomLimit = 100;
TouchScreen touch = TouchScreen(XP, YP, XM, YM, 300);
int touchX, touchY;
bool touchSense(void)
{
    TSPoint touchPoint = touch.getPoint();
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);
    digitalWrite(XM, HIGH);
    bool pressed = (touchPoint.z > minPressure && touchPoint.z < maxPressure);
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

void setBackColor(int color)
{
    TFT.fillScreen(color);
    makeIcons();
}
void loop()
{
    redButton.press(touchSense() && redButton.contains(touchX, touchY));
    blueButton.press(touchSense() && blueButton.contains(touchX, touchY));
    greenButton.press(touchSense() && greenButton.contains(touchX, touchY));
    yellowButton.press(touchSense() && yellowButton.contains(touchX, touchY));

    if (redButton.justReleased())
    {
        redButton.drawButton();
    }
    if (redButton.justPressed())
    {
        redButton.drawButton(true);
        setBackColor(RED);
    }

    if (blueButton.justReleased())
    {
        blueButton.drawButton();
    }
    if (blueButton.justPressed())
    {
        blueButton.drawButton(true);
        setBackColor(BLUE);
    }

    if (greenButton.justReleased())
    {
        greenButton.drawButton();
    }
    if (greenButton.justPressed())
    {
        greenButton.drawButton(true);
        setBackColor(GREEN);
    }

    if (yellowButton.justReleased())
    {
        yellowButton.drawButton();
    }
    if (yellowButton.justPressed())
    {
        yellowButton.drawButton(true);
        setBackColor(YELLOW);
    }
}