//
//FractionalDelay.cpp
//

#ifndef FractionalDelay_hpp //referred to as a class
#define FractionalDelay_hpp


#define _USE_MATH_DEFINES

#include <math.h>
#include <cmath>
#include <atomic>
#include <array>

using namespace std;

class FractionalDelay {
    
public:
        
    FractionalDelay(int delay, int speed);
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDelaySamples(float delay);

    void setStereoSpread(float newValue);
    
    void setSpeed(float speed);
    void setDepth(float depth);

private:
    
    float Fs = 48000.f;
    
    std::array<std::atomic<float>, 2> delay;
    
    const int MAX_BUFFER_SIZE = 96000;
    float delayBuffer[96000][2] = {0.0f};
    int index[2] = {0};
    
    float speed = 1.0f; // Hz, frequency of LFO
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    float currentAngle[2] = {0.0f};
    float angleChange = speed * (1.f/Fs) * 2.f * M_PI;

    std::atomic<float> stereoSpread {0.5f};
};


#endif /* FractionalDelay_hpp */
