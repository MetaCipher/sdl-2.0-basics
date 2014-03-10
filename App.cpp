#include "App.h"

App App::Instance;

App::App() {
}

void App::OnEvent(SDL_Event* Event) {
}

bool App::Init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    	Log("Unable to Init SDL: %s", SDL_GetError());
    	return false;
    }

    if((Window = SDL_CreateWindow(
    	"My SDL Game",
    	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    	SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)
    ) == NULL) {
    	Log("Unable to create SDL Window: %s", SDL_GetError());
    	return false;
    }

    PrimarySurface = SDL_GetWindowSurface(Window);

    return true;
}

void App::Loop() {
}

void App::Render() {
	SDL_UpdateWindowSurface(Window);
}

void App::Cleanup() {
	if(Window) {
	    SDL_DestroyWindow(Window);
		Window = NULL;
	}

    SDL_Quit();
}

int App::Execute(int argc, char* argv[]) {
	if(!Init()) return 0;

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&TheEvent) != 0) {
			OnEvent();
		}

		Loop();
		Render();

		SDL_Delay(1);
	}

	Cleanup();

	return 1;
}

static App* App::GetInstance() {
	return &App::Instance;
}
