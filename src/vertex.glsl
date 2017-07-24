#version 410

in vec3 vPos;
out vec3 color;

void main()
{
	color = vec3(1., 1., 1.);

	gl_Position = vec4(vPos, 1.);
}
