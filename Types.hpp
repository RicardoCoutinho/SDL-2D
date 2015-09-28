//
//  Types.hpp
//  Templates
//
//  Created by José Ricardo de Sousa Coutinho on 22/09/15.
//  Copyright © 2015 jrsc. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

typedef struct struct_Point2D
{
    int x;
    int y;
    
} Int2D;

typedef struct struct_Value2D
{
    float x;
    float y;
    
} Float2D;

enum Alignment { TOP_LEFT,    TOP_CENTER,    TOP_RIGHT,
                 CENTER_LEFT, CENTER_CENTER, CENTER_RIGHT,
                 BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT };

enum ObjectStateType { IDLE, HOVER, SELECTED, MOVING, DESTROYED };

enum SceneType { MENU, LEVEL };

#endif /* Types_hpp */
