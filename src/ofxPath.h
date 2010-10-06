/*
 *  ofxPath.h
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/3/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

/*
 *
 *  Paths describe any linear transition.
 *  It could be distance, time, etc.
 *  You can make it non-linear later by using eval()
 *  and patching that value into something else
 *  like a Sigmoid function or Robert Penner's Easing.
 *
 */

#ifndef _PATH_
#define _PATH_

class ofxPath
{
public:
	float first;     //  Start from this point
	float last;      //  End at this point
	float now;       //  Where we are now
	float previous;  //  Where we were just before now; convenience variable
	float range;     //  Total range of this Path
	float delta;     //  Distance covered so far on this Path
	
	
	ofxPath( float _first, float _last );
	ofxPath( float _first );
	float predict( float n );
	void update( float n );
	float eval();
	void shift( float n );
	void wrap( float a, float b );	
};
#endif