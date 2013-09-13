#include "MonsterLayer.h"
USING_NS_CC;
using namespace std;

using namespace cocos2d;
//フリック入力のための糞マクロ
#define CCR(X) CCRectMake(X->getPosition().x - (X->getContentSize().width/2),X->getPosition().y - (X->getContentSize().height/2),X->getContentSize().width,X->getContentSize().height);

#define STADC(_X_,_Y1_,_Y2_,_Y3_,_Y4_,_Z1_,_Z2_,_Z3_,_Z4_,_T1_,_T2_,_T3_,_T4_) CCSprite* _Y1_ = CCSprite::create(_Z1_);\
_Y1_->setPosition(ccp(_X_->getPositionX()-_X_->getContentSize().width,_X_->getPositionY()));\
this->addChild(_Y1_,0,_T1_);\
CCSprite* _Y2_ = CCSprite::create(_Z2_);\
_Y2_->setPosition(ccp(_X_->getPosition().x,_X_->getPositionY()+_X_->getContentSize().height));\
this->addChild(_Y2_,0,_T2_);\
CCSprite* _Y3_ = CCSprite::create(_Z3_);\
_Y3_->setPosition(ccp(_X_->getPositionX()+_X_->getContentSize().width,_X_->getPositionY()));\
this->addChild(_Y3_,0,_T3_);\
CCSprite* _Y4_ = CCSprite::create(_Z4_);\
_Y4_->setPosition(ccp(_X_->getPosition().x,_X_->getPositionY()-_X_->getContentSize().height));\
this->addChild(_Y4_,0,_T4_);\
_Y1_->retain();\
_Y2_->retain();\
_Y3_->retain();\
_Y4_->retain();\
_Y1_->autorelease();\
_Y2_->autorelease();\
_Y3_->autorelease();\
_Y4_->autorelease();

#define TASP(_X1_,_X2_,_X3_,_X4_,_X5_,_Y1_,_Y2_,_Y3_,_Y4_,_Y5_) CCSprite* _X1_ = (CCSprite*)this->getChildByTag(_Y1_);\
CCSprite* _X2_ = (CCSprite*)this->getChildByTag(_Y2_);\
CCSprite* _X3_ = (CCSprite*)this->getChildByTag(_Y3_);\
CCSprite* _X4_ = (CCSprite*)this->getChildByTag(_Y4_);\
CCSprite* _X5_ = (CCSprite*)this->getChildByTag(_Y5_);\
CCRect rect##_X1_=CCR(_X1_);\
CCRect rect##_X2_=CCR(_X2_);\
CCRect rect##_X3_=CCR(_X3_);\
CCRect rect##_X4_=CCR(_X4_);\
CCRect rect##_X5_=CCR(_X5_);\
_X1_->retain();\
_X2_->retain();\
_X3_->retain();\
_X4_->retain();\
_X5_->retain();\
_X1_->autorelease();\
_X2_->autorelease();\
_X3_->autorelease();\
_X4_->autorelease();\
_X5_->autorelease();



#define TASP2(_X1_,_X2_,_X3_,_X4_,_X5_,_Y1_,_Y2_,_Y3_,_Y4_,_Y5_) \
    if(rect##_X1_.containsPoint(location)){\
    flickLabel->setString(_Y1_);\
    CCLog(_Y1_);\
    }else if(rect##_X2_.containsPoint(location)){\
    flickLabel->setString(_Y2_);\
    CCLog(_Y2_);\
    }else if(rect##_X3_.containsPoint(location)){\
    flickLabel->setString(_Y3_);\
    CCLog(_Y3_);\
    }else if(rect##_X4_.containsPoint(location)){\
    flickLabel->setString(_Y4_);\
    CCLog(_Y4_);\
    }else if(rect##_X5_.containsPoint(location)){\
    flickLabel->setString(_Y5_);\
        CCLog(_Y5_);}




