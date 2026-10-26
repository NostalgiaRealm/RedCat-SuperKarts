/*
 * FUN_004215ec at 004215ec
 * undefined4 __cdecl FUN_004215ec(int param_1)
 * Address ranges: 004215ec-00421627
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004215ec(int param_1)

{
  int iVar1;
  
  DAT_0043f81c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0043f81c != (HANDLE)0x0) {
    iVar1 = FUN_00422b27();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_0043f81c);
  }
  return 0;
}

