
#pragma once
#include <raylib.h>

class nPlate{

    public:
        float x, y, height, width;
        int speed;
        nPlate();
        void Draw();
        void Update();


};