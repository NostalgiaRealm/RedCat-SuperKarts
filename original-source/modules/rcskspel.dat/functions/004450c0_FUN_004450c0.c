/*
 * FUN_004450c0 at 004450c0
 * undefined FUN_004450c0(void)
 * Address ranges: 004450c0-0044511a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004450c0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1d) != '\0') {
    iVar1 = FUN_00444ba0(*(undefined4 *)(param_1 + 0x18));
    *(int *)(param_1 + 4) =
         (*(int *)(param_1 + 4) / *(int *)(&DAT_0053f674 + iVar1 * 0x340)) *
         *(int *)(&DAT_0053f674 + iVar1 * 0x340);
    return;
  }
  iVar1 = FUN_00444ba0(*(undefined4 *)(param_1 + 0x18));
  *(int *)(param_1 + 4) =
       (*(int *)(param_1 + 4) / (*(int *)(&DAT_0053f674 + iVar1 * 0x340) + -1)) *
       (*(int *)(&DAT_0053f674 + iVar1 * 0x340) + -1);
  return;
}

