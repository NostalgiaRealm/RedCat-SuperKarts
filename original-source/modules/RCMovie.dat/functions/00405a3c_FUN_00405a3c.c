/*
 * FUN_00405a3c at 00405a3c
 * undefined __thiscall FUN_00405a3c(void * this, int param_1)
 * Address ranges: 00405a3c-00405a8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00405a3c(void *this,int param_1)

{
  void *extraout_ECX;
  
  if ((param_1 < 0) || (DAT_0043d400 < param_1)) {
    FUN_0040187a((byte *)s__get_ini_argument_value___s__d____0042edfc);
    this = extraout_ECX;
  }
  FUN_0041fc7b(this,&DAT_004384b0 + param_1 * 200);
  return;
}

