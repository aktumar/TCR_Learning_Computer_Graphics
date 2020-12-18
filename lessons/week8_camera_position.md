# (8 неделя) - OpenGL 3.0: Управление камерой



## План работы: 

## 1. Теория

## 2. Практика




	#include <glm/glm/glm.hpp>
	#include <glm/glm/gtc/matrix_transform.hpp>
	#include <glm/glm/gtc/type_ptr.hpp>

```
GLuint cam;
```

```
uniform mat4 cam;\n\
gl_Position = cam * vec4(pos, 1);\n\
```

```
cam = glGetUniformLocation(program, "cam");
```

	glm::vec3 position = glm::vec3(0, 0, 3);
	glm::vec3 target = glm::vec3(0, 0, 0);
	glm::vec3 dirc = glm::normalize(position - target);
	glm::vec3 up = glm::vec3(0, 1, 0);
	
	glm::mat4 MAT = glm::lookAt(position, dirc, up);
	glm::mat4 pMAT = glm::perspective(60.0f, (float)512 / 512, 1.0f, 100.0f);
	
	glm::mat4 gMAT = pMAT * MAT;
	
	glUniformMatrix4fv(cam, 1, GL_FALSE, &gMAT[0][0]);
# Источники

