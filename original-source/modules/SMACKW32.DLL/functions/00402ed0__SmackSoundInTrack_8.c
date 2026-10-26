/*
 * _SmackSoundInTrack@8 at 00402ed0
 * undefined4 __stdcall _SmackSoundInTrack@8(int param_1, uint param_2)
 * Address ranges: 00402ed0-00402f36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 _SmackSoundInTrack_8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
                    /* 0x2ed0  29  _SmackSoundInTrack@8 */
  if (param_1 == 0) {
LAB_00402f2f:
    uVar3 = 0;
  }
  else {
    do {
      if ((param_2 & 0xfe000) == 0) goto LAB_00402f2f;
      uVar1 = 0x2000;
      bVar4 = 0;
      do {
        if ((uVar1 & param_2) != 0) {
          param_2 = param_2 & ~uVar1;
          goto LAB_00402f0b;
        }
        bVar4 = bVar4 + 1;
        uVar1 = uVar1 * 2;
      } while (bVar4 < 7);
      bVar4 = 0xff;
LAB_00402f0b:
      iVar2 = (uint)bVar4 * 4 + param_1;
    } while (((*(uint *)(iVar2 + 0x48) >> 0x18 & 0x40) == 0) ||
            ((*(uint *)(iVar2 + 0x48) & 0xffffff) == 0));
    uVar3 = 1;
  }
  return uVar3;
}

