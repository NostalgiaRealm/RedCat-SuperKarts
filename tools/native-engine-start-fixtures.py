#!/usr/bin/env python3
"""Capture the original countdown START action and inactive CarSound updates."""
import importlib.util
import json
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_FPCW
from generate_native_gameplay_fixtures import ROOT, OBJECT

module_spec = importlib.util.spec_from_file_location(
    'native_engine_audio', ROOT / 'tools/native-engine-audio-fixtures.py')
engine_module = importlib.util.module_from_spec(module_spec)
module_spec.loader.exec_module(engine_module)


def main():
    probe = engine_module.EngineProbe()
    # Capture the countdown-overlay service, without replacing the action or
    # its CarSound call. Both execute their original instructions.
    probe.uc.mem_write(0x430610, b'\xc3')
    order = []

    def capture(uc, address, size, _):
        if address == 0x49d780:
            order.append({'service': 'sound', 'event': probe.events[probe.selected],
                          'loop': bool(probe.integer(uc.reg_read(UC_X86_REG_ESP) + 4))})
        elif address == 0x430610:
            order.append({'service': 'countdown', 'action':
                          probe.integer(uc.reg_read(UC_X86_REG_ESP) + 4)})

    probe.uc.hook_add(UC_HOOK_CODE, capture)
    cases = []
    for precision in [24, 53]:
        probe.uc.reg_write(UC_X86_REG_FPCW, 0x007f if precision == 24 else 0x027f)
        for previous_action in [-1, 0, 4]:
            probe.reset()
            frames = []
            for gear, rpm in [(0, 0), (0, 800), (1, 2000), (5, 9000)]:
                inputs = {'gear': gear, 'rpm': rpm, 'startPlaying': False}
                probe.start_playing = False
                commands = probe.call(0x418c80, [gear, rpm])
                frames.append({'input': inputs, 'commands': commands, 'state': probe.state()})
            probe.uc.mem_write(0x53bd98, bytes(probe.uc.mem_read(OBJECT, 0x4c)))
            probe.u32(0x4ec410, previous_action & 0xffffffff)
            order.clear()
            commands = probe.call(0x420d90)
            probe.uc.mem_write(OBJECT, bytes(probe.uc.mem_read(0x53bd98, 0x4c)))
            action = probe.integer(0x4ec410)
            if action >= 0x80000000:
                action -= 0x100000000
            cases.append({'precision': precision, 'previousAction': previous_action,
                          'inactiveFrames': frames, 'actionAfter': action,
                          'serviceOrder': order.copy(), 'commands': commands,
                          'stateAfter': probe.state()})
    target = ROOT / 'evidence/native/engine-start-fixtures.json'
    target.write_text(json.dumps({
        'format': 'superkarts-native-engine-start-v1', 'sha256': probe.sha,
        'method': 'Original 420d90 countdown START calls original 418950 on its actual global 53bd98. '
                  'Only sound output and countdown-overlay service are captured. Inactive updates '
                  'execute original 418c80 before the START action; no camera timing is simulated here.',
        'cases': cases}, indent=2) + '\n')
    print(f'Wrote {len(cases)} original START actions and '
          f'{sum(len(case["inactiveFrames"]) for case in cases)} inactive engine updates')


if __name__ == '__main__':
    main()
