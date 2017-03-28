#version 330

in	vec2	a_Position;	// attribute variable: position vector
in	vec3	a_Color;	// attribute variable: color vector

out	vec4	v_Color;	// varying variable for passing color to fragment shader

uniform	mat4	u_Modelview;	// uniform variable for passing modelview  matrix
uniform	mat4	u_Projection;	// uniform variable for passing projection matrix
uniform	float	u_Theta;	// Theta parameter
uniform	int	u_Twist;	// Twist flag

void main()
{
  float d ;
    
  if (u_Twist == 1){// PUT YOUR CODE HERE
      d= sqrt((a_Position.x* a_Position.x) + (a_Position.y*a_Position.y));
  }
   
else{
     d = 1.0;
}
    float sintheta = sin(d*u_Theta);
    float costheta = cos(d*u_Theta);
    //gl_Position = u_Modelview * u_Projection * vec4(a_Position,0,1);
       gl_Position = u_Projection * u_Modelview * vec4((a_Position.x * costheta) - (a_Position.y * sintheta),(a_Position.x * sintheta) + (a_Position.y * costheta), 0, 1);

    //gl_Position = u_Modelview * u_Projection * vec4(a_Position,0,1);
    v_Color = vec4(a_Color,1);


}
