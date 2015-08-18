/*!
  @file
  @author Shin'ichiro Nakaoka
*/

#ifndef CNOID_JVRC_PLUGIN_JVRC_MANAGER_ITEM_H
#define CNOID_JVRC_PLUGIN_JVRC_MANAGER_ITEM_H

#include "JVRCTaskInfo.h"
#include <cnoid/SubSimulatorItem>

namespace cnoid {

class JVRCManagerItemImpl;
class BodyItem;

class CNOID_EXPORT JVRCManagerItem : public SubSimulatorItem
{
public:
    static void initializeClass(ExtensionManager* ext);
    static JVRCManagerItem* instance();
        
    JVRCManagerItem();
    JVRCManagerItem(const JVRCManagerItem& org);
    ~JVRCManagerItem();

    JVRCTaskInfoPtr taskInfo();
    bool loadJVRCInfo(const std::string& filename);
    SignalProxy<void()> sigTaskInfoUpdated();

    BodyItem* robotItem();
    SignalProxy<void()> sigRobotDetected();
        
    virtual bool isEnabled();
    virtual bool initializeSimulation(SimulatorItem* simulatorItem);
    virtual void finalizeSimulation();

protected:
    virtual ItemPtr doDuplicate() const;
    virtual void onPositionChanged();
    virtual void doPutProperties(PutPropertyFunction& putProperty);
    virtual bool store(Archive& archive);
    virtual bool restore(const Archive& archive);

private:
    JVRCManagerItemImpl* impl;
};

typedef ref_ptr<JVRCManagerItem> JVRCManagerItemPtr;

}

#endif