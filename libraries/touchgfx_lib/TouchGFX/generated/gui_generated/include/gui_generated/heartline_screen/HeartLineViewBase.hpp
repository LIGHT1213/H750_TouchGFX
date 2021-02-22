/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HEARTLINEVIEWBASE_HPP
#define HEARTLINEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/heartline_screen/HeartLinePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/CacheableContainer.hpp>
#include <touchgfx/widgets/graph/GraphScroll.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/Slider.hpp>

class HeartLineViewBase : public touchgfx::View<HeartLinePresenter>
{
public:
    HeartLineViewBase();
    virtual ~HeartLineViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::CacheableContainer container1;
    touchgfx::Box box1;
    touchgfx::GraphScroll<136> HeartRateLine;
    touchgfx::GraphElementLine HeartRateLineLine1;
    touchgfx::PainterRGB565 HeartRateLineLine1Painter;
    touchgfx::TextArea textArea1;
    touchgfx::Button button1;
    touchgfx::Slider slider1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<HeartLineViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // HEARTLINEVIEWBASE_HPP
