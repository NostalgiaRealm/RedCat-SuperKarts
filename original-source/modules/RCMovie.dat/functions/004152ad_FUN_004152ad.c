/*
 * FUN_004152ad at 004152ad
 * undefined __cdecl FUN_004152ad(int param_1)
 * Address ranges: 004152ad-00415319
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004152ad(int param_1)

{
  if (DAT_0043db88 != param_1) {
    DAT_0043db88 = param_1;
    if (param_1 == 0) {
      DAT_0043db84 = 0;
      _DAT_0043db7c = 0;
      _DAT_0043db80 = 0;
    }
    else {
      DAT_0043db84 = 1;
      _DAT_0043db7c = *(undefined4 *)(param_1 + 0x8c);
      _DAT_0043db80 = *(undefined4 *)(param_1 + 0x88);
    }
  }
  return;
}

