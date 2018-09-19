#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(3);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofSetDepthTest(true);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int length = 30;
	int x_span = 20;
	int y_span = 20;
	for (int x = 0; x < ofGetWidth(); x += x_span) {

		for (int y = 0; y < ofGetHeight(); y += y_span) {

			ofColor color(ofRandom(255), 255, 255);
			ofSetColor(color);

			ofPushMatrix();
			ofTranslate(x + x_span * 0.5, y + y_span * 0.5);
			ofRotateX(ofMap(ofNoise(x * 0.001, y * 0.001, ofGetFrameNum() * 0.005), 0, 1, 0, 360));

			ofDrawRectangle(0, 0, x_span, y_span);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(720, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}