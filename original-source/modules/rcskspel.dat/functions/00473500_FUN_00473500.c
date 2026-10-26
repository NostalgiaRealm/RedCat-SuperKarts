/*
 * FUN_00473500 at 00473500
 * undefined FUN_00473500(void)
 * Address ranges: 00473500-00473541
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473500(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_00544dcc;
  if (DAT_00544dcc == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar1);
  puVar1 = &DAT_004d2404;
  if (DAT_00544dac != (undefined1 *)0x0) {
    puVar1 = DAT_00544dac;
  }
  puVar2 = DAT_00544dbc;
  if (DAT_00544dbc == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1e70(puVar2,puVar1,0);
  return;
}

