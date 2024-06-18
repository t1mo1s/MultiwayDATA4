#include "CustomRectangle.h"

CustomRectangle::CustomRectangle(const QRectF &r, const QPen &p, const QBrush &b, qreal idx, Type type)
    : _rect(r),
      _pen(p),
      _brush(b),
      _index(idx),
      _type(type)
{
}

// Getter for the Index property
qreal CustomRectangle::index() const
{
    return _index;
}

// Setter for the Index property
void CustomRectangle::setIndex(qreal newIndex)
{
    if (_index != newIndex) {
        _index = newIndex;
        emit indexChanged();
    }
}

QPen CustomRectangle::pen() const{ return _pen; }

QBrush CustomRectangle::brush() const{ return _brush; }

QRectF CustomRectangle::rect() const { return _rect; }
