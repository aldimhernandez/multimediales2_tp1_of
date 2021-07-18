#include "ofApp.h"
#include <iostream>
#include <string>

//--------------------------------------------------------------
void ofApp::setup() {
	//Config grales
	ofSetFrameRate(60);
	ofSetWindowShape(1024, 768);
	ofSetWindowTitle("AURA V1.0");
	ofBackground(0);

	//Video
	video.loadMovie("video/final.mp4");

	//Paneles a desbloquear
	panel1 = true; panel2 = true; panel3 = true; panel4 = true;

	//Cassettes
	showCassette = true;
	cassette1_3d.load("img/cassette1_3d.png");
	cassette2.load("img/cassette2_3d.png");
	cassette3.load("img/cassette3_3d.png");
	cassette4.load("img/cassette4_3d.png");
	choose_3d.load("img/choose_3d.png");
	//Ruedas
	//tinyWheel.load("img/tinyWheel.png");
	bigWheel.load("img/bigWheel_3d.png");
	//Pistas
	clue01.load("img/clue1_3d.png");
	clue02.load("img/clue2_3d.png");
	clue03.load("img/clue3_3d.png");

	//Eventos pendientes del estado de los botones play, pause y/o stop 
	play.addListener(this, &ofApp::playPressed);
	pause.addListener(this, &ofApp::pausePressed);
	resume.addListener(this, &ofApp::resumePressed);
	stop.addListener(this, &ofApp::stopPressed);

	//GUI Inicial
	showGui = true;
	gui.setup("Discover the clue");
	//Grupo Reproductor de Sonido
	soundGroup.setup("Player");
	soundGroup.add(play.setup("Play"));
	soundGroup.add(pause.setup("Pause (Click Resume)"));
	soundGroup.add(resume.setup("Resume"));
	soundGroup.add(stop.setup("Stop"));
	soundGroup.add(volume.setup("Volume", 1.0, 0.0, 1.0));
	soundGroup.add(speed.setup("Speed", 1.0, -3.0, 3.0));
	gui.add(&soundGroup);
	//Grupo Seleccionar Casetes
	cassetteGroup.setup("Cassette Selector");
	cassetteGroup.add(c1.setup("Cassette 1", false)); //Cassette 1 desactivado
	cassetteGroup.add(c2.setup("Cassette 2", false));
	cassetteGroup.add(c3.setup("Cassette 3", false));
	cassetteGroup.add(c4.setup("Cassette 4", false));
	gui.add(&cassetteGroup);
	//Grupo de pistas
	clueGroup.setup("Activate Clue");
	clueGroup.add(clue1.setup("Clue 1", false));
	clueGroup.add(clue2.setup("Clue 2", false));
	clueGroup.add(clue3.setup("Clue 3", false));
	gui.add(&clueGroup);
	//Posicion GUI
	gui.setPosition(20, 20);

	//Pistas
	loop1.loadSound("audio/audio1_fisher.wav");
	loop2.loadSound("audio/audio2_videokill.wav");
	loop3.loadSound("audio/audio3_fukuyama.wav");
	loop4.loadSound("audio/audio4_kraft.wav");
	fail.loadSound("audio/fail.wav");
	succes.loadSound("audio/succes.wav");
	loopFinal.loadSound("audio/master.wav");
	isPaused = false;
	finalPlay = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	video.update();
	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(255);
	video.draw(0, 50, ofGetWidth(), ofGetHeight() - 200);
	video.play();

	ofSetColor(127);
	paneles();

	ofSetColor(255);
	if (showCassette)
	{
		cassette();
		clues();
	}

	ofSetColor(255);
	if (showGui)
	{
		gui.draw();
	}

	//Testing
	//cout << "loopFinal.isLoaded(): " << loopFinal.isLoaded() << " - loopFinal.isPlaying(): " << loopFinal.isPlaying() << " - Loop final: " << loopFinal.getPositionMS() << endl;
	cout << "loop4 pos ms: " << loop4.getPositionMS() << endl;
}
//--------------------------------------------------------------

	
//--------------------------------------------------------------
void ofApp::playPressed() {

	if (c1)
	{
		loop1.play();
	}
	else if (c2)
	{
		loop2.play();
	}
	else if (c3)
	{
		loop3.play();
	}
	else if (c4)
	{
		loop4.play();
	}
	else if (finalPlay)
	{
		loopFinal.play();
	}
}

