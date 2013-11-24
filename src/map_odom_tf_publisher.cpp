#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

int count=1;
nav_msgs::Odometry odom_input;
void callback(const nav_msgs::Odometry odom_prev)
{
  //ros::Rate r(.005);
  //{
  odom_input=odom_prev;
   /* tf::TransformBroadcaster odom_broadcaster;
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.header.frame_id = "map";
    odom_trans.child_frame_id = "odom";

    odom_trans.transform.translation.x = odom_input.pose.pose.position.x;
    odom_trans.transform.translation.y = odom_input.pose.pose.position.y;
    odom_trans.transform.translation.z = odom_input.pose.pose.position.z;
    odom_trans.transform.rotation = odom_input.pose.pose.orientation;
    odom_broadcaster.sendTransform(odom_trans);*/
   // if(count==1)
    //{
      ROS_INFO(" 1 ");
      count++;
      //count=2;
    //}
    //r.sleep();
  //}

}

int main(int argc, char** argv){
  ros::init(argc, argv, "map_odom_tf_publisher");
  ros::NodeHandle n;
 //ros::Rate r(50);
  while (ros::ok())
  {
  if(count>1)
  {
  ros::Time current_time=ros::Time::now();
  tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(odom_input.pose.pose.position.x, odom_input.pose.pose.position.y, 0.0) );
  transform.setRotation( tf::Quaternion(tf::getYaw(odom_input.pose.pose.orientation), 0, 0) );
  br.sendTransform(tf::StampedTransform(transform,current_time, "map","odom"));
  
  }
  ros::Subscriber odom_sub = n.subscribe("odom",100,callback);
  //ros::Duration(0.008).sleep();
  //ros::spin();
  //r.sleep();
}
  return 0;
  
};