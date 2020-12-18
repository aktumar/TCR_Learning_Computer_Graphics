# (13 неделя) - OpenGL 3.0: Управление мышкой



## План работы: 

## 1. Теория

## 2. Практика



	int prevx, prevy;
	bool right_button = false;
	bool left_button = false;
```
void myMouse(int button, int state, int x, int y)
{
	prevx = x;
	prevy = y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		left_button = true;
	}
	else 
	{
		left_button = false;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

		right_button = true;
	}
	else
	{
		right_button = false;
	}

}
```

```
void myMotion(int x, int y)
{
	if (left_button) 
	{
		view = glm::rotate(view, (float)x1/10, glm::vec3(1, 0, 0));
		view = glm::rotate(view, (float)y1/10, glm::vec3(0, 1, 0));
	}

    if (right_button) 
    {
        view = glm::translate(view, glm::vec3(x1/200.f, -y1/200.0f, -(x1 - y1)/200.0f));
    }

    if (middle_button)
    {
        view = glm::scale(view, glm::vec3(1.1f, 1.1f, 1.1f));
    }

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glutPostRedisplay();

    prevx = x;
    prevy = y;
}
```

```
glutMouseFunc(myMouse);
glutMotionFunc(myMotion);
```



# Источники

