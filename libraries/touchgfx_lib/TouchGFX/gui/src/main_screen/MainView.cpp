#include <gui/main_screen/MainView.hpp>
#include <math.h>
#include <stdlib.h>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();

    // Initialize graph range with default slider value at start up
    //sliderValueChanged(sliderResolution.getValue());
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}
void MainView::UpDateHeartNum(int i)
{
    float Temp=0.01f+i+0.1*i;
    HeartRateNum.setValue(Temp);
    Unicode::snprintfFloat(HeartRateTextBuffer,HEARTRATETEXT_SIZE,"%3.1f",float(Temp) );
    HeartRateText.setWildcard(HeartRateTextBuffer);
    HeartRateText.invalidate();
}
void MainView::UpDateTemNum(int i)
{
    //char  buffer[20];

    float Temp=0.01f+i+0.1*i;
    TemNum.setValue(Temp);
    Unicode::snprintfFloat(TemNumTextBuffer,TEMNUMTEXT_SIZE,"%3.1f",float(Temp) );
    TemNumText.setWildcard(TemNumTextBuffer);
    TemNumText.invalidate();

}
