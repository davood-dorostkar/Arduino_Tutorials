#include <Arduino.h>

// TFT screen definitions
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
MCUFRIEND_kbv TFT;
Adafruit_GFX_Button Button[4]; //  redButton, blueButton, greenButton, yellowButton;

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
uint16_t color[4] = {RED, BLUE, GREEN, YELLOW};

// Touch definitions
#define minPressure 200
#define maxPressure 1000
const int XP = 6, XM = A2, YP = A1, YM = 7;
const int touchLeftLimit = 107, touchRightLimit = 910, touchUpLimit = 954, touchButtomLimit = 100;
TouchScreen touch = TouchScreen(XP, YP, XM, YM, 300);
int touchX, touchY;

// Functions
bool touchSensed()
{
    TSPoint touchPoint = touch.getPoint();
    pinMode(YP, OUTPUT);
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);
    digitalWrite(XM, HIGH);
    bool pressed = (touchPoint.z > minPressure && touchPoint.z < maxPressure);
    if (pressed)
    {
        touchX = map(touchPoint.x, touchLeftLimit, touchRightLimit, 0, TFT.width());
        touchY = map(touchPoint.y, touchUpLimit, touchButtomLimit, 0, TFT.height());
    }
    return pressed;
}

void makeIcons()
{
    Button[0].initButton(&TFT, 60, 100, 100, 40, WHITE, MAGENTA, BLACK, "Red", 2);
    Button[1].initButton(&TFT, 180, 100, 100, 40, WHITE, MAGENTA, BLACK, "Blue", 2);
    Button[2].initButton(&TFT, 60, 200, 100, 40, WHITE, MAGENTA, BLACK, "Green", 2);
    Button[3].initButton(&TFT, 180, 200, 100, 40, WHITE, MAGENTA, BLACK, "Yellow", 2);
    Button[0].drawButton();
    Button[1].drawButton();
    Button[2].drawButton();
    Button[3].drawButton();
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

void setBackColor(int color)
{
    TFT.fillScreen(color);
    makeIcons();
}

void checkButtonPressed()
{
    for (int i = 0; i < 4; i++)
    {
        Button[i].press(touchSensed() && Button[i].contains(touchX, touchY));
        if (Button[i].justReleased())
        {
            Button[i].drawButton();
        }
        if (Button[i].justPressed())
        {
            Button[i].drawButton(true);
            setBackColor(color[i]);
        }
    }
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
checkButtonPressed();
}