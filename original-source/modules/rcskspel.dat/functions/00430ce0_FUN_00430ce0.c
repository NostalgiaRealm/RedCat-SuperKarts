/*
 * FUN_00430ce0 at 00430ce0
 * undefined FUN_00430ce0(void)
 * Address ranges: 00430ce0-00430d4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430ce0(void)

{
  double dVar1;
  int iVar2;
  
  iVar2 = FUN_004bf836();
  dVar1 = (double)(iVar2 - DAT_0053bab0) * 0.001;
  FUN_004afce0(s___d__frames___f__sec_004eb100,DAT_0053bab8,dVar1);
  FUN_004afce0(s_fps____f_004eb118,(double)DAT_0053bab8 / dVar1);
  __ftol();
  return;
}

