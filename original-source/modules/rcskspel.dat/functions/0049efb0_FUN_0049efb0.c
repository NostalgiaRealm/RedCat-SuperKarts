/*
 * FUN_0049efb0 at 0049efb0
 * undefined FUN_0049efb0(void)
 * Address ranges: 0049efb0-0049f03b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049efb0(int param_1)

{
  undefined1 *puVar1;
  
  FUN_004afce0(s_______Dump_of_object_CSndType____004fc620);
  puVar1 = *(undefined1 **)(param_1 + 0x2c);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s_Name___s_004fb998,puVar1);
  puVar1 = *(undefined1 **)(param_1 + 0x1c);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004afce0(s_Filename___s_004fc610,puVar1);
  FUN_004afce0(s_Local_volume___d_004fc5fc,*(undefined4 *)(param_1 + 0x10));
  FUN_004afce0(s_Group___d_004fc5f0,*(undefined4 *)(param_1 + 8));
  FUN_004afce0(s_Preload___d_004fc5e0,*(undefined4 *)(param_1 + 4));
  FUN_004afce0(s_Range___d_004fc5d4,*(undefined4 *)(param_1 + 0xc));
  FUN_004afce0(s_Doppler_amount___d_004fc5c0,*(undefined4 *)(param_1 + 0x14));
  return;
}

