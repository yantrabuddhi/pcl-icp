import rospy
import math

from std_msgs.msg import Int32, String
from pi_face_tracker.msg import FaceEvent, Faces
from geometry_msgs.msg import PoseStamped #for sound

face_file = open("face_points.csv","w")
snd_file  = open("sound_points.csv","w")

face_raw = open("face_points.txt","w")
snd_raw = open("sound_points.txt","w")

def to_str(xx,yy,zz):
    txt = str(xx)+" "+str(yy)+" "+str(zz)+"\n"
    return txt

def normalize(x,y,z):
    mag=sqrt(x*x+y*y+z*z)
    xx=x/mag
    yy=y/mag
    zz=z/mag
    txt = to_str(xx,yy,zz)
    return

def face_loc_cb(imsg):
    msg=imsg[0]
    face_raw.write(to_str(msg.point.x,msg.point.y,msg.point.z))
    txt = normalize(msg.point.x,msg.point.y,msg.point.z)
    face_file.write(txt)

def snd1_cb(msg):
    snd_raw.write(to_str(msg.pose.position.x,msg.pose.position.y,msg.pose.position.z))
    txt = normalize(msg.pose.position.x,msg.pose.position.y,msg.pose.position.z)
    snd_file.write(txt)

rospy.init_node("FaceSoundLogger")
rospy.Subscriber("/camera/face_locations", Faces, face_loc_cb)
rospy.Subscriber("/manyears/source_pose",PoseStamped, snd1_cb)
#while not rospy.is_shutdown():
rospy.spin()
face_file.close()
snd_file.close()
face_raw.close()
snd_raw.close()
