/*
 * FUN_004999c0 at 004999c0
 * undefined FUN_004999c0(void)
 * Address ranges: 004999c0-00499b10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004999c0(int param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_00490ce0();
  iVar2 = iVar2 * 0xbc;
  iVar3 = iVar2 + 0x10 + DAT_006a5ee0;
  *param_2 = *(undefined4 *)(iVar2 + 0x10 + DAT_006a5ee0);
  param_2[1] = *(undefined4 *)(iVar3 + 4);
  param_2[2] = *(undefined4 *)(iVar3 + 8);
  iVar3 = iVar2 + 0x1c + DAT_006a5ee0;
  param_2[3] = *(undefined4 *)(iVar2 + 0x1c + DAT_006a5ee0);
  param_2[4] = *(undefined4 *)(iVar3 + 4);
  param_2[5] = *(undefined4 *)(iVar3 + 8);
  iVar3 = iVar2 + 0x4c + DAT_006a5ee0;
  param_2[6] = *(undefined4 *)(iVar2 + 0x4c + DAT_006a5ee0);
  param_2[7] = *(undefined4 *)(iVar3 + 4);
  param_2[8] = *(undefined4 *)(iVar3 + 8);
  iVar3 = iVar2 + 0x40 + DAT_006a5ee0;
  param_2[9] = *(undefined4 *)(iVar2 + 0x40 + DAT_006a5ee0);
  param_2[10] = *(undefined4 *)(iVar3 + 4);
  param_2[0xb] = *(undefined4 *)(iVar3 + 8);
  iVar3 = DAT_006a5c38 + *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  param_2[0xc] = *(undefined4 *)(iVar3 + 0x50);
  param_2[0xd] = *(undefined4 *)(iVar3 + 0x54);
  param_2[0xe] = *(undefined4 *)(iVar3 + 0x58);
  iVar3 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
  fVar1 = *(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8);
  if (*(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8) <= 0.0) {
    FUN_004c062b((double)fVar1);
  }
  else {
    FUN_004c06fa((double)fVar1);
  }
  uVar4 = __ftol();
  param_2[0x11] = uVar4;
  param_2[0xf] = *(undefined4 *)(iVar2 + 0x74 + DAT_006a5ee0);
  param_2[0x10] = param_1;
  param_2[0x12] = 1;
  return;
}

