#ifndef __GPUINFO_H__
#define __GPUINFO_H__

class GPUInfo
{
  public:
  static const unsigned char* getName();
  static const unsigned char* getVendor();
  static const unsigned char* getOpenGLVersion();
  static const unsigned char* getGLSLVersion();
  static const int getMaxTextureSize();
};

#endif // __GPUINFO_H__