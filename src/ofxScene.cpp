/*
 *  ofxScene.cpp
 *  ofPresentor
 *
 *  Created by Nikolas Psaroudakis on 10/3/10.
 *  Copyright 2010 New York University. All rights reserved.
 *
 */

#include "ofxScene.h"

/**
 *
 *  Scenes are like bulkier Agents,
 *  so much bulkier that they may contain child Scenes!
 *  This class doesn't get used directly
 *  Instead it gets extended by actual "scenes"
 *  Subtle, but very powerful !  (Hopefully)
 *
 */



ofxScene::ofxScene( ofxPath  _x, ofxPath  _y, ofxPath  _z, ofxPath  _t, ofxPath _alpha, ofxPath _xR, ofxPath _yR, ofxPath _zR){
	super( _x, _y, _z, _t, new Path( 255 ), new Path( 255 ), new Path( 255 ), _alpha, _xR, _yR, _zR );
	ready  = false;
	scenes = new ArrayList();
	name   = this.getClass().getName();
	String[] temp = splitTokens( name, "$" );
	name   = temp[ temp.length - 1 ];
};
ofxScene::ofxScene( Path _x, Path _y, Path _z, Path _t, Path _alpha )
{
	this( _x, _y, _z, _t, _alpha, new Path( 0 ), new Path( 0 ), new Path( 0 ));
};
ofxScene::ofxScene( Path _x, Path _y, Path _z, Path _t )
{
	this( _x, _y, _z, _t, new Path( 255 ), new Path( 0 ), new Path( 0 ), new Path( 0 ));
};
void ofxScene::setup()
{
	println( "> '" + name + "' is loading." );
	ready = true;
};
void ofxScene::update( float n )
{
	super.update( clock( n ));
	
	Iterator it = scenes.iterator();
	while( it.hasNext() )
	{
		Scene s = (Scene) it.next();
		s.update( t.now );
	};
};
void ofxScene::draw()
{
	for( int i = scenes.size() - 1; i >= 0; i -- )
	{
		Scene s = (Scene) scenes.get( i );
		if( s.eval() > 0 )
		{
			if( !s.ready ) s.setup();
			else println( "> '" + s.name + "' finished loading." );	
		};
		if( s.eval() >= 1 )
		{
			
			//  Unload Scenes on Completion
			
			println( "> '" + s.name + "' has completed its timeline." );
			String temp = s.name;
			scenes.remove( s );
			println( "> '" + temp + "' has been removed." );
		};
	};
};