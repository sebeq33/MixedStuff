#include "HandlerOpus.hh"

HandlerOpus::HandlerOpus(int sampleRate, int numChan)
{
  opus_int32 rate;

  this->enc = opus_encoder_create(sampleRate, numChan, OPUS_APPLICATION_VOIP, &this->error);
  this->dec = opus_decoder_create(sampleRate, numChan, &this->derror);
  this->numChan = numChan;

  /*std::cout << "Creation de la structure de encodage " << opus_strerror(error) << std::endl;
    std::cout << "Creation de la structure de decodage " << opus_strerror(derror) << std::endl;*/

  opus_encoder_ctl(this->enc, OPUS_GET_BANDWIDTH(&rate));
  this->maxDataBytes = rate;
  //std::cerr << "maxDataBytes : " << this->maxDataBytes;
}

HandlerOpus::~HandlerOpus()
{
  opus_encoder_destroy(this->enc);
  opus_decoder_destroy(this->dec);
}

void HandlerOpus::encodeFrame(unsigned char **sampleChar, const float *frame, int frameSize)
{
  int ret;

  ret = opus_encode_float(this->enc,
			  frame,
			  frameSize,
			  *sampleChar,
			  maxDataBytes);
  /*std::cout << "Encodage : " << ret << std::endl;
    std::cout << "Erreur encodage : " << opus_strerror(ret) << std::endl;*/
}

void HandlerOpus::decodeFrame(float **sampleFloat, const unsigned char *data, int frameSize)
{
  int ret;

  /*std::cout << "Nombre de samples total : " << opus_decoder_get_nb_samples(this->dec, data, 4000) << std::endl;
  std::cout << "Nombre de frames total : " << opus_packet_get_nb_frames(data, 4000) << std::endl;
  std::cout << "Bande passante : " << opus_packet_get_bandwidth(data) << std::endl;*/
  ret = opus_decode_float(this->dec,
			  data,
			  maxDataBytes,
			  *sampleFloat,
			  frameSize,
			  0);
  /*std::cout << "Decodage : " << ret << std::endl;
    std::cout << "Erreur decodage : " << opus_strerror(ret) << std::endl;*/
}
