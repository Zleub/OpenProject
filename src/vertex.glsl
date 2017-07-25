#version 410

layout(location = 0) in vec3 vPos;
// out vec3 color;

void main()
{
	// color = vec3(1., 0., 0.);
	gl_Position = vec4(vPos, 1.);
}
