
#include "ofApp.hpp"
#include "utils.hpp"
#include "painting.hpp"
#include "vector/vec2.hpp"
#include "vector/ivec2.hpp"





void pixel_voyageur(int width, int height, int & x, int & y, ofColor pix_color, ofTexture & tex_rgb, ofPixels & pix_rgb) {
  for(int i = 0 ; i < 30 ; i++) {
    check_pos(width, height, x, y , 0);
    pix_rgb.setColor(x, y, pix_color);
    // coord x
    float dir_x = ofRandom(1);
    if(dir_x < 0.5) dir_x = -1; else dir_x = 1;
    x += (int)dir_x;
    // coord y
    float dir_y = ofRandom(1);
    if(dir_y < 0.5) dir_y = -1; else dir_y = 1;
    y += (int)dir_y;
  }
  tex_rgb.loadData(pix_rgb.getData(), width, height, GL_RGB);
  check_pos(width, height, x, y, 0);
}


void pixels_tableau(int width, int height, int num, ofTexture & tex_rgb, ofPixels & pix_rgb, ofImage & img) {
  for(int i = 0 ; i < num ; i++) {
    int x = int(ofRandom(width));
    int y = int(ofRandom(height));
    check_pos(width, height, x, y, 0);
    ofColor c = get_color_image(x, y, img);
    pix_rgb.setColor(x, y, c);
  }
  tex_rgb.loadData(pix_rgb.getData(), width, height, GL_RGB);
}




void pixels_spray(ivec2 size, ivec2 pos, int intensity, float radius, ofTexture & tex_rgb, ofPixels & pix_rgb, ofImage & img) {
  for(int i = 0 ; i < intensity ; i++) {
    float dir = ofRandom(2 * PI);
    float dir_x = sin(dir);
    float dir_y = cos(dir);
    float dist = ofRandom(radius);
    int pos_x = int(dir_x * dist + pos.x);
    int pos_y = int(dir_y * dist + pos.y);
    check_pos(size.x, size.y, pos_x, pos_y, 0);
    ofColor c = get_color_image(pos_x, pos_y, img);
    pix_rgb.setColor(pos_x, pos_y, c);
  }
  tex_rgb.loadData(pix_rgb.getData(), size.x, size.y, GL_RGB);
}


void random_color(int width, int height, ofTexture & tex_rgb, ofPixels & pix_rgb) {
  for(int i = 0 ; i < 10 ; i++)  {
    int x = ofRandom(width);
    int y = ofRandom(height);
    int c = ofRandom(256*256*256);
    pix_rgb.setColor(x,y,c);
    tex_rgb.loadData(pix_rgb.getData(), width, height, GL_RGB);
  }
}

