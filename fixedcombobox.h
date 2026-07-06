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
            "  background-color: white;"
            "  color: black;"
            "  border: 2px solid #219ebc;"
            "  border-radius: 6px;"
            "  padding-left: 8px;"
            "  font-size: 20px;"
            "}"
            "QComboBox::drop-down {"
            "  width: 40px;"
            "  border-left: 1px solid #219ebc;"
            "}"
            "QComboBox QAbstractItemView {"
            "  background-color: white;"
            "  color: black;"
            "  selection-background-color: #219ebc;"
            "  selection-color: white;"
            "  font-size: 20px;"
            "}"
            );

        connect(this, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, [this](int) {
                    m_displayText = this->currentText();
                    this->update();
                    this->repaint();
                });
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
        m_displayText = this->currentText();

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
        painter.drawComplexControl(QStyle::CC_ComboBox, opt);

        // Draw our own text — guaranteed to use m_displayText
        QRect textRect = style()->subControlRect(
            QStyle::CC_ComboBox, &opt,
            QStyle::SC_ComboBoxEditField, this);
        textRect.adjust(4, 0, -4, 0);

        painter.setPen(Qt::black);
        painter.setFont(this->font());
        painter.drawText(textRect,
                         Qt::AlignVCenter | Qt::AlignLeft,
                         m_displayText);
    }

private:
    QString m_displayText;
};

#endif // FIXEDCOMBOBOX_H