bool MonsterLayer::init()
{
    

    if ( !CCLayer::init() )
    {
        return false;
    }
    CCLog("モーダルレイヤーが呼び出されました");
    /*
    this->setTouchPriority(kMonsterLayerPriority);
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    */
    
     CCSize size = CCDirector::sharedDirector()->getVisibleSize();
     
    CCLog("フリックキーボードレイヤーが呼び出されました");
    //かあさ
    CCSprite* kaF = CCSprite::create("kaF.png");
    kaF->setPosition(ccp(size.width/2,390));
    kaF->setTag(111);
    this->addChild(kaF);
    
    
    CCSprite* aF = CCSprite::create("aF.png");
    aF->setPosition(ccp(kaF->getPosition().x-140,kaF->getPosition().y));
    aF->setTag(101);
    this->addChild(aF);
    
    CCSprite* saF = CCSprite::create("saF.png");
    saF->setPosition(ccp(kaF->getPosition().x+140,kaF->getPosition().y));
    saF->setTag(121);
    this->addChild(saF);
    
    //たなは
    CCSprite* taF = CCSprite::create("taF.png");
    taF->setPosition(ccp(kaF->getPosition().x-140,kaF->getPosition().y-kaF->getContentSize().height-5));
    taF->setTag(131);
    this->addChild(taF);
    
    CCSprite* naF = CCSprite::create("naF.png");
    naF->setPosition(ccp(kaF->getPosition().x,kaF->getPosition().y-kaF->getContentSize().height-5));
    naF->setTag(141);
    this->addChild(naF);
    
    CCSprite* haF = CCSprite::create("haF.png");
    haF->setPosition(ccp(kaF->getPosition().x+140,kaF->getPosition().y-kaF->getContentSize().height-5));
    haF->setTag(151);
    this->addChild(haF);
    
    
    //まやら
    CCSprite* maF = CCSprite::create("maF.png");
    maF->setPosition(ccp(kaF->getPosition().x-140,kaF->getPosition().y-(kaF->getContentSize().height)*2-10));
    maF->setTag(161);
    this->addChild(maF);
    
    CCSprite* yaF = CCSprite::create("yaF.png");
    yaF->setPosition(ccp(kaF->getPosition().x,kaF->getPosition().y-(kaF->getContentSize().height)*2-10));
    yaF->setTag(171);
    this->addChild(yaF);
    
    CCSprite* raF = CCSprite::create("raF.png");
    raF->setPosition(ccp(kaF->getPosition().x+140,kaF->getPosition().y-(kaF->getContentSize().height)*2-10));
    raF->setTag(181);
    this->addChild(raF);
    
    //
    CCSprite* poF = CCSprite::create("poF.png");
    poF->setPosition(ccp(kaF->getPosition().x-140,kaF->getPosition().y-(kaF->getContentSize().height)*3-15));
    poF->setTag(191);
    this->addChild(poF);
    
    CCSprite* waF = CCSprite::create("waF.png");
    waF->setPosition(ccp(kaF->getPosition().x,kaF->getPosition().y-(kaF->getContentSize().height)*3-15));
    waF->setTag(201);
    this->addChild(waF);
    
    CCSprite* coF = CCSprite::create("coF.png");
    coF->setPosition(ccp(kaF->getPosition().x+140,kaF->getPosition().y-(kaF->getContentSize().height)*3-15));
    coF->setTag(211);
    this->addChild(coF);
    
    //大砲
    
    CCSprite* canon = CCSprite::create("設置大砲.png");
    canon->setPosition(ccp(size.width/2,90+size.height/2));
    this->addChild(canon,15);
    


    //HPバーの実装
    
    CCSprite* hpBar = CCSprite::create("BossHPFrame.png");
    hpBar->setPosition(ccp(+size.width/2, -25+size.height/2));
    hpBar->setScaleX(1.5f);
    this->addChild(hpBar,3,34);
    //プログレスバーの実装(HP)
    CCSprite* pSprite2 = CCSprite::create("bar.png");
    pSprite2->setPosition(ccp(size.width/2, -25+size.height/2));
    pSprite2->setScaleX(2.0f);
    this->addChild(pSprite2,2,33);
    

    CCProgressTimer* pTimer2 = CCProgressTimer::create(pSprite2);
    pTimer2->setPercentage(100.0f);
    pTimer2->setPosition(ccp(-100+size.width/2, -25+size.height/2));
    pTimer2->setType(kCCProgressTimerTypeBar);
    pTimer2->setMidpoint(ccp(0,0));
    pTimer2->setBarChangeRate(ccp(1,0));
    
    this->addChild(pTimer2,3,59);
    
    
  //背景の追加
    CCSprite* backGround = CCSprite::create("iphone-grass.png");
    backGround ->setPosition(ccp(size.width/2,0));
    this->addChild(backGround,-1,999);

    
    //打ち込む必要のある文字を表示するラベル
    wordLabel = CCLabelTTF::create("あいうえお", "mosamosa", 70);
    wordLabel->setPosition(ccp(
                               size.width/2,
                               35+size.height/2));
    wordLabel->setTag(13);
    this->addChild(wordLabel,6);
    
    //スコアラベル

    scoreLabel = CCLabelTTF::create("0", "mosamosa", 70);
    scoreLabel->setPosition(ccp(
                               size.width-scoreLabel->getContentSize().width,
                               scoreLabel->getContentSize().height));
    scoreLabel->setTag(39);
    

    this->addChild(scoreLabel,6);
    
    //打ち込んだ文字を表示するラベル
    string date("");
    
    
    flickLabel = CCLabelTTF::create(date.substr(0).c_str(), "mosamosa", 50);
    flickLabel->setPosition(ccp(
                                size.width/2,
                                50+size.height/2));
    flickLabel->setTag(10);
    this->addChild(flickLabel,6);
    
    //タッチの設定
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);

    //お城の表示
    /*
    CCSprite* castle = CCSprite::create("castle.png");
    castle->setPosition( ccp(size.width/2, (size.height/2)+50) );
    castle->setTag(11);
    this->addChild(castle,2,13);
*/
    //敵の表示(アメーバ）
     
     CCSprite* enemy = CCSprite::create("ameba.gif");
     enemy->setPosition( ccp(size.width/2, (size.height*3/2)-enemy->getContentSize().height) );
     enemy->setTag(11);
     this->addChild(enemy, 11);
    
    //アメーバのローテーション
    this->schedule(schedule_selector(MonsterLayer::enemyLogic),4.0f);
    

    return true;
}





