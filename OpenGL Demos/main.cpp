//
//  main.cpp
//  OpenGL Demos
//
//  Created by Mehmet Hazar Artuner on 20.04.2020.
//  Copyright © 2020 Mehmet Hazar Artuner. All rights reserved.
//

#include <iostream>

#define GLEW_STATIC
#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES 1

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

const GLint WIDTH = 1280, HEIGHT = 720;

int main(int argc, const char * argv[]) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "STD Initialization error" << SDL_GetError() << std::endl;
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    
    SDL_Window* window = SDL_CreateWindow("OpenGL App", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    
    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()) {
        std::cout << "Glew Failed" << std::endl;
        return EXIT_FAILURE;
    }
    
    glViewport(0, 0, WIDTH, HEIGHT);
    
    SDL_Event windowEvent;
    
    while(true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) {
                break;
            }
        }
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        SDL_GL_SwapWindow(window);
    }
    
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
