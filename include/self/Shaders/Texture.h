#ifndef __TEXTURE_H__
#define __TEXTURE_H__

class Texture
{
    unsigned int ID;
    int width,height,nrChannels;
    public:
    Texture();

    bool load(const char* filepath);

    void bind(unsigned int textureU = 0) const;

    static void unbind();

    unsigned int getID() const;

    ~Texture();
};

#endif // __TEXTURE_H__