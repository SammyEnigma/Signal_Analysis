#include "SARibbonCategory.h"
#include <QList>
#include <QResizeEvent>
#include <QPainter>
class SARibbonCategoryPrivate
{
public:
    QList<SARibbonPannel*> pannelLists;
};

SARibbonCategory::SARibbonCategory(QWidget *parent)
    :QWidget(parent)
    ,m_d(new SARibbonCategoryPrivate)
{
    setFixedHeight(98);
    setAutoFillBackground(true);
    setBackgroundBrush(Qt::white);
}

SARibbonCategory::~SARibbonCategory()
{
    delete m_d;
}

///
/// \brief 添加一个面板
/// \param title 明白名称
/// \return
///
SARibbonPannel *SARibbonCategory::addPannel(const QString &title)
{
    SARibbonPannel* pannel = new SARibbonPannel(this);
    pannel->setWindowTitle(title);
    m_d->pannelLists.append(pannel);
    return pannel;
}
///
/// \brief SARibbonCategory::setBackgroundBrush
/// \param brush
///
void SARibbonCategory::setBackgroundBrush(const QBrush &brush)
{
    QPalette p = palette();
    p.setBrush(QPalette::Background,brush);
    setPalette(p);
}

void SARibbonCategory::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    const int size = m_d->pannelLists.size();
    int lastPos = 0;
    for(int i=0;i<size;++i)
    {
        if(0 != lastPos)
        {
            //绘制分割线

        }
        SARibbonPannel* pannel = m_d->pannelLists[i];
        pannel->move(lastPos,0);
        lastPos = pannel->width() + 1;
    }
}

void SARibbonCategory::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
