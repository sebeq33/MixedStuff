#ifndef IAUDIO_HH_
# define IAUDIO_HH_

class IPortAudio
{
public:
  virtual ~IPortAudio() {}
  
  virtual void startStream() = 0;
};

#endif /* !IAUDIO_HH_ */
