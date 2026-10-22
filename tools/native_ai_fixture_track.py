"""Native track graph layout shared by AI instruction probes."""
def install_track(p, track, base=0x24000000):
    sectors, waypoints, mapping = base, base + 0x200000, base + 0x300000
    p.u32(0x680b28, sectors)
    p.u32(0x680ae0, waypoints)
    p.u32(0x68021c, mapping)
    for i, route in enumerate(track['route']):
        p.u32(mapping + i * 4, i)
        for count_offset, list_offset, key in [(0xe4, 0x124, 'driveLeftIndices'), (0xe8, 0x154, 'driveIndices')]:
            p.u32(sectors + i * 0x984 + count_offset, len(route[key]))
            for j, value in enumerate(route[key]): p.u32(sectors + i * 0x984 + list_offset + j * 4, value)
    for i, node in enumerate(track['drive']):
        address = waypoints + i * 0x50
        for j, value in enumerate(node['unknown']): p.u32(address + j * 4, value)
        for j, value in enumerate(node['position']): p.f32(address + 8 + j * 4, value)
        for j, value in enumerate([node['links'][0], node['links'][2], node['links'][1], node['links'][3]]):
            p.u32(address + 0x14 + j * 4, value & 0xffffffff)
