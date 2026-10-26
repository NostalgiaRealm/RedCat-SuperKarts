/*
 * FUN_00473700 at 00473700
 * undefined FUN_00473700(void)
 * Address ranges: 00473700-0047374c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00473700(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  FUN_00473500();
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
  FUN_004b1e70(puVar2,puVar1,0);
  *param_1 = 1;
  return;
}

