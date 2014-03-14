//==============================================================================
/*
	Primary application class

	3/11/2014
    SDLTutorials.com
    Tim Jones
*/
//==============================================================================
#include <SDL2/SDL.h>

#ifndef __APP_H__
	#define __APP_H__

class App {
	private:
		static App Instance;

		bool Running = true;

		SDL_Window* Window = NULL;
		SDL_Renderer* Renderer = NULL;
		SDL_Surface* PrimarySurface = NULL;

		static const int WindowWidth = 1024;
		static const int WindowHeight = 768;

	private:
		App();

		// Capture SDL Events
		void OnEvent(SDL_Event* Event);

		// Initialize our SDL game / app
		bool Init();

		// Logic loop
		void Loop();

		// Render loop (draw)
		void Render();

		// Free up resources
		void Cleanup();

	public:
		int Execute(int argc, char* argv[]);

	public:
		static App* GetInstance();

		static int GetWindowWidth();
		static int GetWindowHeight();
};

#endif
