"""Strict readers for the supplied RedCat SuperKarts files (all offsets LE).

Archive index validation adapts RCSPOOK_NEW/tools/extract_menu.py. Mesh and map
readers are independent: SuperKarts does not use Spookkasteel GBSP/Genesis ACT.
Unknown fields are preserved; their gameplay meaning is not assumed.
"""
import math
import re
import struct
from collections import Counter
from pathlib import Path


def require(condition, message):
    if not condition:
        raise ValueError(message)


def archive_entries(index, blob_size, named=True):
    require(len(index) >= 2, 'truncated index')
    count = struct.unpack_from('<H', index)[0]
    size = 24 if named else 4
    require(len(index) == 2 + count*size, 'unexpected index size')
    entries = []
    used = Counter()
    for i in range(count):
        if named:
            raw, offset = struct.unpack_from('<20sI', index, 2 + i*size)
            name = raw.split(b'\0', 1)[0].decode('cp1252')
        else:
            offset = struct.unpack_from('<I', index, 2 + i*size)[0]
            name = f'resource_{i:04d}.bin'
        require(0 <= offset <= blob_size, 'archive offset outside image')
        require(not entries or offset >= entries[-1]['offset'], 'decreasing archive offset')
        safe = name.lower() if re.fullmatch(r'[A-Za-z0-9_.-]+', name) else f'resource_{i:04d}.bin'
        used[safe] += 1
        if used[safe] > 1:
            safe = f'{Path(safe).stem}__{used[safe]}{Path(safe).suffix}'
        entries.append({'index': i, 'name': name, 'filename': safe, 'offset': offset})
    for i, e in enumerate(entries):
        e['length'] = (entries[i+1]['offset'] if i+1<count else blob_size) - e['offset']
    return entries


def mesh(data):
    marker = struct.unpack_from('<i', data)[0]
    if marker == -1:
        _, nv, nf = struct.unpack_from('<iII', data)
        header, stride, fmt = 12, 49, '<12fB'
    else:
        nv, nf = struct.unpack_from('<II', data)
        header, stride, fmt = 8, 33, '<8fB'
    require(len(data) == header + nv*stride + nf*9, 'D3D size mismatch')
    vertices = list(struct.iter_unpack(fmt, data[header:header+nv*stride]))
    if stride == 33:
        vertices = [(*v[:8], 1., 1., 1., 1., v[8]) for v in vertices]
    faces = list(struct.iter_unpack('<3H3B', data[header+nv*stride:]))
    require(all(i<nv for f in faces for i in f[:3]), 'D3D index outside vertices')
    used = {i for f in faces for i in f[:3]}
    invalid = [i for i, v in enumerate(vertices) if any(not math.isfinite(x) for x in v[:12])]
    require(not used.intersection(invalid), 'non-finite referenced D3D vertex')
    # Some shipped files contain unused editor sentinel vertices (0x7fff007f).
    # Preserve their source IDs, omit those unreferenced records from geometry.
    remap = {old:new for new,old in enumerate(i for i in range(nv) if i not in invalid)}
    vertices = [v for i,v in enumerate(vertices) if i not in invalid]
    faces = [tuple(remap[i] for i in f[:3]) + f[3:] for f in faces]
    return {'format':'superkarts-d3d-v1','position':[x for v in vertices for x in v[:3]],
            'normal':[x for v in vertices for x in v[3:6]],'uv':[x for v in vertices for x in v[6:8]],
            'color':[x for v in vertices for x in v[8:11]],'alpha':[v[11] for v in vertices],
            'vertexUnknown':[v[12] for v in vertices],'index':[i for f in faces for i in f[:3]],
            'faceUnknown':[list(f[3:]) for f in faces],'vertexCount':len(vertices),'triangleCount':nf,
            'sourceVertexCount':nv,'sourceVersion':'rgba' if marker == -1 else 'legacy',
            'omittedInvalidUnusedVertices':invalid}


