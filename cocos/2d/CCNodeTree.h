//
// Created by 吕佳明 on 2017/11/6.
//

#ifndef __CCNODETREE_H_
#define __CCNODETREE_H_

#include "2d/CCNode.h"
#include "cocos/base/ccMacros.h"

NS_CC_BEGIN

    class Node;

    class NodeTreeMap : public Node {

    public:
        NodeTreeMap();

        ~NodeTreeMap();

        bool init();

        static NodeTreeMap *getInstance();

        void getNodeTree(Node *node, int maxTreeDepth = 5);

    private:

        void getNodeTreeMap(Node *node, int depth = 1);
        int _maxTreeDepth;
    };


NS_CC_END

#endif //__CCNODETREE_H_
