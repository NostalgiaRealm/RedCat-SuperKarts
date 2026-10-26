/*
 * _SmackVolumePan@16 at 00402e30
 * undefined __stdcall _SmackVolumePan@16(int param_1, uint param_2, uint param_3, uint param_4)
 * Address ranges: 00402e30-00402ecf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackVolumePan_16(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
                    /* 0x2e30  30  _SmackVolumePan@16 */
  if ((param_1 != 0) && (*(int *)(param_1 + 0x420) != -1)) {
    if (0x10000 < param_3) {
      param_3 = 0x10000;
    }
    if (0x10000 < param_4) {
      param_4 = 0x10000;
    }
    while ((param_2 & 0xfe000) != 0) {
      uVar2 = 0x2000;
      bVar3 = 0;
      do {
        if ((uVar2 & param_2) != 0) {
          param_2 = param_2 & ~uVar2;
          goto LAB_00402e9d;
        }
        bVar3 = bVar3 + 1;
        uVar2 = uVar2 * 2;
      } while (bVar3 < 7);
      bVar3 = 0xff;
LAB_00402e9d:
      if (((bVar3 < 7) && (iVar1 = *(int *)((uint)bVar3 * 4 + param_1 + 0x404), iVar1 != 0)) &&
         (DAT_0040e858 != (code *)0x0)) {
        (*DAT_0040e858)(param_4,param_3,iVar1);
      }
    }
  }
  return;
}

