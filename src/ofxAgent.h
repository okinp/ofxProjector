/*
 *  ofxAgent.h
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/5/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#ifndef _OFX_AGENT_
#define _OFX_AGENT_

#include "ofxPath.h"

class ofxAgent  {
public:
	ofxPath x, y, z;
	ofxPath t;
	float first, now, last;
	ofxPath red, green, blue;
	ofxPath alpha;
	ofxPath xRot, yRot, zRot;
	float value;
	ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue, ofxPath _alpha, ofxPath _xR, ofxPath _yR, ofxPath _zR);
	ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue, ofxPath _alpha);
	ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue);
	ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t);
	float clock(float now);
	void update(float n);
	float eval();
	void locate();
	void jitter(float d);
	void jumble(float d);
	void arc(float r);
	float proximity(ofxPath _x, ofxPath _y, ofxPath _z);
	float proximity(ofxPath _x, ofxPath _y);
	float ease( float n, float o, float e );
};
#endif


