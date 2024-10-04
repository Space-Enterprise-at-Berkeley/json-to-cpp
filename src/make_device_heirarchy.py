from common import *

# grab device-packet heirarchy

def get_packet_hierarchy(spec_path = "../universalproto/"):

    # Each device has a set of allowed packet groups 
    packet_groups_for_device = json5.loads(open(os.path.join(spec_path, "spec.json5"), "r").read())
    
    # Each packet has a set of allowed packets
    packets_for_packet_group = json5.loads(open(os.path.join(spec_path, "packets.json5"), "r").read())
    
    return packet_groups_for_device, packets_for_packet_group
