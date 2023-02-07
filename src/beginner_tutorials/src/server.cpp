#include <ros/ros.h>
#include <beginner_tutorials_msgs/SeeStats.h>
#include <map>


struct DbEntry 
{
    std::string last_name = "Johnson";
    uint8_t age = 20u;
    uint32_t score = 0u;
};

std::map<std::string, DbEntry> db{
    {"Bob", {"Jones", 50, 0}},
    {"Jill", {"Peters", 20, 8}},
    {"Jack", {"ASDF", 30, 16}}
};

bool find_stats(beginner_tutorials_msgs::SeeStats::Request & req, beginner_tutorials_msgs::SeeStats::Response & res)
{
    ROS_INFO("Request Received!");
    if (db.find(req.first_name) != db.end())
    {
        res.stats.first_name = req.first_name;
        res.stats.age = db.at(req.first_name).age;
        res.stats.last_name = db.at(req.first_name).last_name;
        res.stats.score = db.at(req.first_name).score;
    }
    else
    {
        res.error_message = "Name " + req.first_name + " not available!";
    }
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("see_stats", find_stats);
    ros::spin();
    return 0;
}

