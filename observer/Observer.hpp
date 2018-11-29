#ifndef observer_hpp
#define observer_hpp

class Subject;

class Observer {
protected:
    Observer() = default;

public:
    virtual ~Observer() = default;
    virtual void update(Subject *subject) = 0;
};

#endif
