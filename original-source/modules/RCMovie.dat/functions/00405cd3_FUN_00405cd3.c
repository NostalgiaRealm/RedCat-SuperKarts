/*
 * FUN_00405cd3 at 00405cd3
 * int __stdcall FUN_00405cd3(void)
 * Address ranges: 00405cd3-00405cfd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00405cd3(void)

{
  int iVar1;
  
  if (DAT_0043d434 < DAT_0043d430) {
    iVar1 = DAT_0043d434;
    DAT_0043d434 = DAT_0043d434 + 1;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

