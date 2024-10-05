from common import *
import os
import json5
# grab device-packet hierarchy

default_spec_path = "../universalproto/"

def get_packet_hierarchy(spec_path = default_spec_path):

    # Each device has a set of allowed packet groups 
    packet_groups_for_device = json5.loads(open(os.path.join(spec_path, "spec.json5"), "r").read())
    
    # Each packet has a set of allowed packets
    packets_for_packet_group = json5.loads(open(os.path.join(spec_path, "packets.json5"), "r").read())
    
    return packet_groups_for_device, packets_for_packet_group

def get_payloads(spec_path = default_spec_path):
    return json5.loads(open(os.path.join(spec_path, "types.json5"), "r").read())
    