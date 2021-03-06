#ifndef OGLSPLINELAYER2D_H
#define OGLSPLINELAYER2D_H

#include "ogllayer.h"

#include "../elements/drawelement2D.h"

#include "../elements/joint2D.h"
#include "../elements/obstacle2d.h"
#include "../elements/link2d.h"

#include "../../solution/a1solution.h"

class A1_2DLayer : public OGLLayer
{
public:
    A1_2DLayer(OGLTWidget* parent);


    // UI
    virtual void mouse_grab(MouseInfo m);
    virtual void mouse_drag(MouseInfo m);
    virtual void mouse_release(MouseInfo m);
    virtual void mouse_double_click(MouseInfo m);

    virtual void key_press(KeyboardInfo ki);
    virtual void key_release(KeyboardInfo ki);

    virtual void scroll(double delta);

    virtual void mouse_hover(MouseInfo m);

    virtual bool setUIMode(int);
    int m_UIMode;// 0 = change the view, 1 = create and select Joints, 2 - create and remove links, 3 - create and select obstacles, 4 - showtime

    virtual bool reset_view();

    virtual void resizeGL(int w, int h);

    // virtual
    virtual bool initializeGL();
    virtual bool draw();

    virtual bool passMsg(TMessage*){return false;};

    virtual ~A1_2DLayer(){}

    virtual bool save(QDataStream*){return false;};
    virtual bool load(QDataStream*){return false;};

    DrawElement2D* m_selected;

    QMatrix4x4 m_projection, m_view;

    // Visible elements
    //std::vector<DrawElement2D*> m_elements;

    std::vector<Joint2D*> m_joints;
    std::vector<Link2D*> m_links;

    // this is where the students add their solution
    A1Solution m_solution;

    };


#endif // OGLLAYER2D_H
