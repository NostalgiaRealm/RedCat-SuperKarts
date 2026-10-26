/*
 * FUN_0044c6a8 at 0044c6a8
 * undefined __register FUN_0044c6a8(uint * param_1, byte param_2, ushort param_3, undefined4 * param_4, int param_5, int param_6, int param_7)
 * Address ranges: 0044c6a8-0044c747
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044c6a8(uint *param_1,byte param_2,ushort param_3,undefined4 *param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x44c6c9;
  piVar1 = (int *)FUN_0044c114(param_1,param_2,param_3);
  puStack_20 = &LAB_0044c748;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  piVar1[0x54] = param_7;
  puStack_1c = &stack0xfffffffc;
  FUN_00403ba4(piVar1 + 0x89,param_4);
  if (-1 < param_6) {
    FUN_0043ee6c(piVar1,param_6);
  }
  if (-1 < param_5) {
    FUN_0043ee8c(piVar1,param_5);
  }
  if ((param_5 < 0) && (param_6 < 0)) {
    FUN_0042c914((int)piVar1,'\x04');
  }
  (**(code **)(*piVar1 + 0xd8))();
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0044c74f;
  puStack_20 = (undefined1 *)0x44c747;
  FUN_00402eac(piVar1);
  return;
}

