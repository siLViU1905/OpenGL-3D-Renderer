#include "Color.h"

Color::Color() : rgb()
{
}

Color::Color(float r, float g, float b, float alpha)
{
    rgb = {r, g, b};
    this->alpha = alpha;
}

Color::Color(vec3 rgb ,float alpha)
{
    this->rgb=rgb;
    this->alpha=alpha;
}

const Color Color::White = Color(1.f,1.f,1.f);
const Color Color::Black = Color(0.f,0.f,0.f);
const Color Color::Red = Color(1.f,0.f,0.f);
const Color Color::Green = Color(0.f,1.f,0.f);
const Color Color::Blue = Color(0.f,0.f,1.f);
