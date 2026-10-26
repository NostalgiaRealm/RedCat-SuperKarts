/*
 * FUN_00483650 at 00483650
 * undefined FUN_00483650(void)
 * Address ranges: 00483650-00483730
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00483650(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = FUN_00483280(param_2);
  if ((char)uVar4 == '\0') {
    return uVar4;
  }
  iVar7 = 0;
  iVar6 = *(int *)(param_1 + 0x8c) * 0xd0;
  iVar5 = iVar6 + 0x9c + DAT_0067ee20;
  fVar1 = *(float *)(iVar6 + 0x9c + DAT_0067ee20);
  fVar2 = *(float *)(iVar5 + 4);
  fVar3 = *(float *)(iVar5 + 8);
  fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
  *(float *)(param_1 + 0xc4) = fVar1 * -1.5;
  *(float *)(param_1 + 0xc0) = -fVar1;
  iVar5 = *(int *)(param_1 + 0xa0);
  if (0 < iVar5) {
    iVar6 = 0;
    do {
      *(float *)(iVar6 + 0x40 + *(int *)(param_1 + 0x9c)) =
           *(float *)(iVar6 + 0x40 + *(int *)(param_1 + 0x9c)) + 2.0;
      if (0.0 < *(float *)(iVar6 + 0x40 + *(int *)(param_1 + 0x9c))) {
        *(undefined4 *)(iVar6 + 0x40 + *(int *)(param_1 + 0x9c)) = 0;
      }
      iVar5 = *(int *)(param_1 + 0xa0);
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x5c;
    } while (iVar7 < iVar5);
  }
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

