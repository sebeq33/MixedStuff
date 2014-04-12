#include "HandlerPortAudio.hh"

HandlerPortAudio::HandlerPortAudio()
  : stream(NULL)
  , sampleChar(NULL)
  , sampleFloat(NULL)
  , rate(24000)
  , frames(480)
  , numChan(1)
  , flagStream(false)
  , sampleFormat(paFloat32)
  , sampleSize(4)
  , opus(rate, numChan)
{
  if (Pa_Initialize() != paNoError)
    std::cerr << "Error with Pa_Initialize" << std::endl;

  sampleFloat = new float[frames * numChan * sizeof(float)];
  if (sampleFloat == NULL)
    std::cerr << "Could not allocate record array." << std::endl;
  sampleChar = new unsigned char[4000];
  if (sampleChar == NULL)
    std::cerr << "Could not allocate record array." << std::endl;

  initInput();
  initOutput();
}

HandlerPortAudio::~HandlerPortAudio()
{
  stopStream();
  if (sampleFloat)
    free(sampleFloat);
  Pa_Terminate();
}

void HandlerPortAudio::initInput()
{
  const PaDeviceInfo *info;

  in.device = Pa_GetDefaultInputDevice();
  info = Pa_GetDeviceInfo(in.device);
  in.channelCount = numChan;
  in.sampleFormat = sampleFormat;
  if (info != NULL)
    in.suggestedLatency = info->defaultHighInputLatency;
  in.hostApiSpecificStreamInfo = NULL;
}

void HandlerPortAudio::initOutput()
{
  const PaDeviceInfo *info;

  out.device = Pa_GetDefaultOutputDevice();
  info = Pa_GetDeviceInfo(out.device);
  out.channelCount = numChan;
  out.sampleFormat = sampleFormat;
  if (info != NULL)
    out.suggestedLatency = info->defaultHighOutputLatency;
  out.hostApiSpecificStreamInfo = NULL;
}

void HandlerPortAudio::startStream()
{
  PaError error;

  error = Pa_OpenStream(&stream,
			&in,
			&out,
			rate,
			frames,
			paClipOff,
			NULL,
			NULL);
  if (error != paNoError)
    std::cerr << "Error with Pa_OpenStream" << std::endl;
  if (Pa_StartStream(stream) != paNoError)
    std::cerr << "Error with Pa_StartStream" << std::endl;
  flagStream = true;
  while (flagStream && stream)
    {
      Pa_WriteStream(stream, sampleFloat, frames);
      opus.encodeFrame(&sampleChar, sampleFloat, frames);
      opus.decodeFrame(&sampleFloat, sampleChar, frames);
      Pa_ReadStream(stream, sampleFloat, frames);
    }
}

void HandlerPortAudio::stopStream()
{
  if (stream)
    {
      flagStream = false;
      Pa_StopStream(stream);
      Pa_AbortStream(stream);
      Pa_CloseStream(stream);
    }
}

const int HandlerPortAudio::getRate() const
{
  return (rate);
}

const int HandlerPortAudio::getNumChan() const
{
  return (numChan);
}
