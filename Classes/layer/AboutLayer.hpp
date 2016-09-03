//
//  AboutLayer.hpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/13.
//
//

#ifndef AboutLayer_hpp
#define AboutLayer_hpp

#include "cocos2d.h"
#include "BasicLayer.hpp"
#include "WelcomeLayer.hpp"
#include <stdio.h>

USING_NS_CC;

class AboutLayer:public Layer{
public:
    virtual bool init();
    
    AboutLayer();
    ~AboutLayer();
    
    void setupViews();
    
    void back_callback(CCObject* pSender);
    
    static Scene* scene();
    
    CREATE_FUNC(AboutLayer);
};
#endif /* AboutLayer_hpp */
