//
//  ModalLayer.h
//  FlickFlogFrog
//
//  Created by 高取 泰洋 on 2013/09/06.
//
//

#ifndef __Modal__ModalScene__
#define __Modal__ModalScene__
#include "cocos2d.h"

class ModalLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    //敵の動き
    void enemyMove();
    void menuCloseCallback(CCObject* pSender);
    void spriteMoveFinished(CCNode* sender);
    
    CREATE_FUNC(ModalLayer);
};

#endif /* defined(__Modal__ModalScene__) */
