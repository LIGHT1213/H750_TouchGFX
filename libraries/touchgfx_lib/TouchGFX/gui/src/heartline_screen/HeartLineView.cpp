#include <gui/heartline_screen/HeartLineView.hpp>

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
