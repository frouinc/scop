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

int initGlfw(t_scop *scop)
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

	// Create vertices
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f};

	// Create Vertex object buffer
	unsigned int VBO;
	glGenBuffers(1, &VBO);													   // Generate one buffer and store it in VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);										   // Bind VBO to GL_ARRAY_BUFFER type
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copy the vertices data into the buffer
	// End of create VBO

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
	scop->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);										 // Create an empty fragment shader
	glShaderSource(scop->fragmentShader, 1, (const char *const *)&(scop->fragmentShaderSource), NULL); // Bind the shader source to the empty shader
	glCompileShader(scop->fragmentShader);															 // Compile shader

	glGetShaderiv(scop->fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(scop->fragmentShader, 512, NULL, infoLog);
		printf("Fragment shader compilation failed: %s\n", infoLog);
		return (-1);
	}
	// End of compile fragment shader

	return (1);
}

void processInput(t_scop *scop)
{
	if (glfwGetKey(scop->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Check for escape key
		glfwSetWindowShouldClose(scop->window, true);			 // Window should close if key is pressed
}

int loop(t_scop *scop)
{
	while (!glfwWindowShouldClose(scop->window))
	{
		processInput(scop); // Check for input

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // Choose clear color
		glClear(GL_COLOR_BUFFER_BIT);		  // Clear screen with color

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

	glfwTerminate();
	free(scop);
	return (0);
}