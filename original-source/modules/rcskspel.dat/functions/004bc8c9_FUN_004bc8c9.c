/*
 * FUN_004bc8c9 at 004bc8c9
 * undefined FUN_004bc8c9(void)
 * Address ranges: 004bc8c9-004bc93e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bc8c9(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    while( true ) {
      if (param_3 < 1) {
        return local_8;
      }
      if ((*(int *)param_1[8] == 0) || (iVar1 = *(int *)param_1[0xc], iVar1 < 1)) break;
      if (param_3 < iVar1) {
        iVar1 = param_3;
      }
      FUN_004c0e10(*(int *)param_1[8],param_2,iVar1);
      local_8 = local_8 + iVar1;
      param_3 = param_3 - iVar1;
      *(int *)param_1[0xc] = *(int *)param_1[0xc] - iVar1;
      param_2 = param_2 + iVar1;
      *(int *)param_1[8] = *(int *)param_1[8] + iVar1;
    }
    iVar1 = (**(code **)(*param_1 + 4))(*param_2);
    if (iVar1 == -1) break;
    param_2 = param_2 + 1;
    local_8 = local_8 + 1;
    param_3 = param_3 + -1;
  }
  return local_8;
}

