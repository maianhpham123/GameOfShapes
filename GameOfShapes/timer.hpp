//
//  timer.hpp
//  GameOfShapes
//
//  Created by mac on 4/13/24.
//

#ifndef timer_hpp
#define timer_hpp

#include <SDL2/SDL.h>

class Timer {
public:
    static Timer* Instance();
    static void Release();
    
    void Reset();
    float DeltaTime();
    
    void TimeScale(float t);
    float TimeScale();
    
    void update();
    
private:
    static Timer* sInstance;
    unsigned int mStartTicks;
    unsigned int mElapsedTicks;
    float mDeltaTime;
    float mTimeScale;
    
    Timer();
    ~Timer();
};

#endif /* timer_hpp */
