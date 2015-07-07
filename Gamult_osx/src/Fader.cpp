#include "Fader.h"
#include "ofApp.h"

Fader::Fader(float x0, float y, int size, int range, string title) {
    
    this->x0 = x0;
    this->y = y;
    this->size = size;
    this->range = range;
	this->title = title;
    
    this->id = -1; // -1 means there is no touch associated
	
    this->rect = ofRectangle(x0+range/2-size/2, y-size/2, size, size);

	font.loadFont(UI_FONT_FACE, UI_FONT_SIZE, true);

	ofAddListener(ofEvents().touchDown,  this, &Fader::touchDown);
	ofAddListener(ofEvents().touchMoved, this, &Fader::touchMoved);
	ofAddListener(ofEvents().touchUp,    this, &Fader::touchUp);
	
}

void Fader::touchDown(ofTouchEventArgs& event) {
    if (id == -1 && rect.inside(event.x, event.y)) {
        id = event.id;
    }
}

void Fader::touchUp(ofTouchEventArgs& event) {
    if (event.id == id){
        id = -1;
    }
}

void Fader::touchMoved(ofTouchEventArgs& event) {

	// make sure that only updates fader position if first click was inside it
	if (event.id == id) {

		rect.setX(event.x);
	
		if (rect.x < x0 - size/2)
			rect.x = x0 - size/2;
		
		if (rect.x > x0 + range - size/2)
			rect.x = x0 + range - size/2;
	}
}

float Fader::getValue() {
	return ofMap(rect.x, x0-size/2, x0+range-size/2, 0, 2);
}

void Fader::draw() {
    
	ofSetColor(UI_COLOR);

	// draw the line in which the fader moves
	ofLine(x0, y, x0+range, y);

	ofLine(x0+range/2, y-size/2, x0+range/2, y+size/2);

	// draw the fader
	ofRect(rect);
    
	font.drawString(title, x0, y+size*2);

}