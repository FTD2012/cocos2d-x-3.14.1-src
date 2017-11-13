//
// Created by 吕佳明 on 2017/11/6.
//

#include "CCNodeTree.h"
#include <string>
#include <typeinfo>

using namespace std;

NS_CC_BEGIN

    static NodeTreeMap *s_sharedNodeTree = nullptr;

    NodeTreeMap::NodeTreeMap() : _maxTreeDepth(5) {
    }

    NodeTreeMap::~NodeTreeMap() {
    }

    NodeTreeMap *NodeTreeMap::getInstance() {
        if (!s_sharedNodeTree) {
            s_sharedNodeTree = new(std::nothrow) NodeTreeMap;
            CCASSERT(s_sharedNodeTree, "FATAL: Not enough memory");
            s_sharedNodeTree->init();
        }
        return s_sharedNodeTree;
    }


    bool NodeTreeMap::init() {
        return true;
    }

    void NodeTreeMap::getNodeTree(Node *target, int maxTreeDepth /*= 5*/) {
        if (_maxTreeDepth != maxTreeDepth) {
            _maxTreeDepth = maxTreeDepth;
        }

        CCLOG("\n=-=-=-=-=-=-=-=-=-  Display tree map [%s]  -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n", typeid(*target).name());
        getNodeTreeMap(target);
        CCLOG("\n=-=-=-=-=-=-=-=  Display tree map [%s] finish  =-=-=-=-=-=-=-=-=-=-=-=-=-=\n", typeid(*target).name());

    }


    //  │ ├ ─ └

    void NodeTreeMap::getNodeTreeMap(Node *target, int depth /*= 1*/) {

        std::string formatString = "";
        for (int i = 0; i < depth; i++) {
            formatString += "\t";
        }

        if (depth <= _maxTreeDepth) {

            /* format string */
            formatString += "[%d]-%s";

            /* current node */
            std::string componentType = typeid(*target).name();
            CCLOG(formatString.c_str(), depth, componentType.c_str());

            const auto &children = target->getChildren();
            for (const auto &child : children) {

                /* children */
                getNodeTreeMap(child, depth+1);

            }

        } else {

            /* format string */
            formatString += "[%d]-GetMaxTreeDepth";
            CCLOG(formatString.c_str(), depth);

        }

    }



NS_CC_END




