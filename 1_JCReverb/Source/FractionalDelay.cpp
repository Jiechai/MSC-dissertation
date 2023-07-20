//
//FractionalDelay.cpp
//

#include "FractionalDelay.hpp"

FractionalDelay::FractionalDelay(int newDelay, int newSpeed)
{
    delay[0] = newDelay;
    delay[1] = newDelay/2.f;
    
    speed = newSpeed;
}

float FractionalDelay::processSample(float x, int channel){
    
    if (delay[channel] < 1.f) {
        return x;
    }
    else{
        float lfo; // modulation 
        
        lfo = depth * sin(currentAngle[channel]);  // sine wave, 

        currentAngle[channel] += angleChange;
        
        if (currentAngle[channel] > 2.f * M_PI){
            currentAngle[channel] -= 2.f * M_PI;
        }
        
        // Delay Buffer,"delay" can be fraction
  
        int d1 = floor(delay[channel] +lfo);// returns an integer value that is less than or equal to the argument
        int d2 = d1 + 1;   

        float g2 = delay[channel] + lfo - (float)d1; // fractional gain 2
        float g1 = 1.0f - g2;  // fractional gain 1
        
        int indexD1 = index[channel] - d1; 
        if (indexD1 < 0){
            indexD1 += MAX_BUFFER_SIZE;  // max size is 96000
        }
        
        int indexD2 = index[channel] - d2;
        if (indexD2 < 0){
            indexD2 += MAX_BUFFER_SIZE;
        }
        // linear  interpolation
        float y = g1 * delayBuffer[indexD1][channel] + g2 * delayBuffer[indexD2][channel];
        
        delayBuffer[index[channel]][channel] = x;
        
        if (index[channel] < MAX_BUFFER_SIZE - 1){
            index[channel]++;  // only move index, not need move data.
        }
        else{
            index[channel] = 0;              
        }
        return y;
    }
}

void FractionalDelay::setFs(float newFs){
    Fs = newFs;
}

void FractionalDelay::setDelaySamples(float newDelay) {
    
    delay[0] = newDelay < 1.f ? 0.f : newDelay; //new line for preDelay
    delay[1] = delay[0] * stereoSpread.load();
}

void FractionalDelay::setStereoSpread(float newValue) {

    stereoSpread.store(newValue);
    delay[1] = delay[0] * stereoSpread.load();
}

void FractionalDelay::setSpeed(float newSpeed) {
    if (newSpeed >= 0.1f && newSpeed <= 10.0f){
        speed = newSpeed;
        angleChange = newSpeed * (1.f/Fs) * 2 * M_PI;
    }
}

void FractionalDelay::setDepth(float newDepth){
    depth = newDepth;
}
