/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), envGui(p), filterGui(p), resonanceGui(p), filterEnvelopeGui(p), lfoGui(p), lfoFilterEnvelopeGui(p), hpfGui(p), vcaGui(p), noiseGui(p), sawOscGui(p), squareOscGui(p), subOscGui(p), pitchRangeGui(p), pwmGui(p), lfoPitchGui(p), lfoPwmGui(p), chorusGui(p), keyboardComponent (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard), presets(p), pwmModeSwitchGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 400);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filterGui);
    addAndMakeVisible(&resonanceGui);
    addAndMakeVisible(&filterEnvelopeGui);
    addAndMakeVisible(&lfoGui);
    addAndMakeVisible(&lfoFilterEnvelopeGui);
    addAndMakeVisible(&hpfGui);
    addAndMakeVisible(&vcaGui);
    addAndMakeVisible(&noiseGui);
    addAndMakeVisible(&sawOscGui);
    addAndMakeVisible(&squareOscGui);
    addAndMakeVisible(&subOscGui);
    addAndMakeVisible(&pitchRangeGui);
    addAndMakeVisible(&pwmGui);
    addAndMakeVisible(&lfoPitchGui);
    addAndMakeVisible(&lfoPwmGui);
    addAndMakeVisible(&chorusGui);
    addAndMakeVisible(&keyboardComponent);
    addAndMakeVisible(&presets);
    addAndMakeVisible(&pwmModeSwitchGui);
    
    
    //Labels
    addAndMakeVisible(&lfoLabel);
    lfoLabel.setText ("LFO", dontSendNotification);
    lfoLabel.setJustificationType (Justification::centred);
    lfoLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&oscLabel);
    oscLabel.setText ("DCO", dontSendNotification);
    oscLabel.setJustificationType (Justification::centred);
    oscLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envLabel);
    envLabel.setText ("ENV", dontSendNotification);
    envLabel.setJustificationType (Justification::centred);
    envLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&hpfLabel);
    hpfLabel.setText ("HPF", dontSendNotification);
    hpfLabel.setJustificationType (Justification::centred);
    hpfLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&envAmpLabel);
    envAmpLabel.setText ("ENV", dontSendNotification);
    envAmpLabel.setJustificationType (Justification::centred);
    envAmpLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&ampLabel);
    ampLabel.setText ("AMP", dontSendNotification);
    ampLabel.setJustificationType (Justification::centred);
    ampLabel.setFont (Font (16.0f, Font::bold));
    
    addAndMakeVisible(&chorusLabel);
    chorusLabel.setText ("CHORUS", dontSendNotification);
    chorusLabel.setJustificationType (Justification::centred);
    chorusLabel.setFont (Font (16.0f, Font::bold));
    
   
    //Styling LookAndFeel
    getLookAndFeel().setColour (TextButton::buttonColourId,  Colour(0xffe0dedf));
    getLookAndFeel().setColour (TextButton::buttonOnColourId,  Colour(0xffe0dedf));
    lfoGui.setLookAndFeel(&sliderLookAndFeel);
    lfoPwmGui.setLookAndFeel(&sliderLookAndFeel);
    pwmGui.setLookAndFeel(&sliderLookAndFeel);
    subOscGui.setLookAndFeel(&sliderLookAndFeel);
    noiseGui.setLookAndFeel(&sliderLookAndFeel);
    envGui.setLookAndFeel(&sliderLookAndFeel);
    hpfGui.setLookAndFeel(&sliderLookAndFeel);
    filterGui.setLookAndFeel(&sliderLookAndFeel);
    resonanceGui.setLookAndFeel(&sliderLookAndFeel);
    filterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    lfoFilterEnvelopeGui.setLookAndFeel(&sliderLookAndFeel);
    vcaGui.setLookAndFeel(&sliderLookAndFeel);
    pwmModeSwitchGui.setLookAndFeel(&sliderToggleLookAndFeel);
    
    
}


SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour(0xff333b3d));
    g.setColour(Colours::darkred);
    g.fillRect (3, 0, 120.5, 20);
    g.fillRect (127, 0, 462, 20);
    g.fillRect (593, 0, 204, 20);
    g.fillRect (50, 170, 57, 20);
    g.fillRect (145, 170, 200, 20);
    g.fillRect (400, 170, 50, 20);
    g.setColour(Colours::darkblue);
    g.fillRect (500, 170, 100, 20);
    
    g.setColour(Colours::whitesmoke);
    
    
    drawSquareLabel(402.5, 80, 1.8f, 1.4f, g);
    drawSawLabel(443, 80, 1.8f, 1.4f, g);
    drawDCOLabelLines(325, 35, 83, 1.4f, g);
    drawSeparatingWhiteLines(lfoGui.getX()-4, lfoGui.getY()-5, lfoGui.getHeight()+5, 2.0f, g);
    drawSeparatingWhiteLines(lfoGui.getWidth()+lfoGui.getX()+5, lfoGui.getY()-5, lfoGui.getHeight()+5, 2.0f, g);
    drawSeparatingWhiteLines(noiseGui.getWidth()+noiseGui.getX(), noiseGui.getY()-5, noiseGui.getHeight()+5, 2.0f, g);
     drawSeparatingWhiteLines(envGui.getWidth()+envGui.getX()-6.5, envGui.getY()-5, envGui.getHeight()+5, 2.0f, g);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    area.translate(5, 25);
    
    Rectangle<int> area2 = getLocalBounds();
    area2.translate(0, 190);
    
    //Labels
    lfoLabel.setBounds(0,5,100, 10);
    oscLabel.setBounds(140, 0, 440, 20);
    envLabel.setBounds(563, 0, 237, 20);
    hpfLabel.setBounds(50, 170, 57, 20);
    envAmpLabel.setBounds(145, 170, 200, 20);
    ampLabel.setBounds(400, 170, 50, 20);
    chorusLabel.setBounds(500, 170, 100, 20);
    
    //Synth Components
    lfoGui.setBounds(area.removeFromLeft(115).removeFromTop(140));
    pitchRangeGui.setBounds(area.removeFromLeft(127.5).removeFromTop(140));
    
    lfoPwmGui.setBounds(area.removeFromLeft(60).removeFromTop(140));
    pwmGui.setBounds(area.removeFromLeft(55).removeFromTop(140));
    pwmModeSwitchGui.setBounds(area.removeFromLeft(32.5).removeFromTop(140));
    squareOscGui.setBounds(area.removeFromLeft(40).removeFromTop(140));
    sawOscGui.setBounds(area.removeFromLeft(37.5).removeFromTop(140));
    subOscGui.setBounds(area.removeFromLeft(55).removeFromTop(140));
    noiseGui.setBounds(area.removeFromLeft(65).removeFromTop(140));
    envGui.setBounds(area.removeFromLeft(240).removeFromTop(140));
    hpfGui.setBounds(area2.removeFromLeft(150).removeFromTop(320));
    filterGui.setBounds(area2.removeFromLeft(50).removeFromTop(320));
    resonanceGui.setBounds(area2.removeFromLeft(50).removeFromTop(320));
    filterEnvelopeGui.setBounds(area2.removeFromLeft(50).removeFromTop(320));
    lfoFilterEnvelopeGui.setBounds(area2.removeFromLeft(50).removeFromTop(320));
    vcaGui.setBounds(area2.removeFromLeft(150).removeFromTop(320));
    chorusGui.setBounds(area2.removeFromLeft(100).removeFromTop(320));
    presets.setBounds(area2.removeFromLeft(200).removeFromTop(145));
    


    //Keyboard
    keyboardComponent.setBounds(0, 325, 800, 75);
    
    
 
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
 
    
}

void SynthFrameworkAudioProcessorEditor::handleNoteOn(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{
 
}

void SynthFrameworkAudioProcessorEditor::handleNoteOff(MidiKeyboardState *source, int midiChannel, int midiNoteNumber, float velocity)
{

}

void SynthFrameworkAudioProcessorEditor::handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message)
{
   
}

void SynthFrameworkAudioProcessorEditor::drawSquareLabel(float x, float y, int size, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    double lineModifer = 1.5;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength));
    
    Line<float> line2 (Point<float> (x, y-lineLength),
                      Point<float> (x+lineLength, y-lineLength));
    
    Line<float> line3 (Point<float> (x+lineLength, y-lineLength),
                      Point<float> (x+lineLength, y));
    
    Line<float> line4 (Point<float> (x+lineLength, y),
                       Point<float> (x+lineLength+(lineLength*lineModifer), y));
    
    Line<float> line5 (Point<float> (x+lineLength+(lineLength*lineModifer), y),
                       Point<float> (x+lineLength+(lineLength*lineModifer), y-lineLength));
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness/2);
    g.drawLine (line5, thickness);
    
    
}

void SynthFrameworkAudioProcessorEditor::drawSawLabel(float x, float y, int size, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    float lineLength = 5.0f*size;
    double lineModifer = 2.0f;
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-lineLength));
    
    Line<float> line2 (Point<float> (x, y-lineLength),
                       Point<float> (x+lineLength*2, y));
    
    Line<float> line3 (Point<float> (x+lineLength*lineModifer, y),
                       Point<float> (x+lineLength*lineModifer, y-lineLength));
    
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    
}

void SynthFrameworkAudioProcessorEditor::drawDCOLabelLines(float x, float y, float width, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    Line<float> line (Point<float> (x, y),
                      Point<float> (x, y-5));
    
    Line<float> line2 (Point<float> (x, y-5),
                       Point<float> (x+width, y-5));
    
    Line<float> line3 (Point<float> (x+width, y-5),
                       Point<float> (x+width, y+30));
    
    Line<float> line4 (Point<float> (x+width * 0.6f, y-5),
                       Point<float> (x+width * 0.6f, y+45));
    
    
    g.drawLine (line, thickness);
    g.drawLine (line2, thickness);
    g.drawLine (line3, thickness);
    g.drawLine (line4, thickness);
    
}

void SynthFrameworkAudioProcessorEditor::drawSeparatingWhiteLines(float x, float y, float height, float thickness, Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    
    Line<float> line (Point<float> (x, y),
                     Point<float> (x, y+height));
    
    g.drawLine (line, thickness);
    
}




