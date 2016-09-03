//
//  BasicLayer.hpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/12.
//
//

#ifndef BasicLayer_hpp
#define BasicLayer_hpp
#include "cocos2d.h"
#include <stdio.h>

USING_NS_CC;

class BasicLayer:public Layer{
public:
    virtual bool init();
    
    BasicLayer();
    ~BasicLayer();
    
    Size getWinSize();
    
    void setBackgroundImage(const char* back_image_name);
    
    CREATE_FUNC(BasicLayer);
};
#endif /* BasicLayer_hpp */
