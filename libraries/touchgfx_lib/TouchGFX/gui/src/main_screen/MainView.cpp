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
    HeartRateNum.setValue(i);
}
void MainView::UpDateTemNum(int i)
{
    //char  buffer[20];

    float Temp=0.01f+i+0.1*i;
    TemNum.setValue(Temp);
//  if(Temp>38)
//  {
//      TemNumText.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
//  }
//  else
//  {
//      TemNumText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
//  }
    Unicode::snprintfFloat(HeartRateTextBuffer,HEARTRATETEXT_SIZE,"%3.1f",float(Temp) );
    TemNumText.setWildcard(HeartRateTextBuffer);
//    TemNumText.invalidate();

}
