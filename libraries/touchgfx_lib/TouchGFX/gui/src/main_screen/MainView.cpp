#include <gui/main_screen/MainView.hpp>
#include "main.h"
#include <math.h>
#include <stdlib.h>
extern char *recv_data;
extern uint8_t NetRecFlag;
extern int stepNum;
extern int ecgNum;
extern float tempNum;
extern int heartNum;
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
    //float Temp=0.01f+i+0.1*i;
    HeartRateNum.setValue(i);
    Unicode::snprintfFloat(HeartRateTextBuffer,HEARTRATETEXT_SIZE,"%3.1f",float(i) );
    HeartRateText.setWildcard(HeartRateTextBuffer);
    HeartRateText.invalidate();
}
void MainView::UpDateTemNum(float i)
{
    //char  buffer[20];

    //float Temp=0.01f+i+0.1*i;
    TemNum.setValue(i);
    Unicode::snprintfFloat(TemNumTextBuffer,TEMNUMTEXT_SIZE,"%3.1f",float(i) );
    TemNumText.setWildcard(TemNumTextBuffer);
    TemNumText.invalidate();

}
void MainView::UpDateStepNum(int i)
{
    Unicode::snprintfFloat(stepNumBuffer,STEPNUM_SIZE,"%3.1f",float(i) );
    stepNum.setWildcard(stepNumBuffer);
    stepNum.invalidate();
}
void MainView::handleTickEvent()
{
    if(NetRecFlag==1)
    {
        MainView::UpDateHeartNum((int)heartNum);
        MainView::UpDateTemNum(tempNum);
//    modelListener->UpDateHeartRateLine((int)recv_data[0]);
//    modelListener->UpDateHeartNum((int)recv_data[0]);
//    modelListener->UpDateTemNum((int)recv_data[0]);
    NetRecFlag=0;
    }
}