//敵の動きを定義した関数
void MonsterLayer::enemyMove()
{
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCSprite* enemy = CCSprite::create("ameba.gif");
    
    // position the sprite on the center of the screen
    enemy->setPosition( ccp(size.width/2-100, size.height));
    
    
    
    enemy->setTag(666);
    // add the sprite as a child to this layer
    this->addChild(enemy, 12);
    
    float duration = 100.0f;
    
    CCActionInterval* action1 =CCMoveTo::create(30/duration, ccp(enemy->getPositionX(),
                                                                 enemy->getPositionY()-30));
    CCActionInterval* action2 =CCMoveTo::create(180/duration, ccp(enemy->getPositionX()+180,
                                                                  enemy->getPositionY()-30));
    
    CCActionInterval* action3 =CCMoveTo::create(60/duration, ccp(enemy->getPositionX()+180,
                                                                 enemy->getPositionY()-90));
    CCActionInterval* action4 =CCMoveTo::create(190/duration, ccp(enemy->getPositionX()-10,
                                                                  enemy->getPositionY()-90));
    
    CCActionInterval* action5 =CCMoveTo::create(160/duration, ccp(enemy->getPositionX()-50,
                                                                  enemy->getPositionY()-250));
    
    CCActionInterval* action6 =CCMoveTo::create(230/duration, ccp(enemy->getPositionX()+180,
                                                                  enemy->getPositionY()-250));
    
    CCActionInterval* action7 =CCMoveTo::create(120/duration, ccp(enemy->getPositionX()+200,
                                                                  enemy->getPositionY()-370));
    
    CCActionInterval* action8 =CCMoveTo::create(100/duration, ccp(enemy->getPositionX()+100,
                                                                  enemy->getPositionY()-370));
    
    CCActionInterval* action9 =CCMoveTo::create(50/duration, ccp(enemy->getPositionX()+100,
                                                                 enemy->getPositionY()-500));
    
    //アクションが終了したときのコールバック
    CCCallFuncN* actionMoveDone =
    CCCallFuncN::create(this, callfuncN_selector(MonsterLayer::spriteMoveFinished));
    
    //CCSequence* adsf =CCSequence::create(action1,action2,action3,action4,action5,action6,action7,action8,action9,actionMoveDone,NULL);
    
   enemy->runAction(CCSequence::create(action1,action2,action3,action4,action5,action6,action7,action8,action9,actionMoveDone,NULL));
    
     float x=0, y=0, z=0;
     enemy->getCamera()->getCenterXYZ(&x, &y, &z);
     enemy->getCamera()->setCenterXYZ(x, y+0.00000011, z);
     
    
}
//アメーバの動作関数のローテーション定義
void MonsterLayer::enemyLogic()
{
    this->schedule(schedule_selector(MonsterLayer::enemyMove),4.0f+enemyR);
}

