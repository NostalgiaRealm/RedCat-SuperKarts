/*
 * FUN_00494510 at 00494510
 * undefined FUN_00494510(void)
 * Address ranges: 00494510-004945cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00494510(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_004afce0(s_clear_object___d_from_list__004faf44,param_2);
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_004afce0(s_search_for_object_004faf30);
    iVar2 = 0;
    piVar4 = (int *)(param_1 + 0x28);
    do {
      FUN_004afce0(&DAT_004faf2c,*piVar4);
      iVar3 = iVar2;
      if (*piVar4 == param_2) break;
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      iVar3 = -1;
    } while (iVar2 < 10);
    FUN_004afce0(&DAT_004faf28);
    if (iVar3 != -1) {
      FUN_004afce0(s_found_object_in_list__index__d__004faf04,iVar3);
      if (iVar3 < 9) {
        puVar1 = (undefined4 *)(param_1 + 0x28 + iVar3 * 4);
        iVar2 = 9 - iVar3;
        iVar3 = iVar3 + iVar2;
        do {
          *puVar1 = puVar1[1];
          puVar1 = puVar1 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_004afce0(s_clearing_last_in_list__d__004faee8,iVar3);
      *(undefined4 *)(param_1 + 0x28 + iVar3 * 4) = 0xffffffff;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    }
  }
  return;
}

