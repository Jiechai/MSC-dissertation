//
// Schroeder.hpp
//
#ifndef Schroeder_hpp //referred to as a class
#define Schroeder_hpp
#include "FBCF.hpp"
#include "APF.hpp"

using namespace std;

class Schroeder{
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    Schroeder ();
    
    
    // Destructor
    ~Schroeder ();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setFeedbackGain(float feedbackGain);
    
    void setDiffusionGain(float diffusionGain);
    
    void setDepth(float depth);

    void setStereoSpread(float newValue);
    // void setSize(float size);//3.04
    
private:
    
    float Fs = 48000.f;
    
    FBCF fbcf1 {419.f, 0.723f, 16.3f, 0.27f}; //prime numbers
    FBCF fbcf2 {857.f, 1.257f, 27.1f,0.712f};
    FBCF fbcf3 {1307.f, 0.893f, 83.f, 0.5821f};
    FBCF fbcf4 {1753.f, 1.111f, 30.7f, 0.9117f};
    
    FBCF fbcf5  {2213.f, 0.929f, 42.f, 0.8117f};
    FBCF fbcf6  {2671.f, 1.033f, 21.f, 0.911f};
    FBCF fbcf7  {3109.f, 0.797f, 17.f, 0.4117f};
    FBCF fbcf8  {3517.f, 1.193f, 75.f, 0.217f};
    
    FBCF fbcf9  {3943.f, 1.151f, 15.f, 0.3117f};
    FBCF fbcf10 {4391.f, 0.857f, 33.f, 0.511f};
    FBCF fbcf11 {4877.f, 1.087f, 68.f, 0.67f};
    FBCF fbcf12 {5303.f, 0.811f, 26.f, 0.9117f};
    //FBCF(float delay, float speed, float apfDelay, float apfSpeed)
    APF apf1{40.f, 0.8321f};
    APF apf2{82.f, 0.964f};

    
    float feedbackGain = 0.5f;
    float diffusionGain = 0.5f;
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    float size = 100.0f;// c 3.04
    
};


#endif /* Schroeder_hpp */
