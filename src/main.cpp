#include "AudioTools.h"
#include "AudioTools/AudioCodecs/CodecMP3Helix.h"
#include "AudioTools/AudioLibs/AudioBoardStream.h"

URLStream url("ssid","password");  // or replace with ICYStream to get metadata
AudioBoardStream i2s(AudioKitEs8388V1); // final output of decoded stream
MP3DecoderHelix mp3;
EncodedAudioStream dec_stream(&i2s, &mp3); // Decoding stream
StreamCopy copier(dec_stream, url); // copy url to decoder

void setup(){

  // setup i2s
  auto config = i2s.defaultConfig(TX_MODE);
  i2s.begin(config);

  // setup I2S based on sampling rate provided by decoder
  dec_stream.begin();

  // mp3 radio
  if (!url.begin("http://stream.srg-ssr.ch/m/rsj/mp3_128","audio/mp3")){
    stop();
  }
}

void loop(){
  copier.copy();
}

extern "C" void app_main() {
    setup();
    while(true) loop();
}
