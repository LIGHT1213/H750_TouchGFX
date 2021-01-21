#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}
void MainPresenter::UpDateHeartNum(int i)
{
    view.UpDateHeartNum(i);
}
void MainPresenter::UpDateTemNum(int i)
{
    view.UpDateTemNum(i);
}
