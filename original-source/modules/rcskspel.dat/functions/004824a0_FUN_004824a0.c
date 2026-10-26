/*
 * FUN_004824a0 at 004824a0
 * undefined FUN_004824a0(void)
 * Address ranges: 004824a0-0048250c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004824a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x14) = *param_5;
  *(undefined4 *)(param_1 + 0x18) = param_5[1];
  *(undefined4 *)(param_1 + 0x1c) = param_5[2];
  *(undefined4 *)(param_1 + 0x2c) = *param_7;
  *(undefined4 *)(param_1 + 0x30) = param_7[1];
  *(undefined4 *)(param_1 + 0x34) = param_7[2];
  *(undefined4 *)(param_1 + 0x38) = *param_4;
  *(undefined4 *)(param_1 + 0x3c) = param_4[1];
  *(undefined4 *)(param_1 + 0x40) = param_4[2];
  uVar1 = *param_6;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  *(undefined1 *)(param_1 + 8) = 1;
  return;
}

