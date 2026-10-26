/*
 * FUN_0048f910 at 0048f910
 * undefined FUN_0048f910(void)
 * Address ranges: 0048f910-0048f991
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048f910(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = DAT_006a5c38 + param_1 + param_1 * 0xa8;
  iVar3 = *(int *)(DAT_006a5c38 + param_1 + 0x99 + param_1 * 0xa8);
  if (iVar3 == -1) {
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) * 9 + 4 + DAT_006a5f78) +
                             *(int *)(iVar1 + 8) * 4) * 0x10 + DAT_006a5f30);
  }
  piVar2 = (int *)(DAT_006a5ee0 + 0x9c + iVar3 * 0xbc);
  DAT_0067ee68 = DAT_0067ee68 + *piVar2 / 3;
  DAT_0067ee6c = DAT_0067ee6c + *piVar2;
  return;
}

