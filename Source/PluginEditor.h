/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"
#include "Cutoff.h"
#include "Resonance.h"
#include "FilterEnvelope.h"
#include "LFO.h"
#include "LfoFilterEnvelope.h"
#include "HPF.h"
#include "VCA.h"
#include "Noise.h"
#include "SawOscillator.h"
#include "SquareOscillator.h"
#include "SubOscillator.h"
#include "PitchRange.h"
#include "PWM.h"


//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider* slider);
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;
    
    Oscillator oscGui;
    Envelope envGui;
    Cutoff filterGui;
    Resonance resonanceGui;
    FilterEnvelope filterEnvelopeGui;
    LFO lfoGui;
    HPF hpfGui;
    VCA vcaGui;
    Noise noiseGui;
    SawOscillator sawOscGui;
    SquareOscillator squareOscGui;
    SubOscillator subOscGui;
    LfoFilterEnvelope lfoFilterEnvelopeGui;
    PitchRange pitchRangeGui;
    PWM pwmGui;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
