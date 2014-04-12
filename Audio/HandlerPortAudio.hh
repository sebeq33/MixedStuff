#ifndef HANDLER_PORTAUDIO_H_
# define HANDLER_PORTAUDIO_H_

#include <iostream>
#include <stdlib.h>
#include <portaudio.h>
#include "IAudio.hh"
#include "HandlerOpus.hh"

class HandlerOpus;

class HandlerPortAudio : public IPortAudio
{
  PaStream *stream;
  unsigned char *sampleChar;
  float *sampleFloat;
  int rate;
  int frames;
  int numChan;
  bool flagStream;
  const PaSampleFormat sampleFormat;
  const int sampleSize;
  HandlerOpus opus;
  PaStreamParameters in;
  PaStreamParameters out;

  void initInput();
  void initOutput();
public:
  HandlerPortAudio();
  ~HandlerPortAudio();
  void startStream();
  void stopStream();
  const int getRate() const;
  const int getNumChan() const;
};

#endif /* !HANDLER_PORTAUDIO_H_ */
