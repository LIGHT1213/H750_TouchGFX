#include <gui/heartline_screen/HeartLineView.hpp>
#include "main.h"
extern char *recv_data;
extern uint8_t NetRecFlag;
extern int stepNum;
extern int ecgNum;
extern float tempNum;
extern int heartNum;
HeartLineView::HeartLineView()
{

}

void HeartLineView::setupScreen()
{
    HeartLineViewBase::setupScreen();
}

void HeartLineView::tearDownScreen()
{
    HeartLineViewBase::tearDownScreen();
}
void HeartLineView::UpDateHeartRateLine(int i)
{
    HeartRateLine.addDataPoint(i);
}
void HeartLineView::handleTickEvent()
{
    if(NetRecFlag==1)
    {
        if(ecgNum>500)
            ecgNum=500;
        HeartLineView::UpDateHeartRateLine((int)ecgNum);
        NetRecFlag=0;
    }
}
