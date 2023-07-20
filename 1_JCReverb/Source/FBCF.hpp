//
//  FBCF.hpp
//
#ifndef FBCF_hpp //referred to as a class
#define FBCF_hpp
#include "FractionalDelay.hpp"
#include "APF.hpp"

using namespace std;

class FBCF{
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FBCF ();
    
    FBCF (float delay, float speed);
    
    FBCF (float delay, float speed, float apfDelay, float apfSpeed);
    
    // Destructor
    ~FBCF ();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setFeedbackGain(float feedbackGain);
    
    void setDepth(float depth);

    void setStereoSpread(float newValue) {
        fractionalDelay.setStereoSpread(newValue); 
        apf.setStereoSpread(newValue);
    }
    //void setSize(float size, float basedelay); //3.04
    
private:
    
    float Fs = 44100.f;
    
    FractionalDelay fractionalDelay;

    float feedbackGain = 0.0f;
    
    float fb1 [2] = {0.1f};

    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    //float size = 1000.0f ;//3.04
    //float basedelay = 1000.0f;//3.04
    
    class SimpleLPF{
    public:
    float processSample(float x, int channel){
        float y = 0.5f * x + 0.5f * ff [channel];
        ff[channel] =x;
        return y;
        
        };
    
    private:
        float ff [2] = {0.f};
    };
        SimpleLPF lpf;
        APF apf;
};

#endif /* FBCF_hpp */
