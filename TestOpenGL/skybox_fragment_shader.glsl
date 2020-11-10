#version 440

in vec3 vs_texcoord;

out vec4 fs_color;

//Uniforms
uniform samplerCube skybox;

void main()
{
	fs_color = texture(skybox, vs_texcoord);
}