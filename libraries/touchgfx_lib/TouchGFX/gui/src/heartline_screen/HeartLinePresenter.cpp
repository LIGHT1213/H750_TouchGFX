#include <gui/heartline_screen/HeartLineView.hpp>
#include <gui/heartline_screen/HeartLinePresenter.hpp>

HeartLinePresenter::HeartLinePresenter(HeartLineView& v)
    : view(v)
{

}

void HeartLinePresenter::activate()
{

}

void HeartLinePresenter::deactivate()
{

}
void HeartLinePresenter::UpDateHeartRateLine(int i)
{
        view.UpDateHeartRateLine(i);
}

