#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;


Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
//
//    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, nullptr);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//
//    auto label = Label::createWithTTF("Hello World", "fonts/arial.ttf", TITLE_FONT_SIZE);
//
//    // position the label on the center of the screen
//    label->setPosition(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height);
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize / 2) + origin);
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite);

//    auto systemFontLabel = Label::createWithSystemFont("createWithSystemFont", "fonts/A Damn Mess.ttf", 24);
//    systemFontLabel->setPosition(Vec2(visibleSize/2));
//    systemFontLabel->setName("createWithTTF");
//    systemFontLabel->setOnEnterCallback([]()->void { CCLOG("This is systemFontLabel setOnEnterCallback");});
//    this->addChild(systemFontLabel);

//    auto ttfLabel = Label::createWithTTF("createWithTTF", "fonts/arial.ttf", 23);
//    ttfLabel->setPosition(Vec2(visibleSize/2));
//    ttfLabel->setName("createWithTTF");
//    this->addChild(ttfLabel);

    TTFConfig _ttfConfig("fonts/arial.ttf", 23, GlyphCollection::DYNAMIC, NULL, true);
    Label* createWithTTFConfigLabel = Label::createWithTTF(_ttfConfig, "createWithTTFConfigLabel");
    createWithTTFConfigLabel->setPosition(Vec2(visibleSize/2));
    createWithTTFConfigLabel->setName("createWithTTFConfigLabel");
    this->addChild(createWithTTFConfigLabel);

    auto action = Sequence::create(
            DelayTime::create(1.0f),
            ScaleTo::create(6.0f,5.0f,5.0f),
            ScaleTo::create(6.0f,1.0f,1.0f),
            nullptr);
    createWithTTFConfigLabel->runAction(RepeatForever::create(action->clone()));


//    Label* creatWithBMFont = Label::createWithBMFont("fonts/arial-unicode-26.fnt", "createWithBMFont");
//    creatWithBMFont->setPosition(Vec2(visibleSize/2));
//    creatWithBMFont->setName("creatWithBMFont");
//    this->addChild(creatWithBMFont);

//    Label* createWithCharMap = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap-hd.plist");
//    createWithCharMap->setString("createWithCharMap");
//    createWithCharMap->setPosition(Vec2(visibleSize/2));
//    createWithCharMap->setName("createWithCharMap");
//    this->addChild(createWithCharMap);

//    Label* createWithCharMapPng = Label::createWithCharMap("fonts/tuffy_bold_italic-charmap-hd.png", 96, 128, 32);
//    createWithCharMapPng->setString("createWithCharMapPng");
//    createWithCharMapPng->setPosition(Vec2(visibleSize/2));
//    createWithCharMapPng->setName("createWithCharMapPng");
//    this->addChild(createWithCharMapPng);
//
//    Texture2D* charMapTexture = Director::getInstance()->getTextureCache()->addImage("fonts/tuffy_bold_italic-charmap-hd.png");
//    if (charMapTexture) {
//        Label* createWithCharMapTexture = Label::createWithCharMap(charMapTexture, 96, 128, 32);
//        createWithCharMapTexture->setString("createWithCharMapTexture");
//        createWithCharMapTexture->setPosition(Vec2(visibleSize/2));
//        createWithCharMapTexture->setName("createWithCharMapTexture");
//        this->addChild(createWithCharMapTexture);
//    }

//    DrawNode* drawNode = DrawNode::create();
//    drawNode->drawLine(Vec2(100, 100), Vec2(200 ,200), Color4F::BLUE);
//    this->addChild(drawNode);

    return true;
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
