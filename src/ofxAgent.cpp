/*
 *  ofxAgent.cpp
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/5/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#include "ofxAgent.h"
ofxAgent::ofxAgent::ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue, ofxPath _alpha, ofxPath _xR, ofxPath _yR, ofxPath _zR)
{
	x     = _x;
    y     = _y;
    z     = _z;
	
    t     = _t;
    first = t.first;
    now   = t.now;
    last  = t.last;
	
    red   = _red;
    green = _green;
    blue  = _blue;
    alpha = _alpha;
	
    xR    = _xR;
    yR    = _yR;
    zR    = _zR;
}
ofxAgent::ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue, ofxPath _alpha)
{
	ofxAgent( _x, _y, _z, _t, _red, _green, _blue, _alpha, ofxPath( 0 ), ofxPath( 0 ), ofxPath( 0 ));
}
ofxAgent::ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t, ofxPath _red, ofxPath _green, ofxPath _blue)
{
	ofxAgent( _x, _y, _z, _t, _red, _green, _blue, ofxPath( 255 ));
}
ofxAgent::ofxAgent( ofxPath _x, ofxPath _y, ofxPath _z, ofxPath _t)
{
	ofxAgent( _x, _y, _z, _t, new Path( 255 ), new Path( 255 ), new Path( 255 ));
}
float ofxAgent::clock(float now)
{
	if (t.last!= t.first) {
		return ( now - t.first ) / ( t.last - t.first );
	} else {
		return 0;
	}
	
}
void ofxAgent::update( float n )
{
	//  We are expecting that 0 =< n =< 1
	//  Passes this on to individual Paths
	
	x.update( n );
	y.update( n );
	z.update( n );
	
	t.update( n );
	first = t.first;
	now   = t.now;
	last  = t.last;
	
	red.update(   n );
	green.update( n );
	blue.update(  n );
	alpha.update( n );
	
	xR.update( n );
	yR.update( n );
	zR.update( n );
}

float ofxAgent::eval()
{
    //  Convenience method
    //  Returns the time Path's progress
    //  on a scale of 0 to 1
	
    return t.eval();
};


void ofxAgent::locate()
{
    translate( x.now, y.now, z.now );
    rotateX( radians( xR.now ));
    rotateY( radians( yR.now ));
    rotateZ( radians( zR.now ));
};


void ofxAgent::jitter( float d )
{
    float r = d / 2;
    x.now += random( -r, r );
    y.now += random( -r, r );
    z.now += random( -r, r );
};


void ofxAgent::jumble( float d )
{
    //  This method is like a smoothed version of jitter()
    //  but the agents will loose their original X, Y
    //  so a map could deform very quickly, use with caution.
    
    //  You mighy try using Perlin Noise instead.
	
    float r = d / 2f;
    x.shift( random( -r, r ) );
    y.shift( random( -r, r ) );
    z.shift( random( -r, r ) );
};


void ofxAgent::arc( float r )
{
    float scaled = x.eval();
    float yShift = abs( sin( scaled * PI ) ) * r;
    y.now = y.now - yShift;
};


float ofxAgent::proximity( float _x, float _y, float _z )
{
    return dist( x.now, y.now, z.now, _x, _y, _z );
};
float ofxAgent::proximity( float _x, float _y )
{
    return dist( x.now, y.now, _x, _y );
};


float ofxAgent::ease( float n, float o, float e )
{
    //  This function works correctly
    //  but if we use it in the move() method
    //  it breaks our strict binding of 
    //  a time value to a point along a path.
	
    //  You might try using Robert Penner's Easing instead.
	
    float d;
    d = o + (n - o) / e;
    return d;
};