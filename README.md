# Airplane Simulator in 3D
This project aims to create an Airplane Simulator - a game that simulate an airplane flying over a city in 3D.

First, make sure you have installed:
```
sudo apt-get install libsdl2-dev;
sudo apt-get install libsdl2-mixer-dev;
sudo apt-get install libsdl-mixer1.2-dev;
sudo apt-get install libsoil-dev;
sudo apt-get install freeglut3-dev;
sudo apt-get install libglew-dev;
```

# Overview
This game is a flight simulator in 3D that must be controlled using WASD keys. In this game, you can land in a special place (a landing track), change the cameras (1st person, 3rd person and 2D cameras), activate a fog and activate the light.

![Captura de Tela 2019-05-14 às 22 46 32](https://user-images.githubusercontent.com/49728258/57743131-479ca480-769a-11e9-8d56-486d16d9a083.png)
# Controls

- 1 key: 2D Camera;
- 2 key: Third Person Camera;
- 3 key: First Person Camera;
- W key: Move forward;
- A key: Move to the left;
- S key: Move back;
- D key: Move to the right;
- L key: Light (ON/OFF);
- N key: Fog (ON/OFF);
- P key: Land (Specific area);
- ESC key: Quit.

# What I used to make this game?

- OpenGL 3.0;
- Files with .obj extension;
- Display Lists;
- Sound effects (using SDL_mixer);
- Autonomous objects (birds and the propeller of the windmill);
- Mouse movement (The airplane is controlled like a FPS game);
- Basic knowledge in Computer Graphics.
