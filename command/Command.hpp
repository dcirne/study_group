#ifndef Command_hpp
#define Command_hpp

class Command {
protected:
    Command() = default;

public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif
