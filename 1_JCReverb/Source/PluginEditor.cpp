/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(titleLabel);
    titleLabel.setFont(juce::Font(16.0f, juce::Font::bold));
    titleLabel.setText("Click in the white box to enter some text...", juce::dontSendNotification);
    titleLabel.setColour(juce::Label::textColourId, juce::Colours::lightgreen);
    titleLabel.setJustificationType(juce::Justification::centred);


    setSize (800, 450);
    
    //REVERB TIME SLIDER
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSliderStyle(Slider::LinearVertical);
    reverbTimeSlider.setBounds(50, 70, 100, 100);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    reverbTimeSlider.setRange(0.0f, 0.5f, 0.01f); //change time

    //float sliderValue = 0.1f + 0.8f * (processor.timeValue - 0.2f)/ 3.7f; // ms value conversion
    reverbTimeSlider.setValue(0.2f);
    //reverbTimeSlider.setValue(sliderValue, NotificationType::dontSendNotification);
    addAndMakeVisible(reverbTimeSlider);

    reverbTimeLabel.setText("ER Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);

    //MODULATION SLIDER
    modulationSlider.addListener(this);
    modulationSlider.setSliderStyle(Slider::LinearVertical);
    modulationSlider.setBounds(250, 70, 100, 100);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modulationSlider.setRange(0.0f, 1.0f, 0.1f);
    modulationSlider.setValue(0.0f);
    //modulationSlider.setValue(processor.modValue, NotificationType::dontSendNotification);
    addAndMakeVisible(modulationSlider);

    modulationLable.setText("Modulation", dontSendNotification);
    modulationLable.attachToComponent(&modulationSlider, false);
    modulationLable.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLable);

    //Stereo Spread Components
    stereoSpreadSlider.addListener(this);
    stereoSpreadSlider.setSliderStyle(Slider::LinearVertical);
    stereoSpreadSlider.setBounds(450, 70, 100, 100);
    stereoSpreadSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    stereoSpreadSlider.setRange(0.0f, 0.1f, 0.0001f);
    //float stereoSliderActualVal = 1 - static_cast<float>(processor.stereoSpread);
    stereoSpreadSlider.setValue(0.1f);
    //stereoSpreadSlider.setValue(stereoSliderActualVal, NotificationType::dontSendNotification);
    addAndMakeVisible(stereoSpreadSlider);

    stereoSpreadLabel.setText("Mono/Stereo", dontSendNotification);
    stereoSpreadLabel.attachToComponent(&stereoSpreadSlider, false);
    stereoSpreadLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(stereoSpreadLabel);

    //PRE DELAY SLIDER
    predelaySlider.addListener(this);
    predelaySlider.setSliderStyle(Slider::LinearVertical);
    predelaySlider.setBounds(50, 220, 100, 100);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    predelaySlider.setRange(0.0f, 50.0f, 0.01f);
    predelaySlider.setValue(25.0f);
    //predelaySlider.setValue(processor.predelayMS, NotificationType::dontSendNotification);
    addAndMakeVisible(predelaySlider);

    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);

    //DIFFUSION SLIDER
    diffusionSlider.addListener(this);
    diffusionSlider.setSliderStyle(Slider::LinearVertical);
    diffusionSlider.setBounds(250, 220, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.0f, 0.7, 0.01f);
    diffusionSlider.setValue(0.f);
    //diffusionSlider.setValue(processor.diffusionValue, NotificationType::dontSendNotification);
    addAndMakeVisible(diffusionSlider);

    diffusionLable.setText("Diffusion", dontSendNotification);
    diffusionLable.attachToComponent(&diffusionSlider, false);
    diffusionLable.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLable);

    //LPF SLIDER
    lpfSlider.addListener(this);
    lpfSlider.setSliderStyle(Slider::LinearVertical);
    lpfSlider.setBounds(450, 220, 100, 100);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setRange(1000.f, 20000.f, 1.f);
    lpfSlider.setValue(18000.f);
    addAndMakeVisible(lpfSlider);
    
    lpfLable.setText("LPF", dontSendNotification);
    lpfLable.attachToComponent(&lpfSlider, false);
    lpfLable.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLable);

    //WET DRY SLIDER
    wetDrySlider.addListener(this);
    wetDrySlider.setSliderStyle(Slider::LinearVertical);
    wetDrySlider.setBounds(650, 70, 100, 250);
    wetDrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    wetDrySlider.setRange(0.0f, 1.0f, 0.01f);
    wetDrySlider.setValue(1.0f);

    //wetDrySlider.setValue(processor.wet, NotificationType::dontSendNotification);
    addAndMakeVisible(wetDrySlider);

    wetDryLable.setText("Dry/Wet", dontSendNotification);
    wetDryLable.attachToComponent(&wetDrySlider, false);
    wetDryLable.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLable);


    
    //sizeslider c 3.04
    //sizeSlider.addListener(this);
    //sizeSlider.setSliderStyle(Slider::LinearVertical);
    //sizeSlider.setBounds(350, 30, 100, 100);
    //sizeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    //sizeSlider.setRange(100.f, 2000.f,1.f);
    //sizeSlider.setValue(100.f);
    //addAndMakeVisible(sizeSlider);
    //
    //sizeLabel.setText("Size",dontSendNotification);
    //sizeLabel.attachToComponent(&sizeSlider, false);
    //sizeLabel.setJustificationType(Justification::centred);
    //addAndMakeVisible(sizeLabel);
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (Colours::black);
    
    //background image
    background = juce::ImageCache::getFromMemory(BinaryData::pluginBackground_png, BinaryData::pluginBackground_pngSize);
    g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);

    g.setColour(Colours::lightblue);

    g.setFont(Font(24.0f));

    g.drawText("Early Reflection Generator(Schroeder)", 0, 0, getWidth(), getHeight(), Justification::centredTop, true);



}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
   
    
    // get value from the predelay slider.then give it to variable predelayMS.
    if (slider == &predelaySlider)
    {
        processor.predelayMS = predelaySlider.getValue();
    }
    // get value from the wetDry slider.then give it to variable wet
    if (slider == &wetDrySlider)
    {
        processor.wet = wetDrySlider.getValue();
    }
    /*
       else if (slider == & reverbTimeSlider){
           float revTimeSec =reverbTimeSlider.getValue();
           float revTimeNorm = (revTimeSec - 0.3f)/2.4f;

           float revTimeGAin = revTimeNorm * 0.5f +0.4f;
           processor.timeValue = revTimeGAin;
       }*/

    // get value from the reverbTimeSlider.then give it to variable timeValue
    if (slider == &reverbTimeSlider)
    {
        processor.timeValue = reverbTimeSlider.getValue();
    }


    // get value from the modulationSlider.then give it to variable modValue
    if (slider == &modulationSlider)
    {
        processor.modValue = modulationSlider.getValue();
    }


    // get value from the diffusionSlider.then give it to variable diffusionValue
    if (slider == &diffusionSlider)
    {
        processor.diffusionValue = diffusionSlider.getValue();
    }


    // get value from the lpfSlider.then give it to variable freqValue
    if (slider == &lpfSlider)
    {
        processor.freqValue = lpfSlider.getValue();
    }
    // get value from the stereoSpreadSlider.then give it to variable setStereoSpread
    if (slider == &stereoSpreadSlider)
    {
        float actualValue = 1 - static_cast<float>(stereoSpreadSlider.getValue());
        processor.setStereoSpread(actualValue);
    }


    //if (slider == & sizeSlider) {
    //   processor.sizeValue =  sizeSlider.getValue();
    //} //c 3.04


}