//アメーバのシーケンスが終了するタイミングで呼び出される
void MonsterLayer::spriteMoveFinished(CCNode* sender)
{
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    //達したら難易度緩和
enemyR +=0.02;
    this->removeChildByTag(33,true);
    CCLog("スプライトが削除されました");
    CCSprite *sprite=(CCSprite*)sender;
    bool isCleanUP = true;
    this->removeChild(sprite,isCleanUP);
    CCLog("スプライトが削除されました");
    CCProgressTimer* pTimer2 = (CCProgressTimer*)this->getChildByTag(59);
    float percent2 = pTimer2->getPercentage();
    percent2 -= 3.0f * 3;
    pTimer2->setPercentage(percent2);
    if (pTimer2->getPercentage()<1) {
        CCLabelTTF*GameOver = CCLabelTTF::create("Game Over", "mosamosa", 50);
        GameOver->setPosition(ccp(
                                   size.width/2,
                                  20+size.height/2));
        
         //ワードラベルにゲームオーバー表示
        wordLabel->setString("Game Over");
       
        //スコア表示
        /*
        score = 1;
        CCString* scoreP = CCString::createWithFormat("%d",score);
        scoreLabel->setString(scoreP->getCString());
        this->addChild(scoreLabel);
   */
        //リプレイボタン
        CCRect spriteRect = CCRectMake(0, 0, 80, 80);
        
        CCRect capInsents = CCRectMake(12, 12, 56, 56);
        CCScale9Sprite* backgroundSprite3 = CCScale9Sprite::create("button9.png", spriteRect, capInsents);
        CCLabelTTF* label3 = CCLabelTTF::create("リプレイ", "mosamosa", 70);
        CCControlButton* button3 = CCControlButton::create(label3, backgroundSprite3);
        button3->setPreferredSize(CCSizeMake(300, 100));
        button3->setPosition(ccp(size.width/2,120+size.height/2));
            this->addChild(button3,200,53);
            button3->addTargetWithActionForControlEvents(this, cccontrol_selector(MonsterLayer::switchCallBack), CCControlEventTouchUpInside);
        
        
        
        

        
        
        
       
    }
     this->removeChild(button3,true);
}
//リプレイボタンが押されたときの設定
void MonsterLayer::switchCallBack(CCObject* pSender, CCControlEvent controlEvent)
{
    

    
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);
    this->removeChildByTag(53);


    
  
    CCProgressTimer* pTimer2 = (CCProgressTimer*)this->getChildByTag(59);
    float percent2 = 100.0f;
    pTimer2->setPercentage(percent2);

   
    this->removeChildByTag(666,true);
     this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true); this->removeChildByTag(666,true);
            
    wordLabel->setString("またすたーと");
    
    //難易度初期化
    enemyR = 0.5f;
    
    //スコアの初期化
    this->m_points =0;
    
    // スコアポイントのラベルを取得
    CCLabelTTF* label = (CCLabelTTF *)this->getChildByTag(39);
    // intからCCStringに変換
    CCString* points = CCString::createWithFormat("%d", this->m_points);
    // スコアポイントの表示を更新
    label->setString(points->getCString());

   
   
}
////////////フリック入力画面の実装/////////////////////////////////////////////////
void MonsterLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCLog("タッチ開始");
    
    
    CCSprite* aF = (CCSprite*)this->getChildByTag(101);
    CCSprite* kaF = (CCSprite*)this->getChildByTag(111);
    CCSprite* saF = (CCSprite*)this->getChildByTag(121);
    CCSprite* taF = (CCSprite*)this->getChildByTag(131);
    CCSprite* naF = (CCSprite*)this->getChildByTag(141);
    CCSprite* haF = (CCSprite*)this->getChildByTag(151);
    CCSprite* maF = (CCSprite*)this->getChildByTag(161);
    CCSprite* yaF = (CCSprite*)this->getChildByTag(171);
    CCSprite* raF = (CCSprite*)this->getChildByTag(181);
    CCSprite* waF = (CCSprite*)this->getChildByTag(201);
    CCRect rectA =aF->boundingBox();
    CCRect rectKa =kaF->boundingBox();
    CCRect rectSa =saF->boundingBox();
    CCRect rectTa =taF->boundingBox();
    CCRect rectNa =naF->boundingBox();
    CCRect rectHa =haF->boundingBox();
    CCRect rectMa =maF->boundingBox();
    CCRect rectYa =yaF->boundingBox();
    CCRect rectRa =raF->boundingBox();
    CCRect rectWa =waF->boundingBox();

    //CCRect rectK =kaF->boundingBox();
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    
    if (rectA.containsPoint(location)) {
        STADC(aF, iF, uF, eF, oF, "iF.png", "uF.png", "eF.png", "oF.png", 102, 103, 104, 105);
       
    }else if(rectKa.containsPoint(location)){
        STADC(kaF, kiF, kuF, keF, koF, "kiF.png", "kuF.png", "keF.png", "koF.png", 112, 113, 114, 115);

    }else if(rectSa.containsPoint(location)){
        STADC(saF, siF, suF, seF, soF, "siF.png", "suF.png", "seF.png", "soF.png", 122, 123, 124, 125);
        
    }else if(rectTa.containsPoint(location)){
        STADC(taF, tiF, tuF, teF, toF, "tiF.png", "tuF.png", "teF.png", "toF.png", 132, 133, 134, 135);
        
    }else if(rectNa.containsPoint(location)){
        STADC(naF, niF, nuF, neF, noF, "niF.png", "nuF.png", "neF.png", "noF.png", 142, 143, 144, 145);
        
    }else if(rectHa.containsPoint(location)){
        STADC(haF, hiF, huF, heF, hoF, "hiF.png", "huF.png", "heF.png", "hoF.png", 152, 153, 154, 155);
        
    }else if(rectMa.containsPoint(location)){
        STADC(maF, miF, muF, meF, moF, "miF.png", "muF.png", "meF.png", "moF.png", 162, 163, 164, 165);
        
    }else if(rectYa.containsPoint(location)){
        CCSprite* yuF = CCSprite::create("yuF.png");
        yuF->setPosition(ccp(yaF->getPosition().x,yaF->getPositionY()+yaF->getContentSize().height));
        this->addChild(yuF,0,173);
        CCSprite* yoF = CCSprite::create("yoF.png");
        yoF->setPosition(ccp(yaF->getPosition().x,yaF->getPositionY()-yaF->getContentSize().height));
        this->addChild(yoF,0,175);
        yuF->retain();
        yoF->retain();
        yuF->autorelease();
        yoF->autorelease();

       

        
    }else if(rectRa.containsPoint(location)){
        STADC(raF, riF, ruF, reF, roF, "riF.png", "ruF.png", "reF.png", "roF.png", 182, 183, 184, 185);
        
    }else if(rectWa.containsPoint(location)){
        CCSprite* woF = CCSprite::create("woF.png");
        woF->setPosition(ccp(waF->getPositionX()-waF->getContentSize().width,waF->getPositionY()));
        this->addChild(woF,0,202);
        CCSprite* nnF = CCSprite::create("nnF.png");
        nnF->setPosition(ccp(waF->getPosition().x,waF->getPositionY()+waF->getContentSize().height));
        this->addChild(nnF,0,203);
        CCSprite* barF = CCSprite::create("barF.png");
        barF->setPosition(ccp(waF->getPositionX()+waF->getContentSize().width,waF->getPositionY()));
        this->addChild(barF,0,204);
        
        woF->retain();\
        nnF->retain();\
        barF->retain();\
        woF->autorelease();\
        nnF->autorelease();\
        barF->autorelease();\
        
        
    }
}
void MonsterLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    
    
}
void MonsterLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    
    CCLog("タッチが離れました");
    
    CCLog("離れるタッチ位置を設定");
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint location = touch->getLocationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
 
    CCSprite* AA = (CCSprite*)this->getChildByTag(103);
    CCSprite* KK = (CCSprite*)this->getChildByTag(113);
    CCSprite* SS = (CCSprite*)this->getChildByTag(123);
    CCSprite* TT = (CCSprite*)this->getChildByTag(133);
    CCSprite* NN = (CCSprite*)this->getChildByTag(143);
    CCSprite* HH = (CCSprite*)this->getChildByTag(153);
    CCSprite* MM = (CCSprite*)this->getChildByTag(163);
    CCSprite* YY = (CCSprite*)this->getChildByTag(173);
    CCSprite* RR = (CCSprite*)this->getChildByTag(183);
    CCSprite* WW = (CCSprite*)this->getChildByTag(203);

    if (!(AA==NULL)) {
        TASP(aF,iF,uF,eF,oF,101,102,103,104,105);
        TASP2(aF, iF, uF, eF, oF, "あ", "い", "う", "え", "お")
        this->removeChildByTag(102,true);
        this->removeChildByTag(103,true);
        this->removeChildByTag(104,true);
        this->removeChildByTag(105,true);

        
    }
    if (!(KK==NULL)){
        TASP(kaF, kiF, kuF, keF, koF, 111, 112, 113, 114, 115);
        TASP2(kaF, kiF, kuF, keF, koF, "か", "き", "く", "け", "こ")
        this->removeChildByTag(112,true);
        this->removeChildByTag(113,true);
        this->removeChildByTag(114,true);
        this->removeChildByTag(115,true);
        
    }
    if (!(SS==NULL)){
      TASP(saF, siF, suF, seF, soF, 121, 122, 123, 124, 125);
         TASP2(saF, siF, suF, seF, soF, "さ", "し", "す", "せ", "そ")
        this->removeChildByTag(122,true);
        this->removeChildByTag(123,true);
        this->removeChildByTag(124,true);
        this->removeChildByTag(125,true);
    }
    if (!(TT==NULL)){
        TASP(taF, tiF, tuF, teF, toF, 131, 132, 133, 134, 135);
        TASP2(taF, tiF, tuF, teF, toF, "た", "ち", "つ", "て", "と")
        this->removeChildByTag(132,true);
        this->removeChildByTag(133,true);
        this->removeChildByTag(134,true);
        this->removeChildByTag(135,true);

        
    }
    if (!(NN==NULL)){
        TASP(naF, niF, nuF, neF, noF, 141, 142, 143, 144, 145);
        TASP2(naF, niF, nuF, neF, noF, "な", "に", "ぬ", "ね", "の")
        this->removeChildByTag(142,true);
        this->removeChildByTag(143,true);
        this->removeChildByTag(144,true);
        this->removeChildByTag(145,true);
        
    }
    if (!(HH==NULL)){
        TASP(haF, hiF, huF, heF, hoF, 151, 152, 153, 154, 155);
        TASP2(haF, hiF, huF, heF, hoF, "は", "ひ", "ふ", "へ", "ほ")
        this->removeChildByTag(152,true);
        this->removeChildByTag(153,true);
        this->removeChildByTag(154,true);
        this->removeChildByTag(155,true);
        
    }
    if (!(MM==NULL)){
        
        TASP(maF, miF, muF, meF, moF, 161, 162, 163, 164, 165);
        TASP2(maF, miF, muF, meF, moF, "ま", "み", "む", "め", "も")
        this->removeChildByTag(162,true);
        this->removeChildByTag(163,true);
        this->removeChildByTag(164,true);
        this->removeChildByTag(165,true);
        
    }
    if (!(YY==NULL)){
        //TASP(yaF, yiF, yuF, yeF, yoF, 171, 172, 173, 174, 175);
        
        
        CCSprite* yaF = (CCSprite*)this->getChildByTag(171);\
        CCSprite* yuF = (CCSprite*)this->getChildByTag(173);\
        CCSprite* yoF = (CCSprite*)this->getChildByTag(175);\

        CCRect rectyaF=CCR(yaF);\
        CCRect rectyuF=CCR(yuF);\
        CCRect rectyoF=CCR(yoF);\
        yaF->retain();\
        yuF->retain();\
        yoF->retain();\
        yaF->autorelease();\
        yuF->autorelease();\
        yoF->autorelease();\
        //TASP2(yaF, yiF, yuF, yeF, yoF, "や", "い", "ゆ", "え", "よ")
        if(rectyaF.containsPoint(location)){
            flickLabel->setString("や");
            CCLog("や");\
        }else if(rectyuF.containsPoint(location)){\
            flickLabel->setString("ゆ");\
            CCLog("ゆ");\
        }else if(rectyoF.containsPoint(location)){\
            flickLabel->setString("よ");\
            CCLog("よ");\
        }
      
        this->removeChildByTag(172,true);
        this->removeChildByTag(173,true);
        this->removeChildByTag(174,true);
        this->removeChildByTag(175,true);
        
    }
    if (!(RR==NULL)){
        TASP(raF, riF, ruF, reF, roF, 181, 182, 183, 184, 185);
        TASP2(raF, riF, ruF, reF, roF, "ら", "り", "る", "れ", "ろ")
        this->removeChildByTag(182,true);
        this->removeChildByTag(183,true);
        this->removeChildByTag(184,true);
        this->removeChildByTag(185,true);
        
    }
    if (!(WW==NULL)){
       
        CCSprite* waF = (CCSprite*)this->getChildByTag(201);
        CCSprite* woF = (CCSprite*)this->getChildByTag(202);
        CCSprite* nnF = (CCSprite*)this->getChildByTag(203);
        CCSprite* barF = (CCSprite*)this->getChildByTag(204);
        
        CCRect rectwaF=CCR(waF);
        CCRect rectwoF=CCR(woF);
        CCRect rectnnF=CCR(nnF);
        CCRect rectbarF=CCR(barF);

        waF->retain();
        woF->retain();
        nnF->retain();
        barF->retain();
        waF->autorelease();
        woF->autorelease();
        nnF->autorelease();
        barF->autorelease();
        //TASP2(yaF, yiF, yuF, yeF, yoF, "や", "い", "ゆ", "え", "よ")
        if(rectwaF.containsPoint(location)){
            flickLabel->setString("わ");
            CCLog("わ");
        }else if(rectwoF.containsPoint(location)){
            flickLabel->setString("を");
            CCLog("を");
        }else if(rectnnF.containsPoint(location)){
            flickLabel->setString("ん");
            CCLog("ん");
        }else if(rectbarF.containsPoint(location)){
            flickLabel->setString("ー");
            CCLog("ー");
        
        this->removeChildByTag(202,true);
        this->removeChildByTag(203,true);
        this->removeChildByTag(204,true);
        this->removeChildByTag(205,true);
        
    }
    
    }



   
    CCLog("ここまでや？");

    
    this->removeChildByTag(102,true);
    this->removeChildByTag(103,true);
    this->removeChildByTag(104,true);
    this->removeChildByTag(105,true);
    this->removeChildByTag(112,true);
    this->removeChildByTag(113,true);
    this->removeChildByTag(114,true);
    this->removeChildByTag(115,true);

    this->removeChildByTag(122,true);
    this->removeChildByTag(123,true);
    this->removeChildByTag(124,true);
    this->removeChildByTag(125,true);

    this->removeChildByTag(132,true);
    this->removeChildByTag(133,true);
    this->removeChildByTag(134,true);
    this->removeChildByTag(135,true);

    this->removeChildByTag(142,true);
    this->removeChildByTag(143,true);
    this->removeChildByTag(144,true);
    this->removeChildByTag(145,true);

    this->removeChildByTag(152,true);
    this->removeChildByTag(153,true);
    this->removeChildByTag(154,true);
    this->removeChildByTag(155,true);

    this->removeChildByTag(162,true);
    this->removeChildByTag(163,true);
    this->removeChildByTag(164,true);
    this->removeChildByTag(165,true);

    this->removeChildByTag(172,true);
    this->removeChildByTag(173,true);
    this->removeChildByTag(174,true);
    this->removeChildByTag(175,true);

    this->removeChildByTag(182,true);
    this->removeChildByTag(183,true);
    this->removeChildByTag(184,true);
    this->removeChildByTag(185,true);

    this->removeChildByTag(202,true);
    this->removeChildByTag(203,true);
    this->removeChildByTag(204,true);
    this->removeChildByTag(205,true);

 
 
    CCCallFuncN* flickDone =
    CCCallFuncN::create(this,callfuncN_selector(MonsterLayer::flickFinished));
    
    runAction(flickDone);
     
    CCLog("指がはなれた");
    
}
////////////フリック入力画面の実装終了！！///////////////////////////////////////
void MonsterLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    
}

