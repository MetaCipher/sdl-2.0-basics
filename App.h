#include <SDL2/SDL.h>

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

		void OnEvent(SDL_Event* Event);

		bool Init();

		void Loop();

		void Render();

		void Cleanup();

	public:
		int Execute(int argc, char* argv[]);

	public:
		static App* GetInstance();
};
