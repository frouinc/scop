#include <scop.h>

const char *vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n"
								 "void main()\n"
								 "{\n"
								 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								 "}\0";

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

int initWindow(t_scop *scop)
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create window with GLFW
	scop->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (scop->window == NULL)
	{
		printf("Failed to create GLFW window\n");
		return (-1);
	}
	glfwMakeContextCurrent(scop->window);
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	// End of create window with GLFW

	glfwSetFramebufferSizeCallback(scop->window, framebuffer_size_callback); // Set callback for window resize
	return (1);
}

int buildShaders(t_scop *scop)
{
	// Compile vertex shader
	scop->vertexShader = glCreateShader(GL_VERTEX_SHADER);										   // Create an empty vertex shader
	glShaderSource(scop->vertexShader, 1, (const char *const *)&(scop->vertexShaderSource), NULL); // Bind the shader source to the empty shader
	glCompileShader(scop->vertexShader);														   // Compile shader

	int success;
	char infoLog[512];
	glGetShaderiv(scop->vertexShader, GL_COMPILE_STATUS, &success); // Get compilation status
	if (!success)
	{
		glGetShaderInfoLog(scop->vertexShader, 512, NULL, infoLog); // Get error info
		printf("Vertex shader compilation failed: %s\n", infoLog);
		return (-1);
	}
	// End of compile vertex shader

	// Compile fragment shader
	scop->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);										   // Create an empty fragment shader
	glShaderSource(scop->fragmentShader, 1, (const char *const *)&(scop->fragmentShaderSource), NULL); // Bind the shader source to the empty shader
	glCompileShader(scop->fragmentShader);															   // Compile shader

	glGetShaderiv(scop->fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(scop->fragmentShader, 512, NULL, infoLog);
		printf("Fragment shader compilation failed: %s\n", infoLog);
		return (-1);
	}
	// End of compile fragment shader

	// Create shader program
	scop->shaderProgram = glCreateProgram();
	glAttachShader(scop->shaderProgram, scop->vertexShader);
	glAttachShader(scop->shaderProgram, scop->fragmentShader);
	glLinkProgram(scop->shaderProgram);
	glGetProgramiv(scop->shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(scop->shaderProgram, 512, NULL, infoLog);
		printf("Shader program linking failed: %s\n", infoLog);
		return (-1);
	}
	glUseProgram(scop->shaderProgram);
	glDeleteShader(scop->shaderProgram);
	glDeleteShader(scop->fragmentShader);
	// End of create shader program

	return (1);
}

int initGlfw(t_scop *scop)
{
	if (initWindow(scop) == -1)
	{
		return (-1);
	}

	if (buildShaders(scop) == -1)
	{
		return (-1);
	}

	// Create vertices

	float vertices[] = {
		0.5f, 0.5f, 0.0f,   // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f   // top left
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &scop->VAO); // Create Vertex Array Object
	glGenBuffers(1, &scop->VBO);	  // Create Vertex Buffer Object
	glGenBuffers(1, &scop->EBO);

	glBindVertexArray(scop->VAO);											   // Bind the vertex array object

	glBindBuffer(GL_ARRAY_BUFFER, scop->VBO);								   // Bind VBO to GL_ARRAY_BUFFER type
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copy the vertices data into the buffer

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, scop->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// Tell openGL how to read the vertex data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return (1);
}

void clean(t_scop *scop)
{
	glDeleteVertexArrays(1, &scop->VAO);
	glDeleteBuffers(1, &scop->VBO);
    glDeleteBuffers(1, &scop->EBO);

	glfwTerminate();
	free(scop);
}

void processInput(t_scop *scop)
{
	if (glfwGetKey(scop->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Check for escape key
	{
		glfwSetWindowShouldClose(scop->window, true);			 // Window should close if key is pressed
	}
	else if (glfwGetKey(scop->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else if (glfwGetKey(scop->window, GLFW_KEY_F) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

int loop(t_scop *scop)
{
	while (!glfwWindowShouldClose(scop->window))
	{
		// INPUT
		processInput(scop); // Check for input

		// RENDER
		glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // Choose clear color
		glClear(GL_COLOR_BUFFER_BIT);		  // Clear screen with color

		glUseProgram(scop->shaderProgram);
		glBindVertexArray(scop->VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// GLFW
		glfwSwapBuffers(scop->window); // Swap image buffer
		glfwPollEvents();			   // Poll for any event (close, move, resize)
	}

	return (1);
}

int main()
{
	t_scop *scop;

	if ((scop = malloc(sizeof(t_scop))) == NULL)
	{
		printf("Couldn't allocate memory for scop.\n");
		return (-1);
	}

	scop->vertexShaderSource = (const char *const *)read_file("shaders/vertex.shader");		// Read vertex shader file
	scop->fragmentShaderSource = (const char *const *)read_file("shaders/fragment.shader"); // Read fragment shader file

	// All the initialization
	if (initGlfw(scop) == -1)
	{
		printf("Couldn't initialize GLFW\n");
		glfwTerminate();
		free(scop);
		return (-1);
	}

	loop(scop);

	clean(scop);
	return (0);
}