void MonsterLayer::flickFinished(CCNode* sender){
    CCLog("フリック終わったよ");
    
    //フリック音
    effectsound(4);
    
    const char *abc = "";
    
    
       CCLog("ラベルの文字を読み込むよ");
 
     
    /*
     //CCSize size = CCDirector::sharedDirector()->getWinSize();
     //$BC18l%i%Y%k$NJ8;z$r<hF@(B
     string str(flickLabel->getString());
     //$B:G=i$NJ8;z$r<hF@(B
     str.substr(0,2);
     // CCLog("%s",str.substr(0,1).c_str());
     cout << "文字数は" << str.size() << endl;
     CCLog("文字数は%s",str.substr(str.size()/2,2).c_str());
     //$B%(%G%#%C%H%\%C%/%9$NJ8;z$r<hF@(B
     */
    string str = wordLabel->getString();
   
    
   
     CCString *hoge1 = CCString::create(str.substr(0,3).c_str());
     CCString *hoge2 = CCString::create(flickLabel->getString());
     CCString *hoge3 = CCString::create(str.substr(str.size()-3,3).c_str());
    
    //二つのラベルに記入された文字を照合します。日本語は3byteを想定しています。String型で文字を一文字ずつ取り出します。
      CCLog("文字の照合を始めるよ");
    if (hoge1->isEqual(hoge2) && hoge3->isEqual(hoge2) && str.size()==3) {
          CCLog("配列を作るよ");
        
        int i = rand()%14;
        char    mtxary[][70]   = {"まうす","いわさきくん","さかもとさん", "わーい", "ほりくん","しろとくろ","おいういう","らいと","わーい","やさいふそく","すーん","かわいい","えいゆ","いけめん"};
        //CCSize size = CCDirector::sharedDirector()->getWinSize();
        
       
        wordLabel->setString(mtxary[i]);
        flickLabel->setString(abc);
        q=0;
        
        CCSprite* enemy = (CCSprite*)this->getChildByTag(666);
        
        this->m_points +=1;
        
        // スコアポイントのラベルを取得
        CCLabelTTF* label = (CCLabelTTF *)this->getChildByTag(39);
        // intからCCStringに変換
        CCString* points = CCString::createWithFormat("%d", this->m_points);
        // スコアポイントの表示を更新
        label->setString(points->getCString());
        //敵を倒すと頻度が上がる
        enemyR -=0.1;
        
        //敵の存在意義を・・・説きます！(敵が現れてからインスタンス作成)
        if (!(enemy==NULL)) {
            //砲弾の動き
            CCSprite* face = CCSprite::create("kao.png");
            CCSize size = CCDirector::sharedDirector()->getWinSize();
            face->setPosition(ccp(size.width/2,(size.height/2)+100));
            CCMoveTo *faceaction = CCMoveTo::create(0.1f,ccp(enemy->getPosition().x,enemy->getPosition().y));
            CCFadeOut *fadeout = CCFadeOut::create(0.1f);
            face->runAction(CCSequence::create(faceaction,fadeout,NULL));
            this->addChild(face,30);
        
        
        //アニメーション　消滅アクション
        CCSprite *metu = CCSprite::create("小爆発.png");
        metu->setScale(1.0);
        CCFadeIn *killin = CCFadeIn::create(0.1f);
        metu->setPosition(ccp(enemy->getPosition().x,enemy->getPosition().y));
        metu->runAction(killin);
        CCDelayTime *delay = CCDelayTime::create(0.1f);
        CCActionInterval *reverse = killin->reverse();
        metu->runAction(CCSequence::create(killin,delay,reverse,NULL));
        this->addChild(metu,40);
        }
        //効果音
        effectsound(3);
        this->removeChild(enemy);
        
 CCLog("全文字消えました");
    
     
    }else if (hoge1->isEqual(hoge2)) {
        CCLog("一文字消えました");
         q +=3;
         wordLabel->setString(str.substr(q,str.size()-q).c_str());
         flickLabel->setString(abc);
         q=0;
     }
     else{
         flickLabel->setString(abc);
         CCLog("まちがい");
         
     }
  
         CCLog("文字を照合した");
}

