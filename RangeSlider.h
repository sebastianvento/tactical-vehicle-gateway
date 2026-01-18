#ifndef RANGESLIDER_H
#define RANGESLIDER_H

#include <QWidget>

/**
 * @brief Custom dual-handle range selector widget.
 * Allows users to define a minimum and maximum boundary within a set range.
 */
class RangeSlider : public QWidget
{
    Q_OBJECT

public:
    explicit RangeSlider(QWidget *parent = nullptr);

    // --- Configuration ---
    void setRange(int min, int max);
    void setValues(int min, int max);

    // --- Data Access ---
    int lowerValue() const { return m_lowerValue; }
    int upperValue() const { return m_upperValue; }

signals:
    /** @brief Emitted whenever the lower or upper handle position changes. */
    void valuesChanged(int min, int max);

protected:
    // --- UI Interaction & Rendering ---
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // --- State Variables ---
    int m_minimumRange = 0;
    int m_maximumRange = 100;
    int m_lowerValue = 0;
    int m_upperValue = 100;

    // --- Interaction Logic ---
    bool m_isDraggingLower = false;
    bool m_isDraggingUpper = false;

    /** @brief Maps logical data values to pixel coordinates on the widget. */
    int valueToPosition(int value);

    /** @brief Maps mouse pixel coordinates back to logical data values. */
    int positionToValue(int position);
};

#endif // RANGESLIDER_H
