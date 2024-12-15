#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void drawSunrise(int x, int y) {

    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x, y, YELLOW);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(0, 0, BLUE);
    floodfill(320, 240, BLUE); 
}

void drawSunset(int x, int y) {
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(0, 0, DARKGRAY);
    floodfill(320, 240, DARKGRAY);  
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    for (int i = 240; i >= 100; i -= 2) {
        drawSunrise(320, i);
        delay(100);
    }

    delay(1000);
    for (int i = 100; i <= 240; i += 2) {
        drawSunset(320, i);
        delay(100);
    }


    getch();
    closegraph();
    return 0;
}