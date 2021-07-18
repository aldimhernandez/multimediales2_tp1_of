#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void paneles();
	void cassette();
	void clues();
	void playPressed();
	void pausePressed();
	void resumePressed();
	void stopPressed();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//Creamos el objeto video
	ofVideoPlayer video;
	//Creamos 4 paneles de tipo booleano
	bool panel1, panel2, panel3, panel4;
	//Creamos una variable de tipo booleana para mostrar/esconder la clase cassette
	bool showCassette;

	//Creamos las variables para guardar las imagenes
	ofImage cassette1_3d, cassette2, cassette3, cassette4, choose_3d;
	ofImage tinyWheel, bigWheel;
	ofImage clue01, clue02, clue03;

	//Bool para mostrar/esconder la GUI
	bool showGui;
	ofxPanel gui; //Creamos el panel para la GUI

	ofxGuiGroup soundGroup; //Creamos un grupo de funciones
	ofxButton play; //Función para reproducir
	ofxButton pause; //Función para pausar
	ofxButton resume; //Función para reanudar
	ofxButton stop; //Función para parar
	ofxFloatSlider volume; //Función con rangos de volumen (set)
	ofxFloatSlider speed; //Función con rangos de velocidad (set)

	bool isPaused;

	bool finalPlay;

	ofxGuiGroup cassetteGroup; //Grupo para los cassettes
	ofxToggle c1; //Activa/Desactiva Cassette 1
	ofxToggle c2; //Activa/Desactiva Cassette 2
	ofxToggle c3; //Activa/Desactiva Cassette 3
	ofxToggle c4; //Activa/Desactiva Cassette 4

	ofxGuiGroup clueGroup; //Grupo para pistas
	ofxToggle clue1; //Pistas 1
	ofxToggle clue2; //Pistas 2
	ofxToggle clue3; //Pistas 3

	//Creamos las variables para los audios
	ofSoundPlayer loop1, loop2, loop3, loop4, loopFinal, fail, succes;
};
