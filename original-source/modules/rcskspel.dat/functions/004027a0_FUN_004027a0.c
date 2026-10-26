/*
 * FUN_004027a0 at 004027a0
 * undefined FUN_004027a0(void)
 * Address ranges: 004027a0-0040284e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004027a0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_0053be28;
  iVar4 = DAT_00508610;
  if (DAT_00508610 < 0xf) {
    piVar2 = &DAT_00503ef0 + DAT_00508610 * 0x47;
    do {
      if (*piVar2 == -1) break;
      piVar2 = piVar2 + 0x47;
      iVar4 = iVar4 + 1;
    } while ((int)piVar2 < 0x504f94);
  }
  iVar3 = iVar4 * 0x11c;
  if ((&DAT_00503ef0)[iVar4 * 0x47] == -1) {
    (&DAT_00503ef0)[iVar4 * 0x47] = param_1;
    (&DAT_00503ef4)[iVar4 * 0x47] = 0x13;
    *(undefined4 *)(&DAT_00503ef8 + iVar3) = uVar1;
    *(undefined4 *)(&DAT_00503f24 + iVar3) = 6;
    (&DAT_00503f00)[iVar4 * 0x47] = param_2;
    *(undefined4 *)(&DAT_00503f10 + iVar3) = 0;
    param_1 = param_1 * 0xd0;
    *(uint *)(param_1 + 4 + DAT_0067ee20) = *(uint *)(param_1 + 4 + DAT_0067ee20) | 3;
    *(code **)(param_1 + 0x58 + DAT_0067ee20) = FUN_004170a0;
    return 1;
  }
  return 0;
}

