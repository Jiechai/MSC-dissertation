//
//  APF.cpp
//
#include "APF.hpp"

APF::APF() : APF(240.f, 0.7f) 
{
}

APF::APF(float delay, float speed) : fractionalDelay(delay, speed)
{
}

// Destructor
APF::~APF(){
}

float APF::processSample(float x, int channel){
    
    //first order IIR allpass filter
    float y;
    float x_n= x;
    
    //feedbcak comb filter: v[n]=x[n]-a1*v[n-1]
    float v_n = x_n + (-feedbackGain) * fb1[channel];
    
    //delay:v[n-1]
    float v_nDelay = fractionalDelay.processSample(v_n, channel);
    
  
    //feedforwrd comb filter:y[n]= a1*v[n] +v[n-1]
    y =  feedbackGain * v_n + v_nDelay ;
    
    fb1[channel] = v_nDelay;
    
    return y;
    
//    float y;
//
//    float inDL1 = x + (-feedbackGain) * fb1[channel];
//
//    float outDL1 = fractionalDelay.processSample(inDL1, channel);
//
//    y = outDL1 + feedbackGain * inDL1;
//
//    fb1[channel] = outDL1;
//
//    return y;
}

void APF::setFs(float newFs){
    Fs = newFs;
    fractionalDelay.setFs(newFs);
}

void APF::setFeedbackGain(float newFeedbackGain){

    feedbackGain = newFeedbackGain;
}

void APF::setDepth(float newDepth){

    depth = newDepth;
    fractionalDelay.setDepth(newDepth);
}
