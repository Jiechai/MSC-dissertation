//
//  LowPassFilter.hpp 
//

#ifndef LowPassFilter_hpp //referred to as a class
#define LowPassFilter_hpp

class LowPassFilter {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    LowPassFilter ();
    
    LowPassFilter (float delay, float speed);
    
    // Destructor
    ~LowPassFilter();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setFeedbackGain(float feedbackGain);
    
    void setFrequency(float newFreq);
    
    void setDepth(float depth);
    
private:
    
    float Fs = 48000.f;
    float freq = 20000.f;
    const float Q = 0.7071f;
    
    float x1[2] = {0.f};
    float x2[2] = {0.f};
    float y1[2] = {0.f};
    float y2[2] = {0.f};
    
    float b0 = 1.f;
    float b1 = 0.f;
    float b2 = 0.f;
    
    float a0 = 1.f;
    float a1 = 0.f;
    float a2 = 0.f;
    
    void updateCoefficients();
};

#endif /* LowPassFilter_hpp */
