/*
 *  ofxWebView.h
 *  WebView
 *
 *  Created by Andreas Borg on 06/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 *   Proof od concept
 *   http://forum.openframeworks.cc/t/using-cef-with-of/18094/15
 *  Font rendering not so crips in texture grab...room for improvement.
 *  Also not tested with passing javascript
 */

#ifndef _ofxWebView
#define _ofxWebView

#include "ofMain.h"
#include "ofAppGLFWWindow.h"
#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

class WebViewEvent : public ofEventArgs {
    
public:
    
    WebViewEvent(){};
    string URL;
   
};

class ofxWebView : public ofRectangle {
	
  public:
	
	ofxWebView();
    ~ofxWebView();
    
    void loadURL(string url);
    void loadFile(string file, bool relativeToData = true);//local html
    void setHTML(string htm,string base="");
    
    void toTexture(ofTexture *tex);
    
    void setSize(int w, int h);
    ofRectangle getSize();
    void setPosition(int x, int y);
    
    void setDrawsBackground(bool b);
    bool getDrawBackground();
    
    ofEvent <WebViewEvent> LOAD_URL;
    
    bool getAllowPageLoad();
    void setAllowPageLoad(bool s);
    
    string getLastLoadFileUrl();
    
    string inject(string jsCode);
    
protected:
    string jsCode = "";
    void setWebViewFrame(ofRectangle frame);
    
    bool _allowPageLoad;
    bool _drawBg;
    
    //WebListener *webListener;
    WebView * webView;
    NSWindow * window;
    
    string lastLoadFileUrl;
};

#endif
