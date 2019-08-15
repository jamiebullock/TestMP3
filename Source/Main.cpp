/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic startup code for a JUCE application.
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
int main (int argc, char* argv[])
{
    std::unique_ptr<FileInputStream> mp3File = std::make_unique<FileInputStream>(File::getCurrentWorkingDirectory().getChildFile("85_Padloop_11_35_SP.mp3"));
    
    if (!mp3File->openedOk())
    {
        return EXIT_FAILURE;
    }
    
    AudioFormatManager manager;
    manager.registerBasicFormats();
    
    std::unique_ptr<AudioFormatReader> reader(manager.createReaderFor(mp3File.release()));
    const auto numChannels = static_cast<int>(reader->numChannels);
    const auto numSamples  = static_cast<int>(reader->lengthInSamples);
    
    AudioSampleBuffer buffer(numChannels, numSamples);
    reader->read(&buffer, 0, numSamples, 0, true, true);
    
    return EXIT_SUCCESS;
}
