/*
 *  ofxScene.h
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/3/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

/**
 *
 *  Scenes are like bulkier Agents,
 *  so much bulkier that they may contain child Scenes!
 *  This class doesn't get used directly
 *  Instead it gets extended by actual "scenes"
 *  Subtle, but very powerful !  (Hopefully)
 *
 */
#ifndef _SCENE_
#define _SCENE_ 

#include "ofxAgent.h"
#include "ofxPath.h"
#include <vecotr>
#include <string>

class ofxScene : public ofxAgent {
    std:vector< ofxScene> scenes;	//  Children of this Scene
	boolean ready;					//  Have we run Setup() yet?
	String name;					//  This Scene's Name
	Scene( ofxPath  _x, ofxPath  _y, ofxPath  _z, ofxPath  _t, ofxPath _alpha, ofxPath _xR, ofxPath _yR, ofxPath _zR);
	Scene( Path _x, Path _y, Path _z, Path _t, Path _alpha );
	Scene( Path _x, Path _y, Path _z, Path _t );
	void setup();
	void update( float n );
	void draw();
};
#endif