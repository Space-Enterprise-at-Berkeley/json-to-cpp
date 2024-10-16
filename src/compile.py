from common import *
from read_json import get_packet_hierarchy, get_payloads
from fields import Fields


def get_packet_header_str(packet_name, packet_id, packet_fields, kill_hdr):
    # template
    template = """
#pragma once

#include "common.h"

KillHeader

class PacketPacketName 
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

    PacketPacketName(packet_args)
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
        ("[BUILDER]", packet_fields.build_Builder("Packet"+packet_name).replace("\n","    \n")),
        ("false_list", ", ".join(["false"] * packet_fields.num_fields)),
        ("KillHeader", kill_hdr)
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
def create_packet_headers(packet_list, payloads, build_path = "../bin"):
    packet_structs = {}
    
    os.system(f"cp ../common/* {build_path}")

    all_rw = []

    for packet_def in packet_list:
        allowed = packet_def['writes'] + packet_def['reads']
        if (type(allowed) != str):
            for i in allowed:
                if (i.replace("*","") not in all_rw):
                    all_rw.append(i.replace("*",""))

    for packet_def in tqdm(packet_list):


        if ("payload" in packet_def.keys() and packet_def["payload"]):
            packet_payload = payloads[packet_def["payload"]]
        else:
            packet_payload = {}

        # Now struct has id and payload corresponding to the desired thingiemabobber
        packet_fields = Fields(packet_payload)

        # Make the packet
        packet_name = packet_def['name']
        packet_id = packet_def["id"]

        kill_hdr = ""

        allowed = packet_def['writes'] + packet_def['reads']
        if (type(allowed) != str):
            allowed_rw = [i.replace("*", '') for i in allowed]
            disallowed_rw = [i if not (i in allowed_rw) else None for i in all_rw ]

            for die in disallowed_rw:
                if (die):
                    kill_hdr += f"#ifdef {die}\n#error\n#endif\n"

        packet_header_str = get_packet_header_str(packet_name, packet_id, packet_fields, kill_hdr)

        packet_header_path = os.path.join(build_path, get_packet_file_name(packet_name))
        open(packet_header_path, "w+").write(packet_header_str)
            


def make_headers():
    
    packets_for_packet_group = get_packet_hierarchy()
    
    payloads = get_payloads()

    packet_structs = {}

    create_packet_headers(packets_for_packet_group, payloads)

make_headers()
