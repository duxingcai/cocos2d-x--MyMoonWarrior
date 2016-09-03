//
//  BasicLayer.cpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/12.
//
//

#include "BasicLayer.hpp"


BasicLayer::BasicLayer(){

}


BasicLayer::~BasicLayer(){

}


//初始化方法
bool BasicLayer::init(){
    bool sRect=false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        sRect=true;
    } while (0);
    
    return sRect;
}


//获取屏幕大小的方法
Size BasicLayer::getWinSize(){
    return Director::sharedDirector()->getWinSize();
}


//设置背景图片的方法
void BasicLayer::setBackgroundImage(const char* back_image_name){
    
    Sprite* sp=Sprite::create(back_image_name);
    sp->setPosition(getWinSize().width/2,getWinSize().height/2);
    this->addChild(sp);
}











