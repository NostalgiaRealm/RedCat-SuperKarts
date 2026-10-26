/*
 * FUN_004736b0 at 004736b0
 * undefined FUN_004736b0(void)
 * Address ranges: 004736b0-004736fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004736b0(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  FUN_004734b0();
  puVar1 = DAT_00544dcc;
  if (DAT_00544dcc == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar1);
  puVar1 = DAT_00544d9c;
  if (DAT_00544d9c == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  puVar2 = DAT_00544dbc;
  if (DAT_00544dbc == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1e70(puVar2,puVar1,3);
  *param_1 = 0;
  return;
}

