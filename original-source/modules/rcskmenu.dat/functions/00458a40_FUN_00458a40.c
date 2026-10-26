/*
 * FUN_00458a40 at 00458a40
 * undefined4 __register FUN_00458a40(int param_1, int param_2, int param_3)
 * Address ranges: 00458a40-00458afb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00458a40(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  local_18 = param_2;
  if ((param_2 == -1) && (local_18 = FUN_00458a00(param_1,*(int *)(param_3 + 0x10)), local_18 < 0))
  {
    local_1c = 0xffffffff;
  }
  else if (local_18 < 5) {
    local_14 = local_18 + -5;
    iVar1 = 4;
    do {
      if (iVar1 == local_18) {
        FUN_00403ba4((int *)(param_1 + 8 + iVar1 * 0x18),*(undefined4 **)(param_3 + 4));
        *(undefined1 *)(param_1 + 0xc + iVar1 * 0x18) = *(undefined1 *)(param_3 + 8);
        *(undefined4 *)(param_1 + 0x10 + iVar1 * 0x18) = *(undefined4 *)(param_3 + 0xc);
        *(undefined4 *)(param_1 + 0x14 + iVar1 * 0x18) = *(undefined4 *)(param_3 + 0x10);
        *(undefined1 *)(param_1 + 0x18 + iVar1 * 0x18) = *(undefined1 *)(param_3 + 0x14);
      }
      else {
        FUN_00403ba4((int *)(param_1 + 8 + iVar1 * 0x18),
                     *(undefined4 **)(param_1 + -0x10 + iVar1 * 0x18));
        *(undefined1 *)(param_1 + 0xc + iVar1 * 0x18) =
             *(undefined1 *)(param_1 + -0xc + iVar1 * 0x18);
        *(undefined4 *)(param_1 + 0x10 + iVar1 * 0x18) =
             *(undefined4 *)(param_1 + -8 + iVar1 * 0x18);
        *(undefined4 *)(param_1 + 0x14 + iVar1 * 0x18) =
             *(undefined4 *)(param_1 + -4 + iVar1 * 0x18);
        *(undefined1 *)(param_1 + 0x18 + iVar1 * 0x18) = *(undefined1 *)(param_1 + iVar1 * 0x18);
      }
      iVar1 = iVar1 + -1;
      local_14 = local_14 + 1;
    } while (local_14 != 0);
  }
  return local_1c;
}

