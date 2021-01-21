#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}

    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void UpDateHeartRateLine(int i) {}
    virtual void UpDateHeartNum(int i) {}
    virtual void UpDateTemNum(int i) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
