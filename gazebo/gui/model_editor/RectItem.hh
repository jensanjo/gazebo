/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef _RECT_ITEM_HH_
#define _RECT_ITEM_HH_

#include "gui/qt.h"

namespace gazebo
{
  namespace gui
  {
    class CornerGrabber;

    class RotateHandle;

    class RectItem : public QGraphicsItem
    {
        public: RectItem();

        public: virtual ~RectItem();

        public: void SetGridSpace(int _space);

        public: void SetWidth(int _width);

        public: void SetHeight(int _height);

        public: void SetSize(QSize _size);

        public: int GetWidth();

        public: int GetHeight();

        public: void showCorners(bool _show);

        protected: void UpdateCornerPositions();

        private: void AdjustSize(int _x, int _y);

        protected: void showBoundingBox(QPainter *_painter);

        protected: virtual QRectF boundingRect() const;

        private: virtual bool rotateEventFilter(RotateHandle *_rotateHandle,
            QGraphicsSceneMouseEvent *_event);

        private: virtual bool cornerEventFilter(CornerGrabber *_corner,
            QGraphicsSceneMouseEvent *_event);

        private: virtual void paint (QPainter *_painter,
            const QStyleOptionGraphicsItem *_option, QWidget *_widget);

        private: virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *_event);

        private: virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *_event);

        private: virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *_event);

        private: virtual void mousePressEvent(QGraphicsSceneMouseEvent *_event);

        private: virtual void mouseReleaseEvent(
            QGraphicsSceneMouseEvent *_event);

        private: virtual void mouseMoveEvent(
            QGraphicsSceneDragDropEvent *_event);

        private: virtual void mousePressEvent(
            QGraphicsSceneDragDropEvent *_event);

        private: virtual void mouseDoubleClickEvent(
            QGraphicsSceneMouseEvent *_event);

        private: virtual bool sceneEventFilter(QGraphicsItem *_watched,
            QEvent *_event);

        protected: int width;

        protected: int height;

        protected: int drawingWidth;

        protected: int drawingHeight;

        protected: int drawingOriginX;

        protected: int drawingOriginY;

        protected: QColor borderColor;

        private: QPointF location;

        private: int gridSpace;

        private: int xCornerGrabBuffer;

        private: int yCornerGrabBuffer;

        /// \brief Four corners and four edges, going clockwise with
        /// 0 being top left
        private: CornerGrabber *corners[8];

        private: RotateHandle *rotateHandle;
    };
  }
}

#endif
