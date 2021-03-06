#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void UpDateHeartNum(int i);
    void UpDateTemNum(float i);
    void UpDateStepNum(int i);
protected:
    void handleTickEvent();
};

#endif // MAINVIEW_HPP
