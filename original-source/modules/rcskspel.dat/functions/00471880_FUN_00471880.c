/*
 * FUN_00471880 at 00471880
 * undefined FUN_00471880(void)
 * Address ranges: 00471880-00471893
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00471880(undefined1 *param_1)

{
  undefined1 uStack_1;
  
  uStack_1 = (undefined1)((uint)param_1 >> 0x18);
  *param_1 = uStack_1;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

