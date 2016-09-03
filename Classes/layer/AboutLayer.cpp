//
//  AboutLayer.cpp
//  MyMoonWarrior
//
//  Created by 杜杜兴 on 16/7/13.
//
//

#include "AboutLayer.hpp"


bool AboutLayer::init(){
    bool sRect=false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        setupViews();
        
        sRect=true;
    } while (0);
    
    return sRect;
}

//获取场景指针
Scene* AboutLayer::scene(){
    Scene* sc=NULL;
    
    do {
        sc=Scene::create();
        CC_BREAK_IF(!sc);
        
        WelcomeLayer* layer=WelcomeLayer::create();
        CC_BREAK_IF(!layer);
        
        sc->addChild(layer);
    } while (0);
}


AboutLayer::AboutLayer(){

}

AboutLayer::~AboutLayer(){
}

void AboutLayer::setupViews(){
    //setBackgroundInage("loading.png");
    
    //加入title
    Sprite* title=Sprite::create("menuTitle.png",CCRectMake(0,33,130,38));
    //title->setAnchorPoint(0.5,1);
    title->setPosition(getWinSize.width/2,getWinSize.height/2);
    addChild(title);
    
    //加入文字说明
    LabelBMFont* pDes=LabelBMFont::create("this Game is recoded by duxingcai", "arial-14.fnt");
    //pDes->setPosition(getWinSize.width/2,getWinSize.height/2);
    addChild(pDes);
    
    LabelBMFont* fontOfBack=LabelBMFont::create("Go Back");
    fontOfBack->setScale(1.5f);
    
    MenuItemLabel* backLabel=MenuItemLabel::create(fontOfBack,this,menu_selector(AboutLayer::back_callback));
    backLabel->setAnchorPoint(0.5,0);
    backLabel->setPosition(getWinSize.width/2,30);
    
    Menu* menu=Menu::create(backLabel,NULL);
    menu->setPosition(CCPointZero);
    addChild(menu);
}

void AboutLayer::back_callback(CCObject* pSender){
    Director::sharedDirector()->pushScene(TransitionFade::create(0.5f,WelcomeLayer::scene()));
}
