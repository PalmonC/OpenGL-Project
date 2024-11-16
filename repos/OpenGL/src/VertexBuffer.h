#pragma once

class VertexBuffer {
private:
	// an unique id for each variable such as vertex array object, shader, uniform, vertex... 
	unsigned int m_RenderID;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};