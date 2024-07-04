#include "F:\myownlibforopengl\include\object.h"

void Vao::bind()
{
	glBindVertexArray(ID);
}

Vao::Vao():Object()
{
	glGenVertexArrays(1, &ID);
}

void Veboabc::bind(GLenum mode)
{
	glBindBuffer(mode, ID);
}

void Veboabc::adddata(GLenum mode1,size_t size, const GLvoid * data, GLenum mode2)
{
	glBufferData(mode1, size, data, mode2);
}

Veboabc::Veboabc():Object()
{
	glGenBuffers(1, &ID);
}

void Vao::nbind()
{
	glBindVertexArray(0);
}

void Veboabc::nbind(GLenum mode)
{
	glBindBuffer(mode, 0);
}

Vao::~Vao()
{
	glDeleteVertexArrays(1, &ID);
}

Veboabc::~Veboabc()
{
	glDeleteBuffers(1, &ID);
}

Vbo::Vbo():Veboabc(){ }

Vbo::~Vbo()
{
	Veboabc::~Veboabc();
}

void Vbo::bind()
{
	Veboabc::bind(GL_ARRAY_BUFFER);
}

void Vbo::nbind()
{
	Veboabc::nbind(GL_ARRAY_BUFFER);
}

void Vbo::adddata(size_t size, const void * data, GLenum mode)
{
	Veboabc::adddata(GL_ARRAY_BUFFER, size, data, mode);
}

Ebo::Ebo() :Veboabc() { }

Ebo::~Ebo()
{
	Veboabc::~Veboabc();
}

void Ebo::bind()
{
	Veboabc::bind(GL_ELEMENT_ARRAY_BUFFER);
}

void Ebo::nbind()
{
	Veboabc::nbind(GL_ELEMENT_ARRAY_BUFFER);
}

void Ebo::adddata(size_t size,const void * data, GLenum mode)
{
	Veboabc::adddata(GL_ELEMENT_ARRAY_BUFFER, size, data, mode);
}

Texture::Texture():Veboabc()
{
	glGenTextures(1, &ID);
}

Texture::~Texture()
{

}

void Texture::bind()
{
	glBindTexture(d, ID);
}

void Texture::bind(GLenum d_)
{
	glBindTexture(d_, ID);
	d = d_;
}







void Texture::nbind()
{
	glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::adddata(GLint level, GLint internalformat, GLenum format, GLenum type, const unsigned char data[])
{
	if (d == GL_TEXTURE_1D)
		;//glTexImage1D(d, level, internalformat, width, height, 0, format, type, data);
	else if (d == GL_TEXTURE_2D)
		glTexImage2D(d, level, internalformat, width, height, 0, format, type, data);
	else
		;//glTexImage3D(d, level, internalformat, width, height, 0, format, type, data);
}