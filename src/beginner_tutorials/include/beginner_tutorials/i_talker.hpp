#ifndef TALKER_MANAGER_HPP_
#define TALKER_MANAGER_HPP_

#include <string>

namespace talker
{

class ITalker
{
    public:
        explicit ITalker(std::string central_idea) : central_idea_(central_idea){}
        virtual std::string get_response() = 0;

    protected:
        std::string central_idea_;
};

class TrashTalker : public ITalker
{
    public:
        explicit TrashTalker(std::string central_idea) : ITalker(central_idea){}
        std::string get_response() override {return "You are a sissy to think " + central_idea_;}

};

class NiceTalker : public ITalker
{
    public:
        explicit NiceTalker(std::string central_idea) : ITalker(central_idea){}
        std::string get_response() override {return "Thank you so much for your idea: " + central_idea_;}

};

class NegativeTalker : public ITalker
{
    public:
        explicit NegativeTalker(std::string central_idea) : ITalker(central_idea){}
        std::string get_response() override {return "No body like your idea of " + central_idea_;}

};

}



#endif