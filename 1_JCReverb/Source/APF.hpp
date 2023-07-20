
//  APF.hpp

#ifndef APF_hpp //referred to as a class
#define APF_hpp
#include "FractionalDelay.hpp"

using namespace std;

class APF {
public:
    
    // Constructor function (special function - no return type, name = Class name)
    APF ();
    
    APF (float delay, float speed);
    
    // Destructor
    ~APF ();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setFeedbackGain(float feedbackGain);
    
    void setDepth(float depth);
    
    void setDelay (float delay){   fractionalDelay.setDelaySamples(delay);    }
    void setSpeed(float speed)           {   fractionalDelay.setSpeed(speed);           }
    void setStereoSpread(float newValue) {   fractionalDelay.setStereoSpread(newValue); }
    
private:
    FractionalDelay fractionalDelay;
    float Fs = 48000.f;
    float feedbackGain = 0.5f;    
    float fb1 [2] = {0.1f};
    float depth = 10.0f; // percentage of intensity, control amp of LFO    
};


#endif /* APF_hpp */
