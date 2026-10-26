/*
 * FUN_0044e6f8 at 0044e6f8
 * undefined __register FUN_0044e6f8(undefined4 * param_1, int * param_2)
 * Address ranges: 0044e6f8-0044e775
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e6f8(undefined4 *param_1,int *param_2)

{
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar1;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *local_10;
  undefined4 *local_c;
  int local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = 0;
  local_c = (undefined4 *)0x0;
  local_10 = (byte *)0x0;
  puStack_20 = &LAB_0044e776;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  FUN_00403ba4(param_2,param_1);
  ppuVar1 = (undefined4 **)0x44e72b;
  FUN_0044e4c0("IMAGEBASE",&local_8);
  if (local_8 != 0) {
    ppuVar1 = &local_c;
    FUN_0044e4c0("IMAGEBASE",(int *)&local_10);
    FUN_0044e4f8((undefined4 *)*param_2,local_10,0x44e7a0,(int *)ppuVar1);
    FUN_00403ba4(param_2,local_c);
  }
  *in_FS_OFFSET = ppuVar1;
  puStack_20 = &LAB_0044e77d;
  uStack_24 = 0x44e775;
  FUN_00403b74((int *)&local_10,3);
  return;
}

