#version 410 core
uniform Uniforms{
	vec3 translation;
	float scale;
	vec4 rotation;
	bool enabled;
};
in vec2 vPos;
in vec3 vColor;
out vec4 fColor;
void main()
{
	vec3 pos = vec3(vPos,0.0);
	vec3 temp;
	float angle = radians(rotation[0]);
	vec3 axis = normalize(rotation.yzw);
	mat3 I = mat3(1.0);
	mat3 S = mat3(0,-axis.z,axis.y,
				  axis.z,0,-axis.x,
				  -axis.y,axis.x,0);
	mat3 uuT = outerProduct(axis,axis);
	mat3 rot = uuT + cos(angle)*(I-uuT) + sin(angle)*S;
	pos *= scale;
	angle = 10;
	temp.x = vPos.x*cos(angle) + vPos.y*sin(angle);
	temp.y = vPos.x*sin(angle) - vPos.y*cos(angle);
	pos.x = temp.x;
	pos.y = temp.y;

	fColor = vec4(scale,scale,scale,1);

	gl_Position = vec4(pos,1);
}