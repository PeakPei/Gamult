#ifndef FADER_H
#define FADER_H

#include "ofMain.h"

class Fader {

public:

    Fader(string title);
    void setDimensions(int x0, int y, int size, bool first);

    void draw();
    float getValue();
    void setValue(float value);
    void resetFader() { this->rect.x = this->x0+range/2-size/2; }
    void setTitle(string title) { this->title = title; }

    void touchDown(ofTouchEventArgs& event);
    void touchMoved(ofTouchEventArgs& event);
    void touchUp(ofTouchEventArgs& event);

private:

    int x0;              // the inital position of the fader in the full window
    int y;               // the y position of the fader (is constant all the time)
    int stringOrigin;    // the x point from which to draw the string
    ofRectangle rect;    // the rectangle of the fader itself
    ofTrueTypeFont font;
    string title;
    int size;            // size in pixels of the square of the fader
    int range;           // range in pixels of the line in which the fader moves
    int id;              // the id of the touch to which this fader is locked

};

#endif
