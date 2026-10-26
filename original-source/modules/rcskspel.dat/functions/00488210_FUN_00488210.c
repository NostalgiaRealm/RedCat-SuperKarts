/*
 * FUN_00488210 at 00488210
 * undefined FUN_00488210(void)
 * Address ranges: 00488210-004882e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00488210(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 param_4,int param_5,
            char param_6,char param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x138) = param_2;
  *(undefined1 *)(param_1 + 0x13c) = 1;
  *(undefined4 *)(param_1 + 0x140) = *param_3;
  *(undefined4 *)(param_1 + 0x144) = param_3[1];
  uVar1 = param_3[2];
  *(undefined1 *)(param_1 + 0x151) = param_4;
  *(undefined4 *)(param_1 + 0x148) = uVar1;
  *(char *)(param_1 + 0x150) = param_6;
  if (param_6 == '\0') {
    if ((param_5 < 6) && (-1 < param_5)) {
      *(int *)(param_1 + 0x14c) = param_5;
    }
    else {
      *(undefined4 *)(param_1 + 0x14c) = 0;
    }
  }
  *(char *)(param_1 + 0x134) = param_7;
  if (param_7 != '\0') {
    *(undefined4 *)(param_1 + 0x154) = 7;
  }
  *(undefined4 *)(param_1 + 0x168) = param_8;
  DAT_005450fc = FUN_004a6060(s_S_SFX_PCX_004f9ea8);
  *(undefined4 *)(param_1 + 0x16c) = 0x3efc0000;
  *(undefined4 *)(param_1 + 0x174) = 0x3f7c0000;
  *(undefined4 *)(param_1 + 0x170) = 0x3efc0000;
  *(undefined4 *)(param_1 + 0x178) = 0x3f7c0000;
  return;
}

