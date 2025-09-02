#include "utils.hpp"
#include "vector/vec2.hpp"
#include "vector/ivec2.hpp"


void check_pos(int w, int h, int & x, int & y, int security) {
  if(y < 0) y = h - security;
  if(x < 0) x = w - security;
  if(y >= h) y = 0 + security;
  if(x >= w) x = 0 + security;
}

void check_pos(ivec2 size, ivec2 & pos, int security) { 
  check_pos(size.x, size.y, pos.x, pos.y, security);
}



int rgb1(int r, int g, int b) {
  int c = r;
  c = (c << 8) | g;
  c = (c << 8) | b;
  return c;
}

int rgb2(int r, int g, int b) {
    return (r << 16) | (g << 8) | b;
}

unsigned int rgb3(unsigned int r, unsigned int g, unsigned int b) {
    return (r * 256*256) + (g * 256) + b;
}


ofColor get_color_image(int x, int y, ofImage & img) {
  vec2 ratio = get_ratio(ofGetWidth(), ofGetHeight(), img.getWidth(), img.getHeight(), 0);
  int get_x = int(x * ratio.x);
  int get_y = int(y * ratio.y);
  check_pos(img.getWidth(), img.getHeight(), get_x, get_y, 0);
  return img.getColor(get_x, get_y);
}  


vec2 get_ratio(int target_w, int target_h, int src_w, int src_h, int type) {
  float r_x = (float)src_w / (float)target_w;
  float r_y = (float)src_h / (float)target_h;
  return vec2(r_x, r_y);

}

vec2 get_ratio(ivec2 target, ivec2 src, int type) {
  return get_ratio(target.x, target.y, src.x, src.y, type);
}