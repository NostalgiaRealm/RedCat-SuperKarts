/*
 * FUN_0043d6b8 at 0043d6b8
 * bool __register FUN_0043d6b8(uint param_1)
 * Address ranges: 0043d6b8-0043d6f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0043d6b8(uint param_1)

{
  LRESULT LVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(int *)(DAT_0047d7bc + 4) != 0) {
    LVar1 = FUN_0043d5c0(*(HWND *)(DAT_0047d7bc + 8),param_1,DAT_0047d7bc,
                         (undefined4 *)(DAT_0047d7bc + 0xc),*(int *)(DAT_0047d7bc + 4));
    bVar2 = LVar1 != 0;
  }
  return bVar2;
}

