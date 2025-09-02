
#pragma once

#include "ofMain.h"
#include "vector/vec2.hpp"
#include "vector/ivec2.hpp"

void pixels_spray(ivec2 size, ivec2 pos, int intensity, float radius, ofTexture & tex_rgb, ofPixels & pix_rgb, ofImage & img);
void pixel_voyageur(int width, int height, int & x, int & y, ofColor pix_color, ofTexture & tex_rgb, ofPixels & pix_rgb);
void pixels_tableau(int width, int height, int num, ofTexture & tex_rgb, ofPixels & pix_rgb, ofImage & img);

void random_color(int width, int height, ofTexture & tex_rgb, ofPixels & pix_rgb);

