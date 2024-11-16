#include "Renderer.h"
#include <iostream>
void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* func, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OPENGL Error] (" << error << ")- " << func << " in - " << file << " at line: " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const IndexBuffer& ib, const VertexArray& vao, const Shader& shader)
{
    shader.Bind();
    vao.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

}
