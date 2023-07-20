//
//  FDN.hpp
//
//

#ifndef FDN_hpp
#define FDN_hpp

#include "FractionalDelay.hpp"

using namespace std;

class FDN {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FDN ();    
    
    // Destructor
    ~FDN ();
    
    float processSample(float x,int channel);

    void setFs(float Fs);    
    void setTime(float timeValue);    
    void setDepth(float depth);
    void setStereoSpread(float newValue);
    
private:
    
    float Fs = 48000.f;
    
    FractionalDelay fractionalDelay1;
    FractionalDelay fractionalDelay2;
    FractionalDelay fractionalDelay3;
    FractionalDelay fractionalDelay4;
    FractionalDelay fractionalDelay5;
    FractionalDelay fractionalDelay6;
    FractionalDelay fractionalDelay7;
    FractionalDelay fractionalDelay8;
    
    float feedbackGain = 0.5f;
    
    float fb1 [2] = {0.f};
    float fb2 [2] = {0.f};
    float fb3 [2] = {0.f};
    float fb4 [2] = {0.f};
    float fb5 [2] = {0.f};
    float fb6 [2] = {0.f};
    float fb7 [2] = {0.f};
    float fb8 [2] = {0.f};
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO    
};



#endif /* FDN_hpp */
