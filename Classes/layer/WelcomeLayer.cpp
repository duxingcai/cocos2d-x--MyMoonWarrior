//
//  WelcomeLayer.cpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/12.
//
//

#include "WelcomeLayer.hpp"
#include "BasicLayer.hpp"

bool WelcomeLayer::init(){
    bool sRect=false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        
        setupViews();
        
        sRect=true;
    } while (0);
    
    return sRect;
}


//初始化控件
void WelcomeLayer::setupViews(){
    
    
    setBackgroundImage("loading.png");
    
    
    //加入Logo
    
    Sprite* pLogo=Sprite::create("logo.png");
    pLogo->setAnchorPoint(Vec2(0.5,1));
    Size visibleSize=Director::getInstance()->getVisibleSize();
    pLogo->setPosition(visibleSize.width/2,visibleSize.height/2);
    //pLogo->setPosition(getWinSize.width/2,getWinSize.height/2);
    addChild(pLogo);
    
    //加入菜单项
    
    //第一步：加入开始菜单
    Sprite* pStartNormal=Sprite::create("menu.png",CCRectMake(0, 0, 126, 33));
    Sprite* pStartPressed=Sprite::create("menu.png",CCRectMake(0, 33, 126, 33));
    Sprite* pStartDisabled=Sprite::create("menu.png",CCRectMake(0,66, 126, 33));
  
    MenuItemSprite* startGame=MenuItemSprite::create(pStartNormal, pStartPressed,pStartDisabled,this,menu_selector(WelcomeLayer::startgame_callback));
    
    //第二步：加入关于菜单
    Sprite* pAboutNormal=Sprite::create("menu.png",CCRectMake(252, 0, 126, 33));
    Sprite* pAboutPressed=Sprite::create("menu.png",CCRectMake(252, 33, 126, 33));
    Sprite* pAboutDisabled=Sprite::create("menu.png",CCRectMake(252,66, 126, 33));
    
    MenuItemSprite* aboutGame=MenuItemSprite::create(pAboutNormal, pAboutPressed,pAboutDisabled,this,menu_selector(WelcomeLayer::about_callback));
    
    //第三步：加入选项菜单
    Sprite* pOptionNormal=Sprite::create("menu.png",CCRectMake(126, 0, 126, 33));
    Sprite* pOptionPressed=Sprite::create("menu.png",CCRectMake(126, 33, 126, 33));
    Sprite* pOptionDisabled=Sprite::create("menu.png",CCRectMake(126,66, 126, 33));
    
    MenuItemSprite* optionGame=MenuItemSprite::create(pOptionNormal, pOptionPressed,pOptionDisabled,this,menu_selector(WelcomeLayer::option_callback));
    
    //Size visibleSize=Director::getInstance()->getVisibleSize();
    
    Menu* pMenu=Menu::create(startGame,optionGame,aboutGame, nullptr);
    pMenu->setPosition(visibleSize.width/2,visibleSize.height/2);
    pMenu->alignItemsVerticallyWithPadding(10);
    addChild(pMenu);
    

}


WelcomeLayer::WelcomeLayer(){

}


WelcomeLayer::~WelcomeLayer(){

}


//获取场景指针
Scene* WelcomeLayer::scene(){
    Scene* sc=NULL;
    
    do {
        sc=Scene::create();
        CC_BREAK_IF(!sc);
        
        WelcomeLayer* layer=WelcomeLayer::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
}



//设置背景图片的方法
void BasicLayer::setBackgroundImage(const char* back_image_name){
    
    Sprite* sp=Sprite::create(back_image_name);
    sp->setPosition(getWinSize().width/2,getWinSize().height/2);
    this->addChild(sp);
}

void WelcomeLayer::startgame_callback(CCObject* pSender){
    CCLOG("start game");
}
void WelcomeLayer::option_callback(CCObject* pSender){
    CCLOG("option game");

}
void WelcomeLayer::about_callback(CCObject* pSender){
    CCLOG("about game");
    Director::sharedDirector()->pushScene(TransitionFade::create(0.5f, scene()));
}





