#ifndef HANDLER_OPUS_H_
# define HANLDER_OPUS_H_

#include <iostream>
#include <opus/opus.h>

class HandlerPortAudio;

class HandlerOpus
{
  int numChan;
  OpusEncoder *enc;
  OpusDecoder *dec;
  opus_int32 maxDataBytes;
  int error;
  int derror;
public:
  HandlerOpus(int sampleRate, int numChan);
  ~HandlerOpus();
  void encodeFrame(unsigned char **sampleChar, const float *frame, int frameSize);
  void decodeFrame(float **sampleFloat, const unsigned char *data, int frameSize);
  void displayError(int ret);
};

#endif /* !HANLDER_OPUS_H_ */
