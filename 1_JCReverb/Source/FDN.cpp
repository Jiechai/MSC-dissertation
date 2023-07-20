//
//  FDN.cpp
//

#include "FDN.hpp"


FDN::FDN()
    : fractionalDelay1(1571.f, 0.7f) //2nd argument modulation
    , fractionalDelay2(2053.f, 0.9f)
    , fractionalDelay3(2719.f, 1.1f)
    , fractionalDelay4(3461.f, 1.3f)
    , fractionalDelay5(4733.f, 1.5f)
    , fractionalDelay6(5879.f, 1.7f)
    , fractionalDelay7(6733.f, 1.5f)
    , fractionalDelay8(6873.f, 1.2f)

{
    fractionalDelay1.setStereoSpread(0.5f);
    fractionalDelay2.setStereoSpread(0.5f);
    fractionalDelay3.setStereoSpread(0.5f);
    fractionalDelay4.setStereoSpread(0.5f);
    fractionalDelay5.setStereoSpread(0.5f);
    fractionalDelay6.setStereoSpread(0.5f);
    fractionalDelay7.setStereoSpread(0.5f);
    fractionalDelay8.setStereoSpread(0.5f);
}

// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel){
    
    float y;
    
    float inDL1 = x +   fb1[channel];
    float inDL2 = x +   fb2[channel];
    float inDL3 = x +   fb3[channel];
    float inDL4 = x +   fb4[channel];
    float inDL5 = x +   fb5[channel];
    float inDL6 = x +   fb6[channel];
    float inDL7 = x +   fb7[channel]; // additional feedback path
    float inDL8 = x +   fb8[channel]; // additional feedback path
    
    float outDL1 = fractionalDelay1.processSample(inDL1, channel);
    float outDL2 = fractionalDelay2.processSample(inDL2, channel);
    float outDL3 = fractionalDelay3.processSample(inDL3, channel);
    float outDL4 = fractionalDelay4.processSample(inDL4, channel);
    float outDL5 = fractionalDelay5.processSample(inDL5, channel);
    float outDL6 = fractionalDelay6.processSample(inDL6, channel);
    float outDL7 = fractionalDelay7.processSample(inDL7, channel); // additional delay line
    float outDL8 = fractionalDelay8.processSample(inDL8, channel);
    
    y = 0.125f * (outDL1 + outDL2 + outDL3 + outDL4 + outDL5 + outDL6 + outDL7 + outDL8);
    
    fb1[channel] = (-outDL2 + outDL3) * feedbackGain;
    fb2[channel] = (outDL1 +  outDL4) * feedbackGain;
    fb3[channel] = (outDL1 + -outDL3) * feedbackGain;
    fb4[channel] = (-outDL2 + -outDL3) * feedbackGain;
    fb5[channel] = (outDL4 + outDL6) * feedbackGain;
    fb6[channel] = (-outDL5 - outDL6) * feedbackGain;
    fb7[channel] = (outDL6 - outDL7) * feedbackGain;
    fb8[channel] = (-outDL5 + outDL8) * feedbackGain;
    
    return y;
    
}

void FDN::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
}

void FDN::setTime(float timeValue){

    feedbackGain = timeValue;
}

void FDN::setDepth(float depth){

    this->depth = depth;
    fractionalDelay1.setDepth(depth);
    fractionalDelay2.setDepth(depth);
    fractionalDelay3.setDepth(depth);
    fractionalDelay4.setDepth(depth);
    
}

void FDN::setStereoSpread(float newValue)
{
    fractionalDelay1.setStereoSpread(newValue);
    fractionalDelay2.setStereoSpread(newValue);
    fractionalDelay3.setStereoSpread(newValue);
    fractionalDelay4.setStereoSpread(newValue);
}