def road(data):
    marker, header_count, sectors = struct.unpack_from('<iII',data)
    require(marker == -1, 'unsupported RMP version')
    offset=12
    out={'format':'superkarts-rmp-v1','headerCount':header_count,'sectorCount':sectors,
         'position':[],'uv':[],'color':[],'index':[],'groups':[]}
    for sector in range(sectors):
        for material in range(4):
            count=struct.unpack_from('<I',data,offset)[0];offset+=4
            require(offset+count*120<=len(data),'truncated RMP group')
            start=len(out['index'])
            for _ in range(count):
                base=len(out['position'])//3
                for v in range(4):
                    x,y,z,u,v,c=struct.unpack_from('<5fI',data,offset);offset+=24
                    require(all(math.isfinite(n) for n in [x,y,z,u,v]), 'non-finite RMP vertex')
                    out['position'] += [x,y,z];out['uv'] += [u,v]
                    # FUN_0049cc90 swaps the on-disk RGB bytes into D3D ARGB.
                    out['color'] += [(c&255)/255,((c>>8)&255)/255,((c>>16)&255)/255]
                indices=struct.unpack_from('<6I',data,offset);offset+=24
                require(all(i<4 for i in indices),'invalid RMP quad index')
                out['index'] += [base+i for i in indices]
            out['groups'].append({'sector':sector,'textureIndex':material,
                                  'kind':['road','land','extra','rail'][material],
                                  'start':start,'count':count*6})
    require(offset==len(data),'trailing RMP data')
    return out


def placements(data):
    count=struct.unpack_from('<I',data)[0]
    require(len(data)==4+count*68,'OMP size mismatch')
    return [{'sector':r[0],'type':r[1],'position':list(r[2:5]),'rotation':list(r[5:8]),
             'animation':r[8].split(b'\0',1)[0].decode('cp1252'),'value':r[9],
             'nativeRotationDegrees':[r[5],-r[6],r[7]]}
            for r in struct.iter_unpack('<II6f32sI',data[4:])]


def route(data):
    count=struct.unpack_from('<I',data)[0];offset=4;out=[]
    for _ in range(count):
        values=struct.unpack_from('<3fI',data,offset);offset+=16
        row={'position':list(values[:3]),'trigger':values[3]}
        row['unknown']=struct.unpack_from('<I',data,offset)[0];offset+=4
        for key in ['collisionIndices','driveLeftIndices','driveIndices']:
            n=struct.unpack_from('<I',data,offset)[0];offset+=4
            require(offset+n*4<=len(data),'PMP list outside file')
            row[key]=list(struct.unpack_from('<'+str(n)+'I',data,offset));offset+=n*4
        out.append(row)
    require(offset==len(data),'trailing PMP data')
    return out


def collision(data):
    count=struct.unpack_from('<I',data)[0]
    require(len(data)==4+count*24,'CMP size mismatch')
    return [{'position':list(r[:3]),'delta':list(r[3:])} for r in struct.iter_unpack('<6f',data[4:])]


def drive(data):
    count=struct.unpack_from('<I',data)[0]
    require(len(data)==4+count*36,'DMP size mismatch')
    return [{'unknown':list(r[:2]),'position':list(r[2:5]),'links':list(r[5:])}
            for r in struct.iter_unpack('<II3f4i',data[4:])]


def paths(data):
    """FUN_00444bd0: six integer fields, then 16-byte point records."""
    marker,count=struct.unpack_from('<iI',data)
    require(marker==-1,'unsupported PTH version')
    offset=8;out=[]
    for _ in range(count):
        fields=struct.unpack_from('<6i',data,offset);offset+=24
        require(0<=fields[5]<=49,'PTH point count exceeds native allocation')
        require(offset+fields[5]*16<=len(data),'truncated PTH points')
        points=[]
        for _ in range(fields[5]):
            flag,x,y,z=struct.unpack_from('<I3f',data,offset);offset+=16
            require(all(math.isfinite(v) for v in [x,y,z]),'non-finite PTH position')
            points.append({'flag':flag,'position':[x,y,z]})
        out.append({'startSector':fields[0],'endSector':fields[1],'type':fields[2],
                    'unknown':fields[3],'durationMs':fields[4],'points':points})
    require(offset==len(data),'trailing PTH data')
    return out


def ini(text):
    """Retain duplicate keys and raw values; semicolons delimit animation data."""
    result={}; section=''
    for line in text.splitlines():
        line=line.strip()
        if not line or line.startswith(';'):continue
        if line.startswith('[') and ']' in line:
            section=line[1:line.index(']')].lower();result.setdefault(section,{})
        elif '=' in line:
            key,value=line.split('=',1);result.setdefault(section,{})[key.strip().lower()]=value.strip()
    return result
