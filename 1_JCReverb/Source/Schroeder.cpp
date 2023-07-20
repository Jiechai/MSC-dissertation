//
//  Schroeder.cpp
//

#include "Schroeder.hpp"

Schroeder::Schroeder(){
}

// Destructor
Schroeder::~Schroeder(){
}

float Schroeder::processSample(float x, int channel){
    
    float y;
    //12 parallel FBCF, to increase echo density to 1000 per second
    float outFBCF1 =0.9 * fbcf1.processSample(x,channel);
    float outFBCF2 =0.8 * fbcf2.processSample(x,channel);
    float outFBCF3 = 0.7 * fbcf3.processSample(x,channel);
    float outFBCF4 = 0.6 * fbcf4.processSample(x,channel);
    
    float outFBCF5 = 0.5 * fbcf5.processSample(x, channel);
    float outFBCF6 = 0.4 * fbcf6.processSample(x, channel);
    float outFBCF7 = 0.3 * fbcf7.processSample(x, channel);
    float outFBCF8 = 0.2 * fbcf8.processSample(x, channel);
    
    float outFBCF9 = 0.1 * fbcf9.processSample(x, channel);
    float outFBCF10 = 0.05 * fbcf10.processSample(x, channel);
    float outFBCF11 = 0.02 * fbcf11.processSample(x, channel);
    float outFBCF12 = 0.01* fbcf12.processSample(x, channel);
    
    float sum1 =(outFBCF1 + outFBCF2 + outFBCF3 +outFBCF4);
    float sum2 =(outFBCF5 + outFBCF6 + outFBCF7 +outFBCF8);
    float sum3 =(outFBCF9 + outFBCF10 + outFBCF11 +outFBCF12);

    float inAPF1 =0.25*(sum1 +sum2 + sum3);
    
    // followed by 2 APF, we don't need to much diffusion
    float outAPF1 = apf1.processSample(inAPF1, channel);
    
          y = apf2.processSample(outAPF1,channel);
    
    return y;
    
}

void Schroeder::setFs(float Fs){
    Fs = Fs;
    fbcf1.setFs(Fs);
    fbcf2.setFs(Fs);
    fbcf3.setFs(Fs);
    fbcf4.setFs(Fs);
    
    fbcf5.setFs(Fs);
    fbcf6.setFs(Fs);
    fbcf7.setFs(Fs);
    fbcf8.setFs(Fs);
    
    fbcf9.setFs(Fs);
    fbcf10.setFs(Fs);
    fbcf11.setFs(Fs);
    fbcf12.setFs(Fs);
    
    apf1.setFs(Fs);
    apf2.setFs(Fs);
}

void Schroeder::setFeedbackGain(float feedbackGain){

    this ->feedbackGain = feedbackGain;
    fbcf1.setFeedbackGain(feedbackGain);
    fbcf2.setFeedbackGain(feedbackGain);
    fbcf3.setFeedbackGain(feedbackGain);
    fbcf4.setFeedbackGain(feedbackGain);
    
    fbcf5.setFeedbackGain(feedbackGain);
    fbcf6.setFeedbackGain(feedbackGain);
    fbcf7.setFeedbackGain(feedbackGain);
    fbcf8.setFeedbackGain(feedbackGain);
    
    fbcf9.setFeedbackGain(feedbackGain);
    fbcf10.setFeedbackGain(feedbackGain);
    fbcf11.setFeedbackGain(feedbackGain);
    fbcf12.setFeedbackGain(feedbackGain);
    

}

void Schroeder::setDiffusionGain(float diffusionGain){
    
    diffusionGain = diffusionGain;
    apf1.setFeedbackGain(diffusionGain);
    apf2.setFeedbackGain(diffusionGain);
}
void Schroeder::setDepth(float depth){

    this->depth = depth;
    fbcf1.setDepth(depth);
    fbcf2.setDepth(depth);
    fbcf3.setDepth(depth);
    fbcf4.setDepth(depth);
    
    fbcf5.setDepth(depth);
    fbcf6.setDepth(depth);
    fbcf7.setDepth(depth);
    fbcf8.setDepth(depth);
    
    fbcf9.setDepth(depth);
    fbcf10.setDepth(depth);
    fbcf11.setDepth(depth);
    fbcf12.setDepth(depth);
    
    apf1.setDepth(depth);
    apf2.setDepth(depth);
}

void Schroeder::setStereoSpread(float newValue)
{
    fbcf1.setStereoSpread(newValue);
    fbcf2.setStereoSpread(newValue);
    fbcf3.setStereoSpread(newValue);
    fbcf4.setStereoSpread(newValue);
    
    fbcf5.setStereoSpread(newValue);
    fbcf6.setStereoSpread(newValue);
    fbcf7.setStereoSpread(newValue);
    fbcf8.setStereoSpread(newValue);
    
    fbcf9.setStereoSpread(newValue);
    fbcf10.setStereoSpread(newValue);
    fbcf11.setStereoSpread(newValue);
    fbcf12.setStereoSpread(newValue);

    apf1.setStereoSpread(newValue);
    apf2.setStereoSpread(newValue);
}
//void Schroeder::setSize(float size){
//
//    this->size = size;
//    fbcf1.setSize(size,1426.f);
//    fbcf2.setSize(size,1781.f);
//    fbcf3.setSize(size,1973.f);
//    fbcf4.setSize(size,2098.f);
//    
//    fbcf5.setSize(size,2113.f);
//    fbcf6.setSize(size,2179.f);
//    fbcf7.setSize(size,2203.f);
//    fbcf8.setSize(size,2269.f);
//    
//    fbcf9.setSize(size,2347.f);
//    fbcf10.setSize(size,2521.f);
//    fbcf11.setSize(size,2621.f);
//    fbcf12.setSize(size,2753.f);
//    
//}
