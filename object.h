#include "F:\myownlibforopengl\include\include.h"

class Object
{
protected:
	GLuint ID;
public:
	virtual void bind(){ }
	virtual void nbind() = 0;
	GLuint id() { return ID; }
};

class Vao:public Object
{
public:
	Vao();
	~Vao();
	void bind();
	void nbind();
};

class Veboabc :public Object
{
protected:
	Veboabc();
	virtual ~Veboabc() = 0;
	virtual void bind(GLenum);
	virtual void nbind(GLenum);
	virtual void adddata(GLenum mode1,size_t size, const GLvoid * data, GLenum mode2);
};

class Vbo :public Veboabc
{
public:
	Vbo();
	~Vbo();
	void bind();
	void nbind();
	void adddata(size_t size, const void * data, GLenum mode);
};

class Ebo :public Veboabc
{
public:
	Ebo();
	~Ebo();
	void bind();
	void nbind();
	void adddata(size_t size, const void * data, GLenum mode);
};

enum { D1 = GL_TEXTURE_1D, D2 = GL_TEXTURE_2D, D3 = GL_TEXTURE_3D };

class Texture:public Veboabc
{
private:
	GLenum d;
public:
	GLsizei width;
	GLsizei height;
	GLint number_channels;
	Texture();
	~Texture();
	void bind();
	void bind(GLenum d_);
	void nbind();
	void adddata(GLint level,GLint internalformat,GLenum format,GLenum type,const unsigned char data[]);
};