#include <ros/ros.h>
#include <std_msgs/String.h>
#include <beginner_tutorials/i_talker.hpp>
#include <sstream>
#include <memory>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    std::string talker_type = "nice"; // trash, nice, or negative
    ros::param::set("talker_type", talker_type);
    std_msgs::String msg;
    std::shared_ptr<talker::ITalker> talker; // Use ITalker library
    std::string main_idea = "hello world";

    int count = 0;
    while (ros::ok())
    {
        
        if (ros::param::get("talker_type", talker_type))
        {
            if (talker_type == "trash")
            {
                if (talker)
                {
                    talker.reset();
                }
                talker = std::make_shared<talker::TrashTalker>(main_idea);
            }
            else if (talker_type == "nice")
            {
                if (talker)
                {
                    talker.reset();
                }
                talker = std::make_shared<talker::NiceTalker>(main_idea);
            }
            else
            {
                if (talker)
                {
                    talker.reset();
                }
                talker = std::make_shared<talker::NegativeTalker>(main_idea);
            }

            msg.data = talker->get_response();

            ROS_INFO("%s", msg.data.c_str());

            chatter_pub.publish(msg);
        }
        
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}