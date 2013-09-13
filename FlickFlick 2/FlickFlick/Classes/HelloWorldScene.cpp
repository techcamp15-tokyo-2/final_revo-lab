#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer,0,41);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //タッチの設定
    setTouchEnabled(true);
    setTouchMode(kCCTouchesAllAtOnce);
    //画面サイズ取得
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    //プロローグ
    CCSprite *prologue = CCSprite::create("プロローグ　笑.png");
    prologue->setPosition(ccp(size.width/2,size.height/2));
    CCDelayTime *delay = CCDelayTime::create(5.0f);
    CCFadeOut *fadeOut = CCFadeOut::create(0.8f);
    prologue->runAction(CCSequence::create(delay, fadeOut, NULL));
    this->addChild(prologue,20);
    
    //トップ画面
    CCSprite* top = CCSprite::create("画面.png");
    top->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(top,0,20);
    
    //OP再生
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("OP.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("OP.mp3");
    
   //すたーとボタン
    CCRect spriteRect = CCRectMake(0, 0, 80, 80);
    
    CCRect capInsents = CCRectMake(12, 12, 56, 56);
    CCScale9Sprite* backgroundSprite2 = CCScale9Sprite::create("button9.png", spriteRect, capInsents);
    CCLabelTTF* label2 = CCLabelTTF::create("GAME START", "mosamosa", 50);
    CCControlButton* button2 = CCControlButton::create(label2, backgroundSprite2);
    button2->setPreferredSize(CCSizeMake(550, 140));
    button2->setPosition(ccp(size.width/2, 100));
    this->addChild(button2,3,31);
    button2->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::switchCallBack), CCControlEventTouchUpInside);
    return true;
}
void HelloWorld::switchCallBack(CCObject* pSender, CCControlEvent controlEvent)
{
    CCLog("ボタンが押されました");
    
    this->removeChildByTag(20);
  
    ModalLayer *layer = ModalLayer::create();
    this ->addChild(layer,2);
    
MonsterLayer *layer2 = MonsterLayer::create();
    this ->addChild(layer2,2);
    
    this->removeChildByTag(31);
    
    //FlickKeyBoardLayer *layer3 = FlickKeyBoardLayer::create();
    //this->addChild(layer3,2);
      /*
    FlickActionLayer *layer1 = FlickActionLayer::create();
    this ->addChild(layer1,1);
    
    */
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
