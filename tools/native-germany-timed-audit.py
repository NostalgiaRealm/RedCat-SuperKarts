#!/usr/bin/env python3
"""Audit captured German hard gate awards with original 0x441e70 instructions.
This replays handler inputs, not the complete native race trajectory.
"""
import hashlib,json
from generate_native_race_fixtures import RaceProbe,ROOT

report_path='evidence/full-race-matrix/timed-germany-hard-ground-predict8.json'
report_bytes=(ROOT/report_path).read_bytes()
report=json.loads(report_bytes);run=report['runs'][0]
track_path='public/assets/tracks/etappe1.json'
track_bytes=(ROOT/track_path).read_bytes();track=json.loads(track_bytes)
config_bytes=(ROOT/'public/assets/config.json').read_bytes();config=json.loads(config_bytes)
values=list(map(int,config['track.ini']['time_gates']['5'].split(',')))
times=values[1:];assert times==[7000,12500,13000,11000]
assert run['opening']['initialPlayer']['sector']==173
assert run['opening']['greenPlayer']['sector']==172
assert run['opening']['greenRace']['distance']==-1
assert len(track['route'])==187
probe=RaceProbe();deadline=times[0];index=0;gate_distance=0;cases=[]
# Source topology from the initialized sector173: the first gate174 occurs
# before finish-arm176. Its adjacent slot at175 is rejected by strict progress.
positions=[174,53,112]
for k,event in enumerate(run['gateEvents']):
    slot=k%3;sector=positions[slot]
    distance=[1,67,126][slot]+(k//3)*187
    active=event['now']-run['opening']['greenWallMs']
    state={'raceType':1,'phase':0,'gateIndex':index,'gateDistance':gate_distance,
           'distance':distance,'remainingMs':deadline-active,'gateTimes':times,'player':True}
    assert state['remainingMs']>0
    probe.initialize(state);probe.run(0x441e70,[0]);after=probe.state()
    assert after['gateIndex']==event['index']
    assert after['remainingMs']==state['remainingMs']+event['additionalMs']
    assert after['gateDistance']==distance+1
    assert after['sounds']==1
    duplicate=None
    # The actual track repeats74 at174/175 and76 at112/113. The second
    # source callback is legal, but must not award another clock increment.
    if slot in [0,2]:
        probe.set(0x53be70,distance+1);probe.run(0x441e70,[0]);duplicate=probe.state()
        assert duplicate['remainingMs']==after['remainingMs']
        assert duplicate['sounds']==1
    index=after['gateIndex'];gate_distance=after['gateDistance']
    deadline=active+after['remainingMs']
    cases.append({'event':event,'activeMs':active,'topologicalSector':sector,
                  'input':state,'nativeAfter':after,'adjacentMarkerAfter':duplicate})
assert len(cases)==16
assert deadline-run['race']['elapsedMs']==run['race']['remainingMs']==16625
assert run['race']['distance']==937 and run['race']['gateDistance']==937
assert [e['lap'] for e in run['lapEvents']]==[1,2,3,4,5]
assert sum(e['timeMs'] for e in run['lapEvents'])==run['activeElapsedMs']==185375
result={'format':'superkarts-native-germany-timed-audit-v1','sourceSha256':probe.sha,
        'report':report_path,'reportSha256':hashlib.sha256(report_bytes).hexdigest(),
        'track':track_path,'trackSha256':hashlib.sha256(track_bytes).hexdigest(),
        'configSha256':hashlib.sha256(config_bytes).hexdigest(),
        'method':'Original0x441e70 executed for16 captured gate times with authored forward-topology progress values;11 adjacent-marker callbacks verify rejection. Timer, mode and sound boundary services are RaceProbe stubs. This is not a native full-race replay.',
        'entrypoint':'0x441e70','initialGateMs':times[0],'gateTimes':times,
        'summary':{'acceptedNativeCalls':16,'adjacentRejectedCalls':11,
                   'nativeRemainingAtFinishMs':deadline-run['race']['elapsedMs'],
                   'initialSector':173,'greenSector':172,'finalDistance':937,
                   'lapCount':5,'activeMs':run['activeElapsedMs'],'rank':run['rank'],
                   'qualified':run['qualification']['qualified']},'cases':cases}
output=ROOT/'evidence/native/germany-timed-success-audit.json'
output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result['summary']))
