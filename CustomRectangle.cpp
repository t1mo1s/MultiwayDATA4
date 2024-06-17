#include "CustomRectangle.h"

CustomRectangle::CustomRectangle(const QRectF &r, const QPen &p, const QBrush &b, const qreal idx)
    : rect(r), pen(p), brush(b), index{idx}
{}
