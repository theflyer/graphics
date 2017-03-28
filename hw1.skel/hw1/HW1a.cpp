// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2017 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2017
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);// PUT YOUR CODE HERE
    glColor3f(1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{

    m_winH = h;
    m_winW = w;
   
    float asr = (float) m_winW/m_winH;
    
    float xmax;
    float ymax;
    
    if (asr> 1.0){
        xmax = asr;
        ymax = 1.0;
        
    }else {
        xmax = 1.0;
        ymax = 1/asr ;
        
    }
    
    glViewport(0.0, 0.0, m_winW, m_winH);
    glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
    glOrtho(-xmax,xmax, -ymax, ymax, -1.0, 1.0);
    
    /*
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   
*/
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
    
    
    int w2 = m_winW/3;
    int h2 = m_winH/3;


    glClear(GL_COLOR_BUFFER_BIT);

    for( int i = 0 ; i< 9 ; i++){
        
    glViewport(((i%3)*w2), (i/3)*h2, w2, h2);
    // i%3 is to place three components in each row
    // i/3 is to place three compoents in each column
        
    glBegin(DrawModes[i]);
    for (int k = 0 ; k<32; k++){
        
        int m = k+1;
        glVertex2f(Vertices[k], Vertices[m]);
        k++;
        
    }
    glEnd();
    glFlush();
    
    }
    
    
    
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}
