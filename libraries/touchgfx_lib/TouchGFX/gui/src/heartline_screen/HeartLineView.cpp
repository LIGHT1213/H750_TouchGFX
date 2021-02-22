#include <gui/heartline_screen/HeartLineView.hpp>
#include "main.h"
extern char *recv_data;
extern uint8_t NetRecFlag;
extern int stepNum;
extern int ecgNum;
extern int tempNum;
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
    HeartRateLine.setGraphRangeY(0,10*slider1.getValue());
}
void HeartLineView::handleTickEvent()
{
    if(NetRecFlag==1)
    {
        HeartLineView::UpDateHeartRateLine((int)ecgNum);
        NetRecFlag=0;
    }
}
