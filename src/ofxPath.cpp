/*
 *  ofxPath.cpp
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/3/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#include "ofxPath.h"

/**
 *
 *  Paths describe any linear transition.
 *  It could be distance, time, etc.
 *  You can make it non-linear later by using eval()
 *  and patching that value into something else
 *  like a Sigmoid function or Robert Penner's Easing.
 *
 */



ofxPath::Path( float _first, float _last )
{
	first    = _first;
	last     = _last;
	now      =  first;
	previous =  first;
	range    =  abs( last - first );
	delta    =  0f;
}
ofxPath::ofxPath( float _first )
{
	this( _first, _first );
}
float ofxPath::predict( float n )
{
	//  We are expecting that 0 =< n =< 1
	//  this is the inverse of eval()
	// "predict()" doesn't update any values, however
	//  so we can ask where something might have been
	//  by sending a "n" that is not "n.now".
	
	n = constrain( n, 0.0, 1.0 );
	
	//  Subtle, but we definitely want "last - first" here
	//  and not "range" which is an absolute value.
	
	return n * ( last - first ) + first;
}

void ofxPath::update( float n )
{
	//  We are expecting that 0 =< n =< 1.
	//  Uses "predict()"
	//  but then also updates our values.
	
	range    = abs( last - first );
	previous = now;
	now      = predict( n );
	delta    = now - first;
}


float ofxPath::eval()
{
	//  We are returning 0 =< n =< 1
	//  this is the inverse of predict().
	
	return ( now - first ) / ( last - first );
}


void ofxPath::shift( float n )
{
	//  Shift entire Path by n.
	
	first    += n;
	previous += n;
	now      += n;
	last     += n;
}

void ofxPath::wrap( float a, float b )
{
	//  Expecting a range where
	// 'a' is the lower bound
	//  and 'b' is the upper bound.
	//  Currently not "shifting" all values
	//  just updating the "now".
	
	float min = min( a, b );
	float max = max( a, b );
	if( now < min ) now += max - min;
	if( now > max ) now -= max - min;
}