#ifndef GUI_VIAPOINT_H
#define GUI_VIAPOINT_H

#include <QWidget>
#include <QPlainTextEdit>
#include "util/NonCopyable.h"
#include "gl/DeviceInfo.h"
#include "core/Project.h"
namespace img { class ResourceNode; }
namespace gui { class ResourceDialog; }
namespace gui { class MainMenuBar; }
namespace gui { class KeyCommandMap; }

namespace gui
{

class ViaPoint : private util::NonCopyable
{
public:
    ViaPoint(QWidget* aParent);

    void setProject(core::Project* aProject);

    void setMainMenuBar(MainMenuBar* aMainMenuBar);
    MainMenuBar* mainMenuBar() const { return mMainMenuBar; }

    ResourceDialog* resourceDialog() const { return mResDialog; }
    void createResourceDialog();
    img::ResourceNode* requireOneResource();

    void setLogView(QPlainTextEdit* aLogView);
    void pushLog(const QString& aText);

    void setGLDeviceInfo(const gl::DeviceInfo&);
    const gl::DeviceInfo& glDeviceInfo() const;

    void setKeyCommandMap(KeyCommandMap* aMap);
    KeyCommandMap* keyCommandMap() const { return mKeyCommandMap; }

    util::Signaler<void()> onVisualUpdated;

private:
    QWidget* mParent;
    core::Project* mProject;
    MainMenuBar* mMainMenuBar;
    ResourceDialog* mResDialog;
    QPlainTextEdit* mLogView;
    gl::DeviceInfo mGLDeviceInfo;
    KeyCommandMap* mKeyCommandMap;
};

} // namespace gui

#endif // GUI_VIAPOINT_H
