#version 450 core

in vec2 TexCoord; // 从顶点着色器接收的纹理坐标

out vec4 FragColor; // 输出片段颜色

uniform sampler2D texture1; // 我们的纹理采样器

void main()
{
    FragColor = texture(texture1, TexCoord); // 使用纹理坐标从纹理中采样颜色
}
