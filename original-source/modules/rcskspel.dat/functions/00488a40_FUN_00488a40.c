/*
 * FUN_00488a40 at 00488a40
 * undefined FUN_00488a40(void)
 * Address ranges: 00488a40-00488a7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_00488a40(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 local_1;
  
  *param_1 = &PTR_FUN_004d2f88;
  puVar1 = operator_new(0x10);
  if (puVar1 != (undefined1 *)0x0) {
    local_1 = (undefined1)((uint)param_1 >> 0x18);
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_1;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    param_1[1] = puVar1;
    return param_1;
  }
  param_1[1] = 0;
  return param_1;
}

