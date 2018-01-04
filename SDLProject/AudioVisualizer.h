
#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
using namespace std;

typedef class AudioVisualizer;

class AudioVisualizer {

private:
	//Visual Components//
	const int SCREEN_WIDTH = 720; 
	const int SCREEN_HEIGHT = 480;
	SDL_Window * window; 
	SDL_Surface * screen;

	//Audio Components//
	bool exit;
	Mix_Music * song; //Pointer to song to be played using mix libraries 
	SDL_Event e; //Variable to handle keyboard events

	//Audio Functions//
	bool initialize(); //Initialize audio and visual components 
	Mix_Music * loadMusic(); //Function that will load the audio file. Can be any format supported by SDL


public:
	//Audio Functions//
	AudioVisualizer(); //Constructor 
	void eventListen(); //This handles listening for audio events. Play/Pause/Resume etc.
	//~AudioVisualizer(); //Destructor


};