//--------------------------------------------------------------
void ofApp::pausePressed() {
	if (c1)
	{
		loop1.setPaused(true);
		isPaused = true;

		if (loop1.getPositionMS() > 4700 && loop1.getPositionMS() < 5300)
		{
			panel1 = !panel1;
			succes.play();
		}
		else
		{
			fail.play();
			fail.setVolume(0.1f);
		}
	}
	else if (c2)
	{
		loop2.setPaused(true);
		isPaused = true;
		if (loop2.getPositionMS() > 4700 && loop2.getPositionMS() < 5000)
		{
			panel2 = !panel2;
			succes.play();
		}
		else
		{
			fail.play();
			fail.setVolume(0.1f);
		}
	}
	else if (c3)
	{
		loop3.setPaused(true);
		isPaused = true;
		if (loop3.getPositionMS() > 4700 && loop3.getPositionMS() < 5100)
		{
			panel3 = !panel3;
			succes.play();
		}
		else
		{
			fail.play();
			fail.setVolume(0.1f);
		}
	}
	else if (c4)
	{
		loop4.setPaused(true);
		isPaused = true;
		if (loop4.getPositionMS() > 4900 && loop4.getPositionMS() < 5100)
		{
			panel4 = !panel4;
			succes.play();
		}
		else
		{
			fail.play();
			fail.setVolume(0.1f);
		}
	}
}

//--------------------------------------------------------------
void ofApp::resumePressed() {

	if (c1)
	{
		loop1.setPaused(false);
		isPaused = false;
	}
	else if (c2)
	{
		loop2.setPaused(false);
		isPaused = false;
	}
	else if (c3)
	{
		loop3.setPaused(false);
		isPaused = false;
	}
	else if (c4)
	{
		loop4.setPaused(false);
		isPaused = false;
	}
}

//--------------------------------------------------------------
void ofApp::stopPressed() {

	if (c1)
	{
		loop1.stop();
	}
	else if (c2)
	{
		loop2.stop();
	}
	else if (c3)
	{
		loop3.stop();
	}
	else if (c4)
	{
		loop4.stop();
	}
}

//--------------------------------------------------------------
void ofApp::cassette() {

	if (c1)
	{
		cassette1_3d.draw(ofGetWidth() / 2 - cassette1_3d.getWidth() / 2,
			ofGetHeight() / 2 - cassette1_3d.getHeight() / 2);
		c2 = false;
		c3 = false;
		c4 = false;
		loop2.stop(); loop3.stop(); loop4.stop();
		loop1.setVolume(volume);
		loop1.setSpeed(speed);
		loop1.setLoop(true);
	}
	else if (c2)
	{
		cassette2.draw(ofGetWidth() / 2 - cassette2.getWidth() / 2,
			ofGetHeight() / 2 - cassette2.getHeight() / 2);
		c1 = false;
		c3 = false;
		c4 = false;
		loop1.stop(); loop3.stop(); loop4.stop();
		loop2.setVolume(volume);
		loop2.setSpeed(speed);
		loop2.setLoop(true);
	}
	else if (c3)
	{
		cassette3.draw(ofGetWidth() / 2 - cassette3.getWidth() / 2,
			ofGetHeight() / 2 - cassette3.getHeight() / 2);

		c1 = false;
		c2 = false;
		c4 = false;
		loop1.stop(); loop2.stop(); loop4.stop();
		loop3.setVolume(volume);
		loop3.setSpeed(speed);
		loop3.setLoop(true);
	}
	else if (c4)
	{
		cassette4.draw(ofGetWidth() / 2 - cassette4.getWidth() / 2,
			ofGetHeight() / 2 - cassette4.getHeight() / 2);
		c1 = false;
		c2 = false;
		c3 = false;
		loop1.stop(); loop2.stop(); loop3.stop();
		loop4.setVolume(volume);
		loop4.setSpeed(speed);
		loop4.setLoop(true);
	}
	else
	{
		loop1.stop();
		loop2.stop();
		loop3.stop();
		loop4.stop();

		for (int i = 0; i <= 1000; i++)
		{

		}

		choose_3d.draw(ofGetWidth() / 2 - choose_3d.getWidth() / 2,
			ofGetHeight() / 2 - choose_3d.getHeight() / 2);
	}

	if (loop1.isPlaying() || loop2.isPlaying() || loop3.isPlaying() || loop4.isPlaying())
	{
		if (isPaused == false)
		{
			for (int i = 0; i <= 1000; i++)
			{
				ofPushMatrix();
					ofTranslate(cassette3.getWidth() - (bigWheel.getWidth() / 3) - 13,
								cassette3.getHeight() - (bigWheel.getHeight() / 2) - 10, 0);
					ofRotate(ofGetFrameNum() * .01 * 200, 0, 0, i * 20);
					ofPushMatrix();
						ofTranslate(-bigWheel.getWidth() / 2, -bigWheel.getHeight() / 2, 0);
						bigWheel.draw(0, 0);
					ofPopMatrix();
				ofPopMatrix();
			}
		}
	}
}

