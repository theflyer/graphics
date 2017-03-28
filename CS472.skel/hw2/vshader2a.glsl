#version 120

attribute vec2 a_Position;	// attribute variable
uniform	mat4 u_Projection;	// uniform variable for passing projection matrix

void main()
{
	// PUT YOUR CODE HERE
    gl_PointSize = 5.0; // for increasing size of point
    gl_Position = u_Projection * vec4(a_Position, 0, 1);
}
