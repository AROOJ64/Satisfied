#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Menu {

	int Selected;
	Font font;

public:

	Text MainMenu[2];
	Menu(float width, float height, const Font& font);
	~Menu();
	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();
	void setSelected(int n);
	int pressed() { return Selected; }

};

