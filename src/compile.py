from common import *
from read_json import get_packet_hierarchy, get_payloads
from fields import Fields


def get_packet_header_str(packet_name, packet_id, packet_fields):
    # template
    template = """
#pragma once

#include "common.h"

class PacketName 
{
public:

    [BUILDER]

    uint8_t getId() const
    {
        return id;
    }

    using Builder = Builder_<false_list>;

private:
    packet_fields

    uint8_t id = packet_id;

    PacketName(packet_args)
        : packet_constructor_inline
    {}
};

"""
    arg_name_str = packet_fields.get_constructor_args_str()
    
    inline_val_str = packet_fields.get_constructor_inline_str()

    field_decl_str = packet_fields.get_fields_decl_str()

    template = substitute(template, [
        ("PacketName", packet_name),
        ("packet_id", str(packet_id)),
        ("packet_args", arg_name_str),
        ("packet_constructor_inline", inline_val_str),
        ("packet_fields", field_decl_str),
        ("[BUILDER]", packet_fields.build_Builder(packet_name).replace("\n","    \n")),
        ("false_list", ", ".join(["false"] * packet_fields.num_fields))
    ])

        # no fields...
    if (packet_fields.num_fields == 0):
        template = template.replace("template<>", "").replace("<>", "").replace(" :","").replace("static_", "//static_")

    return template 

def get_packet_file_name(packet_name):
    return f"Packet_{packet_name}.h"

def make_group_header(packet_group_key, packets_for_packet_group):
    
    packet_group_header = "#pragma once\n"

    for packet_name in (packets_for_packet_group[packet_group_key].keys()):
        packet_group_header += f'#include "{get_packet_file_name(packet_name)}"\n'
    
    return packet_group_header


# In; dict of packet_group : {packet1 : {id : [ID], payload : [PAYLOAD]...}...}
# In: dict of payloads; {[NAME] : {type : [TYPE], symbol : [NAME]... }... }
# Out: dict of {}
def create_packet_headers(packet_groups_for_device, packets_for_packet_group, payloads, build_path = "../bin"):
    packet_structs = {}
    
    os.system(f"cp common/* {build_path}")

    for packet_group_key in packets_for_packet_group.keys():
    
        print(f"Compiling group {packet_group_key}")

        for packet_key in tqdm(packets_for_packet_group[packet_group_key].keys()):

            packet_def = packets_for_packet_group[packet_group_key][packet_key]
            

            if ("payload" in packet_def.keys()):
                packet_payload = payloads[packet_def["payload"]]
            else:
                packet_payload = {}

            # Now struct has id and payload corresponding to the desired thingiemabobber
            packet_fields = Fields(packet_payload)


            # Make the packet
            packet_name = packet_key
            packet_id = packet_def["id"]

            packet_header_str = get_packet_header_str(packet_name, packet_id, packet_fields)

            packet_header_path = os.path.join(build_path, get_packet_file_name(packet_name))
            open(packet_header_path, "w+").write(packet_header_str)
    
    
    for packet_group_key in packets_for_packet_group.keys():
        group_header = make_group_header(packet_group_key, packets_for_packet_group)
        open(os.path.join(build_path, f"Group_{packet_group_key}.h"), "w+").write(group_header)

    for packet_device_key in packet_groups_for_device.keys():
        device_header = "#pragma once\n"
        for group_name in (packet_groups_for_device[packet_device_key]):
            device_header += f'#include "Group_{group_name}.h"\n'
        
        open(os.path.join(build_path, f"Device_{packet_device_key}.h"), "w+").write(device_header)
            


def make_headers():
    
    packet_groups_for_device, packets_for_packet_group = get_packet_hierarchy()
    
    payloads = get_payloads()

    packet_structs = {}

    create_packet_headers(packet_groups_for_device, packets_for_packet_group, payloads)

make_headers()