#include "AudioVisualizer.h"

bool AudioVisualizer::initialize() {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { //Init both SDL_Audio and SDL_Video
		SDL_Log("SDL could not be initialized \n");
		return false;
	}

	window = SDL_CreateWindow("My SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Log("Window could not be created! \n");
		return false;
	}

	screen = SDL_GetWindowSurface(window);
	if (screen == NULL) {
		SDL_Log("Window could not be created! \n");
		return false;
	}
	return true;
}

Mix_Music * AudioVisualizer::loadMusic() {
	return Mix_LoadMUS("dt_32bars_105jazz.wav"); //TODO: Change to have a string parameter specifying the file 
}


AudioVisualizer::AudioVisualizer() {
	
	if (!initialize()) {
		SDL_Log("Error Initializing\n");
		return;
	}

	bool exit = false;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		SDL_Log("Error: Could not read audio\n");
	}

	song = loadMusic();
	
	if (song == nullptr) {
		SDL_Log("Could not load song.\n");
	}


}

void AudioVisualizer::eventListen() {
	while (!exit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				exit = true;
			}

			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_p:
					if (!Mix_PlayingMusic()) {
						Mix_PlayMusic(song, -1);
					}
					else if (Mix_PausedMusic()) {
						Mix_ResumeMusic();
					}
					else {
						Mix_PauseMusic();
					}
					break;
				case SDLK_s:
					Mix_HaltMusic();
					break;

				default: break;
				}
			}
		}
	}


}
