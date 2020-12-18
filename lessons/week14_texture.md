# (14 неделя) - OpenGL 3.0: Текстура



## План работы: 

## 1. Теория

## 2. Практика

```
#include "stb_image.h"

GLuint tvbo;
GLuint texLoc;

GLuint uvbo;
GLuint uvLoc;
```

Необходимо полностью убрать цвета, она будет только мешать

```
GLuint tvbo;
GLuint texLoc;

GLuint uvbo;
GLuint uvLoc;
```

		attribute vec2 uv1;\
		varying vec2 uv2;\
	    uv2 = uv1;\n\


		varying vec2 uv2;\
		uniform sampler2D tex;\
	
	gl_FragColor = texture2D(tex, uv2); \n\ написать вместо gl_FragColor = vec4(color2, 1);

	texLoc = glGetUniformLocation(program, "tex");
	uvLoc = glGetAttribLocation(program, "uv1");

![img](https://github.com/aktumar/Learning_Computer_Graphics/blob/master/lessons/images/texture.png)

	float uv[] = {........}; // определите правильные координаты по карте текстуры
	
	glGenBuffers(1, &uvbo);
	glBindBuffer(GL_ARRAY_BUFFER, uvbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	int w, h, comp;
	unsigned char * image = stbi_load("stb_image.jpg", &w, &h, &comp, 3);
	
	float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &tvbo);
	glBindBuffer(GL_TEXTURE_2D, tvbo);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D);
	glUniform1i(texLoc, 0);
	stbi_image_free(image);
	glBufferData(GL_TEXTURE_2D, sizeof(color), color, GL_CLAMP_TO_BORDER);


	glEnableVertexAttribArray(uvLoc);
	glBindBuffer(GL_ARRAY_BUFFER, uvbo);
	glVertexAttribPointer(uvLoc, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDisableVertexAttribArray(uvLoc);
# Источники
