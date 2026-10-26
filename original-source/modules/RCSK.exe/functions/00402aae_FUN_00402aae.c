/*
 * FUN_00402aae at 00402aae
 * undefined4 __cdecl FUN_00402aae(int param_1)
 * Address ranges: 00402aae-00402ae9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00402aae(int param_1)

{
  int iVar1;
  
  DAT_0040a01c = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_0040a01c != (HANDLE)0x0) {
    iVar1 = FUN_00402aea();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_0040a01c);
  }
  return 0;
}

