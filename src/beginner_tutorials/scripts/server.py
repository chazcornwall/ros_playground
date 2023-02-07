#!/usr/bin/env python3

from beginner_tutorials_msgs.msg import Stats
from beginner_tutorials_msgs.srv import SeeStats, SeeStatsResponse
import rospy


db = {}
db["Bob"] = {"last_name": "Jones", "age": 50, "score": 0}
db["Jill"] = {"last_name": "Peters", "age": 20, "score": 8}
db["Jack"] = {"last_name": "ASDF", "age": 30, "score": 16}


def handle_see_stats(req):
    print("Request Received!")
    if req.first_name in db:
        db_entry = db[req.first_name]
        return SeeStatsResponse("", Stats(req.first_name, db_entry["last_name"], db_entry["age"], db_entry["score"]))
    else:
        return SeeStatsResponse("No info available!", Stats())


def server():
    rospy.init_node('server')
    s = rospy.Service('see_stats', SeeStats, handle_see_stats)
    rospy.spin()


if __name__ == "__main__":
    server()