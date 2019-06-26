#ifndef SCOP_H_
#define SCOP_H_

// STDLIB
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graphic lib
#define GL_SILENCE_DEPRECATION
#include <glfw3.h>

#define SCR_WIDTH 800
#define SCR_HEIGHT 600

typedef struct s_scop
{
	GLFWwindow *window; // Window

	// Vertex Shader
	const char *const *vertexShaderSource;
	unsigned int vertexShader;

	// Fragment Shader
	const char *const *fragmentShaderSource;
	unsigned int fragmentShader;
} t_scop;

/*
** read_file.c
*/
char *read_file(const char *filename);

#endif // SCOP_H_