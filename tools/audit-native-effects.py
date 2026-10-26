#!/usr/bin/env python3
"""Inventory shipped effect activation, and execute initially empty managers."""
import json
import struct
import pefile
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP
from generate_native_gameplay_fixtures import NativeProbe, ROOT, SOURCE, SCRATCH


def references(image, target):
    absolute=[]
    needle=struct.pack('<I',target)
    start=0
    while True:
        at=image.find(needle,start)
        if at<0:break
        absolute.append(hex(0x400000+at));start=at+1
    relative=[]
    # Conservative byte scan includes undecoded code and data. Zero matches
    # therefore does not depend on Ghidra's recovered-function boundaries.
    for at,opcode in enumerate(image[:-5]):
        if opcode not in [0xe8,0xe9]:continue
        destination=(0x400000+at+5+struct.unpack_from('<i',image,at+1)[0])&0xffffffff
        if destination==target:relative.append(hex(0x400000+at))
    return {'absolutePointers':absolute,'directCallsOrJumps':relative}


def main():
    image=pefile.PE(str(SOURCE/'rcskspel.dat')).get_memory_mapped_image()
    p=NativeProbe(SOURCE);p.uc.mem_map(0,0x1000);p.uc.mem_map(0x22000000,0x100000)
    heap=[0x22000000];draws=[];unexpected=[]
    p.uc.mem_write(0x4be7ee,b'\xc3')
    p.u32(0x6a621c,SCRATCH+0x6000);p.u32(SCRATCH+0x6000,SCRATCH+0x5000)
    p.u32(SCRATCH+0x5074,SCRATCH+0x7010);p.u32(SCRATCH+0x5078,SCRATCH+0x7010)
    p.uc.mem_write(SCRATCH+0x7010,b'\xc3')
    def hook(uc,address,size,data):
        if address==0x4be7ee:
            n=p.integer(uc.reg_read(UC_X86_REG_ESP)+4)
            base=heap[0];heap[0]+=(n+15)&~15;uc.reg_write(UC_X86_REG_EAX,base)
        elif address==SCRATCH+0x7010:draws.append(address)
        elif address in [0x485730,0x486460]:unexpected.append(hex(address))
    p.uc.hook_add(UC_HOOK_CODE,hook)
    p.run(0x485690);p.run(0x486370)
    effect=p.integer(0x5450c0);halo=p.integer(0x5450cc)
    frames=[]
    for tick in range(120):
        p.u32(0x53ba78,1 if tick%3 else 0)
        p.u32(0x53b9b0,1 if tick%7==0 else 0)
        for address,this in [(0x4863e0,halo),(0x4856e0,effect),(0x486420,halo),(0x485710,effect)]:
            p.uc.reg_write(UC_X86_REG_ECX,this);p.run(address)
            assert p.uc.reg_read(UC_X86_REG_EIP)==SCRATCH
        frames.append({'tick':tick,'effectCount':p.integer(effect+0x1ef0),
            'activeEffects':sum(p.integer(effect+i*0x18c+0x138)&255!=0 for i in range(20)),
            'haloBuffer':p.integer(p.integer(halo+4)+4),
            'randomState':p.integer(0x502978),'draws':len(draws)})
    assert not draws and not unexpected
    for row in frames:assert row['activeEffects']==row['effectCount']==row['haloBuffer']==0
    config=json.loads((ROOT/'public/assets/config.json').read_text())
    manifest=json.loads((ROOT/'public/assets/manifest.json').read_text())
    weather=[]
    for track_info in manifest['tracks']:
        track=json.loads((ROOT/'public/assets'/track_info['file']).read_text())
        weather.append({
            'id':track['id'],'name':track['name'],
            'modes':[{**config['track.ini'].get(f"track{mode}{track['id']}",{}),'raceType':mode}for mode in range(4)],
            'sectors':[{'sector':i,'field':key,'marker':row[key]}for i,row in enumerate(track['route'])
                       for key in ['trigger','unknown']if 79<=row[key]<=88],
            'waypointGuards':[{'waypoint':i,'marker':row['unknown'][1]}for i,row in enumerate(track['drive'])
                              if 79<=row['unknown'][1]<=88],
        })
    report={
        'format':'superkarts-effect-coverage-v1','sourceSha256':p.sha,
        'scope':'Native constructor/update/draw fixtures and static activation inventory; not a complete original-game visual recording.',
        'inactiveManagers':[
            {'name':'HaloEffect','manager':'486370','update':'4863e0','render':'486420',
             'activation':'486460','references':references(image,0x486460),
             'result':'Empty native list remains empty across120 complete update/render calls. No referenced activation entry was found.'},
            {'name':'GenericEffect','manager':'485690','update':'4856e0','render':'485710',
             'activation':'485730','references':references(image,0x485730),
             'result':'All20 native pool records remain inactive across120 update/render calls. No referenced activation entry was found.'},
        ],
        'inactiveManagerFrames':frames,
        'inactiveSparks':{
            'initializer':'427c40','emitter':'427a60','render':'427c70',
            'emitterReferences':references(image,0x427a60),
            'emitterCaller':'4354c0',
            'callerReferences':references(image,0x4354c0),
            'rendererReferences':references(image,0x427c70),
            'activeCollisionDamageEntry':{'address':'435630','bytes':bytes(p.uc.mem_read(0x435630,1)).hex()},
            'result':'Pool initialized by42d7d0, but emission caller and draw function have no discovered references. Active collision calls435630, a literal RET. No active spark RNG or rendering.',
        },
        'families':[
            {'name':'Original world, sky, racer and scenery meshes',
             'render':['4971f0','423010','491670'],'helper':['source/world.js','source/race-visuals.js'],
             'status':'Source geometry/sky selection and native driver/scenery animation helpers implemented; renderer ordering reviewed separately.'},
            {'name':'Projectile mesh and texture selection','init':'4500e0','update':'455a10',
             'helper':'source/simulation/native-bonus.js','verification':'34 original frame selections and960 projectile updates',
             'result':'Fixed mesh/texture chosen by level+kind offset. No per-tick mesh animation.'},
            {'name':'Rain and snow','init':'4818c0','update':'482020→483300',
             'render':'482190→483350','asset':'S_SFX.PCX','helper':'source/simulation/native-weather.js',
             'verification':'8 constructors,256 complete update frames,320 marker callbacks;24/53-bit FPU',
             'limitations':'Original UV initializer writes onlyceil(count/6) quads. Remaining native heap bytes are undefined; browser buffers explicitly start zero.'},
            {'name':'Rocket explosion ring','init':'481ec0','callers':['411830','455ce0','debug42f9c0'],
             'update':'482020→484270','render':'482190→4842f0→4844e0','asset':'S_SFX.PCX',
             'helper':'source/simulation/native-explosions.js','verification':'6 complete constructor/RNG/lifetime/indexed geometry traces;24/53-bit FPU'},
            {'name':'Tyre marks','init':'426c20','emit':'426aa0','render':'426e50',
             'asset':'S_SFX.PCX','helper':'source/simulation/native-skidmarks.js',
             'verification':'520 complete pool/emission/fade frames;24/53-bit FPU'},
            {'name':'Tyre and damage smoke','emit':['432240','420490'],'render':'428a00',
             'asset':'S_SFX.PCX','helper':'source/simulation/native-smoke.js',
             'verification':'180 complete native pool/sort/age/RNG frames'},
            {'name':'Rescue rings','render':'48db30','helper':'source/simulation/native-rescue.js','status':'implemented separately'},
            {'name':'Finish flag','render':'4235c0','helper':'source/finish-flag.js','status':'implemented separately'},
            {'name':'Kart and projectile streams','init':['42d7d0','4537f0','456440'],
             'render':['488b40','48a530'],'helper':'source/simulation/native-streams.js',
             'verification':'960 jet frames,960 ribbon frames,720 manager operations,30 setup branches and16 draw traces',
             'status':'Active helper and renderer binding implemented; preserves draw-time ribbon shrinking. No RNG.'},
            {'name':'Homing rocket warning arm','init':'456440→486b20','render':'487aa0',
             'helper':'source/simulation/native-homing-arm.js','status':'implemented separately'},
            {'name':'Squashed objects','init':'48e480','activate':'48e780','update':'48e970',
             'activeTypes':[43,44,46],
             'helper':['source/simulation/native-squash.js','source/simulation/native-squash-activation.js',
                       'source/simulation/native-scenery-hazards.js'],
             'verification':'720 original timer/matrix/rebound frames and1920 original hazard callbacks;24/53-bit FPU',
             'status':'Manager and source hazard conditions implemented; core services squash after tyre marks and before rescue. No RNG.'},
            {'name':'Original HUD overlays','render':'467d30',
             'helper':['source/race-hud-meshes.js','source/hud-text.js','source/hud-portraits.js',
                       'source/simulation/native-bonus-hud.js','source/simulation/native-minimap.js',
                       'source/simulation/native-countdown.js'],
             'status':'Original overlay transform/text/controller fixtures implemented separately.'},
        ],
        'weather':weather,
        'literalNoOpParticleEntries':[
            {'address':hex(address),'bytes':bytes(p.uc.mem_read(address,6)).hex(),'returnValue':1}
            for address in [0x481a50,0x481a60,0x481a70,0x481e60,0x481e70,0x481e80]
        ],
        'renderOrder':['deferred world','skidmarks426e50','halo486420','jetstream488b40',
                       'stream48a530','arm487aa0','generic485710','rescue48db30',
                       'smoke428a00','finishflag4235c0','weather482190','explosions482190','HUD467d30'],
        'sharedRandomAssessment':'Rain/snow construction and recycling, rocket explosion construction, and existing smoke cover the active particle RNG paths identified in42f4c0/430020. Squash and streams do not consume RNG. This is controller coverage, not a whole-program mathematical reachability proof.',
    }
    for manager in report['inactiveManagers']:
        assert not any(manager['references'].values())
    (ROOT/'evidence/native/effect-coverage.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'inactiveManagers':2,'nativeFrames':len(frames),'draws':len(draws),
                     'weatherSectorTriggers':sum(len(t['sectors'])for t in weather)}))


if __name__=='__main__':main()
