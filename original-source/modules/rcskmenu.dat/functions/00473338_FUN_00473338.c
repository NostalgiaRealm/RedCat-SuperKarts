/*
 * FUN_00473338 at 00473338
 * undefined __register FUN_00473338(void)
 * Address ranges: 00473338-00473407
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473338(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_FS_OFFSET;
  int iStack_54;
  int iStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  uint *local_20;
  int local_1c [5];
  undefined4 *local_8;
  
  puStack_28 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_1c[4] = 0;
  local_1c[3] = 0;
  local_1c[2] = 0;
  local_1c[1] = 0;
  local_1c[0] = 0;
  local_20 = (uint *)0x0;
  puStack_2c = &LAB_00473408;
  iStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_30;
  iVar2 = FUN_00472f00();
  if (iVar2 < 0xc) {
    FUN_0045c4c8(0x47,local_1c + 4);
    FUN_00407f60(iVar2,local_1c + 3);
    FUN_0045c4c8(0x48,local_1c + 2);
    FUN_00407f60(0xc,local_1c + 1);
    FUN_0045c4c8(0x49,local_1c);
    iStack_54 = local_1c[0];
    FUN_00403e90((int *)&local_8,9);
    puVar1 = local_8;
    FUN_0045c4f0(0x18,(int *)&local_20);
    FUN_00460df0(local_20,puVar1,4);
  }
  *in_FS_OFFSET = iStack_54;
  FUN_00403b74((int *)&local_20,7);
  return;
}

