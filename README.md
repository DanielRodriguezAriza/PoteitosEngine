# Poteitos Engine

## Introduction
Welcome to the Poteitos Engine repository.
This project is a very simple game engine built using C++, Legacy OpenGL and FreeGlut, built for an university class project.
The purpose of this project was to attempt building a game engine from scratch and a game in said engine.
Future versions of the engine will be implemented with modern OpenGL and actual shader programming to achieve better results and implement more complex features.

## Features
- **Math Utilities:** A simple namespace with templated mathematical utility functions such as lerp and clamp.
- **Random Utility:** A simple namespace with functions to generate random integer and floating point numbers.
- **Console Utilities:** Simple templated printing functions that can pass information to C++ streams (std::ostream&).
- **Vector3D:** A templated Vector class that implements operators to perform all the basic vector operations required to define vectors and points in 3D space.
- **Glut Text Objects:** Wrapper Text object that allows placing text on the world space with both bitmaps and strokes.
- **OBJ support:** The class ModelLoader supports reading simplified OBJ files that dont contain UV data.
- **Material index support:** The class ColorLoader supports reading the color data from simple plain colored materials stored in MTL files to apply it to 3D models loaded in the scene.
- **Multiple Scenes:** Support for creating and handling multiple scenes where game objects can be stored. Multiple scenes can be activated at the same time.
- **Game Controllers:** Implementation of classes for input definition and creation of controllers that allow the user to manipulate game objects through keyboard and mouse input.
- **Delta Time:** The engine implements variable timestepped updates implemented through delta time.
- **Level Data:** Support for storing level data. Can be loaded from files or written directly on source files.
- **Level Manager:** A class that manages level transitions.
- **Simple Collision Support:** Support for collisions and interactions between all game objects. There are options to change the collision radius, collision behavior and to enable and disable collisions per object.
- **etc...**

## Installation
The project is implemented in Visual Studio using C++. No, I did not use Visual Studio by choice, this was a requirement for my class. I do not enjoy pain, I swear.
To get started with Poteitos Engine, follow these installation steps:

1. Download Visual Studio
2. Open the Solution
3. Profit

The project files can be downloaded and compiled manually if you dislike using IDEs as much as I do. Just make sure you link opengl and glut.
Just beware of the damned system call in the main file: system("chcp 65001>nul"); it should not generate any errors on operating systems that are not Windows, as it is piped to nul, but this system call only exists with the express purpose of adding ANSI escape sequence support to the command prompt so that the utility functions can look cooler. In any case, delete that line of code if you want to run this on an operating system that is not windows.

## Usage
Once you have installed the project, you can begin using the simple classes implemented in the Poteitos Engine to create your own game logic.
The game itself is implemented in the Game.h and Game.cpp files, which is where you will find the example game that was built with Poteitos Engine.

All the objects can be initialized either by using new or allocating enough memory for them.
