//
//  WelcomeLayer.hpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/12.
//
//

#ifndef WelcomeLayer_hpp
#define WelcomeLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BasicLayer.hpp"
#include "AboutLayer.hpp"


USING_NS_CC;


class WelcomeLayer:public Layer{
public:
    virtual bool init();
    
    WelcomeLayer();
    ~WelcomeLayer();
    
    static Scene* scene();
    
    void setBackgroundImage(const char* back_image_name);

    void setupViews();
    
    void startgame_callback(CCObject* pSender);
    void option_callback(CCObject* pSender);
    void about_callback(CCObject* pSender);

    CREATE_FUNC(WelcomeLayer);
};

#endif /* WelcomeLayer_hpp */
