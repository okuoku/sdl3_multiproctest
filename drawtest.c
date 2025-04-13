#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/* Constants */
const char* WND_NAME = "Test A";

/* global states */
static SDL_Window* wnd;
static SDL_Renderer* rnd;
static int quit_requested = 0;
static int animphase = 0;

static Uint32
cb_tick(void* bogus, SDL_TimerID tim, Uint32 interval){
    /* FIXME: Adjust intervals for accurate timing */
    (void) bogus;
    (void) tim;
    (void) interval;

    SDL_UserEvent ev;
    SDL_zero(ev);
    ev.type = SDL_EVENT_USER; /* FIXME: Register it */
    SDL_PushEvent(&ev);

    return 10; /* 10 ms later */
}

static void
tick(void){
    animphase++;
    if(animphase >= 256){
        animphase = 0;
    }

#ifdef PATTERN_A
    /* Render something from main thread */
    (void) SDL_SetRenderDrawColor(rnd, animphase, animphase, animphase, 
                                  SDL_ALPHA_OPAQUE);
    (void) SDL_RenderClear(rnd);

    /* Layout window */
    (void) SDL_SetWindowPosition(wnd, 300 + animphase * 2, 500);

    /* Flip window */
    (void) SDL_RenderPresent(rnd);
#elif defined(PATTERN_B)
    /* Another pattern */
    (void) SDL_SetRenderDrawColor(rnd, animphase, 128, 128, 
                                  SDL_ALPHA_OPAQUE);
    (void) SDL_RenderClear(rnd);
    (void) SDL_SetWindowPosition(wnd, 100, 100);
    (void) SDL_SetWindowSize(wnd, 800, 800);
    (void) SDL_RenderPresent(rnd);
#else
#error unknown pattern??
#endif
}


int
main(int ac, char** av){
    (void) ac;
    (void) av;

    SDL_Init(SDL_INIT_VIDEO);
    wnd = SDL_CreateWindow(WND_NAME, 100, 100, 
                           SDL_WINDOW_HIGH_PIXEL_DENSITY | 
                           SDL_WINDOW_BORDERLESS
                           /* | SDL_WINDOW_NOT_FOCUSABLE */);


    rnd = SDL_CreateRenderer(wnd, NULL);

    /* Add a 100fps timer */
    SDL_TimerID tim;
    tim = SDL_AddTimer(10, cb_tick, 0);

    /* Main event loop */
    SDL_Event ev;
    while(!quit_requested){
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_EVENT_QUIT){
                quit_requested = 1;
            }else if(ev.type == SDL_EVENT_USER){
                tick();
            }
        }
    }

    SDL_DestroyWindow(wnd);
    SDL_Quit();
    return 0;
}
