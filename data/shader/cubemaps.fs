#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
    mat3 TBN;
} fs_in;

uniform sampler2D texture1;
uniform sampler2D normalMap;

uniform vec3 lightPos;
uniform vec3 lightColor;

void main()
{
    vec3 objectColor = texture(texture1, fs_in.TexCoords).rgb;  // 从纹理图片中获取片段的颜色

    vec3 normal;
    normal=texture(normalMap, fs_in.TexCoords).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    normal = normalize(fs_in.TBN * normal);

    // 环境光照
    float ambientStrength=0.1;
    vec3 ambient=ambientStrength*lightColor;
    // 漫反射
    vec3 lightDir=normalize(lightPos-fs_in.FragPos);
    float diff=max(dot(normal, lightDir),0.0);
    vec3 diffuse=diff*lightColor;

    vec3 result=(ambient+diffuse)*objectColor;
    FragColor=vec4(result, 1.0f);

}