/*
 * FUN_0040f420 at 0040f420
 * undefined __register FUN_0040f420(undefined4 * param_1, undefined4 param_2)
 * Address ranges: 0040f420-0040f4ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f420(undefined4 *param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar2;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  char local_e;
  undefined1 local_d;
  undefined4 local_c;
  undefined4 *local_8;
  
  puVar2 = &stack0xfffffffc;
  puStack_14 = (undefined1 *)0x40f436;
  local_c = param_2;
  local_8 = param_1;
  FUN_0040bf7c(DAT_0047d618);
  puStack_18 = &LAB_0040f4ce;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  local_e = (*(ushort *)(local_8 + 8) & 0x201) == 0;
  puStack_14 = &stack0xfffffffc;
  if ((bool)local_e) {
    puStack_20 = (undefined1 *)0x40f46b;
    puStack_14 = &stack0xfffffffc;
    FUN_0040f274();
  }
  puStack_24 = &LAB_0040f4af;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  ppuVar1 = (undefined **)FUN_00402df4(local_8);
  local_d = FUN_0040f378(ppuVar1,extraout_EDX,extraout_ECX,(int)puVar2);
  if (local_e != '\0') {
    FUN_0040f2d4();
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0040f4b6;
  if (local_e != '\0') {
    puStack_24 = (undefined1 *)0x40f4ae;
    FUN_0040f304();
  }
  return;
}

