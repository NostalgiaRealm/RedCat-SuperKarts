/*
 * FUN_00418200 at 00418200
 * undefined __cdecl FUN_00418200(int param_1)
 * Address ranges: 00418200-0041827a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00418200(int param_1)

{
  if ((param_1 < 0) || (0x10 < param_1)) {
    FUN_0040187a((byte *)s__s__d____Font_index_out_of_bound_00435c0c);
  }
  if (*(int *)(&DAT_00435820 + param_1 * 0x10) != 0) {
    if (param_1 == DAT_00435818) {
      DAT_0043dca8 = 0;
      DAT_00435818 = -1;
    }
    DeleteObject(*(HGDIOBJ *)(&DAT_00435820 + param_1 * 0x10));
    *(undefined4 *)(&DAT_00435820 + param_1 * 0x10) = 0;
  }
  return;
}

