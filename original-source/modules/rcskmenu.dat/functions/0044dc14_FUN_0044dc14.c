/*
 * FUN_0044dc14 at 0044dc14
 * undefined __register FUN_0044dc14(int * param_1, char param_2)
 * Address ranges: 0044dc14-0044dc75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044dc14(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined1 *puStack_138;
  undefined4 uStack_134;
  undefined1 *puStack_130;
  undefined1 *puStack_12c;
  undefined4 uStack_128;
  undefined1 *puStack_124;
  undefined1 *puStack_120;
  
  puStack_120 = (undefined1 *)0x44dc2a;
  piVar1 = FUN_0040320c(param_1,param_2);
  puStack_124 = &LAB_0044dcdd;
  uStack_128 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_128;
  puStack_130 = &LAB_0044dc87;
  uStack_134 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_134;
  uStack_140 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_140;
  *in_FS_OFFSET = uStack_140;
  puStack_138 = &LAB_0044dc7d;
  uStack_13c = 0x44dc75;
  puStack_12c = &stack0xfffffffc;
  puStack_120 = &stack0xfffffffc;
  FUN_00402e9c(piVar1,extraout_DL & 0xfc);
  return;
}

