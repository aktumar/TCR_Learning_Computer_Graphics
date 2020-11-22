#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

GLuint vbo;
GLuint cbo;
GLuint posLoc;
GLuint colorLoc;
GLuint cam;

GLuint viewLoc;
glm::mat4 view(1);

void myIdle()
{
	view = glm::rotate(view, 0.1f, glm::vec3(0, 1, 0));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glutPostRedisplay();
}


void myInit()
{
	GLuint program = glCreateProgram();

	GLuint vsh = glCreateShader(GL_VERTEX_SHADER);

	const char*vshCode = "#version 120\n\
				  attribute vec3 pos;\n\
				  attribute vec3 color1;\n\
				  varying vec3 color2;\n\
				  uniform mat4 cam;\n\
					uniform mat4 view;\
				 void main( )\n\
	 				  {\n\
					  		gl_Position = view * cam * vec4(pos, 1);\n\
							color2 = color1;\n\
	 				  }";

	GLint length = strlen(vshCode);
	glShaderSource(vsh, 1, &vshCode, &length);
	glCompileShader(vsh);
	glAttachShader(program, vsh);

	GLuint fsh = glCreateShader(GL_FRAGMENT_SHADER);

	const char*fshCode = "#version 120\n\
						varying vec3 color2;\n\
						 void main( )\n\
	 				  {\n\
					        gl_FragColor = vec4(color2,1);\n\
	 				  }";

	length = strlen(fshCode);
	glShaderSource(fsh, 1, &fshCode, &length);
	glCompileShader(fsh);
	glAttachShader(program, fsh);


	glValidateProgram(program);
	glLinkProgram(program);
	glUseProgram(program);


	posLoc = glGetAttribLocation(program, "pos");
	colorLoc = glGetAttribLocation(program, "color1");
	cam = glGetUniformLocation(program, "cam");
	viewLoc = glGetUniformLocation(program, "view");

	float vertices[] = {

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		 0.5f,  0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	float color[] = { 0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,
		0.0 ,0.0,0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0,
	0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0,0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,
		0.0 ,0.0,0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0,
	0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0, 0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,
		0.0 ,0.0,0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0,
	0.0, 0.0, 1.0 , 1.0, 1.0, 0.0, 0.0 ,1.0 ,0.0, 1.0 ,0.0 ,0.0 };
	glGenBuffers(1, &cbo);
	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), color, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);




	glm::vec3 position = glm::vec3(0, -2, 3);
	glm::vec3 target = glm::vec3(0, 0, 0);
	glm::vec3 dirc = glm::normalize(position - target);
	glm::vec3 up = glm::vec3(1, 0, 0);

	glm::mat4 MAT = glm::lookAt(position, dirc, up);

	glm::mat4 pMAT = glm::perspective(60.0f, (float)512 / 512, 1.0f, 100.0f);
	glm::mat4 gMAT = pMAT * MAT;

	glUniformMatrix4fv(cam, 1, GL_FALSE, &gMAT[0][0]);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableVertexAttribArray(posLoc);
	glEnableVertexAttribArray(colorLoc);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glDrawArrays(GL_TRIANGLES, 0, 36);


	glDisableVertexAttribArray(posLoc);
	glDisableVertexAttribArray(colorLoc);

	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(argv[0]);

	glEnable(GL_DEPTH_TEST);
	glewInit();
	myInit();

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myIdle);

	glutMainLoop();
}