void ofApp::clues() {

	if (clue1)
	{
		for (int i = 0; i <= 1000; i++)
		{
			ofPushMatrix();
				ofTranslate(cassette3.getWidth() - (bigWheel.getWidth() / 3) - 300,
							cassette3.getHeight() - (bigWheel.getHeight() / 2) + 100, 0);
				ofRotate(ofGetFrameNum() * -.01 * 20, 0, 0, i * 2);
				ofPushMatrix();
					ofTranslate(-bigWheel.getWidth() / 2, -bigWheel.getHeight() / 2, 0);
					clue01.draw(0, 0);
				ofPopMatrix();
			ofPopMatrix();
		}
	}

	if (clue2)
	{
		for (int i = 0; i <= 1000; i++)
		{
			ofPushMatrix();
				ofTranslate(cassette3.getWidth() - (bigWheel.getWidth() / 3) + 200,
							cassette3.getHeight() - (bigWheel.getHeight() / 2) - 300, 0);
				ofRotate(ofGetFrameNum() * -.01 * 80, 0, 0, i * 6);
				ofPushMatrix();
					ofTranslate(-bigWheel.getWidth() / 2, -bigWheel.getHeight() / 2, 0);
					clue02.draw(0, 0);
				ofPopMatrix();
			ofPopMatrix();
		}
	}

	if (clue3)
	{
		for (int i = 0; i <= 1000; i++)
		{
			ofPushMatrix();
				ofTranslate(cassette3.getWidth() - (bigWheel.getWidth() / 3) + 450,
							cassette3.getHeight() - (bigWheel.getHeight() / 2) + 150, 0);
				ofRotate(ofGetFrameNum() * -.01 * 1000, 0, 0, i * 6);
				ofPushMatrix();
					ofTranslate(-bigWheel.getWidth() / 2, -bigWheel.getHeight() / 2, 0);
					clue03.draw(0, 0);
				ofPopMatrix();
			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
void ofApp::paneles() {

	if (panel1)
	{
		ofSetColor(63);
		ofDrawRectangle(0, 0, ofGetWidth() / 4, ofGetHeight());
	}
	if (panel2)
	{
		ofSetColor(0, 0, 63);
		ofDrawRectangle(ofGetWidth() / 4, 0, ofGetWidth() / 4, ofGetHeight());
	}
	if (panel3)
	{
		ofSetColor(0, 63, 0);
		ofDrawRectangle(ofGetWidth() / 4 * 2, 0, ofGetWidth() / 4, ofGetHeight());
	}
	if (panel4)
	{
		ofSetColor(63, 0, 0);
		ofDrawRectangle(ofGetWidth() / 4 * 3, 0, ofGetWidth() / 4, ofGetHeight());
	}

	if (!panel1 && !panel2 && !panel3 && !panel4)
	{
		showGui = false;
		showCassette = false;
		finalPlay = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
