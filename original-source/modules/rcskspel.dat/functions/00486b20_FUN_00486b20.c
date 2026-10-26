/*
 * FUN_00486b20 at 00486b20
 * undefined FUN_00486b20(void)
 * Address ranges: 00486b20-00486caf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00486b20(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  float *pfVar7;
  
  *(undefined1 *)(param_1 + 0x724) = 1;
  *(undefined4 *)(param_1 + 0x728) = *param_3;
  *(undefined4 *)(param_1 + 0x72c) = param_3[1];
  uVar5 = param_3[2];
  *(undefined4 *)(param_1 + 0x744) = 0;
  *(undefined4 *)(param_1 + 0x730) = uVar5;
  *(undefined4 *)(param_1 + 0x748) = 0;
  *(undefined4 *)(param_1 + 0x75c) = 0xa3;
  *(undefined4 *)(param_1 + 0x760) = 0xa0;
  *(undefined4 *)(param_1 + 0x764) = 5;
  *(undefined4 *)(param_1 + 0x750) = 0xa3;
  *(undefined4 *)(param_1 + 0x754) = 5;
  *(undefined4 *)(param_1 + 0x758) = 0xa0;
  *(undefined1 *)(param_1 + 0x768) = 0;
  *(undefined4 *)(param_1 + 0x74c) = param_4;
  *(undefined4 *)(param_1 + 0x770) = 2;
  *(undefined4 *)(param_1 + 0x774) = 0;
  *(undefined4 *)(param_1 + 0x778) = 0;
  *(undefined4 *)(param_1 + 0x780) = 0;
  *(undefined4 *)(param_1 + 0x77c) = 0x3fc00000;
  *(undefined4 *)(param_1 + 0x790) = param_2;
  uVar5 = FUN_00456370();
  cVar4 = FUN_00417e90(uVar5);
  uVar5 = DAT_0053be28;
  if (cVar4 == '\0') {
    iVar6 = FUN_00456370();
    uVar5 = (&DAT_005081bc)[iVar6 * 0x1c];
  }
  *(undefined4 *)(param_1 + 0x720) = uVar5;
  pfVar7 = (float *)FUN_0044fbf0();
  fVar2 = pfVar7[2];
  iVar6 = *(int *)(*(int *)(param_1 + 0x720) * 0xd0 + 0xc + DAT_0067ee20);
  fVar3 = *(float *)(DAT_006a5c38 + iVar6 + 0x50 + iVar6 * 0xa8) - *pfVar7;
  fVar1 = *(float *)(DAT_006a5c38 + iVar6 + 0x58 + iVar6 * 0xa8);
  *(undefined4 *)(param_1 + 0x784) = 0;
  fVar1 = fVar1 - fVar2;
  *(undefined4 *)(param_1 + 0x788) = 0x50;
  *(undefined4 *)(param_1 + 0x78c) = 0xa0;
  *(float *)(param_1 + 0x77c) = fVar3 * fVar3 + fVar1 * fVar1;
  DAT_005450f4 = FUN_004a6060(s_S_SFX_PCX_004f9d98);
  return;
}

