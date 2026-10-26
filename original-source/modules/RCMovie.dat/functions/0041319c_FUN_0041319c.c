/*
 * FUN_0041319c at 0041319c
 * undefined4 __stdcall FUN_0041319c(void)
 * Address ranges: 0041319c-00413233
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041319c(void)

{
  int iVar1;
  
  if (DAT_0043d850 == 0) {
    FUN_0040187a((byte *)s__s__d_____handle_form__No_active_00434be8);
  }
  DAT_00434008 = 0xffffffff;
  DAT_0043400c = 0xffffffff;
  DAT_0043d848 = DAT_0043d848 + 1;
  if (DAT_0043d848 == DAT_00434004) {
    DAT_0043d848 = 0;
    FUN_00412ece();
  }
  FUN_00405614();
  iVar1 = FUN_0040a97d();
  if (iVar1 != 0) {
    DAT_00434008 = 0xfffffffe;
  }
  iVar1 = FUN_00412061();
  if (iVar1 == 1) {
    FUN_00401cf3();
  }
  return DAT_00434008;
}

