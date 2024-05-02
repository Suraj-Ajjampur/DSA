import math

def camera_properties(name, focal_length_mm, sensor_size_mm):
    print("For a " + name + " the focal length is " + str(focal_length_mm) + "mm and sensor size is " + str(sensor_size_mm) + "mm\n")
    # Variables
    # Calculate FoV in radians
    fov_radians = 2 * math.atan(sensor_size_mm / (2 * focal_length_mm))

    # Convert radians to degrees
    fov_degrees = math.degrees(fov_radians)

    print("FOV in deg is " + str(fov_degrees))

    # Earth's rotation speed in degrees per hour
    earth_rotation_speed_deg_per_hour = 15.04

    # Convert Earth's rotation speed to degrees per second
    earth_rotation_speed_deg_per_sec = earth_rotation_speed_deg_per_hour / 3600

    # Time for a star to cross the FoV
    time_to_cross_fov_sec = fov_degrees / earth_rotation_speed_deg_per_sec

    print("Time to cross Fov in sec is " + str(time_to_cross_fov_sec))


    print("Time to keep image in frame " + str(time_to_cross_fov_sec/640))

    # #Steps per revolution
    # steps_per_revoluton = 2048
    # degrees_per_step =360/ steps_per_revoluton 
    # print("\ndegrees per step is " + str(degrees_per_step))
    # # Calculate steps per second needed to match the Earth's rotation
    # steps_per_sec_needed = earth_rotation_speed_deg_per_sec / degrees_per_step

    # print("Steps per second needed to match Earth's rotation: " + str(steps_per_sec_needed))


camera_properties("Jetson Nano",4,3.58 * 2.02)
print("---------------------------------")
camera_properties("Telephoto",200,16)
print("---------------------------------")
camera_properties("Hale Telescope", 16760,43)
