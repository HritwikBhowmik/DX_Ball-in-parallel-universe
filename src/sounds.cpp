
#include "sounds.h"

Sounds::Sounds() {
    InitAudioDevice();
    brickCollideSound = LoadSound("sounds/brick_down.wav");
    plateCollideSound = LoadSound("sounds/plate_collide.wav");
}

Sounds::~Sounds() {
    UnloadSound(brickCollideSound);
    UnloadSound(plateCollideSound);
    CloseAudioDevice();
}