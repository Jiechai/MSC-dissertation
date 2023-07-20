//
//  FBCF.cpp
//
#include "FBCF.hpp"


FBCF::FBCF() : FBCF(240.f, 0.7f)
{
}

FBCF::FBCF(float delay, float speed) : fractionalDelay(delay, speed)
{
}

FBCF::FBCF(float delay, float speed, float apfDelay, float apfSpeed)
    : fractionalDelay(delay, speed)
    , apf(apfDelay, apfSpeed)
{
    apf.setFeedbackGain(0.2f);
    apf.setDepth(3.f);
}

// Destructor
FBCF::~FBCF(){
}


float FBCF::processSample(float x, int channel){
    
    float y;

    //y[n]= b0*x[n]-a*y[n-M]
    float y_n = x + (-feedbackGain) * fb1[channel];
    
    // delay: y[n-M]
    float y_nDelay = fractionalDelay.processSample(y_n, channel);
    
    y = y_nDelay;
    
    //fb1[channel] = lpf.processSample (y_nDelay,channel);
    
    fb1[channel] = y_nDelay;
    
    return y;
    
}

void FBCF::setFs(float newFs){
    Fs = newFs;
    fractionalDelay.setFs(newFs);
    apf.setFs(newFs);
}

void FBCF::setFeedbackGain(float newFeedbackGain){

    feedbackGain = newFeedbackGain;
}

void FBCF::setDepth(float newDepth){

    depth = newDepth;
    fractionalDelay.setDepth(newDepth);

}
//void FBCF::setSize(float size, float basedelay){
//
//    this->size = size ;
//    size = size +basedelay;
//    fractionalDelay.setDelaySamples(size);
//   
//}
