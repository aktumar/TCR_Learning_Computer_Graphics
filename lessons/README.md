[TOC]

# Урок 1 - OpenGL 2.0: Первый треугольник



## План работы:

1. Для начала работы с библиотекой OpenGL необходимо установить Visual Studio и иметь базовые навыки программирования на С++
2. Для обсуждения проектов рекомендую создать аккаунт в GitHub (для новичков есть небольшая инструкция по [ссылке](https://github.com/aktumar/Learning_Computer_Graphics/blob/master/lessons/instructions/GitHub.md))
3. Для удобного просмотра данного файла с лекциями рекомендую использовать маркдаун редакторы (Typora, Notion, VisualCode)
4. А также необходимо установить дополнительные библиотеки (для новичков есть небольшая инструкция по [ссылке](https://github.com/aktumar/Learning_Computer_Graphics/blob/master/lessons/instructions/GitHub.md/Library_settings.md))  (ссылку на эти библиотеки можно найти ниже, в разделе "Библиотеки")

P.S. Для первого знакомства с компьютерной графикой будет достаточно одной библиотеки "freeglut 3.0.0 MSVC Package" (https://www.transmissionzero.co.uk/software/freeglut-devel/). Однако в следующих лекциях мы будем рассматривать с вами новые стандарты OpenGL 3.0 и GLSL. 



## 1. Теория

OpenGL (Open Graphics Library) — спецификация, определяющая платформонезависимый программный интерфейс для написания приложений, использующих двумерную и трёхмерную компьютерную графику.

Основным принципом работы OpenGL является получение наборов векторных графических примитивов в виде точек, линий и треугольников с последующей математической обработкой полученных данных и построением растровой картинки на экране и/или в памяти. 

OpenGL является низкоуровневым процедурным API, что вынуждает программиста диктовать точную последовательность шагов, чтобы построить результирующую растровую графику. С одной стороны, такой подход требует от программиста глубокого знания законов трёхмерной графики и математических моделей, с другой стороны — даёт свободу внедрения различных инноваций.

Существует ряд библиотек, созданных поверх или в дополнение к OpenGL. Например, библиотека GLU, являющаяся практически стандартным дополнением OpenGL и всегда её сопровождающая, построена поверх последней, то есть использует её функции для реализации своих возможностей. Другие библиотеки, как, например, GLUT и SDL, созданы для реализации возможностей, недоступных в OpenGL. К таким возможностям относятся создание интерфейса пользователя (окна, кнопки, меню и др.), настройка контекста рисования (область рисования, использующаяся OpenGL), обработка сообщений от устройств ввода-вывода (клавиатура, мышь и др.), а также работа с файлами.



## 2. Практика

Открываем пустой проект, создаем .cpp файл и можем приступать к выполнению следующих шагов.

```
// Включаем стандартный заголовок
#include <GL/freeglut.h>
```

> Если вы правильно выполнили 4-ый пункт в плане работы, то дальше проблем возникнуть не должно. Однако, если все таки у вас появились проблемы, то обязательно пишите на текстовом канале в Discort, постараюсь помочь.

Дальше создаем функцию `main()`. 

```
int main(int argc, char **argv){
```

В теле функции первым делом инициализируем `glut`:

```
	glutInit(&argc, argv);
```

Задаем режимы отображения для окна: GLUT_DOUBLE, к примеру, включает двойную буферизацию, буфер цвета GLUT_RGBA отвечает за цвет нашего объекта и GLUT_DEPTH за глубину (для определения переднего плана). Также задаем позицию окна на экране и размер окна (пиксель х пиксель). Теперь можно создавать OpenGL окно.

```
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL");
```

Попробуйте запустить этот код. Будет видно что у нас появилось окно, но оно очень быстро закроется. Поэтому нам необходимо добавить следующие функции обратного вызова: за рисование в окне отвечает команда `glutDisplayFunc()`, `glutMainLoop()`открывает определенный цикл, который ждет событие от оконной системы. 

```
	glutDisplayFunc(function);
	glutMainLoop();
}
```

Теперь попробуем начать рисование в новой функции `function`. 

	void function(void) {
	    glBegin(GL_TRIANGLES);
	    glVertex3f(0.0, 0.7, 0.0);
	    glColor3f(1, 0, 1);
	    glVertex3f(-0.7, -0.7, 0.0);
	    glColor3f(1, 1, 0);
	    glVertex3f(0.7, -0.7, 0.0);
	    glColor3f(1, 1, 1);
	    glEnd();
	
	    glutSwapBuffers();
	}
Как можно увидеть, для прорисовки одной фигуры необходимо указать начало и конец обрабатываемых точек. И даже можно задать определенный цвет каждой точке. При запуске этого кода, у вас должен получится такой треугольник:

![Image alt](https://github.com/aktumar/Learning_Computer_Graphics/blob/master/lessons/images/Lesson1_OpenGL_2.0.png)


> Задание №1. Найти определение каждой команде (для себя)

> Задание №2. Какие функции обратного вызова существуют в OpenGL (для себя)

> Задание №3. Какие еще существуют примитивы, кроме GL_TRIANGLES (для себя)

> Задание №4. Попробуйте создать шахматную доску 3х3 (Выложить в GitHub, для проверки домашнего задания)



# Урок 2 - OpenGL 3.0: Использование GLSL

## План работы:

1. Почитать самостоятельно про шейдерный язык программирования GLSL. Для полного понимания рекомендую посмотреть все ссылки указанные в параграфе "Источники". По этим ссылкам вам будет легче сориентироваться в огромном потоке информации.
2. Для начала 2-го задания необходимо скачать библиотеку glew (https://sourceforge.net/projects/glew/files/glew/2.1.0/). Скачайте версию - glew-2.1.0-win32. 
3. Проделайте такую же работу, как с freeglut с первого урока. 
   1. Вставить необходимые файлы (.h, .lib, .dll) в соответствующие папки
   2. Не забыть добавить .lib в свойствах проекта "Дополнительные зависимости"

## 1. Теория

Шейдеры — это небольшие программы выполняемые на графическом ускорителе. Эти программы выполняются для каждого конкретного участка графического конвейера. Если описывать шейдеры наиболее простым способом, то шейдеры — это не более чем программы преобразующие входы в выходы. Она сообщает компьютеру, как рендерить каждый пиксель. Шейдеры обычно изолированы друг от друга, и не имеют механизмов коммуникации между собой кроме упомянутых выше входов и выходов.

Эти программы называются шейдерами («затенителями»), потому что их часто используют для управления эффектами освещения и затенения, но ничего не мешает использовать их и для других спецэффектов.

Шейдеры пишут на специальном языке шейдеров. Мы будем использовать GLSL (OpenGL Shading Language), который похож на C. (Существует несколько языков написания шейдеров для разных платформ, но поскольку все они адаптированы под выполнение в видеопроцессоре, то похожи друг на друга.)

Ссылка на источник - https://habr.com/ru/post/333002/

## 2. Практика

Создаем новый .cpp файл.  

> Рекомендую всегда создавать новые .cpp файлы для каждого урока (чтобы не потерять ваши первые задания, так вам будет легче подготовиться к экзаменам), и просто исключить предыдущий .cpp файл из сборки проекта, не удаляя его. Это можно сделать в свойствах. И можем приступать к выполнению следующих шагов.

```
// Включаем стандартный заголовок
#include <GL/freeglut.h>
#include <GL/glew.h>
```

```
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(512, 512);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);

	glewInit();

	myInit();

	glutDisplayFunc(myDisplay);

	glutMainLoop();
	return 0;
}
```



# Библиотеки

https://www.transmissionzero.co.uk/software/freeglut-devel/	"freeglut 3.0.0 MSVC Package"

 https://sourceforge.net/projects/glew/files/glew/2.1.0/  "glew-2.1.0-win32"

# Источники

1) https://ravesli.com/uroki-po-opengl/	"Уроки по OpenGL"

2) http://pmg.org.ru/nehe/	"Работа с OpenGL"

3) https://habr.com/ru/post/310790/ "learnopengl"

4) https://github.com/triplepointfive/ogldev "Туториалы по OpenGL"
