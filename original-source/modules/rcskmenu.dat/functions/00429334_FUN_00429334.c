/*
 * FUN_00429334 at 00429334
 * undefined __register FUN_00429334(undefined4 param_1)
 * Address ranges: 00429334-0042939f;004293b9-004293d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429334(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  DWORD dwThreadId;
  undefined4 *in_FS_OFFSET;
  code *lpfn;
  LPARAM lParam;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 local_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  uVar2 = DAT_0047b6c8;
  uVar1 = DAT_0047b6bc;
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  DAT_0047b6c8 = 0;
  puStack_24 = &LAB_004293d7;
  local_28 = *in_FS_OFFSET;
  DAT_0047b6bc = param_1;
  *in_FS_OFFSET = &local_28;
  puStack_30 = &LAB_004293a0;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  lParam = 0;
  lpfn = FUN_004292e4;
  dwThreadId = GetCurrentThreadId();
  EnumThreadWindows(dwThreadId,lpfn,lParam);
  *in_FS_OFFSET = uStack_34;
  *in_FS_OFFSET = local_28;
  DAT_0047b6c8 = uVar2;
  DAT_0047b6bc = uVar1;
  return;
}

