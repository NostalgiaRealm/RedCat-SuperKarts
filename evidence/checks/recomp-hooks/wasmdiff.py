# Compares two wasm modules function by function (by name-section name): which bodies differ.
import sys
def leb(b, p):
    r = s = 0
    while True:
        x = b[p]; p += 1; r |= (x & 0x7f) << s; s += 7
        if x < 0x80: return r, p
def parse(path):
    b = open(path, 'rb').read(); p = 8; secs = {}; customs = {}
    while p < len(b):
        sid = b[p]; p += 1; n, p = leb(b, p); body = b[p:p + n]; p += n
        if sid == 0:
            nl, q = leb(body, 0); nm = body[q:q + nl].decode(); customs[nm] = body[q + nl:]
        else: secs[sid] = body
    nimp = 0
    imp = secs.get(2, b''); cnt, q = leb(imp, 0)
    for _ in range(cnt):
        l, q = leb(imp, q); q += l; l, q = leb(imp, q); q += l; k = imp[q]; q += 1
        if k == 0: _, q = leb(imp, q); nimp += 1
        elif k == 1: q += 1; fl = imp[q]; q += 1; _, q = leb(imp, q); q = leb(imp, q)[1] if fl & 1 else q
        elif k == 2: fl = imp[q]; q += 1; _, q = leb(imp, q); q = leb(imp, q)[1] if fl & 1 else q
        elif k == 3: q += 2
    code = secs[10]; cnt, q = leb(code, 0); bodies = []
    for _ in range(cnt):
        l, q = leb(code, q); bodies.append(code[q:q + l]); q += l
    names = {}
    nb = customs.get('name', b''); q = 0
    while q < len(nb):
        sub = nb[q]; q += 1; l, q = leb(nb, q); d = nb[q:q + l]; q += l
        if sub == 1:
            c, r = leb(d, 0)
            for _ in range(c):
                i, r = leb(d, r); sl, r = leb(d, r); names[i] = d[r:r + sl].decode(); r += sl
    return {names.get(nimp + k, '#%d' % (nimp + k)): bodies[k] for k in range(len(bodies))}, secs
a, sa = parse(sys.argv[1]); bm, sb = parse(sys.argv[2])
print('functions', len(a), len(bm))
diff = sorted(n for n in a if n in bm and a[n] != bm[n])
print('differing bodies', len(diff))
for n in diff: print('  ', n, len(a[n]), len(bm[n]))
print('only old', sorted(set(a) - set(bm))[:20]); print('only new', sorted(set(bm) - set(a))[:20])
for sid in sorted(set(sa) | set(sb)):
    if sid != 10: print('section', sid, 'same' if sa.get(sid) == sb.get(sid) else 'differs (%d -> %d bytes)' % (len(sa.get(sid, b'')), len(sb.get(sid, b''))))
