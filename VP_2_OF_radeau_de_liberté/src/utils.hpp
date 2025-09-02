#pragma once

#include "ofMain.h"
#include "vector/vec2.hpp"
#include "vector/ivec2.hpp"

int rgb1(int r, int g, int b);
int rgb2(int r, int g, int b);
unsigned int rgb3(unsigned int r, unsigned int g, unsigned int b);
ofColor get_color_image(int x, int y, ofImage & img);

vec2 get_ratio(int target_w, int target_h, int src_w, int src_h, int type); 
vec2 get_ratio(ivec2 target, ivec2 src, int type); 


void check_pos(int w, int h, int & x, int & y, int security);
void check_pos(ivec2 size, ivec2 & pos, int security);
