/*
 * FUN_00445740 at 00445740
 * undefined FUN_00445740(void)
 * Address ranges: 00445740-004457f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00445740(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = FUN_00445720();
  if (iVar2 == -1) {
    return -1;
  }
  iVar5 = iVar2 * 0x24;
  puVar6 = (undefined4 *)(&DAT_0053f4fc + iVar5);
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *param_1;
    param_1 = param_1 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(&DAT_0053f514 + iVar5);
  FUN_0048f4e0();
  uVar3 = __ftol();
  *(undefined4 *)(&DAT_0053f500 + iVar5) = uVar3;
  iVar1 = *(int *)(&DAT_0053f670 + iVar4 * 0x340);
  *(undefined4 *)(&DAT_0053f504 + iVar5) = 0;
  if (iVar1 == 0) {
    FUN_004afee0(s__s___d__Time_not_set_for_path__d_004ef540,
                 s_D__work_rcsk_Code_game_pth_main__004ef51c,0x269,iVar4);
  }
  (&DAT_0053f4f8)[iVar5] = 1;
  FUN_004450c0(&DAT_0053f4fc + iVar5);
  return iVar2;
}

