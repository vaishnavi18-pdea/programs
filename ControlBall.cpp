#include<iostream>
#include<graphics.h>
#include<conio.h>  

using namespace std;

class Shape {
public:
    virtual void draw() = 0;  
    virtual void move(int dx, int dy) = 0;  
};

class Ball : public Shape {
private:
    int x, y;  
    int radius;

public:
    Ball(int startX, int startY, int r) : x(startX), y(startY), radius(r) {}
    void draw() override {
        setcolor(WHITE);  
        setfillstyle(SOLID_FILL, WHITE);  
        fillellipse(x, y, radius, radius);  
    }
    void move(int dx, int dy) override {
        x += dx;  
        y += dy;  
    }

    int getX() { return x; }
    int getY() { return y; }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    Ball ball(200, 200, 20);  
    while(true) {
        
        cleardevice();
        ball.draw();
        if(kbhit()) {

            char key = getch();
            if(key == 0) {
                key = getch();  

                switch(key) {
                    case 72:  
                        ball.move(0, -10);  
                        break;
                    case 80:  
                        ball.move(0, 10);  
                        break;
                    case 75:  
                        ball.move(-10, 0);  
                        break;
                    case 77:  
                        ball.move(10, 0);  
                        break;
                }
            }

            if(key == 27) {
                break;
            }
        }
        delay(50);
    }

    closegraph();
    return 0;
}
