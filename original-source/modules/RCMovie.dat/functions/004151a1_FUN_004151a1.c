/*
 * FUN_004151a1 at 004151a1
 * undefined4 __cdecl FUN_004151a1(int param_1)
 * Address ranges: 004151a1-0041520e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004151a1(int param_1)

{
  if ((param_1 < 0) || (0xff < param_1)) {
    FUN_0040187a((byte *)s__s__d____illegal_character_refer_00435338);
  }
  if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + param_1 * 0xc) == 0) {
    FUN_0040187a((byte *)s__s__d____character_not_available_00435370);
  }
  return *(undefined4 *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + param_1 * 0xc) + 8);
}

