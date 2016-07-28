import rospy
import math

from std_msgs.msg import Int32, String
from pi_face_tracker.msg import FaceEvent, Faces
from geometry_msgs.msg import PoseStamped #for sound

face_file = open("face_points.csv","w")
snd_file  = open("sound_points.csv","w")

def normalize(x,y,z):
    mag=sqrt(x*x+y*y+z*z)
    xx=x/mag
    yy=y/mag
    zz=z/mag
    txt = str(xx)+" "+str(yy)+" "+str(zz)+"\n"
    return

def face_loc_cb(msg):
    txt = normalize(msg.point.x,msg.point.y,msg.point.z)
    face_file.write(txt)

def snd1_cb(msg):
    txt = normalize(msg.position.x,msg.position.y,msg.position.z)
    snd_file.write(txt)

rospy.init_node("FaceSoundLogger")
rospy.Subscriber("/camera/face_locations", Faces, face_loc_cb)
rospy.Subscriber("/manyears/source_pose",PoseStamped, snd1_cb)
#while not rospy.is_shutdown():
rospy.spin()
face_file.close()
snd_file.close()
