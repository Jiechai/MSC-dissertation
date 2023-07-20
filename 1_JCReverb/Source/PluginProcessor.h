/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#include "APF.hpp"
#include "Schroeder.hpp"
#include "LowPassFilter.hpp"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AlgoReverbAudioProcessor();
    ~AlgoReverbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    

    // GUI Values
    std::atomic<float> predelayMS {12.5f};
    std::atomic<float> wet {1.0f};//Preset Value
    std::atomic<float> timeValue {0.0f};
    std::atomic<float> modValue {10.f};
    std::atomic<float> diffusionValue {0.15f};
    std::atomic<float> freqValue  {20000.f};
    std::atomic<float> stereoSpread {0.1f};
    //std::atomic<float> sizeValue {1000.f};
    void setStereoSpread(float newValue);//set amount of stereo

private:

    FractionalDelay predelay;
    
    Schroeder schroeder;
    
    LowPassFilter lpf;
    
    float Fs =44100.f;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessor)
};
