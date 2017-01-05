//
//  VROAnimationGroup.h
//  ViroRenderer
//
//  Created by Raj Advani on 12/28/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#ifndef VROAnimationGroup_h
#define VROAnimationGroup_h

#include <stdio.h>
#include <vector>
#include <map>
#include "VROPropertyAnimation.h"
#include "VROTimingFunction.h"
#include "VROExecutableAnimation.h"

class VRONode;

/*
 An animation group is a set of VROPropertyAnimations that
 execute simultaneously.
 */
class VROAnimationGroup : public VROExecutableAnimation {
    
public:
    
    static std::shared_ptr<VROAnimationGroup> parse(float duration, float delay, std::string functionName,
                                                    std::map<std::string, std::string> &properties);
    
    VROAnimationGroup(float duration, float delay,
                      VROTimingFunctionType timingFunction,
                      std::map<std::string, std::shared_ptr<VROPropertyAnimation>> &animations) :
        _durationMillis(duration),
        _delayMillis(delay),
        _timingFunctionType(timingFunction),
        _animations(animations) {}
    virtual ~VROAnimationGroup() {}
    
    void execute(std::shared_ptr<VRONode> node,
                 std::function<void()> onFinished);
    
    void pause();
    void resume();
    void terminate();
    
    std::string toString() const;
    
private:
    
    static VROTimingFunctionType parseTimingFunction(std::string &name);
    
    float _durationMillis;
    float _delayMillis;
    VROTimingFunctionType _timingFunctionType;
    
    std::shared_ptr<VROTransaction> _transaction;
    
    void animatePosition(std::shared_ptr<VRONode> &node);
    void animateScale(std::shared_ptr<VRONode> &node);
    void animateColor(std::shared_ptr<VRONode> &node);
    void animateOpacity(std::shared_ptr<VRONode> &node);
    void animateRotation(std::shared_ptr<VRONode> &node);

    std::map<std::string, std::shared_ptr<VROPropertyAnimation>> _animations;
    
};

#endif /* VROAnimationGroup_h */
