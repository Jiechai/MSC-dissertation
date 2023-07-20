/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener

{
public:
    AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor&);
    ~AlgoReverbAudioProcessorEditor();

    //==============================================================================




    void paint (juce::Graphics&) override;

    void resized() override;
    
    void sliderValueChanged(Slider * slider) override;
    


private:
    //add background image
    juce::Image background;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.


    AlgoReverbAudioProcessor& processor;
    
    Slider reverbTimeSlider;
    Slider modulationSlider;
    Slider wetDrySlider;
    
    Slider predelaySlider;
    Slider diffusionSlider;
    Slider lpfSlider;
    Slider stereoSpreadSlider;
    //Slider sizeSlider;//c 3.04

    Label reverbTimeLabel;
    Label modulationLable;
    Label wetDryLable;
    
    Label predelayLabel;
    Label diffusionLable;
    Label lpfLable;
    Label stereoSpreadLabel;

    Label titleLabel;

   // Label sizeLabel; //c3.04
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR
        (AlgoReverbAudioProcessorEditor)
};

