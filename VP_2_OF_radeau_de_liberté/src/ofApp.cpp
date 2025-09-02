
#include "ofApp.hpp"
#include "utils.hpp"
#include "painting.hpp"
#include "vector/vec2.hpp"
#include "vector/ivec2.hpp"

ofImage radeau;
ofImage liberte;

ofColor pix_color = 0;
int pos_x = 0;
int pos_y = 0;
bool switch_img = false;
bool show_raw_img = false;
// Tableau
int width, height;
int def_tableau = 10000;
// ofTexture tex_gray;
ofTexture tex_rgb;
// ofTexture tex_rgb_a;

// ofPixels pix_gray;
ofPixels pix_rgb;
// ofPixels pix_rgb_a;
// float ratio_x = 1.0;
// float ratio_y = 1.0;
ivec2 size(0, 0);
vec2 ratio(1.0, 1.0);


//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(255,0,0);
  // ofSetFrameRate(6);
  // ofSetupOpenGL(400, 400, OF_WINDOW);
  ofSetBackgroundAuto(false);
  radeau.load("images/le_radeau_de_la_méduse.jpg");
  liberte.load("images/la_liberté_guidant_le_peuple.jpg");
  // init position
  pos_x = ofRandom(ofGetWidth());
  pos_y = ofRandom(ofGetHeight());
  // radeau.load("images/le_radeau_de_la_méduse_1024_768.jpg");
  // liberte.load("images/la_liberté_guidant_le_peuple_1024_768.jpg");

  // std::cout << "0 setup >> ratio_x: " << ratio_x << " || ratio_y: "<< ratio_y << std::endl ;
  std::cout << "0 setup >> size: " << size.x << " | "<< size.y << std::endl ;

  size.x = ofGetWidth();
  size.y = ofGetHeight();

  std::cout << "1 setup >> size: " << size.x << " | "<< size.y << std::endl ;
  width = ofGetWidth();
  height = ofGetWidth();

  // créer la texture couleur du tableau
  pix_rgb.allocate(width, height, OF_PIXELS_RGB);
  pix_rgb.setColor(ofColor(255,0,255)); // magenta
  tex_rgb.allocate(pix_rgb);
}

//--------------------------------------------------------------
void ofApp::update(){
  // PIXEL SPRAY
  if(ofGetMousePressed()) {
    int num_pixel = 10;
    int radius = 100;
    ivec2 mouse(ofGetMouseX(), ofGetMouseY());
    if(switch_img) {
      pixels_spray(size, mouse, num_pixel, radius, tex_rgb, pix_rgb, liberte);
    } else {
      pixels_spray(size, mouse, num_pixel, radius, tex_rgb, pix_rgb, radeau);
    }
  }
  // PIXEL VOYAGEUR
  if(switch_img) {
    pix_color = get_color_image(pos_x, pos_y, liberte);
  } else {
    pix_color = get_color_image(pos_x, pos_y, radeau);
  }
  pixel_voyageur(width, height, pos_x, pos_y, pix_color, tex_rgb, pix_rgb);
}

//--------------------------------------------------------------
void ofApp::draw() {
  // Tableau final
  tex_rgb.draw(0,0);
  // Image de reférence utlisée
  

  if(show_raw_img) {
    if(switch_img) {
      vec2 ratio(get_ratio(liberte.getWidth(), liberte.getHeight(), ofGetWidth(), ofGetHeight(),0));
      // std::cout << "0 >> ratio: " << ratio.x << " " << ratio.y << std::endl ;
      ivec2 size(liberte.getWidth() *ratio.x, liberte.getHeight() * ratio.y);
      // std::cout << "0 >> size: " << size.x << " " << size.y << std::endl ;
      liberte.draw(0,0, size.x, size.y);
    } else {
      vec2 ratio(get_ratio(radeau.getWidth(), radeau.getHeight(), ofGetWidth(), ofGetHeight(), 0));
      ivec2 size(radeau.getWidth() *ratio.x, radeau.getHeight() * ratio.y);
      radeau.draw(0,0, size.x, size.y);
    }
  }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if(key == 'x') {
    switch_img = !switch_img;
  }
  if(key == 'i') {
    show_raw_img = !show_raw_img;   
  }
  // PLEIN DE PIXELS
  if(key == 'n') {
    if(switch_img) {
      pixels_tableau(width, height, def_tableau, tex_rgb, pix_rgb, liberte);
    } else {
      pixels_tableau(width, height, def_tableau, tex_rgb, pix_rgb, radeau);
    }
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
  pos_x = x;
  pos_y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
