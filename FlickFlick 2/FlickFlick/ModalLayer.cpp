//
//  ModalLayer.cpp
//  Modal
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//
//

#include "ModalLayer.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace CocosDenshion;

// モーダルレイヤの優先順位
#define kModalLayerPriority kCCMenuHandlerPriority-1
// モーダルレイア上のCCMenuの優先順位
#define kModalLayerMenuPriority kCCMenuHandlerPriority-2

using namespace cocos2d;

bool ModalLayer::init()
{
    
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCLog("モーダルレイヤーが呼び出されました");
   

    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    
    CCSprite* pSprite = CCSprite::create("waves.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, (size.height/2)+1100) );
    
        
    //BGM
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("BGM.mp3");
    //音楽を再生する
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("BGM.mp3",true);
    // add the sprite as a child to this layer
    this->addChild(pSprite, 200);
    

    
    
    float x=0, y=0, z=0;
    this->getCamera()->getCenterXYZ(&x, &y, &z);
    this->getCamera()->setCenterXYZ(x, y+0.00000011, z);
    
      
    return true;
}
/*

bool ModalLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    // can not touch on back layers
    CCLog("モーダルレイヤー上でタッチされました");
    return true;
}
*/
void ModalLayer::menuCloseCallback(CCObject* pSender)
{
    this->removeFromParentAndCleanup(true);
}
