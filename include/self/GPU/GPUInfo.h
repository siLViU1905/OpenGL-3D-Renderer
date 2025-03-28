#ifndef __GPUINFO_H__
#define __GPUINFO_H__

class GPUInfo
{
  public:
  const unsigned char* getName();
  const unsigned char* getVendor();
  const unsigned char* getVersion();
  const unsigned char* getGLSLVersion();
  const int getMaxTextureSize();
};

#endif // __GPUINFO_H__