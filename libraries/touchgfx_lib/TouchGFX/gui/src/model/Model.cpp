#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    static int i;
    i=i+1;
    modelListener->UpDateHeartRateLine(i);
    modelListener->UpDateHeartNum(i);
    modelListener->UpDateTemNum(i);
    if(i==100)
    i=0;
}
