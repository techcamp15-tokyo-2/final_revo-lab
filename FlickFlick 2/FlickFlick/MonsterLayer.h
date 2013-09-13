//
//  ModalLayer.h
//  FlickFlogFrog
//
//  Created by 高取 泰洋 on 2013/09/06.
//
//

#ifndef __Monster__MonsterScene__
#define __Monster__MonsterScene__
#include "cocos2d.h"
#include "string.h"
#include "CCControlExtensions.h"
#include "ModalLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

using namespace std;
class MonsterLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    //敵の動き
    void enemyMove();
    void menuCloseCallback(CCObject* pSender);
    void enemyLogic();
    void spriteMoveFinished(CCNode* sender);
    
    void enemyOut();
    void tensou();
    
    //効果音
    void effectsound(int i);
    float percent2;
    int q =0;
    int m_points;
    float enemyR;

    cocos2d::CCLabelTTF* flickLabel;
    cocos2d::CCLabelTTF* scoreLabel;
    CCControlButton* button3;
    cocos2d::CCLabelTTF* wordLabel;
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    void switchCallBack(CCObject* pSender, CCControlEvent controlEvent);

    
    void flickFinished(CCNode* sender);

    
    CREATE_FUNC(MonsterLayer);
};

#endif /* defined(__Monster__MonsterScene__) */
