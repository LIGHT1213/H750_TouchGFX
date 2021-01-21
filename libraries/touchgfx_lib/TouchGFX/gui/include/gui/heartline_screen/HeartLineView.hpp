#ifndef HEARTLINEVIEW_HPP
#define HEARTLINEVIEW_HPP

#include <gui_generated/heartline_screen/HeartLineViewBase.hpp>
#include <gui/heartline_screen/HeartLinePresenter.hpp>

class HeartLineView : public HeartLineViewBase
{
public:
    HeartLineView();
    virtual ~HeartLineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void UpDateHeartRateLine(int i);
protected:
};

#endif // HEARTLINEVIEW_HPP
