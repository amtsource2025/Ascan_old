#ifndef FIXEDCOMBOBOX_H
#define FIXEDCOMBOBOX_H
#include <QComboBox>
#include <QListView>
#include <QLineEdit>
#include <QPainter>
#include <QStyleOptionComboBox>
#include <QStylePainter>
#include <QTimer>
class FixedComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit FixedComboBox(QWidget *parent = nullptr)
        : QComboBox(parent)
    {
        QListView *lv = new QListView();
        lv->setUniformItemSizes(true);
        lv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lv->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        setView(lv);
        // ✅ KEY FIX: explicit opaque background so frame's border-image
        // cannot paint over this widget after popup closes
        setStyleSheet(
            "QComboBox {"
            "  background-color: #FBFCFE;"
            "  color: #1A2B3C;"
            "  border: 1.5px solid #DCE3EA;"
            "  border-radius: 12px;"
            "  padding-left: 10px;"
            "  font-size: 20px;"
            "}"
            "QComboBox:hover {"
            "  border: 1.5px solid #A9C4E8;"
            "}"
            "QComboBox:focus, QComboBox:on {"
            "  border: 1.5px solid #1976D2;"
            "  background-color: #FFFFFF;"
            "}"
            "QComboBox::drop-down {"
            "  width: 40px;"
            "  border-left: 1px solid #DCE3EA;"
            "}"
            "QComboBox QAbstractItemView {"
            "  background-color: white;"
            "  color: #1A2B3C;"
            "  border: 1px solid #DCE3EA;"
            "  selection-background-color: #E3F0FD;"
            "  selection-color: #1976D2;"
            "  outline: 0;"
            "  padding: 4px;"
            "  font-size: 20px;"
            "}"
            );
    }
    void showPopup() override
    {
        QComboBox::showPopup();
        if (!view()) return;
        int itemHeight   = view()->sizeHintForRow(0);
        int visibleItems = qMin(count(), 8);
        int popupHeight  = (itemHeight * visibleItems) + 4;
        QWidget *popup = view()->window();
        if (popup)
            popup->setFixedHeight(popupHeight);
    }
    void hidePopup() override
    {
        QComboBox::hidePopup();
        // Repaint self AND parent frame to flush framebuffer correctly
        this->update();
        this->repaint();
        if (parentWidget()) {
            parentWidget()->update(geometry());
        }
        QTimer::singleShot(50, this, [this] {
            this->update();
            this->repaint();
        });
    }
protected:
    void paintEvent(QPaintEvent *) override
    {
        QStylePainter painter(this);
        QStyleOptionComboBox opt;
        initStyleOption(&opt);
        // Draw frame + arrow only (suppress Qt's text)
        opt.currentText = "";
        // Kill the default focus-rectangle (shows up as a red/dotted
        // border on some embedded styles) — our QSS border already
        // shows focus state via the blue border color.
        opt.state &= ~QStyle::State_HasFocus;
        painter.drawComplexControl(QStyle::CC_ComboBox, opt);
        // Draw our own text — always reads live currentText()
        QRect textRect = style()->subControlRect(
            QStyle::CC_ComboBox, &opt,
            QStyle::SC_ComboBoxEditField, this);
        textRect.adjust(4, 0, -4, 0);
        painter.setPen(QColor("#1A2B3C"));
        painter.setFont(this->font());
        painter.drawText(textRect,
                         Qt::AlignVCenter | Qt::AlignLeft,
                         this->currentText());
    }
};
#endif // FIXEDCOMBOBOX_H
