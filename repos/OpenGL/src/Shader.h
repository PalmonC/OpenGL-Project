#pragma once
#include <string>
#include <unordered_map>

struct ShaderSource
{
	std::string VertexShader;
	std::string FragmentShader;
};

class Shader {
private:
	std::string m_Filepath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
	// caching for uniforms
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void UnBind() const;
	// set Uniform
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	unsigned int CompileShader(const std::string& source_shader, unsigned int type);
	unsigned int CreateShader(const std::string& vertex_shader, const std::string& fragment_shader);
	ShaderSource ParseShader(const std::string& path_file);

	int GetUniformLocation(const std::string& name);
};