void MonsterLayer::effectsound(int i)
{
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    switch(i)
    {
        case 0:
            SimpleAudioEngine::sharedEngine()->preloadEffect("ずば.mp3");
            int sword1;
            sword1 = SimpleAudioEngine::sharedEngine()->playEffect("ずば.mp3");
            break;
            
        case 1:
            SimpleAudioEngine::sharedEngine()->preloadEffect("ざしゅ.mp3");
            int sword2;
            sword2 = SimpleAudioEngine::sharedEngine()->playEffect("ざしゅ.mp3");
            break;
            
        case 2:
            SimpleAudioEngine::sharedEngine()->preloadEffect("どっごーん.mp3");
            int explosion;
            explosion = SimpleAudioEngine::sharedEngine()->playEffect("どっごーん.mp3");
            break;
        case 3:
            SimpleAudioEngine::sharedEngine()->preloadEffect("滅.mp3");
            int vanish;
            vanish = SimpleAudioEngine::sharedEngine()->playEffect("滅.mp3");
            break;
        case 4:
            SimpleAudioEngine::sharedEngine()->preloadEffect("ぴゃっ.mp3");
            int fmusic;
            fmusic = SimpleAudioEngine::sharedEngine()->playEffect("ぴゃっ.mp3");
            break;
    }
}