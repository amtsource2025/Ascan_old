#ifndef FIXEDCOMBOBOX_H
#define FIXEDCOMBOBOX_H

#include <QComboBox>
#include <QListView>
#include <QAbstractItemView>
#include <QFrame>

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
    }

    void showPopup() override
    {
        QComboBox::showPopup();

        if (!view())
            return;

        // Actual Qt item height
        int itemHeight = view()->sizeHintForRow(0);

        // Maximum visible rows
        int visibleItems = qMin(count(), 8);

        // Popup height
        int popupHeight =
            (itemHeight * visibleItems) + 4;

        // Resize popup window
        QWidget *popup = view()->window();
        if (popup) {
            popup->setFixedHeight(popupHeight);
        }
    }
};

#endif // FIXEDCOMBOBOX_H
