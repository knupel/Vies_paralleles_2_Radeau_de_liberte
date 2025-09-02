#include "ofMain.h"
#include "ofApp.hpp"
// #include "utils.hpp"

//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	float ratio_x = 1.5;
	float ratio_y = 1;
	settings.setSize(int(ratio_x*1024), int(ratio_y*768));
	// settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN
	// settings.windowMode = OF_FULLSCREEN;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, std::make_shared<ofApp>());
	ofRunMainLoop();

}
